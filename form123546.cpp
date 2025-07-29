#include "form123546.h"
#include "ui_form123546.h"

Form123546::Form123546(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form123546)
{
    ui->setupUi(this);
}

Form123546::~Form123546()
{
    delete ui;
}
