#ifndef TRANSFORMWIDGET_H
#define TRANSFORMWIDGET_H

#include <QWidget>
#include <QPainter>

/**
 * @class TransformWidget
 * @brief 支持旋转和缩放变换的自定义控件
 *
 * 提供rotation和scale属性，可用于实现旋转和缩放动画
 */
class TransformWidget : public QWidget {
    Q_OBJECT
    Q_PROPERTY(qreal rotation READ rotation WRITE setRotation) // 旋转角度属性
    Q_PROPERTY(qreal scale READ scale WRITE setScale)         // 缩放比例属性

public:
    explicit TransformWidget(QWidget *parent = nullptr);

    // 获取和设置旋转角度
    qreal rotation() const;
    void setRotation(qreal rotation);

    // 获取和设置缩放比例
    qreal scale() const;
    void setScale(qreal scale);

protected:
    // 重绘事件，应用变换
    void paintEvent(QPaintEvent *event) override;

private:
    qreal m_rotation = 0.0; // 当前旋转角度（度）
    qreal m_scale = 1.0;    // 当前缩放比例
};

#endif // TRANSFORMWIDGET_H
