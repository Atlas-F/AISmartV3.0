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

deepseekTalk::deepseekTalk(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::deepseekTalk)
    , request(url)
{
    ui->setupUi(this);
    QString apikey = "sk-f84e2f1fd5ce46a68e66043059696a6d";
    QUrl url = QString("https://api.deepseek.com/chat/completions");

    // QNetworkRequest  request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json") ;
    request.setRawHeader("Authorization",QString("Bearer %1").arg(apikey).toUtf8())  ;

    // QJsonObject rootObj;
    // 使用新的模型R1
    rootObj["model"] = "deepseek-reasoner";
    rootObj["stream"] = false;

    // QJsonArray mesgArray;
    // QJsonObject objAI;
    // objAI["role"] = "assistant";
    // objAI["content"] = "you are a helpful assistant";

    // QJsonObject objHuman;
    // objHuman["role"] = "user";
    // objHuman["content"] = ui->usertext->toPlainText();

    // mesgArray.append(objAI);
    // mesgArray.append(objHuman);

    // rootObj["messages"] = mesgArray;

    MakeupAI(rootObj, mesgArray);
    Makeuphuman(rootObj, mesgArray);

    // 转json格式
    QJsonDocument doc(rootObj);
    QByteArray json = doc.toJson();


    reply = manager.post(request, json);
    connect(reply, &QNetworkReply::readyRead, this, &deepseekTalk::readData);

    // 连接动画请求信号
    connect(this, &deepseekTalk::requestAnimation,
            &AnimationDemo::Animationinstance(), &AnimationDemo::slideAnimation);

}


void deepseekTalk::readData()
{
    QNetworkReply * reply = qobject_cast<QNetworkReply*>(sender());
    QByteArray data = reply->readAll();
    qDebug()<< QString(data);

    //json  解析
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(data, &err);
    if( err.error != QJsonParseError::NoError )
    {
        qDebug()<< "json 格式错误";
        return;
    }

    QJsonObject obj = doc.object();
    QJsonArray choiceArray = obj["choices"].toArray();

    QJsonObject arrayObj = choiceArray.at(0).toObject();
    QJsonObject message = arrayObj["message"].toObject();

    QString content = message["content"].toString();

    ui->dpsktext->setText(content);

}

deepseekTalk::~deepseekTalk()
{
    delete ui;
}

void deepseekTalk::Makeuphuman(QJsonObject &rootObj, QJsonArray &mesgArray)
{
    QJsonObject objHuman;
    objHuman["role"] = "user";
    objHuman["content"] = ui->usertext->toPlainText();

    mesgArray.append(objHuman);

    rootObj["messages"] = mesgArray;
}

void deepseekTalk::MakeupAI(QJsonObject &rootObj, QJsonArray &mesgArray)
{
    QJsonObject objAI;
    objAI["role"] = "assistant";
    objAI["content"] = "你是周博士的弟弟小李";

    mesgArray.append(objAI);

    // rootObj["messages"] = mesgArray;
}


// 发送按钮点击事件
void deepseekTalk::on_send_clicked()
{
    // 参数：
    //
    // 先添加内容，在构建请求体，在发送
    qDebug()<< "按钮点击";
    Makeuphuman(rootObj, mesgArray);

    QJsonDocument doc(rootObj);
    QByteArray json = doc.toJson();


    reply = manager.post(request, json);
    connect(reply, &QNetworkReply::readyRead, this, &deepseekTalk::readData);

    // 发送动画信号
    // using AnimationCallback = std::function<void()>;
    // emit requestAnimation(ui->send,
    //                       QRect(800, 200, 200, 200),
    //                         QRect(300, 200, 200, 200),
    //                       1000,
    //                       nullptr);

}

