/****************************************************************************
** Meta object code from reading C++ file 'node_ef.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../InspectionTooling/Node_EF/node_ef.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'node_ef.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Node_EF_t {
    QByteArrayData data[12];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Node_EF_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Node_EF_t qt_meta_stringdata_Node_EF = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Node_EF"
QT_MOC_LITERAL(1, 8, 10), // "sigBtnBack"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 8), // "sigStart"
QT_MOC_LITERAL(4, 29, 7), // "sigStop"
QT_MOC_LITERAL(5, 37, 10), // "sigLeakCmd"
QT_MOC_LITERAL(6, 48, 3), // "cmd"
QT_MOC_LITERAL(7, 52, 5), // "state"
QT_MOC_LITERAL(8, 58, 10), // "slotFunBtn"
QT_MOC_LITERAL(9, 69, 5), // "index"
QT_MOC_LITERAL(10, 75, 11), // "slotTypeBtn"
QT_MOC_LITERAL(11, 87, 11) // "slotTimeOut"

    },
    "Node_EF\0sigBtnBack\0\0sigStart\0sigStop\0"
    "sigLeakCmd\0cmd\0state\0slotFunBtn\0index\0"
    "slotTypeBtn\0slotTimeOut"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Node_EF[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,
       5,    2,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   57,    2, 0x08 /* Private */,
      10,    1,   60,    2, 0x08 /* Private */,
      11,    0,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,

       0        // eod
};

void Node_EF::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Node_EF *_t = static_cast<Node_EF *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigBtnBack(); break;
        case 1: _t->sigStart(); break;
        case 2: _t->sigStop(); break;
        case 3: _t->sigLeakCmd((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->slotFunBtn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->slotTypeBtn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->slotTimeOut(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Node_EF::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Node_EF::sigBtnBack)) {
                *result = 0;
            }
        }
        {
            typedef void (Node_EF::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Node_EF::sigStart)) {
                *result = 1;
            }
        }
        {
            typedef void (Node_EF::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Node_EF::sigStop)) {
                *result = 2;
            }
        }
        {
            typedef void (Node_EF::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Node_EF::sigLeakCmd)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject Node_EF::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Node_EF.data,
      qt_meta_data_Node_EF,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Node_EF::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Node_EF::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Node_EF.stringdata0))
        return static_cast<void*>(const_cast< Node_EF*>(this));
    return QWidget::qt_metacast(_clname);
}

int Node_EF::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Node_EF::sigBtnBack()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void Node_EF::sigStart()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Node_EF::sigStop()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void Node_EF::sigLeakCmd(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
