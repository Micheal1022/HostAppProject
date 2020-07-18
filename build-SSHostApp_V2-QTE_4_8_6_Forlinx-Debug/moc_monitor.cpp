/****************************************************************************
** Meta object code from reading C++ file 'monitor.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SSHostApp_V2/Monitor/monitor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'monitor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Monitor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,
      23,    8,    8,    8, 0x05,
      47,   37,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      72,    8,    8,    8, 0x08,
      86,    8,    8,    8, 0x08,
     101,    8,    8,    8, 0x08,
     117,    8,    8,    8, 0x08,
     134,    8,    8,    8, 0x08,
     152,    8,    8,    8, 0x08,
     172,    8,    8,    8, 0x08,
     194,  189,    8,    8, 0x0a,
     222,  213,    8,    8, 0x0a,
     318,  250,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Monitor[] = {
    "Monitor\0\0sigBackHome()\0sigBtnReset()\0"
    "cmd,value\0sigSendSetValue(int,int)\0"
    "slotBtnMute()\0slotBtnReset()\0"
    "slotResetTime()\0slotSystemTime()\0"
    "slotBtnBackHome()\0slotBtnLoopSwitch()\0"
    "slotCanBusTime()\0loop\0slotHeartBeat(int)\0"
    "dataList\0slotRecvCanData(QList<int>)\0"
    "index,normalCount,alarmCount,errorCount,offLineCount,powerLostCount\0"
    "slotNodeInfoCount(int,int,int,int,int,int)\0"
};

void Monitor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Monitor *_t = static_cast<Monitor *>(_o);
        switch (_id) {
        case 0: _t->sigBackHome(); break;
        case 1: _t->sigBtnReset(); break;
        case 2: _t->sigSendSetValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->slotBtnMute(); break;
        case 4: _t->slotBtnReset(); break;
        case 5: _t->slotResetTime(); break;
        case 6: _t->slotSystemTime(); break;
        case 7: _t->slotBtnBackHome(); break;
        case 8: _t->slotBtnLoopSwitch(); break;
        case 9: _t->slotCanBusTime(); break;
        case 10: _t->slotHeartBeat((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->slotRecvCanData((*reinterpret_cast< QList<int>(*)>(_a[1]))); break;
        case 12: _t->slotNodeInfoCount((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Monitor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Monitor::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Monitor,
      qt_meta_data_Monitor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Monitor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Monitor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Monitor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Monitor))
        return static_cast<void*>(const_cast< Monitor*>(this));
    return QWidget::qt_metacast(_clname);
}

int Monitor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Monitor::sigBackHome()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Monitor::sigBtnReset()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Monitor::sigSendSetValue(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
