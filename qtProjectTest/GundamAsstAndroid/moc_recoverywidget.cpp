/****************************************************************************
** Meta object code from reading C++ file 'recoverywidget.h'
**
** Created: Sat Aug 2 16:56:25 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "widgets/recoverywidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'recoverywidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RecoveryWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      30,   15,   15,   15, 0x08,
      44,   15,   15,   15, 0x08,
      55,   15,   15,   15, 0x08,
      72,   15,   15,   15, 0x08,
      89,   15,   15,   15, 0x08,
      98,   15,   15,   15, 0x08,
     113,   15,   15,   15, 0x08,
     130,   15,   15,   15, 0x08,
     141,   15,   15,   15, 0x08,
     160,   15,   15,   15, 0x08,
     177,   15,   15,   15, 0x08,
     198,   15,   15,   15, 0x08,
     221,   15,   15,   15, 0x08,
     242,   15,   15,   15, 0x08,
     267,   15,   15,   15, 0x08,
     285,   15,   15,   15, 0x08,
     308,   15,   15,   15, 0x08,
     332,   15,   15,   15, 0x08,
     354,   15,   15,   15, 0x08,
     380,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_RecoveryWidget[] = {
    "RecoveryWidget\0\0wipeBattery()\0"
    "mountSDcard()\0flashZip()\0flashZipCopied()\0"
    "flashZipReboot()\0fixUID()\0fixUIDoutput()\0"
    "fixUIDfinished()\0wipeData()\0"
    "wipeDataFinished()\0nandroidBackup()\0"
    "nandroidBackupEdit()\0nandroidBackupOutput()\0"
    "nandroidBackupPage()\0nandroidBackupFinished()\0"
    "nandroidRestore()\0nandroidRestoreCombo()\0"
    "nandroidRestoreOutput()\0nandroidRestorePage()\0"
    "nandroidRestoreFinished()\0"
    "nandroidRestoreFound()\0"
};

void RecoveryWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RecoveryWidget *_t = static_cast<RecoveryWidget *>(_o);
        switch (_id) {
        case 0: _t->wipeBattery(); break;
        case 1: _t->mountSDcard(); break;
        case 2: _t->flashZip(); break;
        case 3: _t->flashZipCopied(); break;
        case 4: _t->flashZipReboot(); break;
        case 5: _t->fixUID(); break;
        case 6: _t->fixUIDoutput(); break;
        case 7: _t->fixUIDfinished(); break;
        case 8: _t->wipeData(); break;
        case 9: _t->wipeDataFinished(); break;
        case 10: _t->nandroidBackup(); break;
        case 11: _t->nandroidBackupEdit(); break;
        case 12: _t->nandroidBackupOutput(); break;
        case 13: _t->nandroidBackupPage(); break;
        case 14: _t->nandroidBackupFinished(); break;
        case 15: _t->nandroidRestore(); break;
        case 16: _t->nandroidRestoreCombo(); break;
        case 17: _t->nandroidRestoreOutput(); break;
        case 18: _t->nandroidRestorePage(); break;
        case 19: _t->nandroidRestoreFinished(); break;
        case 20: _t->nandroidRestoreFound(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData RecoveryWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RecoveryWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RecoveryWidget,
      qt_meta_data_RecoveryWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RecoveryWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RecoveryWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RecoveryWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RecoveryWidget))
        return static_cast<void*>(const_cast< RecoveryWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int RecoveryWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
