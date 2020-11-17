QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += \
    Core/Operation/Operation.cpp \
    Core/Operation/OperationResult.cpp \
    Core/Operation/OperationStatus.cpp \
    Core/TimeItem.cpp \
    Core/TimeSeries.cpp \
    main.cpp \
    Gui/TimeSeriesMainWindow.cpp

HEADERS += \
    Core/Operation/Operation.h \
    Core/Operation/OperationResult.h \
    Core/Operation/OperationStatus.h \
    Core/TimeItem.h \
    Core/TimeSeries.h \
    Gui/TimeSeriesMainWindow.h

FORMS += \
    Gui/TimeSeriesMainWindow.ui


