// #include "animationdemo.h"
// #include <QTimer>
// #include <QPainterPath>

// /**
//  * @brief 构造函数
//  * @param parent 父控件
//  *
//  * 初始化UI并设置初始状态
//  */
// AnimationDemo::AnimationDemo(QWidget *parent) : QWidget(parent) {
//     // 设置窗口属性
//     setFixedSize(800, 700); // 固定窗口大小
//     setWindowTitle("Qt 2D动画效果演示"); // 窗口标题
//     setStyleSheet("background-color: #2c3e50; color: white; font-size: 14px;"); // 样式

//     // 创建UI元素
//     createWidgets();
//     setupLayout();
//     connectSignals();

//     // 初始状态：滑入控件在窗口外
//     slideWidget->setGeometry(800, 200, 200, 200);
// }

// // ================== 动画效果实现 ================== //

// /**
//  * @brief 滑入动画
//  *
//  * 控件从右侧滑入到指定位置
//  */
// void AnimationDemo::slideIn() {
//     QPropertyAnimation *animation = new QPropertyAnimation(slideWidget, "geometry");
//     animation->setDuration(1000); // 动画时长1秒
//     animation->setStartValue(QRect(800, 200, 200, 200)); // 起始位置（窗口外右侧）
//     animation->setEndValue(QRect(300, 200, 200, 200)); // 结束位置（窗口内）
//     animation->setEasingCurve(QEasingCurve::OutBack); // 使用回弹效果
//     animation->start(); // 启动动画
// }

// /**
//  * @brief 滑出动画
//  *
//  * 控件滑出到左侧窗口外
//  */
// void AnimationDemo::slideOut() {
//     QPropertyAnimation *animation = new QPropertyAnimation(slideWidget, "geometry");
//     animation->setDuration(1000); // 动画时长1秒
//     animation->setStartValue(slideWidget->geometry()); // 从当前位置开始
//     animation->setEndValue(QRect(-300, 200, 200, 200)); // 结束位置（窗口外左侧）
//     animation->setEasingCurve(QEasingCurve::InBack); // 使用回弹效果
//     animation->start(); // 启动动画
// }

// /**
//  * @brief 淡入动画
//  *
//  * 控件从完全透明变为完全不透明
//  */
// void AnimationDemo::fadeIn() {
//     // 创建透明度效果
//     QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect(fadeWidget);
//     fadeWidget->setGraphicsEffect(opacityEffect); // 应用到控件

//     // 创建透明度动画
//     QPropertyAnimation *animation = new QPropertyAnimation(opacityEffect, "opacity");
//     animation->setDuration(1500); // 动画时长1.5秒
//     animation->setStartValue(0.0); // 完全透明
//     animation->setEndValue(1.0);   // 完全不透明
//     animation->start(); // 启动动画
// }

// /**
//  * @brief 淡出动画
//  *
//  * 控件从完全不透明变为完全透明
//  */
// void AnimationDemo::fadeOut() {
//     // 创建透明度效果
//     QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect(fadeWidget);
//     fadeWidget->setGraphicsEffect(opacityEffect); // 应用到控件

//     // 创建透明度动画
//     QPropertyAnimation *animation = new QPropertyAnimation(opacityEffect, "opacity");
//     animation->setDuration(1500); // 动画时长1.5秒
//     animation->setStartValue(1.0); // 完全不透明
//     animation->setEndValue(0.0);   // 完全透明
//     animation->start(); // 启动动画
// }

// /**
//  * @brief 颜色变化动画
//  *
//  * 控件背景色从红色渐变到蓝色
//  */
// void AnimationDemo::colorChange() {
//     QPropertyAnimation *animation = new QPropertyAnimation(colorWidget, "styleSheet");
//     animation->setDuration(2000); // 动画时长2秒
//     animation->setStartValue("background-color: #e74c3c; border-radius: 100px;"); // 红色
//     animation->setEndValue("background-color: #3498db; border-radius: 100px;");   // 蓝色
//     animation->start(); // 启动动画
// }

// /**
//  * @brief 复杂组合动画
//  *
//  * 同时进行旋转和缩放动画
//  */
// void AnimationDemo::complexAnimation() {
//     // 创建动画组（并行执行）
//     QParallelAnimationGroup *group = new QParallelAnimationGroup(this);

