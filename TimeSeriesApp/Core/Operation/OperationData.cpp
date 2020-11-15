#include "OperationData.h"

OperationData::OperationData(QSharedPointer<Operation> operation) :
    m_operation(operation.toWeakRef())
{

}

QSharedPointer<Operation> OperationData::operation() const
{
    return m_operation.toStrongRef();
}
