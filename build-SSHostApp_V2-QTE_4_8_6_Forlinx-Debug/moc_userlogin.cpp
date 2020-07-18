/****************************************************************************
** Meta object code from reading C++ file 'userlogin.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SSHostApp_V2/UserLogin/userlogin.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userlogin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_UserLogin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   11,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      34,   10,   10,   10, 0x08,
      46,   10,   10,   10, 0x08,
      60,   10,   10,   10, 0x08,
      75,   10,   10,   10, 0x08,
      96,   90,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_UserLogin[] = {
    "UserLogin\0\0user\0sigUserLogin(int)\0"
    "slotBtnOk()\0slotBtnBack()\0slotBtnAdmin()\0"
    "slotBtnSuper()\0index\0slotBtnKey(int)\0"
};

void UserLogin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        UserLogin *_t = static_cast<UserLogin *>(_o);
        switch (_id) {
        case 0: _t->sigUserLogin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->slotBtnOk(); break;
        case 2: _t->slotBtnBack(); break;
        case 3: _t->slotBtnAdmin(); break;
        case 4: _t->slotBtnSuper(); break;
        case 5: _t->slotBtnKey((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData UserLogin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject UserLogin::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_UserLogin,
      qt_meta_data_UserLogin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &UserLogin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *UserLogin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *UserLogin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UserLogin))
        return static_cast<void*>(const_cast< UserLogin*>(this));
    return QWidget::qt_metacast(_clname);
}

int UserLogin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void UserLogin::sigUserLogin(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
