/****************************************************************************
** Meta object code from reading C++ file 'qttcpsocekt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../qttcpsocekt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qttcpsocekt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_XSocketClient_t {
    QByteArrayData data[10];
    char stringdata0[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_XSocketClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_XSocketClient_t qt_meta_stringdata_XSocketClient = {
    {
QT_MOC_LITERAL(0, 0, 13), // "XSocketClient"
QT_MOC_LITERAL(1, 14, 19), // "signalOnReceiveData"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 2), // "by"
QT_MOC_LITERAL(4, 38, 17), // "signalOnConnected"
QT_MOC_LITERAL(5, 56, 20), // "signalOnDisconnected"
QT_MOC_LITERAL(6, 77, 6), // "OnData"
QT_MOC_LITERAL(7, 84, 11), // "OnConnected"
QT_MOC_LITERAL(8, 96, 14), // "OnDisconnected"
QT_MOC_LITERAL(9, 111, 11) // "OnDataReady"

    },
    "XSocketClient\0signalOnReceiveData\0\0"
    "by\0signalOnConnected\0signalOnDisconnected\0"
    "OnData\0OnConnected\0OnDisconnected\0"
    "OnDataReady"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_XSocketClient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    0,   52,    2, 0x06 /* Public */,
       5,    0,   53,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   54,    2, 0x09 /* Protected */,
       7,    0,   57,    2, 0x09 /* Protected */,
       8,    0,   58,    2, 0x09 /* Protected */,
       9,    0,   59,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void XSocketClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<XSocketClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalOnReceiveData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->signalOnConnected(); break;
        case 2: _t->signalOnDisconnected(); break;
        case 3: _t->OnData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: _t->OnConnected(); break;
        case 5: _t->OnDisconnected(); break;
        case 6: _t->OnDataReady(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (XSocketClient::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XSocketClient::signalOnReceiveData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (XSocketClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XSocketClient::signalOnConnected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (XSocketClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XSocketClient::signalOnDisconnected)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject XSocketClient::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_XSocketClient.data,
    qt_meta_data_XSocketClient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *XSocketClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XSocketClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_XSocketClient.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int XSocketClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void XSocketClient::signalOnReceiveData(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void XSocketClient::signalOnConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void XSocketClient::signalOnDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
