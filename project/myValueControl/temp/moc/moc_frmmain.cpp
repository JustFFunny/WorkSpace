/****************************************************************************
** Meta object code from reading C++ file 'frmmain.h'
**
** Created: Fri Aug 8 09:28:17 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../frmmain.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmmain.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_frmMain[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      35,    8,    8,    8, 0x08,
      59,    8,    8,    8, 0x08,
      83,    8,    8,    8, 0x08,
     106,    8,    8,    8, 0x08,
     134,    8,    8,    8, 0x08,
     157,    8,    8,    8, 0x08,
     180,    8,    8,    8, 0x08,
     203,    8,    8,    8, 0x08,
     226,    8,    8,    8, 0x08,
     249,    8,    8,    8, 0x08,
     274,  272,    8,    8, 0x08,
     294,    8,    8,    8, 0x08,
     308,    8,    8,    8, 0x08,
     328,  322,    8,    8, 0x08,
     347,    8,    8,    8, 0x08,
     361,    8,    8,    8, 0x08,
     375,    8,    8,    8, 0x08,
     389,    8,    8,    8, 0x08,
     403,    8,    8,    8, 0x08,
     417,  322,    8,    8, 0x08,
     434,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_frmMain[] = {
    "frmMain\0\0on_btnIndicator_clicked()\0"
    "on_btnCoolBar_clicked()\0on_btnBattery_clicked()\0"
    "on_btnGauge7_clicked()\0"
    "on_btnProgressBar_clicked()\0"
    "on_btnGauge6_clicked()\0on_btnGauge5_clicked()\0"
    "on_btnGauge4_clicked()\0on_btnGauge3_clicked()\0"
    "on_btnGauge2_clicked()\0on_btnGauge1_clicked()\0"
    "b\0ChangeVisible(bool)\0UpdateData1()\0"
    "UpdateData2()\0value\0UpdateData3(qreal)\0"
    "UpdateData4()\0UpdateData5()\0UpdateData6()\0"
    "UpdateData7()\0UpdateData8()\0"
    "UpdateData9(int)\0UpdateData10()\0"
};

void frmMain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        frmMain *_t = static_cast<frmMain *>(_o);
        switch (_id) {
        case 0: _t->on_btnIndicator_clicked(); break;
        case 1: _t->on_btnCoolBar_clicked(); break;
        case 2: _t->on_btnBattery_clicked(); break;
        case 3: _t->on_btnGauge7_clicked(); break;
        case 4: _t->on_btnProgressBar_clicked(); break;
        case 5: _t->on_btnGauge6_clicked(); break;
        case 6: _t->on_btnGauge5_clicked(); break;
        case 7: _t->on_btnGauge4_clicked(); break;
        case 8: _t->on_btnGauge3_clicked(); break;
        case 9: _t->on_btnGauge2_clicked(); break;
        case 10: _t->on_btnGauge1_clicked(); break;
        case 11: _t->ChangeVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->UpdateData1(); break;
        case 13: _t->UpdateData2(); break;
        case 14: _t->UpdateData3((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 15: _t->UpdateData4(); break;
        case 16: _t->UpdateData5(); break;
        case 17: _t->UpdateData6(); break;
        case 18: _t->UpdateData7(); break;
        case 19: _t->UpdateData8(); break;
        case 20: _t->UpdateData9((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->UpdateData10(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData frmMain::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject frmMain::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_frmMain,
      qt_meta_data_frmMain, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &frmMain::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *frmMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *frmMain::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_frmMain))
        return static_cast<void*>(const_cast< frmMain*>(this));
    return QWidget::qt_metacast(_clname);
}

int frmMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
