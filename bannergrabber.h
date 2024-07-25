#ifndef BANNERGRABBER_H
#define BANNERGRABBER_H

#include <QObject>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QTimer>

class BannerGrabber : public QObject
{
    Q_OBJECT
public:
    explicit BannerGrabber(QObject *parent = nullptr);

    // 获取 TCP 端口 banner
    void getTcpBanner(const QString &host, quint16 port, int timeout = 3000);

    // 获取 UDP 端口 banner
    void getUdpBanner(const QString &host, quint16 port, int timeout = 3000);

signals:
    // 成功获取 banner 信号
    void bannerReceived(const QString &banner);

    // 错误信号
    void errorOccurred(const QString &errorString);

private slots:
    // 读取 TCP 数据
    void readTcpData();

    // 读取 UDP 数据
    void readUdpData();

    // 处理连接超时
    void handleTimeout();

    // 处理 TCP 错误
    void handleTcpError(QAbstractSocket::SocketError socketError);

    // 处理 UDP 错误
    void handleUdpError(QAbstractSocket::SocketError socketError);

private:
    QTcpSocket tcpSocket;
    QUdpSocket udpSocket;
    QTimer timer;
};

#endif // BANNERGRABBER_H
