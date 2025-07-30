#include "CommandSystem.h"
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



// 检查 PID 是否存在
// bool isProcessAlive(qint64 pid) {

//     QProcess tasklist;
//     tasklist.start("tasklist", {"-FI", QString("PID eq %1").arg(pid)});
//     tasklist.waitForFinished();
//     QString output = tasklist.readAll();
//     // 若输出中包含 PID 对应的进程名，则存在
//     return output.contains(QString::number(pid));
// }


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


// 函数：尝试终止指定PID的进程，并返回是否成功
bool killProcessByPid(qint64 pid) {
    // 创建QProcess实例
    QProcess taskkill;

    // 启动taskkill命令，参数：强制终止（/F）、指定PID（/PID）
    taskkill.start("taskkill", {"/F", "/PID", QString::number(pid)});

    // 等待命令执行完成（超时时间设为5000毫秒，即5秒）
    bool finished = taskkill.waitForFinished(5000);

    // 如果命令未正常完成（超时或异常）
    if (!finished) {
        qDebug() << "taskkill命令执行超时或异常，错误类型：" << taskkill.errorString();
        return false;
    }

    // 读取标准错误输出（taskkill的错误信息通常在这里）
    QByteArray errorOutput = taskkill.readAllStandardError();
    // 读取标准输出（部分信息可能在这里）
    QByteArray standardOutput = taskkill.readAllStandardOutput();

    // 输出捕获到的信息（便于调试）
    if (!standardOutput.isEmpty()) {
        qDebug() << "taskkill标准输出：" << standardOutput;
    }
    if (!errorOutput.isEmpty()) {
        qDebug() << "taskkill错误输出：" << errorOutput;
    }

    // 获取命令退出码
    int exitCode = taskkill.exitCode();
    qDebug() << "taskkill退出码：" << exitCode;

    // 判断是否成功（exitCode为0表示成功）
    if (exitCode == 0) {
        qDebug() << "进程终止成功，PID：" << pid;
        return true;
    } else {
        qDebug() << "进程终止失败，PID：" << pid;
        return false;
    }
}


// // 交互式命令执行（新增）
// void CommandSystem::executeInteractiveCommand(const QString& program, const QStringList& arguments)
// {
//     if (m_interactiveProcess) {
//         m_interactiveProcess->kill();
//         delete m_interactiveProcess;
//     }

//     m_interactiveProcess = new QProcess(this);
//     m_interactiveProcess->setProgram(program);
//     m_interactiveProcess->setArguments(arguments);
//     m_interactiveProcess->setWorkingDirectory(QDir::homePath());

//     // 连接信号
//     connect(m_interactiveProcess, &QProcess::readyReadStandardOutput, [this]() {
//         emit commandOutput(m_interactiveProcess->readAllStandardOutput());
//     });

//     connect(m_interactiveProcess, &QProcess::readyReadStandardError, [this]() {
//         emit commandOutput("[ERROR] " + m_interactiveProcess->readAllStandardError());
//     });

//     connect(m_interactiveProcess, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
//             [this](int code, QProcess::ExitStatus) {
//                 emit commandFinished(code);
//                 delete m_interactiveProcess;
//                 m_interactiveProcess = nullptr;
//             });

//     // 启动进程
//     m_interactiveProcess->start();

//     if (!m_interactiveProcess->waitForStarted(3000)) {
//         emit errorOccurred(tr("终端启动失败"));
//         delete m_interactiveProcess;
//         m_interactiveProcess = nullptr;
//     } else {
//         emit commandResult(tr("终端已启动"));
//     }
// }

// // 向进程输入命令（新增）
// void CommandSystem::writeToProcess(const QString& command)
// {
//     if (m_interactiveProcess && m_interactiveProcess->state() == QProcess::Running) {
//         m_interactiveProcess->write(command.toUtf8() + "\n");
//     } else {
//         emit errorOccurred(tr("没有活动的终端会话"));
//     }
// }

