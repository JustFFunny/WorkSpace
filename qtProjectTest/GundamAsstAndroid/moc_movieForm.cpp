/****************************************************************************
** Meta object code from reading C++ file 'movieForm.h'
**
** Created: Tue Jan 7 15:51:37 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "widgets/movieForm.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'movieForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MovieForm[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      18,   10,   10,   10, 0x08,
      24,   10,   10,   10, 0x08,
      32,   10,   10,   10, 0x08,
      39,   10,   10,   10, 0x08,
      57,   10,   10,   10, 0x08,
      68,   10,   10,   10, 0x08,
      82,   10,   10,   10, 0x08,
      95,   10,   10,   10, 0x08,
     108,   10,   10,   10, 0x08,
     125,   10,   10,   10, 0x08,
     156,   10,   10,   10, 0x08,
     162,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MovieForm[] = {
    "MovieForm\0\0next()\0pre()\0pause()\0stop()\0"
    "changeVolume(int)\0setSpeed()\0dataRecieve()\0"
    "current(int)\0jumpByTime()\0sureBtnClicked()\0"
    "playListItem(QListWidgetItem*)\0add()\0"
    "del()\0"
};

void MovieForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MovieForm *_t = static_cast<MovieForm *>(_o);
        switch (_id) {
        case 0: _t->next(); break;
        case 1: _t->pre(); break;
        case 2: _t->pause(); break;
        case 3: _t->stop(); break;
        case 4: _t->changeVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setSpeed(); break;
        case 6: _t->dataRecieve(); break;
        case 7: _t->current((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->jumpByTime(); break;
        case 9: _t->sureBtnClicked(); break;
        case 10: _t->playListItem((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 11: _t->add(); break;
        case 12: _t->del(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MovieForm::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MovieForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MovieForm,
      qt_meta_data_MovieForm, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MovieForm::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MovieForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MovieForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MovieForm))
        return static_cast<void*>(const_cast< MovieForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int MovieForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
