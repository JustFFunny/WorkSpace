/****************************************************************************
** Meta object code from reading C++ file 'contactwidget.h'
**
** Created: Sat Aug 2 16:57:25 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "widgets/contactwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'contactwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ContactWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      32,   14,   14,   14, 0x0a,
      54,   50,   14,   14, 0x0a,
      72,   14,   14,   14, 0x0a,
      96,   14,   14,   14, 0x0a,
     109,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ContactWidget[] = {
    "ContactWidget\0\0getContactList()\0"
    "readContactInfo()\0msg\0showInfo(QString)\0"
    "readContactInfoFished()\0addContact()\0"
    "delContact()\0"
};

void ContactWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ContactWidget *_t = static_cast<ContactWidget *>(_o);
        switch (_id) {
        case 0: _t->getContactList(); break;
        case 1: _t->readContactInfo(); break;
        case 2: _t->showInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->readContactInfoFished(); break;
        case 4: _t->addContact(); break;
        case 5: _t->delContact(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ContactWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ContactWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ContactWidget,
      qt_meta_data_ContactWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ContactWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ContactWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ContactWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ContactWidget))
        return static_cast<void*>(const_cast< ContactWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ContactWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
