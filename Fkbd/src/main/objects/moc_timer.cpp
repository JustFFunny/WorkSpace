/****************************************************************************
** Meta object code from reading C++ file 'timer.h'
**
** Created: Sat Feb 20 14:54:15 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../timer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'timer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Timer[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       2,   69, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x05,
      17,    6,    6,    6, 0x05,
      36,   28,    6,    6, 0x05,
      53,    6,    6,    6, 0x05,
      76,   74,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
      91,    6,    6,    6, 0x0a,
      99,   28,    6,    6, 0x0a,
     118,  112,    6,    6, 0x0a,
     132,    6,    6,    6, 0x0a,
     140,    6,    6,    6, 0x0a,
     147,    6,    6,    6, 0x09,

 // properties: name, type, flags
      28,  154, 0x02095001,
     166,  158, 0x0a095001,

 // properties: notify_signal_id
       0,
       0,

       0        // eod
};

static const char qt_meta_stringdata_Timer[] = {
    "Timer\0\0timeOut()\0timeTick()\0seconds\0"
    "secondsLeft(int)\0timeUpdated(QString)\0"
    "m\0moneyLeft(int)\0reset()\0addTime(int)\0"
    "value\0addValue(int)\0start()\0stop()\0"
    "tick()\0int\0QString\0timeStr\0"
};

const QMetaObject Timer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Timer,
      qt_meta_data_Timer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Timer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Timer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Timer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Timer))
        return static_cast<void*>(const_cast< Timer*>(this));
    return QObject::qt_metacast(_clname);
}

int Timer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: timeOut(); break;
        case 1: timeTick(); break;
        case 2: secondsLeft((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: timeUpdated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: moneyLeft((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 5: reset(); break;
        case 6: addTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: addValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: start(); break;
        case 9: stop(); break;
        case 10: tick(); break;
        default: ;
        }
        _id -= 11;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = seconds(); break;
        case 1: *reinterpret_cast< QString*>(_v) = timeStr(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Timer::timeOut()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Timer::timeTick()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Timer::secondsLeft(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Timer::timeUpdated(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Timer::moneyLeft(const int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