//     // 旋转动画
//     QPropertyAnimation *rotate = new QPropertyAnimation(complexWidget, "rotation");
//     rotate->setDuration(2000); // 时长2秒
//     rotate->setStartValue(0);  // 起始角度0度
//     rotate->setEndValue(360);  // 结束角度360度
//     rotate->setEasingCurve(QEasingCurve::InOutQuad); // 缓动曲线

//     // 缩放动画
//     QPropertyAnimation *scale = new QPropertyAnimation(complexWidget, "scale");
//     scale->setDuration(2000); // 时长2秒
//     scale->setStartValue(1.0); // 原始大小
//     scale->setEndValue(1.5);   // 放大1.5倍
//     scale->setEasingCurve(QEasingCurve::InOutQuad); // 缓动曲线

//     // 添加到动画组
//     group->addAnimation(rotate);
//     group->addAnimation(scale);

//     // 启动动画
//     group->start();

//     // 动画完成后恢复原始大小
//     QTimer::singleShot(2000, this, [this]() {
//         QPropertyAnimation *scaleBack = new QPropertyAnimation(complexWidget, "scale");
//         scaleBack->setDuration(1000); // 时长1秒
//         scaleBack->setStartValue(1.5); // 当前大小
//         scaleBack->setEndValue(1.0);   // 恢复原始大小
//         scaleBack->start();
//     });
// }

// /**
//  * @brief 弹跳动画
//  *
//  * 模拟物体弹跳效果
//  */
// void AnimationDemo::bounceAnimation() {
//     // 创建动画组（顺序执行）
//     QSequentialAnimationGroup *bounceGroup = new QSequentialAnimationGroup(this);

//     // 下落动画
//     QPropertyAnimation *fall = new QPropertyAnimation(bounceWidget, "pos");
//     fall->setDuration(800); // 时长0.8秒
//     fall->setStartValue(QPoint(300, 50)); // 起始位置（顶部）
//     fall->setEndValue(QPoint(300, 400));  // 结束位置（底部）
//     fall->setEasingCurve(QEasingCurve::OutBounce); // 弹跳效果

//     // 弹起动画
//     QPropertyAnimation *bounceUp = new QPropertyAnimation(bounceWidget, "pos");
//     bounceUp->setDuration(300); // 时长0.3秒
//     bounceUp->setStartValue(QPoint(300, 400)); // 从底部开始
//     bounceUp->setEndValue(QPoint(300, 300));   // 弹起到中间

//     // 再次下落
//     QPropertyAnimation *bounceDown = new QPropertyAnimation(bounceWidget, "pos");
//     bounceDown->setDuration(300); // 时长0.3秒
//     bounceDown->setStartValue(QPoint(300, 300)); // 从中间开始
//     bounceDown->setEndValue(QPoint(300, 400));   // 落回底部

//     // 添加到动画组
//     bounceGroup->addAnimation(fall);
//     bounceGroup->addAnimation(bounceUp);
//     bounceGroup->addAnimation(bounceDown);

//     // 启动动画
//     bounceGroup->start();

//     // 动画结束后恢复原位
//     connect(bounceGroup, &QSequentialAnimationGroup::finished, [=]() {
//         bounceWidget->move(300, 50);
//     });
// }

// /**
//  * @brief 摇摆动画
//  *
//  * 模拟钟摆摇摆效果
//  */
// void AnimationDemo::swingAnimation() {
//     // 创建动画组（顺序执行）
//     QSequentialAnimationGroup *swingGroup = new QSequentialAnimationGroup(this);

//     // 左摇动画
//     QPropertyAnimation *swingLeft = new QPropertyAnimation(swingWidget, "rotation");
//     swingLeft->setDuration(500); // 时长0.5秒
//     swingLeft->setStartValue(0);  // 起始角度0度
//     swingLeft->setEndValue(-20);  // 左摇20度

//     // 右摇动画
//     QPropertyAnimation *swingRight = new QPropertyAnimation(swingWidget, "rotation");
//     swingRight->setDuration(500); // 时长0.5秒
//     swingRight->setStartValue(-20); // 从左摇位置开始
//     swingRight->setEndValue(20);    // 右摇20度

//     // 回中动画
//     QPropertyAnimation *swingCenter = new QPropertyAnimation(swingWidget, "rotation");
//     swingCenter->setDuration(500); // 时长0.5秒
//     swingCenter->setStartValue(20);  // 从右摇位置开始
//     swingCenter->setEndValue(0);     // 回到中心

//     // 添加到动画组
//     swingGroup->addAnimation(swingLeft);
//     swingGroup->addAnimation(swingRight);
//     swingGroup->addAnimation(swingCenter);

