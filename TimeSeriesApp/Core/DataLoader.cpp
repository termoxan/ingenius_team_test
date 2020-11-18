#include "DataLoader.h"

#include "Operation/SaveOperation.h"
#include "Operation/LoadOperation.h"

#include "Operation/OperationResult.h"

#include <QFile>

#include <QDebug>

DataLoader::DataLoader(QObject *parent) : QObject(parent)
{

}

OperationResult DataLoader::startOperation(const QSharedPointer<Operation> &operation)
{
    OperationResult result;

    if (!operation)
    {
        result.setResult(false);
        result.setMessage(QString::fromUtf8("Не задана операция"));

        return result;
    }

    QString fileName = extractFileName(operation);

    m_currentOperation = operation;

    /* Запускаем операцию. */

    return result;
}

void DataLoader::stopOperation(const QSharedPointer<Operation> &operation)
{
    /// @todo Должна выполняться в потоке класса.
    if (m_currentOperation != operation)
    {
        qDebug().noquote() << "Unknown operation";
        return;
    }

    /* Останавливаем операцию. */

    m_currentOperation.clear();
}

QString DataLoader::extractFileName(const QSharedPointer<Operation> &operation) const
{
    QString fileName;

    switch (operation->type())
    {
        case OperationType::Save:
        {
            auto saveOperation = qSharedPointerCast<SaveOperation>(operation);

            if (saveOperation)
            {
                fileName = saveOperation->fileName();
            }
            break;
        }
        case OperationType::Load:
        {
            auto loadOperation = qSharedPointerCast<LoadOperation>(operation);

            if (loadOperation)
            {
                fileName = loadOperation->fileName();
            }
            break;
        }
        default:
            break;
    }

    return fileName;
}
