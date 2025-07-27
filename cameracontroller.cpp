#include "CameraController.h"

#include <QUrl>

CameraController::CameraController(QObject *parent)
    : QObject(parent)
{
    // 初始化媒体捕获会话
    m_captureSession = std::make_unique<QMediaCaptureSession>();
}

CameraController::~CameraController()
{
    closeCamera();
}

QList<QCameraDevice> CameraController::getAvailableCameras() const
{
    return QMediaDevices::videoInputs();
}

bool CameraController::openCamera(const QCameraDevice &cameraDevice)
{
    // 关闭当前摄像头（如果已打开）
    closeCamera();

    try {
        // 创建摄像头对象
        m_camera = std::make_unique<QCamera>(cameraDevice);

        // 设置到捕获会话
        m_captureSession->setCamera(m_camera.get());

        // 创建图像捕获对象
        m_imageCapture = std::make_unique<QImageCapture>();
        m_captureSession->setImageCapture(m_imageCapture.get());

        // 创建媒体录制器
        m_recorder = std::make_unique<QMediaRecorder>();
        m_captureSession->setRecorder(m_recorder.get());

        // 设置视频输出
        if (m_videoSink) {
            m_captureSession->setVideoOutput(m_videoSink);
        }

        // 应用摄像头设置
        applyCameraSettings();

        // 设置信号连接
        setupConnections();

        // 启动摄像头
        m_camera->start();

        emit cameraOpened();
        return true;
    } catch (...) {
        emit errorOccurred("无法打开摄像头");
        return false;
    }
}

void CameraController::closeCamera()
{
    if (isRecording()) {
        stopRecording();
    }

    if (m_camera) {
        m_camera->stop();
        m_camera.reset();
    }

    m_imageCapture.reset();
    m_recorder.reset();

    emit cameraClosed();
}

bool CameraController::isCameraActive() const
{
    return m_camera && m_camera->isActive();
}

bool CameraController::startRecording(const QString &filePath)
{
    if (!isCameraActive()) {
        emit errorOccurred("请先打开摄像头");
        return false;
    }

    if (isRecording()) {
        return false;
    }

    try {
        // 设置输出位置
        m_recorder->setOutputLocation(QUrl::fromLocalFile("E:/QTprojects/secondSmartTest/camerafile/video.mp4"));

        // 设置媒体格式
        QMediaFormat format;
        format.setFileFormat(QMediaFormat::MPEG4);
        format.setVideoCodec(QMediaFormat::VideoCodec::H264);
        m_recorder->setMediaFormat(format);

        // 开始录制
        m_recorder->record();

        emit recordingStarted();
        return true;
    } catch (...) {
        emit errorOccurred("无法开始录制");
        return false;
    }
}

void CameraController::stopRecording()
{
    if (m_recorder && m_recorder->recorderState() == QMediaRecorder::RecordingState) {
        m_recorder->stop();
        emit recordingStopped();
    }
}

bool CameraController::isRecording() const
{
    return m_recorder && m_recorder->recorderState() == QMediaRecorder::RecordingState;
}

void CameraController::captureImage(const QString &filePath)
{
    if (!isCameraActive() || !m_imageCapture) {
        emit errorOccurred("请先打开摄像头");
        return;
    }

    // 捕获图像到文件
    m_imageCapture->captureToFile(filePath);
}

void CameraController::pauseCamera()
{
    if (m_camera && m_camera->isActive()) {
        m_camera->stop();
    }
}

void CameraController::resumeCamera()
{
    if (m_camera && !m_camera->isActive()) {
        m_camera->start();
    }
}

bool CameraController::isPaused() const
{
    return m_camera && !m_camera->isActive();
}

void CameraController::setVideoOutput(QVideoSink *videoSink)
{
    m_videoSink = videoSink;
    if (m_captureSession && m_videoSink) {
        m_captureSession->setVideoOutput(m_videoSink);
    }
}

QVideoSink *CameraController::videoSink() const
{
    return m_videoSink;
}

void CameraController::setResolution(const QSize &resolution)
{
    m_resolution = resolution;
    if (isCameraActive()) {
        applyCameraSettings();
    }
}

QSize CameraController::currentResolution() const
{
    return m_resolution;
}

void CameraController::setFrameRate(int fps)
{
    m_frameRate = fps;
    if (isCameraActive()) {
        applyCameraSettings();
    }
}

int CameraController::currentFrameRate() const
{
    return m_frameRate;
}

QString CameraController::statusString() const
{
    if (!isCameraActive()) return "摄像头未打开";
    if (isRecording()) return "录制中...";
    if (isPaused()) return "已暂停";
    return "运行中";
}

qint64 CameraController::recordingDuration() const
{
    return m_recorder ? m_recorder->duration() : 0;
}

void CameraController::applyCameraSettings()
{
    if (!m_camera) return;

    // 获取摄像头支持的所有格式
    const QList<QCameraFormat> formats = m_camera->cameraDevice().videoFormats();

    // 查找匹配的分辨率和帧率
    for (const QCameraFormat &format : formats) {
        if (format.resolution() == m_resolution &&
            format.maxFrameRate() >= m_frameRate) {
            m_camera->setCameraFormat(format);
            return;
        }
    }

    // 如果没有精确匹配，使用最接近的分辨率
    for (const QCameraFormat &format : formats) {
        if (format.resolution().width() == m_resolution.width() ||
            format.resolution().height() == m_resolution.height()) {
            m_camera->setCameraFormat(format);
            m_resolution = format.resolution();
            emit errorOccurred("使用最接近的分辨率: " +
                               QString("%1x%2").arg(m_resolution.width()).arg(m_resolution.height()));
            return;
        }
    }

    // 如果仍然没有匹配，使用第一个可用格式
    if (!formats.isEmpty()) {
        m_camera->setCameraFormat(formats.first());
        m_resolution = formats.first().resolution();
        emit errorOccurred("使用默认分辨率: " +
                           QString("%1x%2").arg(m_resolution.width()).arg(m_resolution.height()));
    }
}

void CameraController::setupConnections()
{
    if (!m_camera || !m_imageCapture) return;

    // 图像捕获完成信号
    connect(m_imageCapture.get(), &QImageCapture::imageSaved,
            this, [this](int id, const QString &fileName) {
                Q_UNUSED(id);
                emit imageCaptured(fileName);
            });

    // 错误处理
    connect(m_camera.get(), &QCamera::errorOccurred, this, [this]() {
        emit errorOccurred(m_camera->errorString());
    });

    if (m_recorder) {
        connect(m_recorder.get(), &QMediaRecorder::errorOccurred, this, [this]() {
            emit errorOccurred(m_recorder->errorString());
        });
    }

    connect(m_imageCapture.get(), &QImageCapture::errorOccurred, this,
            [this](int id, QImageCapture::Error error, const QString &errorString) {
                Q_UNUSED(id);
                Q_UNUSED(error);
                emit errorOccurred(errorString);
            });

    // 连接视频帧信号
    if (m_videoSink) {
        connect(m_videoSink, &QVideoSink::videoFrameChanged, this,
                [this](const QVideoFrame &frame) {
                    // 转换为QImage并发出信号
                    QImage image = frame.toImage();
                    if (!image.isNull()) {
                        emit newVideoFrame(image);
                    }
                });
    }
}
