/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sat Aug 2 16:57:02 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dialogs/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      39,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      31,   12,   11,   11, 0x08,
      67,   11,   11,   11, 0x08,
     100,   11,   11,   11, 0x08,
     119,   11,   11,   11, 0x08,
     134,   11,   11,   11, 0x08,
     150,   11,   11,   11, 0x08,
     169,   11,   11,   11, 0x08,
     188,   11,   11,   11, 0x08,
     208,   11,   11,   11, 0x08,
     229,   11,   11,   11, 0x08,
     248,   11,   11,   11, 0x08,
     264,   11,   11,   11, 0x08,
     287,   11,   11,   11, 0x08,
     303,   11,   11,   11, 0x08,
     319,   11,   11,   11, 0x08,
     335,   11,   11,   11, 0x08,
     357,   11,   11,   11, 0x08,
     376,   11,   11,   11, 0x08,
     391,   11,   11,   11, 0x08,
     418,  411,   11,   11, 0x08,
     443,   11,   11,   11, 0x08,
     459,   11,   11,   11, 0x08,
     481,  474,   11,   11, 0x08,
     506,  474,   11,   11, 0x08,
     531,   11,   11,   11, 0x08,
     547,   11,   11,   11, 0x08,
     565,  562,   11,   11, 0x08,
     608,   11,   11,   11, 0x08,
     633,  621,   11,   11, 0x08,
     669,  662,   11,   11, 0x08,
     688,   11,   11,   11, 0x08,
     773,  743,   11,   11, 0x08,
     822,   11,   11,   11, 0x08,
     845,  838,   11,   11, 0x08,
     864,   11,   11,   11, 0x08,
     904,  894,   11,   11, 0x08,
     930,   11,   11,   11, 0x08,
     951,   11,   11,   11, 0x08,
     967,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0state,serialNumber\0"
    "phoneConnectionChanged(int,QString)\0"
    "on_actionO_programie_triggered()\0"
    "showPageMessages()\0showPageApps()\0"
    "showPageFiles()\0showPageRecovery()\0"
    "showPageFastboot()\0showPagePhoneInfo()\0"
    "showPageScreenshot()\0showPageSettings()\0"
    "showPageShell()\0showPageDisconnected()\0"
    "showPageImage()\0showPageAudio()\0"
    "showPageVideo()\0showPageApplication()\0"
    "showPageContacts()\0connectFresh()\0"
    "animationFinished()\0target\0"
    "startAnimation(QWidget*)\0restartInWifi()\0"
    "restartInUsb()\0action\0setLanguageDir(QAction*)\0"
    "setLanguageRes(QAction*)\0fillLanguages()\0"
    "updatesCheck()\0,,\0"
    "updatesCheckFinished(bool,QString,QString)\0"
    "showLogcat()\0number,body\0"
    "smsReceived(QString,QString)\0result\0"
    "smsResult(QString)\0"
    "systemTrayActivated(QSystemTrayIcon::ActivationReason)\0"
    "icon,textTr,text,method,flags\0"
    "addButton(QIcon,QString,QString,const char*,int)\0"
    "changeToolBar()\0number\0setButtonDown(int)\0"
    "disableActions(Action::Flags)\0value,max\0"
    "setProgressValue(int,int)\0"
    "setProgressDisable()\0donateMessage()\0"
    "on_actionEnter_register_key_triggered()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->phoneConnectionChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->on_actionO_programie_triggered(); break;
        case 2: _t->showPageMessages(); break;
        case 3: _t->showPageApps(); break;
        case 4: _t->showPageFiles(); break;
        case 5: _t->showPageRecovery(); break;
        case 6: _t->showPageFastboot(); break;
        case 7: _t->showPagePhoneInfo(); break;
        case 8: _t->showPageScreenshot(); break;
        case 9: _t->showPageSettings(); break;
        case 10: _t->showPageShell(); break;
        case 11: _t->showPageDisconnected(); break;
        case 12: _t->showPageImage(); break;
        case 13: _t->showPageAudio(); break;
        case 14: _t->showPageVideo(); break;
        case 15: _t->showPageApplication(); break;
        case 16: _t->showPageContacts(); break;
        case 17: _t->connectFresh(); break;
        case 18: _t->animationFinished(); break;
        case 19: _t->startAnimation((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 20: _t->restartInWifi(); break;
        case 21: _t->restartInUsb(); break;
        case 22: _t->setLanguageDir((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 23: _t->setLanguageRes((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 24: _t->fillLanguages(); break;
        case 25: _t->updatesCheck(); break;
        case 26: _t->updatesCheckFinished((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 27: _t->showLogcat(); break;
        case 28: _t->smsReceived((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 29: _t->smsResult((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 30: _t->systemTrayActivated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 31: _t->addButton((*reinterpret_cast< QIcon(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< const char*(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 32: _t->changeToolBar(); break;
        case 33: _t->setButtonDown((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->disableActions((*reinterpret_cast< Action::Flags(*)>(_a[1]))); break;
        case 35: _t->setProgressValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 36: _t->setProgressDisable(); break;
        case 37: _t->donateMessage(); break;
        case 38: _t->on_actionEnter_register_key_triggered(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 39)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 39;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
