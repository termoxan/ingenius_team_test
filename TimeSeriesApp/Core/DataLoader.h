#ifndef DATALOADER_H
#define DATALOADER_H

#include <QObject>
#include <QSharedPointer>
#include <QScopedPointer>

#include <QFile>
#include <QThread>

#include "Operation/OperationResult.h"
#include "Operation/OperationStatus.h"

#include <QMetaType>

#include "TimeItem.h"

class Operation;
class LoadOperation;
class OperationResult;
class TimeSeries;

class DataLoader : public QObject
{
    Q_OBJECT
public:
    explicit DataLoader(QObject *parent = nullptr);

    OperationResult startOperation(const QSharedPointer<Operation> &operation);
    void stopOperation(const QSharedPointer<Operation> &operation, const OperationResult &result);

signals:
    void needSaveData(QSharedPointer<LoadOperation> operation,
                      QVector<TimeItem> points);

    void operationStarted(QSharedPointer<Operation> operation,
                          OperationStatus status);
    void operationFinished(QSharedPointer<Operation> operation,
                           OperationResult result);

public slots:
    void processDataSaved(QSharedPointer<Operation> operation, bool result, const QString &message);

private slots:
    void runOperation();
    void finishOperation();

    void runLoadingData();

    void runSavingData();


private:
    QString extractFileName(const QSharedPointer<Operation> &operation) const;

private:
    QSharedPointer<Operation> m_currentOperation;

    QScopedPointer<QFile> m_file;
    QScopedPointer<QThread> m_thread;

    bool m_bOperationStoped;
    OperationResult m_operationResult;
};

#endif // DATALOADER_H
