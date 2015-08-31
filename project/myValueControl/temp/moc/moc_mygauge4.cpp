/****************************************************************************
** Meta object code from reading C++ file 'mygauge4.h'
**
** Created: Fri Aug 8 09:28:27 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mygauge4.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mygauge4.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LinearGradient[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_LinearGradient[] = {
    "LinearGradient\0"
};

void LinearGradient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData LinearGradient::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LinearGradient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LinearGradient,
      qt_meta_data_LinearGradient, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LinearGradient::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LinearGradient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LinearGradient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LinearGradient))
        return static_cast<void*>(const_cast< LinearGradient*>(this));
    return QObject::qt_metacast(_clname);
}

int LinearGradient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_myGauge4[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      30,   24,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_myGauge4[] = {
    "myGauge4\0\0UpdateGraph()\0value\0"
    "setValue(qreal)\0"
};

void myGauge4::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        myGauge4 *_t = static_cast<myGauge4 *>(_o);
        switch (_id) {
        case 0: _t->UpdateGraph(); break;
        case 1: _t->setValue((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData myGauge4::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject myGauge4::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_myGauge4,
      qt_meta_data_myGauge4, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &myGauge4::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *myGauge4::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *myGauge4::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_myGauge4))
        return static_cast<void*>(const_cast< myGauge4*>(this));
    return QWidget::qt_metacast(_clname);
}

int myGauge4::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
