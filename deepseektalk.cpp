/*********************
 * @file deepseektalk.cpp
 * @brief deepseek Talk source file
 * @author LFG (lfg@.com)
 * @version 1.0
 * @date 2025-08-01
 * 
 * @copyright Copyright (c) 2025  LFG
 * 
 *************************************************/
#include "deepseektalk.h"
#include "ui_deepseektalk.h"
#include "ui_commandbox.h"
#include "animationdemo.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

#include <QStringLiteral>


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

#include <QShortcut>

// deepseekTalk::deepseekTalk(QWidget *parent)
//     : QWidget(parent)
//     , ui(new Ui::deepseekTalk)
//     , request(url)


/*********************
 * @brief Construct a new deepseek Talk::deepseek Talk object
 * @param  command 命令盒对象
 *************************************************/
deepseekTalk::deepseekTalk(CommandBox* command)
    : ui(new Ui::deepseekTalk)
    , request(url)
{
    ui->setupUi(this);
    qDebug() << "UI init finished，wodgets sum ：" << this->children().size();
    // qDebug() << "UI 初始化完成，控件数量：" << this->children().size();
    QString apikey = "sk-f84e2f1fd5ce46a68e66043059696a6d";
    QUrl url = QString("https://api.deepseek.com/chat/completions");

    // QNetworkRequest  request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json") ;
    request.setRawHeader("Authorization",QString("Bearer %1").arg(apikey).toUtf8())  ;

    // QJsonObject rootObj;
    // 使用新的模型R1："deepseek-reasoner";
    rootObj["model"] = "deepseek-chat";
    rootObj["stream"] = false;
    // 可能是新的模型原因吗？每次会回复全部历史消息？

    MakeupAI(rootObj, mesgArray, command);
    Makeuphuman(rootObj, mesgArray, command);

    // 转json格式
    QJsonDocument doc(rootObj);
    QByteArray json = doc.toJson();

    // 发送请求，并得到一个回复对象
    reply = manager.post(request, json);
    // connect(reply, &QNetworkReply::readyRead, this, &deepseekTalk::readData);
    // readyread信号可以优化， 使用lambda表达式作为信号接收方式，捕获当前ommandbox对象
    connect(reply, &QNetworkReply::readyRead, this, [this, command](){
        this->readData(command);
        if( this != nullptr )
        {
            qDebug() << "deepseek  Alive";
        }
        if( this == nullptr )
        {
            qDebug() << "deepseek not  Alive";
        }
    });

    connect(ui->send, &QPushButton::clicked, this, [this, command](){this->sendClicked(command);});

    // 连接动画请求信号
    connect(this, &deepseekTalk::requestAnimation,
            &AnimationDemo::Animationinstance(), &AnimationDemo::slideAnimation);

    // 在构造函数中添加
    // QShortcut *shortcut = new QShortcut(QKeySequence(Qt::Key_Return), ui->usertext);
    // connect(shortcut, &QShortcut::activated, ui->send, &QPushButton::click);
}


deepseekTalk::~deepseekTalk()
{
    delete ui;
}


/*********************
 * @brief 发送消息的槽函数，负责获取回复对象，执行解析、输出回复文本
 * @param  command 
 *************************************************/
void deepseekTalk::readData(CommandBox* command)
{
    qDebug()<< "Button was Clicked3";
    QNetworkReply * reply = qobject_cast<QNetworkReply*>(sender());
    QByteArray data = reply->readAll();
    qDebug()<< QString(data);
    qDebug()<< "Button was Clicked4";
    //json  解析
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(data, &err);
    if( err.error != QJsonParseError::NoError )
    {
        qDebug()<< "json format ERROR";
        return;
    }
    qDebug()<< "Button was Clicked5";
    QJsonObject obj = doc.object();
    QJsonArray choiceArray = obj["choices"].toArray();
    QJsonObject arrayObj = choiceArray.at(0).toObject();
    QJsonObject message = arrayObj["message"].toObject();
    QString content = message["content"].toString();

    qDebug()<< "Button was Clicked6";
    command->ui->outputArea->setText(content);
    qDebug()<< "Button was Clicked7";
}

