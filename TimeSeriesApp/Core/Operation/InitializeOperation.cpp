#include "InitializeOperation.h"

InitializeOperation::InitializeOperation()
{

}

OperationType InitializeOperation::type() const
{
    return OperationType::Initialize;
}

OperationStatus InitializeOperation::status() const
{
    return m_status;
}

void InitializeOperation::setStatus(const OperationStatus &status)
{
    m_status = status;
}
