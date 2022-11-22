/****************************************************************************
** Meta object code from reading C++ file 'ftproductsoverview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ftproductsoverview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ftproductsoverview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FtProductsOverview_t {
    QByteArrayData data[11];
    char stringdata0[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FtProductsOverview_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FtProductsOverview_t qt_meta_stringdata_FtProductsOverview = {
    {
QT_MOC_LITERAL(0, 0, 18), // "FtProductsOverview"
QT_MOC_LITERAL(1, 19, 18), // "on_pbClose_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 5), // "setup"
QT_MOC_LITERAL(4, 45, 16), // "on_rbAll_toggled"
QT_MOC_LITERAL(5, 62, 7), // "checked"
QT_MOC_LITERAL(6, 70, 17), // "on_rbVasi_toggled"
QT_MOC_LITERAL(7, 88, 18), // "on_rbTappi_toggled"
QT_MOC_LITERAL(8, 107, 9), // "queryLots"
QT_MOC_LITERAL(9, 117, 10), // "getDetails"
QT_MOC_LITERAL(10, 128, 1) // "i"

    },
    "FtProductsOverview\0on_pbClose_clicked\0"
    "\0setup\0on_rbAll_toggled\0checked\0"
    "on_rbVasi_toggled\0on_rbTappi_toggled\0"
    "queryLots\0getDetails\0i"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FtProductsOverview[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    1,   51,    2, 0x08 /* Private */,
       6,    1,   54,    2, 0x08 /* Private */,
       7,    1,   57,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    1,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,

       0        // eod
};

void FtProductsOverview::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FtProductsOverview *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pbClose_clicked(); break;
        case 1: _t->setup(); break;
        case 2: _t->on_rbAll_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_rbVasi_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_rbTappi_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->queryLots(); break;
        case 6: _t->getDetails((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FtProductsOverview::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_FtProductsOverview.data,
    qt_meta_data_FtProductsOverview,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FtProductsOverview::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FtProductsOverview::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FtProductsOverview.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FtProductsOverview::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