/*********************
 * @brief 将用户的消息构造为json对象，并添加到messages消息数组
 * @param  rootObj 
 * @param  mesgArray 
 * @param  command 
 *************************************************/
void deepseekTalk::Makeuphuman(QJsonObject &rootObj, QJsonArray &mesgArray, CommandBox* command)
{
    QJsonObject objHuman;
    qDebug()<< QStringLiteral("Button was Clicked12");
    objHuman["role"] = "user";
    qDebug()<< "Button was Clicked13";
    objHuman["content"] = command->ui->inputField->text();
    // objHuman["content"] = ui->usertext->toPlainText();
    qDebug()<< "Button was Clicked14";
    mesgArray.append(objHuman);
    qDebug()<< "Button was Clicked15";
    rootObj["messages"] = mesgArray;
    qDebug()<< "Button was Clicked16";
}

/*********************
 * @brief 将AI的回复消息构造为json对象，并添加到messages消息数组
 * @param  rootObj 
 * @param  mesgArray 
 * @param  command 
 *************************************************/
void deepseekTalk::MakeupAI(QJsonObject &rootObj, QJsonArray &mesgArray, CommandBox* command)
{
    QJsonObject objAI;
    objAI["role"] = "assistant";
    objAI["content"] = "你是小李";

    mesgArray.append(objAI);

    // rootObj["messages"] = mesgArray;
}


// 发送Button was Clicked事件
// 默认时无参的吗？如果带参数是不是算作重载了
/*********************
 * @brief 由系统生成的点击发送按钮的发送默认槽函数，已经重写为sendClicked，并使用
 * @param  command 
 *************************************************/
void deepseekTalk::on_send_clicked(CommandBox* command)
{

    // 先添加内容，在构建请求体，在发送
    qDebug()<< "Button was Clicked";
    Makeuphuman(rootObj, mesgArray, command);
    qDebug()<< "Button was Clicked8";
    QJsonDocument doc(rootObj);
    QByteArray json = doc.toJson();

    qDebug()<< "Button was Clicked1";
    // 发送
    reply = manager.post(request, json);
    // connect(reply, &QNetworkReply::readyRead, this, &deepseekTalk::readData);

    qDebug()<< "Button was Clicked2";
    connect(reply, &QNetworkReply::readyRead, this, [this, command](){
        this->readData(command);
        if( this != nullptr )
        {
            qDebug() << "deepseek  Alive222";
        }
        if( this == nullptr )
        {
            qDebug() << "deepseek不  Alive";
        }
    });

    // 先进行输入与输出重定向，取消show函数，在connect中添加判断，当deepseek运行时，断开连接，当deep seek关闭时，重新连接.

    // 发送动画信号
    // using AnimationCallback = std::function<void()>;
    // emit requestAnimation(ui->send,
    //                       QRect(800, 200, 200, 200),
    //                         QRect(300, 200, 200, 200),
    //                       1000,
    //                       nullptr);

}


/*********************
 * @brief 正式使用的Button was Clicked发送槽函数
 * @param  command commandbox对象
 *************************************************/
void deepseekTalk::sendClicked(CommandBox* command)
{
    if( command->ui->inputField->text() == "exit" )
    {
        // 退出
        // 重连connect
    }

    qDebug()<< "Button was Clicked";
    Makeuphuman(rootObj, mesgArray, command);
    qDebug()<< "Button was Clicked8";
    QJsonDocument doc(rootObj);
    QByteArray json = doc.toJson();

    qDebug()<< "Button was Clicked1";
    reply = manager.post(request, json);
    // connect(reply, &QNetworkReply::readyRead, this, &deepseekTalk::readData);

    qDebug()<< "Button was Clicked2";
    connect(reply, &QNetworkReply::readyRead, this, [this, command](){
        this->readData(command);
        if( this != nullptr )
        {
            qDebug() << "deepseek  Alive222";
        }
        if( this == nullptr )
        {
            qDebug() << "deepseek不  Alive";
        }
    });
}
