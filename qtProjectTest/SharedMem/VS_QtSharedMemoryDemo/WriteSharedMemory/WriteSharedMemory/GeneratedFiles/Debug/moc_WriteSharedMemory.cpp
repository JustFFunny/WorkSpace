/****************************************************************************
** Meta object code from reading C++ file 'WriteSharedMemory.h'
**
** Created: Thu May 2 16:10:56 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../WriteSharedMemory.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WriteSharedMemory.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WriteSharedMemory[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x0a,
      39,   18,   18,   18, 0x0a,
      46,   18,   18,   18, 0x0a,
      62,   18,   54,   18, 0x0a,
      69,   18,   18,   18, 0x0a,
      75,   18,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_WriteSharedMemory[] = {
    "WriteSharedMemory\0\0loadIntoSharedMem()\0"
    "init()\0write()\0QString\0read()\0run()\0"
    "detach()\0"
};

const QMetaObject WriteSharedMemory::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_WriteSharedMemory,
      qt_meta_data_WriteSharedMemory, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WriteSharedMemory::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WriteSharedMemory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WriteSharedMemory::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WriteSharedMemory))
        return static_cast<void*>(const_cast< WriteSharedMemory*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int WriteSharedMemory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: loadIntoSharedMem(); break;
        case 1: init(); break;
        case 2: write(); break;
        case 3: { QString _r = read();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 4: run(); break;
        case 5: detach(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
