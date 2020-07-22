/****************************************************************************
** Meta object code from reading C++ file 'node_pm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../InspectionTooling/Node_PM/node_pm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'node_pm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Node_PM_t {
    QByteArrayData data[14];
    char stringdata0[129];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Node_PM_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Node_PM_t qt_meta_stringdata_Node_PM = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Node_PM"
QT_MOC_LITERAL(1, 8, 10), // "sigBtnBack"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 10), // "sigRunFlag"
QT_MOC_LITERAL(4, 31, 3), // "run"
QT_MOC_LITERAL(5, 35, 8), // "sigStart"
QT_MOC_LITERAL(6, 44, 3), // "cmd"
QT_MOC_LITERAL(7, 48, 13), // "sigCurrentCmd"
QT_MOC_LITERAL(8, 62, 13), // "sigVoltageCmd"
QT_MOC_LITERAL(9, 76, 11), // "slotGetData"
QT_MOC_LITERAL(10, 88, 11), // "slotTimeOut"
QT_MOC_LITERAL(11, 100, 10), // "slotFunBtn"
QT_MOC_LITERAL(12, 111, 5), // "index"
QT_MOC_LITERAL(13, 117, 11) // "slotTypeBtn"

    },
    "Node_PM\0sigBtnBack\0\0sigRunFlag\0run\0"
    "sigStart\0cmd\0sigCurrentCmd\0sigVoltageCmd\0"
    "slotGetData\0slotTimeOut\0slotFunBtn\0"
    "index\0slotTypeBtn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Node_PM[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    1,   60,    2, 0x06 /* Public */,
       5,    1,   63,    2, 0x06 /* Public */,
       7,    1,   66,    2, 0x06 /* Public */,
       8,    1,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   72,    2, 0x08 /* Private */,
      10,    0,   73,    2, 0x08 /* Private */,
      11,    1,   74,    2, 0x08 /* Private */,
      13,    1,   77,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,

       0        // eod
};

void Node_PM::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Node_PM *_t = static_cast<Node_PM *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigBtnBack(); break;
        case 1: _t->sigRunFlag((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->sigStart((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->sigCurrentCmd((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->sigVoltageCmd((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->slotGetData(); break;
        case 6: _t->slotTimeOut(); break;
        case 7: _t->slotFunBtn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->slotTypeBtn((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Node_PM::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Node_PM::sigBtnBack)) {
                *result = 0;
            }
        }
        {
            typedef void (Node_PM::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Node_PM::sigRunFlag)) {
                *result = 1;
            }
        }
        {
            typedef void (Node_PM::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Node_PM::sigStart)) {
                *result = 2;
            }
        }
        {
            typedef void (Node_PM::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Node_PM::sigCurrentCmd)) {
                *result = 3;
            }
        }
        {
            typedef void (Node_PM::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Node_PM::sigVoltageCmd)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject Node_PM::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Node_PM.data,
      qt_meta_data_Node_PM,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Node_PM::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Node_PM::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Node_PM.stringdata0))
        return static_cast<void*>(const_cast< Node_PM*>(this));
    return QWidget::qt_metacast(_clname);
}

int Node_PM::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Node_PM::sigBtnBack()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void Node_PM::sigRunFlag(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Node_PM::sigStart(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Node_PM::sigCurrentCmd(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Node_PM::sigVoltageCmd(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
