#include "mainwin.h"
#include "deepseektalk.h"
#include "datetime.h"
#include "animationdemo.h"
#include "widgettest.h"

#include <QThread>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWin w;
    // w.show();

    // // 设置应用样式
    // a.setStyle("Fusion");
    // // 设置调色板
    // QPalette palette;
    // palette.setColor(QPalette::Window, QColor(53,53,53));
    // palette.setColor(QPalette::WindowText, Qt::white);
    // palette.setColor(QPalette::Base, QColor(25,25,25));
    // palette.setColor(QPalette::AlternateBase, QColor(53,53,53));
    // palette.setColor(QPalette::ToolTipBase, Qt::white);
    // palette.setColor(QPalette::ToolTipText, Qt::white);
    // palette.setColor(QPalette::Text, Qt::white);
    // palette.setColor(QPalette::Button, QColor(53,53,53));
    // palette.setColor(QPalette::ButtonText, Qt::white);
    // palette.setColor(QPalette::BrightText, Qt::red);
    // palette.setColor(QPalette::Link, QColor(42, 130, 218));
    // palette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    // palette.setColor(QPalette::HighlightedText, Qt::black);
    // a.setPalette(palette);

    // MainWindow window;
    // window.show();

    deepseekTalk dp;
    dp.show();

    // 动画功能类
    // 注册自定义属性类型
    qRegisterMetaType<qreal>("qreal");

    // // 创建并显示主窗口
    // MyAnimationDemo demo;
    // demo.show();
    // demo.colorAnimation(demo, Qt::red, Qt::blue, 1000 , nullptr);

    // widgetTest wtest;
    // wtest.show();
    // AnimationDemo::Animationinstance().slideAnimation(wtest.getpushButton());
    // QThread::sleep(10);
    // AnimationDemo::Animationinstance().bounceAnimation(wtest.getpushButton_2());
    // QThread::sleep(1);
    // AnimationDemo::Animationinstance().colorAnimation(wtest.getpushButton_3());
    // QThread::sleep(1);
    // AnimationDemo::Animationinstance().fadeAnimation(wtest.getpushButton_4(), true);
    // QThread::sleep(1);
    // AnimationDemo::Animationinstance().complexAnimation(wtest.getpushButton_5());
    // _sleep(1);

    // 时间日期天气
    // DateTime today;
    // today.show();

    // // 父窗口
    // QWidget *parentWidget = new QWidget;
    // parentWidget->setWindowTitle("父窗口");
    // parentWidget->resize(800, 600);

    // // 创建子窗口（实际是 QWidget）
    // QWidget *childWidget = new QWidget(parentWidget);  // 关键：指定父对象
    // childWidget->setWindowTitle("子窗口");
    // childWidget->setStyleSheet("background-color: lightblue;");
    // childWidget->setMinimumSize(400, 300);

    // // 使用布局管理器
    // QVBoxLayout *layout = new QVBoxLayout(parentWidget);
    // layout->addWidget(childWidget);  // 将子窗口添加到布局

    // parentWidget->show();

    // Weather guangzhou;
    // guangzhou.show();
    return a.exec();
}
