/****************************************************************************
** Meta object code from reading C++ file 'CalcGUI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CalcGUI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CalcGUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CalcGUI_t {
    QByteArrayData data[13];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CalcGUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CalcGUI_t qt_meta_stringdata_CalcGUI = {
    {
QT_MOC_LITERAL(0, 0, 7), // "CalcGUI"
QT_MOC_LITERAL(1, 8, 13), // "numberClicked"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 15), // "handleOperation"
QT_MOC_LITERAL(4, 39, 13), // "equalsPressed"
QT_MOC_LITERAL(5, 53, 5), // "clear"
QT_MOC_LITERAL(6, 59, 10), // "clearEntry"
QT_MOC_LITERAL(7, 70, 9), // "backspace"
QT_MOC_LITERAL(8, 80, 7), // "decimal"
QT_MOC_LITERAL(9, 88, 10), // "percentage"
QT_MOC_LITERAL(10, 99, 8), // "xSquared"
QT_MOC_LITERAL(11, 108, 8), // "oneOverX"
QT_MOC_LITERAL(12, 117, 9) // "plusMinus"

    },
    "CalcGUI\0numberClicked\0\0handleOperation\0"
    "equalsPressed\0clear\0clearEntry\0backspace\0"
    "decimal\0percentage\0xSquared\0oneOverX\0"
    "plusMinus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CalcGUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x0a /* Public */,
       3,    0,   70,    2, 0x0a /* Public */,
       4,    0,   71,    2, 0x0a /* Public */,
       5,    0,   72,    2, 0x0a /* Public */,
       6,    0,   73,    2, 0x0a /* Public */,
       7,    0,   74,    2, 0x0a /* Public */,
       8,    0,   75,    2, 0x0a /* Public */,
       9,    0,   76,    2, 0x0a /* Public */,
      10,    0,   77,    2, 0x0a /* Public */,
      11,    0,   78,    2, 0x0a /* Public */,
      12,    0,   79,    2, 0x0a /* Public */,

 // slots: parameters
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

       0        // eod
};

void CalcGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CalcGUI *_t = static_cast<CalcGUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->numberClicked(); break;
        case 1: _t->handleOperation(); break;
        case 2: _t->equalsPressed(); break;
        case 3: _t->clear(); break;
        case 4: _t->clearEntry(); break;
        case 5: _t->backspace(); break;
        case 6: _t->decimal(); break;
        case 7: _t->percentage(); break;
        case 8: _t->xSquared(); break;
        case 9: _t->oneOverX(); break;
        case 10: _t->plusMinus(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CalcGUI::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CalcGUI.data,
      qt_meta_data_CalcGUI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CalcGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CalcGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CalcGUI.stringdata0))
        return static_cast<void*>(const_cast< CalcGUI*>(this));
    return QWidget::qt_metacast(_clname);
}

int CalcGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