//     // 启动动画
//     swingGroup->start();
// }

// /**
//  * @brief 路径动画
//  *
//  * 控件沿自定义路径移动
//  */
// void AnimationDemo::pathAnimation() {
//     // 创建路径
//     QPainterPath path;
//     path.moveTo(50, 400); // 起点
//     path.cubicTo(150, 300, 250, 500, 350, 400); // 贝塞尔曲线
//     path.lineTo(550, 400); // 直线
//     path.arcTo(450, 300, 200, 200, 0, 180); // 半圆

//     // 创建路径动画
//     QPropertyAnimation *pathAnim = new QPropertyAnimation(pathWidget, "pos");
//     pathAnim->setDuration(4000); // 时长4秒
//     pathAnim->setEasingCurve(QEasingCurve::InOutQuad); // 缓动曲线

//     // 设置路径关键帧
//     for (int i = 0; i <= 100; i++) {
//         qreal percent = i / 100.0; // 路径百分比
//         QPointF point = path.pointAtPercent(percent); // 路径上的点
//         pathAnim->setKeyValueAt(percent, point.toPoint()); // 设置关键帧
//     }

//     // 启动动画
//     pathAnim->start();

//     // 动画结束后恢复原位
//     connect(pathAnim, &QPropertyAnimation::finished, [=]() {
//         pathWidget->move(50, 400);
//     });
// }

// /**
//  * @brief 序列动画
//  *
//  * 控件按顺序执行多个移动动画
//  */
// void AnimationDemo::sequenceAnimation() {
//     // 创建动画组（顺序执行）
//     QSequentialAnimationGroup *sequenceGroup = new QSequentialAnimationGroup(this);

//     // 右移动画
//     QPropertyAnimation *moveRight = new QPropertyAnimation(sequenceWidget, "pos");
//     moveRight->setDuration(1000); // 时长1秒
//     moveRight->setStartValue(QPoint(50, 400)); // 起始位置
//     moveRight->setEndValue(QPoint(350, 400));  // 右侧位置
//     moveRight->setEasingCurve(QEasingCurve::OutQuad); // 缓动曲线

//     // 上移动画
//     QPropertyAnimation *moveUp = new QPropertyAnimation(sequenceWidget, "pos");
//     moveUp->setDuration(800); // 时长0.8秒
//     moveUp->setStartValue(QPoint(350, 400)); // 右侧位置
//     moveUp->setEndValue(QPoint(350, 200));   // 上方位置
//     moveUp->setEasingCurve(QEasingCurve::OutBack); // 回弹效果

//     // 左移动画
//     QPropertyAnimation *moveLeft = new QPropertyAnimation(sequenceWidget, "pos");
//     moveLeft->setDuration(1000); // 时长1秒
//     moveLeft->setStartValue(QPoint(350, 200)); // 上方位置
//     moveLeft->setEndValue(QPoint(150, 200));   // 左侧位置
//     moveLeft->setEasingCurve(QEasingCurve::InOutQuad); // 缓动曲线

//     // 下移动画
//     QPropertyAnimation *moveDown = new QPropertyAnimation(sequenceWidget, "pos");
//     moveDown->setDuration(800); // 时长0.8秒
//     moveDown->setStartValue(QPoint(150, 200)); // 左侧位置
//     moveDown->setEndValue(QPoint(150, 400));   // 下方位置
//     moveDown->setEasingCurve(QEasingCurve::InBack); // 回弹效果

//     // 添加到动画组
//     sequenceGroup->addAnimation(moveRight);
//     sequenceGroup->addAnimation(moveUp);
//     sequenceGroup->addAnimation(moveLeft);
//     sequenceGroup->addAnimation(moveDown);

//     // 启动动画
//     sequenceGroup->start();

//     // 动画结束后恢复原位
//     connect(sequenceGroup, &QSequentialAnimationGroup::finished, [=]() {
//         sequenceWidget->move(50, 400);
//     });
// }

// /**
//  * @brief 翻转动画
//  *
//  * 3D卡片翻转效果，同时改变颜色
//  */
// void AnimationDemo::flipAnimation() {
//     // 创建翻转动画
//     QPropertyAnimation *flipAnim = new QPropertyAnimation(flipWidget, "flipAngle");
//     flipAnim->setDuration(1500); // 时长1.5秒
//     flipAnim->setStartValue(0);   // 起始角度0度
//     flipAnim->setEndValue(360);   // 结束角度360度
//     flipAnim->setEasingCurve(QEasingCurve::InOutQuad); // 缓动曲线

