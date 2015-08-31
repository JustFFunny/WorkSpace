/****************************************************************************
** Meta object code from reading C++ file 'mygauge2.h'
**
** Created: Fri Aug 8 09:28:22 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mygauge2.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mygauge2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_myGauge2[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   10,    9,    9, 0x0a,
      39,   32,    9,    9, 0x0a,
      58,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_myGauge2[] = {
    "myGauge2\0\0value\0setValue(qreal)\0enable\0"
    "setAnimating(bool)\0UpdateGraph()\0"
};

void myGauge2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        myGauge2 *_t = static_cast<myGauge2 *>(_o);
        switch (_id) {
        case 0: _t->setValue((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 1: _t->setAnimating((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->UpdateGraph(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData myGauge2::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject myGauge2::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_myGauge2,
      qt_meta_data_myGauge2, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &myGauge2::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *myGauge2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *myGauge2::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_myGauge2))
        return static_cast<void*>(const_cast< myGauge2*>(this));
    return QWidget::qt_metacast(_clname);
}

int myGauge2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
