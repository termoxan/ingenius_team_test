#include "DataLoader.h"

#include "Operation/SaveOperation.h"
#include "Operation/LoadOperation.h"

#include "Operation/OperationResult.h"

#include "TimeSeries.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <QDebug>

const QString SERIAL = "serial";
const QString SERIAL_ID = "serial_id";
const QString POINTS_COUNT = "points_count";
const QString LAST_POINT_NUMBER = "last_point_number";
const QString POINTS = "points";
const QString NUMBER = "number";
const QString VALUE = "value";

DataLoader::DataLoader(QObject *parent) :
    QObject(parent),
    m_file(new QFile()),
    m_thread(new QThread()),
    m_bOperationStoped(false)
{
    this->moveToThread(m_thread.data());

    qRegisterMetaType<QSharedPointer<Operation>>("QSharedPointer<Operation>");
    qRegisterMetaType<OperationStatus>("OperationStatus");
    qRegisterMetaType<OperationResult>("OperationResult");

    /* Настраиваем запуск/остановку потока. */
    connect (&*m_thread,    &QThread::started,
             this,          &DataLoader::runOperation);
    connect (&*m_thread,    &QThread::finished,
             this,          &DataLoader::finishOperation);
}

OperationResult DataLoader::startOperation(const QSharedPointer<Operation> &operation)
{
    qDebug().noquote() << Q_FUNC_INFO << "thread id: " << QThread::currentThreadId();
    OperationResult result;

    if (!operation)
    {
        result.setResult(false);
        result.setMessage(QString::fromUtf8("Не задана операция"));

        return result;
    }

    m_bOperationStoped = false;

    QString fileName = extractFileName(operation);

    m_file->setFileName(fileName);

    OperationStatus status;

    /* Подготавливаем файл. Проверяем возможно ли открыть его для записи/чтения
     * и существует ли он вообще. */
    switch (operation->type())
    {
        case OperationType::Save:
        {
            if (!m_file->open(QIODevice::WriteOnly))
            {
                result.setResult(false);
                result.setMessage(QString::fromUtf8("Не удалось создать файл %0: %1")
                                  .arg(m_file->fileName()).arg(m_file->errorString()));
                m_file->setFileName("");

                return result;
            }

            status.setMessage(QString::fromUtf8("Запись данных в файл %0").arg(fileName));

            break;
        }
        case OperationType::Load:
        {
            if (!m_file->exists())
            {
                result.setResult(false);
                result.setMessage(QString::fromUtf8("Не найден файл %0").arg(fileName));
                m_file->setFileName("");

                return result;
            }

            if (!m_file->open(QIODevice::ReadOnly))
            {
                result.setResult(false);
                result.setMessage(QString::fromUtf8("Не удалось открыть файл %0: %1")
                                  .arg(m_file->fileName()).arg(m_file->errorString()));
                m_file->setFileName("");

                return result;
            }

            status.setMessage(QString::fromUtf8("Чтение данных файла %0").arg(fileName));

            break;
        }
        default:
        {
            result.setResult(false);
            result.setMessage(QString::fromUtf8("Операция не поддерживается"));

            m_file->setFileName("");

            return result;
        }
    }

    /* Подготовка файла прошла успешно, теперь приступаем к самой операции. */

    operation->setStatus(status);

    m_currentOperation = operation;

    m_thread->start();

    return result;
}

void DataLoader::stopOperation(const QSharedPointer<Operation> &operation,
                               const OperationResult &result)
{
    qDebug().noquote() << Q_FUNC_INFO << "thread id: " << QThread::currentThreadId();

    if (m_currentOperation != operation)
    {
        qDebug().noquote() << "Unknown operation";
        return;
    }

    m_bOperationStoped = true;
    m_operationResult = result;

    /* Останавливаем операцию. */
    m_thread->exit();
}

void DataLoader::processDataSaved(QSharedPointer<Operation> operation, bool result, const QString &message)
{
    qDebug().noquote() << Q_FUNC_INFO << "thread id: " << QThread::currentThreadId();

    /* В текущей реализации вызовется один раз. */
    m_operationResult.setResult(result);
    m_operationResult.setMessage(message);

    /* Поэтому просто вызовем завершение операции. */
    stopOperation(operation, m_operationResult);
}

void DataLoader::runOperation()
{
    qDebug().noquote() << Q_FUNC_INFO << "thread id: " << QThread::currentThreadId();

    emit operationStarted(m_currentOperation, m_currentOperation->status());

    /* Выполняется после запуска потока. */
    if (m_currentOperation->type() == OperationType::Load)
    {
        runLoadingData();
    }
    else
    {
        runSavingData();
    }
}

