#include "mainwin.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QFileDialog>
#include <QDateTime>
#include <QMessageBox>
#include <QMediaDevices>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 创建摄像头控制器
    m_cameraController = new CameraController(this);

    setupUI();
    updateUIState();

    // 初始刷新摄像头列表
    onRefreshCameras();
}

MainWindow::~MainWindow()
{
    // 自动调用CameraController的析构函数
}

void MainWindow::setupUI()
{
    setWindowTitle("Qt摄像头控制工具");
    setMinimumSize(800, 600);

    // 中央部件
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // 主布局
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);

    // 左侧控制面板
    QGroupBox *controlGroup = new QGroupBox("摄像头控制");
    QVBoxLayout *controlLayout = new QVBoxLayout(controlGroup);

    // 设备选择
    m_cameraCombo = new QComboBox();
    m_refreshBtn = new QPushButton("刷新设备");

    QHBoxLayout *deviceLayout = new QHBoxLayout();
    deviceLayout->addWidget(m_cameraCombo);
    deviceLayout->addWidget(m_refreshBtn);
    controlLayout->addLayout(deviceLayout);

    // 操作按钮
    m_openBtn = new QPushButton("打开摄像头");
    m_closeBtn = new QPushButton("关闭摄像头");
    m_captureBtn = new QPushButton("截图");
    m_recordBtn = new QPushButton("开始录制");
    m_stopRecordBtn = new QPushButton("停止录制");
    m_pauseBtn = new QPushButton("暂停");

    // 添加到布局
    controlLayout->addWidget(m_openBtn);
    controlLayout->addWidget(m_closeBtn);
    controlLayout->addWidget(m_captureBtn);
    controlLayout->addWidget(m_recordBtn);
    controlLayout->addWidget(m_stopRecordBtn);
    controlLayout->addWidget(m_pauseBtn);

    // 分辨率设置
    m_resolutionCombo = new QComboBox();
    m_resolutionCombo->addItem("640x480");
    m_resolutionCombo->addItem("800x600");
    m_resolutionCombo->addItem("1024x768");
    m_resolutionCombo->addItem("1280x720");
    m_resolutionCombo->addItem("1920x1080");
    m_resolutionCombo->setCurrentIndex(3);

    controlLayout->addWidget(new QLabel("分辨率设置:"));
    controlLayout->addWidget(m_resolutionCombo);

    // 状态信息
    m_statusLabel = new QLabel("就绪");
    controlLayout->addWidget(m_statusLabel);

    // 右侧显示区域
    QGroupBox *displayGroup = new QGroupBox("摄像头画面");
    QVBoxLayout *displayLayout = new QVBoxLayout(displayGroup);

    // 视频显示部件
    m_videoWidget = new QVideoWidget();
    m_videoWidget->setMinimumSize(640, 480);
    displayLayout->addWidget(m_videoWidget);

    // 获取视频接收器并设置到控制器
    m_videoSink = m_videoWidget->videoSink();
    m_cameraController->setVideoOutput(m_videoSink);

    // 截图预览
    m_capturePreview = new QLabel("截图预览区域");
    m_capturePreview->setAlignment(Qt::AlignCenter);
    m_capturePreview->setMinimumSize(320, 240);
    m_capturePreview->setStyleSheet("background-color: #333; color: #ccc; border: 1px solid #555;");
    displayLayout->addWidget(m_capturePreview);

    // 添加到主布局
    mainLayout->addWidget(controlGroup, 1);
    mainLayout->addWidget(displayGroup, 3);

    // 连接信号槽
    connect(m_refreshBtn, &QPushButton::clicked, this, &MainWindow::onRefreshCameras);
    connect(m_openBtn, &QPushButton::clicked, this, &MainWindow::onOpenCamera);
    connect(m_closeBtn, &QPushButton::clicked, this, &MainWindow::onOpenCamera);
    connect(m_captureBtn, &QPushButton::clicked, this, &MainWindow::onCaptureImage);
    connect(m_recordBtn, &QPushButton::clicked, this, &MainWindow::onStartRecording);
    connect(m_stopRecordBtn, &QPushButton::clicked, this, &MainWindow::onStopRecording);
    connect(m_pauseBtn, &QPushButton::clicked, this, &MainWindow::onPauseResume);
    connect(m_resolutionCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onResolutionChanged);

    // 连接摄像头控制器信号
    connect(m_cameraController, &CameraController::imageCaptured,
            this, &MainWindow::onImageCaptured);
    connect(m_cameraController, &CameraController::errorOccurred,
            this, [this](const QString &msg) {
                m_statusLabel->setText(msg);
                QMessageBox::warning(this, "错误", msg);
            });

    // 连接新视频帧信号（可选，用于处理每一帧）
    connect(m_cameraController, &CameraController::newVideoFrame,
            this, &MainWindow::onNewVideoFrame);
}

