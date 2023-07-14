/****************************************************************************
** Meta object code from reading C++ file 'ftraw.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ftraw.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ftraw.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FtRaw_t {
    QByteArrayData data[14];
    char stringdata0[179];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FtRaw_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FtRaw_t qt_meta_stringdata_FtRaw = {
    {
QT_MOC_LITERAL(0, 0, 5), // "FtRaw"
QT_MOC_LITERAL(1, 6, 14), // "get_Operations"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 18), // "on_pbClose_clicked"
QT_MOC_LITERAL(4, 41, 16), // "modify_operation"
QT_MOC_LITERAL(5, 58, 5), // "print"
QT_MOC_LITERAL(6, 64, 7), // "refresh"
QT_MOC_LITERAL(7, 72, 22), // "on_tvRaw_doubleClicked"
QT_MOC_LITERAL(8, 95, 11), // "QModelIndex"
QT_MOC_LITERAL(9, 107, 5), // "index"
QT_MOC_LITERAL(10, 113, 19), // "on_rbLabels_toggled"
QT_MOC_LITERAL(11, 133, 7), // "checked"
QT_MOC_LITERAL(12, 141, 18), // "on_rbVases_toggled"
QT_MOC_LITERAL(13, 160, 18) // "on_pbPrint_clicked"

    },
    "FtRaw\0get_Operations\0\0on_pbClose_clicked\0"
    "modify_operation\0print\0refresh\0"
    "on_tvRaw_doubleClicked\0QModelIndex\0"
    "index\0on_rbLabels_toggled\0checked\0"
    "on_rbVases_toggled\0on_pbPrint_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FtRaw[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    1,   64,    2, 0x08 /* Private */,
      10,    1,   67,    2, 0x08 /* Private */,
      12,    1,   70,    2, 0x08 /* Private */,
      13,    0,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void,

       0        // eod
};

void FtRaw::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FtRaw *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->get_Operations(); break;
        case 1: _t->on_pbClose_clicked(); break;
        case 2: _t->modify_operation(); break;
        case 3: _t->print(); break;
        case 4: _t->refresh(); break;
        case 5: _t->on_tvRaw_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->on_rbLabels_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_rbVases_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_pbPrint_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FtRaw::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_FtRaw.data,
    qt_meta_data_FtRaw,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FtRaw::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FtRaw::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FtRaw.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FtRaw::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
