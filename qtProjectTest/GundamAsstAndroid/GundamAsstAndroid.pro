QT += network
QT += declarative

HEADERS += \
    widgets/videowidget.h \
    widgets/shellwidget.h \
    widgets/settingswidget.h \
    widgets/screenshotwidget.h \
    widgets/recoverywidget.h \
    widgets/phoneinfowidget.h \
    widgets/messagewidget.h \
    widgets/imagewidget.h \
    widgets/filewidget.h \
    widgets/fastbootwidget.h \
    widgets/audiowidget.h \
    widgets/appwidget.h \
    classes/models/messagethreadmodel.h \
    classes/models/messagemodel.h \
    classes/models/logcatmodel.h \
    classes/models/filetablemodel.h \
    classes/models/contactmodel.h \
    classes/models/backuptablemodel.h \
    classes/models/apptablemodel.h \
    classes/updateapp.h \
    classes/phone.h \
    classes/ecwin7.h \
    classes/computer.h \
    classes/application.h \
    classes/animation.h \
    classes/androidapk.h \
    dialogs/registerdialog.h \
    dialogs/mainwindow.h \
    dialogs/logcatdialog.h \
    dialogs/dialogkopiuj.h \
    dialogs/connectWifi.h \
    dialogs/appinfo.h \
    dialogs/appdialog.h \
    dialogs/aboutdialog.h \
    threads/videothread.h \
    threads/thumbnailthread.h \
    threads/screenshotthread.h \
    threads/imagethread.h \
    threads/audiothread.h \
    classes/mytableview.h \
    threads/socketthread.h \
    widgets/applicationwidget.h \
    widgets/contactwidget.h \
    dialogs/contactdialog.h \
    threads/conthread.h \
    widgets/imagelistwidget.h

SOURCES += \
    widgets/videowidget.cpp \
    widgets/shellwidget.cpp \
    widgets/settingswidget.cpp \
    widgets/screenshotwidget.cpp \
    widgets/recoverywidget.cpp \
    widgets/phoneinfowidget.cpp \
    widgets/messagewidget.cpp \
    widgets/imagewidget.cpp \
    widgets/filewidget.cpp \
    widgets/fastbootwidget.cpp \
    widgets/audiowidget.cpp \
    widgets/appwidget.cpp \
    classes/models/messagethreadmodel.cpp \
    classes/models/messagemodel.cpp \
    classes/models/logcatmodel.cpp \
    classes/models/filetablemodel.cpp \
    classes/models/contactmodel.cpp \
    classes/models/backuptablemodel.cpp \
    classes/models/apptablemodel.cpp \
    classes/updateapp.cpp \
    classes/phone.cpp \
    classes/ecwin7.cpp \
    classes/computer.cpp \
    classes/application.cpp \
    classes/animation.cpp \
    classes/androidapk.cpp \
    dialogs/registerdialog.cpp \
    dialogs/mainwindow.cpp \
    dialogs/logcatdialog.cpp \
    dialogs/dialogkopiuj.cpp \
    dialogs/connectWifi.cpp \
    dialogs/appinfo.cpp \
    dialogs/appdialog.cpp \
    dialogs/aboutdialog.cpp \
    threads/videothread.cpp \
    threads/thumbnailthread.cpp \
    threads/screenshotthread.cpp \
    threads/imagethread.cpp \
    threads/audiothread.cpp \
    main.cpp \
    classes/mytableview.cpp \
    threads/socketthread.cpp \
    widgets/applicationwidget.cpp \
    widgets/contactwidget.cpp \
    dialogs/contactdialog.cpp \
    threads/conthread.cpp \
    widgets/imagelistwidget.cpp

FORMS += \
    widgets/videowidget.ui \
    widgets/shellwidget.ui \
    widgets/settingswidget.ui \
    widgets/screenshotwidget.ui \
    widgets/recoverywidget.ui \
    widgets/phoneinfowidget.ui \
    widgets/messagewidget.ui \
    widgets/imagewidget.ui \
    widgets/filewidget.ui \
    widgets/fastbootwidget.ui \
    widgets/audiowidget.ui \
    widgets/appwidget.ui \
    dialogs/registerdialog.ui \
    dialogs/mainwindow.ui \
    dialogs/logcatdialog.ui \
    dialogs/dialogkopiuj.ui \
    dialogs/connectWifi.ui \
    dialogs/appinfo.ui \
    dialogs/appdialog.ui \
    dialogs/aboutdialog.ui \
    widgets/applicationwidget.ui \
    widgets/contactwidget.ui \
    dialogs/contactdialog.ui \
    widgets/imagelistwidget.ui

RESOURCES += \
    zasoby.qrc

OTHER_FILES += \
    qml/messageView.qml \
    qml/messages/delegates/ThreadDelegate.qml \
    qml/messages/delegates/ThreadContextMenu.qml \
    qml/messages/delegates/SendSmsButton.qml \
    qml/messages/delegates/SendMessage.qml \
    qml/messages/delegates/ScrollBar.qml \
    qml/messages/delegates/MessageDelegate.qml \
    qml/messages/delegates/ContactDelegate.qml \
    qml/messages/delegates/Button.qml \
    qml/messages/ThreadList.qml \
    qml/messages/NewMessage.qml \
    qml/messages/MessageList.qml \
    qml/messages/ContactList.qml

TRANSLATIONS += languages/qtadb_en.ts languages/qtadb_zh.ts
