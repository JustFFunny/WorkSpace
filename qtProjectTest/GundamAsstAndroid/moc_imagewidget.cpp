/****************************************************************************
** Meta object code from reading C++ file 'imagewidget.h'
**
** Created: Sat Aug 2 16:56:33 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "widgets/imagewidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imagewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ImageWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   13,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      48,   12,   44,   12, 0x0a,
      69,   65,   12,   12, 0x0a,
      87,   12,   12,   12, 0x0a,
     108,  103,   12,   12, 0x0a,
     130,   12,   12,   12, 0x0a,
     162,  146,   12,   12, 0x0a,
     187,   12,   12,   12, 0x0a,
     207,  198,   12,   12, 0x0a,
     239,  230,   12,   12, 0x0a,
     270,   12,   12,   12, 0x0a,
     302,  296,   12,   12, 0x0a,
     327,   12,   12,   12, 0x0a,
     338,   12,   12,   12, 0x0a,
     357,  349,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ImageWidget[] = {
    "ImageWidget\0\0list\0getFilePaths(QStringList)\0"
    "int\0getImagetCount()\0num\0GetImageInfo(int)\0"
    "readImageInfo()\0path\0GetImageFile(QString)\0"
    "readImageFile()\0phonePath,pcDir\0"
    "getFile(QString,QString)\0readFile()\0"
    "fileName\0startTransfer(QString)\0"
    "numBytes\0updateTransferProgress(qint64)\0"
    "insertTableRow(ImageInfo)\0index\0"
    "ImageChange(QModelIndex)\0PushFile()\0"
    "PullFile()\0row,col\0CheckBoxChanged(int,int)\0"
};

void ImageWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ImageWidget *_t = static_cast<ImageWidget *>(_o);
        switch (_id) {
        case 0: _t->getFilePaths((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 1: { int _r = _t->getImagetCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: _t->GetImageInfo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->readImageInfo(); break;
        case 4: _t->GetImageFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->readImageFile(); break;
        case 6: _t->getFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: _t->readFile(); break;
        case 8: _t->startTransfer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->updateTransferProgress((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 10: _t->insertTableRow((*reinterpret_cast< ImageInfo(*)>(_a[1]))); break;
        case 11: _t->ImageChange((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 12: _t->PushFile(); break;
        case 13: _t->PullFile(); break;
        case 14: _t->CheckBoxChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ImageWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ImageWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ImageWidget,
      qt_meta_data_ImageWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ImageWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ImageWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ImageWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ImageWidget))
        return static_cast<void*>(const_cast< ImageWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ImageWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void ImageWidget::getFilePaths(QStringList _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
