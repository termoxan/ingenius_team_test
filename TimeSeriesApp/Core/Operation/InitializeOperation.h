#ifndef INITIALIZEOPERATION_H
#define INITIALIZEOPERATION_H

#include "Operation.h"
#include "OperationStatus.h"

class InitializeOperation : public Operation
{
public:
    InitializeOperation();

    // Operation interface
public:
    OperationType type() const;
    OperationStatus status() const;
    void setStatus(const OperationStatus &status);

private:
    OperationStatus m_status;
};

#endif // INITIALIZEOPERATION_H
