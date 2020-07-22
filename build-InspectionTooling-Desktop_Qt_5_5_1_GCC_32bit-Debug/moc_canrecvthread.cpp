/****************************************************************************
** Meta object code from reading C++ file 'canrecvthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../InspectionTooling/CanDataMgm/canrecvthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'canrecvthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CanRecvThread_t {
    QByteArrayData data[11];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CanRecvThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CanRecvThread_t qt_meta_stringdata_CanRecvThread = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CanRecvThread"
QT_MOC_LITERAL(1, 14, 12), // "sigHeartBeat"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 4), // "loop"
QT_MOC_LITERAL(4, 33, 14), // "sigSendCanData"
QT_MOC_LITERAL(5, 48, 10), // "QList<int>"
QT_MOC_LITERAL(6, 59, 8), // "dataList"
QT_MOC_LITERAL(7, 68, 15), // "sigSendSetValue"
QT_MOC_LITERAL(8, 84, 3), // "cmd"
QT_MOC_LITERAL(9, 88, 4), // "type"
QT_MOC_LITERAL(10, 93, 5) // "value"

    },
    "CanRecvThread\0sigHeartBeat\0\0loop\0"
    "sigSendCanData\0QList<int>\0dataList\0"
    "sigSendSetValue\0cmd\0type\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CanRecvThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,
       7,    3,   35,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    8,    9,   10,

       0        // eod
};

void CanRecvThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CanRecvThread *_t = static_cast<CanRecvThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigHeartBeat((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sigSendCanData((*reinterpret_cast< QList<int>(*)>(_a[1]))); break;
        case 2: _t->sigSendSetValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CanRecvThread::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CanRecvThread::sigHeartBeat)) {
                *result = 0;
            }
        }
        {
            typedef void (CanRecvThread::*_t)(QList<int> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CanRecvThread::sigSendCanData)) {
                *result = 1;
            }
        }
        {
            typedef void (CanRecvThread::*_t)(int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CanRecvThread::sigSendSetValue)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject CanRecvThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_CanRecvThread.data,
      qt_meta_data_CanRecvThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CanRecvThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CanRecvThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CanRecvThread.stringdata0))
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
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void CanRecvThread::sigHeartBeat(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CanRecvThread::sigSendCanData(QList<int> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CanRecvThread::sigSendSetValue(int _t1, int _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
