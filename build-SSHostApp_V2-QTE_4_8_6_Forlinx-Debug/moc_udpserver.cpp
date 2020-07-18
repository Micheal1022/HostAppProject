/****************************************************************************
** Meta object code from reading C++ file 'udpserver.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SSHostApp_V2/UDPServer/udpserver.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'udpserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_UDPServer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      22,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      32,   10,   10,   10, 0x08,
      91,   48,   10,   10, 0x08,
     204,  147,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_UDPServer[] = {
    "UDPServer\0\0sigReset()\0sigMute()\0"
    "slotReadReady()\0"
    "index,loop,canId,type,state,valueList,area\0"
    "slotSendCanData(int,int,int,int,int,QList<int>,QString)\0"
    "index,pass,canId,type,state,voltageList,currentList,area\0"
    "slotSendCanData(int,int,int,int,int,QList<int>,QList<qreal>,QString)\0"
};

void UDPServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        UDPServer *_t = static_cast<UDPServer *>(_o);
        switch (_id) {
        case 0: _t->sigReset(); break;
        case 1: _t->sigMute(); break;
        case 2: _t->slotReadReady(); break;
        case 3: _t->slotSendCanData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< QList<int>(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7]))); break;
        case 4: _t->slotSendCanData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< QList<int>(*)>(_a[6])),(*reinterpret_cast< QList<qreal>(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData UDPServer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject UDPServer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_UDPServer,
      qt_meta_data_UDPServer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &UDPServer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *UDPServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *UDPServer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UDPServer))
        return static_cast<void*>(const_cast< UDPServer*>(this));
    return QObject::qt_metacast(_clname);
}

int UDPServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void UDPServer::sigReset()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void UDPServer::sigMute()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
