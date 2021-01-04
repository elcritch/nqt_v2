#include <nqt_template>

struct qt_meta_stringdata_MyObject_t
{
  QByteArrayData data[5];
  char stringdata0[31];
};

static const qt_meta_stringdata_MyObject_t MyObject_qt_meta_stringdata = {
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

static const uint MyObject_qt_meta_data[] = {

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

// SIGNAL 0
void MyObject::mySignal(const QString &_t1)
{
  void *_a[] = {nullptr, const_cast<void *>(reinterpret_cast<const void *>(std::addressof(_t1)))};
  QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// template <NMetaStringData, NMetaCall, NQtObjectFunc>
typedef class NQtObject<MyObject_qt_meta_stringdata, qt_meta_stringdata_MyObject> MyObject_t;

// Meta Object impl
QT_INIT_METAOBJECT const QMetaObject MyObject_t::staticMetaObject = 
{
  {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    My_object_qt_meta_stringdata.data,
    MyObject_qt_meta_data,
    MyObject_qt_static_metacall,
    nullptr,
    nullptr
  }
};

