#ifndef LOADOPERATION_H
#define LOADOPERATION_H

#include "Operation.h"
#include "OperationStatus.h"

#include <QSharedPointer>

class TimeSeries;

class LoadOperation : public Operation
{
public:
    explicit LoadOperation(const QString &fileName);

    // Operation interface
public:
    OperationType type() const;
    OperationStatus status() const;
    void setStatus(const OperationStatus &status);

    QString fileName() const;
    void setFileName(const QString &fileName);

    QSharedPointer<TimeSeries> loadedTimeSeries() const;
    void setLoadedTimeSeries(const QSharedPointer<TimeSeries> &loadedTimeSeries);

private:
    OperationStatus m_status;

    QString m_fileName;
    QSharedPointer<TimeSeries> m_loadedTimeSeries;
};

#endif // LOADOPERATION_H
