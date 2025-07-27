#include "widgettest.h"
#include "ui_widgettest.h"

widgetTest::widgetTest(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::widgetTest)
{
    ui->setupUi(this);
}

widgetTest::~widgetTest()
{
    delete ui;
}
