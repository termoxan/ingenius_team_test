#include "LoadSettings.h"

LoadSettings::LoadSettings(QSharedPointer<Operation> operation, const QString &fileName) :
    OperationSettings(operation),
    m_fileName(fileName)
{

}

QString LoadSettings::fileName() const
{
    return m_fileName;
}

void LoadSettings::setFileName(const QString &fileName)
{
    m_fileName = fileName;
}