//     // 创建颜色变化动画
//     QPropertyAnimation *colorAnim = new QPropertyAnimation(flipWidget, "flipColor");
//     colorAnim->setDuration(1500); // 时长1.5秒
//     colorAnim->setStartValue(QColor("#3498db")); // 起始颜色（蓝色）
//     colorAnim->setEndValue(QColor("#e74c3c"));   // 结束颜色（红色）

//     // 创建并行动画组
//     QParallelAnimationGroup *group = new QParallelAnimationGroup(this);
//     group->addAnimation(flipAnim);
//     group->addAnimation(colorAnim);

//     // 启动动画
//     group->start();
// }

// // ================== UI创建和布局 ================== //

// /**
//  * @brief 创建UI控件
//  */
// void AnimationDemo::createWidgets() {
//     // 滑入滑出控件
//     slideWidget = new QWidget(this);
//     slideWidget->setStyleSheet("background-color: #9b59b6; border-radius: 20px;");
//     slideLabel = new QLabel("滑入滑出动画", slideWidget);
//     slideLabel->setAlignment(Qt::AlignCenter);
//     slideLabel->setGeometry(10, 80, 180, 40);

//     slideInBtn = new QPushButton("滑入", this);
//     slideOutBtn = new QPushButton("滑出", this);
//     slideInBtn->setStyleSheet("background-color: #27ae60; color: white; border: none; padding: 10px;");
//     slideOutBtn->setStyleSheet("background-color: #c0392b; color: white; border: none; padding: 10px;");

//     // 淡入淡出控件
//     fadeWidget = new QWidget(this);
//     fadeWidget->setGeometry(300, 50, 200, 100);
//     fadeWidget->setStyleSheet("background-color: #e67e22; border-radius: 10px;");
//     fadeLabel = new QLabel("淡入淡出动画", fadeWidget);
//     fadeLabel->setAlignment(Qt::AlignCenter);
//     fadeLabel->setGeometry(10, 30, 180, 40);

//     fadeInBtn = new QPushButton("淡入", this);
//     fadeOutBtn = new QPushButton("淡出", this);
//     fadeInBtn->setStyleSheet("background-color: #27ae60; color: white; border: none; padding: 10px;");
//     fadeOutBtn->setStyleSheet("background-color: #c0392b; color: white; border: none; padding: 10px;");

//     // 颜色变化控件
//     colorWidget = new QWidget(this);
//     colorWidget->setGeometry(550, 50, 200, 100);
//     colorWidget->setStyleSheet("background-color: #e74c3c; border-radius: 100px;");
//     colorLabel = new QLabel("颜色变化动画", colorWidget);
//     colorLabel->setAlignment(Qt::AlignCenter);
//     colorLabel->setGeometry(10, 30, 180, 40);

//     colorBtn = new QPushButton("颜色变化", this);
//     colorBtn->setStyleSheet("background-color: #2980b9; color: white; border: none; padding: 10px;");

//     // 复杂组合动画控件
//     complexWidget = new TransformWidget(this);
//     complexWidget->setGeometry(300, 400, 200, 100);
//     complexWidget->setStyleSheet("background-color: #1abc9c; border-radius: 10px;");
//     complexLabel = new QLabel("复杂组合动画", complexWidget);
//     complexLabel->setAlignment(Qt::AlignCenter);
//     complexLabel->setGeometry(10, 30, 180, 40);

//     complexBtn = new QPushButton("组合动画", this);
//     complexBtn->setStyleSheet("background-color: #f39c12; color: white; border: none; padding: 10px;");

//     // 弹跳动画控件
//     bounceWidget = new TransformWidget(this);
//     bounceWidget->setGeometry(300, 50, 100, 100);
//     bounceWidget->setStyleSheet("background-color: #9b59b6; border-radius: 50px;");
//     bounceLabel = new QLabel("弹跳", bounceWidget);
//     bounceLabel->setAlignment(Qt::AlignCenter);
//     bounceLabel->setGeometry(10, 35, 80, 30);

//     bounceBtn = new QPushButton("弹跳动画", this);
//     bounceBtn->setStyleSheet("background-color: #8e44ad; color: white; border: none; padding: 10px;");

//     // 摇摆动画控件
//     swingWidget = new TransformWidget(this);
//     swingWidget->setGeometry(500, 200, 100, 100);
//     swingWidget->setStyleSheet("background-color: #1abc9c; border-radius: 10px;");
//     swingLabel = new QLabel("摇摆", swingWidget);
//     swingLabel->setAlignment(Qt::AlignCenter);
//     swingLabel->setGeometry(10, 35, 80, 30);

