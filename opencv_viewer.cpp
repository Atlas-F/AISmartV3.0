#include "opencv_viewer.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>

// 构造函数：所有UI控件在此初始化
OpenCvViewer::OpenCvViewer(QWidget *parent)
    : QWidget(parent)
{
    // 设置窗口属性
    setWindowTitle("OpenCV 图像查看器");
    setMinimumSize(800, 600);

    // 初始化控件
    imageLabel = new QLabel(this);
    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setText("请打开一张图片");
    imageLabel->setStyleSheet("border: 1px solid #cccccc;");

    openBtn = new QPushButton("打开图片", this);
    processBtn = new QPushButton("处理图片", this);
    processBtn->setEnabled(false); // 初始禁用，打开图片后启用

    // 创建布局
    btnLayout = new QHBoxLayout();
    btnLayout->addWidget(openBtn);
    btnLayout->addWidget(processBtn);
    btnLayout->addStretch();

    mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(btnLayout);
    mainLayout->addWidget(imageLabel);

    // 设置主布局
    setLayout(mainLayout);

    // 连接信号槽
    connect(openBtn, &QPushButton::clicked, this, &OpenCvViewer::onOpenImageClicked);
    connect(processBtn, &QPushButton::clicked, this, &OpenCvViewer::onProcessImageClicked);
}

OpenCvViewer::~OpenCvViewer()
{
    // 动态分配的控件会被父对象自动销毁，无需手动delete
}

// 打开图片
void OpenCvViewer::onOpenImageClicked()
{
    QString filePath = QFileDialog::getOpenFileName(
        this,
        "选择图片",
        "",
        "图片文件 (*.png *.jpg *.jpeg *.bmp *.gif)"
        );

    if (filePath.isEmpty()) {
        return;
    }

    // 读取图片（支持中文路径）
    QByteArray byteArray = filePath.toLocal8Bit();
    const char *path = byteArray.data();
    currentImage = cv::imread(path);

    if (currentImage.empty()) {
        QMessageBox::warning(this, "错误", "无法打开图片！");
        return;
    }

    // 显示原始图片
    QImage qImg = cvMatToQImage(currentImage);
    imageLabel->setPixmap(QPixmap::fromImage(qImg.scaled(
        imageLabel->width(),
        imageLabel->height(),
        Qt::KeepAspectRatio,
        Qt::SmoothTransformation
        )));

    processBtn->setEnabled(true);
}

// 处理图片（转为灰度图示例）
void OpenCvViewer::onProcessImageClicked()
{
    if (currentImage.empty()) {
        return;
    }

    // OpenCV处理：转为灰度图
    cv::Mat grayImage;
    cv::cvtColor(currentImage, grayImage, cv::COLOR_BGR2GRAY);

    // 显示处理后的图片
    QImage qImg = cvMatToQImage(grayImage);
    imageLabel->setPixmap(QPixmap::fromImage(qImg.scaled(
        imageLabel->width(),
        imageLabel->height(),
        Qt::KeepAspectRatio,
        Qt::SmoothTransformation
        )));
}

// OpenCV Mat转QImage（处理色彩空间转换）
QImage OpenCvViewer::cvMatToQImage(const cv::Mat &mat)
{
    // 处理彩色图像
    if (mat.type() == CV_8UC3) {
        cv::Mat rgbMat;
        cv::cvtColor(mat, rgbMat, cv::COLOR_BGR2RGB);
        return QImage(
                   rgbMat.data,
                   rgbMat.cols,
                   rgbMat.rows,
                   static_cast<int>(rgbMat.step),
                   QImage::Format_RGB888
                   ).copy(); // 使用copy确保内存管理安全
    }
    // 处理灰度图像
    else if (mat.type() == CV_8UC1) {
        return QImage(
                   mat.data,
                   mat.cols,
                   mat.rows,
                   static_cast<int>(mat.step),
                   QImage::Format_Grayscale8
                   ).copy();
    }
    // 其他格式暂不支持
    else {
        qWarning() << "不支持的图像格式";
        return QImage();
    }
}
