#-------------------------------------------------
#
# Project created by QtCreator 2016-03-14T11:52:31
#
#-------------------------------------------------

QT       += widgets network

TARGET = SingleApplication
TEMPLATE = lib

DEFINES += SINGLEAPPLICATION_LIBRARY

SOURCES += singleapplication.cpp

HEADERS += singleapplication.h\
        singleapplication_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
