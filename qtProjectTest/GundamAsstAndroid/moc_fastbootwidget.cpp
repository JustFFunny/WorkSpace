/****************************************************************************
** Meta object code from reading C++ file 'fastbootwidget.h'
**
** Created: Sat Aug 2 16:56:38 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "widgets/fastbootwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fastbootwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FastbootWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      27,   15,   15,   15, 0x08,
      43,   15,   15,   15, 0x08,
      56,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FastbootWidget[] = {
    "FastbootWidget\0\0flashSPL()\0flashRecovery()\0"
    "flashRadio()\0bootIMG()\0"
};

void FastbootWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FastbootWidget *_t = static_cast<FastbootWidget *>(_o);
        switch (_id) {
        case 0: _t->flashSPL(); break;
        case 1: _t->flashRecovery(); break;
        case 2: _t->flashRadio(); break;
        case 3: _t->bootIMG(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData FastbootWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FastbootWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FastbootWidget,
      qt_meta_data_FastbootWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FastbootWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FastbootWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FastbootWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FastbootWidget))
        return static_cast<void*>(const_cast< FastbootWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int FastbootWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