//     swingBtn = new QPushButton("摇摆动画", this);
//     swingBtn->setStyleSheet("background-color: #16a085; color: white; border: none; padding: 10px;");

//     // 路径动画控件
//     pathWidget = new TransformWidget(this);
//     pathWidget->setGeometry(50, 400, 50, 50);
//     pathWidget->setStyleSheet("background-color: #e74c3c; border-radius: 25px;");
//     pathLabel = new QLabel("路径", pathWidget);
//     pathLabel->setAlignment(Qt::AlignCenter);
//     pathLabel->setGeometry(5, 12, 40, 25);

//     pathBtn = new QPushButton("路径动画", this);
//     pathBtn->setStyleSheet("background-color: #c0392b; color: white; border: none; padding: 10px;");

//     // 序列动画控件
//     sequenceWidget = new TransformWidget(this);
//     sequenceWidget->setGeometry(50, 400, 50, 50);
//     sequenceWidget->setStyleSheet("background-color: #f39c12; border-radius: 25px;");
//     sequenceLabel = new QLabel("序列", sequenceWidget);
//     sequenceLabel->setAlignment(Qt::AlignCenter);
//     sequenceLabel->setGeometry(5, 12, 40, 25);

//     sequenceBtn = new QPushButton("序列动画", this);
//     sequenceBtn->setStyleSheet("background-color: #d35400; color: white; border: none; padding: 10px;");

//     // 翻转动画控件
//     flipWidget = new FlipWidget(this);
//     flipWidget->setGeometry(200, 200, 200, 100);
//     flipBtn = new QPushButton("翻转动画", this);
//     flipBtn->setStyleSheet("background-color: #2980b9; color: white; border: none; padding: 10px;");
// }

// /**
//  * @brief 设置布局
//  */
// void AnimationDemo::setupLayout() {
//     QVBoxLayout *mainLayout = new QVBoxLayout(this);
//     mainLayout->setSpacing(15); // 控件间距

//     // 第一行：滑入滑出和淡入淡出
//     QHBoxLayout *row1Layout = new QHBoxLayout();
//     row1Layout->addWidget(slideInBtn);
//     row1Layout->addWidget(slideOutBtn);
//     row1Layout->addWidget(fadeInBtn);
//     row1Layout->addWidget(fadeOutBtn);
//     row1Layout->addStretch(); // 添加拉伸空间

//     // 第二行：颜色变化和组合动画
//     QHBoxLayout *row2Layout = new QHBoxLayout();
//     row2Layout->addWidget(colorBtn);
//     row2Layout->addWidget(complexBtn);
//     row2Layout->addStretch();

//     // 第三行：弹跳、摇摆和翻转
//     QHBoxLayout *row3Layout = new QHBoxLayout();
//     row3Layout->addWidget(bounceBtn);
//     row3Layout->addWidget(swingBtn);
//     row3Layout->addWidget(flipBtn);
//     row3Layout->addStretch();

//     // 第四行：路径和序列动画
//     QHBoxLayout *row4Layout = new QHBoxLayout();
//     row4Layout->addWidget(pathBtn);
//     row4Layout->addWidget(sequenceBtn);
//     row4Layout->addStretch();

//     // 添加到主布局
//     mainLayout->addLayout(row1Layout);
//     mainLayout->addLayout(row2Layout);
//     mainLayout->addLayout(row3Layout);
//     mainLayout->addLayout(row4Layout);
//     mainLayout->addStretch(); // 底部拉伸

//     setLayout(mainLayout);
// }

// /**
//  * @brief 连接信号槽
//  */
// void AnimationDemo::connectSignals() {
//     // 连接按钮点击信号到对应的动画槽函数
//     connect(slideInBtn, &QPushButton::clicked, this, &AnimationDemo::slideIn);
//     connect(slideOutBtn, &QPushButton::clicked, this, &AnimationDemo::slideOut);
//     connect(fadeInBtn, &QPushButton::clicked, this, &AnimationDemo::fadeIn);
//     connect(fadeOutBtn, &QPushButton::clicked, this, &AnimationDemo::fadeOut);
//     connect(colorBtn, &QPushButton::clicked, this, &AnimationDemo::colorChange);
//     connect(complexBtn, &QPushButton::clicked, this, &AnimationDemo::complexAnimation);
//     connect(bounceBtn, &QPushButton::clicked, this, &AnimationDemo::bounceAnimation);
//     connect(swingBtn, &QPushButton::clicked, this, &AnimationDemo::swingAnimation);
//     connect(pathBtn, &QPushButton::clicked, this, &AnimationDemo::pathAnimation);
//     connect(sequenceBtn, &QPushButton::clicked, this, &AnimationDemo::sequenceAnimation);
//     connect(flipBtn, &QPushButton::clicked, this, &AnimationDemo::flipAnimation);
// }


