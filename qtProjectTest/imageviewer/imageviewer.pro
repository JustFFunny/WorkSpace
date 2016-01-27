QT += widgets
qtHaveModule(printsupport): QT += printsupport

HEADERS       = imageviewer.h
SOURCES       = imageviewer.cpp \
                main.cpp

TRANSLATIONS =qiankun_zh_cn.ts
# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/widgets/imageviewer
INSTALLS += target


wince*: {
   DEPLOYMENT_PLUGIN += qjpeg qgif
}

RESOURCES += \
    src.qrc
