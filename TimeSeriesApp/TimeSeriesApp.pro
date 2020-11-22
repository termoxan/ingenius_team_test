QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += \
    Core/DataLoader.cpp \
    Core/DatabaseManager.cpp \
    Core/Operation/InitializeOperation.cpp \
    Core/Operation/LoadOperation.cpp \
    Core/Operation/OperationResult.cpp \
    Core/Operation/OperationStatus.cpp \
    Core/Operation/SaveOperation.cpp \
    Core/TimeItem.cpp \
    Core/TimeSeries.cpp \
    Core/TimeSeriesApplicationCore.cpp \
    Gui/OperationDialog.cpp \
    main.cpp \
    Gui/TimeSeriesMainWindow.cpp

HEADERS += \
    Core/DataLoader.h \
    Core/DatabaseManager.h \
    Core/Operation/InitializeOperation.h \
    Core/Operation/LoadOperation.h \
    Core/Operation/Operation.h \
    Core/Operation/OperationResult.h \
    Core/Operation/OperationStatus.h \
    Core/Operation/SaveOperation.h \
    Core/TimeItem.h \
    Core/TimeSeries.h \
    Core/TimeSeriesApplicationCore.h \
    Gui/OperationDialog.h \
    Gui/TimeSeriesMainWindow.h

FORMS += \
    Gui/OperationDialog.ui \
    Gui/TimeSeriesMainWindow.ui


