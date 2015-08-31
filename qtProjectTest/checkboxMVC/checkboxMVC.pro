#-------------------------------------------------
#
# Project created by QtCreator 2015-08-20T16:56:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = checkboxMVC
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    studentinfomodel.cpp \
    dewidget.cpp \
    widgetdelegate.cpp

HEADERS  += mainwindow.h \
    studentinfomodel.h \
    dewidget.h \
    widgetdelegate.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
