#include "TimeSeries.h"

TimeSeries::TimeSeries(const quint64 &id, const qint32 &count) :
    m_id(id),
    m_count(count)
{

}

quint64 TimeSeries::id() const
{
    return m_id;
}

void TimeSeries::setId(const quint64 &id)
{
    m_id = id;
}

qint32 TimeSeries::count() const
{
    return m_count;
}

void TimeSeries::setCount(const qint32 &count)
{
    m_count = count;
}
