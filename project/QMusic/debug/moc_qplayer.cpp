/****************************************************************************
** Meta object code from reading C++ file 'qplayer.h'
**
** Created: Thu Jan 7 10:28:03 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qplayer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qplayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QPlayer[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      31,    8,    8,    8, 0x08,
      57,    8,    8,    8, 0x08,
      81,    8,    8,    8, 0x08,
     106,    8,    8,    8, 0x08,
     130,    8,    8,    8, 0x08,
     154,    8,    8,    8, 0x08,
     179,    8,    8,    8, 0x08,
     203,    8,    8,    8, 0x08,
     227,    8,    8,    8, 0x08,
     250,    8,    8,    8, 0x08,
     261,    8,    8,    8, 0x08,
     272,    8,    8,    8, 0x08,
     283,    8,    8,    8, 0x08,
     299,    8,    8,    8, 0x08,
     310,    8,    8,    8, 0x08,
     323,    8,    8,    8, 0x08,
     343,  333,    8,    8, 0x08,
     385,  333,    8,    8, 0x08,
     438,  431,    8,    8, 0x08,
     478,  473,    8,    8, 0x08,
     500,    8,    8,    8, 0x08,
     515,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QPlayer[] = {
    "QPlayer\0\0on_MuButton_clicked()\0"
    "on_RemoveButton_clicked()\0"
    "on_pushButton_clicked()\0"
    "on_StyleButton_clicked()\0"
    "on_PrevButton_clicked()\0on_NextButton_clicked()\0"
    "on_PauseButton_clicked()\0"
    "on_StopButton_clicked()\0on_PlayButton_clicked()\0"
    "on_AddButton_clicked()\0addFiles()\0"
    "nextFile()\0prevFile()\0aboutToFinish()\0"
    "finished()\0tick(qint64)\0rndFile()\0"
    "newState,\0stateChanged(Phonon::State,Phonon::State)\0"
    "metaStateChanged(Phonon::State,Phonon::State)\0"
    "source\0sourceChanged(Phonon::MediaSource)\0"
    "row,\0tableClicked(int,int)\0setupActions()\0"
    "removeFiles()\0"
};

const QMetaObject QPlayer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QPlayer,
      qt_meta_data_QPlayer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QPlayer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QPlayer))
        return static_cast<void*>(const_cast< QPlayer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int QPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_MuButton_clicked(); break;
        case 1: on_RemoveButton_clicked(); break;
        case 2: on_pushButton_clicked(); break;
        case 3: on_StyleButton_clicked(); break;
        case 4: on_PrevButton_clicked(); break;
        case 5: on_NextButton_clicked(); break;
        case 6: on_PauseButton_clicked(); break;
        case 7: on_StopButton_clicked(); break;
        case 8: on_PlayButton_clicked(); break;
        case 9: on_AddButton_clicked(); break;
        case 10: addFiles(); break;
        case 11: nextFile(); break;
        case 12: prevFile(); break;
        case 13: aboutToFinish(); break;
        case 14: finished(); break;
        case 15: tick((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 16: rndFile(); break;
        case 17: stateChanged((*reinterpret_cast< Phonon::State(*)>(_a[1])),(*reinterpret_cast< Phonon::State(*)>(_a[2]))); break;
        case 18: metaStateChanged((*reinterpret_cast< Phonon::State(*)>(_a[1])),(*reinterpret_cast< Phonon::State(*)>(_a[2]))); break;
        case 19: sourceChanged((*reinterpret_cast< const Phonon::MediaSource(*)>(_a[1]))); break;
        case 20: tableClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 21: setupActions(); break;
        case 22: removeFiles(); break;
        default: ;
        }
        _id -= 23;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
