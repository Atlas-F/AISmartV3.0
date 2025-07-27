#ifndef WIDGETTEST_H
#define WIDGETTEST_H

#include <QWidget>
#include "animationdemo.h"
#include "ui_widgetTest.h"

namespace Ui {
class widgetTest;
}

class widgetTest : public QWidget
{
    Q_OBJECT

public:
    explicit widgetTest(QWidget *parent = nullptr);
    ~widgetTest();

    QPushButton* getpushButton() const { return ui->pushButton; }    // 使用ui，需要包含定义，头文件
    QPushButton* getpushButton_2() const { return ui->pushButton_2; }
    QPushButton* getpushButton_3() const { return ui->pushButton_3; }
    QPushButton* getpushButton_4() const { return ui->pushButton_4; }
    QPushButton* getpushButton_5() const { return ui->pushButton_5; }
    QPushButton* getpushButton_6() const { return ui->pushButton_6; }
    QPushButton* getpushButton_7() const { return ui->pushButton_7; }
    QPushButton* getpushButton_8() const { return ui->pushButton_8; }
    QPushButton* getpushButton_9() const { return ui->pushButton_9; }

private:
    Ui::widgetTest *ui;
};

#endif // WIDGETTEST_H
