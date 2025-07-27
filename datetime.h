#ifndef DATETIME_H
#define DATETIME_H

#include <QWidget>
#include <QDate>
#include <QTime>
#include <QTimer>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include <QJsonObject>
#include <QJsonArray>

namespace Ui {
class DateTime;
}

class DateTime : public QWidget
{
    Q_OBJECT

public:
    explicit DateTime(QWidget *parent = nullptr);
    ~DateTime();

private slots:
    void updateTime();

    void handleWeatherReply(QNetworkReply* reply);


private:
    Ui::DateTime *ui;
    QTimer qtimer;
    QNetworkAccessManager manager;
    QNetworkRequest request;
};


// class Weather : public QWidget
// {
//     Q_OBJECT
// public :
//     Weather();
//     ~Weather();
// private slots:
//     void readData();

// private :
//     QNetworkAccessManager manager;
//     QNetworkRequest request;

// };

#endif // DATETIME_H
