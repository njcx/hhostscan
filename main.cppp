#include <QCoreApplication>
#include <QDebug>
#include "httpclient.h"
#include "timeutils.h"
#include "logutils.h"
#include "bannergrabber.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    LogUtils::initLogging("application.log");

    qDebug() << "This is a debug message";

    QString currentTime = TimeUtils::getCurrentTimeString();
     qDebug() << "Current Time:" << currentTime;

     BannerGrabber grabber;

     QObject::connect(&grabber, &BannerGrabber::bannerReceived, [](const QString &banner) {
         qDebug() << "Banner received:" << banner;
     });

     QObject::connect(&grabber, &BannerGrabber::errorOccurred, [](const QString &errorString) {
         qWarning() << "Error occurred:" << errorString;
     });

     // 获取 TCP 端口 banner
     grabber.getTcpBanner("example.com", 80);

     // 获取 UDP 端口 banner
     grabber.getUdpBanner("example.com", 123);

    HttpClient client;
    client.get("https://www.baidu.com");

    QJsonObject postData;
    postData["name"] = "John Doe";
    postData["age"] = 30;
    client.post("https://www.baidu.com", postData);

    return a.exec();
}
