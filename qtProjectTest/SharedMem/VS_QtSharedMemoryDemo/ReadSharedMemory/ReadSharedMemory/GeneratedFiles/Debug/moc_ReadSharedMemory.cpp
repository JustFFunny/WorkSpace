/****************************************************************************
** Meta object code from reading C++ file 'ReadSharedMemory.h'
**
** Created: Wed May 15 09:33:19 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ReadSharedMemory.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ReadSharedMemory.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ReadSharedMemory[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x0a,
      38,   17,   17,   17, 0x0a,
      45,   17,   17,   17, 0x0a,
      51,   17,   17,   17, 0x0a,
      60,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ReadSharedMemory[] = {
    "ReadSharedMemory\0\0loadFromSharedMem()\0"
    "read()\0run()\0detach()\0attach()\0"
};

const QMetaObject ReadSharedMemory::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ReadSharedMemory,
      qt_meta_data_ReadSharedMemory, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ReadSharedMemory::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ReadSharedMemory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ReadSharedMemory::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ReadSharedMemory))
        return static_cast<void*>(const_cast< ReadSharedMemory*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ReadSharedMemory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: loadFromSharedMem(); break;
        case 1: read(); break;
        case 2: run(); break;
        case 3: detach(); break;
        case 4: attach(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