void DataLoader::finishOperation()
{
    /* Выполняется после завершения потока. */

    /* Закрываем файл. */
    m_file->close();

    /* Уведомляем о результате завершения операции. */
    emit operationFinished(m_currentOperation, m_operationResult);

    /* Очищаем текущую операцию. */
    m_currentOperation.clear();
}

void DataLoader::runLoadingData()
{
    qDebug().noquote() << Q_FUNC_INFO << "thread id: " << QThread::currentThreadId();

    /* Выполняется после запуска потока. */
    QTextStream stream(m_file.data());

    /* Считываем все данные. */
    /// @todo Реализовать полноценный парсинг данных, т.к. теоретически объем данных
    /// может быть слишком большим. В целом DOM подход для чтения не подходит. Нужен SAX.
    /// В перспективе можно использоваь RapidJSON SAX Writer http://rapidjson.org/md_doc_sax.html
    QString buffer = stream.readAll();

    qDebug().noquote() << "json:\n" << buffer;

    QJsonParseError error;
    QJsonDocument document = QJsonDocument::fromJson(buffer.toLocal8Bit(), &error);

    if (document.isNull())
    {
        /* Ошибка преобразования данных. */

        /* Завершить выполнение операции. */
        return;
    }

    /* Работает с вариантом, когда в json хранится только один временной ряд. */
    QJsonObject rootObject = document.object();

    QJsonObject serialObject = rootObject[SERIAL].toObject();

    /* Для начала получим основные данные временного ряда. */

    /* На первой итерации без проверки валидности данных. */
    quint64 id = serialObject[SERIAL_ID].toString().toULongLong();

    quint64 pointsCount = serialObject[POINTS_COUNT].toString().toULongLong();

    quint64 lastPointNumber = serialObject[LAST_POINT_NUMBER].toString().toULongLong();

    qDebug().noquote() << "id: " << id << " points count: " << pointsCount << "last point number: " << lastPointNumber;

    QJsonArray pointsArray = serialObject[POINTS].toArray();

    qDebug().noquote() << "points array: " << pointsArray;

    QVector<TimeItem> points(pointsCount);

    quint64 index = 0;

    /* Считываем данные временного ряда. */
    /* На первой итерации мы будем отправлять все данные сразу. */
    for (const QJsonValueRef &valueRef: pointsArray)
    {
        QJsonObject object = valueRef.toObject();

        quint64 pointNumber = object[NUMBER].toString().toULongLong();
        qint32 pointValue = object[VALUE].toInt();

        qDebug().noquote() << "number: " << pointNumber << " value: " << pointValue;

        TimeItem &item = points[index];

        item.setIndex(pointNumber);
        item.setValue(pointValue);

        ++index;

        /* Преждевременное завершение операции. */
        if (m_bOperationStoped)
        {
            return;
        }
    }

    if (index != pointsCount)
    {
        /* Неверно задан заголовок ряда: различается количество эллементов. */
        qDebug().noquote() << QString::fromUtf8("Количество точек ряда из заголовка: %0. Реальное количество точек: %1")
                              .arg(pointsCount).arg(index);
    }

    /* Создаем временной ряд, который будем сохранять в БД. */
    auto timeSeries = QSharedPointer<TimeSeries>::create(id, lastPointNumber + 1);

    auto loadOperation = qSharedPointerCast<LoadOperation>(m_currentOperation);

    loadOperation->setLoadedTimeSeries(timeSeries);

    /* Заснуть на 2 сек. */
    QThread::currentThread()->sleep(2);

    /* Уведомляем о наличии данных для записи в БД. */
    emit needSaveData(loadOperation, qMove(points));
}

void DataLoader::runSavingData()
{
    /// @todo Реализовать.
}

QString DataLoader::extractFileName(const QSharedPointer<Operation> &operation) const
{
    QString fileName;

    switch (operation->type())
    {
        case OperationType::Save:
        {
            auto saveOperation = qSharedPointerCast<SaveOperation>(operation);

            if (saveOperation)
            {
                fileName = saveOperation->fileName();
            }
            break;
        }
        case OperationType::Load:
        {
            auto loadOperation = qSharedPointerCast<LoadOperation>(operation);

            if (loadOperation)
            {
                fileName = loadOperation->fileName();
            }
            break;
        }
        default:
            break;
    }

    return fileName;
}
