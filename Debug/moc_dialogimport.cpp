/****************************************************************************
** Meta object code from reading C++ file 'dialogimport.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/dialogimport.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogimport.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DialogImport_t {
    QByteArrayData data[27];
    char stringdata[361];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_DialogImport_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_DialogImport_t qt_meta_stringdata_DialogImport = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 20),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 15),
QT_MOC_LITERAL(4, 51, 25),
QT_MOC_LITERAL(5, 77, 4),
QT_MOC_LITERAL(6, 82, 10),
QT_MOC_LITERAL(7, 93, 3),
QT_MOC_LITERAL(8, 97, 7),
QT_MOC_LITERAL(9, 105, 15),
QT_MOC_LITERAL(10, 121, 14),
QT_MOC_LITERAL(11, 136, 14),
QT_MOC_LITERAL(12, 151, 15),
QT_MOC_LITERAL(13, 167, 14),
QT_MOC_LITERAL(14, 182, 14),
QT_MOC_LITERAL(15, 197, 16),
QT_MOC_LITERAL(16, 214, 15),
QT_MOC_LITERAL(17, 230, 15),
QT_MOC_LITERAL(18, 246, 20),
QT_MOC_LITERAL(19, 267, 14),
QT_MOC_LITERAL(20, 282, 12),
QT_MOC_LITERAL(21, 295, 10),
QT_MOC_LITERAL(22, 306, 11),
QT_MOC_LITERAL(23, 318, 12),
QT_MOC_LITERAL(24, 331, 16),
QT_MOC_LITERAL(25, 348, 6),
QT_MOC_LITERAL(26, 355, 4)
    },
    "DialogImport\0on_btnBrowse_clicked\0\0"
    "changeSeparator\0on_lineStart_valueChanged\0"
    "arg1\0tblCtxMenu\0pos\0cctHide\0cctSupplierName\0"
    "cctSupplierInn\0cctSupplierKpp\0"
    "cctProducerName\0cctProducerInn\0"
    "cctProducerKpp\0cctLicenseNumber\0"
    "cctLicenseSDate\0cctLicenseEDate\0"
    "cctLicenseDepartment\0cctProductType\0"
    "cctTtnNumber\0cctTtnDate\0cctTdNumber\0"
    "cctNumberDkl\0changeColumnType\0column\0"
    "type\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogImport[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  119,    2, 0x08,
       3,    0,  120,    2, 0x08,
       4,    1,  121,    2, 0x08,
       6,    1,  124,    2, 0x08,
       8,    0,  127,    2, 0x08,
       9,    0,  128,    2, 0x08,
      10,    0,  129,    2, 0x08,
      11,    0,  130,    2, 0x08,
      12,    0,  131,    2, 0x08,
      13,    0,  132,    2, 0x08,
      14,    0,  133,    2, 0x08,
      15,    0,  134,    2, 0x08,
      16,    0,  135,    2, 0x08,
      17,    0,  136,    2, 0x08,
      18,    0,  137,    2, 0x08,
      19,    0,  138,    2, 0x08,
      20,    0,  139,    2, 0x08,
      21,    0,  140,    2, 0x08,
      22,    0,  141,    2, 0x08,
      23,    0,  142,    2, 0x08,
      24,    2,  143,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::QPoint,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   25,   26,

       0        // eod
};

void DialogImport::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DialogImport *_t = static_cast<DialogImport *>(_o);
        switch (_id) {
        case 0: _t->on_btnBrowse_clicked(); break;
        case 1: _t->changeSeparator(); break;
        case 2: _t->on_lineStart_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->tblCtxMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 4: _t->cctHide(); break;
        case 5: _t->cctSupplierName(); break;
        case 6: _t->cctSupplierInn(); break;
        case 7: _t->cctSupplierKpp(); break;
        case 8: _t->cctProducerName(); break;
        case 9: _t->cctProducerInn(); break;
        case 10: _t->cctProducerKpp(); break;
        case 11: _t->cctLicenseNumber(); break;
        case 12: _t->cctLicenseSDate(); break;
        case 13: _t->cctLicenseEDate(); break;
        case 14: _t->cctLicenseDepartment(); break;
        case 15: _t->cctProductType(); break;
        case 16: _t->cctTtnNumber(); break;
        case 17: _t->cctTtnDate(); break;
        case 18: _t->cctTdNumber(); break;
        case 19: _t->cctNumberDkl(); break;
        case 20: _t->changeColumnType((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject DialogImport::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DialogImport.data,
      qt_meta_data_DialogImport,  qt_static_metacall, 0, 0}
};


const QMetaObject *DialogImport::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogImport::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DialogImport.stringdata))
        return static_cast<void*>(const_cast< DialogImport*>(this));
    return QDialog::qt_metacast(_clname);
}

int DialogImport::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 21;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
