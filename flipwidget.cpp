#include "flipwidget.h"
#include <QPainter>
#include <QTransform>
#include <QtMath>

FlipWidget::FlipWidget(QWidget *parent) : QWidget(parent) {}

qreal FlipWidget::flipAngle() const {
    return m_flipAngle;
}

void FlipWidget::setFlipAngle(qreal angle) {
    m_flipAngle = angle;
    update();
}

QColor FlipWidget::flipColor() const {
    return m_flipColor;
}

void FlipWidget::setFlipColor(const QColor &color) {
    m_flipColor = color;
    update();
}

void FlipWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    // 保存原始状态
    painter.save();

    // 计算翻转角度的正弦和余弦值
    qreal radians = qDegreesToRadians(m_flipAngle);
    qreal cosAngle = qCos(radians);
    qreal sinAngle = qSin(radians);

    // 创建3D变换矩阵
    QTransform transform;

    // 1. 平移到中心点
    transform.translate(width() / 2.0, height() / 2.0);

    // 2. 应用3D旋转（绕Y轴）
    // 绕Y轴旋转的变换矩阵：
    // [ cos   0   sin ]
    // [ 0     1   0   ]
    // [-sin   0   cos ]
    QTransform rotation(
        cosAngle, 0.0, sinAngle,
        0.0,      1.0, 0.0,
        -sinAngle, 0.0, cosAngle
        );

    // 3. 组合变换
    transform *= rotation;

    // 4. 平移回原点
    transform.translate(-width() / 2.0, -height() / 2.0);

    // 应用变换
    painter.setTransform(transform);

    // 绘制卡片背景
    painter.setPen(Qt::NoPen);
    painter.setBrush(m_flipColor);
    painter.drawRoundedRect(rect(), 10, 10);

    // 绘制卡片文字
    painter.setPen(Qt::white);
    painter.setFont(QFont("Arial", 16, QFont::Bold));
    painter.drawText(rect(), Qt::AlignCenter, "Flip Animation");

    // 恢复原始状态
    painter.restore();
}
