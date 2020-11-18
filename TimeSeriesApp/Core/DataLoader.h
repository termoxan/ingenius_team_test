#ifndef DATALOADER_H
#define DATALOADER_H

#include <QObject>
#include <QSharedPointer>
#include <QScopedPointer>

#include <QFile>

class Operation;
class OperationResult;

class DataLoader : public QObject
{
    Q_OBJECT
public:
    explicit DataLoader(QObject *parent = nullptr);

    OperationResult startOperation(const QSharedPointer<Operation> &operation);
    void stopOperation(const QSharedPointer<Operation> &operation);

private:
    QString extractFileName(const QSharedPointer<Operation> &operation) const;

private:
    QSharedPointer<Operation> m_currentOperation;

    QScopedPointer<QFile> m_file;
};

#endif // DATALOADER_H
