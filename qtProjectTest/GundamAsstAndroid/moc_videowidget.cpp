/****************************************************************************
** Meta object code from reading C++ file 'videowidget.h'
**
** Created: Sat Aug 2 16:56:17 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "widgets/videowidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'videowidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VideoWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   12,   13,   12, 0x0a,
      37,   33,   12,   12, 0x0a,
      55,   12,   12,   12, 0x0a,
      76,   71,   12,   12, 0x0a,
      98,   12,   12,   12, 0x0a,
     130,  114,   12,   12, 0x0a,
     155,   12,   12,   12, 0x0a,
     175,  166,   12,   12, 0x0a,
     207,  198,   12,   12, 0x0a,
     243,  238,   12,   12, 0x0a,
     275,  269,   12,   12, 0x0a,
     300,   12,   12,   12, 0x0a,
     311,   12,   12,   12, 0x0a,
     322,   12,   12,   12, 0x0a,
     335,   12,   12,   12, 0x0a,
     353,  345,   12,   12, 0x0a,
     378,  269,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_VideoWidget[] = {
    "VideoWidget\0\0int\0getVideoCount()\0num\0"
    "getVideoInfo(int)\0readVideoInfo()\0"
    "path\0getVideoFile(QString)\0readVideoFile()\0"
    "phonePath,pcDir\0getFile(QString,QString)\0"
    "readFile()\0fileName\0startTransfer(QString)\0"
    "numBytes\0updateTransferProgress(qint64)\0"
    "info\0insertTableRow(VideoInfo)\0index\0"
    "videoChange(QModelIndex)\0pushFile()\0"
    "pullFile()\0deleteFile()\0refresh()\0"
    "row,col\0checkBoxChanged(int,int)\0"
    "showVideoInfo(QModelIndex)\0"
};

void VideoWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        VideoWidget *_t = static_cast<VideoWidget *>(_o);
        switch (_id) {
        case 0: { int _r = _t->getVideoCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: _t->getVideoInfo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->readVideoInfo(); break;
        case 3: _t->getVideoFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->readVideoFile(); break;
        case 5: _t->getFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->readFile(); break;
        case 7: _t->startTransfer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->updateTransferProgress((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 9: _t->insertTableRow((*reinterpret_cast< VideoInfo(*)>(_a[1]))); break;
        case 10: _t->videoChange((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 11: _t->pushFile(); break;
        case 12: _t->pullFile(); break;
        case 13: _t->deleteFile(); break;
        case 14: _t->refresh(); break;
        case 15: _t->checkBoxChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 16: _t->showVideoInfo((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData VideoWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VideoWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_VideoWidget,
      qt_meta_data_VideoWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VideoWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VideoWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VideoWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VideoWidget))
        return static_cast<void*>(const_cast< VideoWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int VideoWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
