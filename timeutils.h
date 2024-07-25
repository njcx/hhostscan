#ifndef TIMEUTILS_H
#define TIMEUTILS_H

#include <QObject>
#include <QDateTime>
#include <QString>

class TimeUtils : public QObject
{
    Q_OBJECT
public:
    explicit TimeUtils(QObject *parent = nullptr);

    // 获取当前时间的字符串表示
    static QString getCurrentTimeString(const QString &format = "yyyy-MM-dd HH:mm:ss");

    // 计算两个时间之间的差异（以秒为单位）
    static qint64 timeDifferenceInSeconds(const QDateTime &start, const QDateTime &end);

    // 将字符串解析为 QDateTime
    static QDateTime parseDateTimeString(const QString &dateTimeString, const QString &format = "yyyy-MM-dd HH:mm:ss");

    // 将 QDateTime 转换为字符串
    static QString formatDateTime(const QDateTime &dateTime, const QString &format = "yyyy-MM-dd HH:mm:ss");
};


#endif // TIMEUTILS_H
