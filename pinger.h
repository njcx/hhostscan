#ifndef PINGER_H
#define PINGER_H

#include <QObject>

class QProcess;

class Pinger : public QObject
{
    Q_OBJECT
public:
    explicit Pinger(QObject *parent = nullptr);
    void ping(const QString &host);

private slots:
    void readOutput();

private:
    QProcess *m_process;
};

#endif // PINGER_H
