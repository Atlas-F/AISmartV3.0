/********************************************************************************
** Form generated from reading UI file 'commandbox.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMANDBOX_H
#define UI_COMMANDBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommandBox
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *outputArea;
    QHBoxLayout *horizontalLayout;
    QTextEdit *status;
    QVBoxLayout *verticalLayout;
    QLineEdit *inputField;
    QPushButton *executeButton;
    QLabel *statusLabel;

    void setupUi(QWidget *CommandBox)
    {
        if (CommandBox->objectName().isEmpty())
            CommandBox->setObjectName("CommandBox");
        CommandBox->resize(1025, 780);
        verticalLayout_3 = new QVBoxLayout(CommandBox);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        outputArea = new QTextEdit(CommandBox);
        outputArea->setObjectName("outputArea");
        outputArea->setReadOnly(true);

        verticalLayout_2->addWidget(outputArea);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        status = new QTextEdit(CommandBox);
        status->setObjectName("status");

        horizontalLayout->addWidget(status);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        inputField = new QLineEdit(CommandBox);
        inputField->setObjectName("inputField");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(inputField->sizePolicy().hasHeightForWidth());
        inputField->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(inputField);

        executeButton = new QPushButton(CommandBox);
        executeButton->setObjectName("executeButton");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(executeButton->sizePolicy().hasHeightForWidth());
        executeButton->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(executeButton);

        statusLabel = new QLabel(CommandBox);
        statusLabel->setObjectName("statusLabel");
        sizePolicy.setHeightForWidth(statusLabel->sizePolicy().hasHeightForWidth());
        statusLabel->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(statusLabel);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 2);
        verticalLayout->setStretch(2, 1);

        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout_2->setStretch(0, 3);
        verticalLayout_2->setStretch(1, 1);

        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(CommandBox);

        QMetaObject::connectSlotsByName(CommandBox);
    } // setupUi

    void retranslateUi(QWidget *CommandBox)
    {
        CommandBox->setWindowTitle(QCoreApplication::translate("CommandBox", "Form", nullptr));
        executeButton->setText(QCoreApplication::translate("CommandBox", "\346\211\247\350\241\214", nullptr));
        statusLabel->setText(QCoreApplication::translate("CommandBox", "\345\260\261\347\273\252", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CommandBox: public Ui_CommandBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMANDBOX_H