// CommandSystem::CommandSystem(QObject *parent)
//     : QObject(parent), m_ruleEngine(new RuleEngine(this))


CommandSystem::CommandSystem(QObject *parent)
    : QObject(parent), m_ruleEngine(new RuleEngine(this))
{
    // 连接规则引擎的未匹配信号
    connect(m_ruleEngine, &RuleEngine::noMatchFound, this, [this](const QString& input){
        emit commandResult(tr("未识别的命令: %1").arg(input));
    });


}


// 2. 应用名称到命令的映射
// 将map设为全局，而非设置/*
// const QMap<QString, QStringList> CommandSystem::appMap = []{
//         QMap<QString, QStringList> map;
//         // map.insert("notepad", {"D:/Notepad++/notepad.exe"});
//         map.insert("notepad", {"D:/Notepad++/notepad++.exe"});      // 这种方式可以在新窗口中打开程序
//         // map.insert("thonny", {"D:/Thonny/thonny.exe"});      // 直接在输入框键入完整路径的方式速度更快，非常快

//         map.insert("Steam", {"C:/Users/Public/Desktop/Steam.exe"});     // 快捷方式无法执行
//         map.insert("ak", {"D:/AKPlatform/AK.exe"});
//         map.insert("微信开发者工具", {"D:/微信web开发者工具/微信开发者工具.exe"});
//         map.insert("uv4", {"D:/Keil_v5/UV4/UV4.exe"});


//         // 跨平台命令定义
// #ifdef Q_OS_WIN
//         map.insert("计算器", {"cmd.exe", "/c", "start", "calc.exe"});
//         map.insert("记事本", {"cmd.exe", "/c", "start", "notepad.exe"});
//         map.insert("终端", {"cmd.exe"});
// #elif defined(Q_OS_MACOS)
//         map.insert("计算器", {"open", "-a", "Calculator"});
//         map.insert("记事本", {"open", "-a", "TextEdit"});
//         map.insert("终端", {"open", "-a", "Terminal"});
// #else
//         map.insert("计算器", {"gnome-calculator"});ne
//         map.insert("记事本", {"gedit"});
//         map.insert("终端", {"gnome-terminal"});
// #endif
//         return map;
//     }();

void CommandSystem::initialize()
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
                                  commands.append(QString("%1: %2").arg(rule.name).arg(rule.pattern.pattern()));
                              }
                              emit commandResult(tr("可用命令:\n%1").arg(commands.join("\n")));
                          });
}

// input是裁剪首尾空格后的输入字符串
void CommandSystem::processInput(const QString& input)
{
    m_ruleEngine->execute(input);
}

RuleEngine* CommandSystem::ruleEngine() const
{
    return m_ruleEngine;
}




void CommandSystem::openApplication(const QString& appName)
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

    if( appName == "deepseek" )
    {
        deepseekTalk * dp = new deepseekTalk(nullptr);
        dp->show();

        qApp->processEvents();  // 作用是什么？
    }

//    2. 应用名称到命令的映射

    // 3. 处理预定义应用
    // 不在映射表的程序，用完整路径可直接启动，用文件名则需依赖环境变量。
    if (appMap.contains(appName)) {
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

    // 4. 尝试直接执行命令：环境变量中已配置路径的程序
    bool success = QProcess::startDetached(appName, {}, QDir::homePath());

    if (success) {
        emit commandResult(tr("已执行命令: %1").arg(appName));
    } else {
        emit errorOccurred(tr("无法执行命令: %1").arg(appName));
    }


}

void CommandSystem::CloseApplication(const QString& appName)
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




void CommandSystem::Openfile(const QString& fileName)
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

void CommandSystem::Closefile(const QString& fileName)
{




}


void CommandSystem::createFile(const QString& fileName)
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

void CommandSystem::searchFiles(const QString& pattern)
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

void CommandSystem::runSystemCommand(const QString& command)
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

void CommandSystem::getCurrentTime()
{
    QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    emit commandResult(tr("当前时间: %1").arg(currentTime));
}
