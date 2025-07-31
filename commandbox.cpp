#include "commandbox.h"
#include "ui_commandbox.h"

#include "CommandSystemMap.h"
#include <QProcess>
#include <QFile>
#include <QDir>
#include <QDateTime>
#include <QDebug>
#include <QUrl>
#include <QDesktopServices>
#include <QDirIterator>

#include <QDesktopServices>
#include <QProcess>
#include <QUrl>
#include <QMap>
#include <QString>
#include <QDir>

// #include <qint64.h>

#include <windows.h>
#include <tlhelp32.h>


#include <QProcess>    // 核心：用于QProcess::startDetached()和执行系统命令
#include <qglobal.h>   // 用于跨平台宏定义（如Q_OS_WIN、Q_OS_LINUX等）

#include <QWidget>

// 在CommandSystem.cpp的开头添加
#include <QVBoxLayout>

#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>


#include "terminalwidget.h"
#include "deepseektalk.h"




bool isProcessAlive(qint64 pid) {
    // 创建进程快照
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE) return false;

    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32);

    // 遍历所有进程，匹配PID
    if (Process32First(hSnapshot, &pe32)) {
        do {
            if (pe32.th32ProcessID == (DWORD)pid) { // 精准匹配PID
                CloseHandle(hSnapshot);
                return true;
            }
        } while (Process32Next(hSnapshot, &pe32));
    }

    CloseHandle(hSnapshot);
    return false;
}



CommandBox::CommandBox(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CommandBox)
    , m_ruleEngine(new RuleEngine(this))
{
    ui->setupUi(this);

    // 连接规则引擎的未匹配信号
    connect(m_ruleEngine, &RuleEngine::noMatchFound, this, [this](const QString& input){
        emit commandResult(tr("未识别的命令: %1").arg(input));
    });
    // this->ui->outputArea, statusLabel

    this->conncommandResult = QObject::connect(this, &CommandBox::commandResult,
                                                    [this](const QString& result) {
                                                        this->ui->outputArea->append("结果: " + result);
                                                        this->ui->statusLabel->setText("命令执行成功");
                                                    });

    this->connerrorOccurred = QObject::connect(this, &CommandBox::errorOccurred,
                                                    [this](const QString& error) {
                                                        this->ui->outputArea->append("错误: " + error);
                                                        this->ui->statusLabel->setText("发生错误");
                                                    });

    // 执行按钮点击事件
    this->connclicked = QObject::connect(this->ui->executeButton, &QPushButton::clicked, [this]() {
        QString input = this->ui->inputField->text().trimmed();
        if (!input.isEmpty()) {
            this->ui->outputArea->append("> " + input);   // 测试是否由于多余的符号导致无法识别命令 ？
            // outputArea->append(input.toUtf8() + "\r\n");
            // 关键！！！！！
            this->processInput(input);
            this->ui->inputField->clear();
            // 能否添加条件判断，当terminaltest实例被创建时，执行另一种命令

        }
    });

    // 回车键执行
    // 这个信号连接似乎就是表示当按下enter或者return时，执行点击按钮的动作？
    QObject::connect(this->ui->inputField, &QLineEdit::returnPressed, this->ui->executeButton, &QPushButton::click);


}

CommandBox::~CommandBox()
{
    delete ui;
}


void CommandBox::initialize()
{
    // 添加打开应用程序规则
    m_ruleEngine->addRule("OpenApp",
                          R"(打开程序\s*(.*))",
                          [this](const QRegularExpressionMatch& match) {
                              QString appName = match.captured(1).trimmed();
                              openApplication(appName);
                          });

    // 添加关闭应用程序规则(未完成)(目前无法达到要求)
    m_ruleEngine->addRule("CloseApp",
                          R"(关闭程序\s*(.*))",
                          [this](const QRegularExpressionMatch& match) {
                              QString appName = match.captured(1).trimmed();
                              CloseApplication(appName);
                          });

    // 添加打开文件规则
    m_ruleEngine->addRule("OpenFile",
                          R"(打开文件\s*(.*))",
                          [this](const QRegularExpressionMatch& match) {
                              QString fileName = match.captured(1).trimmed();
                              Openfile(fileName);
                          });

    // 添加关闭文件规则(未完成)
    m_ruleEngine->addRule("OpenFile",
                          R"(关闭文件\s*(.*))",
                          [this](const QRegularExpressionMatch& match) {
                              QString fileName = match.captured(1).trimmed();
                              Closefile(fileName);
                          });

    // 添加创建文件规则
    m_ruleEngine->addRule("CreateFile",
                          R"(创建文件\s*(.*))",
                          [this](const QRegularExpressionMatch& match) {
                              QString fileName = match.captured(1).trimmed();
                              createFile(fileName);
                          });

    // 添加搜索文件规则
    m_ruleEngine->addRule("SearchFiles",
                          R"(查找\s*(.*))",
                          [this](const QRegularExpressionMatch& match) {
                              QString pattern = match.captured(1).trimmed();
                              searchFiles(pattern);
                          });

    // 添加运行命令规则
    m_ruleEngine->addRule("RunCommand",
                          R"(运行命令\s*(.*))",
                          [this](const QRegularExpressionMatch& match) {
                              QString command = match.captured(1).trimmed();
                              runSystemCommand(command);
                          });

    // 添加获取时间规则
    m_ruleEngine->addRule("GetTime",
                          R"(现在几点|当前时间)",
                          [this](const QRegularExpressionMatch&) {
                              getCurrentTime();
                          });

    // 添加帮助规则
    m_ruleEngine->addRule("Help",
                          R"(帮助|查看命令)",
                          [this](const QRegularExpressionMatch&) {
                              QStringList commands;
                              for (const auto& rule : m_ruleEngine->getRules()) {
                                  commands.append(QString("%1: %2 + ProgramNmae or FileName").arg(rule.name).arg(rule.pattern.pattern()));
                              }
                              emit commandResult(tr("可用命令:\n%1").arg(commands.join("\n")));
                          });
}

