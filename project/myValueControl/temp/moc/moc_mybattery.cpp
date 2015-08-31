/****************************************************************************
** Meta object code from reading C++ file 'mybattery.h'
**
** Created: Fri Aug 8 09:28:38 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mybattery.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mybattery.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_myBattery[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   11,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      37,   10,   10,   10, 0x08,
      51,   11,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_myBattery[] = {
    "myBattery\0\0value\0valueChanged(qreal)\0"
    "UpdateGraph()\0setValue(qreal)\0"
};

void myBattery::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        myBattery *_t = static_cast<myBattery *>(_o);
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 1: _t->UpdateGraph(); break;
        case 2: _t->setValue((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData myBattery::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject myBattery::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_myBattery,
      qt_meta_data_myBattery, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &myBattery::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *myBattery::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *myBattery::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_myBattery))
        return static_cast<void*>(const_cast< myBattery*>(this));
    return QWidget::qt_metacast(_clname);
}

int myBattery::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void myBattery::valueChanged(qreal _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
