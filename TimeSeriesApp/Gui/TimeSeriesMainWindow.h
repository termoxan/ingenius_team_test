#ifndef TIMESERIESMAINWINDOW_H
#define TIMESERIESMAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class TimeSeriesMainWindow; }
QT_END_NAMESPACE

class TimeSeriesMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    TimeSeriesMainWindow(QWidget *parent = nullptr);
    ~TimeSeriesMainWindow();

private:
    Ui::TimeSeriesMainWindow *ui;
};
#endif // TIMESERIESMAINWINDOW_H
