#ifndef LOADDATA_H
#define LOADDATA_H

#include "OperationData.h"

class TimeSeries;

class LoadData : public OperationData
{
public:
    explicit LoadData(QSharedPointer<Operation> operation, QSharedPointer<TimeSeries> timeSeries);

    QSharedPointer<TimeSeries> timeSeries() const;
    void setTimeSeries(QSharedPointer<TimeSeries> timeSeries);

private:
    QSharedPointer<TimeSeries> m_timeSeries;
};

#endif // LOADDATA_H
