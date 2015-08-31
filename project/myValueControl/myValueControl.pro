#-------------------------------------------------
#
# Project created by QtCreator 2011-11-28T17:02:34
#
#-------------------------------------------------

QT       += core gui

TARGET = myValueControl
TEMPLATE = app


SOURCES += main.cpp\
        frmmain.cpp \
    mygauge1.cpp \
    mygauge2.cpp \
    mygauge3.cpp \
    mygauge4.cpp \
    mygauge5.cpp \
    mygauge6.cpp \
    myprogressbar.cpp \
    mygauge7.cpp \
    mybattery.cpp \
    mycoolbar.cpp \
    mylcdnumber.cpp \
    myindicator.cpp

HEADERS  += frmmain.h \
    mygauge1.h \
    mygauge2.h \
    mygauge3.h \
    mygauge4.h \
    mygauge5.h \
    mygauge6.h \
    myprogressbar.h \
    mygauge7.h \
    mybattery.h \
    mycoolbar.h \
    mylcdnumber.h \
    myindicator.h

FORMS    += frmmain.ui

MOC_DIR=temp/moc
RCC_DIR=temp/rcc
UI_DIR=temp/ui
OBJECTS_DIR=temp/obj

win32:RC_FILE=main.rc
