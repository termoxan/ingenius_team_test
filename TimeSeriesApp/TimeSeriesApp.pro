QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += \
    Core/Operation/InitializeSettings.cpp \
    Core/Operation/LoadData.cpp \
    Core/Operation/LoadSettings.cpp \
    Core/Operation/Operation.cpp \
    Core/Operation/OperationData.cpp \
    Core/Operation/OperationResult.cpp \
    Core/Operation/OperationSettings.cpp \
    Core/Operation/OperationStatus.cpp \
    Core/Operation/SaveSettings.cpp \
    Core/TimeItem.cpp \
    Core/TimeSeries.cpp \
    main.cpp \
    Gui/TimeSeriesMainWindow.cpp

HEADERS += \
    Core/Operation/InitializeSettings.h \
    Core/Operation/LoadData.h \
    Core/Operation/LoadSettings.h \
    Core/Operation/Operation.h \
    Core/Operation/OperationData.h \
    Core/Operation/OperationResult.h \
    Core/Operation/OperationSettings.h \
    Core/Operation/OperationStatus.h \
    Core/Operation/SaveSettings.h \
    Core/TimeItem.h \
    Core/TimeSeries.h \
    Gui/TimeSeriesMainWindow.h

FORMS += \
    Gui/TimeSeriesMainWindow.ui


