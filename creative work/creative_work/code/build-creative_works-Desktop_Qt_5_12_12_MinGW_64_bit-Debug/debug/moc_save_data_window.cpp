/****************************************************************************
** Meta object code from reading C++ file 'save_data_window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../creative_works/save_data_window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'save_data_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_save_data_window_t {
    QByteArrayData data[9];
    char stringdata0[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_save_data_window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_save_data_window_t qt_meta_stringdata_save_data_window = {
    {
QT_MOC_LITERAL(0, 0, 16), // "save_data_window"
QT_MOC_LITERAL(1, 17, 6), // "slot_3"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 7), // "Prices&"
QT_MOC_LITERAL(4, 33, 9), // "catalog_3"
QT_MOC_LITERAL(5, 43, 6), // "House&"
QT_MOC_LITERAL(6, 50, 7), // "house_3"
QT_MOC_LITERAL(7, 58, 28), // "on_pushButton_cansel_clicked"
QT_MOC_LITERAL(8, 87, 26) // "on_pushButton_save_clicked"

    },
    "save_data_window\0slot_3\0\0Prices&\0"
    "catalog_3\0House&\0house_3\0"
    "on_pushButton_cansel_clicked\0"
    "on_pushButton_save_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_save_data_window[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x0a /* Public */,
       7,    0,   34,    2, 0x08 /* Private */,
       8,    0,   35,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void save_data_window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<save_data_window *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_3((*reinterpret_cast< Prices(*)>(_a[1])),(*reinterpret_cast< House(*)>(_a[2]))); break;
        case 1: _t->on_pushButton_cansel_clicked(); break;
        case 2: _t->on_pushButton_save_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject save_data_window::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_save_data_window.data,
    qt_meta_data_save_data_window,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *save_data_window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *save_data_window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_save_data_window.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int save_data_window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
