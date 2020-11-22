#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>

#include <QSharedPointer>
#include <QVector>

#include "TimeItem.h"


class LoadOperation;

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseManager(QObject *parent = nullptr);

signals:
    void dataSaved(QSharedPointer<LoadOperation> operation,
                   bool result, const QString &message);

public slots:
    void savingData(QSharedPointer<LoadOperation> operation,
                    QVector<TimeItem> points);


};

#endif // DATABASEMANAGER_H
