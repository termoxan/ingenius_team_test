#include "TimeSeriesMainWindow.h"
#include "ui_TimeSeriesMainWindow.h"

TimeSeriesMainWindow::TimeSeriesMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TimeSeriesMainWindow)
{
    ui->setupUi(this);
}

TimeSeriesMainWindow::~TimeSeriesMainWindow()
{
    delete ui;
}

