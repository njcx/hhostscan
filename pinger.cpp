#include "pinger.h"
#include <QProcess>
#include <QDebug>

Pinger::Pinger(QObject *parent) : QObject(parent), m_process(nullptr)
{
}

void Pinger::ping(const QString &host)
{
    if (m_process) {
        delete m_process;
    }
    m_process = new QProcess(this);
    connect(m_process, &QProcess::readyReadStandardOutput, this, &Pinger::readOutput);
    connect(m_process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            m_process, &QProcess::deleteLater);

    QStringList arguments;
    #ifdef Q_OS_WIN
        arguments << "-n" << "4" << host;
    #else
        arguments << "-c" << "4" << host;
    #endif

    m_process->start("ping", arguments);

    if (!m_process->waitForStarted()) {
        qDebug() << "Failed to start ping process:" << m_process->errorString();
    }
}

void Pinger::readOutput()
{
    if (m_process) {
        qDebug() << m_process->readAllStandardOutput();
    }
}
