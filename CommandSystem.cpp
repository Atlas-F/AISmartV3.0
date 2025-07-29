#include "CommandSystem.h"
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


#include <QProcess>    // 核心：用于QProcess::startDetached()和执行系统命令
#include <qglobal.h>   // 用于跨平台宏定义（如Q_OS_WIN、Q_OS_LINUX等）


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




CommandSystem::CommandSystem(QObject *parent)
    : QObject(parent), m_ruleEngine(new RuleEngine(this))
{
    // 连接规则引擎的未匹配信号
    connect(m_ruleEngine, &RuleEngine::noMatchFound, this, [this](const QString& input){
        emit commandResult(tr("未识别的命令: %1").arg(input));
    });


}


// 2. 应用名称到命令的映射
// 将map设为全局，而非设置
const QMap<QString, QStringList> CommandSystem::appMap = []{
        QMap<QString, QStringList> map;
        // map.insert("notepad", {"D:/Notepad++/notepad.exe"});
        map.insert("notepad", {"D:/Notepad++/notepad++.exe"});      // 这种方式可以在新窗口中打开程序
        // map.insert("thonny", {"D:/Thonny/thonny.exe"});      // 直接在输入框键入完整路径的方式速度更快，非常快

        map.insert("Steam", {"C:/Users/Public/Desktop/Steam.exe"});     // 快捷方式无法执行
        map.insert("ak", {"D:/AKPlatform/AK.exe"});
        map.insert("微信开发者工具", {"D:/微信web开发者工具/微信开发者工具.exe"});
        map.insert("uv4", {"D:/Keil_v5/UV4/UV4.exe"});


        // 跨平台命令定义
#ifdef Q_OS_WIN
        map.insert("计算器", {"cmd.exe", "/c", "start", "calc.exe"});
        map.insert("记事本", {"cmd.exe", "/c", "start", "notepad.exe"});
        map.insert("终端", {"cmd.exe"});
#elif defined(Q_OS_MACOS)
        map.insert("计算器", {"open", "-a", "Calculator"});
        map.insert("记事本", {"open", "-a", "TextEdit"});
        map.insert("终端", {"open", "-a", "Terminal"});
#else
        map.insert("计算器", {"gnome-calculator"});ne
        map.insert("记事本", {"gedit"});
        map.insert("终端", {"gnome-terminal"});
#endif
        return map;
    }();

void CommandSystem::initialize()
{
    // 添加打开应用程序规则
    m_ruleEngine->addRule("OpenApp",
                          R"(打开\s*(.*))",
                          [this](const QRegularExpressionMatch& match) {
                              QString appName = match.captured(1).trimmed();
                              openApplication(appName);
                          });

    // 添加关闭应用程序规则(未完成)
    m_ruleEngine->addRule("CloseApp",
                          R"(关闭\s*(.*))",
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

// void CommandSystem::openApplication(const QString& appName)
// {
//     // 应用名称到实际命令的映射
//     static const QMap<QString, QString> appMap = {
//         {"浏览器", "https://www.qt.io"},
//         {"notepad", "D:/Notepad++/notepad.exe"},
//         {"计算器",
// #ifdef Q_OS_WIN
//             "calc.exe"
// #elif defined(Q_OS_MACOS)
//             "open -a Calculator"
// #else
//             "gnome-calculator"
// #endif
//         },
//         {"记事本",
// #ifdef Q_OS_WIN
//             "notepad.exe"
// #elif defined(Q_OS_MACOS)
//             "open -a TextEdit"
// #else
//             "gedit"
// #endif
//         }
//     };

//     if (appMap.contains(appName)) {
//         QString command = appMap[appName];

//         if (appName == "浏览器") {
//             // 使用QDesktopServices打开URL
//             QDesktopServices::openUrl(QUrl(command));   // 为什么使用QDesktopServices？是只能打开桌面上有的应用吗？
//             emit commandResult(tr("已打开浏览器"));
//         } else {
//             // 使用QProcess启动应用程序
//             QProcess process;
//             process.start(command);     // 这里才是核心启动代码吗？
//             if (process.waitForStarted(5000)) {
//                 emit commandResult(tr("已启动应用: %1").arg(appName));
//             } else {
//                 emit errorOccurred(tr("启动应用失败: %1").arg(appName));
//             }
//         }
//     } else {
//         // 尝试直接执行命令
//         QProcess process;
//         process.start(appName);
//         if (process.waitForStarted(5000)) {     // 不是会等待吗？
//             emit commandResult(tr("已执行命令: %1").arg(appName));
//         } else {
//             emit errorOccurred(tr("无法执行命令: %1").arg(appName));
//         }
//     }
// }



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

    // 2. 应用名称到命令的映射
    // 将map设为全局，而非设置
//     static const QMap<QString, QStringList> appMap = []{
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

    // 3. 处理预定义应用
    if (appMap.contains(appName)) {
        const QStringList& command = appMap[appName];

        // // 特殊处理终端应用
        // if (appName == "终端") {
        //     executeInteractiveCommand(command[0], command.mid(1));
        //     return;
        // }

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

    // 4. 尝试直接执行命令
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


    // 关闭进程（需要根据PID操作）
    if (appPid > 0) {
        // Windows系统：使用taskkill命令
#ifdef Q_OS_WIN
        QString killCommand = QString("taskkill /F /PID %1").arg(appPid);
        int result = QProcess::execute(killCommand);
        if (result != 0) {
            qDebug() << "关闭进程失败，PID：" << appPid;
        } // 强制关闭进程

        // Linux/macOS系统：使用kill命令
#elif defined(Q_OS_LINUX) || defined(Q_OS_MACOS)
        QString killCommand = QString("kill -9 %1").arg(pid);  // -9表示强制终止
        QProcess::execute(killCommand);

#endif
    }





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

void CommandSystem::createFile(const QString& fileName)
{
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly)) {
        file.close();
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
