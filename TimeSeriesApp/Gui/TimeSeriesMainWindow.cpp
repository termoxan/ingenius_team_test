#include "TimeSeriesMainWindow.h"
#include "ui_TimeSeriesMainWindow.h"

#include "OperationDialog.h"
#include "Core/Operation/Operation.h"

#include <QFileDialog>
#include <QMessageBox>

TimeSeriesMainWindow::TimeSeriesMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TimeSeriesMainWindow),
      m_core(new TimeSeriesApplicationCore()),
      m_operationDialog(new OperationDialog(this))
{
    ui->setupUi(this);

    /* Обработка сигналов меню. */
    connect (ui->m_loadAction,  &QAction::triggered,
             this,              &TimeSeriesMainWindow::processLoadClicked);

    /* Обработка выполнения операции. */
    connect (&*m_core,  &TimeSeriesApplicationCore::operationStarted,
             this,      &TimeSeriesMainWindow::processOperationStarted);
    connect (&*m_core,  &TimeSeriesApplicationCore::operationFinished,
             this,      &TimeSeriesMainWindow::processOperationFinished);
}

TimeSeriesMainWindow::~TimeSeriesMainWindow()
{
    delete ui;
}

void TimeSeriesMainWindow::processLoadClicked()
{
    QFileDialog dialog(this);

    int result = dialog.exec();

    if (result != QDialog::Accepted)
    {
        return;
    }

    QString fileName = dialog.selectedFiles().value(0);

    if (fileName.isEmpty())
    {
        return;
    }

    auto operation = m_core->createLoadOperation(fileName);

    OperationResult operationResult = m_core->startOperation(operation);

    if (!operationResult.result())
    {
        QMessageBox::critical(this, QString::fromUtf8("Ошибка загрузки из файла"), operationResult.message());
    }
}

void TimeSeriesMainWindow::processOperationStarted(QSharedPointer<Operation> operation,
                                                   OperationStatus status)
{
    Q_UNUSED(operation)

    m_operationDialog->setMessage(status.message());
    m_operationDialog->setProgress(status.progress());

    m_operationDialog->exec();
}

void TimeSeriesMainWindow::processOperationFinished(QSharedPointer<Operation> operation,
                                                    OperationResult result)
{
    Q_UNUSED(operation)
    Q_UNUSED(result)
    /// @todo Добавить обработку и вывод ошибки.
    m_operationDialog->accept();
}

