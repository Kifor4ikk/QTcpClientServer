/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Client/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[34];
    char stringdata0[287];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 11), // "socketReady"
QT_MOC_LITERAL(23, 0), // ""
QT_MOC_LITERAL(24, 16), // "socketDisconnect"
QT_MOC_LITERAL(41, 25), // "on_connect_button_clicked"
QT_MOC_LITERAL(67, 28), // "on_disconnect_button_clicked"
QT_MOC_LITERAL(96, 22), // "on_ip_line_textChanged"
QT_MOC_LITERAL(119, 4), // "arg1"
QT_MOC_LITERAL(124, 24), // "on_port_line_textChanged"
QT_MOC_LITERAL(149, 31), // "on_download_file_button_clicked"
QT_MOC_LITERAL(181, 27), // "on_load_file_button_clicked"
QT_MOC_LITERAL(209, 18), // "on_loadDir_clicked"
QT_MOC_LITERAL(228, 8), // "checkDir"
QT_MOC_LITERAL(237, 8), // "loadFile"
QT_MOC_LITERAL(246, 12), // "downloadFile"
QT_MOC_LITERAL(259, 10), // "disconnect"
QT_MOC_LITERAL(270, 16) // "on_test2_clicked"

    },
    "MainWindow\0socketReady\0\0socketDisconnect\0"
    "on_connect_button_clicked\0"
    "on_disconnect_button_clicked\0"
    "on_ip_line_textChanged\0arg1\0"
    "on_port_line_textChanged\0"
    "on_download_file_button_clicked\0"
    "on_load_file_button_clicked\0"
    "on_loadDir_clicked\0checkDir\0loadFile\0"
    "downloadFile\0disconnect\0on_test2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x0a,    0 /* Public */,
       3,    0,   99,    2, 0x0a,    1 /* Public */,
       4,    0,  100,    2, 0x08,    2 /* Private */,
       5,    0,  101,    2, 0x08,    3 /* Private */,
       6,    1,  102,    2, 0x08,    4 /* Private */,
       8,    1,  105,    2, 0x08,    6 /* Private */,
       9,    0,  108,    2, 0x08,    8 /* Private */,
      10,    0,  109,    2, 0x08,    9 /* Private */,
      11,    0,  110,    2, 0x08,   10 /* Private */,
      12,    0,  111,    2, 0x08,   11 /* Private */,
      13,    0,  112,    2, 0x08,   12 /* Private */,
      14,    0,  113,    2, 0x08,   13 /* Private */,
      15,    0,  114,    2, 0x08,   14 /* Private */,
      16,    0,  115,    2, 0x08,   15 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
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

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->socketReady(); break;
        case 1: _t->socketDisconnect(); break;
        case 2: _t->on_connect_button_clicked(); break;
        case 3: _t->on_disconnect_button_clicked(); break;
        case 4: _t->on_ip_line_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_port_line_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_download_file_button_clicked(); break;
        case 7: _t->on_load_file_button_clicked(); break;
        case 8: _t->on_loadDir_clicked(); break;
        case 9: _t->checkDir(); break;
        case 10: _t->loadFile(); break;
        case 11: _t->downloadFile(); break;
        case 12: _t->disconnect(); break;
        case 13: _t->on_test2_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
