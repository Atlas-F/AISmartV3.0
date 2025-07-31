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

#include "terminalwidget.h"
#include <fstream>

#ifdef _WIN32
#include <windows.h> // Windows特定功能
#else
#include <unistd.h> // Linux/MacOS功能
#endif



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#if 0
    // 创建字体对象并设置属性
    QFont font;
    font.setFamily("Consolas"); // 字体家族（如"Consolas"、"SimHei"、"Arial"）
    font.setPointSize(12);      // 字体大小（磅值）
    font.setBold(true);         // 加粗
    font.setItalic(true);       // 斜体
    font.setUnderline(true);    // 下划线
    font.setFixedPitch(true);   // 等宽字体（终端/代码编辑器常用）



    TerminalWidget terminaltest;

    // 应用字体到QTextEdit
    terminaltest.setFont(font);
    terminaltest.show();

#endif

# if 1
    // 仅用作测试，如何打开终端时，重定向到文本框，关闭时正常显示

    // 创建命令系统
    CommandSystem commandSystem;
    commandSystem.initialize();
    // 创建主窗口
    QWidget window;
    window.setWindowTitle("Command Box");
    window.resize(800, 600);

    // 创建布局
    QVBoxLayout *layout = new QVBoxLayout(&window);

    // 输出区域
    commandSystem.outputArea = new QTextEdit;
    commandSystem.outputArea->setReadOnly(true);
    layout->addWidget(commandSystem.outputArea);

    // commandSystem.outputArea2 = new QTextEdit;
    // commandSystem.outputArea2->setReadOnly(true);
    // layout->addWidget(commandSystem.outputArea2);

    // 输入区域
    commandSystem.inputField = new QLineEdit;
    commandSystem.inputField->setPlaceholderText("请输入指令...");
    layout->addWidget(commandSystem.inputField);

    // 按钮
    commandSystem.executeButton = new QPushButton("执行");
    layout->addWidget(commandSystem.executeButton);

    // 状态标签
    commandSystem.statusLabel = new QLabel("就绪");
    layout->addWidget(commandSystem.statusLabel);

#if 0

    window.setStyleSheet("background-color:#0D0221;");

    commandSystem.inputField->setStyleSheet("border:5px ridge #B3E5FC;"
                                            "border-radius:10px;"
                                            "font-size:15px;"
                                            "color:#05D9E8;"
                                            "background-color:black;"
                                            );

    commandSystem.outputArea->setStyleSheet("border:5px ridge #8A2BE2;"
                                            "border-radius:10px;"
                                            "font-size:15px;"
                                            "color:#00FF00;"
                                            "background-color:black;"
                                            );

    commandSystem.executeButton->setStyleSheet("border:5px ridge #FF2A6D;"
                                               "border-radius:10px;"
                                               "font-size:15px;"
                                               "color:#00FF00;"
                                               "background-color:black;"
                                               );

    commandSystem.statusLabel->setStyleSheet(
                                             "font-size:15px;"
                                             "color:white;"
                                             "background-color:black;"
                                             );
#endif

    // commandSystem.show();
    // 赋值给局部变量，用于捕获列表 ，捕获列表支支持局部变量，不支持对象.成员方式
    QTextEdit* outputArea = commandSystem.outputArea;
    QLineEdit* inputField = commandSystem.inputField;
    QPushButton * executeButton = commandSystem.executeButton;
    QLabel * statusLabel = commandSystem.statusLabel;
    // 连接信号
    commandSystem.conncommandResult = QObject::connect(&commandSystem, &CommandSystem::commandResult,
                     [outputArea, statusLabel](const QString& result) {
                         outputArea->append("结果: " + result);
                         statusLabel->setText("命令执行成功");
                     });

    commandSystem.connerrorOccurred = QObject::connect(&commandSystem, &CommandSystem::errorOccurred,
                     [outputArea, statusLabel](const QString& error) {
                         outputArea->append("错误: " + error);
                         statusLabel->setText("发生错误");
                     });

    // 执行按钮点击事件
    commandSystem.connclicked = QObject::connect(executeButton, &QPushButton::clicked, [&]() {
        QString input = inputField->text().trimmed();
        if (!input.isEmpty()) {
            outputArea->append("> " + input);   // 测试是否由于多余的符号导致无法识别命令 ？
            // outputArea->append(input.toUtf8() + "\r\n");
            // 关键！！！！！
            commandSystem.processInput(input);
            inputField->clear();
            // 能否添加条件判断，当terminaltest实例被创建时，执行另一种命令

        }
    });

    // 回车键执行
    // 这个信号连接似乎就是表示当按下enter或者return时，执行点击按钮的动作？
    QObject::connect(inputField, &QLineEdit::returnPressed, executeButton, &QPushButton::click);

    window.show();

#endif

    // MainWin w;
    // w.show();

#if 0

    // // 设置应用样式
    a.setStyle("Fusion");
    // // 设置调色板
    QPalette palette;
    palette.setColor(QPalette::Window, QColor(53,53,53));
    palette.setColor(QPalette::WindowText, Qt::white);
    palette.setColor(QPalette::Base, QColor(25,25,25));
    palette.setColor(QPalette::AlternateBase, QColor(53,53,53));
    palette.setColor(QPalette::ToolTipBase, Qt::white);
    palette.setColor(QPalette::ToolTipText, Qt::white);
    palette.setColor(QPalette::Text, Qt::white);
    palette.setColor(QPalette::Button, QColor(53,53,53));
    palette.setColor(QPalette::ButtonText, Qt::white);
    palette.setColor(QPalette::BrightText, Qt::red);
    palette.setColor(QPalette::Link, QColor(42, 130, 218));
    palette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    palette.setColor(QPalette::HighlightedText, Qt::black);
    a.setPalette(palette);

    MainWindow window;
    window.show();

#endif

    // deepseekTalk dp;
    // dp.show();

#if 0

    // 动画功能类
    // 注册自定义属性类型
    qRegisterMetaType<qreal>("qreal");

    // // 创建并显示主窗口
    MyAnimationDemo demo;
    demo.show();
    demo.colorAnimation(demo, Qt::red, Qt::blue, 1000 , nullptr);

    widgetTest wtest;
    wtest.show();
    AnimationDemo::Animationinstance().slideAnimation(wtest.getpushButton());
    QThread::sleep(10);
    AnimationDemo::Animationinstance().bounceAnimation(wtest.getpushButton_2());
    QThread::sleep(1);
    AnimationDemo::Animationinstance().colorAnimation(wtest.getpushButton_3());
    QThread::sleep(1);
    AnimationDemo::Animationinstance().fadeAnimation(wtest.getpushButton_4(), true);
    QThread::sleep(1);
    AnimationDemo::Animationinstance().complexAnimation(wtest.getpushButton_5());
    _sleep(1);

#endif


#if 0

    时间日期天气
    DateTime today;
    today.show();

    // 父窗口
    QWidget *parentWidget = new QWidget;
    parentWidget->setWindowTitle("父窗口");
    parentWidget->resize(800, 600);

    // 创建子窗口（实际是 QWidget）
    QWidget *childWidget = new QWidget(parentWidget);  // 关键：指定父对象
    childWidget->setWindowTitle("子窗口");
    childWidget->setStyleSheet("background-color: lightblue;");
    childWidget->setMinimumSize(400, 300);

    // 使用布局管理器
    QVBoxLayout *layout = new QVBoxLayout(parentWidget);
    layout->addWidget(childWidget);  // 将子窗口添加到布局

    parentWidget->show();

    Weather guangzhou;
    guangzhou.show();

#endif
    qDebug() << "准备进入事件循环";
    return a.exec();
}
