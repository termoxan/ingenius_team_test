#ifndef OPERATION_H
#define OPERATION_H

#include <QSharedPointer>

enum class OperationType
{
    Initialize = 0,
    Save,
    Load,
    Analize
};

class OperationSettings;
class OperationData;
class OperationStatus;

class Operation
{
public:
    Operation(OperationType type, QSharedPointer<OperationSettings> settings);

    OperationType type() const;

    QSharedPointer<OperationSettings> settings() const;
    QSharedPointer<OperationData> data() const;
    QSharedPointer<OperationStatus> status() const;

private:
    OperationType m_type;
    QSharedPointer<OperationSettings> m_settings;
    QSharedPointer<OperationData> m_data;
    QSharedPointer<OperationStatus> m_status;
};

#endif // OPERATION_H
