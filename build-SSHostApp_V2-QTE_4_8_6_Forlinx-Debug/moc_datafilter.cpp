/****************************************************************************
** Meta object code from reading C++ file 'datafilter.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SSHostApp_V2/Record/datafilter.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datafilter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DataFilter[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      42,   11,   11,   11, 0x08,
      54,   11,   11,   11, 0x08,
      74,   68,   11,   11, 0x08,
      99,   92,   11,   11, 0x08,
     124,   92,   11,   11, 0x08,
     148,   68,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DataFilter[] = {
    "DataFilter\0\0queryStr\0sigSqlQuery(QString)\0"
    "slotBtnOk()\0slotBtnBack()\0index\0"
    "slotBtnIndex(int)\0enable\0"
    "slotSetCanIdEnable(bool)\0"
    "slotSetLoopEnable(bool)\0slotBtnKeyIndex(int)\0"
};

void DataFilter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DataFilter *_t = static_cast<DataFilter *>(_o);
        switch (_id) {
        case 0: _t->sigSqlQuery((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->slotBtnOk(); break;
        case 2: _t->slotBtnBack(); break;
        case 3: _t->slotBtnIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->slotSetCanIdEnable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->slotSetLoopEnable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->slotBtnKeyIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DataFilter::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DataFilter::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DataFilter,
      qt_meta_data_DataFilter, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DataFilter::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DataFilter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DataFilter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DataFilter))
        return static_cast<void*>(const_cast< DataFilter*>(this));
    return QWidget::qt_metacast(_clname);
}

int DataFilter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void DataFilter::sigSqlQuery(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
