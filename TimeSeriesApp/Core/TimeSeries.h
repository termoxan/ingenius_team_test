#ifndef TIMESERIES_H
#define TIMESERIES_H

#include <qglobal.h>

/// Идентификатор нового временного ряда.
constexpr quint64 NEW_ITEM_ID = 0;

/**
 * @brief Временной ряд.
 */
class TimeSeries
{
public:
    /**
     * @brief Инициализирует объект.
     * @param id Идентификатор временного ряда
     * @param count Количество элементов во временном ряду.
     */
    explicit TimeSeries(const quint64 &id, const qint32 &count);

    /// Возвращает идентификатор временного ряда.
    quint64 id() const;
    /// Изменяет идентификатор временного ряда.
    void setId(const quint64 &id);

    /// Возвращает количество элементов во временном ряду.
    qint32 count() const;
    /// Изменяет количество элементов во временном ряду.
    void setCount(const qint32 &count);

private:
    quint64 m_id;
    qint32 m_count;
};

#endif // TIMESERIES_H
