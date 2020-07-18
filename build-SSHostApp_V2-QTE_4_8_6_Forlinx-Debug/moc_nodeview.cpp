/****************************************************************************
** Meta object code from reading C++ file 'nodeview.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SSHostApp_V2/Monitor/nodeview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nodeview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NodeView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   10,    9,    9, 0x05,
      45,   10,    9,    9, 0x05,
      68,   10,    9,    9, 0x05,
      98,   93,    9,    9, 0x05,
     158,  115,    9,    9, 0x05,
     258,  215,    9,    9, 0x05,
     381,  313,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
     430,  423,    9,    9, 0x08,
     452,    9,    9,    9, 0x08,
     467,    9,    9,    9, 0x08,
     482,    9,    9,    9, 0x08,
     498,    9,    9,    9, 0x08,
     514,    9,    9,    9, 0x08,
     532,    9,    9,    9, 0x08,
     549,    9,    9,    9, 0x08,
     568,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NodeView[] = {
    "NodeView\0\0index,count\0sigAlarmCount(int,int)\0"
    "sigErrorCount(int,int)\0sigOffLineCount(int,int)\0"
    "step\0sigSetValue(int)\0"
    "loop,type,state,canId,value,pass,time,area\0"
    "sigInsertAlarmInfo(int,int,int,int,int,int,uint,QString)\0"
    "index,loop,canId,type,state,valueList,area\0"
    "sigSendUdpData(int,int,int,int,int,QList<int>,QString)\0"
    "index,normalCount,alarmCount,errorCount,offLineCount,powerLostCount\0"
    "sigNodeInfoCount(int,int,int,int,int,int)\0"
    "curBtn\0slotNodeBtnGroup(int)\0"
    "slotLastPage()\0slotNestPage()\0"
    "slotAlarmInfo()\0slotErrorInfo()\0"
    "slotOffLineInfo()\0slotHeartTimer()\0"
    "slotUdpDateTimer()\0slotReset()\0"
};

void NodeView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NodeView *_t = static_cast<NodeView *>(_o);
        switch (_id) {
        case 0: _t->sigAlarmCount((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->sigErrorCount((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->sigOffLineCount((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->sigSetValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->sigInsertAlarmInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< uint(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8]))); break;
        case 5: _t->sigSendUdpData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< QList<int>(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7]))); break;
        case 6: _t->sigNodeInfoCount((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        case 7: _t->slotNodeBtnGroup((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->slotLastPage(); break;
        case 9: _t->slotNestPage(); break;
        case 10: _t->slotAlarmInfo(); break;
        case 11: _t->slotErrorInfo(); break;
        case 12: _t->slotOffLineInfo(); break;
        case 13: _t->slotHeartTimer(); break;
        case 14: _t->slotUdpDateTimer(); break;
        case 15: _t->slotReset(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData NodeView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject NodeView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_NodeView,
      qt_meta_data_NodeView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NodeView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NodeView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NodeView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NodeView))
        return static_cast<void*>(const_cast< NodeView*>(this));
    return QWidget::qt_metacast(_clname);
}

int NodeView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void NodeView::sigAlarmCount(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NodeView::sigErrorCount(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void NodeView::sigOffLineCount(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void NodeView::sigSetValue(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void NodeView::sigInsertAlarmInfo(int _t1, int _t2, int _t3, int _t4, int _t5, int _t6, uint _t7, QString _t8)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void NodeView::sigSendUdpData(int _t1, int _t2, int _t3, int _t4, int _t5, QList<int> _t6, QString _t7)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void NodeView::sigNodeInfoCount(int _t1, int _t2, int _t3, int _t4, int _t5, int _t6)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
