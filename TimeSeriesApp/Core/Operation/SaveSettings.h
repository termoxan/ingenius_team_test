#ifndef SAVESETTINGS_H
#define SAVESETTINGS_H

#include "OperationSettings.h"

class TimeSeries;

class SaveSettings : public OperationSettings
{
public:
    explicit SaveSettings(QSharedPointer<Operation> operation, const QString &fileName,
                          QSharedPointer<TimeSeries> timeSeries);

    QString fileName() const;
    void setFileName(const QString &fileName);

    QSharedPointer<TimeSeries> timeSeries() const;
    void setTimeSeries(QSharedPointer<TimeSeries> timeSeries);

private:
    QString m_fileName;
    QSharedPointer<TimeSeries> m_timeSeries;
};

#endif // SAVESETTINGS_H
