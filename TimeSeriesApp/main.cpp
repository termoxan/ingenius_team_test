#include "Gui/TimeSeriesMainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TimeSeriesMainWindow w;
    w.show();
    return a.exec();
}
