/****************************************************************************
** Meta object code from reading C++ file 'rs485.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SSHostApp_V2/RS485/rs485.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rs485.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RS485[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x05,
      17,    6,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
      33,   28,    6,    6, 0x0a,
      84,   64,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_RS485[] = {
    "RS485\0\0sigMute()\0sigReset()\0data\0"
    "slotUpdateNodeSts(QList<uint>)\0"
    "mainPower,backPower\0slotUpdatePowerSts(int,int)\0"
};

void RS485::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RS485 *_t = static_cast<RS485 *>(_o);
        switch (_id) {
        case 0: _t->sigMute(); break;
        case 1: _t->sigReset(); break;
        case 2: _t->slotUpdateNodeSts((*reinterpret_cast< QList<uint>(*)>(_a[1]))); break;
        case 3: _t->slotUpdatePowerSts((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RS485::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RS485::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RS485,
      qt_meta_data_RS485, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RS485::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RS485::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RS485::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RS485))
        return static_cast<void*>(const_cast< RS485*>(this));
    return QObject::qt_metacast(_clname);
}

int RS485::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void RS485::sigMute()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void RS485::sigReset()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
