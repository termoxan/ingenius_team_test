#ifndef TIMESERIESAPPLICATIONCORE_H
#define TIMESERIESAPPLICATIONCORE_H

#include <QObject>
#include <QSharedPointer>

#include "DataLoader.h"
#include "DatabaseManager.h"

class Operation;
class OperationResult;
class OperationStatus;

class TimeSeries;

class TimeSeriesApplicationCore : public QObject
{
    Q_OBJECT
public:
    explicit TimeSeriesApplicationCore(QObject *parent = nullptr);

    QSharedPointer<Operation> createSaveOperation(const QString &savedFileName,
                                                  const QWeakPointer<TimeSeries> &timeSeries) const;

    QSharedPointer<Operation> createLoadOperation(const QString &loadedFileName) const;


    OperationResult startOperation(const QSharedPointer<Operation> &operation) const;
    void stopOperation(const QSharedPointer<Operation> &operation) const;

signals:
    void operationStarted(QSharedPointer<Operation> operation, OperationStatus status);
    void operationFinished(QSharedPointer<Operation> operation, OperationResult result);

private:
    QScopedPointer<DataLoader> m_dataLoader;
    QScopedPointer<DatabaseManager> m_databaseManager;
};

#endif // TIMESERIESAPPLICATIONCORE_H
