#ifndef OPENCVTEST_H
#define OPENCVTEST_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class opencvtest; }
QT_END_NAMESPACE

class opencvtest : public QMainWindow
{
    Q_OBJECT

public:
    opencvtest(QWidget *parent = nullptr);
    ~opencvtest();

private slots:
    void on_loadImageBtn_clicked();

private:
    Ui::opencvtest *ui;
    // OpenCV与Qt图像转换函数
    QImage cvMatToQImage(const cv::Mat &mat);
};
#endif // opencvtest_H
