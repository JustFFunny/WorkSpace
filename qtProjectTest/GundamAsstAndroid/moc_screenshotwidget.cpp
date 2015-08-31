/****************************************************************************
** Meta object code from reading C++ file 'screenshotwidget.h'
**
** Created: Sat Aug 2 16:56:23 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "widgets/screenshotwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'screenshotwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ScreenshotWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      38,   35,   17,   17, 0x08,
      69,   17,   17,   17, 0x08,
      86,   17,   17,   17, 0x08,
     106,   17,   17,   17, 0x08,
     119,   17,   17,   17, 0x08,
     133,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ScreenshotWidget[] = {
    "ScreenshotWidget\0\0takeScreenshot()\0"
    ",,\0showScreenshot(QImage,int,int)\0"
    "saveScreenshot()\0refreshScreenshot()\0"
    "rotateLeft()\0rotateRight()\0"
    "updateScreenshotLabel()\0"
};

void ScreenshotWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ScreenshotWidget *_t = static_cast<ScreenshotWidget *>(_o);
        switch (_id) {
        case 0: _t->takeScreenshot(); break;
        case 1: _t->showScreenshot((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->saveScreenshot(); break;
        case 3: _t->refreshScreenshot(); break;
        case 4: _t->rotateLeft(); break;
        case 5: _t->rotateRight(); break;
        case 6: _t->updateScreenshotLabel(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ScreenshotWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ScreenshotWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ScreenshotWidget,
      qt_meta_data_ScreenshotWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ScreenshotWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ScreenshotWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ScreenshotWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ScreenshotWidget))
        return static_cast<void*>(const_cast< ScreenshotWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ScreenshotWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
