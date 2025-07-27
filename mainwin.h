#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVideoWidget>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QVideoSink>
#include "CameraController.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onRefreshCameras();
    void onOpenCamera();
    void onCaptureImage();
    void onStartRecording();
    void onStopRecording();
    void onPauseResume();
    void onResolutionChanged(int index);
    void onImageCaptured(const QString &filePath);
    void onNewVideoFrame(const QImage &frame); // 处理新视频帧

private:
    void setupUI();
    void updateUIState();

    CameraController *m_cameraController;
    QVideoWidget *m_videoWidget;
    QVideoSink *m_videoSink; // Qt 6 视频接收器
    QComboBox *m_cameraCombo;
    QComboBox *m_resolutionCombo;
    QPushButton *m_refreshBtn;
    QPushButton *m_openBtn;
    QPushButton *m_closeBtn;
    QPushButton *m_captureBtn;
    QPushButton *m_recordBtn;
    QPushButton *m_stopRecordBtn;
    QPushButton *m_pauseBtn;
    QLabel *m_statusLabel;
    QLabel *m_capturePreview;
};

#endif // MAINWINDOW_H
