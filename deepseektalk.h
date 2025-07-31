#ifndef DEEPSEEKTALK_H
#define DEEPSEEKTALK_H

#include <QWidget>
#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include <QJsonObject>
#include <QJsonArray>

#include "CommandSystem.h"

namespace Ui {
class deepseekTalk;
}

class deepseekTalk : public QWidget
{
    Q_OBJECT

    // explicit deepseekTalk(QWidget *parent = nullptr);
public:

    explicit deepseekTalk (CommandSystem * command = nullptr);
    ~deepseekTalk();
    void readData(CommandSystem* command);
    void Makeuphuman(QJsonObject &rootObj, QJsonArray &mesgArray, CommandSystem* command);
    void MakeupAI(QJsonObject &rootObj, QJsonArray &mesgArray, CommandSystem* command);
    QString apikey = "sk-f84e2f1fd5ce46a68e66043059696a6d";
    QUrl url = QString("https://api.deepseek.com/chat/completions");
    // QNetworkRequest request("https://api.deepseek.com/chat/completions");
public slots:
    void on_send_clicked(CommandSystem* command);
    void sendClicked(CommandSystem* command);

private slots:




private:
    Ui::deepseekTalk *ui;
    QNetworkAccessManager manager;
    QNetworkRequest request;

    QJsonObject rootObj;
    QJsonArray mesgArray;

    QNetworkReply * reply;

using AnimationCallback = std::function<void()>;

signals:
    void requestAnimation(QWidget *target,
                          const QRect &startRect ,
                          const QRect &endRect ,
                          int duration,
                          AnimationCallback callback );

private slots:
    // void on_animateButton_clicked();

};

// 构造请求体
class ConfigRequest
{
    // Q_OBJECT

public:
    ConfigRequest();
    ~ConfigRequest();


private:


};

// 将文本添加进消息数组
class AddTextToMesssage
{

public:
    AddTextToMesssage();
    ~AddTextToMesssage();
    void Makeuphuman();
    void MakeupAI();
private:
    QString content;
    Ui::deepseekTalk *ui;

};



#endif // DEEPSEEKTALK_H
