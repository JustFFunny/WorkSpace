/****************************************************************************
** Meta object code from reading C++ file 'dialogkopiuj.h'
**
** Created: Sat Aug 2 16:57:07 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dialogs/dialogkopiuj.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogkopiuj.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ThreadCopy[] = {

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
      12,   11,   11,   11, 0x05,
      63,   21,   11,   11, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ThreadCopy[] = {
    "ThreadCopy\0\0copied()\0"
    "fileName,pathFrom,pathTo,fileSize,counter\0"
    "nextFile(QString,QString,QString,int,int)\0"
};

void ThreadCopy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ThreadCopy *_t = static_cast<ThreadCopy *>(_o);
        switch (_id) {
        case 0: _t->copied(); break;
        case 1: _t->nextFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ThreadCopy::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ThreadCopy::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ThreadCopy,
      qt_meta_data_ThreadCopy, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ThreadCopy::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ThreadCopy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ThreadCopy::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadCopy))
        return static_cast<void*>(const_cast< ThreadCopy*>(this));
    return QThread::qt_metacast(_clname);
}

int ThreadCopy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ThreadCopy::copied()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ThreadCopy::nextFile(QString _t1, QString _t2, QString _t3, int _t4, int _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
static const uint qt_meta_data_ThreadProgress[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   16,   15,   15, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ThreadProgress[] = {
    "ThreadProgress\0\0fileSize\0progressValue(int)\0"
};

void ThreadProgress::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ThreadProgress *_t = static_cast<ThreadProgress *>(_o);
        switch (_id) {
        case 0: _t->progressValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ThreadProgress::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ThreadProgress::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ThreadProgress,
      qt_meta_data_ThreadProgress, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ThreadProgress::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ThreadProgress::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ThreadProgress::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadProgress))
        return static_cast<void*>(const_cast< ThreadProgress*>(this));
    return QThread::qt_metacast(_clname);
}

int ThreadProgress::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void ThreadProgress::progressValue(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_dialogKopiuj[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   14,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      47,   13,   13,   13, 0x0a,
      68,   13,   13,   13, 0x0a,
     119,   77,   13,   13, 0x0a,
     167,  161,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_dialogKopiuj[] = {
    "dialogKopiuj\0\0value,max\0progressValue(int,int)\0"
    "closeAfterFinished()\0copied()\0"
    "fileName,pathFrom,pathTo,fileSize,counter\0"
    "nextFile(QString,QString,QString,int,int)\0"
    "value\0setProgressValue(int)\0"
};

void dialogKopiuj::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        dialogKopiuj *_t = static_cast<dialogKopiuj *>(_o);
        switch (_id) {
        case 0: _t->progressValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->closeAfterFinished(); break;
        case 2: _t->copied(); break;
        case 3: _t->nextFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 4: _t->setProgressValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData dialogKopiuj::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject dialogKopiuj::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_dialogKopiuj,
      qt_meta_data_dialogKopiuj, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dialogKopiuj::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dialogKopiuj::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dialogKopiuj::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dialogKopiuj))
        return static_cast<void*>(const_cast< dialogKopiuj*>(this));
    return QDialog::qt_metacast(_clname);
}

int dialogKopiuj::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void dialogKopiuj::progressValue(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
