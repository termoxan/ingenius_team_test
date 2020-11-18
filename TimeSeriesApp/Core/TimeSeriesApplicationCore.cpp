#include "TimeSeriesApplicationCore.h"

#include "Operation/SaveOperation.h"
#include "Operation/LoadOperation.h"
#include "Operation/OperationResult.h"

#include "TimeSeries.h"

#include <QDebug>

TimeSeriesApplicationCore::TimeSeriesApplicationCore(QObject *parent) :
    QObject(parent),
    m_dataLoader(new DataLoader())
{

}

QSharedPointer<Operation> TimeSeriesApplicationCore::createSaveOperation(const QString &savedFileName,
                                                                         const QSharedPointer<TimeSeries> &timeSeries) const
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
    switch (operation->type())
    {
        case OperationType::Save:
        case OperationType::Load:
        {
            m_dataLoader->stopOperation(operation);
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
