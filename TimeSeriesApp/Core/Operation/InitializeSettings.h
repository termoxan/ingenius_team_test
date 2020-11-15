#ifndef INITIALIZESETTINGS_H
#define INITIALIZESETTINGS_H

#include "OperationSettings.h"

class InitializeSettings : public OperationSettings
{
public:
    explicit InitializeSettings(QSharedPointer<Operation> operation, const QString &sqliteFileName);

    QString sqliteFileName() const;
    void setSqliteFileName(const QString &sqliteFileName);

private:
    QString m_sqliteFileName;
};

#endif // INITIALIZESETTINGS_H
