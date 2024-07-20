/****************************************************************************
** Meta object code from reading C++ file 'snakemodel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../models/snakemodel.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'snakemodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSSnakeModelENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSSnakeModelENDCLASS = QtMocHelpers::stringData(
    "SnakeModel",
    "Direction",
    "Up",
    "Down",
    "Left",
    "Right",
    "Start",
    "Pause",
    "GameOver",
    "None",
    "MenuGames",
    "N",
    "Menu",
    "Move_Up",
    "Move_Down",
    "Tetris_game",
    "Snake_game",
    "Quit",
    "Exit"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSnakeModelENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       2,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, alias, flags, count, data
       1,    1, 0x0,    8,   24,
      10,   10, 0x0,    8,   40,

 // enum data: key, value
       2, uint(SnakeModel::Up),
       3, uint(SnakeModel::Down),
       4, uint(SnakeModel::Left),
       5, uint(SnakeModel::Right),
       6, uint(SnakeModel::Start),
       7, uint(SnakeModel::Pause),
       8, uint(SnakeModel::GameOver),
       9, uint(SnakeModel::None),
      11, uint(SnakeModel::N),
      12, uint(SnakeModel::Menu),
      13, uint(SnakeModel::Move_Up),
      14, uint(SnakeModel::Move_Down),
      15, uint(SnakeModel::Tetris_game),
      16, uint(SnakeModel::Snake_game),
      17, uint(SnakeModel::Quit),
      18, uint(SnakeModel::Exit),

       0        // eod
};

Q_CONSTINIT const QMetaObject SnakeModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSSnakeModelENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSnakeModelENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSnakeModelENDCLASS_t,
        // enum 'Direction'
        QtPrivate::TypeAndForceComplete<SnakeModel::Direction, std::true_type>,
        // enum 'MenuGames'
        QtPrivate::TypeAndForceComplete<SnakeModel::MenuGames, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SnakeModel, std::true_type>
    >,
    nullptr
} };

void SnakeModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *SnakeModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SnakeModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSnakeModelENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SnakeModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
