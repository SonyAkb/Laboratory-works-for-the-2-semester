/****************************************************************************
** Meta object code from reading C++ file 'main_window_1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../creative_works/main_window_1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window_1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Main_Window_1_t {
    QByteArrayData data[12];
    char stringdata0[189];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Main_Window_1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Main_Window_1_t qt_meta_stringdata_Main_Window_1 = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Main_Window_1"
QT_MOC_LITERAL(1, 14, 8), // "signal_1"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 7), // "Prices&"
QT_MOC_LITERAL(4, 32, 8), // "signal_3"
QT_MOC_LITERAL(5, 41, 6), // "House&"
QT_MOC_LITERAL(6, 48, 24), // "on_calculate_but_clicked"
QT_MOC_LITERAL(7, 73, 28), // "on_change_prices_but_clicked"
QT_MOC_LITERAL(8, 102, 24), // "on_save_data_but_clicked"
QT_MOC_LITERAL(9, 127, 27), // "on_pushButton_clear_clicked"
QT_MOC_LITERAL(10, 155, 26), // "on_pushButton_exit_clicked"
QT_MOC_LITERAL(11, 182, 6) // "slot_2"

    },
    "Main_Window_1\0signal_1\0\0Prices&\0"
    "signal_3\0House&\0on_calculate_but_clicked\0"
    "on_change_prices_but_clicked\0"
    "on_save_data_but_clicked\0"
    "on_pushButton_clear_clicked\0"
    "on_pushButton_exit_clicked\0slot_2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Main_Window_1[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    2,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   62,    2, 0x08 /* Private */,
       7,    0,   63,    2, 0x08 /* Private */,
       8,    0,   64,    2, 0x08 /* Private */,
       9,    0,   65,    2, 0x08 /* Private */,
      10,    0,   66,    2, 0x08 /* Private */,
      11,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Main_Window_1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Main_Window_1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_1((*reinterpret_cast< Prices(*)>(_a[1]))); break;
        case 1: _t->signal_3((*reinterpret_cast< Prices(*)>(_a[1])),(*reinterpret_cast< House(*)>(_a[2]))); break;
        case 2: _t->on_calculate_but_clicked(); break;
        case 3: _t->on_change_prices_but_clicked(); break;
        case 4: _t->on_save_data_but_clicked(); break;
        case 5: _t->on_pushButton_clear_clicked(); break;
        case 6: _t->on_pushButton_exit_clicked(); break;
        case 7: _t->slot_2(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Main_Window_1::*)(Prices & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Main_Window_1::signal_1)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Main_Window_1::*)(Prices & , House & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Main_Window_1::signal_3)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Main_Window_1::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_Main_Window_1.data,
    qt_meta_data_Main_Window_1,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Main_Window_1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Main_Window_1::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Main_Window_1.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Main_Window_1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Main_Window_1::signal_1(Prices & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Main_Window_1::signal_3(Prices & _t1, House & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
