#include "httpclient.h"
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QDebug>
#include <QUrl>

HttpClient::HttpClient(QObject *parent) : QObject(parent) {
    connect(&manager, &QNetworkAccessManager::finished,
            this, &HttpClient::onFinished);
}

HttpClient::~HttpClient() {}

void HttpClient::get(const QString &url) {
    QNetworkRequest request((QUrl(url)));
    manager.get(request);
}

void HttpClient::post(const QString &url, const QJsonObject &data) {
    QNetworkRequest request((QUrl(url)));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonDocument doc(data);
    QByteArray postData = doc.toJson();
    manager.post(request, postData);
}

void HttpClient::onFinished(QNetworkReply *reply) {
    if (reply->error()) {
        qDebug() << "Error:" << reply->errorString();
    } else {
        qDebug() << "Response:" << reply->readAll();
    }
    reply->deleteLater();
}
