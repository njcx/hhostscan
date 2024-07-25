#include "bannergrabber.h"

BannerGrabber::BannerGrabber(QObject *parent) : QObject(parent)
{
    connect(&tcpSocket, &QTcpSocket::readyRead, this, &BannerGrabber::readTcpData);
    connect(&tcpSocket, QOverload<QAbstractSocket::SocketError>::of(&QTcpSocket::error), this, &BannerGrabber::handleTcpError);

    connect(&udpSocket, &QUdpSocket::readyRead, this, &BannerGrabber::readUdpData);
    connect(&udpSocket, QOverload<QAbstractSocket::SocketError>::of(&QUdpSocket::error), this, &BannerGrabber::handleUdpError);

    connect(&timer, &QTimer::timeout, this, &BannerGrabber::handleTimeout);
}

void BannerGrabber::getTcpBanner(const QString &host, quint16 port, int timeout)
{
    tcpSocket.abort(); // 中止任何已有连接
    tcpSocket.connectToHost(host, port);
    if (tcpSocket.waitForConnected(timeout)) {
        timer.start(timeout);
    } else {
        emit errorOccurred(tcpSocket.errorString());
    }
}

void BannerGrabber::getUdpBanner(const QString &host, quint16 port, int timeout)
{
    udpSocket.abort(); // 中止任何已有连接
    udpSocket.connectToHost(host, port);
    QByteArray datagram = "Hello"; // UDP 通常需要发送一些数据来触发响应
    udpSocket.write(datagram);
    timer.start(timeout);
}

void BannerGrabber::readTcpData()
{
    timer.stop();
    QString banner = tcpSocket.readAll();
    emit bannerReceived(banner);
    tcpSocket.disconnectFromHost();
}

void BannerGrabber::readUdpData()
{
    timer.stop();
    while (udpSocket.hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(int(udpSocket.pendingDatagramSize()));
        udpSocket.readDatagram(datagram.data(), datagram.size());
        QString banner = datagram;
        emit bannerReceived(banner);
    }
}

void BannerGrabber::handleTimeout()
{
    if (tcpSocket.state() == QTcpSocket::ConnectedState) {
        tcpSocket.disconnectFromHost();
    }
    emit errorOccurred("Connection timed out");
}

void BannerGrabber::handleTcpError(QAbstractSocket::SocketError socketError)
{
    Q_UNUSED(socketError);
    emit errorOccurred(tcpSocket.errorString());
}

void BannerGrabber::handleUdpError(QAbstractSocket::SocketError socketError)
{
    Q_UNUSED(socketError);
    emit errorOccurred(udpSocket.errorString());
}
