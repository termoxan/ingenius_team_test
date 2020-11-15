#include "SaveSettings.h"

SaveSettings::SaveSettings(QSharedPointer<Operation> operation, const QString &fileName,
                           QSharedPointer<TimeSeries> timeSeries) :
    OperationSettings(operation),
    m_fileName(fileName),
    m_timeSeries(timeSeries)
{

}

QString SaveSettings::fileName() const
{
    return m_fileName;
}

void SaveSettings::setFileName(const QString &fileName)
{
    m_fileName = fileName;
}

QSharedPointer<TimeSeries> SaveSettings::timeSeries() const
{
    return m_timeSeries;
}

void SaveSettings::setTimeSeries(const QSharedPointer<TimeSeries> &timeSeries)
{
    m_timeSeries = timeSeries;
}
