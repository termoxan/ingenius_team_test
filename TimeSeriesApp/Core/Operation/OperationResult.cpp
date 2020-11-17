#include "OperationResult.h"

OperationResult::OperationResult(bool result, const QString &message) :
    m_bResult(result),
    m_message(message)
{

}

bool OperationResult::result() const
{
    return m_bResult;
}

void OperationResult::setResult(bool result)
{
    m_bResult = result;
}

QString OperationResult::message() const
{
    return m_message;
}

void OperationResult::setMessage(const QString &message)
{
    m_message = message;
}
