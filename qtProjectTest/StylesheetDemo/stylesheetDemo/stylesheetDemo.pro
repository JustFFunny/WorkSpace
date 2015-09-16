#-------------------------------------------------
#
# Project created by QtCreator 2010-10-14T15:08:01
#
#-------------------------------------------------

QT       += core gui

QT += webkit network


TARGET = stylesheetDemo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

symbian {
    TARGET.UID3 = 0xe40da709
    TARGET.CAPABILITY += NetworkServices
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x0200000 0x8000000
}

RESOURCES += \
    stylesheetDemo.qrc
