/****************************************************************************
** Meta object code from reading C++ file 'logcatdialog.h'
**
** Created: Sat Aug 2 16:57:05 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dialogs/logcatdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logcatdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LogcatDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      21,   13,   13,   13, 0x0a,
      30,   13,   13,   13, 0x0a,
      44,   13,   13,   13, 0x08,
      79,   13,   13,   13, 0x08,
     127,  119,   13,   13, 0x08,
     169,  163,   13,   13, 0x08,
     193,   13,   13,   13, 0x08,
     219,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LogcatDialog[] = {
    "LogcatDialog\0\0read()\0filter()\0"
    "startLogcat()\0on_pushButtonClearLogcat_pressed()\0"
    "on_spinBoxBufferLimit_editingFinished()\0"
    "checked\0on_checkBoxAutoScroll_toggled(bool)\0"
    "point\0showContextMenu(QPoint)\0"
    "copySelectedToClipboard()\0"
    "exportSelectedToFile()\0"
};

void LogcatDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LogcatDialog *_t = static_cast<LogcatDialog *>(_o);
        switch (_id) {
        case 0: _t->read(); break;
        case 1: _t->filter(); break;
        case 2: _t->startLogcat(); break;
        case 3: _t->on_pushButtonClearLogcat_pressed(); break;
        case 4: _t->on_spinBoxBufferLimit_editingFinished(); break;
        case 5: _t->on_checkBoxAutoScroll_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->showContextMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 7: _t->copySelectedToClipboard(); break;
        case 8: _t->exportSelectedToFile(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LogcatDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LogcatDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_LogcatDialog,
      qt_meta_data_LogcatDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LogcatDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LogcatDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LogcatDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LogcatDialog))
        return static_cast<void*>(const_cast< LogcatDialog*>(this));
    if (!strcmp(_clname, "Ui::LogcatDialog"))
        return static_cast< Ui::LogcatDialog*>(const_cast< LogcatDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int LogcatDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
