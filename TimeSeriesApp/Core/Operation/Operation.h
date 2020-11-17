#ifndef OPERATION_H
#define OPERATION_H

enum class OperationType
{
    Initialize = 0,
    Save,
    Load,
    Analize
};

class OperationStatus;

class Operation
{
public:
    Operation() {}
    virtual ~Operation() {}

    virtual OperationType type() const = 0;
    virtual OperationStatus status() const = 0;
    virtual void setStatus(const OperationStatus &status) = 0;
};

#endif // OPERATION_H
