/****************************************************************************
** Meta object code from reading C++ file 'applicationwidget.h'
**
** Created: Sat Aug 2 16:57:23 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "widgets/applicationwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'applicationwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ApplicationWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   18,   19,   18, 0x0a,
      41,   37,   18,   18, 0x0a,
      57,   18,   18,   18, 0x0a,
      71,   18,   18,   18, 0x0a,
      91,   18,   18,   18, 0x0a,
     104,   18,   18,   18, 0x0a,
     117,   18,   18,   18, 0x0a,
     141,  132,   18,   18, 0x0a,
     173,  164,   18,   18, 0x0a,
     204,   18,   18,   18, 0x0a,
     214,   18,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ApplicationWidget[] = {
    "ApplicationWidget\0\0int\0getAppCount()\0"
    "num\0GetAppInfo(int)\0readAppInfo()\0"
    "appsSelectedCount()\0appRefresh()\0"
    "appInstall()\0appUninstall()\0fileName\0"
    "startTransfer(QString)\0numBytes\0"
    "updateTransferProgress(qint64)\0appCopy()\0"
    "readFile()\0"
};

void ApplicationWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ApplicationWidget *_t = static_cast<ApplicationWidget *>(_o);
        switch (_id) {
        case 0: { int _r = _t->getAppCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: _t->GetAppInfo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->readAppInfo(); break;
        case 3: _t->appsSelectedCount(); break;
        case 4: _t->appRefresh(); break;
        case 5: _t->appInstall(); break;
        case 6: _t->appUninstall(); break;
        case 7: _t->startTransfer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->updateTransferProgress((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 9: _t->appCopy(); break;
        case 10: _t->readFile(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ApplicationWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ApplicationWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ApplicationWidget,
      qt_meta_data_ApplicationWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ApplicationWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ApplicationWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ApplicationWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ApplicationWidget))
        return static_cast<void*>(const_cast< ApplicationWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ApplicationWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
