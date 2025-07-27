#include "datetime.h"
#include "ui_datetime.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

DateTime::DateTime(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DateTime)
{
    ui->setupUi(this);

    // 设置日期
    QDate now = QDate::currentDate();
    QString nowDate = now.toString("yyyy-MM-dd");
    qDebug()<< nowDate;
    ui->date->setText(nowDate);

    // 设置时间
    QTime nowTime = QTime::currentTime();
    QString timeNow = nowTime.toString("hh:mm:ss AP");
    qDebug()<< timeNow;
    ui->time->setText(timeNow);

    qtimer.setInterval(1000);
    connect(&qtimer, &QTimer::timeout, this, &DateTime::updateTime);
    qtimer.start();


// #if 1

    // 设置天气
    // QString apiKey = "S5s2v5deZctn-lyum";
    QUrl url = QString("https://api.seniverse.com/v3/weather/now.json?key=S5s2v5deZctn-lyum&location=guangzhou&language=zh-Hans&unit=c");
    QNetworkRequest  request(url);

    // 转json格式
    // QJsonDocument doc(rootObj);
    // QByteArray json = doc.toJson();
    qDebug()<< "xinhaolianjei ";

    // 解析
    // QNetworkReply * replywea = manager.get(request,nullptr);
    // connect(reply, &QNetworkReply::readyRead, this, &Weather::readData);
    // 连接管理器信号（只需要一次）
    connect(&manager, &QNetworkAccessManager::finished,
            this, &DateTime::handleWeatherReply);
    qDebug()<< "123456789 ";
    // 发起请求
    manager.get(request);
    // replywea = qobject_cast<QNetworkReply*>(sender());
    // QByteArray datawea = replywea->readAll();
    // qDebug()<< QString(datawea);

    #if 0

    //json  解析
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(datawea, &err);
    if( err.error != QJsonParseError::NoError )
    {
        qDebug()<< "json 格式错误";
        return;
    }
    QJsonObject obj = doc.object();
    QJsonArray result = obj["results"].toArray();

    QJsonObject arrayObj = result.at(0).toObject();
    QJsonObject loc = arrayObj["location"].toObject();

    QString locate = loc["name"].toString();


    QJsonObject nowwea = arrayObj["now"].toObject();
    QString text = nowwea["text"].toString();
    QString tempurature = nowwea["tempurature"].toString();

    // ui->weather->setTextFormat("locate-text-tempurature",locate, );

    QString str = QString("%1-%2-%3")
                      .arg(locate)
                      .arg(text)
                      .arg(tempurature);
    ui->weather->setText(str);

#endif
}

DateTime::~DateTime()
{
    delete ui;
}

void DateTime::updateTime()
{
    // 设置日期
    QDate now = QDate::currentDate();
    QString nowDate = now.toString("yyyy-MM-dd");
    qDebug()<< nowDate;
    ui->date->setText(nowDate);

    // 设置时间
    QTime nowTime = QTime::currentTime();
    QString timeNow = nowTime.toString("hh:mm:ss AP");
    qDebug()<< timeNow;
    ui->time->setText(timeNow);
}


void DateTime::handleWeatherReply(QNetworkReply* reply)
{
    // QNetworkReply * replywea = qobject_cast<QNetworkReply*>(sender());
    QByteArray datawea = reply->readAll();
    qDebug()<< QString(datawea);
    qDebug()<< "xinhaolianjei ";

    //json  解析
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(datawea, &err);
    if( err.error != QJsonParseError::NoError )
    {
        qDebug()<< "json 格式错误";
        return;
    }
    QJsonObject obj = doc.object();
    QJsonArray result = obj["results"].toArray();

    QJsonObject arrayObj = result.at(0).toObject();
    QJsonObject loc = arrayObj["location"].toObject();

    QString locate = loc["name"].toString();

    QJsonObject now = arrayObj["now"].toObject();
    QString text = now["text"].toString();
    QString temperature = now["temperature"].toString();
    QString str = QString("%1-%2-%3")
                      .arg(locate)
                      .arg(text)
                      .arg(temperature);
    ui->weather->setText(str);

}

// Weather::Weather()
// {


//     QString apiKey = "S5s2v5deZctn-lyum";
//     QUrl url = QString("https://api.seniverse.com/v3/weather/now.json?key=S5s2v5deZctn-lyum&location=guangzhou&language=zh-Hans&unit=c");
//     QNetworkRequest  request(url);

//     // 转json格式
//     // QJsonDocument doc(rootObj);
//     // QByteArray json = doc.toJson();


//     QNetworkReply * reply = manager.get(request,nullptr);
//     connect(reply, &QNetworkReply::readyRead, this, &Weather::readData);

// }
// Weather::~Weather()
// {

// }

// void Weather::readData()
// {
//     QNetworkReply * replywea = qobject_cast<QNetworkReply*>(sender());
//     QByteArray datawea = replywea->readAll();
//     qDebug()<< QString(datawea);
//     qDebug()<< "xinhaolianjei ";

//     //json  解析
//     QJsonParseError err;
//     QJsonDocument doc = QJsonDocument::fromJson(datawea, &err);
//     if( err.error != QJsonParseError::NoError )
//     {
//         qDebug()<< "json 格式错误";
//         return;
//     }
//     QJsonObject obj = doc.object();
//     QJsonArray result = obj["results"].toArray();

//     QJsonObject arrayObj = result.at(0).toObject();
//     QJsonObject loc = arrayObj["location"].toObject();

//     QString locate = loc["name"].toString();

//     QJsonObject now = arrayObj["now"].toObject();
//     QString text = now["text"].toString();
//     QString tempurature = now["tempurature"].toString();
// QString str = QString("%1-%2-%3")
//                   .arg(locate)
//                   .arg(text)
//                   .arg(tempurature);
// ui->weather->setText(str);




// }


#if 0

{
  "results": [
    {
      "location": {
        "id": "WS0E9D8WN298",
        "name": "广州",
        "country": "CN",
        "path": "广州,广州,广东,中国",
        "timezone": "Asia/Shanghai",
        "timezone_offset": "+08:00"
      },
      "now": {
        "text": "小雨",
        "code": "13",
        "temperature": "24"
      },
      "last_update": "2025-07-25T19:37:21+08:00"
    }
  ]
}

#endif

