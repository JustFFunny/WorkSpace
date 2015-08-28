#-------------------------------------------------
#
# Project created by QtCreator 2015-08-14T09:53:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mvTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mytablemodel.cpp \
    comwidget.cpp

HEADERS  += mainwindow.h \
    mytablemodel.h \
    comwidget.h

FORMS    += mainwindow.ui
