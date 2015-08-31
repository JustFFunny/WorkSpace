/****************************************************************************
** Meta object code from reading C++ file 'phone.h'
**
** Created: Sat Aug 2 16:56:55 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "classes/phone.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'phone.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Phone[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,    7,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
      81,   52,    6,    6, 0x0a,
     116,    6,    6,    6, 0x0a,
     138,    6,    6,    6, 0x0a,
     158,    6,    6,    6, 0x0a,
     170,    6,    6,    6, 0x0a,
     184,    6,    6,    6, 0x0a,
     201,    6,    6,    6, 0x0a,
     228,    6,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Phone[] = {
    "Phone\0\0connectionState\0"
    "signalConnectionChanged(int)\0"
    "connectionState,serialNumber\0"
    "slotConnectionChanged(int,QString)\0"
    "adbRebootBootloader()\0adbRebootRecovery()\0"
    "adbReboot()\0adbPowerOff()\0fastbootReboot()\0"
    "fastbootRebootBootloader()\0"
    "fastbootPowerOff()\0"
};

void Phone::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Phone *_t = static_cast<Phone *>(_o);
        switch (_id) {
        case 0: _t->signalConnectionChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->slotConnectionChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->adbRebootBootloader(); break;
        case 3: _t->adbRebootRecovery(); break;
        case 4: _t->adbReboot(); break;
        case 5: _t->adbPowerOff(); break;
        case 6: _t->fastbootReboot(); break;
        case 7: _t->fastbootRebootBootloader(); break;
        case 8: _t->fastbootPowerOff(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Phone::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Phone::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Phone,
      qt_meta_data_Phone, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Phone::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Phone::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Phone::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Phone))
        return static_cast<void*>(const_cast< Phone*>(this));
    return QObject::qt_metacast(_clname);
}

int Phone::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Phone::signalConnectionChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
