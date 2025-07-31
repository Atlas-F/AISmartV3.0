#ifndef OPENCV_VIEWER_H
#define OPENCV_VIEWER_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <opencv2/opencv.hpp>

// 避免使用MainWindow类名，改用OpenCvViewer
class OpenCvViewer : public QWidget
{
    Q_OBJECT

public:
    OpenCvViewer(QWidget *parent = nullptr);
    ~OpenCvViewer();

private slots:
    // 打开图片按钮点击事件
    void onOpenImageClicked();
    // 处理图片按钮点击事件
    void onProcessImageClicked();

private:
    // UI控件声明
    QLabel *imageLabel;       // 显示图片的标签
    QPushButton *openBtn;     // 打开图片按钮
    QPushButton *processBtn;  // 处理图片按钮
    QVBoxLayout *mainLayout;  // 主布局
    QHBoxLayout *btnLayout;   // 按钮布局

    // OpenCV图像存储
    cv::Mat currentImage;

    // 辅助函数：转换OpenCV图像到QImage
    QImage cvMatToQImage(const cv::Mat &mat);
};

#endif // OPENCV_VIEWER_H
