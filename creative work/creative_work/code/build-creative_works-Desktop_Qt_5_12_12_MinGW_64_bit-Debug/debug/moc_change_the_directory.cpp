/****************************************************************************
** Meta object code from reading C++ file 'change_the_directory.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../creative_works/change_the_directory.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'change_the_directory.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_change_the_directory_t {
    QByteArrayData data[8];
    char stringdata0[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_change_the_directory_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_change_the_directory_t qt_meta_stringdata_change_the_directory = {
    {
QT_MOC_LITERAL(0, 0, 20), // "change_the_directory"
QT_MOC_LITERAL(1, 21, 8), // "signal_2"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 6), // "slot_1"
QT_MOC_LITERAL(4, 38, 7), // "Prices&"
QT_MOC_LITERAL(5, 46, 9), // "catalog_1"
QT_MOC_LITERAL(6, 56, 33), // "on_pushButton_change_cost_cli..."
QT_MOC_LITERAL(7, 90, 28) // "on_pushButton_cansel_clicked"

    },
    "change_the_directory\0signal_2\0\0slot_1\0"
    "Prices&\0catalog_1\0on_pushButton_change_cost_clicked\0"
    "on_pushButton_cansel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_change_the_directory[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   35,    2, 0x0a /* Public */,
       6,    0,   38,    2, 0x08 /* Private */,
       7,    0,   39,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void change_the_directory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<change_the_directory *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_2(); break;
        case 1: _t->slot_1((*reinterpret_cast< Prices(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_change_cost_clicked(); break;
        case 3: _t->on_pushButton_cansel_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (change_the_directory::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&change_the_directory::signal_2)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject change_the_directory::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_change_the_directory.data,
    qt_meta_data_change_the_directory,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *change_the_directory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *change_the_directory::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_change_the_directory.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int change_the_directory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void change_the_directory::signal_2()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
