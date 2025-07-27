#include "transformwidget.h"

/**
 * @brief 构造函数
 * @param parent 父控件
 */
TransformWidget::TransformWidget(QWidget *parent) : QWidget(parent) {}

/**
 * @brief 获取当前旋转角度
 * @return 旋转角度（度）
 */
qreal TransformWidget::rotation() const {
    return m_rotation;
}

/**
 * @brief 设置旋转角度并触发重绘
 * @param rotation 新的旋转角度（度）
 */
void TransformWidget::setRotation(qreal rotation) {
    m_rotation = rotation;
    update(); // 触发重绘
}

/**
 * @brief 获取当前缩放比例
 * @return 缩放比例
 */
qreal TransformWidget::scale() const {
    return m_scale;
}

/**
 * @brief 设置缩放比例并触发重绘
 * @param scale 新的缩放比例
 */
void TransformWidget::setScale(qreal scale) {
    m_scale = scale;
    update(); // 触发重绘
}

/**
 * @brief 重绘事件处理
 * @param event 绘制事件
 *
 * 应用旋转和缩放变换后绘制控件内容
 */
void TransformWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing); // 启用抗锯齿

    // 保存原始状态
    painter.save();

    // 应用变换：
    // 1. 平移到中心点
    // 2. 旋转
    // 3. 缩放
    // 4. 平移回原点
    painter.translate(width() / 2, height() / 2);
    painter.rotate(m_rotation);
    painter.scale(m_scale, m_scale);
    painter.translate(-width() / 2, -height() / 2);

    // 绘制控件内容（使用基类实现）
    QWidget::paintEvent(event);

    // 恢复原始状态
    painter.restore();
}
