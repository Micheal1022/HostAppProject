/****************************************************************************
** Meta object code from reading C++ file 'canrecvthread.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SSHostApp_V2/CanDataMgm/canrecvthread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'canrecvthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CanRecvThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   15,   14,   14, 0x05,
      47,   38,   14,   14, 0x05,
      89,   74,   14,   14, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_CanRecvThread[] = {
    "CanRecvThread\0\0loop\0sigHeartBeat(int)\0"
    "dataList\0sigSendCanData(QList<int>)\0"
    "cmd,type,value\0sigSendSetValue(int,int,int)\0"
};

void CanRecvThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CanRecvThread *_t = static_cast<CanRecvThread *>(_o);
        switch (_id) {
        case 0: _t->sigHeartBeat((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sigSendCanData((*reinterpret_cast< QList<int>(*)>(_a[1]))); break;
        case 2: _t->sigSendSetValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CanRecvThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CanRecvThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_CanRecvThread,
      qt_meta_data_CanRecvThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CanRecvThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CanRecvThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CanRecvThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CanRecvThread))
        return static_cast<void*>(const_cast< CanRecvThread*>(this));
    return QThread::qt_metacast(_clname);
}

int CanRecvThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void CanRecvThread::sigHeartBeat(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CanRecvThread::sigSendCanData(QList<int> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CanRecvThread::sigSendSetValue(int _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
