/****************************************************************************
** Meta object code from reading C++ file 'appwidget.h'
**
** Created: Sat Aug 2 16:56:41 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "widgets/appwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'appwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ThreadApps[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      24,   11,   11,   11, 0x05,
      37,   11,   11,   11, 0x05,
      58,   48,   11,   11, 0x05,
      81,   11,   11,   11, 0x05,
     102,   11,   11,   11, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ThreadApps[] = {
    "ThreadApps\0\0gotApp(App)\0maximum(int)\0"
    "value(int)\0value,max\0progressValue(int,int)\0"
    "gotAllApps(QThread*)\0missingAapt()\0"
};

void ThreadApps::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ThreadApps *_t = static_cast<ThreadApps *>(_o);
        switch (_id) {
        case 0: _t->gotApp((*reinterpret_cast< App(*)>(_a[1]))); break;
        case 1: _t->maximum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->value((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->progressValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->gotAllApps((*reinterpret_cast< QThread*(*)>(_a[1]))); break;
        case 5: _t->missingAapt(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ThreadApps::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ThreadApps::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ThreadApps,
      qt_meta_data_ThreadApps, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ThreadApps::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ThreadApps::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ThreadApps::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadApps))
        return static_cast<void*>(const_cast< ThreadApps*>(this));
    return QThread::qt_metacast(_clname);
}

int ThreadApps::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ThreadApps::gotApp(App _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ThreadApps::maximum(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ThreadApps::value(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ThreadApps::progressValue(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ThreadApps::gotAllApps(QThread * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ThreadApps::missingAapt()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}
static const uint qt_meta_data_ThreadBackups[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      33,   14,   14,   14, 0x05,
      46,   14,   14,   14, 0x05,
      67,   57,   14,   14, 0x05,
      90,   14,   14,   14, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ThreadBackups[] = {
    "ThreadBackups\0\0gotBackup(Backup)\0"
    "maximum(int)\0value(int)\0value,max\0"
    "progressValue(int,int)\0gotAllApps(QThread*)\0"
};

void ThreadBackups::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ThreadBackups *_t = static_cast<ThreadBackups *>(_o);
        switch (_id) {
        case 0: _t->gotBackup((*reinterpret_cast< Backup(*)>(_a[1]))); break;
        case 1: _t->maximum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->value((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->progressValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->gotAllApps((*reinterpret_cast< QThread*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ThreadBackups::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ThreadBackups::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ThreadBackups,
      qt_meta_data_ThreadBackups, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ThreadBackups::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ThreadBackups::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ThreadBackups::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadBackups))
        return static_cast<void*>(const_cast< ThreadBackups*>(this));
    return QThread::qt_metacast(_clname);
}

int ThreadBackups::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ThreadBackups::gotBackup(Backup _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ThreadBackups::maximum(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ThreadBackups::value(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ThreadBackups::progressValue(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ThreadBackups::gotAllApps(QThread * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
static const uint qt_meta_data_AppWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   11,   10,   10, 0x05,
      44,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      63,   10,   10,   10, 0x0a,
      76,   10,   10,   10, 0x0a,
      91,   10,   10,   10, 0x0a,
     115,  111,   10,   10, 0x0a,
     137,  130,   10,   10, 0x0a,
     158,   10,   10,   10, 0x0a,
     179,   10,   10,   10, 0x0a,
     199,   10,   10,   10, 0x0a,
     223,   10,   10,   10, 0x0a,
     250,   10,   10,   10, 0x0a,
     264,   10,   10,   10, 0x08,
     277,   10,   10,   10, 0x08,
     286,   10,   10,   10, 0x08,
     341,  305,  300,   10, 0x08,
     395,  389,  381,   10, 0x08,
     433,  389,  425,   10, 0x08,
     463,   10,   10,   10, 0x08,
     499,   10,   10,   10, 0x08,
     529,   10,   10,   10, 0x08,
     560,   10,   10,   10, 0x08,
     593,   10,   10,   10, 0x08,
     624,   10,   10,   10, 0x08,
     646,   10,   10,   10, 0x08,
     669,   10,   10,   10, 0x08,
     698,   10,   10,   10, 0x08,
     721,   10,   10,   10, 0x08,
     745,   10,   10,   10, 0x08,
     775,   10,   10,   10, 0x08,
     799,   10,   10,   10, 0x08,
     821,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AppWidget[] = {
    "AppWidget\0\0value,max\0progressValue(int,int)\0"
    "progressFinished()\0openMarket()\0"
    "openAppBrain()\0getCyrketVersions()\0"
    "app\0insertApp(App)\0backup\0"
    "insertBackup(Backup)\0gotAllApps(QThread*)\0"
    "appsSelectedCount()\0appsContextMenu(QPoint)\0"
    "backupsContextMenu(QPoint)\0copyAppToPC()\0"
    "getAppInfo()\0filter()\0missingAapt()\0"
    "bool\0inFile,outPath,fileToUnpack,outName\0"
    "unpack(QString,QString,QString,QString)\0"
    "quint32\0array\0qbytearrayToInt32(QByteArray)\0"
    "quint16\0qbytearrayToInt16(QByteArray)\0"
    "on_toolButtonRemoveBackup_pressed()\0"
    "on_toolButtonBackup_pressed()\0"
    "on_toolButtonRestore_pressed()\0"
    "on_toolButtonUninstall_pressed()\0"
    "on_toolButtonInstall_pressed()\0"
    "toolButtonBackupApp()\0toolButtonBackupData()\0"
    "toolButtonBackupAppAndData()\0"
    "toolButtonRestoreApp()\0toolButtonRestoreData()\0"
    "toolButtonRestoreAppAndData()\0"
    "toolButtonInstallOnSd()\0comboBoxAppsChanged()\0"
    "refreshApps()\0"
};

void AppWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AppWidget *_t = static_cast<AppWidget *>(_o);
        switch (_id) {
        case 0: _t->progressValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->progressFinished(); break;
        case 2: _t->openMarket(); break;
        case 3: _t->openAppBrain(); break;
        case 4: _t->getCyrketVersions(); break;
        case 5: _t->insertApp((*reinterpret_cast< App(*)>(_a[1]))); break;
        case 6: _t->insertBackup((*reinterpret_cast< Backup(*)>(_a[1]))); break;
        case 7: _t->gotAllApps((*reinterpret_cast< QThread*(*)>(_a[1]))); break;
        case 8: _t->appsSelectedCount(); break;
        case 9: _t->appsContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 10: _t->backupsContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 11: _t->copyAppToPC(); break;
        case 12: _t->getAppInfo(); break;
        case 13: _t->filter(); break;
        case 14: _t->missingAapt(); break;
        case 15: { bool _r = _t->unpack((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 16: { quint32 _r = _t->qbytearrayToInt32((*reinterpret_cast< QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< quint32*>(_a[0]) = _r; }  break;
        case 17: { quint16 _r = _t->qbytearrayToInt16((*reinterpret_cast< QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< quint16*>(_a[0]) = _r; }  break;
        case 18: _t->on_toolButtonRemoveBackup_pressed(); break;
        case 19: _t->on_toolButtonBackup_pressed(); break;
        case 20: _t->on_toolButtonRestore_pressed(); break;
        case 21: _t->on_toolButtonUninstall_pressed(); break;
        case 22: _t->on_toolButtonInstall_pressed(); break;
        case 23: _t->toolButtonBackupApp(); break;
        case 24: _t->toolButtonBackupData(); break;
        case 25: _t->toolButtonBackupAppAndData(); break;
        case 26: _t->toolButtonRestoreApp(); break;
        case 27: _t->toolButtonRestoreData(); break;
        case 28: _t->toolButtonRestoreAppAndData(); break;
        case 29: _t->toolButtonInstallOnSd(); break;
        case 30: _t->comboBoxAppsChanged(); break;
        case 31: _t->refreshApps(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AppWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AppWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AppWidget,
      qt_meta_data_AppWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AppWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AppWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AppWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AppWidget))
        return static_cast<void*>(const_cast< AppWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int AppWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    }
    return _id;
}

// SIGNAL 0
void AppWidget::progressValue(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AppWidget::progressFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
