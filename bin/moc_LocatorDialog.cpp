/****************************************************************************
** Meta object code from reading C++ file 'LocatorDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/LocatorDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LocatorDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LocatorDialog_t {
    QByteArrayData data[9];
    char stringdata[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_LocatorDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_LocatorDialog_t qt_meta_stringdata_LocatorDialog = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 21),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 23),
QT_MOC_LITERAL(4, 61, 23),
QT_MOC_LITERAL(5, 85, 11),
QT_MOC_LITERAL(6, 97, 11),
QT_MOC_LITERAL(7, 109, 12),
QT_MOC_LITERAL(8, 122, 23)
    },
    "LocatorDialog\0on_pushButton_clicked\0"
    "\0on_pushButton_3_clicked\0"
    "on_pushButton_2_clicked\0update_rect\0"
    "set_rect_In\0set_rect_Out\0"
    "on_pushButton_5_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LocatorDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08,
       3,    0,   50,    2, 0x08,
       4,    0,   51,    2, 0x08,
       5,    0,   52,    2, 0x08,
       6,    0,   53,    2, 0x08,
       7,    0,   54,    2, 0x08,
       8,    0,   55,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LocatorDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LocatorDialog *_t = static_cast<LocatorDialog *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_pushButton_3_clicked(); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->update_rect(); break;
        case 4: _t->set_rect_In(); break;
        case 5: _t->set_rect_Out(); break;
        case 6: _t->on_pushButton_5_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject LocatorDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_LocatorDialog.data,
      qt_meta_data_LocatorDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *LocatorDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LocatorDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LocatorDialog.stringdata))
        return static_cast<void*>(const_cast< LocatorDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int LocatorDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
