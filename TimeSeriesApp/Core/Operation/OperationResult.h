#ifndef OPERATIONRESULT_H
#define OPERATIONRESULT_H

#include <QString>

class OperationResult
{
public:
    explicit OperationResult(bool result = true, const QString &message = QString());

    bool result() const;
    void setResult(bool result);

    QString message() const;
    void setMessage(const QString &message);

private:
    bool m_bResult;
    QString m_message;
};

#endif // OPERATIONRESULT_H
