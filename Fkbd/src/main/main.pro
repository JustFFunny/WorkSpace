include (../../Flags.pri) 

FORMS +=
HEADERS +=  vkbd.h \
            keyboardapplication.h 

SOURCES +=  vkbd.cpp \
	    main.cpp 

unix:SOURCES += keyboardapplication_unix.cpp 
win32*:SOURCES += keyboardapplication_win.cpp

INCLUDEPATH+=../ 
             
win32-msvc2008:LIBS+= user32.lib 

QT += declarative  

MOC_DIR = objects
OBJECTS_DIR = objects
DESTDIR = ../../bin 
CONFIG += resources \
    release \
    warn_on
TARGET = fkbd
TEMPLATE = app

RC_FILE = mainicon.rc
RESOURCES = resources.qrc
