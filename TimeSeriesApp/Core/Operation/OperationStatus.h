#ifndef OPERATIONSTATUS_H
#define OPERATIONSTATUS_H

#include <QString>

class OperationStatus
{
public:
    explicit OperationStatus(quint8 progress = 0, const QString message = "");

    quint8 progress() const;
    void setProgress(quint8 progress);

    QString message() const;
    void setMessage(const QString &message);

private:
    quint8 m_progress;
    QString m_message;
};

#endif // OPERATIONSTATUS_H
