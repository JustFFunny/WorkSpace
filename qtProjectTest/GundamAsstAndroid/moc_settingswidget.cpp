/****************************************************************************
** Meta object code from reading C++ file 'settingswidget.h'
**
** Created: Sat Aug 2 16:56:21 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "widgets/settingswidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settingswidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SettingsWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      34,   15,   15,   15, 0x0a,
      49,   15,   15,   15, 0x0a,
      62,   15,   15,   15, 0x08,
      99,   15,   15,   15, 0x08,
     113,   15,   15,   15, 0x08,
     135,   15,   15,   15, 0x08,
     151,   15,   15,   15, 0x08,
     170,   15,   15,   15, 0x08,
     188,   15,   15,   15, 0x08,
     212,   15,   15,   15, 0x08,
     246,   15,   15,   15, 0x08,
     264,   15,   15,   15, 0x08,
     280,   15,   15,   15, 0x08,
     300,   15,   15,   15, 0x08,
     329,   15,   15,   15, 0x08,
     368,   15,   15,   15, 0x08,
     401,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SettingsWidget[] = {
    "SettingsWidget\0\0settingsChanged()\0"
    "saveSettings()\0changeFont()\0"
    "on_pushButtonChangeSDKPath_pressed()\0"
    "getSettings()\0settingsSlotChanged()\0"
    "chooseFontApp()\0chooseFontTables()\0"
    "chooseFontShell()\0setSettingsToDefaults()\0"
    "on_buttonRemoveSettings_pressed()\0"
    "curveChanged(int)\0changePage(int)\0"
    "animationFinished()\0on_buttonAssociate_clicked()\0"
    "on_shellPushButtonBackground_clicked()\0"
    "on_shellPushButtonFont_clicked()\0"
    "detectSdExtFolder()\0"
};

void SettingsWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SettingsWidget *_t = static_cast<SettingsWidget *>(_o);
        switch (_id) {
        case 0: _t->settingsChanged(); break;
        case 1: _t->saveSettings(); break;
        case 2: _t->changeFont(); break;
        case 3: _t->on_pushButtonChangeSDKPath_pressed(); break;
        case 4: _t->getSettings(); break;
        case 5: _t->settingsSlotChanged(); break;
        case 6: _t->chooseFontApp(); break;
        case 7: _t->chooseFontTables(); break;
        case 8: _t->chooseFontShell(); break;
        case 9: _t->setSettingsToDefaults(); break;
        case 10: _t->on_buttonRemoveSettings_pressed(); break;
        case 11: _t->curveChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->changePage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->animationFinished(); break;
        case 14: _t->on_buttonAssociate_clicked(); break;
        case 15: _t->on_shellPushButtonBackground_clicked(); break;
        case 16: _t->on_shellPushButtonFont_clicked(); break;
        case 17: _t->detectSdExtFolder(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SettingsWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SettingsWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SettingsWidget,
      qt_meta_data_SettingsWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SettingsWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SettingsWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SettingsWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SettingsWidget))
        return static_cast<void*>(const_cast< SettingsWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int SettingsWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void SettingsWidget::settingsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
