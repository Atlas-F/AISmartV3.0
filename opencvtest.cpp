#include "opencvtest.h"
// #include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

opencvtest::opencvtest(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::opencvtest)
{
    // ui->setupUi(this);
}

opencvtest::~opencvtest()
{
    delete ui;
}

// OpenCV的Mat转Qt的QImage
QImage opencvtest::cvMatToQImage(const cv::Mat &mat)
{
    // 处理彩色图像(BGR->RGB)
    if (mat.type() == CV_8UC3) {
        cv::cvtColor(mat, mat, cv::COLOR_BGR2RGB);
        return QImage((const unsigned char*)mat.data,
                      mat.cols, mat.rows,
                      mat.step,
                      QImage::Format_RGB888);
    }
    // 处理灰度图像
    else if (mat.type() == CV_8UC1) {
        return QImage((const unsigned char*)mat.data,
                      mat.cols, mat.rows,
                      mat.step,
                      QImage::Format_Grayscale8);
    }
    return QImage();
}

// 加载图像按钮点击事件
void opencvtest::on_loadImageBtn_clicked()
{
    // 打开文件对话框选择图像
    QString filePath = QFileDialog::getOpenFileName(
        this, "选择图像", "", "图像文件 (*.png *.jpg *.bmp)");

    if (filePath.isEmpty()) return;

    // 使用OpenCV加载图像
    cv::Mat image = cv::imread(filePath.toStdString());
    if (image.empty()) {
        QMessageBox::warning(this, "错误", "无法加载图像!");
        return;
    }

    // 转换为QImage并显示在Qt的Label上
    QImage qImage = cvMatToQImage(image);
    ui->imageLabel->setPixmap(QPixmap::fromImage(qImage.scaled(
        ui->imageLabel->size(), Qt::KeepAspectRatio)));
}
