/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[14];
    char stringdata0[315];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 27), // "on_ButtonVisualize_released"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 24), // "on_ButtonBrowse_released"
QT_MOC_LITERAL(4, 65, 22), // "on_ButtonLoad_released"
QT_MOC_LITERAL(5, 88, 27), // "on_ButtonsOkCancel_accepted"
QT_MOC_LITERAL(6, 116, 27), // "on_ButtonsOkCancel_rejected"
QT_MOC_LITERAL(7, 144, 37), // "on_BoxNumberOfPartitions_valu..."
QT_MOC_LITERAL(8, 182, 4), // "arg1"
QT_MOC_LITERAL(9, 187, 26), // "on_advancedButton_released"
QT_MOC_LITERAL(10, 214, 23), // "on_basicButton_released"
QT_MOC_LITERAL(11, 238, 31), // "on_recursive_bisection_released"
QT_MOC_LITERAL(12, 270, 16), // "on_kway_released"
QT_MOC_LITERAL(13, 287, 27) // "on_BoxInputPath_textChanged"

    },
    "MainWindow\0on_ButtonVisualize_released\0"
    "\0on_ButtonBrowse_released\0"
    "on_ButtonLoad_released\0"
    "on_ButtonsOkCancel_accepted\0"
    "on_ButtonsOkCancel_rejected\0"
    "on_BoxNumberOfPartitions_valueChanged\0"
    "arg1\0on_advancedButton_released\0"
    "on_basicButton_released\0"
    "on_recursive_bisection_released\0"
    "on_kway_released\0on_BoxInputPath_textChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

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
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    1,   74,    2, 0x08 /* Private */,
       9,    0,   77,    2, 0x08 /* Private */,
      10,    0,   78,    2, 0x08 /* Private */,
      11,    0,   79,    2, 0x08 /* Private */,
      12,    0,   80,    2, 0x08 /* Private */,
      13,    1,   81,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_ButtonVisualize_released(); break;
        case 1: _t->on_ButtonBrowse_released(); break;
        case 2: _t->on_ButtonLoad_released(); break;
        case 3: _t->on_ButtonsOkCancel_accepted(); break;
        case 4: _t->on_ButtonsOkCancel_rejected(); break;
        case 5: _t->on_BoxNumberOfPartitions_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_advancedButton_released(); break;
        case 7: _t->on_basicButton_released(); break;
        case 8: _t->on_recursive_bisection_released(); break;
        case 9: _t->on_kway_released(); break;
        case 10: _t->on_BoxInputPath_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
