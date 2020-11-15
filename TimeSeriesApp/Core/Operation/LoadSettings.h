#ifndef LOADSETTINGS_H
#define LOADSETTINGS_H

#include "OperationSettings.h"

class LoadSettings : public OperationSettings
{
public:
    explicit LoadSettings(QSharedPointer<Operation> operation, const QString &fileName);

    QString fileName() const;
    void setFileName(const QString &fileName);

private:
    QString m_fileName;
};

#endif // LOADSETTINGS_H