#include "animationdemo.h"
#include <QTimer>
#include <QPainterPath>

AnimationDemo::AnimationDemo(QWidget *parent) : QWidget(parent) {

    // Q_OBJECT;
    // 基础设置
    setMinimumSize(800, 600);
    setWindowTitle("参数化动画框架");

    // connect(this, &AnimationDemo::slideRequested,
    //         this, &AnimationDemo::slideAnimation);
}


// ================== 参数化动画实现 ================== //

void AnimationDemo::slideAnimation(QWidget *target,
                                   const QRect &startRect,
                                   const QRect &endRect,
                                   int duration,
                                   AnimationCallback callback) {
    if (!target) return;

    QPropertyAnimation *animation = new QPropertyAnimation(target, "geometry");
    animation->setDuration(duration);
    animation->setStartValue(startRect);
    animation->setEndValue(endRect);
    animation->setEasingCurve(QEasingCurve::OutBack);

    connect(animation, &QPropertyAnimation::finished, [=]() {
        handleAnimationFinished(callback);
        animation->deleteLater();
    });

    animation->start();
}



void AnimationDemo::fadeAnimation(QWidget *target,
                                  bool fadeIn,
                                  int duration,
                                  AnimationCallback callback) {
    if (!target) return;

    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(target);
    target->setGraphicsEffect(effect);

    QPropertyAnimation *animation = new QPropertyAnimation(effect, "opacity");
    animation->setDuration(duration);
    animation->setStartValue(fadeIn ? 0.0 : 1.0);
    animation->setEndValue(fadeIn ? 1.0 : 0.0);

    connect(animation, &QPropertyAnimation::finished, [=]() {
        handleAnimationFinished(callback);
        animation->deleteLater();
        effect->deleteLater();
    });

    animation->start();
}

void AnimationDemo::colorAnimation(QWidget *target,
                                   const QString &startStyle,
                                   const QString &endStyle,
                                   int duration,
                                   AnimationCallback callback) {
    if (!target) return;

    // 设置初始样式
    target->setStyleSheet(startStyle);

    QPropertyAnimation *animation = new QPropertyAnimation(target, "styleSheet");
    animation->setDuration(duration);
    animation->setStartValue(startStyle);
    animation->setEndValue(endStyle);

    connect(animation, &QPropertyAnimation::finished, [=]() {
        handleAnimationFinished(callback);
        animation->deleteLater();
    });

    animation->start();
}

void AnimationDemo::complexAnimation(TransformWidget *target,
                                     qreal startRotation, qreal endRotation,
                                     qreal startScale, qreal endScale,
                                     int duration,
                                     AnimationCallback callback) {
    if (!target) return;

    QParallelAnimationGroup *group = new QParallelAnimationGroup(this);

    // 旋转动画
    QPropertyAnimation *rotateAnim = new QPropertyAnimation(target, "rotation");
    rotateAnim->setDuration(duration);
    rotateAnim->setStartValue(startRotation);
    rotateAnim->setEndValue(endRotation);

    // 缩放动画
    QPropertyAnimation *scaleAnim = new QPropertyAnimation(target, "scale");
    scaleAnim->setDuration(duration);
    scaleAnim->setStartValue(startScale);
    scaleAnim->setEndValue(endScale);

    group->addAnimation(rotateAnim);
    group->addAnimation(scaleAnim);

    connect(group, &QAnimationGroup::finished, [=]() {
        handleAnimationFinished(callback);
        group->deleteLater();
    });

    group->start();
}

/**
 * @brief 弹跳动画
 *
 * 模拟物体弹跳效果
 */
