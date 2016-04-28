#-------------------------------------------------
#
# Project created by QtCreator 2016-03-14T11:45:29
#
#-------------------------------------------------

QT       += widgets network

TARGET = SharedLibrary
TEMPLATE = lib

DEFINES += SHAREDLIBRARY_LIBRARY

SOURCES += sharedlibrary.cpp

HEADERS += sharedlibrary.h\
        sharedlibrary_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
