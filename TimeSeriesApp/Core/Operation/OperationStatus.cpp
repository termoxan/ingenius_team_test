#include "OperationStatus.h"


OperationStatus::OperationStatus(QSharedPointer<Operation> operation, quint8 progress,
                                 const QString message) :
    m_operation(operation.toWeakRef()),
    m_progress(progress),
    m_message(message)
{

}

QSharedPointer<Operation> OperationStatus::operation() const
{
    return m_operation.toStrongRef();
}

quint8 OperationStatus::progress() const
{
    return m_progress;
}

void OperationStatus::setProgress(quint8 progress)
{
    m_progress = progress;
}

QString OperationStatus::message() const
{
    return m_message;
}

void OperationStatus::setMessage(const QString &message)
{
    m_message = message;
}