void AnimationDemo::bounceAnimation(QWidget *bounceWidget,
                                    const QPoint &startPos , const QPoint &endPos ,
                                    int fallduration , int bounceUpDuration ,
                                    const QPoint &bounceUstartPos , const QPoint &bounceUpendPos ,
                                    AnimationCallback callback ) {
    // 创建动画组（顺序执行）
    QSequentialAnimationGroup *bounceGroup = new QSequentialAnimationGroup(this);

    // 下落动画
    QPropertyAnimation *fall = new QPropertyAnimation(bounceWidget, "pos");
    fall->setDuration(fallduration); // 时长0.8秒
    fall->setStartValue(startPos); // 起始位置（顶部）
    fall->setEndValue(endPos);  // 结束位置（底部）
    fall->setEasingCurve(QEasingCurve::OutBounce); // 弹跳效果

    // 弹起动画
    QPropertyAnimation *bounceUp = new QPropertyAnimation(bounceWidget, "pos");
    bounceUp->setDuration(bounceUpDuration); // 时长0.3秒
    bounceUp->setStartValue(bounceUstartPos); // 从底部开始
    bounceUp->setEndValue(bounceUpendPos);   // 弹起到中间

    // 再次下落
    QPropertyAnimation *bounceDown = new QPropertyAnimation(bounceWidget, "pos");
    bounceDown->setDuration(bounceUpDuration); // 时长0.3秒
    bounceDown->setStartValue(bounceUpendPos); // 从中间开始
    bounceDown->setEndValue(bounceUstartPos);   // 落回底部

    // 添加到动画组
    bounceGroup->addAnimation(fall);
    bounceGroup->addAnimation(bounceUp);
    bounceGroup->addAnimation(bounceDown);

    // 启动动画
    bounceGroup->start();

    // 动画结束后恢复原位
    connect(bounceGroup, &QSequentialAnimationGroup::finished, [=]() {
        bounceWidget->move(300, 50);
    });
}



/**
 * @brief 摇摆动画
 *
 * 模拟钟摆摇摆效果
 */
void AnimationDemo::swingAnimation(TransformWidget *swingWidget,
                                   qreal startAngle, qreal endAngle,
                                   int duration ,
                                   AnimationCallback callback ) {
    // 创建动画组（顺序执行）
    QSequentialAnimationGroup *swingGroup = new QSequentialAnimationGroup(this);

    // 左摇动画
    QPropertyAnimation *swingLeft = new QPropertyAnimation(swingWidget, "rotation");
    swingLeft->setDuration(duration); // 时长0.5秒
    swingLeft->setStartValue(0);  // 起始角度0度
    swingLeft->setEndValue(startAngle);  // 左摇20度

    // 右摇动画
    QPropertyAnimation *swingRight = new QPropertyAnimation(swingWidget, "rotation");
    swingRight->setDuration(duration); // 时长0.5秒
    swingRight->setStartValue(startAngle); // 从左摇位置开始
    swingRight->setEndValue(endAngle);    // 右摇20度

    // 回中动画
    QPropertyAnimation *swingCenter = new QPropertyAnimation(swingWidget, "rotation");
    swingCenter->setDuration(duration); // 时长0.5秒
    swingCenter->setStartValue(endAngle);  // 从右摇位置开始
    swingCenter->setEndValue(0);     // 回到中心

    // 添加到动画组
    swingGroup->addAnimation(swingLeft);
    swingGroup->addAnimation(swingRight);
    swingGroup->addAnimation(swingCenter);

    // 启动动画
    swingGroup->start();
}



/**
 * @brief 路径动画
 *
 * 控件沿自定义路径移动
 */
void AnimationDemo::pathAnimation(QWidget *pathWidget,
                                  QPainterPath &path,   // const QPainterPath &path,
                                  int duration ,
                                  AnimationCallback callback ) {
    // 创建路径
    path;
    path.moveTo(50, 400); // 起点
    path.cubicTo(150, 300, 250, 500, 350, 400); // 贝塞尔曲线
    path.lineTo(550, 400); // 直线
    path.arcTo(450, 300, 200, 200, 0, 180); // 半圆

    // 创建路径动画
    QPropertyAnimation *pathAnim = new QPropertyAnimation(pathWidget, "pos");
    pathAnim->setDuration(4000); // 时长4秒
    pathAnim->setEasingCurve(QEasingCurve::InOutQuad); // 缓动曲线

    // 设置路径关键帧
    for (int i = 0; i <= 100; i++) {
        qreal percent = i / 100.0; // 路径百分比
        QPointF point = path.pointAtPercent(percent); // 路径上的点
        pathAnim->setKeyValueAt(percent, point.toPoint()); // 设置关键帧
    }

    // 启动动画
    pathAnim->start();

    // 动画结束后恢复原位
    connect(pathAnim, &QPropertyAnimation::finished, [=]() {
        pathWidget->move(50, 400);
    });
}



