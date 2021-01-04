#include <memory>
#include "example-qt-build.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>

  /*
  QT_INIT_METAOBJECT const QMetaObject NQtObject::staticMetaObject = {
      {
        QMetaObject::SuperData::link<QObject::staticMetaObject>(),
        NMetaStringData.data,
        NMetaStringData,
        qt_static_metacall,
        nullptr,
        nullptr
      }
  };
  */

  template <NMetaStringData, NMetaCall>
  class NQtObject extends QObject
  {

    void qt_static_metacall(QObject *rawobj, QMetaObject::Call call, int id, void **args)
    {
      auto *obj = static_cast<NQtObject *>(rawobj);
      NMetaCall(obj, call, id, args);
    }

    const QMetaObject *MyObject::metaObject() const
    {
      return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
    }

    void *qt_metacast(const char *calllname)
    {
      if (!calllname)
        return nullptr;
      if (!strcmp(calllname, NMetaStringData.stringdata0))
        return static_cast<void *>(this);
      return QObject::qt_metacast(calllname);
    }

    int qt_metacall(QMetaObject::Call call, int id, void **args)
    {
      id = QObject::qt_metacall(call, id, args);
      if (id < 0)
        return id;
      if (call == QMetaObject::InvokeMetaMethod)
      {
        if (id < 2)
          qt_static_metacall(this, call, id, args);
        id -= 2;
      }
      else if (call == QMetaObject::RegisterMethodArgumentMetaType)
      {
        if (id < 2)
          *reinterpretcallast<int *>(args[0]) = -1;
        id -= 2;
      }
      return id;
    }
  };
