#ifndef _TERMINALWIDGET_H_
#define _TERMINALWIDGET_H_
#include <QProcess>
#include <QTextEdit>

#include <QKeyEvent>
#include <QTextBlock>

#include "CommandSystem.h"
#include <QDebug>


// 似乎可以通过让该类继承自commandsystem，然后指定输出为outputarea
// commandsystem 已经有连接信号槽，将输入指定重定向到outputarea

// class TerminalWidget : public QTextEdit
// class TerminalWidget : public CommandSystem {
//     QProcess* process;

// public:

//     TerminalWidget(QWidget* parent = nullptr) : CommandSystem(parent) {
//         process = new QProcess(this);
//         qDebug()<< "terminaltest  init";
//         // 连接信号
//         connect(process, &QProcess::readyReadStandardOutput, [=](){
//             outputArea->append(process->readAllStandardOutput());
//         });

//         connect(process, &QProcess::readyReadStandardError, [=](){
//             outputArea->append("<span style='color:red'>" +
//                    process->readAllStandardError() + "</span>");
//         });

// // 启动命令解释器
// #ifdef Q_OS_WIN
//         process->start("cmd.exe");
// #endif

//         // 设置提示符
//         outputArea->append("Microsoft Windows [Version 10.0.19045.3803]");
//         outputArea->append("(c) Microsoft Corporation. All rights reserved.");
//         outputArea->append("FakeTerminal:\\>");
//     }

// protected:
//     // void keyPressEvent(QKeyEvent* event) override
//     void keyPressEvent(QKeyEvent* event)  {
//         if (event->key() == Qt::Key_Return) {
//             // 获取当前行命令

//             int lastSeparatorPos = outputArea->textCursor().block().text().lastIndexOf('>');

//             QString command = outputArea->textCursor().block().text().mid(lastSeparatorPos+1);
//             // 发送命令到进程
//             process->write(command.toUtf8() + "\r\n");

//             // 添加新提示符
//             // append("C:\\>");
//         }
//         else {
//             // QTextEdit::keyPressEvent(event);
//             qDebug()<< "keyPressEvent  failed";
//         }
//     }
// };


class TerminalWidget : public QTextEdit {
    QProcess* process;
    QTextEdit* outputEdit;
    QByteArray output;

public:
    TerminalWidget(CommandSystem* parent = nullptr){
//         process = new QProcess(this);
//         qDebug()<< "terminaltest  init";
//         // 连接信号
//         // connect(process, &QProcess::readyReadStandardOutput, [=](){
//         //     append(process->readAllStandardOutput());
//         // });
//         qDebug()<< "terminaltest  connect1";

//         // 关联输出信号
//         connect(process, &QProcess::readyReadStandardOutput, this, [=]() {
//             QByteArray output = process->readAllStandardOutput();
//             append(output); // 显示到QTextEdit
//         });
//         // outputEdit->append(output);

//         // connect(process, &QProcess::readyReadStandardError, [=](){
//         //     append("<span style='color:red'>" +
//         //                        process->readAllStandardError() + "</span>");
//         // });
//         qDebug()<< "terminaltest  connect2";

//         connect(process, &QProcess::readyReadStandardOutput, this, [=]() {
//             QByteArray output = process->readAllStandardOutput();
//             append("<span style='color:red'>" + output + "</span>"); // 显示到QTextEdit
//         });

// // 启动命令解释器
// #ifdef Q_OS_WIN
//         process->start("cmd.exe");
// #endif
//         qDebug()<< "terminaltest  connect3";
//         // 设置提示符
//         append("Microsoft Windows [Version 10.0.19045.3803]zwaexdcfvgbhnjmk");
//         append("(c) Microsoft Corporation. All rights reserved.aasdfghjasdfhjwsdghasdfasdf");
//         append("FakeTerminal:\\>");

//         qDebug()<< "terminaltest  connect4";

        resize(600, 400);
        setStyleSheet(R"(
                QLabel { color: #333; font-weight: bold; }
                QPushButton { background-color: #2196F3; }
                QTextEdit#usertext
                {
                    border-width:15px;
                    border-style:ridge;
                    border-color:#00BFFF;
                    border-radius:30px;
                    background-color:black;
                    Font-size:15px;
                    color:#00FF00;
                    outline-color:red;
                    outline-width:20px;
                    padding-width:5px;
                    padding-color:#1E90FF;

                }
            )");



        // 1. 将process改为指针，避免局部变量生命周期问题和复制操作
        process = new QProcess(this);  // 父对象设为this，自动管理生命周期
        // 2. 确保outputEdit正确初始化（建议作为类成员，避免重复创建）
        // outputEdit = new QTextEdit();
        // outputEdit->setGeometry(100, 100, 600, 400);  // 简单设置位置和大小
        // outputEdit->show();
        // 3. 关联信号槽，注意lambda捕获方式
        connect(process, &QProcess::readyReadStandardOutput, this, [=]() {
            // 由于process是指针，捕获的是指针（非const），可正常调用非const成员函数
            output = process->readAllStandardOutput();
            append(output);  // 显示输出
            // outputEdit->append(output);  // 显示输出
        });
        connect(process, &QProcess::readyReadStandardError, this, [=]() {
            append(process->readAllStandardError()); // 显示错误信息
        });
        // 4. 启动cmd并执行命令
        // process->start("cmd.exe", QStringList() << "/c" << "dir");
        process->start("cmd.exe"); // 没有按键映射





        // // 1. 将process改为指针，避免局部变量生命周期问题和复制操作
        // process = new QProcess(this);  // 父对象设为this，自动管理生命周期
        // // 2. 确保outputEdit正确初始化（建议作为类成员，避免重复创建）
        // outputEdit = new QTextEdit();
        // outputEdit->setGeometry(100, 100, 600, 400);  // 简单设置位置和大小
        // // outputEdit->show();
        // // 3. 关联信号槽，注意lambda捕获方式
        // connect(process, &QProcess::readyReadStandardOutput, this, [=]() {
        //     // 由于process是指针，捕获的是指针（非const），可正常调用非const成员函数
        //     output = process->readAllStandardOutput();
        //     outputEdit->append(output);  // 显示输出
        //     // outputEdit->append(output);  // 显示输出
        // });
        // connect(process, &QProcess::readyReadStandardError, this, [=]() {
        //     append(process->readAllStandardError()); // 显示错误信息
        // });
        // // 4. 启动cmd并执行命令
        // // process->start("cmd.exe", QStringList() << "/c" << "dir");
        // process->start("cmd.exe"); // 没有按键映射
    }
    ~TerminalWidget(){};

protected:
    // void keyPressEvent(QKeyEvent* event) override
    void keyPressEvent(QKeyEvent* event) override
    {
        if (event->key() == Qt::Key_Return) {
            // 获取当前行命令

            int lastSeparatorPos = textCursor().block().text().lastIndexOf('>');

            QString command = textCursor().block().text().mid(lastSeparatorPos+1);
            // 发送命令到进程
            qDebug() << "进程状态" << process->state();
            if( process->state() != QProcess::Running )
            {
                qDebug() << "启动失败原因" << process->errorString();
            }
            process->write(command.toUtf8() + "\r\n");
            // process->write("echo world\r\n");

            // 添加新提示符
            // append("C:\\>");
        }
        else {
            QTextEdit::keyPressEvent(event);    // 该表达式的作用是什么？
            qDebug()<< "keyPressEvent  failed";
        }
    }
};


#endif
