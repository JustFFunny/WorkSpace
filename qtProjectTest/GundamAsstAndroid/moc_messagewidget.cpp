/****************************************************************************
** Meta object code from reading C++ file 'messagewidget.h'
**
** Created: Sat Aug 2 16:56:30 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "widgets/messagewidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'messagewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MessageWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      27,   15,   14,   14, 0x05,
      63,   56,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      88,   14,   14,   14, 0x08,
     162,  112,   14,   14, 0x08,
     227,  112,   14,   14, 0x08,
     291,   14,   14,   14, 0x08,
     320,  305,   14,   14, 0x08,
     363,  356,   14,   14, 0x0a,
     387,  356,   14,   14, 0x0a,
     411,   14,   14,   14, 0x0a,
     436,  428,   14,   14, 0x0a,
     474,  459,   14,   14, 0x0a,
     499,   15,   14,   14, 0x0a,
     559,  532,   14,   14, 0x0a,
     612,   56,   14,   14, 0x0a,
     634,  631,   14,   14, 0x0a,
     661,  631,   14,   14, 0x0a,
     696,  687,   14,   14, 0x0a,
     710,   14,   14,   14, 0x0a,
     728,   14,   14,   14, 0x0a,
     749,  744,   14,   14, 0x0a,
     789,  779,  771,   14, 0x0a,
     859,  819,   14,   14, 0x0a,
     913,   14,   14,   14, 0x0a,
     924,   14,   14,   14, 0x0a,
     943,  938,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MessageWidget[] = {
    "MessageWidget\0\0number,body\0"
    "smsReceived(QString,QString)\0result\0"
    "smsResultSignal(QString)\0"
    "on_pushButton_pressed()\0"
    "threadId,messageId,timestamp,number,read,toa,body\0"
    "smsRead(QString,QString,QString,QString,QString,QString,QString)\0"
    "addSMS(QString,QString,QString,QString,QString,QString,QString)\0"
    "clearModels()\0id,number,name\0"
    "addContact(QString,QString,QString)\0"
    "filter\0filterMessages(QString)\0"
    "filterContacts(QString)\0getContactList()\0"
    "message\0sendSmsThread(QString)\0"
    "number,message\0sendSms(QString,QString)\0"
    "smsReceivedSlot(QString,QString)\0"
    "number,body,timestamp,type\0"
    "insertSmsToDatabase(QString,QString,QString,QString)\0"
    "smsResult(QString)\0id\0markMessageAsRead(QString)\0"
    "markThreadAsRead(QString)\0threadId\0"
    "sort(QString)\0connectToClient()\0"
    "newConnection()\0mesg\0sendToClient(QString)\0"
    "QString\0timestamp\0getDateFromTimestamp(QString)\0"
    "id,timestamp,lastBody,messageCount,read\0"
    "updateThread(QString,QString,QString,QString,QString)\0"
    "readMesg()\0readFinshed()\0info\0"
    "readData(QString)\0"
};

void MessageWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MessageWidget *_t = static_cast<MessageWidget *>(_o);
        switch (_id) {
        case 0: _t->smsReceived((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->smsResultSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_pressed(); break;
        case 3: _t->smsRead((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7]))); break;
        case 4: _t->addSMS((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7]))); break;
        case 5: _t->clearModels(); break;
        case 6: _t->addContact((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 7: _t->filterMessages((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->filterContacts((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->getContactList(); break;
        case 10: _t->sendSmsThread((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->sendSms((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 12: _t->smsReceivedSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 13: _t->insertSmsToDatabase((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 14: _t->smsResult((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->markMessageAsRead((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: _t->markThreadAsRead((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: _t->sort((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: _t->connectToClient(); break;
        case 19: _t->newConnection(); break;
        case 20: _t->sendToClient((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 21: { QString _r = _t->getDateFromTimestamp((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 22: _t->updateThread((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 23: _t->readMesg(); break;
        case 24: _t->readFinshed(); break;
        case 25: _t->readData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MessageWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MessageWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MessageWidget,
      qt_meta_data_MessageWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MessageWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MessageWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MessageWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MessageWidget))
        return static_cast<void*>(const_cast< MessageWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int MessageWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    }
    return _id;
}

// SIGNAL 0
void MessageWidget::smsReceived(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MessageWidget::smsResultSignal(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
