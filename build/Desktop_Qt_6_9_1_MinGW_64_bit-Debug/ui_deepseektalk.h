/********************************************************************************
** Form generated from reading UI file 'deepseektalk.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEEPSEEKTALK_H
#define UI_DEEPSEEKTALK_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_deepseekTalk
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *dpsktext;
    QHBoxLayout *horizontalLayout;
    QTextEdit *usertext;
    QPushButton *send;

    void setupUi(QWidget *deepseekTalk)
    {
        if (deepseekTalk->objectName().isEmpty())
            deepseekTalk->setObjectName("deepseekTalk");
        deepseekTalk->resize(1104, 868);
        deepseekTalk->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-width:20px;\n"
"	border-style:none;\n"
"	border-color:#1E90FF;\n"
"\n"
"	border-radius:20px;\n"
"	padding: 10px;\n"
"	Font-size:20px;\n"
"	color:#purple;\n"
"\n"
"}\n"
"\n"
"QPushButton#send\n"
"{\n"
"	border-width:20px;\n"
"	border-style:none;\n"
"\n"
"\n"
"	border-radius:55px;\n"
"\n"
"	Font-size:20px;\n"
"\n"
"\n"
"}\n"
"\n"
"/* \347\202\271\345\207\273\347\212\266\346\200\201\357\274\210::pressed\357\274\211\357\274\232\346\250\241\346\213\237\347\274\251\345\260\2171/4 */\n"
"QPushButton::pressed {\n"
"    /* \345\242\236\345\212\240\345\206\205\350\276\271\350\267\235\357\274\214\346\214\244\345\216\213\345\206\205\345\256\271\345\214\272\357\274\210\346\240\270\345\277\203\357\274\232\345\206\205\350\276\271\350\267\235\345\242\236\345\212\240\351\207\217=\345\216\237\345\260\272\345\257\270\347\232\2041/4\357\274\211 */\n"
"    padding: 50px 50px; /* \344\270\212\344\270\213\345\206\205\350\276\271\350\267\235=10+40=50px\357\274\214\345\267\246\345\217\263=10+40=50px\357\274"
                        "\210\350\246\206\347\233\2261/4\345\260\272\345\257\270\357\274\211 */\n"
"    \n"
"    /* \345\217\257\351\200\211\357\274\232\345\207\217\345\260\217\350\276\271\346\241\206\345\256\275\345\272\246\357\274\214\345\274\272\345\214\226\347\274\251\345\260\217\346\204\237 */\n"
"    border-width: 1px;\n"
"    \n"
"    /* \345\217\257\351\200\211\357\274\232\345\212\240\346\267\261\350\203\214\346\231\257\350\211\262\357\274\214\346\250\241\346\213\237\342\200\234\345\207\271\351\231\267\342\200\235\346\225\210\346\236\234 */\n"
"    background-color: #15151F;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	border-width:30px;\n"
"	border-color:#1E90FF;\n"
"	padding: 20px;\n"
"	color:#white;\n"
"}\n"
"\n"
"\n"
"\n"
"QTextEdit#dpsktext\n"
"{\n"
"\n"
"	background-color:black;\n"
"	Font-size:15px;\n"
"	color:#00FF00;\n"
"	border-radius:50px;\n"
"\n"
"\n"
"\n"
"\n"
"}\n"
"\n"
"QTextEdit#usertext\n"
"{\n"
"	border-width:15px;\n"
"	border-style:ridge;\n"
"	border-color:#00BFFF;\n"
"	border-radius:30px;\n"
"	background-colo"
                        "r:black;\n"
"	Font-size:15px;\n"
"	color:#00FF00;\n"
"	outline-color:red;\n"
"	outline-width:20px;\n"
"	padding-width:5px;\n"
"	padding-color:#1E90FF;\n"
"\n"
"}\n"
"\n"
"QGroupBox\n"
"{\n"
"	border-width:20px;\n"
"	border-style:ridge;\n"
"	border-color:#8A2BE2;\n"
"	outline-color:red;\n"
"	outline-width:20px;\n"
"	border-radius:50px;\n"
"	background-color:#0A0A0F;\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"{\n"
"	border-width:10px;\n"
"	border-style:solid;\n"
"	border-color:#00BFFF;\n"
"	border-radius:20px;\n"
"\n"
"	background-color:#ffffff;\n"
"}\n"
"\n"
"\n"
"QTextEdit#usertext\n"
"{\n"
"	border-width:10px;\n"
"	border-style:solid;\n"
"	border-color:#00BFFF;\n"
"	border-radius:20px;\n"
"	background-color:#00FF00;\n"
"	Font-size:20px;\n"
"	color:#39FF14;\n"
"	outline-color:red;\n"
"	outline-width:20px;\n"
"	padding-width:5px;\n"
"	padding-color:#1E90FF;\n"
"\n"
"}"));
        verticalLayout = new QVBoxLayout(deepseekTalk);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(deepseekTalk);
        groupBox->setObjectName("groupBox");
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        dpsktext = new QTextEdit(groupBox);
        dpsktext->setObjectName("dpsktext");

        horizontalLayout_2->addWidget(dpsktext);

        horizontalLayout_2->setStretch(0, 2);

        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        usertext = new QTextEdit(groupBox);
        usertext->setObjectName("usertext");

        horizontalLayout->addWidget(usertext);

        send = new QPushButton(groupBox);
        send->setObjectName("send");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(send->sizePolicy().hasHeightForWidth());
        send->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8("C:/Users/phoen/Downloads/\346\217\220\344\272\244.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        send->setIcon(icon);
        send->setIconSize(QSize(100, 100));

        horizontalLayout->addWidget(send);

        horizontalLayout->setStretch(0, 10);

        verticalLayout_3->addLayout(horizontalLayout);

        verticalLayout_3->setStretch(0, 6);
        verticalLayout_3->setStretch(1, 1);

        verticalLayout_4->addLayout(verticalLayout_3);


        verticalLayout->addWidget(groupBox);


        retranslateUi(deepseekTalk);

        QMetaObject::connectSlotsByName(deepseekTalk);
    } // setupUi

    void retranslateUi(QWidget *deepseekTalk)
    {
        deepseekTalk->setWindowTitle(QCoreApplication::translate("deepseekTalk", "Form", nullptr));
        groupBox->setTitle(QString());
        dpsktext->setPlaceholderText(QCoreApplication::translate("deepseekTalk", "\345\260\217\346\235\216\346\255\243\345\234\250\344\270\212\347\272\277\344\270\255\357\274\214\350\257\267\347\250\215\345\220\216\343\200\202\343\200\202\343\200\202", nullptr));
        send->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class deepseekTalk: public Ui_deepseekTalk {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEEPSEEKTALK_H
