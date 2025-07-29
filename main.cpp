#include "mainwin.h"
#include "deepseektalk.h"
#include "datetime.h"
#include "animationdemo.h"
#include "widgettest.h"

#include <QThread>
#include <QApplication>

#include <QTextEdit>
#include <QLineEdit>



// #include "RuleEngine.h"
#include <iostream>
#include <cstdlib> // 用于系统命令
#include "CommandSystem.h"
#include <fstream>

#ifdef _WIN32
#include <windows.h> // Windows特定功能
#else
#include <unistd.h> // Linux/MacOS功能
#endif


// // 文件系统操作
// void createFile(const std::string& filename) {
//     std::ofstream file(filename);
//     if (file) {
//         std::cout << "文件已创建: " << filename << std::endl;
//     } else {
//         std::cerr << "文件创建失败: " << filename << std::endl;
//     }
// }

// // 应用程序操作
// void openApplication(const std::string& appName) {
// #ifdef _WIN32
//     // Windows系统
//     if (appName == "浏览器") {
//         ShellExecute(0, 0, "https://www.google.com", 0, 0, SW_SHOW);
//     } else if (appName == "计算器") {
//         system("calc");
//     } else if (appName == "记事本") {
//         system("notepad");
//     } else {
//         std::string command = "start " + appName;
//         system(command.c_str());
//     }
// #else
//     // Linux/MacOS系统
//     if (appName == "浏览器") {
//         system("xdg-open https://www.google.com");
//     } else if (appName == "计算器") {
//         system("gnome-calculator &");
//     } else if (appName == "文本编辑器") {
//         system("gedit &");
//     } else {
//         std::string command = appName + " &";
//         system(command.c_str());
//     }
// #endif
// }

// // 系统命令执行
// void runSystemCommand(const std::string& command) {
//     std::cout << "执行系统命令: " << command << std::endl;
//     system(command.c_str());
// }

// // 文件搜索
// void searchFiles(const std::string& pattern) {
// #ifdef _WIN32
//     std::string command = "dir /s /b *" + pattern + "*";
// #else
//     std::string command = "find . -name '*" + pattern + "*'";
// #endif

//     std::cout << "搜索文件: " << pattern << std::endl;
//     system(command.c_str());
// }


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 创建主窗口
    QWidget window;
    window.setWindowTitle("Qt 命令系统");
    window.resize(600, 400);

    // 创建布局
    QVBoxLayout *layout = new QVBoxLayout(&window);

    // 输出区域
    QTextEdit *outputArea = new QTextEdit;
    outputArea->setReadOnly(true);
    layout->addWidget(outputArea);

    // 输入区域
    QLineEdit *inputField = new QLineEdit;
    inputField->setPlaceholderText("请输入指令...");
    layout->addWidget(inputField);

    // 按钮
    QPushButton *executeButton = new QPushButton("执行");
    layout->addWidget(executeButton);

    // 状态标签
    QLabel *statusLabel = new QLabel("就绪");
    layout->addWidget(statusLabel);

    // 创建命令系统
    CommandSystem commandSystem;
    commandSystem.initialize();

    // 连接信号
    QObject::connect(&commandSystem, &CommandSystem::commandResult,
                     [outputArea, statusLabel](const QString& result) {
                         outputArea->append("结果: " + result);
                         statusLabel->setText("命令执行成功");
                     });

    QObject::connect(&commandSystem, &CommandSystem::errorOccurred,
                     [outputArea, statusLabel](const QString& error) {
                         outputArea->append("错误: " + error);
                         statusLabel->setText("发生错误");
                     });

    // 执行按钮点击事件
    QObject::connect(executeButton, &QPushButton::clicked, [&]() {
        QString input = inputField->text().trimmed();
        if (!input.isEmpty()) {
            outputArea->append("> " + input);
            commandSystem.processInput(input);
            inputField->clear();
        }
    });

    // 回车键执行
    // 这个信号连接似乎就是表示当按下enter或者return时，执行点击按钮的动作？
    QObject::connect(inputField, &QLineEdit::returnPressed, executeButton, &QPushButton::click);

    window.show();


    // MainWin w;
    // w.show();

    // // 设置应用样式
    // a.setStyle("Fusion");
    // // 设置调色板
    // QPalette palette;
    // palette.setColor(QPalette::Window, QColor(53,53,53));
    // palette.setColor(QPalette::WindowText, Qt::white);
    // palette.setColor(QPalette::Base, QColor(25,25,25));
    // palette.setColor(QPalette::AlternateBase, QColor(53,53,53));
    // palette.setColor(QPalette::ToolTipBase, Qt::white);
    // palette.setColor(QPalette::ToolTipText, Qt::white);
    // palette.setColor(QPalette::Text, Qt::white);
    // palette.setColor(QPalette::Button, QColor(53,53,53));
    // palette.setColor(QPalette::ButtonText, Qt::white);
    // palette.setColor(QPalette::BrightText, Qt::red);
    // palette.setColor(QPalette::Link, QColor(42, 130, 218));
    // palette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    // palette.setColor(QPalette::HighlightedText, Qt::black);
    // a.setPalette(palette);

    // MainWindow window;
    // window.show();

    // deepseekTalk dp;
    // dp.show();

    // 动画功能类
    // 注册自定义属性类型
    qRegisterMetaType<qreal>("qreal");

    // // 创建并显示主窗口
    // MyAnimationDemo demo;
    // demo.show();
    // demo.colorAnimation(demo, Qt::red, Qt::blue, 1000 , nullptr);

    // widgetTest wtest;
    // wtest.show();
    // AnimationDemo::Animationinstance().slideAnimation(wtest.getpushButton());
    // QThread::sleep(10);
    // AnimationDemo::Animationinstance().bounceAnimation(wtest.getpushButton_2());
    // QThread::sleep(1);
    // AnimationDemo::Animationinstance().colorAnimation(wtest.getpushButton_3());
    // QThread::sleep(1);
    // AnimationDemo::Animationinstance().fadeAnimation(wtest.getpushButton_4(), true);
    // QThread::sleep(1);
    // AnimationDemo::Animationinstance().complexAnimation(wtest.getpushButton_5());
    // _sleep(1);

    // 时间日期天气
    // DateTime today;
    // today.show();

    // // 父窗口
    // QWidget *parentWidget = new QWidget;
    // parentWidget->setWindowTitle("父窗口");
    // parentWidget->resize(800, 600);

    // // 创建子窗口（实际是 QWidget）
    // QWidget *childWidget = new QWidget(parentWidget);  // 关键：指定父对象
    // childWidget->setWindowTitle("子窗口");
    // childWidget->setStyleSheet("background-color: lightblue;");
    // childWidget->setMinimumSize(400, 300);

    // // 使用布局管理器
    // QVBoxLayout *layout = new QVBoxLayout(parentWidget);
    // layout->addWidget(childWidget);  // 将子窗口添加到布局

    // parentWidget->show();

    // Weather guangzhou;
    // guangzhou.show();
    return a.exec();
}
