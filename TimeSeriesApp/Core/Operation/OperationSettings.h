#ifndef OPERATIONSETTINGS_H
#define OPERATIONSETTINGS_H

#include <QWeakPointer>

class Operation;

class OperationSettings
{
public:
    explicit OperationSettings(QSharedPointer<Operation> operation);

    QSharedPointer<Operation> operation() const;

private:
    QWeakPointer<Operation> m_operation;
};

#endif // OPERATIONSETTINGS_H
