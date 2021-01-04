
#include <memory>
#include "example-qt-build.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'example-qt-build.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif


QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED

template <class Base, NMetaData, NMetaCall, NQtObjectFunc>
struct NQtObject extends Base {

  void qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
  {
    if (_c == QMetaObject::InvokeMetaMethod)
    {
      auto *_t = static_cast<NQtObject *>(_o);
      NMetaCall(_t, _id, _a);
    }
    else if (_c == QMetaObject::IndexOfMethod)
    {
      int *result = reinterpret_cast<int *>(_a[0]);
      NMetaCall(result, _a[1]);
    }
  }

  QT_INIT_METAOBJECT const QMetaObject NQtObject::staticMetaObject = {
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
    return QObject::d_ptr->metaObject ?
      QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
  }

  void *MyObject::qt_metacast(const char *_clname)
  {
    if (!_clname)
      return nullptr;
    if (!strcmp(_clname, NMetaData.stringdata0))
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

};

QT_WARNING_POP
QT_END_MOC_NAMESPACE

