#ifndef LOADOPERATION_H
#define LOADOPERATION_H

#include "Operation.h"
#include "OperationStatus.h"

#include <QSharedPointer>

class TimeSeies;

class LoadOperation : public Operation
{
public:
    LoadOperation();

    // Operation interface
public:
    OperationType type() const;
    OperationStatus status() const;
    void setStatus(const OperationStatus &status);

    QString fileName() const;
    void setFileName(const QString &fileName);

    QSharedPointer<TimeSeies> loadedTimeSeries() const;
    void setLoadedTimeSeries(const QSharedPointer<TimeSeies> &loadedTimeSeries);

private:
    OperationStatus m_status;

    QString m_fileName;
    QSharedPointer<TimeSeies> m_loadedTimeSeries;
};

#endif // LOADOPERATION_H
