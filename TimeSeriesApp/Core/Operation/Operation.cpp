#include "Operation.h"

#include "OperationSettings.h"
#include "OperationStatus.h"
#include "LoadData.h"
#include "../TimeSeries.h"


Operation::Operation(OperationType type, QSharedPointer<OperationSettings> settings) :
    m_type(type),
    m_settings(settings)
{
    m_status = QSharedPointer<OperationStatus>::create(QSharedPointer<Operation>(this));

    switch (m_type)
    {
        case OperationType::Initialize:
        {
            break;
        }
        case OperationType::Save:
        {
            break;
        }
        case OperationType::Load:
        {
            m_data = QSharedPointer<LoadData>::create(QSharedPointer<Operation>(this), QSharedPointer<TimeSeries>::create(NEW_ITEM_ID, 0));
            break;
        }
        case OperationType::Analize:
        {
            Q_ASSERT(false);
            break;
        }
    }
}

OperationType Operation::type() const
{
    return m_type;
}

QSharedPointer<OperationSettings> Operation::settings() const
{
    return m_settings;
}

QSharedPointer<OperationData> Operation::data() const
{
    return m_data;
}

QSharedPointer<OperationStatus> Operation::status() const
{
    return m_status;
}
