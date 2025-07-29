#include "terminalwidget.h"

// 在头文件中定义，而不是在源文件中定义，在源文件中定义会出现多重定义的错误，原因未知
// TerminalWidget::TerminalWidget(QWidget *parent )
//     : CommandSystem(parent) {
//     process = new QProcess(this);
//     qDebug()<< "terminaltest  init";
//     // 连接信号
//     connect(process, &QProcess::readyReadStandardOutput, [=](){
//         outputArea->append(process->readAllStandardOutput());
//     });

//     connect(process, &QProcess::readyReadStandardError, [=](){
//         outputArea->append("<span style='color:red'>" +
//                            process->readAllStandardError() + "</span>");
//     });

// // 启动命令解释器
// #ifdef Q_OS_WIN
//     process->start("cmd.exe");
// #endif

//     // 设置提示符
//     outputArea->append("Microsoft Windows [Version 10.0.19045.3803]");
//     outputArea->append("(c) Microsoft Corporation. All rights reserved.");
//     outputArea->append("FakeTerminal:\\>");
// }


// void keyPressEvent(QKeyEvent* event) override
// void TerminalWidget::keyPressEvent(QKeyEvent* event)  {
//     if (event->key() == Qt::Key_Return) {
//         // 获取当前行命令
//         qDebug()<< "terminaltest  keyPressEvent2";
//         int lastSeparatorPos = textCursor().block().text().lastIndexOf('>');

//         QString command = textCursor().block().text().mid(lastSeparatorPos+1);
//         // 发送命令到进程
//         process->write(command.toUtf8() + "\r\n");
//         qDebug()<< "terminaltest  keyPressEvent3";
//         // 添加新提示符
//         // append("C:\\>");
//     }
//     else {
//         QTextEdit::keyPressEvent(event);
//         qDebug()<< "keyPressEvent  failed";
//     }
// }