// input是裁剪首尾空格后的输入字符串
void CommandBox::processInput(const QString& input)
{
    m_ruleEngine->execute(input);
}

RuleEngine* CommandBox::ruleEngine() const
{
    return m_ruleEngine;
}




void CommandBox::openApplication(const QString& appName)
{
    // 1. 浏览器特殊处理
    if (appName == "浏览器") {
        if (QDesktopServices::openUrl(QUrl("https://www.qt.io"))) {
            emit commandResult(tr("已打开浏览器"));
        } else {
            emit errorOccurred(tr("打开浏览器失败"));
        }
        return;
    }

    else if( appName == "deepseek" )
    {
#if 0
        deepseekTalk * dp = new deepseekTalk(this);
        // dp->show();

        qApp->processEvents();  // 作用是什么？

        disconnect(this->connclicked);

        // 断联后重写连接

        // this->connclicked = QObject::connect(executeButton, &QPushButton::clicked, [this, dp]() {
        //     QString input = inputField->text().trimmed();
        //     if (!input.isEmpty()) {
        //         outputArea->append("> " + input);   // 测试是否由于多余的符号导致无法识别命令 ？
        //         // outputArea->append(input.toUtf8() + "\r\n");
        //         // 关键！！！！！
        //         // this->processInput(input);
        //         // if( dp != nullptr && input != "exit")
        //         // {
        //         //     qDebug() << "deepseek存在222";
        //         //     qDebug()<< input;
        //         //     dp->sendClicked(this);
        //         //     inputField->clear();
        //         // }
        //         // if( dp == nullptr || input == "exit")
        //         // {
        //         //     qDebug() << "deepseek不存在";
        //         //     delete dp;
        //         //     this->processInput(input);
        //         // }
        //         dp->sendClicked(this);
        //         inputField->clear();
        //         // 能否添加条件判断，当terminaltest实例被创建时，执行另一种命令
        //     }
        // });
        QObject::connect(executeButton, &QPushButton::clicked, [this, dp]() {
            QString input = inputField->text().trimmed();
            if (!input.isEmpty()) {
                outputArea->append("> " + input);   // 测试是否由于多余的符号导致无法识别命令 ？
                // outputArea->append(input.toUtf8() + "\r\n");
                // 关键！！！！！
                // this->processInput(input);
                qDebug()<< input;

                if( input == "exit" || dp == NULL )
                {
                    qDebug() << "deepseek不存在";
                    dp->isNull = !dp->isNull;
                    delete dp;
                    // dp = nullptr;
                    // 执行按钮点击事件
                    this->connclicked = QObject::connect(executeButton, &QPushButton::clicked, [this, dp]() {
                        QString input = inputField->text().trimmed();
                        if (!input.isEmpty()) {
                            outputArea->append("> " + input);   // 测试是否由于多余的符号导致无法识别命令 ？
                            // outputArea->append(input.toUtf8() + "\r\n");
                            // 关键！！！！！
                            this->processInput(input);
                            inputField->clear();
                            // 能否添加条件判断，当terminaltest实例被创建时，执行另一种命令

                        }
                    });
                }
                if( dp )
                {
                    qDebug() << "deepseek存在222";
                    qDebug()<< input;

                    dp->sendClicked(this);      // exit后就没有dp了，访问空指针！！！段错误

                    qDebug() << "deepseek deepseekdeepseekdeepseekdeepseekEXIT！！！";

                    inputField->clear();
                }

                // dp->sendClicked(this);
                // inputField->clear();
                // 能否添加条件判断，当terminaltest实例被创建时，执行另一种命令
            }
        });
#endif
        deepseekTalk * dp = new deepseekTalk(this);

        // 保存原始连接的副本
        auto originalHandler = [this]() {
            QString input = this->ui->inputField->text().trimmed();
            if (!input.isEmpty()) {
                this->ui->outputArea->append("> " + input);
                this->processInput(input);
                this->ui->inputField->clear();
            }
        };

        // 断开原始连接
        disconnect(connclicked);

        // 设置 deepseek 模式下的新连接
        connclicked = QObject::connect(this->ui->executeButton, &QPushButton::clicked, this, [this, dp, originalHandler]() {
            QString input = this->ui->inputField->text().trimmed();
            if (!input.isEmpty()) {
                this->ui->outputArea->append("> " + input);

                if (input == "exit") {
                    // 1. 断开 deepseek 连接
                    disconnect(connclicked);
                    // 2. 删除 deepseek 实例
                    delete dp;
                    // dp = nullptr;
                    // 3. 恢复原始连接
                    connclicked = QObject::connect(this->ui->executeButton, &QPushButton::clicked, this, originalHandler);
                    this->ui->inputField->clear();
                    return;
                }

                // 非 exit 命令，转发给 deepseek
                if (dp) {
                    dp->sendClicked(this);
                }
                this->ui->inputField->clear();
            }
        });

    }

    //    2. 应用名称到命令的映射

    // 3. 处理预定义应用
    // 不在映射表的程序，用完整路径可直接启动，用文件名则需依赖环境变量。
    else if(appMap.contains(appName)) {
        const QStringList& command = appMap[appName];

        // 特殊处理终端应用
        if (appName == "终端") {
            // executeInteractiveCommand(command[0], command.mid(1));

            // 使用终端映射时，能否将输入与输出分别重定向？
            TerminalWidget * terminaltest = new TerminalWidget(this);

            // this->terminaltest ;
            // terminaltest = new TerminalWidget(this)

            // 1. 设置字体样式（家族、大小、加粗等）
            QFont font;
            font.setFamily("Consolas");      // 字体家族
            font.setPointSize(12);           // 字体大小（磅值）
            font.setBold(true);              // 加粗
            font.setItalic(true);            // 斜体
            font.setUnderline(true);         // 下划线
            font.setFixedPitch(true);        // 等宽字体
            // textEdit->setFont(font);         // 应用字体到控件

            // 2. 设置字体颜色（通过QPalette）
            QPalette palette = terminaltest->palette();  // 获取控件当前的调色板
            palette.setColor(QPalette::Text, QColor("#00ff00"));  // 设置文本颜色（绿色）
            palette.setColor(QPalette::Base, QColor("black"));
            // 如果需要设置选中文本的颜色，可添加：
            // palette.setColor(QPalette::HighlightedText, QColor("red"));
            terminaltest->setPalette(palette);   // 应用调色板到控件


            // TerminalWidget * terminaltest = new TerminalWidget();
            terminaltest->setFont(font);
            // terminaltest->show();

            // 刷新连接，执行按钮点击事件, 当进入终端时，断开原来的连接，重新赋值，刷新，将输入按键时的内容重载，重新设置，与terminaltest的案件虫子啊和信誉举行同，重新设置后发送到终端
            disconnect(this->connclicked);

            // 断开连接后，要监测终端进程状态，当退出时 ，重新连接

            // this->connclicked = QObject::connect(this->executeButton, &QPushButton::clicked, [&]() {
            //     QString input = inputField->text().trimmed();
            //     if (!input.isEmpty()) {
            //         // outputArea->append("> " + input);   // 测试是否由于多余的符号导致无法识别命令 ？
            //         // outputArea->append(input.toUtf8() + "\r\n");
            //         // 关键！！！！！
            //         // this->processInput(input);
            //         terminaltest->process->write(input.toUtf8() + "\r\n");
            //         inputField->clear();
            //     }
            // });


            // 暂时未设置连接复原，仅做测试


        }

        // 使用startDetached确保程序独立运行
        bool success = QProcess::startDetached(     // 这种方法适用于需要启动外部工具或应用程序，并且不需要与它进行交互的场景。如果需要与启动的进程进行通信（如读取输出、写入输入），则应该使用QProcess对象的非静态方法。
            command[0],
            command.mid(1),
            QDir::homePath(),  // 设置工作目录
            &pid
            );

        if (success) {
            PIDMap.insert(appName, pid);
            //
            emit commandResult(tr("已启动应用: %1, PID:%2").arg(appName).arg(pid));
        } else {
            emit errorOccurred(tr("启动应用失败: %1").arg(appName));
        }
        return;
    }

    else
    {
        // 4. 尝试直接执行命令：环境变量中已配置路径的程序
        bool success = QProcess::startDetached(appName, {}, QDir::homePath());

        if (success) {
            emit commandResult(tr("已执行命令: %1").arg(appName));
        } else {
            emit errorOccurred(tr("无法执行命令: %1").arg(appName));
        }
    }

}

