#include "timeutils.h"

TimeUtils::TimeUtils(QObject *parent) : QObject(parent)
{
}

QString TimeUtils::getCurrentTimeString(const QString &format)
{
    return QDateTime::currentDateTime().toString(format);
}

qint64 TimeUtils::timeDifferenceInSeconds(const QDateTime &start, const QDateTime &end)
{
    return start.secsTo(end);
}

QDateTime TimeUtils::parseDateTimeString(const QString &dateTimeString, const QString &format)
{
    return QDateTime::fromString(dateTimeString, format);
}

QString TimeUtils::formatDateTime(const QDateTime &dateTime, const QString &format)
{
    return dateTime.toString(format);
}
