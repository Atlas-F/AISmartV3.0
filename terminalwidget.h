#ifndef _TERMINALWIDGET_H_
#define _TERMINALWIDGET_H_
#include <QProcess>
#include <QTextEdit>

#include <QKeyEvent>
#include <QTextBlock>

// #include "CommandSystem.h"
#include <QDebug>
#include "commandbox.h"

#include "ui_commandbox.h"



// 似乎可以通过让该类继承自commandsystem，然后指定输出为outputarea
// commandsystem 已经有连接信号槽，将输入指定重定向到outputarea


class TerminalWidget : public QTextEdit {

    QTextEdit* outputEdit;
    QByteArray output;

public:
    QProcess* process;
    TerminalWidget(CommandBox* parent = nullptr){

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
            parent->ui->outputArea->append(output);     // 尝试将command对象传入，然后再引用成员变量outputarea
            // append(output);  // 显示输出
            // outputEdit->append(output);  // 显示输出
        });
        connect(process, &QProcess::readyReadStandardError, this, [=]() {
            parent->ui->outputArea->append(process->readAllStandardError());
            // append(process->readAllStandardError()); // 显示错误信息
        });
        // 4. 启动cmd并执行命令
        // process->start("cmd.exe", QStringList() << "/c" << "dir");
        // process->start("cmd.exe"); // 没有按键映射
        process->start("cmd.exe", QStringList() << "/k");


        // // 输入框按回车时发送数据
        // connect(parent->inputField, &QLineEdit::returnPressed,
        //         this, &TerminalWidget::onInputEntered);

        connect(parent->ui->inputField, &QLineEdit::returnPressed, this, [=]() {
            if( process->state() == QProcess::Running )
            {
                // 获取输入框中的命令
                QString command = parent->ui->inputField->text();
                // 向进程写入命令（核心语句保持不变）
                process->write(command.toUtf8() + "\r\n");
                // 可选：清空输入框
                parent->ui->inputField->clear();
            }
            if( process->state() != QProcess::Running )
            {
                parent->connclicked = QObject::connect(parent->ui->executeButton, &QPushButton::clicked, [&]() {
                    QString input = parent->ui->inputField->text().trimmed();
                    if (!input.isEmpty()) {
                        // parent->outputArea->append("> " + input);   // 测试是否由于多余的符号导致无法识别命令 ？
                        // outputArea->append(input.toUtf8() + "\r\n");
                        // 关键！！！！！
                        parent->processInput(input);
                        parent->ui->inputField->clear();
                        // 能否添加条件判断，当terminaltest实例被创建时，执行另一种命令

                    }
                });
            }
        });
    }
    ~TerminalWidget(){};
public slots:


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
            // 关键！！！！！
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
