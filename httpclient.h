#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QJsonObject>

class HttpClient : public QObject
{
    Q_OBJECT
public:
    explicit HttpClient(QObject *parent = nullptr);
    virtual ~HttpClient();

    void get(const QString &url);
    void post(const QString &url, const QJsonObject &data);

private slots:
    void onFinished(QNetworkReply *reply);

private:
    QNetworkAccessManager manager;
};


#endif
