#include "DatabaseManager.h"

#include <QDebug>
#include <QThread>

DatabaseManager::DatabaseManager(QObject *parent) : QObject(parent)
{

}

void DatabaseManager::savingData(QSharedPointer<LoadOperation> operation,
                                 QVector<TimeItem> points)
{
    qDebug().noquote() << Q_FUNC_INFO << "thread id: " << QThread::currentThreadId();

    Q_UNUSED(operation);

    for(const TimeItem &item: points)
    {
        qDebug().noquote() << "number: " << item.index() << " value: " << item.value();
    }

    emit dataSaved(operation, true, "");
}
