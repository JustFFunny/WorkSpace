/****************************************************************************
** Meta object code from reading C++ file 'appdialog.h'
**
** Created: Sat Aug 2 16:57:13 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dialogs/appdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'appdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ThreadBackup[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   14,   13,   13, 0x05,
      42,   13,   13,   13, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ThreadBackup[] = {
    "ThreadBackup\0\0,\0backedUp(QString,QString)\0"
    "nextApp(App)\0"
};

void ThreadBackup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ThreadBackup *_t = static_cast<ThreadBackup *>(_o);
        switch (_id) {
        case 0: _t->backedUp((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->nextApp((*reinterpret_cast< App(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ThreadBackup::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ThreadBackup::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ThreadBackup,
      qt_meta_data_ThreadBackup, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ThreadBackup::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ThreadBackup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ThreadBackup::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadBackup))
        return static_cast<void*>(const_cast< ThreadBackup*>(this));
    return QThread::qt_metacast(_clname);
}

int ThreadBackup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ThreadBackup::backedUp(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ThreadBackup::nextApp(App _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
static const uint qt_meta_data_ThreadRestore[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   15,   14,   14, 0x05,
      43,   14,   14,   14, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ThreadRestore[] = {
    "ThreadRestore\0\0,\0restored(QString,QString)\0"
    "nextApp(App)\0"
};

void ThreadRestore::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ThreadRestore *_t = static_cast<ThreadRestore *>(_o);
        switch (_id) {
        case 0: _t->restored((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->nextApp((*reinterpret_cast< App(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ThreadRestore::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ThreadRestore::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ThreadRestore,
      qt_meta_data_ThreadRestore, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ThreadRestore::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ThreadRestore::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ThreadRestore::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadRestore))
        return static_cast<void*>(const_cast< ThreadRestore*>(this));
    return QThread::qt_metacast(_clname);
}

int ThreadRestore::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ThreadRestore::restored(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ThreadRestore::nextApp(App _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
static const uint qt_meta_data_ThreadInstall[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   15,   14,   14, 0x05,
      44,   14,   14,   14, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ThreadInstall[] = {
    "ThreadInstall\0\0,\0installed(QString,QString)\0"
    "nextApp(App)\0"
};

void ThreadInstall::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ThreadInstall *_t = static_cast<ThreadInstall *>(_o);
        switch (_id) {
        case 0: _t->installed((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->nextApp((*reinterpret_cast< App(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ThreadInstall::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ThreadInstall::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ThreadInstall,
      qt_meta_data_ThreadInstall, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ThreadInstall::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ThreadInstall::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ThreadInstall::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadInstall))
        return static_cast<void*>(const_cast< ThreadInstall*>(this));
    return QThread::qt_metacast(_clname);
}

int ThreadInstall::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ThreadInstall::installed(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ThreadInstall::nextApp(App _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
static const uint qt_meta_data_ThreadUninstall[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   17,   16,   16, 0x05,
      48,   16,   16,   16, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ThreadUninstall[] = {
    "ThreadUninstall\0\0,\0uninstalled(QString,QString)\0"
    "nextApp(App)\0"
};

void ThreadUninstall::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ThreadUninstall *_t = static_cast<ThreadUninstall *>(_o);
        switch (_id) {
        case 0: _t->uninstalled((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->nextApp((*reinterpret_cast< App(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ThreadUninstall::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ThreadUninstall::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ThreadUninstall,
      qt_meta_data_ThreadUninstall, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ThreadUninstall::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ThreadUninstall::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ThreadUninstall::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadUninstall))
        return static_cast<void*>(const_cast< ThreadUninstall*>(this));
    return QThread::qt_metacast(_clname);
}

int ThreadUninstall::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ThreadUninstall::uninstalled(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ThreadUninstall::nextApp(App _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
static const uint qt_meta_data_appDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      30,   20,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      53,   10,   10,   10, 0x08,
      63,   10,   10,   10, 0x08,
      75,   10,   10,   10, 0x08,
      87,   10,   10,   10, 0x08,
      96,   10,   10,   10, 0x08,
     108,  106,   10,   10, 0x08,
     134,   10,   10,   10, 0x08,
     149,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_appDialog[] = {
    "appDialog\0\0closed()\0value,max\0"
    "progressValue(int,int)\0install()\0"
    "reinstall()\0uninstall()\0backup()\0"
    "restore()\0,\0finished(QString,QString)\0"
    "clockTimeout()\0nextApp(App)\0"
};

void appDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        appDialog *_t = static_cast<appDialog *>(_o);
        switch (_id) {
        case 0: _t->closed(); break;
        case 1: _t->progressValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->install(); break;
        case 3: _t->reinstall(); break;
        case 4: _t->uninstall(); break;
        case 5: _t->backup(); break;
        case 6: _t->restore(); break;
        case 7: _t->finished((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 8: _t->clockTimeout(); break;
        case 9: _t->nextApp((*reinterpret_cast< App(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData appDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject appDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_appDialog,
      qt_meta_data_appDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &appDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *appDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *appDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_appDialog))
        return static_cast<void*>(const_cast< appDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int appDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void appDialog::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void appDialog::progressValue(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
