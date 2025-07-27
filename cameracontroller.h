#ifndef CAMERACONTROLLER_H
#define CAMERACONTROLLER_H

#include <QObject>
#include <QCamera>
#include <QCameraDevice>
#include <QMediaDevices>
#include <QImageCapture>
#include <QMediaRecorder>
#include <QMediaCaptureSession>
#include <QMediaFormat>
#include <QVideoSink>
#include <QImage>
#include <QDebug>
#include <memory> // 添加智能指针支持

class CameraController : public QObject
{
    Q_OBJECT

public:
    explicit CameraController(QObject *parent = nullptr);
    ~CameraController();

    // 摄像头操作
    QList<QCameraDevice> getAvailableCameras() const;
    bool openCamera(const QCameraDevice &cameraDevice);
    void closeCamera();
    bool isCameraActive() const;

    // 视频录制
    bool startRecording(const QString &filePath);
    void stopRecording();
    bool isRecording() const;

    // 图像捕获
    void captureImage(const QString &filePath);

    // 播放控制
    void pauseCamera();
    void resumeCamera();
    bool isPaused() const;

    // 设置与获取
    void setVideoOutput(QVideoSink *videoSink);
    QVideoSink *videoSink() const;
    void setResolution(const QSize &resolution);
    QSize currentResolution() const;
    void setFrameRate(int fps);
    int currentFrameRate() const;

    // 状态信息
    QString statusString() const;
    qint64 recordingDuration() const;

signals:
    void cameraOpened();
    void cameraClosed();
    void recordingStarted();
    void recordingStopped();
    void imageCaptured(const QString &filePath);
    void errorOccurred(const QString &errorMessage);
    void newVideoFrame(const QImage &frame);

private:
    void applyCameraSettings();
    void setupConnections();

    // 使用智能指针管理资源
    std::unique_ptr<QMediaCaptureSession> m_captureSession;
    std::unique_ptr<QCamera> m_camera;
    std::unique_ptr<QImageCapture> m_imageCapture;
    std::unique_ptr<QMediaRecorder> m_recorder;

    QVideoSink *m_videoSink = nullptr;
    QSize m_resolution = QSize(1280, 720);
    int m_frameRate = 30;
};

#endif // CAMERACONTROLLER_H
