#include "deepseektalk.h"
#include "ui_deepseektalk.h"
#include "animationdemo.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>


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


deepseekTalk::deepseekTalk(CommandSystem* command)
    : ui(new Ui::deepseekTalk)
    , request(url)
{
    ui->setupUi(this);





    qDebug() << "UI初始化完成，控件数量：" << this->children().size();
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


    reply = manager.post(request, json);
    // connect(reply, &QNetworkReply::readyRead, this, &deepseekTalk::readData);
    connect(reply, &QNetworkReply::readyRead, this, [this, command](){
        this->readData(command);
        if( this != nullptr )
        {
            qDebug() << "deepseek存在111";
        }
        if( this == nullptr )
        {
            qDebug() << "deepseek不存在";
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


void deepseekTalk::readData(CommandSystem* command)
{
    qDebug()<< "按钮点击3";
    QNetworkReply * reply = qobject_cast<QNetworkReply*>(sender());
    QByteArray data = reply->readAll();
    qDebug()<< QString(data);
    qDebug()<< "按钮点击4";
    //json  解析
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(data, &err);
    if( err.error != QJsonParseError::NoError )
    {
        qDebug()<< "json 格式错误";
        return;
    }
    qDebug()<< "按钮点击5";
    QJsonObject obj = doc.object();
    QJsonArray choiceArray = obj["choices"].toArray();

    QJsonObject arrayObj = choiceArray.at(0).toObject();
    QJsonObject message = arrayObj["message"].toObject();

    QString content = message["content"].toString();
    qDebug()<< "按钮点击6";
    command->outputArea->setText(content);
    qDebug()<< "按钮点击7";
}

void deepseekTalk::Makeuphuman(QJsonObject &rootObj, QJsonArray &mesgArray, CommandSystem* command)
{
    QJsonObject objHuman;
    qDebug()<< "按钮点击12";
    objHuman["role"] = "user";
    qDebug()<< "按钮点击13";
    objHuman["content"] = command->inputField->text();
    // objHuman["content"] = ui->usertext->toPlainText();
qDebug()<< "按钮点击14";
    mesgArray.append(objHuman);
qDebug()<< "按钮点击15";
    rootObj["messages"] = mesgArray;
qDebug()<< "按钮点击16";
}

void deepseekTalk::MakeupAI(QJsonObject &rootObj, QJsonArray &mesgArray, CommandSystem* command)
{
    QJsonObject objAI;
    objAI["role"] = "assistant";
    objAI["content"] = "你是周博士的弟弟小李";

    mesgArray.append(objAI);

    // rootObj["messages"] = mesgArray;
}


// 发送按钮点击事件
// 默认时无参的吗？如果带参数是不是算作重载了
void deepseekTalk::on_send_clicked(CommandSystem* command)
{
    // 参数：
    //
    // 先添加内容，在构建请求体，在发送
    qDebug()<< "按钮点击";
    Makeuphuman(rootObj, mesgArray, command);
qDebug()<< "按钮点击8";
    QJsonDocument doc(rootObj);
    QByteArray json = doc.toJson();

    qDebug()<< "按钮点击1";
    reply = manager.post(request, json);
    // connect(reply, &QNetworkReply::readyRead, this, &deepseekTalk::readData);

    qDebug()<< "按钮点击2";
    connect(reply, &QNetworkReply::readyRead, this, [this, command](){
        this->readData(command);
        if( this != nullptr )
        {
            qDebug() << "deepseek存在222";
        }
        if( this == nullptr )
        {
            qDebug() << "deepseek不存在";
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


void deepseekTalk::sendClicked(CommandSystem* command)
{
    if( command->inputField->text() == "exit" )
    {
        // 退出
        // 重连connect
    }

    qDebug()<< "按钮点击";
    Makeuphuman(rootObj, mesgArray, command);
    qDebug()<< "按钮点击8";
    QJsonDocument doc(rootObj);
    QByteArray json = doc.toJson();

    qDebug()<< "按钮点击1";
    reply = manager.post(request, json);
    // connect(reply, &QNetworkReply::readyRead, this, &deepseekTalk::readData);

    qDebug()<< "按钮点击2";
    connect(reply, &QNetworkReply::readyRead, this, [this, command](){
        this->readData(command);
        if( this != nullptr )
        {
            qDebug() << "deepseek存在222";
        }
        if( this == nullptr )
        {
            qDebug() << "deepseek不存在";
        }
    });
}
