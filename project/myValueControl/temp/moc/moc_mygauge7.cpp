/****************************************************************************
** Meta object code from reading C++ file 'mygauge7.h'
**
** Created: Fri Aug 8 09:28:36 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mygauge7.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mygauge7.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_myGauge7[] = {

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
      10,    9,    9,    9, 0x08,
      30,   24,    9,    9, 0x0a,
      50,   46,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_myGauge7[] = {
    "myGauge7\0\0UpdateGraph()\0value\0"
    "setValue(qreal)\0clr\0setMarkColor(QColor)\0"
};

void myGauge7::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        myGauge7 *_t = static_cast<myGauge7 *>(_o);
        switch (_id) {
        case 0: _t->UpdateGraph(); break;
        case 1: _t->setValue((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 2: _t->setMarkColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData myGauge7::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject myGauge7::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_myGauge7,
      qt_meta_data_myGauge7, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &myGauge7::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *myGauge7::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *myGauge7::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_myGauge7))
        return static_cast<void*>(const_cast< myGauge7*>(this));
    return QWidget::qt_metacast(_clname);
}

int myGauge7::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
