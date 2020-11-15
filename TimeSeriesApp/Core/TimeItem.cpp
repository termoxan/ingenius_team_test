#include "TimeItem.h"

TimeItem::TimeItem(const quint64 &index, const qint32 &value) :
    m_index(index),
    m_value(value)
{

}

quint64 TimeItem::index() const
{
    return m_index;
}

void TimeItem::setIndex(const quint64 &index)
{
    m_index = index;
}

qint32 TimeItem::value() const
{
    return m_value;
}

void TimeItem::setValue(const qint32 &value)
{
    m_value = value;
}
