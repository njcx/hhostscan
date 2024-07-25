#include "logutils.h"

QFile LogUtils::logFile;
QTextStream LogUtils::logStream;

LogUtils::LogUtils(QObject *parent) : QObject(parent)
{
}

void LogUtils::initLogging(const QString &logFilePath)
{
    logFile.setFileName(logFilePath);
    if (!logFile.open(QIODevice::Append | QIODevice::Text)) {
        qWarning() << "Could not open log file for writing: " << logFilePath;
    } else {
        logStream.setDevice(&logFile);
        qInstallMessageHandler(customMessageHandler);
    }
}

void LogUtils::customMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString logMessage;

    switch (type) {
        case QtDebugMsg:
            logMessage = QString("%1 [DEBUG]: %2").arg(timestamp, msg);
            break;
        case QtInfoMsg:
            logMessage = QString("%1 [INFO]: %2").arg(timestamp, msg);
            break;
        case QtWarningMsg:
            logMessage = QString("%1 [WARNING]: %2").arg(timestamp, msg);
            break;
        case QtCriticalMsg:
            logMessage = QString("%1 [CRITICAL]: %2").arg(timestamp, msg);
            break;
        case QtFatalMsg:
            logMessage = QString("%1 [FATAL]: %2").arg(timestamp, msg);
            // 使用 qCritical 代替 abort 来终止程序
            qCritical("%s", qPrintable(logMessage));
            return;
    }

    logStream << logMessage << Qt::endl;
    logStream.flush();

    // 同时输出到控制台
    fprintf(stderr, "%s\n", qPrintable(logMessage));
    fflush(stderr);
}
