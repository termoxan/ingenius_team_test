#include "TimeSeriesApplicationCore.h"

#include "Operation/SaveOperation.h"
#include "Operation/LoadOperation.h"
#include "Operation/OperationResult.h"
#include "Operation/OperationStatus.h"

#include "TimeSeries.h"
#include "TimeItem.h"

#include <QDebug>

TimeSeriesApplicationCore::TimeSeriesApplicationCore(QObject *parent) :
    QObject(parent),
    m_dataLoader(new DataLoader()),
    m_databaseManager(new DatabaseManager())
{
    qRegisterMetaType<QSharedPointer<LoadOperation>>("QSharedPointer<LoadOperation>");
    qRegisterMetaType<QVector<TimeItem>>(" QVector<TimeItem>");

    /* Настройка взаимодействия между загрузчиком данных и менеджером БД. */
    connect (&*m_dataLoader,        &DataLoader::needSaveData,
             &*m_databaseManager,   &DatabaseManager::savingData,
             Qt::QueuedConnection);

    connect (&*m_databaseManager,   &DatabaseManager::dataSaved,
             &*m_dataLoader,        &DataLoader::processDataSaved,
             Qt::QueuedConnection);

    /* Перенаправление уведомлений о запуске и остановке операции. */
    connect (&*m_dataLoader,    &DataLoader::operationStarted,
             this,              &TimeSeriesApplicationCore::operationStarted);
    connect (&*m_dataLoader,    &DataLoader::operationFinished,
             this,              &TimeSeriesApplicationCore::operationFinished);
}

QSharedPointer<Operation> TimeSeriesApplicationCore::createSaveOperation(const QString &savedFileName,
                                                                         const QWeakPointer<TimeSeries> &timeSeries) const
{
    auto operation = QSharedPointer<SaveOperation>::create(savedFileName, timeSeries);

    return operation;
}

QSharedPointer<Operation> TimeSeriesApplicationCore::createLoadOperation(const QString &loadedFileName) const
{
    auto operation = QSharedPointer<LoadOperation>::create(loadedFileName);

    return operation;
}

OperationResult TimeSeriesApplicationCore::startOperation(const QSharedPointer<Operation> &operation) const
{
    qDebug().noquote() << Q_FUNC_INFO << "thread id: " << QThread::currentThreadId();

    OperationResult result;

    switch (operation->type())
    {
        case OperationType::Save:
        case OperationType::Load:
        {
            result = m_dataLoader->startOperation(operation);
            break;
        }
        case OperationType::Initialize:
        {
            qDebug().noquote() << "can not start unsupported operation";
            result.setResult(false);
            result.setMessage(QString::fromUtf8("Операция не задана"));
            break;
        }
        case OperationType::Analize:
        {
            qDebug().noquote() << "can not start unsupported operation";
            result.setResult(false);
            result.setMessage(QString::fromUtf8("Операция не задана"));
            break;
        }
    }

    return result;
}

void TimeSeriesApplicationCore::stopOperation(const QSharedPointer<Operation> &operation) const
{
    OperationResult result(false, QString::fromUtf8("Прервано пользователем"));

    switch (operation->type())
    {
        case OperationType::Save:
        case OperationType::Load:
        {
            m_dataLoader->stopOperation(operation, result);
            break;
        }
        case OperationType::Initialize:
        {
            qDebug().noquote() << "can not stop unsupported operation";
            break;
        }
        case OperationType::Analize:
        {
            qDebug().noquote() << "can not stop unsupported operation";
            break;
        }
    }
}
