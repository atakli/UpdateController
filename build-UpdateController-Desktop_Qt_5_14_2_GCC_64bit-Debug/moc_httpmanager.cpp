/****************************************************************************
** Meta object code from reading C++ file 'httpmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../include/httpmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'httpmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HttpManager_t {
    QByteArrayData data[10];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HttpManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HttpManager_t qt_meta_stringdata_HttpManager = {
    {
QT_MOC_LITERAL(0, 0, 11), // "HttpManager"
QT_MOC_LITERAL(1, 12, 12), // "httpFinished"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 13), // "httpReadyRead"
QT_MOC_LITERAL(4, 40, 17), // "connectionControl"
QT_MOC_LITERAL(5, 58, 27), // "QNetworkReply::NetworkError"
QT_MOC_LITERAL(6, 86, 5), // "error"
QT_MOC_LITERAL(7, 92, 9), // "sslErrors"
QT_MOC_LITERAL(8, 102, 16), // "QList<QSslError>"
QT_MOC_LITERAL(9, 119, 6) // "errors"

    },
    "HttpManager\0httpFinished\0\0httpReadyRead\0"
    "connectionControl\0QNetworkReply::NetworkError\0"
    "error\0sslErrors\0QList<QSslError>\0"
    "errors"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HttpManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    1,   36,    2, 0x08 /* Private */,
       7,    1,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void HttpManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HttpManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->httpFinished(); break;
        case 1: _t->httpReadyRead(); break;
        case 2: _t->connectionControl((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 3: _t->sslErrors((*reinterpret_cast< const QList<QSslError>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QSslError> >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HttpManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_HttpManager.data,
    qt_meta_data_HttpManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HttpManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HttpManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HttpManager.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int HttpManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE