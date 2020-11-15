#include "LoadData.h"

LoadData::LoadData(QSharedPointer<Operation> operation,
                   QSharedPointer<TimeSeries> timeSeries) :
    OperationData(operation),
    m_timeSeries(timeSeries)
{

}

QSharedPointer<TimeSeries> LoadData::timeSeries() const
{
    return m_timeSeries;
}

void LoadData::setTimeSeries(const QSharedPointer<TimeSeries> &timeSeries)
{
    m_timeSeries = timeSeries;
}