/**
 * @brief 序列动画
 *
 * 控件按顺序执行多个移动动画
 */
void AnimationDemo::sequenceAnimation(QWidget *sequenceWidget,
                                      const QVector<QPoint> &points,
                                      int duration ,
                                      AnimationCallback callback ) {
    // 创建动画组（顺序执行）
    QSequentialAnimationGroup *sequenceGroup = new QSequentialAnimationGroup(this);

    // 右移动画
    QPropertyAnimation *moveRight = new QPropertyAnimation(sequenceWidget, "pos");
    moveRight->setDuration(1000); // 时长1秒
    moveRight->setStartValue(QPoint(50, 400)); // 起始位置
    moveRight->setEndValue(QPoint(350, 400));  // 右侧位置
    moveRight->setEasingCurve(QEasingCurve::OutQuad); // 缓动曲线

    // 上移动画
    QPropertyAnimation *moveUp = new QPropertyAnimation(sequenceWidget, "pos");
    moveUp->setDuration(800); // 时长0.8秒
    moveUp->setStartValue(QPoint(350, 400)); // 右侧位置
    moveUp->setEndValue(QPoint(350, 200));   // 上方位置
    moveUp->setEasingCurve(QEasingCurve::OutBack); // 回弹效果

    // 左移动画
    QPropertyAnimation *moveLeft = new QPropertyAnimation(sequenceWidget, "pos");
    moveLeft->setDuration(1000); // 时长1秒
    moveLeft->setStartValue(QPoint(350, 200)); // 上方位置
    moveLeft->setEndValue(QPoint(150, 200));   // 左侧位置
    moveLeft->setEasingCurve(QEasingCurve::InOutQuad); // 缓动曲线

    // 下移动画
    QPropertyAnimation *moveDown = new QPropertyAnimation(sequenceWidget, "pos");
    moveDown->setDuration(800); // 时长0.8秒
    moveDown->setStartValue(QPoint(150, 200)); // 左侧位置
    moveDown->setEndValue(QPoint(150, 400));   // 下方位置
    moveDown->setEasingCurve(QEasingCurve::InBack); // 回弹效果

    // 添加到动画组
    sequenceGroup->addAnimation(moveRight);
    sequenceGroup->addAnimation(moveUp);
    sequenceGroup->addAnimation(moveLeft);
    sequenceGroup->addAnimation(moveDown);

    // 启动动画
    sequenceGroup->start();

    // 动画结束后恢复原位
    connect(sequenceGroup, &QSequentialAnimationGroup::finished, [=]() {
        sequenceWidget->move(50, 400);
    });
}



/**
 * @brief 翻转动画
 *
 * 3D卡片翻转效果，同时改变颜色
 */
void AnimationDemo::flipAnimation(FlipWidget *flipWidget,
                                  qreal startAngle, qreal endAngle,
                                  const QColor &startColor, const QColor &endColor,
                                  int duration ,
                                  AnimationCallback callback ) {
    // 创建翻转动画
    QPropertyAnimation *flipAnim = new QPropertyAnimation(flipWidget, "flipAngle");
    flipAnim->setDuration(1500); // 时长1.5秒
    flipAnim->setStartValue(startAngle);   // 起始角度0度
    flipAnim->setEndValue(endAngle);   // 结束角度360度
    flipAnim->setEasingCurve(QEasingCurve::InOutQuad); // 缓动曲线

    // 创建颜色变化动画
    QPropertyAnimation *colorAnim = new QPropertyAnimation(flipWidget, "flipColor");
    colorAnim->setDuration(1500); // 时长1.5秒
    colorAnim->setStartValue(startColor); // 起始颜色（蓝色）
    colorAnim->setEndValue(endColor);   // 结束颜色（红色）

    // 创建并行动画组
    QParallelAnimationGroup *group = new QParallelAnimationGroup(this);
    group->addAnimation(flipAnim);
    group->addAnimation(colorAnim);

    // 启动动画
    group->start();
}



// void AnimationDemo::createWidgets()
// {
//     qDebug()<< "void createWidgets()";
// }


// void AnimationDemo::setupLayout()
// {
//     qDebug()<< "void setupLayout()";
// }

// void AnimationDemo::connectSignals()
// {
//     qDebug()<< "void connectSignals()";
// }


void AnimationDemo::handleAnimationFinished(AnimationCallback callback) {
    if (callback) {
        callback();
    }
}
