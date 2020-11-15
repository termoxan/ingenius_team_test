#ifndef OPERATIONSTATUS_H
#define OPERATIONSTATUS_H

#include <QWeakPointer>

class Operation;

class OperationStatus
{
public:
    explicit OperationStatus(QSharedPointer<Operation> operation, quint8 progress = 0, const QString message = "");

    QSharedPointer<Operation> operation() const;

    quint8 progress() const;
    void setProgress(quint8 progress);

    QString message() const;
    void setMessage(const QString &message);

private:
    QWeakPointer<Operation> m_operation;
    quint8 m_progress;
    QString m_message;
};

#endif // OPERATIONSTATUS_H
