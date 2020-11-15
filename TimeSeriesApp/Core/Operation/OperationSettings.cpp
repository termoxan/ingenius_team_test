#include "OperationSettings.h"

OperationSettings::OperationSettings(QSharedPointer<Operation> operation) :
    m_operation(operation.toWeakRef())
{

}

QSharedPointer<Operation> OperationSettings::operation() const
{
    return m_operation.toStrongRef();
}
