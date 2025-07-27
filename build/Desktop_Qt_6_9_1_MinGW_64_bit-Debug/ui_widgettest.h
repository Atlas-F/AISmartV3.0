/********************************************************************************
** Form generated from reading UI file 'widgettest.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETTEST_H
#define UI_WIDGETTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widgetTest
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;

    void setupUi(QWidget *widgetTest)
    {
        if (widgetTest->objectName().isEmpty())
            widgetTest->setObjectName("widgetTest");
        widgetTest->resize(877, 755);
        widgetTest->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-width:20px;\n"
"	border-style:ridge;\n"
"	border-color:red;\n"
"	background-color:purple;\n"
"\n"
"}"));
        pushButton = new QPushButton(widgetTest);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(330, 300, 221, 151));
        pushButton_2 = new QPushButton(widgetTest);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(610, 300, 221, 151));
        pushButton_3 = new QPushButton(widgetTest);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(330, 480, 221, 151));
        pushButton_4 = new QPushButton(widgetTest);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(50, 480, 221, 151));
        pushButton_5 = new QPushButton(widgetTest);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(60, 300, 221, 151));
        pushButton_6 = new QPushButton(widgetTest);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(610, 100, 221, 151));
        pushButton_7 = new QPushButton(widgetTest);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(330, 100, 221, 151));
        pushButton_8 = new QPushButton(widgetTest);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(60, 100, 221, 151));
        pushButton_9 = new QPushButton(widgetTest);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(610, 480, 221, 151));

        retranslateUi(widgetTest);

        QMetaObject::connectSlotsByName(widgetTest);
    } // setupUi

    void retranslateUi(QWidget *widgetTest)
    {
        widgetTest->setWindowTitle(QCoreApplication::translate("widgetTest", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("widgetTest", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("widgetTest", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("widgetTest", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("widgetTest", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("widgetTest", "PushButton", nullptr));
        pushButton_6->setText(QCoreApplication::translate("widgetTest", "PushButton", nullptr));
        pushButton_7->setText(QCoreApplication::translate("widgetTest", "PushButton", nullptr));
        pushButton_8->setText(QCoreApplication::translate("widgetTest", "PushButton", nullptr));
        pushButton_9->setText(QCoreApplication::translate("widgetTest", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class widgetTest: public Ui_widgetTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETTEST_H
