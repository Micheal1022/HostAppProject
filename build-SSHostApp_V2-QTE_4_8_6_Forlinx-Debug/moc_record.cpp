/****************************************************************************
** Meta object code from reading C++ file 'record.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SSHostApp_V2/Record/record.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'record.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Record[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x08,
      21,    7,    7,    7, 0x08,
      37,    7,    7,    7, 0x08,
      51,    7,    7,    7, 0x08,
      66,    7,    7,    7, 0x08,
      81,    7,    7,    7, 0x08,
     106,   97,    7,    7, 0x08,
     128,    7,    7,    7, 0x08,
     142,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Record[] = {
    "Record\0\0slotBtnDel()\0slotBtnAllDel()\0"
    "slotBtnBack()\0slotBtnPrint()\0"
    "slotBtnQuery()\0slotBtnFilter()\0queryStr\0"
    "slotSqlQuery(QString)\0slotBtnNest()\0"
    "slotBtnLast()\0"
};

void Record::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Record *_t = static_cast<Record *>(_o);
        switch (_id) {
        case 0: _t->slotBtnDel(); break;
        case 1: _t->slotBtnAllDel(); break;
        case 2: _t->slotBtnBack(); break;
        case 3: _t->slotBtnPrint(); break;
        case 4: _t->slotBtnQuery(); break;
        case 5: _t->slotBtnFilter(); break;
        case 6: _t->slotSqlQuery((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->slotBtnNest(); break;
        case 8: _t->slotBtnLast(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Record::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Record::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Record,
      qt_meta_data_Record, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Record::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Record::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Record::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Record))
        return static_cast<void*>(const_cast< Record*>(this));
    return QWidget::qt_metacast(_clname);
}

int Record::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
