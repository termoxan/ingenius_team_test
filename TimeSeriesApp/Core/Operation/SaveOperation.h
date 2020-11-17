#ifndef SAVEOPERATION_H
#define SAVEOPERATION_H

#include "Operation.h"
#include "OperationStatus.h"

#include <QSharedPointer>

class TimeSeies;

class SaveOperation : public Operation
{
public:
    SaveOperation();

    // Operation interface
public:
    OperationType type() const;
    OperationStatus status() const;
    void setStatus(const OperationStatus &status);

    QString fileName() const;
    void setFileName(const QString &fileName);

    QSharedPointer<TimeSeies> timeSeries() const;
    void setTimeSeries(const QSharedPointer<TimeSeies> &timeSeries);

private:
    OperationStatus m_status;

    QString m_fileName;
    QSharedPointer<TimeSeies> m_timeSeries;
};

#endif // SAVEOPERATION_H
