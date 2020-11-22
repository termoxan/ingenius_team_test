#ifndef TIMEITEM_H
#define TIMEITEM_H

#include <qglobal.h>

/**
 * @brief Элемент временного ряда.
 */
class TimeItem
{
public:
    /**
     * @brief Иницализирует объект.
     * @param index Индекс элемента.
     * @param value Значение элемента.
     */
    explicit TimeItem(const quint64 &index = 0, const qint32 &value = 0);

    /// Возвращает индекс элемента.
    quint64 index() const;
    /// Изменяет индекс элемента.
    void setIndex(const quint64 &index);

    /// Возвращает значение элемента.
    qint32 value() const;
    /// Изменяет значение элемента.
    void setValue(const qint32 &value);

private:
    /// Индекс элемента.
    quint64 m_index;
    /// Значение элемента.
    qint32 m_value;
};

#endif // TIMEITEM_H
