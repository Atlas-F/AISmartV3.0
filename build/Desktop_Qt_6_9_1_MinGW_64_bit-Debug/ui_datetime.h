/********************************************************************************
** Form generated from reading UI file 'datetime.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATETIME_H
#define UI_DATETIME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DateTime
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *date;
    QSpacerItem *verticalSpacer_2;
    QLabel *time;
    QSpacerItem *verticalSpacer;
    QLabel *weather;

    void setupUi(QWidget *DateTime)
    {
        if (DateTime->objectName().isEmpty())
            DateTime->setObjectName("DateTime");
        DateTime->resize(866, 765);
        DateTime->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style:ridge;\n"
"	border-color:black;\n"
"	border-width:20px;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(DateTime);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        date = new QLabel(DateTime);
        date->setObjectName("date");
        QFont font;
        font.setPointSize(20);
        date->setFont(font);
        date->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(date);

        verticalSpacer_2 = new QSpacerItem(20, 18, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        time = new QLabel(DateTime);
        time->setObjectName("time");
        time->setFont(font);
        time->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(time);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        weather = new QLabel(DateTime);
        weather->setObjectName("weather");
        weather->setFont(font);
        weather->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(weather);

        verticalLayout->setStretch(0, 3);
        verticalLayout->setStretch(2, 3);
        verticalLayout->setStretch(4, 3);

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(DateTime);

        QMetaObject::connectSlotsByName(DateTime);
    } // setupUi

    void retranslateUi(QWidget *DateTime)
    {
        DateTime->setWindowTitle(QCoreApplication::translate("DateTime", "Form", nullptr));
        date->setText(QCoreApplication::translate("DateTime", "TextLabel", nullptr));
        time->setText(QCoreApplication::translate("DateTime", "TextLabel", nullptr));
        weather->setText(QCoreApplication::translate("DateTime", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DateTime: public Ui_DateTime {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATETIME_H
