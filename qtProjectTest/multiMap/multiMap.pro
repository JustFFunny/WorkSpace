#-------------------------------------------------
#
# Project created by QtCreator 2015-10-19T09:40:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = multiMap
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    exercisewidget.cpp \
    testwidget.cpp

HEADERS  += mainwindow.h \
    exercisewidget.h \
    testwidget.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
