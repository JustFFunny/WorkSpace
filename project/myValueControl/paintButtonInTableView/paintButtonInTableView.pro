#-------------------------------------------------
#
# Project created by QtCreator 2015-08-26T16:53:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = paintButtonInTableView
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    buttondelegate.cpp \
    tablemodel.cpp \
    tableview.cpp

HEADERS  += mainwindow.h \
    buttondelegate.h \
    tablemodel.h \
    tableview.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
