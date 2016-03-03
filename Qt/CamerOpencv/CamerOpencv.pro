#-------------------------------------------------
#
# Project created by QtCreator 2016-01-28T17:11:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CamerOpencv
TEMPLATE = app
#openCV 安装路径

  INCLUDEPATH += /usr/local/include/opencv

   LIBS += /usr/local/lib/libcv.so \

            /usr/local/lib/libhighgui.so \

            /usr/local/lib/libcxcore.so \
#

SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    dialog.h

FORMS    += mainwindow.ui \
    dialog.ui
