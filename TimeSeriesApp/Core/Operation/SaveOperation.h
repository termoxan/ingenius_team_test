#ifndef SAVEOPERATION_H
#define SAVEOPERATION_H

#include "Operation.h"
#include "OperationStatus.h"

#include <QSharedPointer>

class TimeSeries;

class SaveOperation : public Operation
{
public:
    explicit SaveOperation(const QString &fileName,
                           const QWeakPointer<TimeSeries> &timeSeries);

    // Operation interface
public:
    OperationType type() const;
    OperationStatus status() const;
    void setStatus(const OperationStatus &status);

    QString fileName() const;
    void setFileName(const QString &fileName);

    QWeakPointer<TimeSeries> timeSeries() const;
    void setTimeSeries(const QWeakPointer<TimeSeries> &timeSeries);

private:
    OperationStatus m_status;

    QString m_fileName;
    QWeakPointer<TimeSeries> m_timeSeries;
};

#endif // SAVEOPERATION_H
