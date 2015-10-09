TEMPLATE = app

INCLUDEPATH += .
DEPENDPATH += .

win32:CONFIG += console

HEADERS += TagTreeModel.h \
    TreeItem.h

SOURCES += main.cpp \
    TagTreeModel.cpp \
    TreeItem.cpp