void CommandBox::CloseApplication(const QString& appName)
{
    int appPid = PIDMap[appName];


    // 关闭进程（需要根据PID操作）,每次关闭不论是否成功都要清除映射
    if (appPid > 0) {
        // Windows系统：使用taskkill命令
#ifdef Q_OS_WIN
        // QString killCommand = QString("taskkill /F /PID %1").arg(appPid);
        // int result = QProcess::execute(killCommand);
        // if (result != 0) {
        //     qDebug() << "关闭进程失败，PID：" << appPid;
        // } // 强制关闭进程
        // int result = QProcess::execute("taskkill", {
        //                                                "/F",
        //                                                "/PID",
        //                                                QString::number(appPid)
        //                                            });      // 显示没有找到进程？
        // if (result != 0) {
        //     qDebug() << "关闭进程失败，PID：" << appPid;
        //     qDebug() << "关闭进程失败，错误码：" << result;
        //     } // 强制关闭进程

        // killProcessByPid(appPid);

        QProcess taskkill;
        taskkill.start("taskkill", {"/F", "/PID", QString::number(appPid)});
        taskkill.waitForFinished();

        // 调用示例
        if (!isProcessAlive(appPid)) {
            qDebug() << "目标进程已不存在，PID：" << appPid;
            return;
        }

        // 输出错误信息
        qDebug() << "taskkill 错误输出：" << taskkill.readAllStandardError();
        qDebug() << "taskkill 退出码：" << taskkill.exitCode();

        // 调用示例
        if (!isProcessAlive(appPid)) {
            qDebug() << "目标进程已不存在，PID：" << appPid;
            return;
        }

        // Linux/macOS系统：使用kill命令
#elif defined(Q_OS_LINUX) || defined(Q_OS_MACOS)
        QString killCommand = QString("kill -9 %1").arg(pid);  // -9表示强制终止
        QProcess::execute(killCommand);

#endif
    }
    PIDMap.clear();

}