void MainWindow::onNewVideoFrame(const QImage &frame)
{
    // 这里可以处理每一帧视频数据
    // 例如：实时图像处理、显示帧率等
    // 注意：这个回调在视频线程中执行，不要进行耗时操作
}

// 其他函数保持不变（与之前实现相同）
// ... [省略相同部分] ...



void MainWindow::updateUIState()
{
    bool cameraActive = m_cameraController->isCameraActive();
    bool recording = m_cameraController->isRecording();
    bool paused = m_cameraController->isPaused();

    m_openBtn->setEnabled(!cameraActive);
    m_closeBtn->setEnabled(cameraActive);
    m_captureBtn->setEnabled(cameraActive);
    m_recordBtn->setEnabled(cameraActive && !recording);
    m_stopRecordBtn->setEnabled(recording);
    m_pauseBtn->setText(paused ? "继续" : "暂停");
    m_pauseBtn->setEnabled(cameraActive);

    m_statusLabel->setText(m_cameraController->statusString());
}

void MainWindow::onRefreshCameras()
{
    m_cameraCombo->clear();
    QList<QCameraDevice> cameras = m_cameraController->getAvailableCameras();

    if (cameras.isEmpty()) {
        m_cameraCombo->addItem("未检测到摄像头");
        return;
    }

    for (const QCameraDevice &camera : cameras) {
        m_cameraCombo->addItem(camera.description());
    }
}

void MainWindow::onOpenCamera()
{
    if (m_cameraController->isCameraActive()) {
        m_cameraController->closeCamera();
        updateUIState();
        return;
    }

    int selectedIndex = m_cameraCombo->currentIndex();
    QList<QCameraDevice> cameras = m_cameraController->getAvailableCameras();

    if (selectedIndex < 0 || selectedIndex >= cameras.size()) {
        QMessageBox::warning(this, "错误", "请选择有效的摄像头");
        return;
    }

    if (m_cameraController->openCamera(cameras.at(selectedIndex))) {
        updateUIState();
    }
}

void MainWindow::onCaptureImage()
{
    QString fileName = QFileDialog::getSaveFileName(
        this, "保存截图",
        QDir::homePath() + "/capture_" + QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss") + ".jpg",
        "Images (*.jpg *.png)");

    if (!fileName.isEmpty()) {
        m_cameraController->captureImage(fileName);
    }
}

void MainWindow::onStartRecording()
{
    QString fileName = QFileDialog::getSaveFileName(
        this, "保存视频",
        QDir::homePath() + "/video_" + QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss") + ".mp4",
        "Videos (*.mp4 *.avi)");

    if (!fileName.isEmpty()) {
        if (m_cameraController->startRecording(fileName)) {
            updateUIState();
        }
    }
}

void MainWindow::onStopRecording()
{
    m_cameraController->stopRecording();
    updateUIState();
}

void MainWindow::onPauseResume()
{
    if (m_cameraController->isPaused()) {
        m_cameraController->resumeCamera();
    } else {
        m_cameraController->pauseCamera();
    }
    updateUIState();
}

void MainWindow::onResolutionChanged(int index)
{
    QString res = m_resolutionCombo->itemText(index);
    QStringList parts = res.split('x');
    if (parts.size() == 2) {
        QSize resolution(parts[0].toInt(), parts[1].toInt());
        m_cameraController->setResolution(resolution);
    }
}

void MainWindow::onImageCaptured(const QString &filePath)
{
    QPixmap pixmap(filePath);
    if (!pixmap.isNull()) {
        m_capturePreview->setPixmap(pixmap.scaled(m_capturePreview->size(), Qt::KeepAspectRatio));
        m_statusLabel->setText("截图已保存: " + filePath);
    }
}
