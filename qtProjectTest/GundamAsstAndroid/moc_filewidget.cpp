/****************************************************************************
** Meta object code from reading C++ file 'filewidget.h'
**
** Created: Sat Aug 2 16:56:35 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "widgets/filewidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ThreadFind[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      28,   11,   11,   11, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ThreadFind[] = {
    "ThreadFind\0\0foundFile(File)\0finished()\0"
};

void ThreadFind::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ThreadFind *_t = static_cast<ThreadFind *>(_o);
        switch (_id) {
        case 0: _t->foundFile((*reinterpret_cast< File(*)>(_a[1]))); break;
        case 1: _t->finished(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ThreadFind::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ThreadFind::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ThreadFind,
      qt_meta_data_ThreadFind, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ThreadFind::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ThreadFind::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ThreadFind::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadFind))
        return static_cast<void*>(const_cast< ThreadFind*>(this));
    return QThread::qt_metacast(_clname);
}

int ThreadFind::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ThreadFind::foundFile(File _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ThreadFind::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
static const uint qt_meta_data_FileWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      67,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      50,   40,   11,   11, 0x05,
      73,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      91,   11,   11,   11, 0x0a,
     106,   11,   11,   11, 0x0a,
     134,  125,  120,   11, 0x0a,
     154,   11,   11,   11, 0x08,
     178,   11,   11,   11, 0x08,
     194,   11,   11,   11, 0x08,
     209,   11,   11,   11, 0x08,
     237,   11,   11,   11, 0x08,
     251,   11,   11,   11, 0x08,
     274,   11,   11,   11, 0x08,
     298,   11,   11,   11, 0x08,
     316,   11,   11,   11, 0x08,
     335,   11,   11,   11, 0x08,
     356,   11,   11,   11, 0x08,
     372,   11,   11,   11, 0x08,
     387,   11,   11,   11, 0x08,
     414,   11,   11,   11, 0x08,
     442,   11,   11,   11, 0x08,
     462,   11,   11,   11, 0x08,
     509,   11,   11,   11, 0x08,
     544,   11,   11,   11, 0x08,
     574,   11,   11,   11, 0x08,
     605,   11,   11,   11, 0x08,
     635,   11,   11,   11, 0x08,
     663,   11,   11,   11, 0x08,
     696,   11,   11,   11, 0x08,
     726,   11,   11,   11, 0x08,
     763,   11,   11,   11, 0x08,
     799,   11,   11,   11, 0x08,
     816,   11,   11,   11, 0x08,
     831,   11,   11,   11, 0x08,
     848,   11,   11,   11, 0x08,
     865,   11,   11,   11, 0x08,
     901,  887,   11,   11, 0x08,
     945,   11,   11,   11, 0x08,
     978,  976,   11,   11, 0x08,
    1018,   11,   11,   11, 0x08,
    1043,   11,   11,   11, 0x08,
    1058,   11,   11,   11, 0x08,
    1075,   11,   11,   11, 0x08,
    1096,   11,   11,   11, 0x08,
    1121,   11,   11,   11, 0x08,
    1137,   11,   11,   11, 0x08,
    1151,   11,   11,   11, 0x08,
    1171,   11,   11,   11, 0x08,
    1195,   11,   11,   11, 0x08,
    1210,   11,   11,   11, 0x08,
    1224,   11,   11,   11, 0x08,
    1236,   11,   11,   11, 0x08,
    1250,   11,   11,   11, 0x08,
    1264,   11,   11,   11, 0x08,
    1283,  887,   11,   11, 0x08,
    1324,   11,   11,   11, 0x08,
    1350,  976,   11,   11, 0x08,
    1387,   11,   11,   11, 0x08,
    1407,   11,   11,   11, 0x08,
    1432,   11,   11,   11, 0x08,
    1457,   11,   11,   11, 0x08,
    1480,   11,   11,   11, 0x08,
    1504,   11,   11,   11, 0x08,
    1533, 1528,   11,   11, 0x08,
    1565, 1528,   11,   11, 0x08,
    1594, 1528,   11,   11, 0x08,
    1627,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FileWidget[] = {
    "FileWidget\0\0phoneConnectionChanged(int)\0"
    "value,max\0progressValue(int,int)\0"
    "copyFinished(int)\0rightDisplay()\0"
    "leftDisplay()\0App*\0filePath\0"
    "getAppInfo(QString)\0on_pushButton_pressed()\0"
    "foundFile(File)\0findFinished()\0"
    "on_toolButtonFind_pressed()\0showAppInfo()\0"
    "setLeftFilter(QString)\0setRightFilter(QString)\0"
    "leftDoubleClick()\0rightDoubleClick()\0"
    "leftComboBoxScroll()\0rightComboBox()\0"
    "leftComboBox()\0leftTableWidgetActivated()\0"
    "rightTableWidgetActivated()\0"
    "connectionChanged()\0"
    "on_leftPushButtonPhoneComputerSwitch_pressed()\0"
    "on_pushButtonHiddenFiles_pressed()\0"
    "on_pushButtonDelete_pressed()\0"
    "on_pushButtonRefresh_pressed()\0"
    "on_pushButtonNewDir_pressed()\0"
    "on_pushButtonCopy_pressed()\0"
    "on_pushButtonSelectAll_pressed()\0"
    "on_pushButtonRename_pressed()\0"
    "on_rightPushButtonFolderUp_pressed()\0"
    "on_leftPushButtonFolderUp_pressed()\0"
    "computerRename()\0computerCopy()\0"
    "computerNewDir()\0computerDelete()\0"
    "computerHiddenFiles()\0indexS,indexE\0"
    "computerRenameSlot(QModelIndex,QModelIndex)\0"
    "computerDisplay(QTableWidget*)\0,\0"
    "computerContextMenu(QPoint,QTableView*)\0"
    "installAppFromComputer()\0rightRefresh()\0"
    "rightSelectAll()\0rightSelectedCount()\0"
    "rightContextMenu(QPoint)\0leftSelectAll()\0"
    "leftRefresh()\0leftSelectedCount()\0"
    "leftContextMenu(QPoint)\0phoneGoToDir()\0"
    "phoneRename()\0phoneCopy()\0phoneNewDir()\0"
    "phoneDelete()\0phoneHiddenFiles()\0"
    "phoneRenameSlot(QModelIndex,QModelIndex)\0"
    "phoneDisplay(QTableView*)\0"
    "phoneContextMenu(QPoint,QTableView*)\0"
    "phoneOpenInNewTab()\0rightTabBarPageChanged()\0"
    "rightTabBarCloseTab(int)\0"
    "computerOpenInNewTab()\0leftTabBarPageChanged()\0"
    "leftTabBarCloseTab(int)\0list\0"
    "copySlotToComputer(QStringList)\0"
    "copySlotToPhone(QStringList)\0"
    "copySlotToPhoneLeft(QStringList)\0"
    "on_pushButtonRefresh_2_pressed()\0"
};

void FileWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FileWidget *_t = static_cast<FileWidget *>(_o);
        switch (_id) {
        case 0: _t->phoneConnectionChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->progressValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->copyFinished((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->rightDisplay(); break;
        case 4: _t->leftDisplay(); break;
        case 5: { App* _r = _t->getAppInfo((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< App**>(_a[0]) = _r; }  break;
        case 6: _t->on_pushButton_pressed(); break;
        case 7: _t->foundFile((*reinterpret_cast< File(*)>(_a[1]))); break;
        case 8: _t->findFinished(); break;
        case 9: _t->on_toolButtonFind_pressed(); break;
        case 10: _t->showAppInfo(); break;
        case 11: _t->setLeftFilter((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->setRightFilter((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->leftDoubleClick(); break;
        case 14: _t->rightDoubleClick(); break;
        case 15: _t->leftComboBoxScroll(); break;
        case 16: _t->rightComboBox(); break;
        case 17: _t->leftComboBox(); break;
        case 18: _t->leftTableWidgetActivated(); break;
        case 19: _t->rightTableWidgetActivated(); break;
        case 20: _t->connectionChanged(); break;
        case 21: _t->on_leftPushButtonPhoneComputerSwitch_pressed(); break;
        case 22: _t->on_pushButtonHiddenFiles_pressed(); break;
        case 23: _t->on_pushButtonDelete_pressed(); break;
        case 24: _t->on_pushButtonRefresh_pressed(); break;
        case 25: _t->on_pushButtonNewDir_pressed(); break;
        case 26: _t->on_pushButtonCopy_pressed(); break;
        case 27: _t->on_pushButtonSelectAll_pressed(); break;
        case 28: _t->on_pushButtonRename_pressed(); break;
        case 29: _t->on_rightPushButtonFolderUp_pressed(); break;
        case 30: _t->on_leftPushButtonFolderUp_pressed(); break;
        case 31: _t->computerRename(); break;
        case 32: _t->computerCopy(); break;
        case 33: _t->computerNewDir(); break;
        case 34: _t->computerDelete(); break;
        case 35: _t->computerHiddenFiles(); break;
        case 36: _t->computerRenameSlot((*reinterpret_cast< QModelIndex(*)>(_a[1])),(*reinterpret_cast< QModelIndex(*)>(_a[2]))); break;
        case 37: _t->computerDisplay((*reinterpret_cast< QTableWidget*(*)>(_a[1]))); break;
        case 38: _t->computerContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1])),(*reinterpret_cast< QTableView*(*)>(_a[2]))); break;
        case 39: _t->installAppFromComputer(); break;
        case 40: _t->rightRefresh(); break;
        case 41: _t->rightSelectAll(); break;
        case 42: _t->rightSelectedCount(); break;
        case 43: _t->rightContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 44: _t->leftSelectAll(); break;
        case 45: _t->leftRefresh(); break;
        case 46: _t->leftSelectedCount(); break;
        case 47: _t->leftContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 48: _t->phoneGoToDir(); break;
        case 49: _t->phoneRename(); break;
        case 50: _t->phoneCopy(); break;
        case 51: _t->phoneNewDir(); break;
        case 52: _t->phoneDelete(); break;
        case 53: _t->phoneHiddenFiles(); break;
        case 54: _t->phoneRenameSlot((*reinterpret_cast< QModelIndex(*)>(_a[1])),(*reinterpret_cast< QModelIndex(*)>(_a[2]))); break;
        case 55: _t->phoneDisplay((*reinterpret_cast< QTableView*(*)>(_a[1]))); break;
        case 56: _t->phoneContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1])),(*reinterpret_cast< QTableView*(*)>(_a[2]))); break;
        case 57: _t->phoneOpenInNewTab(); break;
        case 58: _t->rightTabBarPageChanged(); break;
        case 59: _t->rightTabBarCloseTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 60: _t->computerOpenInNewTab(); break;
        case 61: _t->leftTabBarPageChanged(); break;
        case 62: _t->leftTabBarCloseTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 63: _t->copySlotToComputer((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 64: _t->copySlotToPhone((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 65: _t->copySlotToPhoneLeft((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 66: _t->on_pushButtonRefresh_2_pressed(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData FileWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FileWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FileWidget,
      qt_meta_data_FileWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FileWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FileWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FileWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FileWidget))
        return static_cast<void*>(const_cast< FileWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int FileWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 67)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 67;
    }
    return _id;
}

// SIGNAL 0
void FileWidget::phoneConnectionChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FileWidget::progressValue(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FileWidget::copyFinished(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
