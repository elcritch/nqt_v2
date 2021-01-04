
#include <memory>
#include "example-qt-build.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>


struct qt_meta_stringdata_MyObject_t
{
  QByteArrayData data[5];
  char stringdata0[31];
};

static const qt_meta_stringdata_MyObject_t qt_meta_stringdata_MyObject = {
  {
      QT_MOC_LITERAL(0, 0, 8),  // "MyObject"
      QT_MOC_LITERAL(1, 9, 8),  // "mySignal"
      QT_MOC_LITERAL(2, 18, 0), // ""
      QT_MOC_LITERAL(3, 19, 4), // "name"
      QT_MOC_LITERAL(4, 24, 6)  // "mySlot"
  },
  "MyObject\0mySignal\0\0name\0mySlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyObject[] = {

    // content:
    8,     // revision
    0,     // classname
    0, 0,  // classinfo
    2, 14, // methods
    0, 0,  // properties
    0, 0,  // enums/sets
    0, 0,  // constructors
    0,     // flags
    1,     // signalCount

    // signals: name, argc, parameters, tag, flags
    1, 1, 24, 2, 0x06 /* Public */,

    // slots: name, argc, parameters, tag, flags
    4, 1, 27, 2, 0x0a /* Public */,

    // signals: parameters
    QMetaType::Void, QMetaType::QString, 3,

    // slots: parameters
    QMetaType::Void, QMetaType::QString, 3,

    0 // eod
};

void MyObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
  if (_c == QMetaObject::InvokeMetaMethod)
  {
    auto *_t = static_cast<MyObject *>(_o);
    Q_UNUSED(_t)
    switch (_id)
    {
    case 0:
      _t->mySignal((*reinterpret_cast<const QString(*)>(_a[1])));
      break;
    case 1:
      _t->mySlot((*reinterpret_cast<const QString(*)>(_a[1])));
      break;
    default:;
    }
  }
  else if (_c == QMetaObject::IndexOfMethod)
  {
    int *result = reinterpret_cast<int *>(_a[0]);
    {
      using _t = void (MyObject::*)(const QString &);
      if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyObject::mySignal))
      {
        *result = 0;
        return;
      }
    }
  }
}

QT_INIT_METAOBJECT const QMetaObject MyObject::staticMetaObject =
{
  {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MyObject.data,
    qt_meta_data_MyObject,
    qt_static_metacall,
    nullptr,
    nullptr
  }
};

const QMetaObject *MyObject::metaObject() const
{
  return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyObject::qt_metacast(const char *_clname)
{
  if (!_clname)
    return nullptr;
  if (!strcmp(_clname, qt_meta_stringdata_MyObject.stringdata0))
    return static_cast<void *>(this);
  return QObject::qt_metacast(_clname);
}

int MyObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
  _id = QObject::qt_metacall(_c, _id, _a);
  if (_id < 0)
    return _id;
  if (_c == QMetaObject::InvokeMetaMethod)
  {
    if (_id < 2)
      qt_static_metacall(this, _c, _id, _a);
    _id -= 2;
  }
  else if (_c == QMetaObject::RegisterMethodArgumentMetaType)
  {
    if (_id < 2)
      *reinterpret_cast<int *>(_a[0]) = -1;
    _id -= 2;
  }
  return _id;
}

// SIGNAL 0
void MyObject::mySignal(const QString &_t1)
{
  void *_a[] = {nullptr, const_cast<void *>(reinterpret_cast<const void *>(std::addressof(_t1)))};
  QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

