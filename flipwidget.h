#ifndef FLIPWIDGET_H
#define FLIPWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QVector3D>  // 添加 QVector3D 头文件

/**
 * @class FlipWidget
 * @brief 支持3D翻转效果的自定义控件
 *
 * 提供flipAngle和flipColor属性，可用于实现3D翻转动画
 */
class FlipWidget : public QWidget {
    Q_OBJECT
    Q_PROPERTY(qreal flipAngle READ flipAngle WRITE setFlipAngle) // 翻转角度属性
    Q_PROPERTY(QColor flipColor READ flipColor WRITE setFlipColor) // 颜色属性

public:
    explicit FlipWidget(QWidget *parent = nullptr);

    // 获取和设置翻转角度
    qreal flipAngle() const;
    void setFlipAngle(qreal angle);

    // 获取和设置颜色
    QColor flipColor() const;
    void setFlipColor(const QColor &color);

protected:
    // 重绘事件，应用3D翻转效果
    void paintEvent(QPaintEvent *event) override;

private:
    qreal m_flipAngle = 0.0; // 当前翻转角度（度）
    QColor m_flipColor = Qt::blue; // 当前颜色
};

#endif // FLIPWIDGET_H
