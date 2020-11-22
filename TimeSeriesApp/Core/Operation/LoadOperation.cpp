#include "LoadOperation.h"

LoadOperation::LoadOperation(const QString &fileName) :
    m_fileName(fileName)
{

}

OperationType LoadOperation::type() const
{
    return OperationType::Load;
}

OperationStatus LoadOperation::status() const
{
    return m_status;
}

void LoadOperation::setStatus(const OperationStatus &status)
{
    m_status = status;
}

QString LoadOperation::fileName() const
{
    return m_fileName;
}

void LoadOperation::setFileName(const QString &fileName)
{
    m_fileName = fileName;
}

QSharedPointer<TimeSeries> LoadOperation::loadedTimeSeries() const
{
    return m_loadedTimeSeries;
}

void LoadOperation::setLoadedTimeSeries(const QSharedPointer<TimeSeries> &loadedTimeSeries)
{
    m_loadedTimeSeries = loadedTimeSeries;
}
