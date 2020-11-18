#include "SaveOperation.h"

SaveOperation::SaveOperation(const QString &fileName,
                             const QSharedPointer<TimeSeies> &timeSeries) :
    m_fileName(fileName),
    m_timeSeries(timeSeries)
{

}

OperationType SaveOperation::type() const
{
    return OperationType::Save;
}

OperationStatus SaveOperation::status() const
{
    return m_status;
}

void SaveOperation::setStatus(const OperationStatus &status)
{
    m_status = status;
}

QString SaveOperation::fileName() const
{
    return m_fileName;
}

void SaveOperation::setFileName(const QString &fileName)
{
    m_fileName = fileName;
}

QSharedPointer<TimeSeies> SaveOperation::timeSeries() const
{
    return m_timeSeries;
}

void SaveOperation::setTimeSeries(const QSharedPointer<TimeSeies> &timeSeries)
{
    m_timeSeries = timeSeries;
}
