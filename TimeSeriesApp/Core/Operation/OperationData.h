#ifndef OPERATIONDATA_H
#define OPERATIONDATA_H

#include <QWeakPointer>

class Operation;

class OperationData
{
public:
    explicit OperationData(QSharedPointer<Operation> operation);

    QSharedPointer<Operation> operation() const;

private:
    QWeakPointer<Operation> m_operation;
};

#endif // OPERATIONDATA_H
