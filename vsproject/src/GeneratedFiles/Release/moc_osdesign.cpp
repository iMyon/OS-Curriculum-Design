/****************************************************************************
** Meta object code from reading C++ file 'osdesign.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../osdesign.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'osdesign.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_osDesign_t {
    QByteArrayData data[17];
    char stringdata[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_osDesign_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_osDesign_t qt_meta_stringdata_osDesign = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 5),
QT_MOC_LITERAL(2, 15, 0),
QT_MOC_LITERAL(3, 16, 3),
QT_MOC_LITERAL(4, 20, 4),
QT_MOC_LITERAL(5, 25, 4),
QT_MOC_LITERAL(6, 30, 16),
QT_MOC_LITERAL(7, 47, 5),
QT_MOC_LITERAL(8, 53, 2),
QT_MOC_LITERAL(9, 56, 5),
QT_MOC_LITERAL(10, 62, 5),
QT_MOC_LITERAL(11, 68, 6),
QT_MOC_LITERAL(12, 75, 13),
QT_MOC_LITERAL(13, 89, 10),
QT_MOC_LITERAL(14, 100, 16),
QT_MOC_LITERAL(15, 117, 24),
QT_MOC_LITERAL(16, 142, 5)
    },
    "osDesign\0alert\0\0str\0test\0open\0"
    "QTreeWidgetItem*\0index\0rm\0touch\0mkdir\0"
    "rename\0setPermission\0switchUser\0"
    "refreshFileLists\0showFileListsContextMenu\0"
    "point"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_osDesign[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x0a /* Public */,
       4,    0,   82,    2, 0x0a /* Public */,
       5,    1,   83,    2, 0x0a /* Public */,
       5,    0,   86,    2, 0x0a /* Public */,
       5,    2,   87,    2, 0x0a /* Public */,
       8,    0,   92,    2, 0x0a /* Public */,
       9,    0,   93,    2, 0x0a /* Public */,
      10,    0,   94,    2, 0x0a /* Public */,
      11,    0,   95,    2, 0x0a /* Public */,
      12,    0,   96,    2, 0x0a /* Public */,
      13,    0,   97,    2, 0x0a /* Public */,
      14,    0,   98,    2, 0x0a /* Public */,
      15,    1,   99,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Int,    2,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   16,

       0        // eod
};

void osDesign::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        osDesign *_t = static_cast<osDesign *>(_o);
        switch (_id) {
        case 0: _t->alert((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->test(); break;
        case 2: _t->open((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->open(); break;
        case 4: _t->open((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->rm(); break;
        case 6: _t->touch(); break;
        case 7: _t->mkdir(); break;
        case 8: _t->rename(); break;
        case 9: _t->setPermission(); break;
        case 10: _t->switchUser(); break;
        case 11: _t->refreshFileLists(); break;
        case 12: _t->showFileListsContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject osDesign::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_osDesign.data,
      qt_meta_data_osDesign,  qt_static_metacall, 0, 0}
};


const QMetaObject *osDesign::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *osDesign::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_osDesign.stringdata))
        return static_cast<void*>(const_cast< osDesign*>(this));
    if (!strcmp(_clname, "Ui::osDesignClass"))
        return static_cast< Ui::osDesignClass*>(const_cast< osDesign*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int osDesign::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
