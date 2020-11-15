#include "InitializeSettings.h"

InitializeSettings::InitializeSettings(QSharedPointer<Operation> operation, const QString &sqliteFileName) :
    OperationSettings(operation),
    m_sqliteFileName(sqliteFileName)
{

}

QString InitializeSettings::sqliteFileName() const
{
    return m_sqliteFileName;
}

void InitializeSettings::setSqliteFileName(const QString &sqliteFileName)
{
    m_sqliteFileName = sqliteFileName;
}
