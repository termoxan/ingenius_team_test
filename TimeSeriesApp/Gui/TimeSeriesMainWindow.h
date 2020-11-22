#ifndef TIMESERIESMAINWINDOW_H
#define TIMESERIESMAINWINDOW_H

#include <QMainWindow>

#include <QScopedPointer>
#include "Core/TimeSeriesApplicationCore.h"

#include "Core/Operation/OperationStatus.h"
#include "Core/Operation/OperationResult.h"

class OperationDialog;

QT_BEGIN_NAMESPACE
namespace Ui { class TimeSeriesMainWindow; }
QT_END_NAMESPACE

class TimeSeriesMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    TimeSeriesMainWindow(QWidget *parent = nullptr);
    ~TimeSeriesMainWindow();

private slots:
    void processLoadClicked();

    void processOperationStarted(QSharedPointer<Operation> operation,
                          OperationStatus status);
    void processOperationFinished(QSharedPointer<Operation> operation,
                           OperationResult result);

private:
    Ui::TimeSeriesMainWindow *ui;

    QScopedPointer<TimeSeriesApplicationCore> m_core;

    OperationDialog *m_operationDialog;
};
#endif // TIMESERIESMAINWINDOW_H
