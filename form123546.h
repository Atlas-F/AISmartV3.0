#ifndef FORM123546_H
#define FORM123546_H

#include <QWidget>

namespace Ui {
class Form123546;
}

class Form123546 : public QWidget
{
    Q_OBJECT

public:
    explicit Form123546(QWidget *parent = nullptr);
    ~Form123546();

private:
    Ui::Form123546 *ui;
};

#endif // FORM123546_H
