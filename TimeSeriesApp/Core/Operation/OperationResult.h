#ifndef OPERATIONRESULT_H
#define OPERATIONRESULT_H

#include <QSharedPointer>

class Operation;

class OperationResult
{
public:
    explicit OperationResult(QSharedPointer<Operation> operation,
                             bool result, const QString &message);

    QSharedPointer<Operation> operation() const;

    bool result() const;
    void setResult(bool result);

    QString message() const;
    void setMessage(const QString &message);

private:
    QSharedPointer<Operation> m_operation;
    bool m_bResult;
    QString m_message;
};

#endif // OPERATIONRESULT_H
