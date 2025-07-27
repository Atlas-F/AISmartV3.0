// #ifndef ANIMATIONDEMO_H
// #define ANIMATIONDEMO_H

// #include <QWidget>
// #include <QPushButton>
// #include <QLabel>
// #include <QPropertyAnimation>
// #include <QParallelAnimationGroup>
// #include <QSequentialAnimationGroup>
// #include <QGraphicsOpacityEffect>
// #include <QVBoxLayout>
// #include <QHBoxLayout>
// #include <QEasingCurve>
// #include <QTimer>
// #include <QPainterPath>

// #include "transformwidget.h" // 自定义变换控件
// #include "flipwidget.h"     // 自定义翻转控件

// /**
//  * @class AnimationDemo
//  * @brief 主窗口类，展示各种2D动画效果
//  *
//  * 包含滑入滑出、淡入淡出、颜色渐变、弹跳、摇摆、路径、序列和翻转动画
//  */
// class AnimationDemo : public QWidget {
//     Q_OBJECT

// public:
//     explicit AnimationDemo(QWidget *parent = nullptr);

// private slots:
//     // 动画效果槽函数
//     void slideIn();      // 滑入动画
//     void slideOut();     // 滑出动画
//     void fadeIn();       // 淡入动画
//     void fadeOut();      // 淡出动画
//     void colorChange();  // 颜色变化动画
//     void complexAnimation(); // 复杂组合动画
//     void bounceAnimation();  // 弹跳动画
//     void swingAnimation();   // 摇摆动画
//     void pathAnimation();    // 路径动画
//     void sequenceAnimation();// 序列动画
//     void flipAnimation();    // 翻转动画

// private:
//     // 创建UI控件
//     void createWidgets();
//     // 设置布局
//     void setupLayout();
//     // 连接信号槽
//     void connectSignals();

//     // 动画控件
//     QWidget *slideWidget;     // 滑入滑出控件
//     QWidget *fadeWidget;      // 淡入淡出控件
//     QWidget *colorWidget;     // 颜色变化控件
//     TransformWidget *complexWidget; // 复杂组合动画控件
//     TransformWidget *bounceWidget;  // 弹跳动画控件
//     TransformWidget *swingWidget;   // 摇摆动画控件
//     TransformWidget *pathWidget;    // 路径动画控件
//     TransformWidget *sequenceWidget;// 序列动画控件
//     FlipWidget *flipWidget;         // 翻转动画控件

//     // 标签
//     QLabel *slideLabel;
//     QLabel *fadeLabel;
//     QLabel *colorLabel;
//     QLabel *complexLabel;
//     QLabel *bounceLabel;
//     QLabel *swingLabel;
//     QLabel *pathLabel;
//     QLabel *sequenceLabel;

//     // 按钮
//     QPushButton *slideInBtn;
//     QPushButton *slideOutBtn;
//     QPushButton *fadeInBtn;
//     QPushButton *fadeOutBtn;
//     QPushButton *colorBtn;
//     QPushButton *complexBtn;
//     QPushButton *bounceBtn;
//     QPushButton *swingBtn;
//     QPushButton *pathBtn;
//     QPushButton *sequenceBtn;
//     QPushButton *flipBtn;
// };

// #endif // ANIMATIONDEMO_H


#ifndef ANIMATIONDEMO_H
#define ANIMATIONDEMO_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
#include <QGraphicsOpacityEffect>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QEasingCurve>
#include <QTimer>
#include <QPainterPath>
#include <functional>

#include "transformwidget.h" // 自定义变换控件
#include "flipwidget.h"     // 自定义翻转控件

/**
 * @class AnimationDemo
 * @brief 参数化的动画框架基类
 *
 * 提供可配置的动画接口，支持自定义目标对象和动画参数
 */
class AnimationDemo : public QWidget {
    Q_OBJECT

public:

    static AnimationDemo& Animationinstance()
    {
        static AnimationDemo instance;
        return instance;
    }

    explicit AnimationDemo(QWidget *parent = nullptr);
    virtual ~AnimationDemo() = default;



    // ================ 参数化动画接口 ================= //
    using AnimationCallback = std::function<void()>;

public slots:
    // 滑入动画
    void slideAnimation(QWidget *target,
                        const QRect &startRect = QRect(800, 200, 200, 200),
                        const QRect &endRect = QRect(300, 200, 200, 200),
                        int duration = 1000,
                        AnimationCallback callback = nullptr);

    // 淡入淡出动画
    void fadeAnimation(QWidget *target,
                       bool fadeIn,
                       int duration = 1500,
                       AnimationCallback callback = nullptr);

    // 颜色变化动画
    void colorAnimation(QWidget *target,
                        const QString &startStyle = "background-color: #e74c3c; border-radius: 100px;",
                        const QString &endStyle = "background-color: #3498db; border-radius: 100px;",
                        int duration = 2000,
                        AnimationCallback callback = nullptr);

    // 复杂组合动画
    void complexAnimation(TransformWidget *target,
                          qreal startRotation = 0, qreal endRotation = 360,
                          qreal startScale = 1.0, qreal endScale = 1.5,
                          int duration = 2000,
                          AnimationCallback callback = nullptr);

    // 弹跳动画
    void bounceAnimation(QWidget *target,
                         const QPoint &startPos = QPoint(300, 50), const QPoint &endPos = QPoint(300, 400),
                         int fallduration = 800, int bounceUpDuration = 300,
                         const QPoint &bounceUstartPos = QPoint(300, 400), const QPoint &bounceUpendPos = QPoint(300, 300),
                         AnimationCallback callback = nullptr);

    // 摇摆动画
    void swingAnimation(TransformWidget *target,
                        qreal startAngle, qreal endAngle,
                        int duration = 500,
                        AnimationCallback callback = nullptr);

    // 路径动画
    void pathAnimation(QWidget *pathWidget,
                       QPainterPath &path,   // const QPainterPath &path,
                       int duration = 4000,
                       AnimationCallback callback = nullptr);

    // 序列动画
    void sequenceAnimation(QWidget *target,
                           const QVector<QPoint> &points,
                           int duration = 3000,
                           AnimationCallback callback = nullptr);

    // 翻转动画
    void flipAnimation(FlipWidget *target,
                       qreal startAngle = 0, qreal endAngle = 360,
                       const QColor &startColor = QColor("#3498db"), const QColor &endColor = QColor("#e74c3c"),
                       int duration = 1500,
                       AnimationCallback callback = nullptr);

signals:
    // 动画请求信号
    // void slideRequested(QWidget* target, const QPoint& start, const QPoint& end, int duration);


protected:
    // // 创建UI元素（由子类实现）
    // virtual void createWidgets() = 0;

    // // 设置布局（由子类实现）
    // virtual void setupLayout() = 0;

    // // 连接信号槽（由子类实现）
    // virtual void connectSignals() = 0;

    // 动画完成处理
    void handleAnimationFinished(AnimationCallback callback);

public slots:
    // void slideAnimation(QWidget* target, const QPoint& start, const QPoint& end, int duration);
};


class MyAnimationDemo : public AnimationDemo {
public:
    // void createWidgets() override {
    //     // 具体实现
    //     qDebug()<< "void createWidgets()";
    // }

    // void setupLayout() override {
    //     // 具体实现
    //     qDebug()<< "void setupLayout()";
    // }

    // void connectSignals() override {
    //     // 具体实现
    //     qDebug()<< "void connectSignals()";
    // }
};



#endif // ANIMATIONDEMO_H
