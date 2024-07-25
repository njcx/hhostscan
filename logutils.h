#ifndef LOGUTILS_H
#define LOGUTILS_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QDebug>

class LogUtils : public QObject
{
    Q_OBJECT
public:
    explicit LogUtils(QObject *parent = nullptr);

    // 初始化日志系统
    static void initLogging(const QString &logFilePath);

    // 自定义消息处理函数
    static void customMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

private:
    static QFile logFile;
    static QTextStream logStream;
};

#endif // LOGUTILS_H