void CommandBox::Openfile(const QString& fileName)
{
    // 将本地文件路径转换为 QUrl（自动处理跨平台路径格式）
    QUrl fileUrl = QUrl::fromLocalFile(fileName);

    // 调用系统默认程序打开文件
    bool success = QDesktopServices::openUrl(fileUrl);

    if (success) {
        qDebug() << "文件已用默认程序打开：" << fileName;
    } else {
        qDebug() << "打开文件失败，可能原因：文件不存在或无关联程序";
    }
}

void CommandBox::Closefile(const QString& fileName)
{




}


void CommandBox::createFile(const QString& fileName)
{
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly)) {
        // file.close();
        emit commandResult(tr("文件已创建: %1").arg(fileName));
    } else {
        emit errorOccurred(tr("文件创建失败: %1").arg(fileName));
    }
}

void CloseFile(const QString& fileName)
{

}

void CommandBox::searchFiles(const QString& pattern)
{
    QDir currentDir(QDir::currentPath());
    QStringList foundFiles;

    // 递归搜索文件
    QDirIterator it(currentDir.path(), QDirIterator::Subdirectories);
    while (it.hasNext()) {
        QString filePath = it.next();
        if (filePath.contains(pattern)) {
            foundFiles.append(filePath);
        }
    }

    if (foundFiles.isEmpty()) {
        emit commandResult(tr("未找到匹配文件: %1").arg(pattern));
    } else {
        emit commandResult(tr("找到 %1 个匹配文件:\n%2")
                               .arg(foundFiles.size())
                               .arg(foundFiles.join("\n")));
    }
}

void CommandBox::runSystemCommand(const QString& command)
{
    QProcess process;
    process.start(command);

    if (!process.waitForStarted()) {
        emit errorOccurred(tr("命令启动失败: %1").arg(command));
        return;
    }

    if (!process.waitForFinished()) {
        emit errorOccurred(tr("命令执行超时: %1").arg(command));
        return;
    }

    QString output = QString::fromUtf8(process.readAllStandardOutput());
    QString error = QString::fromUtf8(process.readAllStandardError());

    if (!error.isEmpty()) {
        emit errorOccurred(tr("命令错误:\n%1").arg(error));
    } else {
        emit commandResult(tr("命令执行成功:\n%1").arg(output));
    }
}

void CommandBox::getCurrentTime()
{
    QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    emit commandResult(tr("当前时间: %1").arg(currentTime));
}
