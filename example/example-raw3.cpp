
namespace std {
inline namespace __1 {}
} // namespace std

typedef long int ptrdiff_t;
typedef long unsigned int size_t;
typedef long double max_align_t;

typedef signed char __int8_t;

typedef unsigned char __uint8_t;
typedef short __int16_t;
typedef unsigned short __uint16_t;
typedef int __int32_t;
typedef unsigned int __uint32_t;
typedef long long __int64_t;
typedef unsigned long long __uint64_t;

typedef long __darwin_intptr_t;
typedef unsigned int __darwin_natural_t;
typedef int __darwin_ct_rune_t;

typedef union {
  char __mbstate8[128];
  long long _mbstateL;
} __mbstate_t;

typedef __mbstate_t __darwin_mbstate_t;

typedef long int __darwin_ptrdiff_t;

typedef long unsigned int __darwin_size_t;

typedef __builtin_va_list __darwin_va_list;

typedef int __darwin_wchar_t;

typedef __darwin_wchar_t __darwin_rune_t;

typedef int __darwin_wint_t;

typedef unsigned long __darwin_clock_t;
typedef __uint32_t __darwin_socklen_t;
typedef long __darwin_ssize_t;
typedef long __darwin_time_t;
typedef __int64_t __darwin_blkcnt_t;
typedef __int32_t __darwin_blksize_t;
typedef __int32_t __darwin_dev_t;
typedef unsigned int __darwin_fsblkcnt_t;
typedef unsigned int __darwin_fsfilcnt_t;
typedef __uint32_t __darwin_gid_t;
typedef __uint32_t __darwin_id_t;
typedef __uint64_t __darwin_ino64_t;

typedef __darwin_ino64_t __darwin_ino_t;

typedef __darwin_natural_t __darwin_mach_port_name_t;
typedef __darwin_mach_port_name_t __darwin_mach_port_t;
typedef __uint16_t __darwin_mode_t;
typedef __int64_t __darwin_off_t;
typedef __int32_t __darwin_pid_t;
typedef __uint32_t __darwin_sigset_t;
typedef __int32_t __darwin_suseconds_t;
typedef __uint32_t __darwin_uid_t;
typedef __uint32_t __darwin_useconds_t;
typedef unsigned char __darwin_uuid_t[16];
typedef char __darwin_uuid_string_t[37];

typedef struct _opaque_pthread_attr_t __darwin_pthread_attr_t;
typedef struct _opaque_pthread_cond_t __darwin_pthread_cond_t;
typedef struct _opaque_pthread_condattr_t __darwin_pthread_condattr_t;
typedef unsigned long __darwin_pthread_key_t;
typedef struct _opaque_pthread_mutex_t __darwin_pthread_mutex_t;
typedef struct _opaque_pthread_mutexattr_t __darwin_pthread_mutexattr_t;
typedef struct _opaque_pthread_once_t __darwin_pthread_once_t;
typedef struct _opaque_pthread_rwlock_t __darwin_pthread_rwlock_t;
typedef struct _opaque_pthread_rwlockattr_t __darwin_pthread_rwlockattr_t;
typedef struct _opaque_pthread_t *__darwin_pthread_t;
typedef int __darwin_nl_item;
typedef int __darwin_wctrans_t;

typedef __uint32_t __darwin_wctype_t;

typedef signed char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long long int64_t;

typedef unsigned char u_int8_t;
typedef unsigned short u_int16_t;
typedef unsigned int u_int32_t;
typedef unsigned long long u_int64_t;

typedef int64_t register_t;

typedef __darwin_intptr_t intptr_t;
typedef unsigned long uintptr_t;

typedef u_int64_t user_addr_t;
typedef u_int64_t user_size_t;
typedef int64_t user_ssize_t;
typedef int64_t user_long_t;
typedef u_int64_t user_ulong_t;
typedef int64_t user_time_t;
typedef int64_t user_off_t;

typedef u_int64_t syscall_arg_t;
typedef __darwin_ssize_t ssize_t;

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;

typedef int8_t int_least8_t;
typedef int16_t int_least16_t;
typedef int32_t int_least32_t;
typedef int64_t int_least64_t;
typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;
typedef uint64_t uint_least64_t;

typedef int8_t int_fast8_t;
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef int64_t int_fast64_t;
typedef uint8_t uint_fast8_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
typedef uint64_t uint_fast64_t;
typedef long int intmax_t;
typedef long unsigned int uintmax_t;

typedef __darwin_mbstate_t mbstate_t;
typedef __darwin_ct_rune_t ct_rune_t;
typedef __darwin_rune_t rune_t;
typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

typedef __darwin_va_list va_list;

typedef __darwin_off_t fpos_t;
struct __sbuf {
  unsigned char *_base;
  int _size;
};

struct __sFILEX;

enum class QCborSimpleType : quint8;

template <typename T> struct QMetaTypeId2;

template <typename T> inline constexpr int qMetaTypeId();
class QDataStream;
class QMetaTypeInterface;
struct QMetaObject;

namespace QtPrivate {

template <typename From, typename To> To convertImplicit(const From &from) {
  return from;
}

struct AbstractDebugStreamFunction {
  typedef void (*Stream)(const AbstractDebugStreamFunction *, QDebug &,
                         const void *);
  typedef void (*Destroy)(AbstractDebugStreamFunction *);
  explicit AbstractDebugStreamFunction(Stream s = nullptr, Destroy d = nullptr)
      : stream(s), destroy(d) {}
  AbstractDebugStreamFunction(const AbstractDebugStreamFunction &) = delete;
  AbstractDebugStreamFunction &
  operator=(const AbstractDebugStreamFunction &) = delete;
  Stream stream;
  Destroy destroy;
};

template <typename T>
struct BuiltInDebugStreamFunction : public AbstractDebugStreamFunction {
  BuiltInDebugStreamFunction() : AbstractDebugStreamFunction(stream, destroy) {}
  static void stream(const AbstractDebugStreamFunction *, QDebug &dbg,
                     const void *r) {
    const T *rhs = static_cast<const T *>(r);
    operator<<(dbg, *rhs);
  }

  static void destroy(AbstractDebugStreamFunction *_this) {
    delete static_cast<BuiltInDebugStreamFunction *>(_this);
  }
};

struct AbstractComparatorFunction {
  typedef bool (*LessThan)(const AbstractComparatorFunction *, const void *,
                           const void *);
  typedef bool (*Equals)(const AbstractComparatorFunction *, const void *,
                         const void *);
  typedef void (*Destroy)(AbstractComparatorFunction *);
  explicit AbstractComparatorFunction(LessThan lt = nullptr, Equals e = nullptr,
                                      Destroy d = nullptr)
      : lessThan(lt), equals(e), destroy(d) {}
  AbstractComparatorFunction(const AbstractComparatorFunction &) = delete;
  AbstractComparatorFunction &
  operator=(const AbstractComparatorFunction &) = delete;
  LessThan lessThan;
  Equals equals;
  Destroy destroy;
};

template <typename T>
struct BuiltInComparatorFunction : public AbstractComparatorFunction {
  BuiltInComparatorFunction()
      : AbstractComparatorFunction(lessThan, equals, destroy) {}
  static bool lessThan(const AbstractComparatorFunction *, const void *l,
                       const void *r) {
    const T *lhs = static_cast<const T *>(l);
    const T *rhs = static_cast<const T *>(r);
    return *lhs < *rhs;
  }

  static bool equals(const AbstractComparatorFunction *, const void *l,
                     const void *r) {
    const T *lhs = static_cast<const T *>(l);
    const T *rhs = static_cast<const T *>(r);
    return *lhs == *rhs;
  }

  static void destroy(AbstractComparatorFunction *_this) {
    delete static_cast<BuiltInComparatorFunction *>(_this);
  }
};

template <typename T>
struct BuiltInEqualsComparatorFunction : public AbstractComparatorFunction {
  BuiltInEqualsComparatorFunction()
      : AbstractComparatorFunction(nullptr, equals, destroy) {}
  static bool equals(const AbstractComparatorFunction *, const void *l,
                     const void *r) {
    const T *lhs = static_cast<const T *>(l);
    const T *rhs = static_cast<const T *>(r);
    return *lhs == *rhs;
  }

  static void destroy(AbstractComparatorFunction *_this) {
    delete static_cast<BuiltInEqualsComparatorFunction *>(_this);
  }
};

struct AbstractConverterFunction {
  typedef bool (*Converter)(const AbstractConverterFunction *, const void *,
                            void *);
  explicit AbstractConverterFunction(Converter c = nullptr) : convert(c) {}
  AbstractConverterFunction(const AbstractConverterFunction &) = delete;
  AbstractConverterFunction &
  operator=(const AbstractConverterFunction &) = delete;
  Converter convert;
};

template <typename From, typename To>
struct ConverterMemberFunction : public AbstractConverterFunction {
  explicit ConverterMemberFunction(To (From::*function)() const)
      : AbstractConverterFunction(convert), m_function(function) {}
  ~ConverterMemberFunction();
  static bool convert(const AbstractConverterFunction *_this, const void *in,
                      void *out) {
    const From *f = static_cast<const From *>(in);
    To *t = static_cast<To *>(out);
    const ConverterMemberFunction *_typedThis =
        static_cast<const ConverterMemberFunction *>(_this);
    *t = (f->*_typedThis->m_function)();
    return true;
  }

  To (From::*const m_function)() const;
};

template <typename From, typename To>
struct ConverterMemberFunctionOk : public AbstractConverterFunction {
  explicit ConverterMemberFunctionOk(To (From::*function)(bool *) const)
      : AbstractConverterFunction(convert), m_function(function) {}
  ~ConverterMemberFunctionOk();
  static bool convert(const AbstractConverterFunction *_this, const void *in,
                      void *out) {
    const From *f = static_cast<const From *>(in);
    To *t = static_cast<To *>(out);
    bool ok = false;
    const ConverterMemberFunctionOk *_typedThis =
        static_cast<const ConverterMemberFunctionOk *>(_this);
    *t = (f->*_typedThis->m_function)(&ok);
    if (!ok)
      *t = To();
    return ok;
  }

  To (From::*const m_function)(bool *) const;
};

template <typename From, typename To, typename UnaryFunction>
struct ConverterFunctor : public AbstractConverterFunction {
  explicit ConverterFunctor(UnaryFunction function)
      : AbstractConverterFunction(convert), m_function(function) {}
  ~ConverterFunctor();
  static bool convert(const AbstractConverterFunction *_this, const void *in,
                      void *out) {
    const From *f = static_cast<const From *>(in);
    To *t = static_cast<To *>(out);
    const ConverterFunctor *_typedThis =
        static_cast<const ConverterFunctor *>(_this);
    *t = _typedThis->m_function(*f);
    return true;
  }

  UnaryFunction m_function;
};

template <typename T, bool> struct ValueTypeIsMetaType;
template <typename T, bool> struct AssociativeValueTypeIsMetaType;
template <typename T, bool> struct IsMetaTypePair;
template <typename, typename> struct MetaTypeSmartPointerHelper;
} // namespace QtPrivate

class __attribute__((visibility("default"))) QMetaType {
  enum ExtensionFlag {
    NoExtensionFlags,
    CreateEx = 0x1,
    DestroyEx = 0x2,
    ConstructEx = 0x4,
    DestructEx = 0x8,
    NameEx = 0x10,
    SizeEx = 0x20,
    CtorEx = 0x40,
    DtorEx = 0x80,
    FlagsEx = 0x100,
    MetaObjectEx = 0x200
  };

public:
  enum Type {

    Void = 43,
    Bool = 1,
    Int = 2,
    UInt = 3,
    LongLong = 4,
    ULongLong = 5,
    Double = 6,
    Long = 32,
    Short = 33,
    Char = 34,
    ULong = 35,
    UShort = 36,
    UChar = 37,
    Float = 38,
    SChar = 40,
    Nullptr = 51,
    QCborSimpleType = 52,
    VoidStar = 31,
    QChar = 7,
    QString = 10,
    QStringList = 11,
    QByteArray = 12,
    QBitArray = 13,
    QDate = 14,
    QTime = 15,
    QDateTime = 16,
    QUrl = 17,
    QLocale = 18,
    QRect = 19,
    QRectF = 20,
    QSize = 21,
    QSizeF = 22,
    QLine = 23,
    QLineF = 24,
    QPoint = 25,
    QPointF = 26,
    QRegExp = 27,
    QEasingCurve = 29,
    QUuid = 30,
    QVariant = 41,
    QRegularExpression = 44,
    QJsonValue = 45,
    QJsonObject = 46,
    QJsonArray = 47,
    QJsonDocument = 48,
    QCborValue = 53,
    QCborArray = 54,
    QCborMap = 55,
    QModelIndex = 42,
    QPersistentModelIndex = 50,
    QObjectStar = 39,
    QVariantMap = 8,
    QVariantList = 9,
    QVariantHash = 28,
    QByteArrayList = 49,
    QFont = 64,
    QPixmap = 65,
    QBrush = 66,
    QColor = 67,
    QPalette = 68,
    QIcon = 69,
    QImage = 70,
    QPolygon = 71,
    QRegion = 72,
    QBitmap = 73,
    QCursor = 74,
    QKeySequence = 75,
    QPen = 76,
    QTextLength = 77,
    QTextFormat = 78,
    QMatrix = 79,
    QTransform = 80,
    QMatrix4x4 = 81,
    QVector2D = 82,
    QVector3D = 83,
    QVector4D = 84,
    QQuaternion = 85,
    QPolygonF = 86,
    QColorSpace = 87,
    QSizePolicy = 121,

    FirstCoreType = Bool,
    LastCoreType = QCborMap,
    FirstGuiType = QFont,
    LastGuiType = QColorSpace,
    FirstWidgetsType = QSizePolicy,
    LastWidgetsType = QSizePolicy,
    HighestInternalId = LastWidgetsType,

    QReal = sizeof(qreal) == sizeof(double) ? Double : Float,

    UnknownType = 0,
    User = 1024
  };
  enum TypeFlag {
    NeedsConstruction = 0x1,
    NeedsDestruction = 0x2,
    MovableType = 0x4,
    PointerToQObject = 0x8,
    IsEnumeration = 0x10,
    SharedPointerToQObject = 0x20,
    WeakPointerToQObject = 0x40,
    TrackingPointerToQObject = 0x80,
    WasDeclaredAsMetaType = 0x100,
    IsGadget = 0x200,
    PointerToGadget = 0x400
  };
  typedef QFlags<TypeFlag> TypeFlags;

  typedef void (*Deleter)(void *);
  typedef void *(*Creator)(const void *);

  typedef void (*Destructor)(void *);
  typedef void *(*Constructor)(void *, const void *);

  typedef void (*TypedDestructor)(int, void *);
  typedef void *(*TypedConstructor)(int, void *, const void *);

  typedef void (*SaveOperator)(QDataStream &, const void *);
  typedef void (*LoadOperator)(QDataStream &, void *);

  static void registerStreamOperators(const char *typeName, SaveOperator saveOp,
                                      LoadOperator loadOp);
  static void registerStreamOperators(int type, SaveOperator saveOp,
                                      LoadOperator loadOp);

  static int registerType(const char *typeName, Deleter deleter,
                          Creator creator);
  static int registerType(const char *typeName, Deleter deleter,
                          Creator creator, Destructor destructor,
                          Constructor constructor, int size,
                          QMetaType::TypeFlags flags,
                          const QMetaObject *metaObject);
  static int registerType(const char *typeName, TypedDestructor destructor,
                          TypedConstructor constructor, int size,
                          QMetaType::TypeFlags flags,
                          const QMetaObject *metaObject);
  static bool unregisterType(int type);
  static int registerNormalizedType(const ::QByteArray &normalizedTypeName,
                                    Deleter deleter, Creator creator,
                                    Destructor destructor,
                                    Constructor constructor, int size,
                                    QMetaType::TypeFlags flags,
                                    const QMetaObject *metaObject);
  static int registerNormalizedType(const ::QByteArray &normalizedTypeName,
                                    Destructor destructor,
                                    Constructor constructor, int size,
                                    QMetaType::TypeFlags flags,
                                    const QMetaObject *metaObject);
  static int registerNormalizedType(const ::QByteArray &normalizedTypeName,
                                    TypedDestructor destructor,
                                    TypedConstructor constructor, int size,
                                    QMetaType::TypeFlags flags,
                                    const QMetaObject *metaObject);
  static int registerTypedef(const char *typeName, int aliasId);
  static int registerNormalizedTypedef(const ::QByteArray &normalizedTypeName,
                                       int aliasId);
  static int type(const char *typeName);

  static int type(const ::QByteArray &typeName);
  static const char *typeName(int type);
  static int sizeOf(int type);
  static TypeFlags typeFlags(int type);
  static const QMetaObject *metaObjectForType(int type);
  static bool isRegistered(int type);
  static void *create(int type, const void *copy = nullptr);

  static void destroy(int type, void *data);
  static void *construct(int type, void *where, const void *copy);
  static void destruct(int type, void *where);

  static bool save(QDataStream &stream, int type, const void *data);
  static bool load(QDataStream &stream, int type, void *data);

  explicit QMetaType(const int type = QMetaType::UnknownType);
  inline ~QMetaType();

  inline bool isValid() const;
  inline bool isRegistered() const;
  inline int id() const;
  inline int sizeOf() const;
  inline TypeFlags flags() const;
  inline const QMetaObject *metaObject() const;
  ::QByteArray name() const;

  inline void *create(const void *copy = nullptr) const;
  inline void destroy(void *data) const;
  inline void *construct(void *where, const void *copy = nullptr) const;
  inline void destruct(void *data) const;

  template <typename T> static QMetaType fromType() {
    return QMetaType(qMetaTypeId<T>());
  }

  friend bool operator==(const QMetaType &a, const QMetaType &b) {
    return a.m_typeId == b.m_typeId;
  }

  friend bool operator!=(const QMetaType &a, const QMetaType &b) {
    return a.m_typeId != b.m_typeId;
  }

public:
  template <typename T> static bool registerComparators() {
    static_assert(
        bool((!QMetaTypeId2<T>::IsBuiltIn)),
        "QMetaType::registerComparators: The type must be a custom type.");

    const int typeId = qMetaTypeId<T>();
    static const QtPrivate::BuiltInComparatorFunction<T> f;
    return registerComparatorFunction(&f, typeId);
  }
  template <typename T> static bool registerEqualsComparator() {
    static_assert(
        bool((!QMetaTypeId2<T>::IsBuiltIn)),
        "QMetaType::registerEqualsComparator: The type must be a custom type.");

    const int typeId = qMetaTypeId<T>();
    static const QtPrivate::BuiltInEqualsComparatorFunction<T> f;
    return registerComparatorFunction(&f, typeId);
  }

  template <typename T> static bool hasRegisteredComparators() {
    return hasRegisteredComparators(qMetaTypeId<T>());
  }
  static bool hasRegisteredComparators(int typeId);

  template <typename T> static bool registerDebugStreamOperator() {
    static_assert(bool((!QMetaTypeId2<T>::IsBuiltIn)),
                  "QMetaType::registerDebugStreamOperator: The type must be a "
                  "custom type.");

    const int typeId = qMetaTypeId<T>();
    static const QtPrivate::BuiltInDebugStreamFunction<T> f;
    return registerDebugStreamOperatorFunction(&f, typeId);
  }
  template <typename T> static bool hasRegisteredDebugStreamOperator() {
    return hasRegisteredDebugStreamOperator(qMetaTypeId<T>());
  }
  static bool hasRegisteredDebugStreamOperator(int typeId);

  template <typename From, typename To> static bool registerConverter() {
    return registerConverter<From, To>(QtPrivate::convertImplicit<From, To>);
  }
  template <typename From, typename To>
  static bool registerConverter(To (From::*function)() const) {
    static_assert(
        bool((!QMetaTypeId2<To>::IsBuiltIn || !QMetaTypeId2<From>::IsBuiltIn)),
        "QMetaType::registerConverter: At least one of the types must be a "
        "custom type.");

    const int fromTypeId = qMetaTypeId<From>();
    const int toTypeId = qMetaTypeId<To>();
    static const QtPrivate::ConverterMemberFunction<From, To> f(function);
    return registerConverterFunction(&f, fromTypeId, toTypeId);
  }

  template <typename From, typename To>
  static bool registerConverter(To (From::*function)(bool *) const) {
    static_assert(
        bool((!QMetaTypeId2<To>::IsBuiltIn || !QMetaTypeId2<From>::IsBuiltIn)),
        "QMetaType::registerConverter: At least one of the types must be a "
        "custom type.");

    const int fromTypeId = qMetaTypeId<From>();
    const int toTypeId = qMetaTypeId<To>();
    static const QtPrivate::ConverterMemberFunctionOk<From, To> f(function);
    return registerConverterFunction(&f, fromTypeId, toTypeId);
  }

  template <typename From, typename To, typename UnaryFunction>
  static bool registerConverter(UnaryFunction function) {
    static_assert(
        bool((!QMetaTypeId2<To>::IsBuiltIn || !QMetaTypeId2<From>::IsBuiltIn)),
        "QMetaType::registerConverter: At least one of the types must be a "
        "custom type.");

    const int fromTypeId = qMetaTypeId<From>();
    const int toTypeId = qMetaTypeId<To>();
    static const QtPrivate::ConverterFunctor<From, To, UnaryFunction> f(
        function);
    return registerConverterFunction(&f, fromTypeId, toTypeId);
  }

  static bool convert(const void *from, int fromTypeId, void *to, int toTypeId);
  static bool compare(const void *lhs, const void *rhs, int typeId,
                      int *result);
  static bool equals(const void *lhs, const void *rhs, int typeId, int *result);
  static bool debugStream(QDebug &dbg, const void *rhs, int typeId);

  template <typename From, typename To>
  static bool hasRegisteredConverterFunction() {
    return hasRegisteredConverterFunction(qMetaTypeId<From>(),
                                          qMetaTypeId<To>());
  }

  static bool hasRegisteredConverterFunction(int fromTypeId, int toTypeId);

private:
  static QMetaType typeInfo(const int type);
  inline QMetaType(const ExtensionFlag extensionFlags,
                   const QMetaTypeInterface *info, TypedConstructor creator,
                   TypedDestructor deleter, SaveOperator saveOp,
                   LoadOperator loadOp, Constructor constructor,
                   Destructor destructor, uint sizeOf, uint theTypeFlags,
                   int typeId, const QMetaObject *metaObject);
  QMetaType(const QMetaType &other);
  QMetaType &operator=(const QMetaType &);
  inline bool isExtended(const ExtensionFlag flag) const {
    return m_extensionFlags & flag;
  }

  void ctor(const QMetaTypeInterface *info);
  void dtor();
  uint sizeExtended() const;
  QMetaType::TypeFlags flagsExtended() const;
  const QMetaObject *metaObjectExtended() const;
  void *createExtended(const void *copy = nullptr) const;
  void destroyExtended(void *data) const;
  void *constructExtended(void *where, const void *copy = nullptr) const;
  void destructExtended(void *data) const;

  static bool
  registerComparatorFunction(const QtPrivate::AbstractComparatorFunction *f,
                             int type);

  static bool registerDebugStreamOperatorFunction(
      const QtPrivate::AbstractDebugStreamFunction *f, int type);

  template <typename, bool> friend struct QtPrivate::ValueTypeIsMetaType;
  template <typename, typename>
  friend struct QtPrivate::ConverterMemberFunction;
  template <typename, typename>
  friend struct QtPrivate::ConverterMemberFunctionOk;
  template <typename, typename, typename>
  friend struct QtPrivate::ConverterFunctor;
  template <typename, bool>
  friend struct QtPrivate::AssociativeValueTypeIsMetaType;
  template <typename, bool> friend struct QtPrivate::IsMetaTypePair;
  template <typename, typename>
  friend struct QtPrivate::MetaTypeSmartPointerHelper;

  static bool
  registerConverterFunction(const QtPrivate::AbstractConverterFunction *f,
                            int from, int to);
  static void unregisterConverterFunction(int from, int to);

private:
  TypedConstructor m_typedConstructor;
  TypedDestructor m_typedDestructor;
  SaveOperator m_saveOp;
  LoadOperator m_loadOp;
  Constructor m_constructor;
  Destructor m_destructor;
  void *m_extension;
  uint m_size;
  uint m_typeFlags;
  uint m_extensionFlags;
  int m_typeId;
  const QMetaObject *m_metaObject;
};

constexpr inline QFlags<QMetaType::TypeFlags::enum_type>
operator|(QMetaType::TypeFlags::enum_type f1,
          QMetaType::TypeFlags::enum_type f2) noexcept {
  return QFlags<QMetaType::TypeFlags::enum_type>(f1) | f2;
}
constexpr inline QFlags<QMetaType::TypeFlags::enum_type>
operator|(QMetaType::TypeFlags::enum_type f1,
          QFlags<QMetaType::TypeFlags::enum_type> f2) noexcept {
  return f2 | f1;
}
constexpr inline QIncompatibleFlag operator|(QMetaType::TypeFlags::enum_type f1,
                                             int f2) noexcept {
  return QIncompatibleFlag(int(f1) | f2);
}

namespace QtPrivate {

template <typename From, typename To>
ConverterMemberFunction<From, To>::~ConverterMemberFunction() {
  QMetaType::unregisterConverterFunction(qMetaTypeId<From>(),
                                         qMetaTypeId<To>());
}
template <typename From, typename To>
ConverterMemberFunctionOk<From, To>::~ConverterMemberFunctionOk() {
  QMetaType::unregisterConverterFunction(qMetaTypeId<From>(),
                                         qMetaTypeId<To>());
}
template <typename From, typename To, typename UnaryFunction>
ConverterFunctor<From, To, UnaryFunction>::~ConverterFunctor() {
  QMetaType::unregisterConverterFunction(qMetaTypeId<From>(),
                                         qMetaTypeId<To>());
}

} // namespace QtPrivate

namespace QtMetaTypePrivate {
template <typename T, bool Accepted = true> struct QMetaTypeFunctionHelper {
  static void Destruct(void *t) {
    (void)t;
    static_cast<T *>(t)->~T();
  }

  static void *Construct(void *where, const void *t) {
    if (t)
      return new (where) T(*static_cast<const T *>(t));
    return new (where) T;
  }

  static void Save(QDataStream &stream, const void *t) {
    stream << *static_cast<const T *>(t);
  }

  static void Load(QDataStream &stream, void *t) {
    stream >> *static_cast<T *>(t);
  }
};

template <typename T> struct QMetaTypeFunctionHelper<T, false> {
  static void Destruct(void *) {}
  static void *Construct(void *, const void *) { return nullptr; }

  static void Save(QDataStream &, const void *) {}
  static void Load(QDataStream &, void *) {}
};
template <>
struct QMetaTypeFunctionHelper<void, true>
    : public QMetaTypeFunctionHelper<void, false> {};

struct VariantData {
  VariantData(const int metaTypeId_, const void *data_, const uint flags_)
      : metaTypeId(metaTypeId_), data(data_), flags(flags_) {}
  VariantData(const VariantData &other)
      : metaTypeId(other.metaTypeId), data(other.data), flags(other.flags) {}
  const int metaTypeId;
  const void *data;
  const uint flags;

private:
  VariantData &operator=(const VariantData &) = delete;
};

template <typename const_iterator> struct IteratorOwnerCommon {
  static void assign(void **ptr, const_iterator iterator) {
    *ptr = new const_iterator(iterator);
  }
  static void assign(void **ptr, void *const *src) {
    *ptr = new const_iterator(*static_cast<const_iterator *>(*src));
  }

  static void advance(void **iterator, int step) {
    const_iterator &it = *static_cast<const_iterator *>(*iterator);
    std::advance(it, step);
  }

  static void destroy(void **ptr) {
    delete static_cast<const_iterator *>(*ptr);
  }

  static bool equal(void *const *it, void *const *other) {
    return *static_cast<const_iterator *>(*it) ==
           *static_cast<const_iterator *>(*other);
  }
};

template <typename const_iterator>
struct IteratorOwner : IteratorOwnerCommon<const_iterator> {
  static const void *getData(void *const *iterator) {
    return &**static_cast<const_iterator *>(*iterator);
  }

  static const void *getData(const_iterator it) { return &*it; }
};

struct __attribute__((visibility("default"))) VectorBoolElements {
  static const bool true_element;
  static const bool false_element;
};

template <>
struct IteratorOwner<std::vector<bool>::const_iterator>
    : IteratorOwnerCommon<std::vector<bool>::const_iterator> {
public:
  static const void *getData(void *const *iterator) {
    return **static_cast<std::vector<bool>::const_iterator *>(*iterator)
               ? &VectorBoolElements::true_element
               : &VectorBoolElements::false_element;
  }

  static const void *getData(const std::vector<bool>::const_iterator &it) {
    return *it ? &VectorBoolElements::true_element
               : &VectorBoolElements::false_element;
  }
};

template <typename value_type> struct IteratorOwner<const value_type *> {
private:
  struct Dummy {};
  typedef
      typename std::conditional<std::is_same<value_type, void *>::value, Dummy,
                                value_type>::type value_type_OR_Dummy;

public:
  static void assign(void **ptr, const value_type_OR_Dummy *iterator) {
    *ptr = const_cast<value_type *>(iterator);
  }
  static void assign(void **ptr, void *const *src) {
    *ptr = static_cast<value_type *>(*src);
  }

  static void advance(void **iterator, int step) {
    value_type *it = static_cast<value_type *>(*iterator);
    std::advance(it, step);
    *iterator = it;
  }

  static void destroy(void **) {}

  static const void *getData(void *const *iterator) { return *iterator; }

  static const void *getData(const value_type_OR_Dummy *it) { return it; }

  static bool equal(void *const *it, void *const *other) {
    return static_cast<value_type *>(*it) == static_cast<value_type *>(*other);
  }
};

enum IteratorCapability {
  ForwardCapability = 1,
  BiDirectionalCapability = 2,
  RandomAccessCapability = 4
};

enum ContainerCapability { ContainerIsAppendable = 1 };

template <typename Container, typename T = void>
struct ContainerCapabilitiesImpl {
  enum { ContainerCapabilities = 0 };
  using appendFunction = void (*)(const void *container,
                                  const void *newElement);
  static constexpr const appendFunction appendImpl = nullptr;
};

template <typename Container>
struct ContainerCapabilitiesImpl<
    Container, decltype(std::declval<Container>().push_back(
                   std::declval<typename Container::value_type>()))> {
  enum { ContainerCapabilities = ContainerIsAppendable };

  static void appendImpl(const void *container, const void *value) {
    static_cast<Container *>(const_cast<void *>(container))
        ->push_back(
            *static_cast<const typename Container::value_type *>(value));
  }
};

namespace QtPrivate {
namespace ContainerCapabilitiesMetaProgrammingHelper {
template <typename... Ts> using void_t = void;
}
} // namespace QtPrivate

template <typename Container>
struct ContainerCapabilitiesImpl<
    Container, QtPrivate::ContainerCapabilitiesMetaProgrammingHelper::void_t<
                   decltype(std::declval<Container>().insert(
                       std::declval<typename Container::value_type>())),
                   decltype(std::declval<typename Container::value_type>() ==
                            std::declval<typename Container::value_type>())>> {
  enum { ContainerCapabilities = ContainerIsAppendable };

  static void appendImpl(const void *container, const void *value) {
    static_cast<Container *>(const_cast<void *>(container))
        ->insert(*static_cast<const typename Container::value_type *>(value));
  }
};

template <typename T, typename Category = typename std::iterator_traits<
                          typename T::const_iterator>::iterator_category>
struct CapabilitiesImpl;

template <typename T> struct CapabilitiesImpl<T, std::forward_iterator_tag> {
  enum { IteratorCapabilities = ForwardCapability };
};
template <typename T>
struct CapabilitiesImpl<T, std::bidirectional_iterator_tag> {
  enum { IteratorCapabilities = BiDirectionalCapability | ForwardCapability };
};
template <typename T>
struct CapabilitiesImpl<T, std::random_access_iterator_tag> {
  enum {
    IteratorCapabilities =
        RandomAccessCapability | BiDirectionalCapability | ForwardCapability
  };
};

template <typename T> struct ContainerAPI : CapabilitiesImpl<T> {
  static int size(const T *t) {
    return int(std::distance(t->begin(), t->end()));
  }
};

template <typename T>
struct ContainerAPI<QList<T>> : CapabilitiesImpl<QList<T>> {
  static int size(const QList<T> *t) { return t->size(); }
};

template <typename T>
struct ContainerAPI<QVector<T>> : CapabilitiesImpl<QVector<T>> {
  static int size(const QVector<T> *t) { return t->size(); }
};

template <typename T>
struct ContainerAPI<std::vector<T>> : CapabilitiesImpl<std::vector<T>> {
  static int size(const std::vector<T> *t) { return int(t->size()); }
};

template <typename T>
struct ContainerAPI<std::list<T>> : CapabilitiesImpl<std::list<T>> {
  static int size(const std::list<T> *t) { return int(t->size()); }
};

class QSequentialIterableImpl {
public:
  const void *_iterable;
  void *_iterator;
  int _metaType_id;
  uint _metaType_flags;
  uint _iteratorCapabilities;

  typedef int (*sizeFunc)(const void *p);
  typedef const void *(*atFunc)(const void *p, int);
  typedef void (*moveIteratorFunc)(const void *p, void **);
  enum Position { ToBegin, ToEnd };
  typedef void (*moveIteratorFunc2)(const void *p, void **, Position position);
  typedef void (*advanceFunc)(void **p, int);
  typedef VariantData (*getFunc)(void *const *p, int metaTypeId, uint flags);
  typedef void (*destroyIterFunc)(void **p);
  typedef bool (*equalIterFunc)(void *const *p, void *const *other);
  typedef void (*copyIterFunc)(void **, void *const *);
  typedef void (*appendFunction)(const void *container, const void *newElement);

  IteratorCapability iteratorCapabilities() {
    return static_cast<IteratorCapability>(_iteratorCapabilities & 0xF);
  }
  uint revision() { return _iteratorCapabilities >> 4 & 0x7; }
  uint containerCapabilities() { return _iteratorCapabilities >> 7 & 0xF; }

  sizeFunc _size;
  atFunc _at;
  union {
    moveIteratorFunc _moveToBegin;
    moveIteratorFunc2 _moveTo;
  };
  union {
    moveIteratorFunc _moveToEnd;
    appendFunction _append;
  };
  advanceFunc _advance;
  getFunc _get;
  destroyIterFunc _destroyIter;
  equalIterFunc _equalIter;
  copyIterFunc _copyIter;

  template <class T> static int sizeImpl(const void *p) {
    return ContainerAPI<T>::size(static_cast<const T *>(p));
  }

  template <class T> static const void *atImpl(const void *p, int idx) {
    typename T::const_iterator i = static_cast<const T *>(p)->begin();
    std::advance(i, idx);
    return IteratorOwner<typename T::const_iterator>::getData(i);
  }

  template <class T>
  static void moveToBeginImpl(const void *container, void **iterator) {
    IteratorOwner<typename T::const_iterator>::assign(
        iterator, static_cast<const T *>(container)->begin());
  }

  template <class T>
  static void moveToEndImpl(const void *container, void **iterator) {
    IteratorOwner<typename T::const_iterator>::assign(
        iterator, static_cast<const T *>(container)->end());
  }

  template <class Container>
  static void moveToImpl(const void *container, void **iterator,
                         Position position) {
    if (position == ToBegin)
      moveToBeginImpl<Container>(container, iterator);
    else
      moveToEndImpl<Container>(container, iterator);
  }

  template <class T>
  static VariantData getImpl(void *const *iterator, int metaTypeId,
                             uint flags) {
    return VariantData(
        metaTypeId,
        IteratorOwner<typename T::const_iterator>::getData(iterator), flags);
  }

public:
  template <class T>
  QSequentialIterableImpl(const T *p)
      : _iterable(p), _iterator(nullptr),
        _metaType_id(qMetaTypeId<typename T::value_type>()),
        _metaType_flags(QTypeInfo<typename T::value_type>::isPointer),
        _iteratorCapabilities(
            ContainerAPI<T>::IteratorCapabilities | (1 << 4) |
            (ContainerCapabilitiesImpl<T>::ContainerCapabilities << (4 + 3))),
        _size(sizeImpl<T>), _at(atImpl<T>), _moveTo(moveToImpl<T>),
        _append(ContainerCapabilitiesImpl<T>::appendImpl),
        _advance(IteratorOwner<typename T::const_iterator>::advance),
        _get(getImpl<T>),
        _destroyIter(IteratorOwner<typename T::const_iterator>::destroy),
        _equalIter(IteratorOwner<typename T::const_iterator>::equal),
        _copyIter(IteratorOwner<typename T::const_iterator>::assign) {}

  QSequentialIterableImpl()
      : _iterable(nullptr), _iterator(nullptr),
        _metaType_id(QMetaType::UnknownType), _metaType_flags(0),
        _iteratorCapabilities(0 | (1 << 4)), _size(nullptr), _at(nullptr),
        _moveToBegin(nullptr), _moveToEnd(nullptr), _advance(nullptr),
        _get(nullptr), _destroyIter(nullptr), _equalIter(nullptr),
        _copyIter(nullptr) {}

  inline void moveToBegin() {
    if (revision() == 0)
      _moveToBegin(_iterable, &_iterator);
    else
      _moveTo(_iterable, &_iterator, ToBegin);
  }
  inline void moveToEnd() {
    if (revision() == 0)
      _moveToEnd(_iterable, &_iterator);
    else
      _moveTo(_iterable, &_iterator, ToEnd);
  }
  inline bool equal(const QSequentialIterableImpl &other) const {
    return _equalIter(&_iterator, &other._iterator);
  }
  inline QSequentialIterableImpl &advance(int i) {
    ((i > 0 || _iteratorCapabilities & BiDirectionalCapability)
         ? static_cast<void>(0)
         : qt_assert("i > 0 || _iteratorCapabilities & BiDirectionalCapability",
                     "/usr/local/include/QtCore/qmetatype.h", 1205));
    _advance(&_iterator, i);
    return *this;
  }

  inline void append(const void *newElement) {
    if (containerCapabilities() & ContainerIsAppendable)
      _append(_iterable, newElement);
  }

  inline VariantData getCurrent() const {
    return _get(&_iterator, _metaType_id, _metaType_flags);
  }

  VariantData at(int idx) const {
    return VariantData(_metaType_id, _at(_iterable, idx), _metaType_flags);
  }

  int size() const {
    ((_iterable) ? static_cast<void>(0)
                 : qt_assert("_iterable",
                             "/usr/local/include/QtCore/qmetatype.h", 1220));
    return _size(_iterable);
  }

  inline void destroyIter() { _destroyIter(&_iterator); }

  void copy(const QSequentialIterableImpl &other) {
    *this = other;
    _copyIter(&_iterator, &other._iterator);
  }
};
} // namespace QtMetaTypePrivate
template <> class QTypeInfo<QtMetaTypePrivate::QSequentialIterableImpl> {
public:
  enum {
    isSpecialized = true,
    isComplex = ((((Q_MOVABLE_TYPE)) & Q_PRIMITIVE_TYPE) == 0) &&
                !qIsTrivial<QtMetaTypePrivate::QSequentialIterableImpl>(),
    isStatic =
        ((((Q_MOVABLE_TYPE)) & (Q_MOVABLE_TYPE | Q_PRIMITIVE_TYPE)) == 0),
    isRelocatable =
        !isStatic || (((Q_MOVABLE_TYPE)) & Q_RELOCATABLE_TYPE) ||
        qIsRelocatable<QtMetaTypePrivate::QSequentialIterableImpl>(),
    isLarge =
        (sizeof(QtMetaTypePrivate::QSequentialIterableImpl) > sizeof(void *)),
    isPointer = false,
    isIntegral =
        std::is_integral<QtMetaTypePrivate::QSequentialIterableImpl>::value,
    isDummy = ((((Q_MOVABLE_TYPE)) & Q_DUMMY_TYPE) != 0),
    sizeOf = sizeof(QtMetaTypePrivate::QSequentialIterableImpl)
  };
  static inline const char *name() {
    return "QtMetaTypePrivate:: QSequentialIterableImpl";
  }
};
namespace QtMetaTypePrivate {

template <typename From> struct QSequentialIterableConvertFunctor {
  QSequentialIterableImpl operator()(const From &f) const {
    return QSequentialIterableImpl(&f);
  }
};
} // namespace QtMetaTypePrivate

namespace QtMetaTypePrivate {
template <typename T,
          bool = std::is_same<typename T::const_iterator::value_type,
                              typename T::mapped_type>::value>
struct AssociativeContainerAccessor {
  static const typename T::key_type &
  getKey(const typename T::const_iterator &it) {
    return it.key();
  }

  static const typename T::mapped_type &
  getValue(const typename T::const_iterator &it) {
    return it.value();
  }
};

template <typename T,
          bool = std::is_same<typename T::const_iterator::value_type,
                              std::pair<const typename T::key_type,
                                        typename T::mapped_type>>::value>
struct StlStyleAssociativeContainerAccessor;

template <typename T> struct StlStyleAssociativeContainerAccessor<T, true> {
  static const typename T::key_type &
  getKey(const typename T::const_iterator &it) {
    return it->first;
  }

  static const typename T::mapped_type &
  getValue(const typename T::const_iterator &it) {
    return it->second;
  }
};

template <typename T>
struct AssociativeContainerAccessor<T, false>
    : public StlStyleAssociativeContainerAccessor<T> {};

class QAssociativeIterableImpl {
public:
  const void *_iterable;
  void *_iterator;
  int _metaType_id_key;
  uint _metaType_flags_key;
  int _metaType_id_value;
  uint _metaType_flags_value;
  typedef int (*sizeFunc)(const void *p);
  typedef void (*findFunc)(const void *container, const void *p,
                           void **iterator);
  typedef void (*beginFunc)(const void *p, void **);
  typedef void (*advanceFunc)(void **p, int);
  typedef VariantData (*getFunc)(void *const *p, int metaTypeId, uint flags);
  typedef void (*destroyIterFunc)(void **p);
  typedef bool (*equalIterFunc)(void *const *p, void *const *other);
  typedef void (*copyIterFunc)(void **, void *const *);

  sizeFunc _size;
  findFunc _find;
  beginFunc _begin;
  beginFunc _end;
  advanceFunc _advance;
  getFunc _getKey;
  getFunc _getValue;
  destroyIterFunc _destroyIter;
  equalIterFunc _equalIter;
  copyIterFunc _copyIter;

  template <class T> static int sizeImpl(const void *p) {
    return int(std::distance(static_cast<const T *>(p)->begin(),
                             static_cast<const T *>(p)->end()));
  }

  template <class T>
  static void findImpl(const void *container, const void *p, void **iterator) {
    IteratorOwner<typename T::const_iterator>::assign(
        iterator, static_cast<const T *>(container)->find(
                      *static_cast<const typename T::key_type *>(p)));
  }

  template <class T> static void advanceImpl(void **p, int step) {
    std::advance(*static_cast<typename T::const_iterator *>(*p), step);
  }

  template <class T>
  static void beginImpl(const void *container, void **iterator) {
    IteratorOwner<typename T::const_iterator>::assign(
        iterator, static_cast<const T *>(container)->begin());
  }

  template <class T>
  static void endImpl(const void *container, void **iterator) {
    IteratorOwner<typename T::const_iterator>::assign(
        iterator, static_cast<const T *>(container)->end());
  }

  template <class T>
  static VariantData getKeyImpl(void *const *iterator, int metaTypeId,
                                uint flags) {
    return VariantData(
        metaTypeId,
        &AssociativeContainerAccessor<T>::getKey(
            *static_cast<typename T::const_iterator *>(*iterator)),
        flags);
  }

  template <class T>
  static VariantData getValueImpl(void *const *iterator, int metaTypeId,
                                  uint flags) {
    return VariantData(
        metaTypeId,
        &AssociativeContainerAccessor<T>::getValue(
            *static_cast<typename T::const_iterator *>(*iterator)),
        flags);
  }

public:
  template <class T>
  QAssociativeIterableImpl(const T *p)
      : _iterable(p), _iterator(nullptr),
        _metaType_id_key(qMetaTypeId<typename T::key_type>()),
        _metaType_flags_key(QTypeInfo<typename T::key_type>::isPointer),
        _metaType_id_value(qMetaTypeId<typename T::mapped_type>()),
        _metaType_flags_value(QTypeInfo<typename T::mapped_type>::isPointer),
        _size(sizeImpl<T>), _find(findImpl<T>), _begin(beginImpl<T>),
        _end(endImpl<T>), _advance(advanceImpl<T>), _getKey(getKeyImpl<T>),
        _getValue(getValueImpl<T>),
        _destroyIter(IteratorOwner<typename T::const_iterator>::destroy),
        _equalIter(IteratorOwner<typename T::const_iterator>::equal),
        _copyIter(IteratorOwner<typename T::const_iterator>::assign) {}

  QAssociativeIterableImpl()
      : _iterable(nullptr), _iterator(nullptr),
        _metaType_id_key(QMetaType::UnknownType), _metaType_flags_key(0),
        _metaType_id_value(QMetaType::UnknownType), _metaType_flags_value(0),
        _size(nullptr), _find(nullptr), _begin(nullptr), _end(nullptr),
        _advance(nullptr), _getKey(nullptr), _getValue(nullptr),
        _destroyIter(nullptr), _equalIter(nullptr), _copyIter(nullptr) {}

  inline void begin() { _begin(_iterable, &_iterator); }
  inline void end() { _end(_iterable, &_iterator); }
  inline bool equal(const QAssociativeIterableImpl &other) const {
    return _equalIter(&_iterator, &other._iterator);
  }
  inline QAssociativeIterableImpl &advance(int i) {
    _advance(&_iterator, i);
    return *this;
  }

  inline void destroyIter() { _destroyIter(&_iterator); }

  inline VariantData getCurrentKey() const {
    return _getKey(&_iterator, _metaType_id_key, _metaType_flags_key);
  }
  inline VariantData getCurrentValue() const {
    return _getValue(&_iterator, _metaType_id_value, _metaType_flags_value);
  }

  inline void find(const VariantData &key) {
    _find(_iterable, key.data, &_iterator);
  }

  int size() const {
    ((_iterable) ? static_cast<void>(0)
                 : qt_assert("_iterable",
                             "/usr/local/include/QtCore/qmetatype.h", 1395));
    return _size(_iterable);
  }

  void copy(const QAssociativeIterableImpl &other) {
    *this = other;
    _copyIter(&_iterator, &other._iterator);
  }
};
} // namespace QtMetaTypePrivate
template <> class QTypeInfo<QtMetaTypePrivate::QAssociativeIterableImpl> {
public:
  enum {
    isSpecialized = true,
    isComplex = ((((Q_MOVABLE_TYPE)) & Q_PRIMITIVE_TYPE) == 0) &&
                !qIsTrivial<QtMetaTypePrivate::QAssociativeIterableImpl>(),
    isStatic =
        ((((Q_MOVABLE_TYPE)) & (Q_MOVABLE_TYPE | Q_PRIMITIVE_TYPE)) == 0),
    isRelocatable =
        !isStatic || (((Q_MOVABLE_TYPE)) & Q_RELOCATABLE_TYPE) ||
        qIsRelocatable<QtMetaTypePrivate::QAssociativeIterableImpl>(),
    isLarge =
        (sizeof(QtMetaTypePrivate::QAssociativeIterableImpl) > sizeof(void *)),
    isPointer = false,
    isIntegral =
        std::is_integral<QtMetaTypePrivate::QAssociativeIterableImpl>::value,
    isDummy = ((((Q_MOVABLE_TYPE)) & Q_DUMMY_TYPE) != 0),
    sizeOf = sizeof(QtMetaTypePrivate::QAssociativeIterableImpl)
  };
  static inline const char *name() {
    return "QtMetaTypePrivate:: QAssociativeIterableImpl";
  }
};
namespace QtMetaTypePrivate {

template <typename From> struct QAssociativeIterableConvertFunctor {
  QAssociativeIterableImpl operator()(const From &f) const {
    return QAssociativeIterableImpl(&f);
  }
};

class QPairVariantInterfaceImpl {
  const void *_pair;
  int _metaType_id_first;
  uint _metaType_flags_first;
  int _metaType_id_second;
  uint _metaType_flags_second;

  typedef VariantData (*getFunc)(const void *const *p, int metaTypeId,
                                 uint flags);

  getFunc _getFirst;
  getFunc _getSecond;

  template <class T>
  static VariantData getFirstImpl(const void *const *pair, int metaTypeId,
                                  uint flags) {
    return VariantData(metaTypeId, &static_cast<const T *>(*pair)->first,
                       flags);
  }
  template <class T>
  static VariantData getSecondImpl(const void *const *pair, int metaTypeId,
                                   uint flags) {
    return VariantData(metaTypeId, &static_cast<const T *>(*pair)->second,
                       flags);
  }

public:
  template <class T>
  QPairVariantInterfaceImpl(const T *p)
      : _pair(p), _metaType_id_first(qMetaTypeId<typename T::first_type>()),
        _metaType_flags_first(QTypeInfo<typename T::first_type>::isPointer),
        _metaType_id_second(qMetaTypeId<typename T::second_type>()),
        _metaType_flags_second(QTypeInfo<typename T::second_type>::isPointer),
        _getFirst(getFirstImpl<T>), _getSecond(getSecondImpl<T>) {}

  QPairVariantInterfaceImpl()
      : _pair(nullptr), _metaType_id_first(QMetaType::UnknownType),
        _metaType_flags_first(0), _metaType_id_second(QMetaType::UnknownType),
        _metaType_flags_second(0), _getFirst(nullptr), _getSecond(nullptr) {}

  inline VariantData first() const {
    return _getFirst(&_pair, _metaType_id_first, _metaType_flags_first);
  }
  inline VariantData second() const {
    return _getSecond(&_pair, _metaType_id_second, _metaType_flags_second);
  }
};
} // namespace QtMetaTypePrivate
template <> class QTypeInfo<QtMetaTypePrivate::QPairVariantInterfaceImpl> {
public:
  enum {
    isSpecialized = true,
    isComplex = ((((Q_MOVABLE_TYPE)) & Q_PRIMITIVE_TYPE) == 0) &&
                !qIsTrivial<QtMetaTypePrivate::QPairVariantInterfaceImpl>(),
    isStatic =
        ((((Q_MOVABLE_TYPE)) & (Q_MOVABLE_TYPE | Q_PRIMITIVE_TYPE)) == 0),
    isRelocatable =
        !isStatic || (((Q_MOVABLE_TYPE)) & Q_RELOCATABLE_TYPE) ||
        qIsRelocatable<QtMetaTypePrivate::QPairVariantInterfaceImpl>(),
    isLarge =
        (sizeof(QtMetaTypePrivate::QPairVariantInterfaceImpl) > sizeof(void *)),
    isPointer = false,
    isIntegral =
        std::is_integral<QtMetaTypePrivate::QPairVariantInterfaceImpl>::value,
    isDummy = ((((Q_MOVABLE_TYPE)) & Q_DUMMY_TYPE) != 0),
    sizeOf = sizeof(QtMetaTypePrivate::QPairVariantInterfaceImpl)
  };
  static inline const char *name() {
    return "QtMetaTypePrivate:: QPairVariantInterfaceImpl";
  }
};
namespace QtMetaTypePrivate {

template <typename From> struct QPairVariantInterfaceConvertFunctor;

template <typename T, typename U>
struct QPairVariantInterfaceConvertFunctor<QPair<T, U>> {
  QPairVariantInterfaceImpl operator()(const QPair<T, U> &f) const {
    return QPairVariantInterfaceImpl(&f);
  }
};

template <typename T, typename U>
struct QPairVariantInterfaceConvertFunctor<std::pair<T, U>> {
  QPairVariantInterfaceImpl operator()(const std::pair<T, U> &f) const {
    return QPairVariantInterfaceImpl(&f);
  }
};

} // namespace QtMetaTypePrivate

class QObject;
class QWidget;

template <class T> class QSharedPointer;
template <class T> class QWeakPointer;
template <class T> class QPointer;

namespace QtPrivate {
template <typename T> struct IsPointerToTypeDerivedFromQObject {
  enum { Value = false };
};

template <> struct IsPointerToTypeDerivedFromQObject<void *> {
  enum { Value = false };
};
template <> struct IsPointerToTypeDerivedFromQObject<const void *> {
  enum { Value = false };
};
template <> struct IsPointerToTypeDerivedFromQObject<QObject *> {
  enum { Value = true };
};

template <typename T> struct IsPointerToTypeDerivedFromQObject<T *> {
  typedef qint8 yes_type;
  typedef qint64 no_type;

  static yes_type checkType(QObject *);

  static no_type checkType(...);
  static_assert(
      bool(sizeof(T)),
      "Type argument of Q_DECLARE_METATYPE(T*) must be fully defined");
  enum {
    Value = sizeof(checkType(static_cast<T *>(nullptr))) == sizeof(yes_type)
  };
};

template <typename T, typename Enable = void> struct IsGadgetHelper {
  enum { IsRealGadget = false, IsGadgetOrDerivedFrom = false };
};

template <typename T> struct IsGadgetHelper<T, typename T::QtGadgetHelper> {
  template <typename X> static char checkType(void (X::*)());
  static void *checkType(void (T::*)());
  enum {
    IsRealGadget =
        sizeof(checkType(&T::qt_check_for_QGADGET_macro)) == sizeof(void *),
    IsGadgetOrDerivedFrom = true
  };
};

template <typename T, typename Enable = void> struct IsPointerToGadgetHelper {
  enum { IsRealGadget = false, IsGadgetOrDerivedFrom = false };
};

template <typename T>
struct IsPointerToGadgetHelper<T *, typename T::QtGadgetHelper> {
  using BaseType = T;
  template <typename X> static char checkType(void (X::*)());
  static void *checkType(void (T::*)());
  enum {
    IsRealGadget =
        !IsPointerToTypeDerivedFromQObject<T *>::Value &&
        sizeof(checkType(&T::qt_check_for_QGADGET_macro)) == sizeof(void *),
    IsGadgetOrDerivedFrom = !IsPointerToTypeDerivedFromQObject<T *>::Value
  };
};

template <typename T> char qt_getEnumMetaObject(const T &);

template <typename T> struct IsQEnumHelper {
  static const T &declval();
  enum {
    Value = sizeof(qt_getEnumMetaObject(declval())) == sizeof(QMetaObject *)
  };
};

template <> struct IsQEnumHelper<void> {
  enum { Value = false };
};

template <typename T, typename Enable = void> struct MetaObjectForType {
  static inline const QMetaObject *value() { return nullptr; }
};

template <> struct MetaObjectForType<void> {
  static inline const QMetaObject *value() { return nullptr; }
};

template <typename T>
struct MetaObjectForType<
    T *, typename std::enable_if<
             IsPointerToTypeDerivedFromQObject<T *>::Value>::type> {
  static inline const QMetaObject *value() { return &T::staticMetaObject; }
};

template <typename T>
struct MetaObjectForType<
    T,
    typename std::enable_if<IsGadgetHelper<T>::IsGadgetOrDerivedFrom>::type> {
  static inline const QMetaObject *value() { return &T::staticMetaObject; }
};

template <typename T>
struct MetaObjectForType<T, typename std::enable_if<IsPointerToGadgetHelper<
                                T>::IsGadgetOrDerivedFrom>::type> {
  static inline const QMetaObject *value() {
    return &IsPointerToGadgetHelper<T>::BaseType::staticMetaObject;
  }
};
template <typename T>
struct MetaObjectForType<
    T, typename std::enable_if<IsQEnumHelper<T>::Value>::type> {
  static inline const QMetaObject *value() { return qt_getEnumMetaObject(T()); }
};

template <typename T> struct IsSharedPointerToTypeDerivedFromQObject {
  enum { Value = false };
};

template <typename T>
struct IsSharedPointerToTypeDerivedFromQObject<QSharedPointer<T>>
    : IsPointerToTypeDerivedFromQObject<T *> {};

template <typename T> struct IsWeakPointerToTypeDerivedFromQObject {
  enum { Value = false };
};

template <typename T>
struct IsWeakPointerToTypeDerivedFromQObject<QWeakPointer<T>>
    : IsPointerToTypeDerivedFromQObject<T *> {};

template <typename T> struct IsTrackingPointerToTypeDerivedFromQObject {
  enum { Value = false };
};

template <typename T>
struct IsTrackingPointerToTypeDerivedFromQObject<QPointer<T>> {
  enum { Value = true };
};

template <typename T> struct IsSequentialContainer {
  enum { Value = false };
};

template <typename T> struct IsAssociativeContainer {
  enum { Value = false };
};

template <typename T, bool = QtPrivate::IsSequentialContainer<T>::Value>
struct SequentialContainerConverterHelper {
  static bool registerConverter(int) { return false; }
};

template <typename T, bool = QMetaTypeId2<typename T::value_type>::Defined>
struct ValueTypeIsMetaType {
  static bool registerConverter(int) { return false; }
};

template <typename T>
struct SequentialContainerConverterHelper<T, true> : ValueTypeIsMetaType<T> {};

template <typename T, bool = QtPrivate::IsAssociativeContainer<T>::Value>
struct AssociativeContainerConverterHelper {
  static bool registerConverter(int) { return false; }
};

template <typename T, bool = QMetaTypeId2<typename T::mapped_type>::Defined>
struct AssociativeValueTypeIsMetaType {
  static bool registerConverter(int) { return false; }
};

template <typename T, bool = QMetaTypeId2<typename T::key_type>::Defined>
struct KeyAndValueTypeIsMetaType {
  static bool registerConverter(int) { return false; }
};

template <typename T>
struct KeyAndValueTypeIsMetaType<T, true> : AssociativeValueTypeIsMetaType<T> {
};

template <typename T>
struct AssociativeContainerConverterHelper<T, true>
    : KeyAndValueTypeIsMetaType<T> {};

template <typename T, bool = QMetaTypeId2<typename T::first_type>::Defined
                          &&QMetaTypeId2<typename T::second_type>::Defined>
struct IsMetaTypePair {
  static bool registerConverter(int) { return false; }
};

template <typename T> struct IsMetaTypePair<T, true> {
  inline static bool registerConverter(int id);
};

template <typename T> struct IsPair {
  static bool registerConverter(int) { return false; }
};
template <typename T, typename U>
struct IsPair<QPair<T, U>> : IsMetaTypePair<QPair<T, U>> {};
template <typename T, typename U>
struct IsPair<std::pair<T, U>> : IsMetaTypePair<std::pair<T, U>> {};

template <typename T> struct MetaTypePairHelper : IsPair<T> {};

template <typename T, typename = void> struct MetaTypeSmartPointerHelper {
  static bool registerConverter(int) { return false; }
};

__attribute__((visibility("default"))) bool
isBuiltinType(const QByteArray &type);
} // namespace QtPrivate

template <typename T,
          int = QtPrivate::IsPointerToTypeDerivedFromQObject<T>::Value
                    ? QMetaType::PointerToQObject
                : QtPrivate::IsGadgetHelper<T>::IsRealGadget
                    ? QMetaType::IsGadget
                : QtPrivate::IsPointerToGadgetHelper<T>::IsRealGadget
                    ? QMetaType::PointerToGadget
                : QtPrivate::IsQEnumHelper<T>::Value ? QMetaType::IsEnumeration
                                                     : 0>
struct QMetaTypeIdQObject {
  enum { Defined = 0 };
};

template <typename T> struct QMetaTypeId : public QMetaTypeIdQObject<T> {};

template <typename T> struct QMetaTypeId2 {
  enum { Defined = QMetaTypeId<T>::Defined, IsBuiltIn = false };
  static inline constexpr int qt_metatype_id() {
    return QMetaTypeId<T>::qt_metatype_id();
  }
};

template <typename T> struct QMetaTypeId2<const T &> : QMetaTypeId2<T> {};

template <typename T> struct QMetaTypeId2<T &> {
  enum { Defined = false };
};

namespace QtPrivate {
template <typename T, bool Defined = QMetaTypeId2<T>::Defined>
struct QMetaTypeIdHelper {
  static inline constexpr int qt_metatype_id() {
    return QMetaTypeId2<T>::qt_metatype_id();
  }
};
template <typename T> struct QMetaTypeIdHelper<T, false> {
  static inline constexpr int qt_metatype_id() { return -1; }
};

template <typename Result, typename... Args>
struct IsPointerToTypeDerivedFromQObject<Result (*)(Args...)> {
  enum { Value = false };
};

template <typename T> struct QMetaTypeTypeFlags {
  enum {
    Flags =
        (QTypeInfoQuery<T>::isRelocatable ? QMetaType::MovableType : 0) |
        (QTypeInfo<T>::isComplex ? QMetaType::NeedsConstruction : 0) |
        (QTypeInfo<T>::isComplex ? QMetaType::NeedsDestruction : 0) |
        (IsPointerToTypeDerivedFromQObject<T>::Value
             ? QMetaType::PointerToQObject
             : 0) |
        (IsSharedPointerToTypeDerivedFromQObject<T>::Value
             ? QMetaType::SharedPointerToQObject
             : 0) |
        (IsWeakPointerToTypeDerivedFromQObject<T>::Value
             ? QMetaType::WeakPointerToQObject
             : 0) |
        (IsTrackingPointerToTypeDerivedFromQObject<T>::Value
             ? QMetaType::TrackingPointerToQObject
             : 0) |
        (std::is_enum<T>::value ? QMetaType::IsEnumeration : 0) |
        (IsGadgetHelper<T>::IsGadgetOrDerivedFrom ? QMetaType::IsGadget : 0) |
        (IsPointerToGadgetHelper<T>::IsGadgetOrDerivedFrom
             ? QMetaType::PointerToGadget
             : 0)
  };
};

template <typename T, bool defined> struct MetaTypeDefinedHelper {
  enum DefinedType { Defined = defined };
};

template <typename SmartPointer> struct QSmartPointerConvertFunctor {
  QObject *operator()(const SmartPointer &p) const { return p.operator->(); }
};

template <typename T> struct EnableInternalDataWrap;

template <typename T> struct QSmartPointerConvertFunctor<QWeakPointer<T>> {
  QObject *operator()(const QWeakPointer<T> &p) const {
    return QtPrivate::EnableInternalDataWrap<T>::internalData(p);
  }
};
} // namespace QtPrivate

template <typename T>
int qRegisterNormalizedMetaType(
    const ::QByteArray &normalizedTypeName

    ,
    T *dummy = 0,
    typename QtPrivate::MetaTypeDefinedHelper<
        T, QMetaTypeId2<T>::Defined && !QMetaTypeId2<T>::IsBuiltIn>::DefinedType
        defined = QtPrivate::MetaTypeDefinedHelper<
            T, QMetaTypeId2<T>::Defined && !QMetaTypeId2<T>::IsBuiltIn>::Defined

) {

  ((normalizedTypeName ==
    QMetaObject::normalizedType(normalizedTypeName.constData()))
       ? static_cast<void>(0)
       : qt_assert_x(
             "qRegisterNormalizedMetaType",
             "qRegisterNormalizedMetaType was called with a not normalized "
             "type name, please call qRegisterMetaType instead.",
             "/usr/local/include/QtCore/qmetatype.h", 1855));

  const int typedefOf =
      dummy ? -1 : QtPrivate::QMetaTypeIdHelper<T>::qt_metatype_id();
  if (typedefOf != -1)
    return QMetaType::registerNormalizedTypedef(normalizedTypeName, typedefOf);

  QMetaType::TypeFlags flags(QtPrivate::QMetaTypeTypeFlags<T>::Flags);

  if (defined)
    flags |= QMetaType::WasDeclaredAsMetaType;

  const int id = QMetaType::registerNormalizedType(
      normalizedTypeName,
      QtMetaTypePrivate::QMetaTypeFunctionHelper<T>::Destruct,
      QtMetaTypePrivate::QMetaTypeFunctionHelper<T>::Construct, int(sizeof(T)),
      flags, QtPrivate::MetaObjectForType<T>::value());

  if (id > 0) {
    QtPrivate::SequentialContainerConverterHelper<T>::registerConverter(id);
    QtPrivate::AssociativeContainerConverterHelper<T>::registerConverter(id);
    QtPrivate::MetaTypePairHelper<T>::registerConverter(id);
    QtPrivate::MetaTypeSmartPointerHelper<T>::registerConverter(id);
  }

  return id;
}

template <typename T>
int qRegisterMetaType(
    const char *typeName

    ,
    T *dummy = nullptr,
    typename QtPrivate::MetaTypeDefinedHelper<
        T, QMetaTypeId2<T>::Defined && !QMetaTypeId2<T>::IsBuiltIn>::DefinedType
        defined = QtPrivate::MetaTypeDefinedHelper<
            T, QMetaTypeId2<T>::Defined && !QMetaTypeId2<T>::IsBuiltIn>::Defined

) {

  ::QByteArray normalizedTypeName = QMetaObject::normalizedType(typeName);

  return qRegisterNormalizedMetaType<T>(normalizedTypeName, dummy, defined);
}

template <typename T>
void qRegisterMetaTypeStreamOperators(const char *typeName

                                      ,
                                      T * = nullptr

) {
  qRegisterMetaType<T>(typeName);
  QMetaType::registerStreamOperators(
      typeName, QtMetaTypePrivate::QMetaTypeFunctionHelper<T>::Save,
      QtMetaTypePrivate::QMetaTypeFunctionHelper<T>::Load);
}

template <typename T> inline constexpr int qMetaTypeId() {
  static_assert(bool(QMetaTypeId2<T>::Defined),
                "Type is not registered, please use the Q_DECLARE_METATYPE "
                "macro to make it known to Qt's meta-object system");
  return QMetaTypeId2<T>::qt_metatype_id();
}

template <typename T> inline constexpr int qRegisterMetaType() {
  return qMetaTypeId<T>();
}

template <typename T>
__attribute__((__deprecated__)) inline constexpr int qMetaTypeId(T *) {
  return qMetaTypeId<T>();
}

template <typename T>
__attribute__((__deprecated__)) inline constexpr int qRegisterMetaType(T *) {
  return qRegisterMetaType<T>();
}

template <typename T>
struct QMetaTypeIdQObject<T *, QMetaType::PointerToQObject> {
  enum { Defined = 1 };

  static int qt_metatype_id() {
    static QBasicAtomicInt metatype_id = {0};
    if (const int id = metatype_id.loadAcquire())
      return id;
    const char *const cName = T::staticMetaObject.className();
    QByteArray typeName;
    typeName.reserve(int(strlen(cName)) + 1);
    typeName.append(cName).append('*');
    const int newId = qRegisterNormalizedMetaType<T *>(
        typeName, reinterpret_cast<T **>(quintptr(-1)));
    metatype_id.storeRelease(newId);
    return newId;
  }
};

template <typename T> struct QMetaTypeIdQObject<T, QMetaType::IsGadget> {
  enum { Defined = std::is_default_constructible<T>::value };

  static int qt_metatype_id() {
    static QBasicAtomicInt metatype_id = {0};
    if (const int id = metatype_id.loadAcquire())
      return id;
    const char *const cName = T::staticMetaObject.className();
    const int newId = qRegisterNormalizedMetaType<T>(
        cName, reinterpret_cast<T *>(quintptr(-1)));
    metatype_id.storeRelease(newId);
    return newId;
  }
};

template <typename T>
struct QMetaTypeIdQObject<T *, QMetaType::PointerToGadget> {
  enum { Defined = 1 };

  static int qt_metatype_id() {
    static QBasicAtomicInt metatype_id = {0};
    if (const int id = metatype_id.loadAcquire())
      return id;
    const char *const cName = T::staticMetaObject.className();
    QByteArray typeName;
    typeName.reserve(int(strlen(cName)) + 1);
    typeName.append(cName).append('*');
    const int newId = qRegisterNormalizedMetaType<T *>(
        typeName, reinterpret_cast<T **>(quintptr(-1)));
    metatype_id.storeRelease(newId);
    return newId;
  }
};

template <typename T> struct QMetaTypeIdQObject<T, QMetaType::IsEnumeration> {
  enum { Defined = 1 };

  static int qt_metatype_id() {
    static QBasicAtomicInt metatype_id = {0};
    if (const int id = metatype_id.loadAcquire())
      return id;
    const char *eName = qt_getEnumName(T());
    const char *cName = qt_getEnumMetaObject(T())->className();
    QByteArray typeName;
    typeName.reserve(int(strlen(cName) + 2 + strlen(eName)));
    typeName.append(cName).append("::").append(eName);
    const int newId = qRegisterNormalizedMetaType<T>(
        typeName, reinterpret_cast<T *>(quintptr(-1)));
    metatype_id.storeRelease(newId);
    return newId;
  }
};

template <typename T> inline int qRegisterMetaTypeStreamOperators() {
  int id = qMetaTypeId<T>();
  QMetaType::registerStreamOperators(
      id, QtMetaTypePrivate::QMetaTypeFunctionHelper<T>::Save,
      QtMetaTypePrivate::QMetaTypeFunctionHelper<T>::Load);
  return id;
}
class QChar;
class QString;
class QStringList;
class QByteArray;
class QBitArray;
class QDate;
class QTime;
class QDateTime;
class QUrl;
class QLocale;
class QRect;
class QRectF;
class QSize;
class QSizeF;
class QLine;
class QLineF;
class QPoint;
class QPointF;
class QRegExp;
class QEasingCurve;
class QUuid;
class QVariant;
class QRegularExpression;
class QJsonValue;
class QJsonObject;
class QJsonArray;
class QJsonDocument;
class QCborValue;
class QCborArray;
class QCborMap;
class QModelIndex;
class QPersistentModelIndex;
class QFont;
class QPixmap;
class QBrush;
class QColor;
class QPalette;
class QIcon;
class QImage;
class QPolygon;
class QRegion;
class QBitmap;
class QCursor;
class QKeySequence;
class QPen;
class QTextLength;
class QTextFormat;
class QMatrix;
class QTransform;
class QMatrix4x4;
class QVector2D;
class QVector3D;
class QVector4D;
class QQuaternion;
class QPolygonF;
class QColorSpace;
class QSizePolicy;

typedef QList<QVariant> QVariantList;
typedef QMap<QString, QVariant> QVariantMap;
typedef QHash<QString, QVariant> QVariantHash;

typedef QList<QByteArray> QByteArrayList;
namespace QtPrivate {

template <typename T, bool = false> struct SharedPointerMetaTypeIdHelper {
  enum { Defined = 0 };
  static int qt_metatype_id() { return -1; }
};

} // namespace QtPrivate
template <class T> class QList;
template <typename T> struct QMetaTypeId<QList<T>> {
  enum { Defined = QMetaTypeId2<T>::Defined };
  static int qt_metatype_id() {
    static QBasicAtomicInt metatype_id = {0};
    if (const int id = metatype_id.loadRelaxed())
      return id;
    const char *tName = QMetaType::typeName(qMetaTypeId<T>());
    ((tName)
         ? static_cast<void>(0)
         : qt_assert("tName", "/usr/local/include/QtCore/qmetatype.h", 2254));
    const int tNameLen = int(qstrlen(tName));
    QByteArray typeName;
    typeName.reserve(int(sizeof("QList")) + 1 + tNameLen + 1 + 1);
    typeName.append("QList", int(sizeof("QList")) - 1)
        .append('<')
        .append(tName, tNameLen);
    if (typeName.endsWith('>'))
      typeName.append(' ');
    typeName.append('>');
    const int newId = qRegisterNormalizedMetaType<QList<T>>(
        typeName, reinterpret_cast<QList<T> *>(quintptr(-1)));
    metatype_id.storeRelease(newId);
    return newId;
  }
};
namespace QtPrivate {
template <typename T> struct IsSequentialContainer<QList<T>> {
  enum { Value = true };
};
} // namespace QtPrivate
template <class T> class QVector;
template <typename T> struct QMetaTypeId<QVector<T>> {
  enum { Defined = QMetaTypeId2<T>::Defined };
  static int qt_metatype_id() {
    static QBasicAtomicInt metatype_id = {0};
    if (const int id = metatype_id.loadRelaxed())
      return id;
    const char *tName = QMetaType::typeName(qMetaTypeId<T>());
    ((tName)
         ? static_cast<void>(0)
         : qt_assert("tName", "/usr/local/include/QtCore/qmetatype.h", 2254));
    const int tNameLen = int(qstrlen(tName));
    QByteArray typeName;
    typeName.reserve(int(sizeof("QVector")) + 1 + tNameLen + 1 + 1);
    typeName.append("QVector", int(sizeof("QVector")) - 1)
        .append('<')
        .append(tName, tNameLen);
    if (typeName.endsWith('>'))
      typeName.append(' ');
    typeName.append('>');
    const int newId = qRegisterNormalizedMetaType<QVector<T>>(
        typeName, reinterpret_cast<QVector<T> *>(quintptr(-1)));
    metatype_id.storeRelease(newId);
    return newId;
  }
};
namespace QtPrivate {
template <typename T> struct IsSequentialContainer<QVector<T>> {
  enum { Value = true };
};
} // namespace QtPrivate
template <class T> class QQueue;
template <typename T> struct QMetaTypeId<QQueue<T>> {
  enum { Defined = QMetaTypeId2<T>::Defined };
  static int qt_metatype_id() {
    static QBasicAtomicInt metatype_id = {0};
    if (const int id = metatype_id.loadRelaxed())
      return id;
    const char *tName = QMetaType::typeName(qMetaTypeId<T>());
    ((tName)
         ? static_cast<void>(0)
         : qt_assert("tName", "/usr/local/include/QtCore/qmetatype.h", 2254));
    const int tNameLen = int(qstrlen(tName));
    QByteArray typeName;
    typeName.reserve(int(sizeof("QQueue")) + 1 + tNameLen + 1 + 1);
    typeName.append("QQueue", int(sizeof("QQueue")) - 1)
        .append('<')
        .append(tName, tNameLen);
    if (typeName.endsWith('>'))
      typeName.append(' ');
    typeName.append('>');
    const int newId = qRegisterNormalizedMetaType<QQueue<T>>(
        typeName, reinterpret_cast<QQueue<T> *>(quintptr(-1)));
    metatype_id.storeRelease(newId);
    return newId;
  }
};
namespace QtPrivate {
template <typename T> struct IsSequentialContainer<QQueue<T>> {
  enum { Value = true };
};
} // namespace QtPrivate
template <class T> class QStack;
template <typename T> struct QMetaTypeId<QStack<T>> {
  enum { Defined = QMetaTypeId2<T>::Defined };
  static int qt_metatype_id() {
    static QBasicAtomicInt metatype_id = {0};
    if (const int id = metatype_id.loadRelaxed())
      return id;
    const char *tName = QMetaType::typeName(qMetaTypeId<T>());
    ((tName)
         ? static_cast<void>(0)
         : qt_assert("tName", "/usr/local/include/QtCore/qmetatype.h", 2254));
    const int tNameLen = int(qstrlen(tName));
    QByteArray typeName;
    typeName.reserve(int(sizeof("QStack")) + 1 + tNameLen + 1 + 1);
    typeName.append("QStack", int(sizeof("QStack")) - 1)
        .append('<')
        .append(tName, tNameLen);
    if (typeName.endsWith('>'))
      typeName.append(' ');
    typeName.append('>');
    const int newId = qRegisterNormalizedMetaType<QStack<T>>(
        typeName, reinterpret_cast<QStack<T> *>(quintptr(-1)));
    metatype_id.storeRelease(newId);
    return newId;
  }
};
namespace QtPrivate {
template <typename T> struct IsSequentialContainer<QStack<T>> {
  enum { Value = true };
};
} // namespace QtPrivate
template <class T> class QSet;
template <typename T> struct QMetaTypeId<QSet<T>> {
  enum { Defined = QMetaTypeId2<T>::Defined };
  static int qt_metatype_id() {
    static QBasicAtomicInt metatype_id = {0};
    if (const int id = metatype_id.loadRelaxed())
      return id;
    const char *tName = QMetaType::typeName(qMetaTypeId<T>());
    ((tName)
         ? static_cast<void>(0)
         : qt_assert("tName", "/usr/local/include/QtCore/qmetatype.h", 2254));
    const int tNameLen = int(qstrlen(tName));
    QByteArray typeName;
    typeName.reserve(int(sizeof("QSet")) + 1 + tNameLen + 1 + 1);
    typeName.append("QSet", int(sizeof("QSet")) - 1)
        .append('<')
        .append(tName, tNameLen);
    if (typeName.endsWith('>'))
      typeName.append(' ');
    typeName.append('>');
    const int newId = qRegisterNormalizedMetaType<QSet<T>>(
        typeName, reinterpret_cast<QSet<T> *>(quintptr(-1)));
    metatype_id.storeRelease(newId);
    return newId;
  }
};
namespace QtPrivate {
template <typename T> struct IsSequentialContainer<QSet<T>> {
  enum { Value = true };
};
} // namespace QtPrivate

template <typename T> struct QMetaTypeId<std::vector<T>> {
  enum { Defined = QMetaTypeId2<T>::Defined };
  static int qt_metatype_id() {
    static QBasicAtomicInt metatype_id = {0};
    if (const int id = metatype_id.loadRelaxed())
      return id;
    const char *tName = QMetaType::typeName(qMetaTypeId<T>());
    ((tName)
         ? static_cast<void>(0)
         : qt_assert("tName", "/usr/local/include/QtCore/qmetatype.h", 2260));
    const int tNameLen = int(qstrlen(tName));
    QByteArray typeName;
    typeName.reserve(int(sizeof("std::vector")) + 1 + tNameLen + 1 + 1);
    typeName.append("std::vector", int(sizeof("std::vector")) - 1)
        .append('<')
        .append(tName, tNameLen);
    if (typeName.endsWith('>'))
      typeName.append(' ');
    typeName.append('>');
    const int newId = qRegisterNormalizedMetaType<std::vector<T>>(
        typeName, reinterpret_cast<std::vector<T> *>(quintptr(-1)));
    metatype_id.storeRelease(newId);
    return newId;
  }
};
namespace QtPrivate {
template <typename T> struct IsSequentialContainer<std::vector<T>> {
  enum { Value = true };
};
} // namespace QtPrivate
template <typename T> struct QMetaTypeId<std::list<T>> {
  enum { Defined = QMetaTypeId2<T>::Defined };
  static int qt_metatype_id() {
    static QBasicAtomicInt metatype_id = {0};
    if (const int id = metatype_id.loadRelaxed())
      return id;
    const char *tName = QMetaType::typeName(qMetaTypeId<T>());
    ((tName)
         ? static_cast<void>(0)
         : qt_assert("tName", "/usr/local/include/QtCore/qmetatype.h", 2261));
    const int tNameLen = int(qstrlen(tName));
    QByteArray typeName;
    typeName.reserve(int(sizeof("std::list")) + 1 + tNameLen + 1 + 1);
    typeName.append("std::list", int(sizeof("std::list")) - 1)
        .append('<')
        .append(tName, tNameLen);
    if (typeName.endsWith('>'))
      typeName.append(' ');
    typeName.append('>');
    const int newId = qRegisterNormalizedMetaType<std::list<T>>(
        typeName, reinterpret_cast<std::list<T> *>(quintptr(-1)));
    metatype_id.storeRelease(newId);
    return newId;
  }
};
namespace QtPrivate {
template <typename T> struct IsSequentialContainer<std::list<T>> {
  enum { Value = true };
};
} // namespace QtPrivate

template <class T1, class T2> class QHash;
template <class T1, class T2> class QMap;
template <class T1, class T2> struct QPair;
namespace QtPrivate {
template <typename T, typename U> struct IsAssociativeContainer<QHash<T, U>> {
  enum { Value = true };
};
} // namespace QtPrivate
template <typename T, typename U> struct QMetaTypeId<QHash<T, U>> {
  enum { Defined = QMetaTypeId2<T>::Defined && QMetaTypeId2<U>::Defined };
  static int qt_metatype_id() {
    static QBasicAtomicInt metatype_id = {0};
    if (const int id = metatype_id.loadAcquire())
      return id;
    const char *tName = QMetaType::typeName(qMetaTypeId<T>());
    const char *uName = QMetaType::typeName(qMetaTypeId<U>());
    ((tName)
         ? static_cast<void>(0)
         : qt_assert("tName", "/usr/local/include/QtCore/qmetatype.h", 2284));
    ((uName)
         ? static_cast<void>(0)
         : qt_assert("uName", "/usr/local/include/QtCore/qmetatype.h", 2284));
    const int tNameLen = int(qstrlen(tName));
    const int uNameLen = int(qstrlen(uName));
    QByteArray typeName;
    typeName.reserve(int(sizeof("QHash")) + 1 + tNameLen + 1 + uNameLen + 1 +
                     1);
    typeName.append("QHash", int(sizeof("QHash")) - 1)
        .append('<')
        .append(tName, tNameLen)
        .append(',')
        .append(uName, uNameLen);
    if (typeName.endsWith('>'))
      typeName.append(' ');
    typeName.append('>');
    const int newId = qRegisterNormalizedMetaType<QHash<T, U>>(
        typeName, reinterpret_cast<QHash<T, U> *>(quintptr(-1)));
    metatype_id.storeRelease(newId);
    return newId;
  }
};
namespace QtPrivate {
template <typename T, typename U> struct IsAssociativeContainer<QMap<T, U>> {
  enum { Value = true };
};
} // namespace QtPrivate
template <typename T, typename U> struct QMetaTypeId<QMap<T, U>> {
  enum { Defined = QMetaTypeId2<T>::Defined && QMetaTypeId2<U>::Defined };
  static int qt_metatype_id() {
    static QBasicAtomicInt metatype_id = {0};
    if (const int id = metatype_id.loadAcquire())
      return id;
    const char *tName = QMetaType::typeName(qMetaTypeId<T>());
    const char *uName = QMetaType::typeName(qMetaTypeId<U>());
    ((tName)
         ? static_cast<void>(0)
         : qt_assert("tName", "/usr/local/include/QtCore/qmetatype.h", 2285));
    ((uName)
         ? static_cast<void>(0)
         : qt_assert("uName", "/usr/local/include/QtCore/qmetatype.h", 2285));
    const int tNameLen = int(qstrlen(tName));
    const int uNameLen = int(qstrlen(uName));
    QByteArray typeName;
    typeName.reserve(int(sizeof("QMap")) + 1 + tNameLen + 1 + uNameLen + 1 + 1);
    typeName.append("QMap", int(sizeof("QMap")) - 1)
        .append('<')
        .append(tName, tNameLen)
        .append(',')
        .append(uName, uNameLen);
    if (typeName.endsWith('>'))
      typeName.append(' ');
    typeName.append('>');
    const int newId = qRegisterNormalizedMetaType<QMap<T, U>>(
        typeName, reinterpret_cast<QMap<T, U> *>(quintptr(-1)));
    metatype_id.storeRelease(newId);
    return newId;
  }
};
namespace QtPrivate {
template <typename T, typename U>
struct IsAssociativeContainer<std::map<T, U>> {
  enum { Value = true };
};
} // namespace QtPrivate
template <typename T, typename U> struct QMetaTypeId<std::map<T, U>> {
  enum { Defined = QMetaTypeId2<T>::Defined && QMetaTypeId2<U>::Defined };
  static int qt_metatype_id() {
    static QBasicAtomicInt metatype_id = {0};
    if (const int id = metatype_id.loadAcquire())
      return id;
    const char *tName = QMetaType::typeName(qMetaTypeId<T>());
    const char *uName = QMetaType::typeName(qMetaTypeId<U>());
    ((tName)
         ? static_cast<void>(0)
         : qt_assert("tName", "/usr/local/include/QtCore/qmetatype.h", 2286));
    ((uName)
         ? static_cast<void>(0)
         : qt_assert("uName", "/usr/local/include/QtCore/qmetatype.h", 2286));
    const int tNameLen = int(qstrlen(tName));
    const int uNameLen = int(qstrlen(uName));
    QByteArray typeName;
    typeName.reserve(int(sizeof("std::map")) + 1 + tNameLen + 1 + uNameLen + 1 +
                     1);
    typeName.append("std::map", int(sizeof("std::map")) - 1)
        .append('<')
        .append(tName, tNameLen)
        .append(',')
        .append(uName, uNameLen);
    if (typeName.endsWith('>'))
      typeName.append(' ');
    typeName.append('>');
    const int newId = qRegisterNormalizedMetaType<std::map<T, U>>(
        typeName, reinterpret_cast<std::map<T, U> *>(quintptr(-1)));
    metatype_id.storeRelease(newId);
    return newId;
  }
};

template <typename T, typename U> struct QMetaTypeId<QPair<T, U>> {
  enum { Defined = QMetaTypeId2<T>::Defined && QMetaTypeId2<U>::Defined };
  static int qt_metatype_id() {
    static QBasicAtomicInt metatype_id = {0};
    if (const int id = metatype_id.loadAcquire())
      return id;
    const char *tName = QMetaType::typeName(qMetaTypeId<T>());
    const char *uName = QMetaType::typeName(qMetaTypeId<U>());
    ((tName)
         ? static_cast<void>(0)
         : qt_assert("tName", "/usr/local/include/QtCore/qmetatype.h", 2288));
    ((uName)
         ? static_cast<void>(0)
         : qt_assert("uName", "/usr/local/include/QtCore/qmetatype.h", 2288));
    const int tNameLen = int(qstrlen(tName));
    const int uNameLen = int(qstrlen(uName));
    QByteArray typeName;
    typeName.reserve(int(sizeof("QPair")) + 1 + tNameLen + 1 + uNameLen + 1 +
                     1);
    typeName.append("QPair", int(sizeof("QPair")) - 1)
        .append('<')
        .append(tName, tNameLen)
        .append(',')
        .append(uName, uNameLen);
    if (typeName.endsWith('>'))
      typeName.append(' ');
    typeName.append('>');
    const int newId = qRegisterNormalizedMetaType<QPair<T, U>>(
        typeName, reinterpret_cast<QPair<T, U> *>(quintptr(-1)));
    metatype_id.storeRelease(newId);
    return newId;
  }
};
template <typename T, typename U> struct QMetaTypeId<std::pair<T, U>> {
  enum { Defined = QMetaTypeId2<T>::Defined && QMetaTypeId2<U>::Defined };
  static int qt_metatype_id() {
    static QBasicAtomicInt metatype_id = {0};
    if (const int id = metatype_id.loadAcquire())
      return id;
    const char *tName = QMetaType::typeName(qMetaTypeId<T>());
    const char *uName = QMetaType::typeName(qMetaTypeId<U>());
    ((tName)
         ? static_cast<void>(0)
         : qt_assert("tName", "/usr/local/include/QtCore/qmetatype.h", 2289));
    ((uName)
         ? static_cast<void>(0)
         : qt_assert("uName", "/usr/local/include/QtCore/qmetatype.h", 2289));
    const int tNameLen = int(qstrlen(tName));
    const int uNameLen = int(qstrlen(uName));
    QByteArray typeName;
    typeName.reserve(int(sizeof("std::pair")) + 1 + tNameLen + 1 + uNameLen +
                     1 + 1);
    typeName.append("std::pair", int(sizeof("std::pair")) - 1)
        .append('<')
        .append(tName, tNameLen)
        .append(',')
        .append(uName, uNameLen);
    if (typeName.endsWith('>'))
      typeName.append(' ');
    typeName.append('>');
    const int newId = qRegisterNormalizedMetaType<std::pair<T, U>>(
        typeName, reinterpret_cast<std::pair<T, U> *>(quintptr(-1)));
    metatype_id.storeRelease(newId);
    return newId;
  }
};

namespace QtPrivate {
template <typename T>
struct SharedPointerMetaTypeIdHelper<QSharedPointer<T>, true> {
  enum { Defined = 1 };
  static int qt_metatype_id() {
    static QBasicAtomicInt metatype_id = {0};
    if (const int id = metatype_id.loadAcquire())
      return id;
    const char *const cName = T::staticMetaObject.className();
    QByteArray typeName;
    typeName.reserve(int(sizeof("QSharedPointer") + 1 + strlen(cName) + 1));
    typeName.append("QSharedPointer", int(sizeof("QSharedPointer")) - 1)
        .append('<')
        .append(cName)
        .append('>');
    const int newId = qRegisterNormalizedMetaType<QSharedPointer<T>>(
        typeName, reinterpret_cast<QSharedPointer<T> *>(quintptr(-1)));
    metatype_id.storeRelease(newId);
    return newId;
  }
};

template <typename T>
struct MetaTypeSmartPointerHelper<
    QSharedPointer<T>,
    typename std::enable_if<
        IsPointerToTypeDerivedFromQObject<T *>::Value>::type> {
  static bool registerConverter(int id) {
    const int toId = QMetaType::QObjectStar;
    if (!QMetaType::hasRegisteredConverterFunction(id, toId)) {
      QtPrivate::QSmartPointerConvertFunctor<QSharedPointer<T>> o;
      static const QtPrivate::ConverterFunctor<
          QSharedPointer<T>, QObject *,
          QSmartPointerConvertFunctor<QSharedPointer<T>>>
          f(o);
      return QMetaType::registerConverterFunction(&f, id, toId);
    }
    return true;
  }
};
} // namespace QtPrivate

template <typename T>
struct QMetaTypeId<QSharedPointer<T>>
    : QtPrivate::SharedPointerMetaTypeIdHelper<
          QSharedPointer<T>,
          QtPrivate::IsPointerToTypeDerivedFromQObject<T *>::Value> {};

namespace QtPrivate {

template <typename T>
struct SharedPointerMetaTypeIdHelper<QWeakPointer<T>, true> {
  enum { Defined = 1 };
  static int qt_metatype_id() {
    static QBasicAtomicInt metatype_id = {0};
    if (const int id = metatype_id.loadAcquire())
      return id;
    const char *const cName = T::staticMetaObject.className();
    QByteArray typeName;
    typeName.reserve(int(sizeof("QWeakPointer") + 1 + strlen(cName) + 1));
    typeName.append("QWeakPointer", int(sizeof("QWeakPointer")) - 1)
        .append('<')
        .append(cName)
        .append('>');
    const int newId = qRegisterNormalizedMetaType<QWeakPointer<T>>(
        typeName, reinterpret_cast<QWeakPointer<T> *>(quintptr(-1)));
    metatype_id.storeRelease(newId);
    return newId;
  }
};

template <typename T>
struct MetaTypeSmartPointerHelper<
    QWeakPointer<T>, typename std::enable_if<
                         IsPointerToTypeDerivedFromQObject<T *>::Value>::type> {
  static bool registerConverter(int id) {
    const int toId = QMetaType::QObjectStar;
    if (!QMetaType::hasRegisteredConverterFunction(id, toId)) {
      QtPrivate::QSmartPointerConvertFunctor<QWeakPointer<T>> o;
      static const QtPrivate::ConverterFunctor<
          QWeakPointer<T>, QObject *,
          QSmartPointerConvertFunctor<QWeakPointer<T>>>
          f(o);
      return QMetaType::registerConverterFunction(&f, id, toId);
    }
    return true;
  }
};
} // namespace QtPrivate

template <typename T>
struct QMetaTypeId<QWeakPointer<T>>
    : QtPrivate::SharedPointerMetaTypeIdHelper<
          QWeakPointer<T>,
          QtPrivate::IsPointerToTypeDerivedFromQObject<T *>::Value> {};

namespace QtPrivate {

template <typename T> struct SharedPointerMetaTypeIdHelper<QPointer<T>, true> {
  enum { Defined = 1 };

  static int qt_metatype_id() {
    static QBasicAtomicInt metatype_id = {0};
    if (const int id = metatype_id.loadAcquire())
      return id;
    const char *const cName = T::staticMetaObject.className();
    QByteArray typeName;
    typeName.reserve(int(sizeof("QPointer") + 1 + strlen(cName) + 1));
    typeName.append("QPointer", int(sizeof("QPointer")) - 1)
        .append('<')
        .append(cName)
        .append('>');
    const int newId = qRegisterNormalizedMetaType<QPointer<T>>(
        typeName, reinterpret_cast<QPointer<T> *>(quintptr(-1)));
    metatype_id.storeRelease(newId);
    return newId;
  }
};

template <typename T>
struct MetaTypeSmartPointerHelper<
    QPointer<T>, typename std::enable_if<
                     IsPointerToTypeDerivedFromQObject<T *>::Value>::type> {
  static bool registerConverter(int id) {
    const int toId = QMetaType::QObjectStar;
    if (!QMetaType::hasRegisteredConverterFunction(id, toId)) {
      QtPrivate::QSmartPointerConvertFunctor<QPointer<T>> o;
      static const QtPrivate::ConverterFunctor<
          QPointer<T>, QObject *, QSmartPointerConvertFunctor<QPointer<T>>>
          f(o);
      return QMetaType::registerConverterFunction(&f, id, toId);
    }
    return true;
  }
};
} // namespace QtPrivate

template <typename T>
struct QMetaTypeId<QPointer<T>>
    : QtPrivate::SharedPointerMetaTypeIdHelper<
          QPointer<T>,
          QtPrivate::IsPointerToTypeDerivedFromQObject<T *>::Value> {};

inline QMetaType::QMetaType(const ExtensionFlag extensionFlags,
                            const QMetaTypeInterface *info,
                            TypedConstructor creator, TypedDestructor deleter,
                            SaveOperator saveOp, LoadOperator loadOp,
                            Constructor constructor, Destructor destructor,
                            uint size, uint theTypeFlags, int typeId,
                            const QMetaObject *_metaObject)
    : m_typedConstructor(creator), m_typedDestructor(deleter), m_saveOp(saveOp),
      m_loadOp(loadOp), m_constructor(constructor), m_destructor(destructor),
      m_extension(nullptr), m_size(size), m_typeFlags(theTypeFlags),
      m_extensionFlags(extensionFlags), m_typeId(typeId),
      m_metaObject(_metaObject) {
  if (__builtin_expect(!!(isExtended(CtorEx) || typeId == QMetaType::Void),
                       false))
    ctor(info);
}

inline QMetaType::~QMetaType() {
  if (__builtin_expect(!!(isExtended(DtorEx)), false))
    dtor();
}

inline bool QMetaType::isValid() const { return m_typeId != UnknownType; }

inline bool QMetaType::isRegistered() const { return isValid(); }

inline int QMetaType::id() const { return m_typeId; }

inline void *QMetaType::create(const void *copy) const {

  return createExtended(copy);
}

inline void QMetaType::destroy(void *data) const { destroyExtended(data); }

inline void *QMetaType::construct(void *where, const void *copy) const {
  if (__builtin_expect(!!(isExtended(ConstructEx)), false))
    return constructExtended(where, copy);
  return m_constructor(where, copy);
}

inline void QMetaType::destruct(void *data) const {
  if (__builtin_expect(!!(isExtended(DestructEx)), false))
    return destructExtended(data);
  if (__builtin_expect(!!(!data), false))
    return;
  m_destructor(data);
}

inline int QMetaType::sizeOf() const {
  if (__builtin_expect(!!(isExtended(SizeEx)), false))
    return sizeExtended();
  return m_size;
}

inline QMetaType::TypeFlags QMetaType::flags() const {
  if (__builtin_expect(!!(isExtended(FlagsEx)), false))
    return flagsExtended();
  return QMetaType::TypeFlags(m_typeFlags);
}

inline const QMetaObject *QMetaType::metaObject() const {
  if (__builtin_expect(!!(isExtended(MetaObjectEx)), false))
    return metaObjectExtended();
  return m_metaObject;
}

template <> struct QMetaTypeId2<void> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 43 };
  static inline constexpr int qt_metatype_id() { return 43; }
};
template <> struct QMetaTypeId2<bool> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 1 };
  static inline constexpr int qt_metatype_id() { return 1; }
};
template <> struct QMetaTypeId2<int> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 2 };
  static inline constexpr int qt_metatype_id() { return 2; }
};
template <> struct QMetaTypeId2<uint> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 3 };
  static inline constexpr int qt_metatype_id() { return 3; }
};
template <> struct QMetaTypeId2<qlonglong> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 4 };
  static inline constexpr int qt_metatype_id() { return 4; }
};
template <> struct QMetaTypeId2<qulonglong> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 5 };
  static inline constexpr int qt_metatype_id() { return 5; }
};
template <> struct QMetaTypeId2<double> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 6 };
  static inline constexpr int qt_metatype_id() { return 6; }
};
template <> struct QMetaTypeId2<long> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 32 };
  static inline constexpr int qt_metatype_id() { return 32; }
};
template <> struct QMetaTypeId2<short> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 33 };
  static inline constexpr int qt_metatype_id() { return 33; }
};
template <> struct QMetaTypeId2<char> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 34 };
  static inline constexpr int qt_metatype_id() { return 34; }
};
template <> struct QMetaTypeId2<ulong> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 35 };
  static inline constexpr int qt_metatype_id() { return 35; }
};
template <> struct QMetaTypeId2<ushort> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 36 };
  static inline constexpr int qt_metatype_id() { return 36; }
};
template <> struct QMetaTypeId2<uchar> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 37 };
  static inline constexpr int qt_metatype_id() { return 37; }
};
template <> struct QMetaTypeId2<float> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 38 };
  static inline constexpr int qt_metatype_id() { return 38; }
};
template <> struct QMetaTypeId2<signed char> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 40 };
  static inline constexpr int qt_metatype_id() { return 40; }
};
template <> struct QMetaTypeId2<std::nullptr_t> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 51 };
  static inline constexpr int qt_metatype_id() { return 51; }
};
template <> struct QMetaTypeId2<QCborSimpleType> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 52 };
  static inline constexpr int qt_metatype_id() { return 52; }
};
template <> struct QMetaTypeId2<void *> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 31 };
  static inline constexpr int qt_metatype_id() { return 31; }
};
template <> struct QMetaTypeId2<QChar> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 7 };
  static inline constexpr int qt_metatype_id() { return 7; }
};
template <> struct QMetaTypeId2<QString> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 10 };
  static inline constexpr int qt_metatype_id() { return 10; }
};
template <> struct QMetaTypeId2<QStringList> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 11 };
  static inline constexpr int qt_metatype_id() { return 11; }
};
template <> struct QMetaTypeId2<QByteArray> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 12 };
  static inline constexpr int qt_metatype_id() { return 12; }
};
template <> struct QMetaTypeId2<QBitArray> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 13 };
  static inline constexpr int qt_metatype_id() { return 13; }
};
template <> struct QMetaTypeId2<QDate> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 14 };
  static inline constexpr int qt_metatype_id() { return 14; }
};
template <> struct QMetaTypeId2<QTime> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 15 };
  static inline constexpr int qt_metatype_id() { return 15; }
};
template <> struct QMetaTypeId2<QDateTime> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 16 };
  static inline constexpr int qt_metatype_id() { return 16; }
};
template <> struct QMetaTypeId2<QUrl> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 17 };
  static inline constexpr int qt_metatype_id() { return 17; }
};
template <> struct QMetaTypeId2<QLocale> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 18 };
  static inline constexpr int qt_metatype_id() { return 18; }
};
template <> struct QMetaTypeId2<QRect> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 19 };
  static inline constexpr int qt_metatype_id() { return 19; }
};
template <> struct QMetaTypeId2<QRectF> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 20 };
  static inline constexpr int qt_metatype_id() { return 20; }
};
template <> struct QMetaTypeId2<QSize> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 21 };
  static inline constexpr int qt_metatype_id() { return 21; }
};
template <> struct QMetaTypeId2<QSizeF> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 22 };
  static inline constexpr int qt_metatype_id() { return 22; }
};
template <> struct QMetaTypeId2<QLine> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 23 };
  static inline constexpr int qt_metatype_id() { return 23; }
};
template <> struct QMetaTypeId2<QLineF> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 24 };
  static inline constexpr int qt_metatype_id() { return 24; }
};
template <> struct QMetaTypeId2<QPoint> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 25 };
  static inline constexpr int qt_metatype_id() { return 25; }
};
template <> struct QMetaTypeId2<QPointF> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 26 };
  static inline constexpr int qt_metatype_id() { return 26; }
};
template <> struct QMetaTypeId2<QRegExp> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 27 };
  static inline constexpr int qt_metatype_id() { return 27; }
};
template <> struct QMetaTypeId2<QEasingCurve> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 29 };
  static inline constexpr int qt_metatype_id() { return 29; }
};
template <> struct QMetaTypeId2<QUuid> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 30 };
  static inline constexpr int qt_metatype_id() { return 30; }
};
template <> struct QMetaTypeId2<QVariant> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 41 };
  static inline constexpr int qt_metatype_id() { return 41; }
};
template <> struct QMetaTypeId2<QRegularExpression> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 44 };
  static inline constexpr int qt_metatype_id() { return 44; }
};
template <> struct QMetaTypeId2<QJsonValue> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 45 };
  static inline constexpr int qt_metatype_id() { return 45; }
};
template <> struct QMetaTypeId2<QJsonObject> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 46 };
  static inline constexpr int qt_metatype_id() { return 46; }
};
template <> struct QMetaTypeId2<QJsonArray> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 47 };
  static inline constexpr int qt_metatype_id() { return 47; }
};
template <> struct QMetaTypeId2<QJsonDocument> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 48 };
  static inline constexpr int qt_metatype_id() { return 48; }
};
template <> struct QMetaTypeId2<QCborValue> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 53 };
  static inline constexpr int qt_metatype_id() { return 53; }
};
template <> struct QMetaTypeId2<QCborArray> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 54 };
  static inline constexpr int qt_metatype_id() { return 54; }
};
template <> struct QMetaTypeId2<QCborMap> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 55 };
  static inline constexpr int qt_metatype_id() { return 55; }
};
template <> struct QMetaTypeId2<QModelIndex> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 42 };
  static inline constexpr int qt_metatype_id() { return 42; }
};
template <> struct QMetaTypeId2<QPersistentModelIndex> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 50 };
  static inline constexpr int qt_metatype_id() { return 50; }
};
template <> struct QMetaTypeId2<QObject *> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 39 };
  static inline constexpr int qt_metatype_id() { return 39; }
};
template <> struct QMetaTypeId2<QVariantMap> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 8 };
  static inline constexpr int qt_metatype_id() { return 8; }
};
template <> struct QMetaTypeId2<QVariantList> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 9 };
  static inline constexpr int qt_metatype_id() { return 9; }
};
template <> struct QMetaTypeId2<QVariantHash> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 28 };
  static inline constexpr int qt_metatype_id() { return 28; }
};
template <> struct QMetaTypeId2<QByteArrayList> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 49 };
  static inline constexpr int qt_metatype_id() { return 49; }
};
template <> struct QMetaTypeId2<QFont> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 64 };
  static inline constexpr int qt_metatype_id() { return 64; }
};
template <> struct QMetaTypeId2<QPixmap> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 65 };
  static inline constexpr int qt_metatype_id() { return 65; }
};
template <> struct QMetaTypeId2<QBrush> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 66 };
  static inline constexpr int qt_metatype_id() { return 66; }
};
template <> struct QMetaTypeId2<QColor> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 67 };
  static inline constexpr int qt_metatype_id() { return 67; }
};
template <> struct QMetaTypeId2<QPalette> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 68 };
  static inline constexpr int qt_metatype_id() { return 68; }
};
template <> struct QMetaTypeId2<QIcon> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 69 };
  static inline constexpr int qt_metatype_id() { return 69; }
};
template <> struct QMetaTypeId2<QImage> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 70 };
  static inline constexpr int qt_metatype_id() { return 70; }
};
template <> struct QMetaTypeId2<QPolygon> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 71 };
  static inline constexpr int qt_metatype_id() { return 71; }
};
template <> struct QMetaTypeId2<QRegion> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 72 };
  static inline constexpr int qt_metatype_id() { return 72; }
};
template <> struct QMetaTypeId2<QBitmap> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 73 };
  static inline constexpr int qt_metatype_id() { return 73; }
};
template <> struct QMetaTypeId2<QCursor> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 74 };
  static inline constexpr int qt_metatype_id() { return 74; }
};
template <> struct QMetaTypeId2<QKeySequence> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 75 };
  static inline constexpr int qt_metatype_id() { return 75; }
};
template <> struct QMetaTypeId2<QPen> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 76 };
  static inline constexpr int qt_metatype_id() { return 76; }
};
template <> struct QMetaTypeId2<QTextLength> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 77 };
  static inline constexpr int qt_metatype_id() { return 77; }
};
template <> struct QMetaTypeId2<QTextFormat> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 78 };
  static inline constexpr int qt_metatype_id() { return 78; }
};
template <> struct QMetaTypeId2<QMatrix> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 79 };
  static inline constexpr int qt_metatype_id() { return 79; }
};
template <> struct QMetaTypeId2<QTransform> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 80 };
  static inline constexpr int qt_metatype_id() { return 80; }
};
template <> struct QMetaTypeId2<QMatrix4x4> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 81 };
  static inline constexpr int qt_metatype_id() { return 81; }
};
template <> struct QMetaTypeId2<QVector2D> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 82 };
  static inline constexpr int qt_metatype_id() { return 82; }
};
template <> struct QMetaTypeId2<QVector3D> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 83 };
  static inline constexpr int qt_metatype_id() { return 83; }
};
template <> struct QMetaTypeId2<QVector4D> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 84 };
  static inline constexpr int qt_metatype_id() { return 84; }
};
template <> struct QMetaTypeId2<QQuaternion> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 85 };
  static inline constexpr int qt_metatype_id() { return 85; }
};
template <> struct QMetaTypeId2<QPolygonF> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 86 };
  static inline constexpr int qt_metatype_id() { return 86; }
};
template <> struct QMetaTypeId2<QColorSpace> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 87 };
  static inline constexpr int qt_metatype_id() { return 87; }
};
template <> struct QMetaTypeId2<QSizePolicy> {
  enum { Defined = 1, IsBuiltIn = true, MetaType = 121 };
  static inline constexpr int qt_metatype_id() { return 121; }
};

template <> struct QMetaTypeId<QtMetaTypePrivate::QSequentialIterableImpl> {
  enum { Defined = 1 };
  static int qt_metatype_id() {
    static QBasicAtomicInt metatype_id = {0};
    if (const int id = metatype_id.loadAcquire())
      return id;
    const int newId =
        qRegisterMetaType<QtMetaTypePrivate::QSequentialIterableImpl>(
            "QtMetaTypePrivate::QSequentialIterableImpl",
            reinterpret_cast<QtMetaTypePrivate::QSequentialIterableImpl *>(
                quintptr(-1)));
    metatype_id.storeRelease(newId);
    return newId;
  }
};
template <> struct QMetaTypeId<QtMetaTypePrivate::QAssociativeIterableImpl> {
  enum { Defined = 1 };
  static int qt_metatype_id() {
    static QBasicAtomicInt metatype_id = {0};
    if (const int id = metatype_id.loadAcquire())
      return id;
    const int newId =
        qRegisterMetaType<QtMetaTypePrivate::QAssociativeIterableImpl>(
            "QtMetaTypePrivate::QAssociativeIterableImpl",
            reinterpret_cast<QtMetaTypePrivate::QAssociativeIterableImpl *>(
                quintptr(-1)));
    metatype_id.storeRelease(newId);
    return newId;
  }
};
template <> struct QMetaTypeId<QtMetaTypePrivate::QPairVariantInterfaceImpl> {
  enum { Defined = 1 };
  static int qt_metatype_id() {
    static QBasicAtomicInt metatype_id = {0};
    if (const int id = metatype_id.loadAcquire())
      return id;
    const int newId =
        qRegisterMetaType<QtMetaTypePrivate::QPairVariantInterfaceImpl>(
            "QtMetaTypePrivate::QPairVariantInterfaceImpl",
            reinterpret_cast<QtMetaTypePrivate::QPairVariantInterfaceImpl *>(
                quintptr(-1)));
    metatype_id.storeRelease(newId);
    return newId;
  }
};

template <typename T>
inline bool QtPrivate::IsMetaTypePair<T, true>::registerConverter(int id) {
  const int toId = qMetaTypeId<QtMetaTypePrivate::QPairVariantInterfaceImpl>();
  if (!QMetaType::hasRegisteredConverterFunction(id, toId)) {
    QtMetaTypePrivate::QPairVariantInterfaceConvertFunctor<T> o;
    static const QtPrivate::ConverterFunctor<
        T, QtMetaTypePrivate::QPairVariantInterfaceImpl,
        QtMetaTypePrivate::QPairVariantInterfaceConvertFunctor<T>>
        f(o);
    return QMetaType::registerConverterFunction(&f, id, toId);
  }
  return true;
}

namespace QtPrivate {
template <typename T> struct ValueTypeIsMetaType<T, true> {
  static bool registerConverter(int id) {
    const int toId = qMetaTypeId<QtMetaTypePrivate::QSequentialIterableImpl>();
    if (!QMetaType::hasRegisteredConverterFunction(id, toId)) {
      QtMetaTypePrivate::QSequentialIterableConvertFunctor<T> o;
      static const QtPrivate::ConverterFunctor<
          T, QtMetaTypePrivate::QSequentialIterableImpl,
          QtMetaTypePrivate::QSequentialIterableConvertFunctor<T>>
          f(o);
      return QMetaType::registerConverterFunction(&f, id, toId);
    }
    return true;
  }
};

template <typename T> struct AssociativeValueTypeIsMetaType<T, true> {
  static bool registerConverter(int id) {
    const int toId = qMetaTypeId<QtMetaTypePrivate::QAssociativeIterableImpl>();
    if (!QMetaType::hasRegisteredConverterFunction(id, toId)) {
      QtMetaTypePrivate::QAssociativeIterableConvertFunctor<T> o;
      static const QtPrivate::ConverterFunctor<
          T, QtMetaTypePrivate::QAssociativeIterableImpl,
          QtMetaTypePrivate::QAssociativeIterableConvertFunctor<T>>
          f(o);
      return QMetaType::registerConverterFunction(&f, id, toId);
    }
    return true;
  }
};
} // namespace QtPrivate

namespace w_internal {
using std::index_sequence;
using std::make_index_sequence;

struct IndexBase {};
template <size_t> struct Index : IndexBase {};
template <size_t I> constexpr auto index = Index<I>{};

template <typename... Args> constexpr void ordered(Args...) {}
template <class T> constexpr void ordered2(std::initializer_list<T>) {}

template <typename... Args> constexpr int sums(Args... args) {

  auto r = int{};
  ordered2<int>({(r += args)...});
  return r;
}

template <int... args> constexpr int summed = sums(args...);

struct StringView {
  const char *b{};
  const char *e{};

  constexpr auto size() const -> qptrdiff { return e - b; }
  constexpr auto begin() const { return b; }
  constexpr auto end() const { return e; }
};

template <size_t N>
constexpr auto viewLiteral(const char (&d)[N]) -> StringView {
  return {&d[0], &d[N - 1]};
}

template <size_t N = 0> struct StringViewArray {
  StringView data[(N > 0 ? N : 1)]{};

  constexpr auto operator[](size_t i) const { return data[i]; }
};

template <size_t SN> constexpr auto countParsedLiterals(const char (&s)[SN]) {
  auto r = size_t{};
  auto i = 0u;
  while (true) {
    while (true) {
      if (i >= SN - 1)
        return r;
      if (s[i] != ' ' && s[i] != ',')
        break;
      i++;
    }
    r++;
    i++;
    while (true) {
      if (i >= SN - 1)
        return r;
      if (s[i] == ',')
        break;
      i++;
    }
    i++;
  }
}

template <size_t N, size_t SN>
constexpr auto viewParsedLiterals(const char (&s)[SN]) -> StringViewArray<N> {

  auto r = StringViewArray<N>{};
  auto ri = size_t{};
  auto i = 0u;
  while (true) {
    while (true) {
      if (i >= SN - 1)
        return r;
      if (s[i] != ' ' && s[i] != ',')
        break;
      i++;
    }
    r.data[ri].b = &s[i];
    i++;
    while (true) {
      if (i >= SN - 1) {
        r.data[ri].e = &s[i];
        return r;
      }
      if (s[i] == ' ') {
        if (i + 1 >= SN - 1) {
          r.data[ri].e = &s[i];
          return r;
        }
        if (s[i + 1] == ',') {
          r.data[ri].e = &s[i];
          i += 2;
          break;
        }
        i += 2;
        continue;
      }
      if (s[i] == ',') {
        r.data[ri].e = &s[i];
        i++;
        break;
      }
      i++;
    }
    ri++;
  }
}

template <size_t N, size_t SN>
constexpr auto viewScopedLiterals(const char (&s)[SN]) -> StringViewArray<N> {
  auto r = StringViewArray<N>{};
  auto ri = size_t{};
  auto i = 0u;
  while (true) {
    while (true) {
      if (i >= SN - 1)
        return r;
      if (s[i] != ' ' && s[i] != ',' && s[i] != ':')
        break;
      i++;
    }
    r.data[ri].b = &s[i];
    i++;
    while (true) {
      if (i >= SN - 1) {
        r.data[ri].e = &s[i];
        return r;
      }
      if (s[i] == ':') {
        i++;
        if (s[i] == ' ')
          i++;
        r.data[ri].b = &s[i];
        continue;
      }
      if (s[i] == ' ') {
        if (i + 1 >= SN - 1) {
          r.data[ri].e = &s[i];
          return r;
        }
        if (s[i + 1] == ',') {
          r.data[ri].e = &s[i];
          i += 2;
          break;
        }
        i += 2;
        continue;
      }
      if (s[i] == ',') {
        r.data[ri].e = &s[i];
        i++;
        break;
      }
      i++;
    }
    ri++;
  }
}

enum class PropertyFlags {
  Invalid = 0x00000000,
  Readable = 0x00000001,
  Writable = 0x00000002,
  Resettable = 0x00000004,
  EnumOrFlag = 0x00000008,
  StdCppSet = 0x00000100,

  Constant = 0x00000400,
  Final = 0x00000800,
  Designable = 0x00001000,
  ResolveDesignable = 0x00002000,
  Scriptable = 0x00004000,
  ResolveScriptable = 0x00008000,
  Stored = 0x00010000,
  ResolveStored = 0x00020000,
  Editable = 0x00040000,
  ResolveEditable = 0x00080000,
  User = 0x00100000,
  ResolveUser = 0x00200000,
  Notify = 0x00400000,
  Revisioned = 0x00800000
};
constexpr uint operator|(uint a, PropertyFlags b) { return a | uint(b); }

template <int N> struct W_MethodFlags { static constexpr int value = N; };
constexpr W_MethodFlags<0> W_EmptyFlag{};

} // namespace w_internal

namespace W_Access {

constexpr w_internal::W_MethodFlags<0x1000> Private{};
constexpr w_internal::W_MethodFlags<0x01> Protected{};
constexpr w_internal::W_MethodFlags<0x02> Public{};
} // namespace W_Access

namespace W_MethodType {

constexpr w_internal::W_MethodFlags<0x00> Method{};
constexpr w_internal::W_MethodFlags<0x04> Signal{};
constexpr w_internal::W_MethodFlags<0x08> Slot{};
constexpr w_internal::W_MethodFlags<0x0c> Constructor{};
} // namespace W_MethodType

constexpr w_internal::W_MethodFlags<0x10> W_Compat{};
constexpr w_internal::W_MethodFlags<0x40> W_Scriptable{};
constexpr struct {
} W_Notify{};
constexpr struct {
} W_Reset{};
constexpr std::integral_constant<int, int(w_internal::PropertyFlags::Constant)>
    W_Constant{};
constexpr std::integral_constant<int, int(w_internal::PropertyFlags::Final)>
    W_Final{};

namespace w_internal {

template <typename F, int Flags, typename IC, typename ParamTypes,
          typename ParamNames = StringViewArray<>>
struct MetaMethodInfo {
  F func;
  StringView name;
  ParamTypes paramTypes;
  ParamNames paramNames;
  static constexpr int argCount = QtPrivate::FunctionPointer<F>::ArgumentCount;
  static constexpr auto argSequence = make_index_sequence<argCount>{};
  static constexpr int flags = Flags;
  using IntegralConstant = IC;
};

template <typename F, typename ParamTypes, int... Flags,
          typename IntegralConstant>
constexpr MetaMethodInfo<F, summed<Flags...> | W_MethodType::Slot.value,
                         IntegralConstant, ParamTypes>
makeMetaSlotInfo(F f, StringView name, IntegralConstant,
                 const ParamTypes &paramTypes, W_MethodFlags<Flags>...) {
  return {f, name, paramTypes, {}};
}

template <typename F, typename ParamTypes, int... Flags,
          typename IntegralConstant>
constexpr MetaMethodInfo<F, summed<Flags...> | W_MethodType::Method.value,
                         IntegralConstant, ParamTypes>
makeMetaMethodInfo(F f, StringView name, IntegralConstant,
                   const ParamTypes &paramTypes, W_MethodFlags<Flags>...) {
  return {f, name, paramTypes, {}};
}

template <typename F, typename ParamTypes, typename ParamNames, int... Flags,
          typename IntegralConstant>
constexpr MetaMethodInfo<F, summed<Flags...> | W_MethodType::Signal.value,
                         IntegralConstant, ParamTypes, ParamNames>
makeMetaSignalInfo(F f, StringView name, IntegralConstant,
                   const ParamTypes &paramTypes, const ParamNames &paramNames,
                   W_MethodFlags<Flags>...) {
  return {f, name, paramTypes, paramNames};
}

template <typename... Args> struct MetaConstructorInfo {
  static constexpr std::size_t argCount = sizeof...(Args);
  static constexpr auto argSequence = make_index_sequence<argCount>{};
  static constexpr int flags =
      W_MethodType::Constructor.value | W_Access::Public.value;
  using IntegralConstant = void *;
  StringView name;
};

template <typename... Args>
constexpr MetaConstructorInfo<Args...>
makeMetaConstructorInfo(StringView name) {
  return {name};
}

struct Empty {
  constexpr operator bool() const { return false; }
};

template <typename Type, typename Getter = Empty, typename Setter = Empty,
          typename Member = Empty, typename Notify = Empty,
          typename Reset = Empty, int Flags = 0>
struct MetaPropertyInfo {
  using PropertyType = Type;
  StringView name;
  StringView typeStr;
  Getter getter;
  Setter setter;
  Member member;
  Notify notify;
  Reset reset;
  static constexpr uint flags = Flags;

  template <typename S> constexpr auto setGetter(const S &s) const {
    return MetaPropertyInfo<Type, S, Setter, Member, Notify, Reset,
                            Flags | PropertyFlags::Readable>{
        name, typeStr, s, setter, member, notify, reset};
  }
  template <typename S> constexpr auto setSetter(const S &s) const {
    return MetaPropertyInfo<Type, Getter, S, Member, Notify, Reset,
                            Flags | PropertyFlags::Writable>{
        name, typeStr, getter, s, member, notify, reset};
  }
  template <typename S> constexpr auto setMember(const S &s) const {
    return MetaPropertyInfo<Type, Getter, Setter, S, Notify, Reset,
                            Flags | PropertyFlags::Writable |
                                PropertyFlags::Readable>{
        name, typeStr, getter, setter, s, notify, reset};
  }
  template <typename S> constexpr auto setNotify(const S &s) const {
    return MetaPropertyInfo<Type, Getter, Setter, Member, S, Reset,
                            Flags | PropertyFlags::Notify>{
        name, typeStr, getter, setter, member, s, reset};
  }
  template <typename S> constexpr auto setReset(const S &s) const {
    return MetaPropertyInfo<Type, Getter, Setter, Member, Notify, S,
                            Flags | PropertyFlags::Resettable>{
        name, typeStr, getter, setter, member, notify, s};
  }
  template <int Flag> constexpr auto addFlag() const {
    return MetaPropertyInfo<Type, Getter, Setter, Member, Notify, Reset,
                            Flags | Flag>{name,   typeStr, getter, setter,
                                          member, notify,  reset};
  }
};

template <typename PropInfo> constexpr auto parseProperty(const PropInfo &p) {
  return p;
}

template <typename PropInfo, typename Obj, typename Arg, typename Ret,
          typename... Tail>
constexpr auto parseProperty(const PropInfo &p, Ret (Obj::*s)(Arg), Tail... t) {
  return parseProperty(p.setSetter(s), t...);
}

template <typename PropInfo, typename Obj, typename Ret, typename... Tail>
constexpr auto parseProperty(const PropInfo &p, Ret (Obj::*s)(), Tail... t) {
  return parseProperty(p.setGetter(s), t...);
}
template <typename PropInfo, typename Obj, typename Ret, typename... Tail>
constexpr auto parseProperty(const PropInfo &p, Ret (Obj::*s)() const,
                             Tail... t) {
  return parseProperty(p.setGetter(s), t...);
}
template <typename PropInfo, typename Obj, typename Ret, typename... Tail>
constexpr auto parseProperty(const PropInfo &p, Ret Obj::*s, Tail... t) {
  return parseProperty(p.setMember(s), t...);
}

template <typename PropInfo, typename F, typename... Tail>
constexpr auto parseProperty(const PropInfo &p, decltype(W_Notify), F f,
                             Tail... t) {
  return parseProperty(p.setNotify(f), t...);
}

template <typename PropInfo, typename Obj, typename Ret, typename... Tail>
constexpr auto parseProperty(const PropInfo &p, decltype(W_Reset),
                             Ret (Obj::*s)(), Tail... t) {
  return parseProperty(p.setReset(s), t...);
}

template <typename PropInfo, int Flag, typename... Tail>
constexpr auto parseProperty(const PropInfo &p,
                             std::integral_constant<int, Flag>, Tail... t) {
  return parseProperty(p.template addFlag<Flag>(), t...);
}

template <typename T, typename... Args>
constexpr auto makeMetaPropertyInfo(StringView name, StringView type,
                                    Args... args) {
  auto meta = MetaPropertyInfo<T>{name, type, {}, {}, {}, {}, {}};
  return parseProperty(meta, args...);
}

template <typename T, typename = void> struct EnumIsScoped {
  enum { Value = std::is_convertible<T, int>::value ? 0 : 2 };
};
template <typename T>
struct EnumIsScoped<QFlags<T>, void>
    : EnumIsScoped<typename QFlags<T>::enum_type> {};

template <typename T> struct QEnumOrQFlags { using Type = T; };
template <typename T> struct QEnumOrQFlags<QFlags<T>> { using Type = T; };

template <bool HasAlias, typename Values_, typename Names, int Flags>
struct MetaEnumInfo {
  StringView name;
  StringView alias;
  Names names;
  using Values = Values_;
  static constexpr uint flags = Flags;
  static constexpr auto count = Values::size();
  static constexpr auto sequence = make_index_sequence<count>{};
  static constexpr auto hasAlias = HasAlias;
};
template <typename Enum, Enum... Value> struct enum_sequence {};

template <typename Enum, int Flag, Enum... Values, typename Names>
constexpr auto makeMetaEnumInfo(StringView name, int,
                                enum_sequence<Enum, Values...>, Names names)
    -> MetaEnumInfo<false, index_sequence<size_t(Values)...>, Names,
                    Flag | EnumIsScoped<Enum>::Value> {
  return {name, viewLiteral(""), names};
}
template <typename Enum, int Flag, Enum... Values, typename Names>
constexpr auto makeMetaEnumInfo(StringView name, StringView alias,
                                enum_sequence<Enum, Values...>, Names names)
    -> MetaEnumInfo<true, index_sequence<size_t(Values)...>, Names,
                    Flag | EnumIsScoped<Enum>::Value> {
  return {name, alias, names};
}

template <int N> constexpr int removedScopeSize(const char (&name)[N]) {

  int p = N - 1;
  while (p > 0 && name[p] != ':')
    p--;
  if (name[p] == ':')
    p++;
  return N - p;
}
template <typename Func, int Idx> struct SignalImplementation {};
template <typename Obj, typename Ret, typename... Args, int Idx>
struct SignalImplementation<Ret (Obj::*)(Args...), Idx> {
  Obj *this_;
  Ret operator()(Args... args, int) const {
    Ret r{};
    const void *a[] = {std::addressof(r), std::addressof(args)...};
    QMetaObject::activate(this_, &Obj::staticMetaObject, Idx,
                          const_cast<void **>(a));
    return r;
  }
};
template <typename Obj, typename... Args, int Idx>
struct SignalImplementation<void (Obj::*)(Args...), Idx> {
  Obj *this_;
  void operator()(Args... args, int) {
    const void *a[] = {nullptr, std::addressof(args)...};
    QMetaObject::activate(this_, &Obj::staticMetaObject, Idx,
                          const_cast<void **>(a));
  }
};
template <typename Obj, typename Ret, typename... Args, int Idx>
struct SignalImplementation<Ret (Obj::*)(Args...) const, Idx> {
  const Obj *this_;
  Ret operator()(Args... args, int) const {
    Ret r{};
    const void *a[] = {std::addressof(r), std::addressof(args)...};
    QMetaObject::activate(const_cast<Obj *>(this_), &Obj::staticMetaObject, Idx,
                          const_cast<void **>(a));
    return r;
  }
};
template <typename Obj, typename... Args, int Idx>
struct SignalImplementation<void (Obj::*)(Args...) const, Idx> {
  const Obj *this_;
  void operator()(Args... args, int) {
    const void *a[] = {nullptr, std::addressof(args)...};
    QMetaObject::activate(const_cast<Obj *>(this_), &Obj::staticMetaObject, Idx,
                          const_cast<void **>(a));
  }
};
template <typename T> T &getParentObjectHelper(void *(T::*)(const char *));

struct FriendHelper;

inline namespace w_ShouldBeInQt {

template <typename... Args> struct QNonConstOverload {
  template <typename R, typename T>
  constexpr auto operator()(R (T::*ptr)(Args...)) const {
    return ptr;
  }
};
template <typename... Args> struct QConstOverload {
  template <typename R, typename T>
  constexpr auto operator()(R (T::*ptr)(Args...) const) const {
    return ptr;
  }
};
template <typename... Args>
struct QOverload : QConstOverload<Args...>, QNonConstOverload<Args...> {
  using QConstOverload<Args...>::operator();
  using QNonConstOverload<Args...>::operator();

  template <typename R> constexpr auto operator()(R (*ptr)(Args...)) const {
    return ptr;
  }
};
template <typename... Args> constexpr QOverload<Args...> qOverload = {};

} // namespace w_ShouldBeInQt

} // namespace w_internal
namespace w_internal {

template <class State, class TPP> void w_state(IndexBase, State, TPP);
template <size_t L, class State, class TPP, size_t N, size_t M,
          size_t X = (N + M) / 2,
          bool noX = std::is_same<void, decltype(w_state(index<X>, State{},
                                                         TPP{}))>::value,
          bool up = N == X>
struct CountBetween;

template <size_t L, class State, class TPP, size_t N, size_t M, size_t X>
struct CountBetween<L, State, TPP, N, M, X, true, true> {
  static constexpr auto value = N;
};
template <size_t L, class State, class TPP, size_t N, size_t M, size_t X>
struct CountBetween<L, State, TPP, N, M, X, false, true> {
  static constexpr auto value = M;
};
template <size_t L, class State, class TPP, size_t N, size_t M, size_t X>
struct CountBetween<L, State, TPP, N, M, X, true, false> {
  static constexpr auto value = CountBetween<L, State, TPP, N, X>::value;
};
template <size_t L, class State, class TPP, size_t N, size_t M, size_t X>
struct CountBetween<L, State, TPP, N, M, X, false, false> {
  static constexpr auto value = CountBetween<L, State, TPP, X, M>::value;
};

template <size_t L, class State, class TPP, size_t N = 1,
          bool noX = std::is_same<void, decltype(w_state(index<N>, State{},
                                                         TPP{}))>::value>
struct Count;

template <size_t L, class State, class TPP, size_t N>
struct Count<L, State, TPP, N, true> {
  static constexpr auto value = CountBetween<L, State, TPP, N / 2, N>::value;
};
template <size_t L, class State, class TPP, size_t N>
struct Count<L, State, TPP, N, false> {
  static constexpr auto value = Count<L, State, TPP, N * 2>::value;
};

template <size_t L, class State, class TPP>
constexpr auto stateCount = Count<L, State, TPP>::value;

struct SlotStateTag {};
struct SignalStateTag {};
struct MethodStateTag {};
struct ConstructorStateTag {};
struct PropertyStateTag {};
struct EnumStateTag {};
struct ClassInfoStateTag {};
struct InterfaceStateTag {};

} // namespace w_internal
namespace w_internal {
template <typename T> struct W_TypeRegistery {
  enum { registered = false };
};
} // namespace w_internal

namespace w_internal {
template <> struct W_TypeRegistery<char *> {
  enum { registered = true };
  static constexpr auto name = viewLiteral("char*");
};
} // namespace w_internal
namespace w_internal {
template <> struct W_TypeRegistery<const char *> {
  enum { registered = true };
  static constexpr auto name = viewLiteral("const char*");
};
} // namespace w_internal
template <typename Key, typename T, class Iterator> class QKeyValueIterator {
public:
  typedef typename Iterator::iterator_category iterator_category;
  typedef typename Iterator::difference_type difference_type;
  typedef std::pair<Key, T> value_type;
  typedef const value_type &reference;

  QKeyValueIterator() = default;
  constexpr explicit QKeyValueIterator(Iterator o) noexcept(
      std::is_nothrow_move_constructible<Iterator>::value)
      : i(std::move(o)) {}

  std::pair<Key, T> operator*() const {
    return std::pair<Key, T>(i.key(), i.value());
  }

  struct pointer {
    pointer(value_type &&r_) : r(std::move(r_)) {}

    pointer() = default;
    pointer(const pointer &other) = default;
    pointer(pointer &&other) = default;
    pointer &operator=(const pointer &other) = default;
    pointer &operator=(pointer &&other) = default;

    value_type &operator*() const { return r; }

    value_type r;
    const value_type *operator->() const { return &r; }
  };

  pointer operator->() const {
    return pointer(std::pair<Key, T>(i.key(), i.value()));
  }

  friend bool operator==(QKeyValueIterator lhs,
                         QKeyValueIterator rhs) noexcept {
    return lhs.i == rhs.i;
  }
  friend bool operator!=(QKeyValueIterator lhs,
                         QKeyValueIterator rhs) noexcept {
    return lhs.i != rhs.i;
  }

  inline QKeyValueIterator &operator++() {
    ++i;
    return *this;
  }
  inline QKeyValueIterator operator++(int) { return QKeyValueIterator(i++); }
  inline QKeyValueIterator &operator--() {
    --i;
    return *this;
  }
  inline QKeyValueIterator operator--(int) { return QKeyValueIterator(i--); }
  Iterator base() const { return i; }

private:
  Iterator i;
};

template <typename T> class QVector {
  typedef QTypedArrayData<T> Data;
  Data *d;

public:
  inline QVector() noexcept : d(Data::sharedNull()) {}
  explicit QVector(int size);
  QVector(int size, const T &t);
  inline QVector(const QVector<T> &v);
  inline ~QVector() {
    if (!d->ref.deref())
      freeData(d);
  }
  QVector<T> &operator=(const QVector<T> &v);
  QVector(QVector<T> &&other) noexcept : d(other.d) {
    other.d = Data::sharedNull();
  }
  QVector<T> &operator=(QVector<T> &&other) noexcept {
    QVector moved(std::move(other));
    swap(moved);
    return *this;
  }
  void swap(QVector<T> &other) noexcept { qSwap(d, other.d); }
  inline QVector(std::initializer_list<T> args);
  QVector<T> &operator=(std::initializer_list<T> args);
  template <typename InputIterator,
            QtPrivate::IfIsInputIterator<InputIterator> = true>
  inline QVector(InputIterator first, InputIterator last);
  explicit QVector(QArrayDataPointerRef<T> ref) noexcept : d(ref.ptr) {}

  bool operator==(const QVector<T> &v) const;
  inline bool operator!=(const QVector<T> &v) const { return !(*this == v); }

  inline int size() const { return d->size; }

  inline bool isEmpty() const { return d->size == 0; }

  void resize(int size);

  inline int capacity() const { return int(d->alloc); }
  void reserve(int size);
  inline void squeeze() {
    if (d->size < int(d->alloc)) {
      if (!d->size) {
        *this = QVector<T>();
        return;
      }
      realloc(d->size);
    }
    if (d->capacityReserved) {

      d->capacityReserved = 0;
    }
  }

  inline void detach();
  inline bool isDetached() const { return !d->ref.isShared(); }

  inline void setSharable(bool sharable) {
    if (sharable == d->ref.isSharable())
      return;
    if (!sharable)
      detach();

    if (d == Data::unsharableEmpty()) {
      if (sharable)
        d = Data::sharedNull();
    } else {
      d->ref.setSharable(sharable);
    }
    ((d->ref.isSharable() == sharable)
         ? static_cast<void>(0)
         : qt_assert("d->ref.isSharable() == sharable",
                     "/usr/local/include/QtCore/qvector.h", 128));
  }

  inline bool isSharedWith(const QVector<T> &other) const {
    return d == other.d;
  }

  inline T *data() {
    detach();
    return d->begin();
  }
  inline const T *data() const { return d->begin(); }
  inline const T *constData() const { return d->begin(); }
  void clear();

  const T &at(int i) const;
  T &operator[](int i);
  const T &operator[](int i) const;
  void append(const T &t);
  void append(T &&t);
  inline void append(const QVector<T> &l) { *this += l; }
  void prepend(T &&t);
  void prepend(const T &t);
  void insert(int i, T &&t);
  void insert(int i, const T &t);
  void insert(int i, int n, const T &t);
  void replace(int i, const T &t);
  void remove(int i);
  void remove(int i, int n);
  inline void removeFirst() {
    ((!isEmpty())
         ? static_cast<void>(0)
         : qt_assert("!isEmpty()", "/usr/local/include/QtCore/qvector.h", 153));
    erase(d->begin());
  }
  inline void removeLast();
  T takeFirst() {
    ((!isEmpty())
         ? static_cast<void>(0)
         : qt_assert("!isEmpty()", "/usr/local/include/QtCore/qvector.h", 155));
    T r = std::move(first());
    removeFirst();
    return r;
  }
  T takeLast() {
    ((!isEmpty())
         ? static_cast<void>(0)
         : qt_assert("!isEmpty()", "/usr/local/include/QtCore/qvector.h", 156));
    T r = std::move(last());
    removeLast();
    return r;
  }

  QVector<T> &fill(const T &t, int size = -1);

  int indexOf(const T &t, int from = 0) const;
  int lastIndexOf(const T &t, int from = -1) const;
  bool contains(const T &t) const;
  int count(const T &t) const;

  void removeAt(int i) { remove(i); }
  int removeAll(const T &t) {
    const const_iterator ce = this->cend(),
                         cit = std::find(this->cbegin(), ce, t);
    if (cit == ce)
      return 0;

    const T tCopy = t;
    const int firstFoundIdx = std::distance(this->cbegin(), cit);
    const iterator e = end(),
                   it = std::remove(begin() + firstFoundIdx, e, tCopy);
    const int result = std::distance(it, e);
    erase(it, e);
    return result;
  }
  bool removeOne(const T &t) {
    const int i = indexOf(t);
    if (i < 0)
      return false;
    remove(i);
    return true;
  }
  int length() const { return size(); }
  T takeAt(int i) {
    T t = std::move((*this)[i]);
    remove(i);
    return t;
  }
  void move(int from, int to) {
    ((from >= 0 && from < size())
         ? static_cast<void>(0)
         : qt_assert_x("QVector::move(int,int)", "'from' is out-of-range",
                       "/usr/local/include/QtCore/qvector.h", 192));
    ((to >= 0 && to < size())
         ? static_cast<void>(0)
         : qt_assert_x("QVector::move(int,int)", "'to' is out-of-range",
                       "/usr/local/include/QtCore/qvector.h", 193));
    if (from == to)
      return;
    detach();
    T *const b = d->begin();
    if (from < to)
      std::rotate(b + from, b + from + 1, b + to + 1);
    else
      std::rotate(b + to, b + from, b + from + 1);
  }

  typedef typename Data::iterator iterator;
  typedef typename Data::const_iterator const_iterator;
  typedef std::reverse_iterator<iterator> reverse_iterator;
  typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

  inline iterator begin() {
    detach();
    return d->begin();
  }
  inline const_iterator begin() const noexcept { return d->constBegin(); }
  inline const_iterator cbegin() const noexcept { return d->constBegin(); }
  inline const_iterator constBegin() const noexcept { return d->constBegin(); }
  inline iterator end() {
    detach();
    return d->end();
  }
  inline const_iterator end() const noexcept { return d->constEnd(); }
  inline const_iterator cend() const noexcept { return d->constEnd(); }
  inline const_iterator constEnd() const noexcept { return d->constEnd(); }
  reverse_iterator rbegin() { return reverse_iterator(end()); }
  reverse_iterator rend() { return reverse_iterator(begin()); }
  const_reverse_iterator rbegin() const noexcept {
    return const_reverse_iterator(end());
  }
  const_reverse_iterator rend() const noexcept {
    return const_reverse_iterator(begin());
  }
  const_reverse_iterator crbegin() const noexcept {
    return const_reverse_iterator(end());
  }
  const_reverse_iterator crend() const noexcept {
    return const_reverse_iterator(begin());
  }
  iterator insert(iterator before, int n, const T &x);
  inline iterator insert(iterator before, const T &x) {
    return insert(before, 1, x);
  }
  inline iterator insert(iterator before, T &&x);
  iterator erase(iterator begin, iterator end);
  inline iterator erase(iterator pos) { return erase(pos, pos + 1); }

  inline int count() const { return d->size; }
  inline T &first() {
    ((!isEmpty())
         ? static_cast<void>(0)
         : qt_assert("!isEmpty()", "/usr/local/include/QtCore/qvector.h", 242));
    return *begin();
  }
  inline const T &first() const {
    ((!isEmpty())
         ? static_cast<void>(0)
         : qt_assert("!isEmpty()", "/usr/local/include/QtCore/qvector.h", 243));
    return *begin();
  }
  inline const T &constFirst() const {
    ((!isEmpty())
         ? static_cast<void>(0)
         : qt_assert("!isEmpty()", "/usr/local/include/QtCore/qvector.h", 244));
    return *begin();
  }
  inline T &last() {
    ((!isEmpty())
         ? static_cast<void>(0)
         : qt_assert("!isEmpty()", "/usr/local/include/QtCore/qvector.h", 245));
    return *(end() - 1);
  }
  inline const T &last() const {
    ((!isEmpty())
         ? static_cast<void>(0)
         : qt_assert("!isEmpty()", "/usr/local/include/QtCore/qvector.h", 246));
    return *(end() - 1);
  }
  inline const T &constLast() const {
    ((!isEmpty())
         ? static_cast<void>(0)
         : qt_assert("!isEmpty()", "/usr/local/include/QtCore/qvector.h", 247));
    return *(end() - 1);
  }
  inline bool startsWith(const T &t) const {
    return !isEmpty() && first() == t;
  }
  inline bool endsWith(const T &t) const { return !isEmpty() && last() == t; }
  QVector<T> mid(int pos, int len = -1) const;

  T value(int i) const;
  T value(int i, const T &defaultValue) const;

  void swapItemsAt(int i, int j) {
    ((i >= 0 && i < size() && j >= 0 && j < size())
         ? static_cast<void>(0)
         : qt_assert_x("QVector<T>::swap", "index out of range",
                       "/usr/local/include/QtCore/qvector.h", 257));

    detach();
    qSwap(d->begin()[i], d->begin()[j]);
  }

  typedef T value_type;
  typedef value_type *pointer;
  typedef const value_type *const_pointer;
  typedef value_type &reference;
  typedef const value_type &const_reference;
  typedef qptrdiff difference_type;
  typedef iterator Iterator;
  typedef const_iterator ConstIterator;
  typedef int size_type;
  inline void push_back(const T &t) { append(t); }
  void push_back(T &&t) { append(std::move(t)); }
  void push_front(T &&t) { prepend(std::move(t)); }
  inline void push_front(const T &t) { prepend(t); }
  void pop_back() { removeLast(); }
  void pop_front() { removeFirst(); }
  inline bool empty() const { return d->size == 0; }
  inline T &front() { return first(); }
  inline const_reference front() const { return first(); }
  inline reference back() { return last(); }
  inline const_reference back() const { return last(); }
  void shrink_to_fit() { squeeze(); }

  QVector<T> &operator+=(const QVector<T> &l);
  inline QVector<T> operator+(const QVector<T> &l) const {
    QVector n = *this;
    n += l;
    return n;
  }
  inline QVector<T> &operator+=(const T &t) {
    append(t);
    return *this;
  }
  inline QVector<T> &operator<<(const T &t) {
    append(t);
    return *this;
  }
  inline QVector<T> &operator<<(const QVector<T> &l) {
    *this += l;
    return *this;
  }
  inline QVector<T> &operator+=(T &&t) {
    append(std::move(t));
    return *this;
  }
  inline QVector<T> &operator<<(T &&t) {
    append(std::move(t));
    return *this;
  }

  static QVector<T> fromList(const QList<T> &list);
  QList<T> toList() const;

  __attribute__((__deprecated__("Use QVector<T>(vector.begin(), vector.end()) "
                                "instead."))) static inline QVector<T>
  fromStdVector(const std::vector<T> &vector) {
    return QVector<T>(vector.begin(), vector.end());
  }
  __attribute__((
      __deprecated__("Use std::vector<T>(vector.begin(), vector.end()) "
                     "instead."))) inline std::vector<T>
  toStdVector() const {
    return std::vector<T>(d->begin(), d->end());
  }

private:
  void reallocData(const int size, const int alloc,
                   QArrayData::AllocationOptions options = QArrayData::Default);
  void reallocData(const int sz) { reallocData(sz, d->alloc); }
  void realloc(int alloc,
               QArrayData::AllocationOptions options = QArrayData::Default);
  void freeData(Data *d);
  void defaultConstruct(T *from, T *to);
  void copyConstruct(const T *srcFrom, const T *srcTo, T *dstFrom);
  void destruct(T *from, T *to);
  bool isValidIterator(const iterator &i) const {
    const std::less<const T *> less = {};
    return !less(d->end(), i) && !less(i, d->begin());
  }
  class AlignmentDummy {
    Data header;
    T array[1];
  };
};
template <typename T> void QVector<T>::defaultConstruct(T *from, T *to) {
  if (QTypeInfo<T>::isComplex) {
    while (from != to) {
      new (from++) T();
    }
  } else {
    ::memset(static_cast<void *>(from), 0, (to - from) * sizeof(T));
  }
}

template <typename T>
void QVector<T>::copyConstruct(const T *srcFrom, const T *srcTo, T *dstFrom) {
  if (QTypeInfo<T>::isComplex) {
    while (srcFrom != srcTo)
      new (dstFrom++) T(*srcFrom++);
  } else {
    ::memcpy(static_cast<void *>(dstFrom), static_cast<const void *>(srcFrom),
             (srcTo - srcFrom) * sizeof(T));
  }
}

template <typename T> void QVector<T>::destruct(T *from, T *to) {
  if (QTypeInfo<T>::isComplex) {
    while (from != to) {
      from++->~T();
    }
  }
}

template <typename T> inline QVector<T>::QVector(const QVector<T> &v) {
  if (v.d->ref.ref()) {
    d = v.d;
  } else {
    if (v.d->capacityReserved) {
      d = Data::allocate(v.d->alloc);
      do {
        if (!(d))
          qBadAlloc();
      } while (false);
      d->capacityReserved = true;
    } else {
      d = Data::allocate(v.d->size);
      do {
        if (!(d))
          qBadAlloc();
      } while (false);
    }
    if (d->alloc) {
      copyConstruct(v.d->begin(), v.d->end(), d->begin());
      d->size = v.d->size;
    }
  }
}

template <typename T> void QVector<T>::detach() {
  if (!isDetached()) {

    if (!d->alloc)
      d = Data::unsharableEmpty();
    else

      realloc(int(d->alloc));
  }
  ((isDetached())
       ? static_cast<void>(0)
       : qt_assert("isDetached()", "/usr/local/include/QtCore/qvector.h", 413));
}

template <typename T> void QVector<T>::reserve(int asize) {
  if (asize > int(d->alloc))
    realloc(asize);
  if (isDetached()

      && d != Data::unsharableEmpty()

  )
    d->capacityReserved = 1;
  ((capacity() >= asize)
       ? static_cast<void>(0)
       : qt_assert("capacity() >= asize", "/usr/local/include/QtCore/qvector.h",
                   427));
}

template <typename T> void QVector<T>::resize(int asize) {
  if (asize == d->size)
    return detach();
  if (asize > int(d->alloc) || !isDetached()) {
    QArrayData::AllocationOptions opt =
        asize > int(d->alloc) ? QArrayData::Grow : QArrayData::Default;
    realloc(qMax(int(d->alloc), asize), opt);
  }
  if (asize < d->size)
    destruct(begin() + asize, end());
  else
    defaultConstruct(end(), begin() + asize);
  d->size = asize;
}
template <typename T> inline void QVector<T>::clear() {
  if (!d->size)
    return;
  destruct(begin(), end());
  d->size = 0;
}
template <typename T> inline const T &QVector<T>::at(int i) const {
  ((i >= 0 && i < d->size)
       ? static_cast<void>(0)
       : qt_assert_x("QVector<T>::at", "index out of range",
                     "/usr/local/include/QtCore/qvector.h", 455));
  return d->begin()[i];
}
template <typename T> inline const T &QVector<T>::operator[](int i) const {
  ((i >= 0 && i < d->size)
       ? static_cast<void>(0)
       : qt_assert_x("QVector<T>::operator[]", "index out of range",
                     "/usr/local/include/QtCore/qvector.h", 459));
  return d->begin()[i];
}
template <typename T> inline T &QVector<T>::operator[](int i) {
  ((i >= 0 && i < d->size)
       ? static_cast<void>(0)
       : qt_assert_x("QVector<T>::operator[]", "index out of range",
                     "/usr/local/include/QtCore/qvector.h", 463));
  return data()[i];
}
template <typename T> inline void QVector<T>::insert(int i, const T &t) {
  ((i >= 0 && i <= d->size)
       ? static_cast<void>(0)
       : qt_assert_x("QVector<T>::insert", "index out of range",
                     "/usr/local/include/QtCore/qvector.h", 467));
  insert(begin() + i, 1, t);
}
template <typename T> inline void QVector<T>::insert(int i, int n, const T &t) {
  ((i >= 0 && i <= d->size)
       ? static_cast<void>(0)
       : qt_assert_x("QVector<T>::insert", "index out of range",
                     "/usr/local/include/QtCore/qvector.h", 471));
  insert(begin() + i, n, t);
}
template <typename T> inline void QVector<T>::insert(int i, T &&t) {
  ((i >= 0 && i <= d->size)
       ? static_cast<void>(0)
       : qt_assert_x("QVector<T>::insert", "index out of range",
                     "/usr/local/include/QtCore/qvector.h", 475));
  insert(begin() + i, std::move(t));
}
template <typename T> inline void QVector<T>::remove(int i, int n) {
  ((i >= 0 && n >= 0 && i + n <= d->size)
       ? static_cast<void>(0)
       : qt_assert_x("QVector<T>::remove", "index out of range",
                     "/usr/local/include/QtCore/qvector.h", 479));
  erase(d->begin() + i, d->begin() + i + n);
}
template <typename T> inline void QVector<T>::remove(int i) {
  ((i >= 0 && i < d->size)
       ? static_cast<void>(0)
       : qt_assert_x("QVector<T>::remove", "index out of range",
                     "/usr/local/include/QtCore/qvector.h", 483));
  erase(d->begin() + i, d->begin() + i + 1);
}
template <typename T> inline void QVector<T>::prepend(const T &t) {
  insert(begin(), 1, t);
}
template <typename T> inline void QVector<T>::prepend(T &&t) {
  insert(begin(), std::move(t));
}

template <typename T> inline void QVector<T>::replace(int i, const T &t) {
  ((i >= 0 && i < d->size)
       ? static_cast<void>(0)
       : qt_assert_x("QVector<T>::replace", "index out of range",
                     "/usr/local/include/QtCore/qvector.h", 495));
  const T copy(t);
  data()[i] = copy;
}

template <typename T> QVector<T> &QVector<T>::operator=(const QVector<T> &v) {
  if (v.d != d) {
    QVector<T> tmp(v);
    tmp.swap(*this);
  }
  return *this;
}

template <typename T> QVector<T>::QVector(int asize) {
  ((asize >= 0) ? static_cast<void>(0)
                : qt_assert_x("QVector::QVector",
                              "Size must be greater than or equal to 0.",
                              "/usr/local/include/QtCore/qvector.h", 513));
  if (__builtin_expect(!!(asize > 0), true)) {
    d = Data::allocate(asize);
    do {
      if (!(d))
        qBadAlloc();
    } while (false);
    d->size = asize;
    defaultConstruct(d->begin(), d->end());
  } else {
    d = Data::sharedNull();
  }
}

template <typename T> QVector<T>::QVector(int asize, const T &t) {
  ((asize >= 0) ? static_cast<void>(0)
                : qt_assert_x("QVector::QVector",
                              "Size must be greater than or equal to 0.",
                              "/usr/local/include/QtCore/qvector.h", 527));
  if (asize > 0) {
    d = Data::allocate(asize);
    do {
      if (!(d))
        qBadAlloc();
    } while (false);
    d->size = asize;
    T *i = d->end();
    while (i != d->begin())
      new (--i) T(t);
  } else {
    d = Data::sharedNull();
  }
}

template <typename T> QVector<T>::QVector(std::initializer_list<T> args) {
  if (args.size() > 0) {
    d = Data::allocate(args.size());
    do {
      if (!(d))
        qBadAlloc();
    } while (false);

    copyConstruct(args.begin(), args.end(), d->begin());
    d->size = int(args.size());
  } else {
    d = Data::sharedNull();
  }
}

template <typename T>
QVector<T> &QVector<T>::operator=(std::initializer_list<T> args) {
  QVector<T> tmp(args);
  tmp.swap(*this);
  return *this;
}

template <typename T>
template <typename InputIterator, QtPrivate::IfIsInputIterator<InputIterator>>
QVector<T>::QVector(InputIterator first, InputIterator last) : QVector() {
  QtPrivate::reserveIfForwardIterator(this, first, last);
  std::copy(first, last, std::back_inserter(*this));
}

template <typename T> void QVector<T>::freeData(Data *x) {
  destruct(x->begin(), x->end());
  Data::deallocate(x);
}

template <typename T>
void QVector<T>::reallocData(const int asize, const int aalloc,
                             QArrayData::AllocationOptions options) {
  ((asize >= 0 && asize <= aalloc)
       ? static_cast<void>(0)
       : qt_assert("asize >= 0 && asize <= aalloc",
                   "/usr/local/include/QtCore/qvector.h", 596));
  Data *x = d;

  const bool isShared = d->ref.isShared();

  if (aalloc != 0) {
    if (aalloc != int(d->alloc) || isShared) {
      try {

        x = Data::allocate(aalloc, options);
        do {
          if (!(x))
            qBadAlloc();
        } while (false);

        ((x->ref.isSharable() || options.testFlag(QArrayData::Unsharable))
             ? static_cast<void>(0)
             : qt_assert("x->ref.isSharable() || "
                         "options.testFlag(QArrayData::Unsharable)",
                         "/usr/local/include/QtCore/qvector.h", 609));

        ((!x->ref.isStatic())
             ? static_cast<void>(0)
             : qt_assert("!x->ref.isStatic()",
                         "/usr/local/include/QtCore/qvector.h", 611));
        x->size = asize;

        T *srcBegin = d->begin();
        T *srcEnd = asize > d->size ? d->end() : d->begin() + asize;
        T *dst = x->begin();

        if (!QTypeInfoQuery<T>::isRelocatable ||
            (isShared && QTypeInfo<T>::isComplex)) {
          try {
            if (isShared || !std::is_nothrow_move_constructible<T>::value) {

              while (srcBegin != srcEnd)
                new (dst++) T(*srcBegin++);
            } else {
              while (srcBegin != srcEnd)
                new (dst++) T(std::move(*srcBegin++));
            }
          } catch (...) {

            destruct(x->begin(), dst);
            throw;
          }
        } else {
          ::memcpy(static_cast<void *>(dst), static_cast<void *>(srcBegin),
                   (srcEnd - srcBegin) * sizeof(T));
          dst += srcEnd - srcBegin;

          if (asize < d->size)
            destruct(d->begin() + asize, d->end());
        }

        if (asize > d->size) {

          if (!QTypeInfo<T>::isComplex) {
            ::memset(static_cast<void *>(dst), 0,
                     (static_cast<T *>(x->end()) - dst) * sizeof(T));
          } else {
            try {
              while (dst != x->end())
                new (dst++) T();
            } catch (...) {

              destruct(x->begin(), dst);
              throw;
            }
          }
        }
      } catch (...) {
        Data::deallocate(x);
        throw;
      }
      x->capacityReserved = d->capacityReserved;
    } else {
      ((int(d->alloc) == aalloc)
           ? static_cast<void>(0)
           : qt_assert("int(d->alloc) == aalloc",
                       "/usr/local/include/QtCore/qvector.h", 663));
      ((isDetached()) ? static_cast<void>(0)
                      : qt_assert("isDetached()",
                                  "/usr/local/include/QtCore/qvector.h", 664));
      ((x == d)
           ? static_cast<void>(0)
           : qt_assert("x == d", "/usr/local/include/QtCore/qvector.h", 665));
      if (asize <= d->size) {
        destruct(x->begin() + asize, x->end());
      } else {
        defaultConstruct(x->end(), x->begin() + asize);
      }
      x->size = asize;
    }
  } else {
    x = Data::sharedNull();
  }
  if (d != x) {
    if (!d->ref.deref()) {
      if (!QTypeInfoQuery<T>::isRelocatable || !aalloc ||
          (isShared && QTypeInfo<T>::isComplex)) {

        freeData(d);
      } else {
        Data::deallocate(d);
      }
    }
    d = x;
  }

  ((d->data())
       ? static_cast<void>(0)
       : qt_assert("d->data()", "/usr/local/include/QtCore/qvector.h", 689));
  ((uint(d->size) <= d->alloc)
       ? static_cast<void>(0)
       : qt_assert("uint(d->size) <= d->alloc",
                   "/usr/local/include/QtCore/qvector.h", 690));

  ((d != Data::unsharableEmpty())
       ? static_cast<void>(0)
       : qt_assert("d != Data::unsharableEmpty()",
                   "/usr/local/include/QtCore/qvector.h", 692));

  ((aalloc ? d != Data::sharedNull() : d == Data::sharedNull())
       ? static_cast<void>(0)
       : qt_assert("aalloc ? d != Data::sharedNull() : d == Data::sharedNull()",
                   "/usr/local/include/QtCore/qvector.h", 694));
  ((d->alloc >= uint(aalloc))
       ? static_cast<void>(0)
       : qt_assert("d->alloc >= uint(aalloc)",
                   "/usr/local/include/QtCore/qvector.h", 695));
  ((d->size == asize) ? static_cast<void>(0)
                      : qt_assert("d->size == asize",
                                  "/usr/local/include/QtCore/qvector.h", 696));
}

template <typename T>
void QVector<T>::realloc(int aalloc, QArrayData::AllocationOptions options) {
  ((aalloc >= d->size) ? static_cast<void>(0)
                       : qt_assert("aalloc >= d->size",
                                   "/usr/local/include/QtCore/qvector.h", 702));
  Data *x = d;

  const bool isShared = d->ref.isShared();

  try {

    x = Data::allocate(aalloc, options);
    do {
      if (!(x))
        qBadAlloc();
    } while (false);

    ((x->ref.isSharable() || options.testFlag(QArrayData::Unsharable))
         ? static_cast<void>(0)
         : qt_assert("x->ref.isSharable() || "
                     "options.testFlag(QArrayData::Unsharable)",
                     "/usr/local/include/QtCore/qvector.h", 713));

    ((!x->ref.isStatic())
         ? static_cast<void>(0)
         : qt_assert("!x->ref.isStatic()",
                     "/usr/local/include/QtCore/qvector.h", 715));
    x->size = d->size;

    T *srcBegin = d->begin();
    T *srcEnd = d->end();
    T *dst = x->begin();

    if (!QTypeInfoQuery<T>::isRelocatable ||
        (isShared && QTypeInfo<T>::isComplex)) {
      try {
        if (isShared || !std::is_nothrow_move_constructible<T>::value) {

          while (srcBegin != srcEnd)
            new (dst++) T(*srcBegin++);
        } else {
          while (srcBegin != srcEnd)
            new (dst++) T(std::move(*srcBegin++));
        }
      } catch (...) {

        destruct(x->begin(), dst);
        throw;
      }
    } else {
      ::memcpy(static_cast<void *>(dst), static_cast<void *>(srcBegin),
               (srcEnd - srcBegin) * sizeof(T));
      dst += srcEnd - srcBegin;
    }

  } catch (...) {
    Data::deallocate(x);
    throw;
  }
  x->capacityReserved = d->capacityReserved;

  ((d != x) ? static_cast<void>(0)
            : qt_assert("d != x", "/usr/local/include/QtCore/qvector.h", 748));
  if (!d->ref.deref()) {
    if (!QTypeInfoQuery<T>::isRelocatable || !aalloc ||
        (isShared && QTypeInfo<T>::isComplex)) {

      freeData(d);
    } else {
      Data::deallocate(d);
    }
  }
  d = x;

  ((d->data())
       ? static_cast<void>(0)
       : qt_assert("d->data()", "/usr/local/include/QtCore/qvector.h", 760));
  ((uint(d->size) <= d->alloc)
       ? static_cast<void>(0)
       : qt_assert("uint(d->size) <= d->alloc",
                   "/usr/local/include/QtCore/qvector.h", 761));

  ((d != Data::unsharableEmpty())
       ? static_cast<void>(0)
       : qt_assert("d != Data::unsharableEmpty()",
                   "/usr/local/include/QtCore/qvector.h", 763));

  ((d != Data::sharedNull())
       ? static_cast<void>(0)
       : qt_assert("d != Data::sharedNull()",
                   "/usr/local/include/QtCore/qvector.h", 765));
  ((d->alloc >= uint(aalloc))
       ? static_cast<void>(0)
       : qt_assert("d->alloc >= uint(aalloc)",
                   "/usr/local/include/QtCore/qvector.h", 766));
}

template <typename T> T QVector<T>::value(int i) const {
  if (uint(i) >= uint(d->size)) {
    return T();
  }
  return d->begin()[i];
}
template <typename T> T QVector<T>::value(int i, const T &defaultValue) const {
  return uint(i) >= uint(d->size) ? defaultValue : d->begin()[i];
}

template <typename T> void QVector<T>::append(const T &t) {
  const bool isTooSmall = uint(d->size + 1) > d->alloc;
  if (!isDetached() || isTooSmall) {
    T copy(t);
    QArrayData::AllocationOptions opt(isTooSmall ? QArrayData::Grow
                                                 : QArrayData::Default);
    realloc(isTooSmall ? d->size + 1 : d->alloc, opt);

    if (QTypeInfo<T>::isComplex)
      new (d->end()) T(std::move(copy));
    else
      *d->end() = std::move(copy);

  } else {
    if (QTypeInfo<T>::isComplex)
      new (d->end()) T(t);
    else
      *d->end() = t;
  }
  ++d->size;
}

template <typename T> void QVector<T>::append(T &&t) {
  const bool isTooSmall = uint(d->size + 1) > d->alloc;
  if (!isDetached() || isTooSmall) {
    QArrayData::AllocationOptions opt(isTooSmall ? QArrayData::Grow
                                                 : QArrayData::Default);
    realloc(isTooSmall ? d->size + 1 : d->alloc, opt);
  }

  new (d->end()) T(std::move(t));

  ++d->size;
}

template <typename T> void QVector<T>::removeLast() {
  ((!isEmpty())
       ? static_cast<void>(0)
       : qt_assert("!isEmpty()", "/usr/local/include/QtCore/qvector.h", 827));
  ((d->alloc)
       ? static_cast<void>(0)
       : qt_assert("d->alloc", "/usr/local/include/QtCore/qvector.h", 828));

  if (d->ref.isShared())
    detach();
  --d->size;
  if (QTypeInfo<T>::isComplex)
    (d->data() + d->size)->~T();
}

template <typename T>
typename QVector<T>::iterator QVector<T>::insert(iterator before, size_type n,
                                                 const T &t) {
  ((isValidIterator(before))
       ? static_cast<void>(0)
       : qt_assert_x("QVector::insert",
                     "The specified iterator argument 'before' is invalid",
                     "/usr/local/include/QtCore/qvector.h", 840));

  const auto offset = std::distance(d->begin(), before);
  if (n != 0) {
    const T copy(t);
    if (!isDetached() || d->size + n > int(d->alloc))
      realloc(d->size + n, QArrayData::Grow);
    if (!QTypeInfoQuery<T>::isRelocatable) {
      T *b = d->end();
      T *i = d->end() + n;
      while (i != b)
        new (--i) T;
      i = d->end();
      T *j = i + n;
      b = d->begin() + offset;
      while (i != b)
        *--j = *--i;
      i = b + n;
      while (i != b)
        *--i = copy;
    } else {
      T *b = d->begin() + offset;
      T *i = b + n;
      memmove(static_cast<void *>(i), static_cast<const void *>(b),
              (d->size - offset) * sizeof(T));
      while (i != b)
        new (--i) T(copy);
    }
    d->size += n;
  }
  return d->begin() + offset;
}

template <typename T>
typename QVector<T>::iterator QVector<T>::insert(iterator before, T &&t) {
  ((isValidIterator(before))
       ? static_cast<void>(0)
       : qt_assert_x("QVector::insert",
                     "The specified iterator argument 'before' is invalid",
                     "/usr/local/include/QtCore/qvector.h", 875));

  const auto offset = std::distance(d->begin(), before);
  if (!isDetached() || d->size + 1 > int(d->alloc))
    realloc(d->size + 1, QArrayData::Grow);
  if (!QTypeInfoQuery<T>::isRelocatable) {
    T *i = d->end();
    T *j = i + 1;
    T *b = d->begin() + offset;

    if (i != b) {
      new (--j) T(std::move(*--i));
      while (i != b)
        *--j = std::move(*--i);
      *b = std::move(t);
    } else {
      new (b) T(std::move(t));
    }
  } else {
    T *b = d->begin() + offset;
    memmove(static_cast<void *>(b + 1), static_cast<const void *>(b),
            (d->size - offset) * sizeof(T));
    new (b) T(std::move(t));
  }
  d->size += 1;
  return d->begin() + offset;
}

template <typename T>
typename QVector<T>::iterator QVector<T>::erase(iterator abegin,
                                                iterator aend) {
  ((isValidIterator(abegin))
       ? static_cast<void>(0)
       : qt_assert_x("QVector::erase",
                     "The specified iterator argument 'abegin' is invalid",
                     "/usr/local/include/QtCore/qvector.h", 905));
  ((isValidIterator(aend))
       ? static_cast<void>(0)
       : qt_assert_x("QVector::erase",
                     "The specified iterator argument 'aend' is invalid",
                     "/usr/local/include/QtCore/qvector.h", 906));

  const auto itemsToErase = aend - abegin;

  if (!itemsToErase)
    return abegin;

  ((abegin >= d->begin())
       ? static_cast<void>(0)
       : qt_assert("abegin >= d->begin()",
                   "/usr/local/include/QtCore/qvector.h", 913));
  ((aend <= d->end()) ? static_cast<void>(0)
                      : qt_assert("aend <= d->end()",
                                  "/usr/local/include/QtCore/qvector.h", 914));
  ((abegin <= aend) ? static_cast<void>(0)
                    : qt_assert("abegin <= aend",
                                "/usr/local/include/QtCore/qvector.h", 915));

  const auto itemsUntouched = abegin - d->begin();

  if (d->alloc) {
    detach();
    abegin = d->begin() + itemsUntouched;
    aend = abegin + itemsToErase;
    if (!QTypeInfoQuery<T>::isRelocatable) {
      iterator moveBegin = abegin + itemsToErase;
      iterator moveEnd = d->end();
      while (moveBegin != moveEnd) {
        if (QTypeInfo<T>::isComplex)
          static_cast<T *>(abegin)->~T();
        new (abegin++) T(*moveBegin++);
      }
      if (abegin < d->end()) {

        destruct(abegin, d->end());
      }
    } else {
      destruct(abegin, aend);

      memmove(static_cast<void *>(abegin), static_cast<void *>(aend),
              (d->size - itemsToErase - itemsUntouched) * sizeof(T));
    }
    d->size -= int(itemsToErase);
  }
  return d->begin() + itemsUntouched;
}

template <typename T> bool QVector<T>::operator==(const QVector<T> &v) const {
  if (d == v.d)
    return true;
  if (d->size != v.d->size)
    return false;
  const T *vb = v.d->begin();
  const T *b = d->begin();
  const T *e = d->end();
  return std::equal(b, e, (vb));
}

template <typename T> QVector<T> &QVector<T>::fill(const T &from, int asize) {
  const T copy(from);
  resize(asize < 0 ? d->size : asize);
  if (d->size) {
    T *i = d->end();
    T *b = d->begin();
    while (i != b)
      *--i = copy;
  }
  return *this;
}

template <typename T> QVector<T> &QVector<T>::operator+=(const QVector &l) {
  if (d->size == 0) {
    *this = l;
  } else {
    uint newSize = d->size + l.d->size;
    const bool isTooSmall = newSize > d->alloc;
    if (!isDetached() || isTooSmall) {
      QArrayData::AllocationOptions opt(isTooSmall ? QArrayData::Grow
                                                   : QArrayData::Default);
      realloc(isTooSmall ? newSize : d->alloc, opt);
    }

    if (d->alloc) {
      T *w = d->begin() + newSize;
      T *i = l.d->end();
      T *b = l.d->begin();
      while (i != b) {
        if (QTypeInfo<T>::isComplex)
          new (--w) T(*--i);
        else
          *--w = *--i;
      }
      d->size = newSize;
    }
  }
  return *this;
}

template <typename T> int QVector<T>::indexOf(const T &t, int from) const {
  if (from < 0)
    from = qMax(from + d->size, 0);
  if (from < d->size) {
    T *n = d->begin() + from - 1;
    T *e = d->end();
    while (++n != e)
      if (*n == t)
        return n - d->begin();
  }
  return -1;
}

template <typename T> int QVector<T>::lastIndexOf(const T &t, int from) const {
  if (from < 0)
    from += d->size;
  else if (from >= d->size)
    from = d->size - 1;
  if (from >= 0) {
    T *b = d->begin();
    T *n = d->begin() + from + 1;
    while (n != b) {
      if (*--n == t)
        return n - b;
    }
  }
  return -1;
}

template <typename T> bool QVector<T>::contains(const T &t) const {
  const T *b = d->begin();
  const T *e = d->end();
  return std::find(b, e, t) != e;
}

template <typename T> int QVector<T>::count(const T &t) const {
  const T *b = d->begin();
  const T *e = d->end();
  return int(std::count(b, e, t));
}

template <typename T> QVector<T> QVector<T>::mid(int pos, int len) const {
  using namespace QtPrivate;
  switch (QContainerImplHelper::mid(d->size, &pos, &len)) {
  case QContainerImplHelper::Null:
  case QContainerImplHelper::Empty:
    return QVector<T>();
  case QContainerImplHelper::Full:
    return *this;
  case QContainerImplHelper::Subset:
    break;
  }

  QVector<T> midResult;
  midResult.realloc(len);
  T *srcFrom = d->begin() + pos;
  T *srcTo = d->begin() + pos + len;
  midResult.copyConstruct(srcFrom, srcTo, midResult.data());
  midResult.d->size = len;
  return midResult;
}

template <class T> class QVectorIterator {
  typedef typename QVector<T>::const_iterator const_iterator;
  QVector<T> c;
  const_iterator i;
public:
  inline QVectorIterator(const QVector<T> &container)
      : c(container), i(c.constBegin()) {}
  inline QVectorIterator &operator=(const QVector<T> &container) {
    c = container;
    i = c.constBegin();
    return *this;
  }
  inline void toFront() { i = c.constBegin(); }
  inline void toBack() { i = c.constEnd(); }
  inline bool hasNext() const { return i != c.constEnd(); }
  inline const T &next() { return *i++; }
  inline const T &peekNext() const { return *i; }
  inline bool hasPrevious() const { return i != c.constBegin(); }
  inline const T &previous() { return *--i; }
  inline const T &peekPrevious() const {
    const_iterator p = i;
    return *--p;
  }
  inline bool findNext(const T &t) {
    while (i != c.constEnd())
      if (*i++ == t)
        return true;
    return false;
  }
  inline bool findPrevious(const T &t) {
    while (i != c.constBegin())
      if (*(--i) == t)
        return true;
    return false;
  }
};
template <class T> class QMutableVectorIterator {
  typedef typename QVector<T>::iterator iterator;
  typedef typename QVector<T>::const_iterator const_iterator;
  QVector<T> *c;
  iterator i, n;
  inline bool item_exists() const { return const_iterator(n) != c->constEnd(); }
public:
  inline QMutableVectorIterator(QVector<T> &container) : c(&container) {
    i = c->begin();
    n = c->end();
  }
  inline QMutableVectorIterator &operator=(QVector<T> &container) {
    c = &container;
    i = c->begin();
    n = c->end();
    return *this;
  }
  inline void toFront() {
    i = c->begin();
    n = c->end();
  }
  inline void toBack() {
    i = c->end();
    n = i;
  }
  inline bool hasNext() const { return c->constEnd() != const_iterator(i); }
  inline T &next() {
    n = i++;
    return *n;
  }
  inline T &peekNext() const { return *i; }
  inline bool hasPrevious() const {
    return c->constBegin() != const_iterator(i);
  }
  inline T &previous() {
    n = --i;
    return *n;
  }
  inline T &peekPrevious() const {
    iterator p = i;
    return *--p;
  }
  inline void remove() {
    if (c->constEnd() != const_iterator(n)) {
      i = c->erase(n);
      n = c->end();
    }
  }
  inline void setValue(const T &t) const {
    if (c->constEnd() != const_iterator(n))
      *n = t;
  }
  inline T &value() {
    ((item_exists()) ? static_cast<void>(0)
                     : qt_assert("item_exists()",
                                 "/usr/local/include/QtCore/qvector.h", 1080));
    return *n;
  }
  inline const T &value() const {
    ((item_exists()) ? static_cast<void>(0)
                     : qt_assert("item_exists()",
                                 "/usr/local/include/QtCore/qvector.h", 1080));
    return *n;
  }
  inline void insert(const T &t) {
    n = i = c->insert(i, t);
    ++i;
  }
  inline bool findNext(const T &t) {
    while (c->constEnd() != const_iterator(n = i))
      if (*i++ == t)
        return true;
    return false;
  }
  inline bool findPrevious(const T &t) {
    while (c->constBegin() != const_iterator(i))
      if (*(n = --i) == t)
        return true;
    n = c->end();
    return false;
  }
};

template <typename T>
uint qHash(const QVector<T> &key,
           uint seed = 0) noexcept(noexcept(qHashRange(key.cbegin(), key.cend(),
                                                       seed))) {
  return qHashRange(key.cbegin(), key.cend(), seed);
}

template <typename T>
bool operator<(const QVector<T> &lhs, const QVector<T> &rhs) noexcept(
    noexcept(std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
                                          rhs.end()))) {
  return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
                                      rhs.end());
}

template <typename T>
inline bool operator>(const QVector<T> &lhs,
                      const QVector<T> &rhs) noexcept(noexcept(lhs < rhs)) {
  return rhs < lhs;
}

template <typename T>
inline bool operator<=(const QVector<T> &lhs,
                       const QVector<T> &rhs) noexcept(noexcept(lhs < rhs)) {
  return !(lhs > rhs);
}

template <typename T>
inline bool operator>=(const QVector<T> &lhs,
                       const QVector<T> &rhs) noexcept(noexcept(lhs < rhs)) {
  return !(lhs < rhs);
}
QVector<uint> QStringView::toUcs4() const {
  return QtPrivate::convertToUcs4(*this);
}

template <typename T> class QVector;
template <typename T> class QSet;

template <typename T> struct QListSpecialMethods {
protected:
  ~QListSpecialMethods() = default;
};
template <> struct QListSpecialMethods<QByteArray>;
template <> struct QListSpecialMethods<QString>;

struct __attribute__((visibility("default"))) QListData {

  struct NotArrayCompatibleLayout {};
  struct NotIndirectLayout {};
  struct ArrayCompatibleLayout : NotIndirectLayout {};
  struct InlineWithPaddingLayout : NotArrayCompatibleLayout,
                                   NotIndirectLayout {};
  struct IndirectLayout : NotArrayCompatibleLayout {};

  struct Data {
    QtPrivate::RefCount ref;
    int alloc, begin, end;
    void *array[1];
  };
  enum { DataHeaderSize = sizeof(Data) - sizeof(void *) };

  Data *detach(int alloc);
  Data *detach_grow(int *i, int n);
  void realloc(int alloc);
  void realloc_grow(int growth);
  inline void dispose() { dispose(d); }
  static void dispose(Data *d);
  static const Data shared_null;
  Data *d;
  void **erase(void **xi);
  void **append(int n);
  void **append();
  void **append(const QListData &l);
  void **prepend();
  void **insert(int i);
  void remove(int i);
  void remove(int i, int n);
  void move(int from, int to);
  inline int size() const noexcept { return int(d->end - d->begin); }
  inline bool isEmpty() const noexcept { return d->end == d->begin; }
  inline void **at(int i) const noexcept { return d->array + d->begin + i; }
  inline void **begin() const noexcept { return d->array + d->begin; }
  inline void **end() const noexcept { return d->array + d->end; }
};

namespace QtPrivate {
template <typename V, typename U>
int indexOf(const QList<V> &list, const U &u, int from);
template <typename V, typename U>
int lastIndexOf(const QList<V> &list, const U &u, int from);
} // namespace QtPrivate

template <typename T>
class QList

    : public QListSpecialMethods<T>

{
public:
  struct MemoryLayout
      : std::conditional<

            QTypeInfo<T>::isStatic || QTypeInfo<T>::isLarge,
            QListData::IndirectLayout,
            typename std::conditional<
                sizeof(T) == sizeof(void *), QListData::ArrayCompatibleLayout,
                QListData::InlineWithPaddingLayout>::type>::type {};

private:
  template <typename V, typename U>
  friend int QtPrivate::indexOf(const QList<V> &list, const U &u, int from);
  template <typename V, typename U>
  friend int QtPrivate::lastIndexOf(const QList<V> &list, const U &u, int from);
  struct Node {
    void *v;

    inline T &t() {
      return *reinterpret_cast<T *>(
          QTypeInfo<T>::isLarge || QTypeInfo<T>::isStatic ? v : this);
    }
  };

  union {
    QListData p;
    QListData::Data *d;
  };

public:
  inline QList() noexcept
      : d(const_cast<QListData::Data *>(&QListData::shared_null)) {}
  QList(const QList<T> &l);
  ~QList();
  QList<T> &operator=(const QList<T> &l);
  inline QList(QList<T> &&other) noexcept : d(other.d) {
    other.d = const_cast<QListData::Data *>(&QListData::shared_null);
  }
  inline QList &operator=(QList<T> &&other) noexcept {
    QList moved(std::move(other));
    swap(moved);
    return *this;
  }
  inline void swap(QList<T> &other) noexcept { qSwap(d, other.d); }
  inline QList(std::initializer_list<T> args)
      : QList(args.begin(), args.end()) {}
  template <typename InputIterator,
            QtPrivate::IfIsInputIterator<InputIterator> = true>
  QList(InputIterator first, InputIterator last);
  bool operator==(const QList<T> &l) const;
  inline bool operator!=(const QList<T> &l) const { return !(*this == l); }

  inline int size() const noexcept { return p.size(); }

  inline void detach() {
    if (d->ref.isShared())
      detach_helper();
  }

  inline void detachShared() {

    if (d->ref.isShared() && this->d != &QListData::shared_null)
      detach_helper();
  }

  inline bool isDetached() const { return !d->ref.isShared(); }

  inline void setSharable(bool sharable) {
    if (sharable == d->ref.isSharable())
      return;
    if (!sharable)
      detach();
    if (d != &QListData::shared_null)
      d->ref.setSharable(sharable);
  }

  inline bool isSharedWith(const QList<T> &other) const noexcept {
    return d == other.d;
  }

  inline bool isEmpty() const noexcept { return p.isEmpty(); }

  void clear();

  const T &at(int i) const;
  const T &operator[](int i) const;
  T &operator[](int i);

  void reserve(int size);
  void append(const T &t);
  void append(const QList<T> &t);
  void prepend(const T &t);
  void insert(int i, const T &t);
  void replace(int i, const T &t);
  void removeAt(int i);
  int removeAll(const T &t);
  bool removeOne(const T &t);
  T takeAt(int i);
  T takeFirst();
  T takeLast();
  void move(int from, int to);
  void swapItemsAt(int i, int j);

  __attribute__((__deprecated__("Use QList<T>::swapItemsAt()"))) void
  swap(int i, int j) {
    swapItemsAt(i, j);
  }

  int indexOf(const T &t, int from = 0) const;
  int lastIndexOf(const T &t, int from = -1) const;
  bool contains(const T &t) const;
  int count(const T &t) const;

  class const_iterator;

  class iterator {
  public:
    Node *i;
    typedef std::random_access_iterator_tag iterator_category;

    typedef qptrdiff difference_type;
    typedef T value_type;
    typedef T *pointer;
    typedef T &reference;

    inline iterator() noexcept : i(nullptr) {}
    inline iterator(Node *n) noexcept : i(n) {}

    inline iterator(const iterator &o) noexcept : i(o.i) {}
    inline iterator &operator=(const iterator &o) noexcept {
      i = o.i;
      return *this;
    }

    inline T &operator*() const { return i->t(); }
    inline T *operator->() const { return &i->t(); }
    inline T &operator[](difference_type j) const { return i[j].t(); }
    inline bool operator==(const iterator &o) const noexcept {
      return i == o.i;
    }
    inline bool operator!=(const iterator &o) const noexcept {
      return i != o.i;
    }
    inline bool operator<(const iterator &other) const noexcept {
      return i < other.i;
    }
    inline bool operator<=(const iterator &other) const noexcept {
      return i <= other.i;
    }
    inline bool operator>(const iterator &other) const noexcept {
      return i > other.i;
    }
    inline bool operator>=(const iterator &other) const noexcept {
      return i >= other.i;
    }

    inline bool operator==(const const_iterator &o) const noexcept {
      return i == o.i;
    }
    inline bool operator!=(const const_iterator &o) const noexcept {
      return i != o.i;
    }
    inline bool operator<(const const_iterator &other) const noexcept {
      return i < other.i;
    }
    inline bool operator<=(const const_iterator &other) const noexcept {
      return i <= other.i;
    }
    inline bool operator>(const const_iterator &other) const noexcept {
      return i > other.i;
    }
    inline bool operator>=(const const_iterator &other) const noexcept {
      return i >= other.i;
    }

    inline iterator &operator++() {
      ++i;
      return *this;
    }
    inline iterator operator++(int) {
      Node *n = i;
      ++i;
      return n;
    }
    inline iterator &operator--() {
      i--;
      return *this;
    }
    inline iterator operator--(int) {
      Node *n = i;
      i--;
      return n;
    }
    inline iterator &operator+=(difference_type j) {
      i += j;
      return *this;
    }
    inline iterator &operator-=(difference_type j) {
      i -= j;
      return *this;
    }
    inline iterator operator+(difference_type j) const {
      return iterator(i + j);
    }
    inline iterator operator-(difference_type j) const {
      return iterator(i - j);
    }
    friend inline iterator operator+(difference_type j, iterator k) {
      return k + j;
    }
    inline int operator-(iterator j) const { return int(i - j.i); }
  };
  friend class iterator;

  class const_iterator {
  public:
    Node *i;
    typedef std::random_access_iterator_tag iterator_category;

    typedef qptrdiff difference_type;
    typedef T value_type;
    typedef const T *pointer;
    typedef const T &reference;

    inline const_iterator() noexcept : i(nullptr) {}
    inline const_iterator(Node *n) noexcept : i(n) {}

    inline const_iterator(const const_iterator &o) noexcept : i(o.i) {}
    inline const_iterator &operator=(const const_iterator &o) noexcept {
      i = o.i;
      return *this;
    }

    inline const_iterator(const iterator &o) noexcept : i(o.i) {}

    inline const T &operator*() const { return i->t(); }
    inline const T *operator->() const { return &i->t(); }
    inline const T &operator[](difference_type j) const { return i[j].t(); }
    inline bool operator==(const const_iterator &o) const noexcept {
      return i == o.i;
    }
    inline bool operator!=(const const_iterator &o) const noexcept {
      return i != o.i;
    }
    inline bool operator<(const const_iterator &other) const noexcept {
      return i < other.i;
    }
    inline bool operator<=(const const_iterator &other) const noexcept {
      return i <= other.i;
    }
    inline bool operator>(const const_iterator &other) const noexcept {
      return i > other.i;
    }
    inline bool operator>=(const const_iterator &other) const noexcept {
      return i >= other.i;
    }
    inline const_iterator &operator++() {
      ++i;
      return *this;
    }
    inline const_iterator operator++(int) {
      Node *n = i;
      ++i;
      return n;
    }
    inline const_iterator &operator--() {
      i--;
      return *this;
    }
    inline const_iterator operator--(int) {
      Node *n = i;
      i--;
      return n;
    }
    inline const_iterator &operator+=(difference_type j) {
      i += j;
      return *this;
    }
    inline const_iterator &operator-=(difference_type j) {
      i -= j;
      return *this;
    }
    inline const_iterator operator+(difference_type j) const {
      return const_iterator(i + j);
    }
    inline const_iterator operator-(difference_type j) const {
      return const_iterator(i - j);
    }
    friend inline const_iterator operator+(difference_type j,
                                           const_iterator k) {
      return k + j;
    }
    inline int operator-(const_iterator j) const { return int(i - j.i); }
  };
  friend class const_iterator;

  typedef std::reverse_iterator<iterator> reverse_iterator;
  typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
  inline iterator begin() {
    detach();
    return reinterpret_cast<Node *>(p.begin());
  }
  inline const_iterator begin() const noexcept {
    return reinterpret_cast<Node *>(p.begin());
  }
  inline const_iterator cbegin() const noexcept {
    return reinterpret_cast<Node *>(p.begin());
  }
  inline const_iterator constBegin() const noexcept {
    return reinterpret_cast<Node *>(p.begin());
  }
  inline iterator end() {
    detach();
    return reinterpret_cast<Node *>(p.end());
  }
  inline const_iterator end() const noexcept {
    return reinterpret_cast<Node *>(p.end());
  }
  inline const_iterator cend() const noexcept {
    return reinterpret_cast<Node *>(p.end());
  }
  inline const_iterator constEnd() const noexcept {
    return reinterpret_cast<Node *>(p.end());
  }
  reverse_iterator rbegin() { return reverse_iterator(end()); }
  reverse_iterator rend() { return reverse_iterator(begin()); }
  const_reverse_iterator rbegin() const noexcept {
    return const_reverse_iterator(end());
  }
  const_reverse_iterator rend() const noexcept {
    return const_reverse_iterator(begin());
  }
  const_reverse_iterator crbegin() const noexcept {
    return const_reverse_iterator(end());
  }
  const_reverse_iterator crend() const noexcept {
    return const_reverse_iterator(begin());
  }
  iterator insert(iterator before, const T &t);
  iterator erase(iterator pos);
  iterator erase(iterator first, iterator last);

  typedef iterator Iterator;
  typedef const_iterator ConstIterator;
  inline int count() const { return p.size(); }
  inline int length() const { return p.size(); }
  inline T &first() {
    ((!isEmpty())
         ? static_cast<void>(0)
         : qt_assert("!isEmpty()", "/usr/local/include/QtCore/qlist.h", 361));
    return *begin();
  }
  inline const T &constFirst() const { return first(); }
  inline const T &first() const {
    ((!isEmpty())
         ? static_cast<void>(0)
         : qt_assert("!isEmpty()", "/usr/local/include/QtCore/qlist.h", 363));
    return at(0);
  }
  T &last() {
    ((!isEmpty())
         ? static_cast<void>(0)
         : qt_assert("!isEmpty()", "/usr/local/include/QtCore/qlist.h", 364));
    return *(--end());
  }
  const T &last() const {
    ((!isEmpty())
         ? static_cast<void>(0)
         : qt_assert("!isEmpty()", "/usr/local/include/QtCore/qlist.h", 365));
    return at(count() - 1);
  }
  inline const T &constLast() const { return last(); }
  inline void removeFirst() {
    ((!isEmpty())
         ? static_cast<void>(0)
         : qt_assert("!isEmpty()", "/usr/local/include/QtCore/qlist.h", 367));
    erase(begin());
  }
  inline void removeLast() {
    ((!isEmpty())
         ? static_cast<void>(0)
         : qt_assert("!isEmpty()", "/usr/local/include/QtCore/qlist.h", 368));
    erase(--end());
  }
  inline bool startsWith(const T &t) const {
    return !isEmpty() && first() == t;
  }
  inline bool endsWith(const T &t) const { return !isEmpty() && last() == t; }
  QList<T> mid(int pos, int length = -1) const;

  T value(int i) const;
  T value(int i, const T &defaultValue) const;

  inline void push_back(const T &t) { append(t); }
  inline void push_front(const T &t) { prepend(t); }
  inline T &front() { return first(); }
  inline const T &front() const { return first(); }
  inline T &back() { return last(); }
  inline const T &back() const { return last(); }
  inline void pop_front() { removeFirst(); }
  inline void pop_back() { removeLast(); }
  inline bool empty() const { return isEmpty(); }
  typedef int size_type;
  typedef T value_type;
  typedef value_type *pointer;
  typedef const value_type *const_pointer;
  typedef value_type &reference;
  typedef const value_type &const_reference;

  typedef qptrdiff difference_type;

  QList<T> &operator+=(const QList<T> &l);
  inline QList<T> operator+(const QList<T> &l) const {
    QList n = *this;
    n += l;
    return n;
  }
  inline QList<T> &operator+=(const T &t) {
    append(t);
    return *this;
  }
  inline QList<T> &operator<<(const T &t) {
    append(t);
    return *this;
  }
  inline QList<T> &operator<<(const QList<T> &l) {
    *this += l;
    return *this;
  }

  static QList<T> fromVector(const QVector<T> &vector);
  QVector<T> toVector() const;

  __attribute__((__deprecated__(
      "Use QList<T>(set.begin(), set.end()) instead."))) static QList<T>
  fromSet(const QSet<T> &set);
  __attribute__((
      __deprecated__("Use QSet<T>(list.begin(), list.end()) instead."))) QSet<T>
  toSet() const;

  __attribute__((__deprecated__("Use QList<T>(list.begin(), list.end()) "
                                "instead."))) static inline QList<T>
  fromStdList(const std::list<T> &list) {
    return QList<T>(list.begin(), list.end());
  }
  __attribute__((__deprecated__(
      "Use std::list<T>(list.begin(), list.end()) instead."))) inline std::
      list<T>
      toStdList() const {
    return std::list<T>(begin(), end());
  }

private:
  Node *detach_helper_grow(int i, int n);
  void detach_helper(int alloc);
  void detach_helper();
  void dealloc(QListData::Data *d);

  void node_construct(Node *n, const T &t);
  void node_destruct(Node *n);
  void node_copy(Node *from, Node *to, Node *src);
  void node_destruct(Node *from, Node *to);

  bool isValidIterator(const iterator &i) const noexcept {
    const std::less<const Node *> less = {};
    return !less(i.i, cbegin().i) && !less(cend().i, i.i);
  }

private:
  inline bool op_eq_impl(const QList &other,
                         QListData::NotArrayCompatibleLayout) const;
  inline bool op_eq_impl(const QList &other,
                         QListData::ArrayCompatibleLayout) const;
  inline bool contains_impl(const T &,
                            QListData::NotArrayCompatibleLayout) const;
  inline bool contains_impl(const T &, QListData::ArrayCompatibleLayout) const;
  inline int count_impl(const T &, QListData::NotArrayCompatibleLayout) const;
  inline int count_impl(const T &, QListData::ArrayCompatibleLayout) const;
};
template <typename T>
inline void QList<T>::node_construct(Node *n, const T &t) {
  if (QTypeInfo<T>::isLarge || QTypeInfo<T>::isStatic)
    n->v = new T(t);
  else if (QTypeInfo<T>::isComplex)
    new (n) T(t);

  else
    ::memcpy(n, static_cast<const void *>(&t), sizeof(T));
}

template <typename T> inline void QList<T>::node_destruct(Node *n) {
  if (QTypeInfo<T>::isLarge || QTypeInfo<T>::isStatic)
    delete reinterpret_cast<T *>(n->v);
  else if (QTypeInfo<T>::isComplex)
    reinterpret_cast<T *>(n)->~T();
}

template <typename T>
inline void QList<T>::node_copy(Node *from, Node *to, Node *src) {
  Node *current = from;
  if (QTypeInfo<T>::isLarge || QTypeInfo<T>::isStatic) {
    try {
      while (current != to) {
        current->v = new T(*reinterpret_cast<T *>(src->v));
        ++current;
        ++src;
      }
    } catch (...) {
      while (current-- != from)
        delete reinterpret_cast<T *>(current->v);
      throw;
    }

  } else if (QTypeInfo<T>::isComplex) {
    try {
      while (current != to) {
        new (current) T(*reinterpret_cast<T *>(src));
        ++current;
        ++src;
      }
    } catch (...) {
      while (current-- != from)
        (reinterpret_cast<T *>(current))->~T();
      throw;
    }
  } else {
    if (src != from && to - from > 0)
      memcpy(from, src, (to - from) * sizeof(Node));
  }
}

template <typename T>
inline void QList<T>::node_destruct(Node *from, Node *to) {
  if (QTypeInfo<T>::isLarge || QTypeInfo<T>::isStatic)
    while (from != to)
      --to, delete reinterpret_cast<T *>(to->v);
  else if (QTypeInfo<T>::isComplex)
    while (from != to)
      --to, reinterpret_cast<T *>(to)->~T();
}

template <typename T> inline QList<T> &QList<T>::operator=(const QList<T> &l) {
  if (d != l.d) {
    QList<T> tmp(l);
    tmp.swap(*this);
  }
  return *this;
}
template <typename T>
inline typename QList<T>::iterator QList<T>::insert(iterator before,
                                                    const T &t) {
  ((isValidIterator(before))
       ? static_cast<void>(0)
       : qt_assert_x("QList::insert",
                     "The specified iterator argument 'before' is invalid",
                     "/usr/local/include/QtCore/qlist.h", 541));

  int iBefore = int(before.i - reinterpret_cast<Node *>(p.begin()));
  Node *n = nullptr;
  if (d->ref.isShared())
    n = detach_helper_grow(iBefore, 1);
  else
    n = reinterpret_cast<Node *>(p.insert(iBefore));
  try {
    node_construct(n, t);
  } catch (...) {
    p.remove(iBefore);
    throw;
  }
  return n;
}
template <typename T>
inline typename QList<T>::iterator QList<T>::erase(iterator it) {
  ((isValidIterator(it))
       ? static_cast<void>(0)
       : qt_assert_x("QList::erase",
                     "The specified iterator argument 'it' is invalid",
                     "/usr/local/include/QtCore/qlist.h", 560));
  if (d->ref.isShared()) {
    int offset = int(it.i - reinterpret_cast<Node *>(p.begin()));
    it = begin();
    it += offset;
  }
  node_destruct(it.i);
  return reinterpret_cast<Node *>(p.erase(reinterpret_cast<void **>(it.i)));
}
template <typename T> inline const T &QList<T>::at(int i) const {
  ((i >= 0 && i < p.size())
       ? static_cast<void>(0)
       : qt_assert_x("QList<T>::at", "index out of range",
                     "/usr/local/include/QtCore/qlist.h", 571));
  return reinterpret_cast<Node *>(p.at(i))->t();
}
template <typename T> inline const T &QList<T>::operator[](int i) const {
  ((i >= 0 && i < p.size())
       ? static_cast<void>(0)
       : qt_assert_x("QList<T>::operator[]", "index out of range",
                     "/usr/local/include/QtCore/qlist.h", 575));
  return reinterpret_cast<Node *>(p.at(i))->t();
}
template <typename T> inline T &QList<T>::operator[](int i) {
  ((i >= 0 && i < p.size())
       ? static_cast<void>(0)
       : qt_assert_x("QList<T>::operator[]", "index out of range",
                     "/usr/local/include/QtCore/qlist.h", 579));
  detach();
  return reinterpret_cast<Node *>(p.at(i))->t();
}
template <typename T> inline void QList<T>::removeAt(int i) {

  if (i < 0 || i >= p.size()) {

    QMessageLogger(
        static_cast<const char *>("/usr/local/include/QtCore/qlist.h"), 589,
        static_cast<const char *>(__PRETTY_FUNCTION__))
        .warning("QList::removeAt(): Index out of range.");

    return;
  }
  detach();
  node_destruct(reinterpret_cast<Node *>(p.at(i)));
  p.remove(i);
}
template <typename T> inline T QList<T>::takeAt(int i) {
  ((i >= 0 && i < p.size())
       ? static_cast<void>(0)
       : qt_assert_x("QList<T>::take", "index out of range",
                     "/usr/local/include/QtCore/qlist.h", 598));
  detach();
  Node *n = reinterpret_cast<Node *>(p.at(i));
  T t = std::move(n->t());
  node_destruct(n);
  p.remove(i);
  return t;
}
template <typename T> inline T QList<T>::takeFirst() {
  T t = std::move(first());
  removeFirst();
  return t;
}
template <typename T> inline T QList<T>::takeLast() {
  T t = std::move(last());
  removeLast();
  return t;
}

template <typename T> void QList<T>::reserve(int alloc) {
  if (d->alloc < alloc) {
    if (d->ref.isShared())
      detach_helper(alloc);
    else
      p.realloc(alloc);
  }
}

template <typename T> void QList<T>::append(const T &t) {
  if (d->ref.isShared()) {
    Node *n = detach_helper_grow(2147483647, 1);
    try {
      node_construct(n, t);
    } catch (...) {
      --d->end;
      throw;
    }
  } else {
    if (QTypeInfo<T>::isLarge || QTypeInfo<T>::isStatic) {
      Node *n = reinterpret_cast<Node *>(p.append());
      try {
        node_construct(n, t);
      } catch (...) {
        --d->end;
        throw;
      }
    } else {
      Node *n, copy;
      node_construct(&copy, t);
      try {
        n = reinterpret_cast<Node *>(p.append());
        ;
      } catch (...) {
        node_destruct(&copy);
        throw;
      }
      *n = copy;
    }
  }
}

template <typename T> inline void QList<T>::prepend(const T &t) {
  if (d->ref.isShared()) {
    Node *n = detach_helper_grow(0, 1);
    try {
      node_construct(n, t);
    } catch (...) {
      ++d->begin;
      throw;
    }
  } else {
    if (QTypeInfo<T>::isLarge || QTypeInfo<T>::isStatic) {
      Node *n = reinterpret_cast<Node *>(p.prepend());
      try {
        node_construct(n, t);
      } catch (...) {
        ++d->begin;
        throw;
      }
    } else {
      Node *n, copy;
      node_construct(&copy, t);
      try {
        n = reinterpret_cast<Node *>(p.prepend());
        ;
      } catch (...) {
        node_destruct(&copy);
        throw;
      }
      *n = copy;
    }
  }
}

template <typename T> inline void QList<T>::insert(int i, const T &t) {

  if (i < 0 || i > p.size())
    QMessageLogger(
        static_cast<const char *>("/usr/local/include/QtCore/qlist.h"), 694,
        static_cast<const char *>(__PRETTY_FUNCTION__))
        .warning("QList::insert(): Index out of range.");

  if (d->ref.isShared()) {
    Node *n = detach_helper_grow(i, 1);
    try {
      node_construct(n, t);
    } catch (...) {
      p.remove(i);
      throw;
    }
  } else {
    if (QTypeInfo<T>::isLarge || QTypeInfo<T>::isStatic) {
      Node *n = reinterpret_cast<Node *>(p.insert(i));
      try {
        node_construct(n, t);
      } catch (...) {
        p.remove(i);
        throw;
      }
    } else {
      Node *n, copy;
      node_construct(&copy, t);
      try {
        n = reinterpret_cast<Node *>(p.insert(i));
        ;
      } catch (...) {
        node_destruct(&copy);
        throw;
      }
      *n = copy;
    }
  }
}

template <typename T> inline void QList<T>::replace(int i, const T &t) {
  ((i >= 0 && i < p.size())
       ? static_cast<void>(0)
       : qt_assert_x("QList<T>::replace", "index out of range",
                     "/usr/local/include/QtCore/qlist.h", 730));
  detach();
  reinterpret_cast<Node *>(p.at(i))->t() = t;
}

template <typename T> inline void QList<T>::swapItemsAt(int i, int j) {
  ((i >= 0 && i < p.size() && j >= 0 && j < p.size())
       ? static_cast<void>(0)
       : qt_assert_x("QList<T>::swap", "index out of range",
                     "/usr/local/include/QtCore/qlist.h", 739));

  detach();
  qSwap(d->array[d->begin + i], d->array[d->begin + j]);
}

template <typename T> inline void QList<T>::move(int from, int to) {
  ((from >= 0 && from < p.size() && to >= 0 && to < p.size())
       ? static_cast<void>(0)
       : qt_assert_x("QList<T>::move", "index out of range",
                     "/usr/local/include/QtCore/qlist.h", 748));

  detach();
  p.move(from, to);
}

template <typename T> QList<T> QList<T>::mid(int pos, int alength) const {
  using namespace QtPrivate;
  switch (QContainerImplHelper::mid(size(), &pos, &alength)) {
  case QContainerImplHelper::Null:
  case QContainerImplHelper::Empty:
    return QList<T>();
  case QContainerImplHelper::Full:
    return *this;
  case QContainerImplHelper::Subset:
    break;
  }

  QList<T> cpy;
  if (alength <= 0)
    return cpy;
  cpy.reserve(alength);
  cpy.d->end = alength;
  try {
    cpy.node_copy(reinterpret_cast<Node *>(cpy.p.begin()),
                  reinterpret_cast<Node *>(cpy.p.end()),
                  reinterpret_cast<Node *>(p.begin() + pos));
  } catch (...) {

    cpy.d->end = 0;
    throw;
  }
  return cpy;
}

template <typename T> T QList<T>::value(int i) const {
  if (i < 0 || i >= p.size()) {
    return T();
  }
  return reinterpret_cast<Node *>(p.at(i))->t();
}

template <typename T> T QList<T>::value(int i, const T &defaultValue) const {
  return ((i < 0 || i >= p.size()) ? defaultValue
                                   : reinterpret_cast<Node *>(p.at(i))->t());
}

template <typename T>
typename QList<T>::Node *QList<T>::detach_helper_grow(int i, int c) {
  Node *n = reinterpret_cast<Node *>(p.begin());
  QListData::Data *x = p.detach_grow(&i, c);
  try {
    node_copy(reinterpret_cast<Node *>(p.begin()),
              reinterpret_cast<Node *>(p.begin() + i), n);
  } catch (...) {
    p.dispose();
    d = x;
    throw;
  }
  try {
    node_copy(reinterpret_cast<Node *>(p.begin() + i + c),
              reinterpret_cast<Node *>(p.end()), n + i);
  } catch (...) {
    node_destruct(reinterpret_cast<Node *>(p.begin()),
                  reinterpret_cast<Node *>(p.begin() + i));
    p.dispose();
    d = x;
    throw;
  }

  if (!x->ref.deref())
    dealloc(x);

  return reinterpret_cast<Node *>(p.begin() + i);
}

template <typename T> void QList<T>::detach_helper(int alloc) {
  Node *n = reinterpret_cast<Node *>(p.begin());
  QListData::Data *x = p.detach(alloc);
  try {
    node_copy(reinterpret_cast<Node *>(p.begin()),
              reinterpret_cast<Node *>(p.end()), n);
  } catch (...) {
    p.dispose();
    d = x;
    throw;
  }

  if (!x->ref.deref())
    dealloc(x);
}

template <typename T> void QList<T>::detach_helper() {
  detach_helper(d->alloc);
}

template <typename T>
QList<T>::QList(const QList<T> &l) : QListSpecialMethods<T>(l), d(l.d) {
  if (!d->ref.ref()) {
    p.detach(d->alloc);

    try {
      node_copy(reinterpret_cast<Node *>(p.begin()),
                reinterpret_cast<Node *>(p.end()),
                reinterpret_cast<Node *>(l.p.begin()));
    } catch (...) {
      QListData::dispose(d);
      throw;
    }
  }
}

template <typename T> QList<T>::~QList() {
  if (!d->ref.deref())
    dealloc(d);
}

template <typename T>
template <typename InputIterator, QtPrivate::IfIsInputIterator<InputIterator>>
QList<T>::QList(InputIterator first, InputIterator last) : QList() {
  QtPrivate::reserveIfForwardIterator(this, first, last);
  std::copy(first, last, std::back_inserter(*this));
}

template <typename T> bool QList<T>::operator==(const QList<T> &l) const {
  if (d == l.d)
    return true;
  if (p.size() != l.p.size())
    return false;
  return this->op_eq_impl(l, MemoryLayout());
}

template <typename T>
inline bool QList<T>::op_eq_impl(const QList &l,
                                 QListData::NotArrayCompatibleLayout) const {
  Node *i = reinterpret_cast<Node *>(p.begin());
  Node *e = reinterpret_cast<Node *>(p.end());
  Node *li = reinterpret_cast<Node *>(l.p.begin());
  for (; i != e; ++i, ++li) {
    if (!(i->t() == li->t()))
      return false;
  }
  return true;
}

template <typename T>
inline bool QList<T>::op_eq_impl(const QList &l,
                                 QListData::ArrayCompatibleLayout) const {
  const T *lb = reinterpret_cast<const T *>(l.p.begin());
  const T *b = reinterpret_cast<const T *>(p.begin());
  const T *e = reinterpret_cast<const T *>(p.end());
  return std::equal(b, e, (lb));
}

template <typename T> void QList<T>::dealloc(QListData::Data *data) {
  node_destruct(reinterpret_cast<Node *>(data->array + data->begin),
                reinterpret_cast<Node *>(data->array + data->end));
  QListData::dispose(data);
}

template <typename T> void QList<T>::clear() { *this = QList<T>(); }

template <typename T> int QList<T>::removeAll(const T &_t) {
  int index = indexOf(_t);
  if (index == -1)
    return 0;

  const T t = _t;
  detach();

  Node *i = reinterpret_cast<Node *>(p.at(index));
  Node *e = reinterpret_cast<Node *>(p.end());
  Node *n = i;
  node_destruct(i);
  while (++i != e) {
    if (i->t() == t)
      node_destruct(i);
    else
      *n++ = *i;
  }

  int removedCount = int(e - n);
  d->end -= removedCount;
  return removedCount;
}

template <typename T> bool QList<T>::removeOne(const T &_t) {
  int index = indexOf(_t);
  if (index != -1) {
    removeAt(index);
    return true;
  }
  return false;
}

template <typename T>
typename QList<T>::iterator QList<T>::erase(typename QList<T>::iterator afirst,
                                            typename QList<T>::iterator alast) {
  ((isValidIterator(afirst))
       ? static_cast<void>(0)
       : qt_assert_x("QList::erase",
                     "The specified iterator argument 'afirst' is invalid",
                     "/usr/local/include/QtCore/qlist.h", 974));
  ((isValidIterator(alast))
       ? static_cast<void>(0)
       : qt_assert_x("QList::erase",
                     "The specified iterator argument 'alast' is invalid",
                     "/usr/local/include/QtCore/qlist.h", 975));

  if (d->ref.isShared()) {

    int offsetfirst = int(afirst.i - reinterpret_cast<Node *>(p.begin()));
    int offsetlast = int(alast.i - reinterpret_cast<Node *>(p.begin()));
    afirst = begin();
    alast = afirst;
    afirst += offsetfirst;
    alast += offsetlast;
  }

  for (Node *n = afirst.i; n < alast.i; ++n)
    node_destruct(n);
  int idx = afirst - begin();
  p.remove(idx, alast - afirst);
  return begin() + idx;
}

template <typename T> QList<T> &QList<T>::operator+=(const QList<T> &l) {
  if (!l.isEmpty()) {
    if (d == &QListData::shared_null) {
      *this = l;
    } else {
      Node *n = (d->ref.isShared()) ? detach_helper_grow(2147483647, l.size())
                                    : reinterpret_cast<Node *>(p.append(l.p));
      try {
        node_copy(n, reinterpret_cast<Node *>(p.end()),
                  reinterpret_cast<Node *>(l.p.begin()));
      } catch (...) {

        d->end -= int(reinterpret_cast<Node *>(p.end()) - n);
        throw;
      }
    }
  }
  return *this;
}

template <typename T> inline void QList<T>::append(const QList<T> &t) {
  *this += t;
}

template <typename T> int QList<T>::indexOf(const T &t, int from) const {
  return QtPrivate::indexOf<T, T>(*this, t, from);
}

namespace QtPrivate {
template <typename T, typename U>
int indexOf(const QList<T> &list, const U &u, int from) {
  typedef typename QList<T>::Node Node;

  if (from < 0)
    from = qMax(from + list.p.size(), 0);
  if (from < list.p.size()) {
    Node *n = reinterpret_cast<Node *>(list.p.at(from - 1));
    Node *e = reinterpret_cast<Node *>(list.p.end());
    while (++n != e)
      if (n->t() == u)
        return int(n - reinterpret_cast<Node *>(list.p.begin()));
  }
  return -1;
}
} // namespace QtPrivate

template <typename T> int QList<T>::lastIndexOf(const T &t, int from) const {
  return QtPrivate::lastIndexOf<T, T>(*this, t, from);
}

namespace QtPrivate {
template <typename T, typename U>
int lastIndexOf(const QList<T> &list, const U &u, int from) {
  typedef typename QList<T>::Node Node;

  if (from < 0)
    from += list.p.size();
  else if (from >= list.p.size())
    from = list.p.size() - 1;
  if (from >= 0) {
    Node *b = reinterpret_cast<Node *>(list.p.begin());
    Node *n = reinterpret_cast<Node *>(list.p.at(from + 1));
    while (n-- != b) {
      if (n->t() == u)
        return int(n - b);
    }
  }
  return -1;
}
} // namespace QtPrivate

template <typename T> bool QList<T>::contains(const T &t) const {
  return contains_impl(t, MemoryLayout());
}

template <typename T>
inline bool QList<T>::contains_impl(const T &t,
                                    QListData::NotArrayCompatibleLayout) const {
  Node *e = reinterpret_cast<Node *>(p.end());
  Node *i = reinterpret_cast<Node *>(p.begin());
  for (; i != e; ++i)
    if (i->t() == t)
      return true;
  return false;
}

template <typename T>
inline bool QList<T>::contains_impl(const T &t,
                                    QListData::ArrayCompatibleLayout) const {
  const T *b = reinterpret_cast<const T *>(p.begin());
  const T *e = reinterpret_cast<const T *>(p.end());
  return std::find(b, e, t) != e;
}

template <typename T> int QList<T>::count(const T &t) const {
  return this->count_impl(t, MemoryLayout());
}

template <typename T>
inline int QList<T>::count_impl(const T &t,
                                QListData::NotArrayCompatibleLayout) const {
  int c = 0;
  Node *e = reinterpret_cast<Node *>(p.end());
  Node *i = reinterpret_cast<Node *>(p.begin());
  for (; i != e; ++i)
    if (i->t() == t)
      ++c;
  return c;
}

template <typename T>
inline int QList<T>::count_impl(const T &t,
                                QListData::ArrayCompatibleLayout) const {
  return int(std::count(reinterpret_cast<const T *>(p.begin()),
                        reinterpret_cast<const T *>(p.end()), t));
}

template <typename T> QVector<T> QList<T>::toVector() const {
  return QVector<T>(begin(), end());
}

template <typename T> QList<T> QList<T>::fromVector(const QVector<T> &vector) {
  return vector.toList();
}

template <typename T> QList<T> QVector<T>::toList() const {
  return QList<T>(begin(), end());
}

template <typename T> QVector<T> QVector<T>::fromList(const QList<T> &list) {
  return list.toVector();
}

template <class T> class QListIterator {
  typedef typename QList<T>::const_iterator const_iterator;
  QList<T> c;
  const_iterator i;
public:
  inline QListIterator(const QList<T> &container)
      : c(container), i(c.constBegin()) {}
  inline QListIterator &operator=(const QList<T> &container) {
    c = container;
    i = c.constBegin();
    return *this;
  }
  inline void toFront() { i = c.constBegin(); }
  inline void toBack() { i = c.constEnd(); }
  inline bool hasNext() const { return i != c.constEnd(); }
  inline const T &next() { return *i++; }
  inline const T &peekNext() const { return *i; }
  inline bool hasPrevious() const { return i != c.constBegin(); }
  inline const T &previous() { return *--i; }
  inline const T &peekPrevious() const {
    const_iterator p = i;
    return *--p;
  }
  inline bool findNext(const T &t) {
    while (i != c.constEnd())
      if (*i++ == t)
        return true;
    return false;
  }
  inline bool findPrevious(const T &t) {
    while (i != c.constBegin())
      if (*(--i) == t)
        return true;
    return false;
  }
};
template <class T> class QMutableListIterator {
  typedef typename QList<T>::iterator iterator;
  typedef typename QList<T>::const_iterator const_iterator;
  QList<T> *c;
  iterator i, n;
  inline bool item_exists() const { return const_iterator(n) != c->constEnd(); }
public:
  inline QMutableListIterator(QList<T> &container) : c(&container) {
    i = c->begin();
    n = c->end();
  }
  inline QMutableListIterator &operator=(QList<T> &container) {
    c = &container;
    i = c->begin();
    n = c->end();
    return *this;
  }
  inline void toFront() {
    i = c->begin();
    n = c->end();
  }
  inline void toBack() {
    i = c->end();
    n = i;
  }
  inline bool hasNext() const { return c->constEnd() != const_iterator(i); }
  inline T &next() {
    n = i++;
    return *n;
  }
  inline T &peekNext() const { return *i; }
  inline bool hasPrevious() const {
    return c->constBegin() != const_iterator(i);
  }
  inline T &previous() {
    n = --i;
    return *n;
  }
  inline T &peekPrevious() const {
    iterator p = i;
    return *--p;
  }
  inline void remove() {
    if (c->constEnd() != const_iterator(n)) {
      i = c->erase(n);
      n = c->end();
    }
  }
  inline void setValue(const T &t) const {
    if (c->constEnd() != const_iterator(n))
      *n = t;
  }
  inline T &value() {
    ((item_exists()) ? static_cast<void>(0)
                     : qt_assert("item_exists()",
                                 "/usr/local/include/QtCore/qlist.h", 1154));
    return *n;
  }
  inline const T &value() const {
    ((item_exists()) ? static_cast<void>(0)
                     : qt_assert("item_exists()",
                                 "/usr/local/include/QtCore/qlist.h", 1154));
    return *n;
  }
  inline void insert(const T &t) {
    n = i = c->insert(i, t);
    ++i;
  }
  inline bool findNext(const T &t) {
    while (c->constEnd() != const_iterator(n = i))
      if (*i++ == t)
        return true;
    return false;
  }
  inline bool findPrevious(const T &t) {
    while (c->constBegin() != const_iterator(i))
      if (*(n = --i) == t)
        return true;
    n = c->end();
    return false;
  }
};

template <typename T>
uint qHash(const QList<T> &key,
           uint seed = 0) noexcept(noexcept(qHashRange(key.cbegin(), key.cend(),
                                                       seed))) {
  return qHashRange(key.cbegin(), key.cend(), seed);
}

template <typename T>
bool operator<(const QList<T> &lhs, const QList<T> &rhs) noexcept(
    noexcept(std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
                                          rhs.end()))) {
  return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
                                      rhs.end());
}

template <typename T>
inline bool operator>(const QList<T> &lhs,
                      const QList<T> &rhs) noexcept(noexcept(lhs < rhs)) {
  return rhs < lhs;
}

template <typename T>
inline bool operator<=(const QList<T> &lhs,
                       const QList<T> &rhs) noexcept(noexcept(lhs < rhs)) {
  return !(lhs > rhs);
}

template <typename T>
inline bool operator>=(const QList<T> &lhs,
                       const QList<T> &rhs) noexcept(noexcept(lhs < rhs)) {
  return !(lhs < rhs);
}

typedef QListIterator<QByteArray> QByteArrayListIterator;
typedef QMutableListIterator<QByteArray> QMutableByteArrayListIterator;

typedef QList<QByteArray> QByteArrayList;

namespace QtPrivate {
QByteArray __attribute__((visibility("default")))
QByteArrayList_join(const QByteArrayList *that, const char *separator,
                    int separatorLength);
int __attribute__((visibility("default")))
QByteArrayList_indexOf(const QByteArrayList *that, const char *needle,
                       int from);
} // namespace QtPrivate

template <>
struct QListSpecialMethods<QByteArray>

{

protected:
  ~QListSpecialMethods() = default;

public:
  inline QByteArray join() const {
    return QtPrivate::QByteArrayList_join(self(), nullptr, 0);
  }
  inline QByteArray join(const QByteArray &sep) const {
    return QtPrivate::QByteArrayList_join(self(), sep.constData(), sep.size());
  }
  inline QByteArray join(char sep) const {
    return QtPrivate::QByteArrayList_join(self(), &sep, 1);
  }

  inline int indexOf(const char *needle, int from = 0) const {
    return QtPrivate::QByteArrayList_indexOf(self(), needle, from);
  }

private:
  typedef QList<QByteArray> Self;
  Self *self() { return static_cast<Self *>(this); }
  const Self *self() const { return static_cast<const Self *>(this); }
};

struct QRegExpPrivate;
class QStringList;
class QRegExp;

__attribute__((visibility("default"))) uint qHash(const QRegExp &key,
                                                  uint seed = 0) noexcept;

class __attribute__((visibility("default"))) QRegExp {
public:
  enum PatternSyntax {
    RegExp,
    Wildcard,
    FixedString,
    RegExp2,
    WildcardUnix,
    W3CXmlSchema11
  };
  enum CaretMode { CaretAtZero, CaretAtOffset, CaretWontMatch };

  QRegExp();
  explicit QRegExp(const QString &pattern,
                   Qt::CaseSensitivity cs = Qt::CaseSensitive,
                   PatternSyntax syntax = RegExp);
  QRegExp(const QRegExp &rx);
  ~QRegExp();
  QRegExp &operator=(const QRegExp &rx);
  QRegExp &operator=(QRegExp &&other) noexcept {
    swap(other);
    return *this;
  }
  void swap(QRegExp &other) noexcept { qSwap(priv, other.priv); }

  bool operator==(const QRegExp &rx) const;
  inline bool operator!=(const QRegExp &rx) const { return !operator==(rx); }

  bool isEmpty() const;
  bool isValid() const;
  QString pattern() const;
  void setPattern(const QString &pattern);
  Qt::CaseSensitivity caseSensitivity() const;
  void setCaseSensitivity(Qt::CaseSensitivity cs);
  PatternSyntax patternSyntax() const;
  void setPatternSyntax(PatternSyntax syntax);

  bool isMinimal() const;
  void setMinimal(bool minimal);

  bool exactMatch(const QString &str) const;

  int indexIn(const QString &str, int offset = 0,
              CaretMode caretMode = CaretAtZero) const;
  int lastIndexIn(const QString &str, int offset = -1,
                  CaretMode caretMode = CaretAtZero) const;
  int matchedLength() const;

  int captureCount() const;
  QStringList capturedTexts() const;
  QStringList capturedTexts();
  QString cap(int nth = 0) const;
  QString cap(int nth = 0);
  int pos(int nth = 0) const;
  int pos(int nth = 0);
  QString errorString() const;
  QString errorString();

  static QString escape(const QString &str);

  friend __attribute__((visibility("default"))) uint qHash(const QRegExp &key,
                                                           uint seed) noexcept;

private:
  QRegExpPrivate *priv;
};

template <> class QTypeInfo<QRegExp> {
public:
  enum {
    isSpecialized = true,
    isComplex =
        (((Q_MOVABLE_TYPE)&Q_PRIMITIVE_TYPE) == 0) && !qIsTrivial<QRegExp>(),
    isStatic = (((Q_MOVABLE_TYPE) & (Q_MOVABLE_TYPE | Q_PRIMITIVE_TYPE)) == 0),
    isRelocatable = !isStatic || ((Q_MOVABLE_TYPE)&Q_RELOCATABLE_TYPE) ||
                    qIsRelocatable<QRegExp>(),
    isLarge = (sizeof(QRegExp) > sizeof(void *)),
    isPointer = false,
    isIntegral = std::is_integral<QRegExp>::value,
    isDummy = (((Q_MOVABLE_TYPE)&Q_DUMMY_TYPE) != 0),
    sizeOf = sizeof(QRegExp)
  };
  static inline const char *name() { return "QRegExp"; }
};

__attribute__((visibility("default"))) QDataStream &
operator<<(QDataStream &out, const QRegExp &regExp);
__attribute__((visibility("default"))) QDataStream &operator>>(QDataStream &in,
                                                               QRegExp &regExp);

__attribute__((visibility("default"))) QDebug operator<<(QDebug,
                                                         const QRegExp &);

class QStringMatcherPrivate;

class __attribute__((visibility("default"))) QStringMatcher {
public:
  QStringMatcher();
  explicit QStringMatcher(const QString &pattern,
                          Qt::CaseSensitivity cs = Qt::CaseSensitive);
  QStringMatcher(const QChar *uc, int len,
                 Qt::CaseSensitivity cs = Qt::CaseSensitive);
  QStringMatcher(QStringView pattern,
                 Qt::CaseSensitivity cs = Qt::CaseSensitive);
  QStringMatcher(const QStringMatcher &other);
  ~QStringMatcher();

  QStringMatcher &operator=(const QStringMatcher &other);

  void setPattern(const QString &pattern);
  void setCaseSensitivity(Qt::CaseSensitivity cs);

  int indexIn(const QString &str, int from = 0) const;
  int indexIn(const QChar *str, int length, int from = 0) const;
  qsizetype indexIn(QStringView str, qsizetype from = 0) const;
  QString pattern() const;
  inline Qt::CaseSensitivity caseSensitivity() const { return q_cs; }

private:
  QStringMatcherPrivate *d_ptr;
  QString q_pattern;
  Qt::CaseSensitivity q_cs;
  struct Data {
    uchar q_skiptable[256];
    const QChar *uc;
    int len;
  };
  union {
    uint q_data[256];
    Data p;
  };
};

class QRegExp;
class QRegularExpression;

typedef QListIterator<QString> QStringListIterator;
typedef QMutableListIterator<QString> QMutableStringListIterator;

class QStringList;

template <>
struct QListSpecialMethods<QString>

{

protected:
  ~QListSpecialMethods() = default;

public:
  inline void sort(Qt::CaseSensitivity cs = Qt::CaseSensitive);
  inline int removeDuplicates();

  inline QString join(const QString &sep) const;

  inline QString join(QStringView sep) const;
  inline QString join(QLatin1String sep) const;
  inline QString join(QChar sep) const;

  inline QStringList filter(QStringView str,
                            Qt::CaseSensitivity cs = Qt::CaseSensitive) const;
  inline QStringList &
  replaceInStrings(QStringView before, QStringView after,
                   Qt::CaseSensitivity cs = Qt::CaseSensitive);

  inline QStringList filter(const QString &str,
                            Qt::CaseSensitivity cs = Qt::CaseSensitive) const;
  inline QStringList &
  replaceInStrings(const QString &before, const QString &after,
                   Qt::CaseSensitivity cs = Qt::CaseSensitive);
  inline QStringList &
  replaceInStrings(const QString &before, QStringView after,
                   Qt::CaseSensitivity cs = Qt::CaseSensitive);
  inline QStringList &
  replaceInStrings(QStringView before, const QString &after,
                   Qt::CaseSensitivity cs = Qt::CaseSensitive);

  inline QStringList filter(const QRegExp &rx) const;
  inline QStringList &replaceInStrings(const QRegExp &rx, const QString &after);

  inline QStringList filter(const QRegularExpression &re) const;
  inline QStringList &replaceInStrings(const QRegularExpression &re,
                                       const QString &after);

private:
  inline QStringList *self();
  inline const QStringList *self() const;
};

class QStringList : public QList<QString> {

public:
  inline QStringList() noexcept {}
  inline explicit QStringList(const QString &i) { append(i); }
  inline QStringList(const QList<QString> &l) : QList<QString>(l) {}
  inline QStringList(QList<QString> &&l) noexcept
      : QList<QString>(std::move(l)) {}
  inline QStringList(std::initializer_list<QString> args)
      : QList<QString>(args) {}
  template <typename InputIterator,
            QtPrivate::IfIsInputIterator<InputIterator> = true>
  inline QStringList(InputIterator first, InputIterator last)
      : QList<QString>(first, last) {}

  QStringList &operator=(const QList<QString> &other) {
    QList<QString>::operator=(other);
    return *this;
  }
  QStringList &operator=(QList<QString> &&other) noexcept {
    QList<QString>::operator=(std::move(other));
    return *this;
  }

  inline bool contains(const QString &str,
                       Qt::CaseSensitivity cs = Qt::CaseSensitive) const;

  inline bool contains(QLatin1String str,
                       Qt::CaseSensitivity cs = Qt::CaseSensitive) const;
  inline bool contains(QStringView str,
                       Qt::CaseSensitivity cs = Qt::CaseSensitive) const;

  inline QStringList operator+(const QStringList &other) const {
    QStringList n = *this;
    n += other;
    return n;
  }
  inline QStringList &operator<<(const QString &str) {
    append(str);
    return *this;
  }
  inline QStringList &operator<<(const QStringList &l) {
    *this += l;
    return *this;
  }
  inline QStringList &operator<<(const QList<QString> &l) {
    *this += l;
    return *this;
  }

  inline int indexOf(QStringView str, int from = 0) const;
  inline int indexOf(QLatin1String str, int from = 0) const;

  inline int lastIndexOf(QStringView str, int from = -1) const;
  inline int lastIndexOf(QLatin1String str, int from = -1) const;

  inline int indexOf(const QRegExp &rx, int from = 0) const;
  inline int lastIndexOf(const QRegExp &rx, int from = -1) const;
  inline int indexOf(QRegExp &rx, int from = 0) const;
  inline int lastIndexOf(QRegExp &rx, int from = -1) const;

  inline int indexOf(const QRegularExpression &re, int from = 0) const;
  inline int lastIndexOf(const QRegularExpression &re, int from = -1) const;

  using QList<QString>::indexOf;
  using QList<QString>::lastIndexOf;
};

template <> class QTypeInfo<QStringList> {
public:
  enum {
    isSpecialized = true,
    isComplex = (((Q_MOVABLE_TYPE)&Q_PRIMITIVE_TYPE) == 0) &&
                !qIsTrivial<QStringList>(),
    isStatic = (((Q_MOVABLE_TYPE) & (Q_MOVABLE_TYPE | Q_PRIMITIVE_TYPE)) == 0),
    isRelocatable = !isStatic || ((Q_MOVABLE_TYPE)&Q_RELOCATABLE_TYPE) ||
                    qIsRelocatable<QStringList>(),
    isLarge = (sizeof(QStringList) > sizeof(void *)),
    isPointer = false,
    isIntegral = std::is_integral<QStringList>::value,
    isDummy = (((Q_MOVABLE_TYPE)&Q_DUMMY_TYPE) != 0),
    sizeOf = sizeof(QStringList)
  };
  static inline const char *name() { return "QStringList"; }
};

inline QStringList *QListSpecialMethods<QString>::self() {
  return static_cast<QStringList *>(this);
}
inline const QStringList *QListSpecialMethods<QString>::self() const {
  return static_cast<const QStringList *>(this);
}

namespace QtPrivate {
void __attribute__((visibility("default")))
QStringList_sort(QStringList *that, Qt::CaseSensitivity cs);
int __attribute__((visibility("default")))
QStringList_removeDuplicates(QStringList *that);
QString __attribute__((visibility("default")))
QStringList_join(const QStringList *that, QStringView sep);
QString __attribute__((visibility("default")))
QStringList_join(const QStringList *that, const QChar *sep, int seplen);
__attribute__((visibility("default"))) QString
QStringList_join(const QStringList &list, QLatin1String sep);
QStringList __attribute__((visibility("default")))
QStringList_filter(const QStringList *that, QStringView str,
                   Qt::CaseSensitivity cs);

QStringList __attribute__((visibility("default")))
QStringList_filter(const QStringList *that, const QString &str,
                   Qt::CaseSensitivity cs);

bool __attribute__((visibility("default")))
QStringList_contains(const QStringList *that, const QString &str,
                     Qt::CaseSensitivity cs);

bool __attribute__((visibility("default")))
QStringList_contains(const QStringList *that, QStringView str,
                     Qt::CaseSensitivity cs);
bool __attribute__((visibility("default")))
QStringList_contains(const QStringList *that, QLatin1String str,
                     Qt::CaseSensitivity cs);
void __attribute__((visibility("default")))
QStringList_replaceInStrings(QStringList *that, QStringView before,
                             QStringView after, Qt::CaseSensitivity cs);

void __attribute__((visibility("default")))
QStringList_replaceInStrings(QStringList *that, const QString &before,
                             const QString &after, Qt::CaseSensitivity cs);

void __attribute__((visibility("default")))
QStringList_replaceInStrings(QStringList *that, const QRegExp &rx,
                             const QString &after);
QStringList __attribute__((visibility("default")))
QStringList_filter(const QStringList *that, const QRegExp &re);
int __attribute__((visibility("default")))
QStringList_indexOf(const QStringList *that, const QRegExp &rx, int from);
int __attribute__((visibility("default")))
QStringList_lastIndexOf(const QStringList *that, const QRegExp &rx, int from);
int __attribute__((visibility("default")))
QStringList_indexOf(const QStringList *that, QRegExp &rx, int from);
int __attribute__((visibility("default")))
QStringList_lastIndexOf(const QStringList *that, QRegExp &rx, int from);

void __attribute__((visibility("default")))
QStringList_replaceInStrings(QStringList *that, const QRegularExpression &rx,
                             const QString &after);
QStringList __attribute__((visibility("default")))
QStringList_filter(const QStringList *that, const QRegularExpression &re);
int __attribute__((visibility("default")))
QStringList_indexOf(const QStringList *that, const QRegularExpression &re,
                    int from);
int __attribute__((visibility("default")))
QStringList_lastIndexOf(const QStringList *that, const QRegularExpression &re,
                        int from);

} // namespace QtPrivate

inline void QListSpecialMethods<QString>::sort(Qt::CaseSensitivity cs) {
  QtPrivate::QStringList_sort(self(), cs);
}

inline int QListSpecialMethods<QString>::removeDuplicates() {
  return QtPrivate::QStringList_removeDuplicates(self());
}

inline QString QListSpecialMethods<QString>::join(const QString &sep) const {
  return QtPrivate::QStringList_join(self(), sep.constData(), sep.length());
}

inline QString QListSpecialMethods<QString>::join(QStringView sep) const {
  return QtPrivate::QStringList_join(self(), sep);
}

QString QListSpecialMethods<QString>::join(QLatin1String sep) const {
  return QtPrivate::QStringList_join(*self(), sep);
}

inline QString QListSpecialMethods<QString>::join(QChar sep) const {
  return QtPrivate::QStringList_join(self(), &sep, 1);
}

inline QStringList
QListSpecialMethods<QString>::filter(QStringView str,
                                     Qt::CaseSensitivity cs) const {
  return QtPrivate::QStringList_filter(self(), str, cs);
}

inline QStringList
QListSpecialMethods<QString>::filter(const QString &str,
                                     Qt::CaseSensitivity cs) const {
  return QtPrivate::QStringList_filter(self(), str, cs);
}

inline bool QStringList::contains(const QString &str,
                                  Qt::CaseSensitivity cs) const {
  return QtPrivate::QStringList_contains(this, str, cs);
}

inline bool QStringList::contains(QLatin1String str,
                                  Qt::CaseSensitivity cs) const {
  return QtPrivate::QStringList_contains(this, str, cs);
}

inline bool QStringList::contains(QStringView str,
                                  Qt::CaseSensitivity cs) const {
  return QtPrivate::QStringList_contains(this, str, cs);
}

inline QStringList &QListSpecialMethods<QString>::replaceInStrings(
    QStringView before, QStringView after, Qt::CaseSensitivity cs) {
  QtPrivate::QStringList_replaceInStrings(self(), before, after, cs);
  return *self();
}

inline QStringList &QListSpecialMethods<QString>::replaceInStrings(
    const QString &before, const QString &after, Qt::CaseSensitivity cs) {
  QtPrivate::QStringList_replaceInStrings(self(), before, after, cs);
  return *self();
}

inline QStringList &QListSpecialMethods<QString>::replaceInStrings(
    QStringView before, const QString &after, Qt::CaseSensitivity cs) {
  QtPrivate::QStringList_replaceInStrings(self(), before,
                                          qToStringViewIgnoringNull(after), cs);
  return *self();
}

inline QStringList &QListSpecialMethods<QString>::replaceInStrings(
    const QString &before, QStringView after, Qt::CaseSensitivity cs) {
  QtPrivate::QStringList_replaceInStrings(self(), QStringView(before), after,
                                          cs);
  return *self();
}

inline QStringList operator+(const QList<QString> &one,
                             const QStringList &other) {
  QStringList n = one;
  n += other;
  return n;
}

inline int QStringList::indexOf(QStringView string, int from) const {
  return QtPrivate::indexOf<QString, QStringView>(*this, string, from);
}

inline int QStringList::indexOf(QLatin1String string, int from) const {
  return QtPrivate::indexOf<QString, QLatin1String>(*this, string, from);
}

inline int QStringList::lastIndexOf(QStringView string, int from) const {
  return QtPrivate::lastIndexOf<QString, QStringView>(*this, string, from);
}

inline int QStringList::lastIndexOf(QLatin1String string, int from) const {
  return QtPrivate::lastIndexOf<QString, QLatin1String>(*this, string, from);
}

inline QStringList &
QListSpecialMethods<QString>::replaceInStrings(const QRegExp &rx,
                                               const QString &after) {
  QtPrivate::QStringList_replaceInStrings(self(), rx, after);
  return *self();
}

inline QStringList
QListSpecialMethods<QString>::filter(const QRegExp &rx) const {
  return QtPrivate::QStringList_filter(self(), rx);
}

inline int QStringList::indexOf(const QRegExp &rx, int from) const {
  return QtPrivate::QStringList_indexOf(this, rx, from);
}

inline int QStringList::lastIndexOf(const QRegExp &rx, int from) const {
  return QtPrivate::QStringList_lastIndexOf(this, rx, from);
}

inline int QStringList::indexOf(QRegExp &rx, int from) const {
  return QtPrivate::QStringList_indexOf(this, rx, from);
}

inline int QStringList::lastIndexOf(QRegExp &rx, int from) const {
  return QtPrivate::QStringList_lastIndexOf(this, rx, from);
}

inline QStringList &
QListSpecialMethods<QString>::replaceInStrings(const QRegularExpression &rx,
                                               const QString &after) {
  QtPrivate::QStringList_replaceInStrings(self(), rx, after);
  return *self();
}

inline QStringList
QListSpecialMethods<QString>::filter(const QRegularExpression &rx) const {
  return QtPrivate::QStringList_filter(self(), rx);
}

inline int QStringList::indexOf(const QRegularExpression &rx, int from) const {
  return QtPrivate::QStringList_indexOf(this, rx, from);
}

inline int QStringList::lastIndexOf(const QRegularExpression &rx,
                                    int from) const {
  return QtPrivate::QStringList_lastIndexOf(this, rx, from);
}

template <typename T> struct QScopedPointerDeleter {
  static inline void cleanup(T *pointer) {

    typedef char IsIncompleteType[sizeof(T) ? 1 : -1];
    (void)sizeof(IsIncompleteType);

    delete pointer;
  }
};

template <typename T> struct QScopedPointerArrayDeleter {
  static inline void cleanup(T *pointer) {

    typedef char IsIncompleteType[sizeof(T) ? 1 : -1];
    (void)sizeof(IsIncompleteType);

    delete[] pointer;
  }
};

struct QScopedPointerPodDeleter {
  static inline void cleanup(void *pointer) {
    if (pointer)
      free(pointer);
  }
};

template <typename T> struct QScopedPointerObjectDeleteLater {
  static inline void cleanup(T *pointer) {
    if (pointer)
      pointer->deleteLater();
  }
};

class QObject;
typedef QScopedPointerObjectDeleteLater<QObject> QScopedPointerDeleteLater;

template <typename T, typename Cleanup = QScopedPointerDeleter<T>>
class QScopedPointer {
  typedef T *QScopedPointer::*RestrictedBool;

public:
  explicit QScopedPointer(T *p = nullptr) noexcept : d(p) {}

  inline ~QScopedPointer() {
    T *oldD = this->d;
    Cleanup::cleanup(oldD);
  }

  inline T &operator*() const {
    ((d) ? static_cast<void>(0)
         : qt_assert("d", "/usr/local/include/QtCore/qscopedpointer.h", 112));
    return *d;
  }

  T *operator->() const noexcept { return d; }

  bool operator!() const noexcept { return !d; }

  operator RestrictedBool() const noexcept {
    return isNull() ? nullptr : &QScopedPointer::d;
  }

  T *data() const noexcept { return d; }

  T *get() const noexcept { return d; }

  bool isNull() const noexcept { return !d; }

  void reset(T *other = nullptr) noexcept(
      noexcept(Cleanup::cleanup(std::declval<T *>()))) {
    if (d == other)
      return;
    T *oldD = d;
    d = other;
    Cleanup::cleanup(oldD);
  }

  T *take() noexcept {
    T *oldD = d;
    d = nullptr;
    return oldD;
  }

  void swap(QScopedPointer<T, Cleanup> &other) noexcept { qSwap(d, other.d); }

  typedef T *pointer;

protected:
  T *d;

private:
  QScopedPointer(const QScopedPointer &) = delete;
  QScopedPointer &operator=(const QScopedPointer &) = delete;
};

template <class T, class Cleanup>
inline bool operator==(const QScopedPointer<T, Cleanup> &lhs,
                       const QScopedPointer<T, Cleanup> &rhs) noexcept {
  return lhs.data() == rhs.data();
}

template <class T, class Cleanup>
inline bool operator!=(const QScopedPointer<T, Cleanup> &lhs,
                       const QScopedPointer<T, Cleanup> &rhs) noexcept {
  return lhs.data() != rhs.data();
}

template <class T, class Cleanup>
inline bool operator==(const QScopedPointer<T, Cleanup> &lhs,
                       std::nullptr_t) noexcept {
  return lhs.isNull();
}

template <class T, class Cleanup>
inline bool operator==(std::nullptr_t,
                       const QScopedPointer<T, Cleanup> &rhs) noexcept {
  return rhs.isNull();
}

template <class T, class Cleanup>
inline bool operator!=(const QScopedPointer<T, Cleanup> &lhs,
                       std::nullptr_t) noexcept {
  return !lhs.isNull();
}

template <class T, class Cleanup>
inline bool operator!=(std::nullptr_t,
                       const QScopedPointer<T, Cleanup> &rhs) noexcept {
  return !rhs.isNull();
}

template <class T, class Cleanup>
inline void swap(QScopedPointer<T, Cleanup> &p1,
                 QScopedPointer<T, Cleanup> &p2) noexcept {
  p1.swap(p2);
}

template <typename T, typename Cleanup = QScopedPointerArrayDeleter<T>>
class QScopedArrayPointer : public QScopedPointer<T, Cleanup> {
  template <typename Ptr>
  using if_same_type = typename std::enable_if<
      std::is_same<typename std::remove_cv<T>::type, Ptr>::value, bool>::type;

public:
  inline QScopedArrayPointer() : QScopedPointer<T, Cleanup>(nullptr) {}

  template <typename D, if_same_type<D> = true>
  explicit QScopedArrayPointer(D *p) : QScopedPointer<T, Cleanup>(p) {}

  inline T &operator[](int i) { return this->d[i]; }

  inline const T &operator[](int i) const { return this->d[i]; }

  void swap(QScopedArrayPointer &other) noexcept {
    QScopedPointer<T, Cleanup>::swap(other);
  }

private:
  explicit inline QScopedArrayPointer(void *) {}

  QScopedArrayPointer(const QScopedArrayPointer &) = delete;
  QScopedArrayPointer &operator=(const QScopedArrayPointer &) = delete;
};

template <typename T, typename Cleanup>
inline void swap(QScopedArrayPointer<T, Cleanup> &lhs,
                 QScopedArrayPointer<T, Cleanup> &rhs) noexcept {
  lhs.swap(rhs);
}

namespace QtPrivate {
template <typename ArgList> struct TypesAreDeclaredMetaType {
  enum { Value = false };
};
template <> struct TypesAreDeclaredMetaType<List<>> {
  enum { Value = true };
};
template <typename Arg, typename... Tail>
struct TypesAreDeclaredMetaType<List<Arg, Tail...>> {
  enum {
    Value = QMetaTypeId2<Arg>::Defined &&
            TypesAreDeclaredMetaType<List<Tail...>>::Value
  };
};

template <typename ArgList,
          bool Declared = TypesAreDeclaredMetaType<ArgList>::Value>
struct ConnectionTypes {
  static const int *types() { return nullptr; }
};
template <> struct ConnectionTypes<List<>, true> {
  static const int *types() { return nullptr; }
};
template <typename... Args> struct ConnectionTypes<List<Args...>, true> {
  static const int *types() {
    static const int t[sizeof...(Args) + 1] = {
        (QtPrivate::QMetaTypeIdHelper<Args>::qt_metatype_id())..., 0};
    return t;
  }
};

template <typename Func, typename Args, typename R>
class QStaticSlotObject : public QSlotObjectBase {
  typedef QtPrivate::FunctionPointer<Func> FuncType;
  Func function;
  static void impl(int which, QSlotObjectBase *this_, QObject *r, void **a,
                   bool *ret) {
    switch (which) {
    case Destroy:
      delete static_cast<QStaticSlotObject *>(this_);
      break;
    case Call:
      FuncType::template call<Args, R>(
          static_cast<QStaticSlotObject *>(this_)->function, r, a);
      break;
    case Compare:
    case NumOperations:
      (void)ret;
      ;
    }
  }

public:
  explicit QStaticSlotObject(Func f) : QSlotObjectBase(&impl), function(f) {}
};
} // namespace QtPrivate

class QEvent;
class QTimerEvent;
class QChildEvent;
struct QMetaObject;
class QVariant;
class QObjectPrivate;
class QObject;
class QThread;
class QWidget;
class QAccessibleWidget;

class QRegExp;

class QRegularExpression;

class QObjectUserData;

struct QDynamicMetaObjectData;

typedef QList<QObject *> QObjectList;

__attribute__((visibility("default"))) void
qt_qFindChildren_helper(const QObject *parent, const QString &name,
                        const QMetaObject &mo, QList<void *> *list,
                        Qt::FindChildOptions options);
__attribute__((visibility("default"))) void
qt_qFindChildren_helper(const QObject *parent, const QRegExp &re,
                        const QMetaObject &mo, QList<void *> *list,
                        Qt::FindChildOptions options);
__attribute__((visibility("default"))) void
qt_qFindChildren_helper(const QObject *parent, const QRegularExpression &re,
                        const QMetaObject &mo, QList<void *> *list,
                        Qt::FindChildOptions options);
__attribute__((visibility("default"))) QObject *
qt_qFindChild_helper(const QObject *parent, const QString &name,
                     const QMetaObject &mo, Qt::FindChildOptions options);

class __attribute__((visibility("default"))) QObjectData {
  QObjectData(const QObjectData &) = delete;
  QObjectData &operator=(const QObjectData &) = delete;

public:
  QObjectData() = default;
  virtual ~QObjectData() = 0;
  QObject *q_ptr;
  QObject *parent;
  QObjectList children;

  uint isWidget : 1;
  uint blockSig : 1;
  uint wasDeleted : 1;
  uint isDeletingChildren : 1;
  uint sendChildEvents : 1;
  uint receiveChildEvents : 1;
  uint isWindow : 1;
  uint deleteLaterCalled : 1;
  uint unused : 24;
  int postedEvents;
  QDynamicMetaObjectData *metaObject;
  QMetaObject *dynamicMetaObject() const;

  enum { CheckForParentChildLoopsWarnDepth = 4096 };
};

class QObject {
public:
  static const QMetaObject staticMetaObject;
  virtual const QMetaObject *metaObject() const;
  virtual void *qt_metacast(const char *);
  virtual int qt_metacall(QMetaObject::Call, int, void **);

  static inline QString tr(const char *s, const char *c = nullptr, int n = -1) {
    return staticMetaObject.tr(s, c, n);
  }

  static inline QString trUtf8(const char *s, const char *c = nullptr,
                               int n = -1) {
    return staticMetaObject.tr(s, c, n);
  }

private:
  static void qt_static_metacall(QObject *, QMetaObject::Call, int, void **);
  struct QPrivateSignal {};

  inline QObjectPrivate *d_func() {
    return reinterpret_cast<QObjectPrivate *>(qGetPtrHelper(d_ptr));
  }
  inline const QObjectPrivate *d_func() const {
    return reinterpret_cast<const QObjectPrivate *>(qGetPtrHelper(d_ptr));
  }
  friend class QObjectPrivate;

public:
  explicit QObject(QObject *parent = nullptr);
  virtual ~QObject();

  virtual bool event(QEvent *event);
  virtual bool eventFilter(QObject *watched, QEvent *event);
  QString objectName() const;
  void setObjectName(const QString &name);

  inline bool isWidgetType() const { return d_ptr->isWidget; }
  inline bool isWindowType() const { return d_ptr->isWindow; }

  inline bool signalsBlocked() const noexcept { return d_ptr->blockSig; }
  bool blockSignals(bool b) noexcept;

  QThread *thread() const;
  void moveToThread(QThread *thread);

  int startTimer(int interval, Qt::TimerType timerType = Qt::CoarseTimer);

  inline __attribute__((always_inline)) int
  startTimer(std::chrono::milliseconds time,
             Qt::TimerType timerType = Qt::CoarseTimer) {
    return startTimer(int(time.count()), timerType);
  }

  void killTimer(int id);

  template <typename T>
  inline T
  findChild(const QString &aName = QString(),
            Qt::FindChildOptions options = Qt::FindChildrenRecursively) const {
    typedef typename std::remove_cv<typename std::remove_pointer<T>::type>::type
        ObjType;
    return static_cast<T>(
        qt_qFindChild_helper(this, aName, ObjType::staticMetaObject, options));
  }

  template <typename T>
  inline QList<T> findChildren(
      const QString &aName = QString(),
      Qt::FindChildOptions options = Qt::FindChildrenRecursively) const {
    typedef typename std::remove_cv<typename std::remove_pointer<T>::type>::type
        ObjType;
    QList<T> list;
    qt_qFindChildren_helper(this, aName, ObjType::staticMetaObject,
                            reinterpret_cast<QList<void *> *>(&list), options);
    return list;
  }

  template <typename T>
  __attribute__((__deprecated__("Use findChildren(const QRegularExpression &, "
                                "...) instead."))) inline QList<T>
  findChildren(const QRegExp &re, Qt::FindChildOptions options =
                                      Qt::FindChildrenRecursively) const {
    typedef typename std::remove_cv<typename std::remove_pointer<T>::type>::type
        ObjType;
    QList<T> list;
    qt_qFindChildren_helper(this, re, ObjType::staticMetaObject,
                            reinterpret_cast<QList<void *> *>(&list), options);
    return list;
  }

  template <typename T>
  inline QList<T> findChildren(
      const QRegularExpression &re,
      Qt::FindChildOptions options = Qt::FindChildrenRecursively) const {
    typedef typename std::remove_cv<typename std::remove_pointer<T>::type>::type
        ObjType;
    QList<T> list;
    qt_qFindChildren_helper(this, re, ObjType::staticMetaObject,
                            reinterpret_cast<QList<void *> *>(&list), options);
    return list;
  }

  inline const QObjectList &children() const { return d_ptr->children; }

  void setParent(QObject *parent);
  void installEventFilter(QObject *filterObj);
  void removeEventFilter(QObject *obj);

  static QMetaObject::Connection
  connect(const QObject *sender, const char *signal, const QObject *receiver,
          const char *member, Qt::ConnectionType = Qt::AutoConnection);

  static QMetaObject::Connection
  connect(const QObject *sender, const QMetaMethod &signal,
          const QObject *receiver, const QMetaMethod &method,
          Qt::ConnectionType type = Qt::AutoConnection);

  inline QMetaObject::Connection
  connect(const QObject *sender, const char *signal, const char *member,
          Qt::ConnectionType type = Qt::AutoConnection) const;
  template <typename Func1, typename Func2>
  static inline QMetaObject::Connection
  connect(const typename QtPrivate::FunctionPointer<Func1>::Object *sender,
          Func1 signal,
          const typename QtPrivate::FunctionPointer<Func2>::Object *receiver,
          Func2 slot, Qt::ConnectionType type = Qt::AutoConnection) {
    typedef QtPrivate::FunctionPointer<Func1> SignalType;
    typedef QtPrivate::FunctionPointer<Func2> SlotType;

    static_assert(
        bool(QtPrivate::HasQ_OBJECT_Macro<typename SignalType::Object>::Value),
        "No Q_OBJECT in the class with the signal");

    static_assert(
        bool(int(SignalType::ArgumentCount) >= int(SlotType::ArgumentCount)),
        "The slot requires more arguments than the signal provides.");

    static_assert(bool((QtPrivate::CheckCompatibleArguments<
                        typename SignalType::Arguments,
                        typename SlotType::Arguments>::value)),
                  "Signal and slot arguments are not compatible.");

    static_assert(bool((QtPrivate::AreArgumentsCompatible<
                        typename SlotType::ReturnType,
                        typename SignalType::ReturnType>::value)),
                  "Return type of the slot is not compatible with the return "
                  "type of the signal.");

    const int *types = nullptr;
    if (type == Qt::QueuedConnection || type == Qt::BlockingQueuedConnection)
      types =
          QtPrivate::ConnectionTypes<typename SignalType::Arguments>::types();

    return connectImpl(
        sender, reinterpret_cast<void **>(&signal), receiver,
        reinterpret_cast<void **>(&slot),
        new QtPrivate::QSlotObject<
            Func2,
            typename QtPrivate::List_Left<typename SignalType::Arguments,
                                          SlotType::ArgumentCount>::Value,
            typename SignalType::ReturnType>(slot),
        type, types, &SignalType::Object::staticMetaObject);
  }

  template <typename Func1, typename Func2>
  static inline typename std::enable_if<
      int(QtPrivate::FunctionPointer<Func2>::ArgumentCount) >= 0,
      QMetaObject::Connection>::type
  connect(const typename QtPrivate::FunctionPointer<Func1>::Object *sender,
          Func1 signal, Func2 slot) {
    return connect(sender, signal, sender, slot, Qt::DirectConnection);
  }

  template <typename Func1, typename Func2>
  static inline typename std::enable_if<
      int(QtPrivate::FunctionPointer<Func2>::ArgumentCount) >= 0 &&
          !QtPrivate::FunctionPointer<Func2>::IsPointerToMemberFunction,
      QMetaObject::Connection>::type
  connect(const typename QtPrivate::FunctionPointer<Func1>::Object *sender,
          Func1 signal, const QObject *context, Func2 slot,
          Qt::ConnectionType type = Qt::AutoConnection) {
    typedef QtPrivate::FunctionPointer<Func1> SignalType;
    typedef QtPrivate::FunctionPointer<Func2> SlotType;

    static_assert(
        bool(QtPrivate::HasQ_OBJECT_Macro<typename SignalType::Object>::Value),
        "No Q_OBJECT in the class with the signal");

    static_assert(
        bool(int(SignalType::ArgumentCount) >= int(SlotType::ArgumentCount)),
        "The slot requires more arguments than the signal provides.");

    static_assert(bool((QtPrivate::CheckCompatibleArguments<
                        typename SignalType::Arguments,
                        typename SlotType::Arguments>::value)),
                  "Signal and slot arguments are not compatible.");

    static_assert(bool((QtPrivate::AreArgumentsCompatible<
                        typename SlotType::ReturnType,
                        typename SignalType::ReturnType>::value)),
                  "Return type of the slot is not compatible with the return "
                  "type of the signal.");

    const int *types = nullptr;
    if (type == Qt::QueuedConnection || type == Qt::BlockingQueuedConnection)
      types =
          QtPrivate::ConnectionTypes<typename SignalType::Arguments>::types();

    return connectImpl(
        sender, reinterpret_cast<void **>(&signal), context, nullptr,
        new QtPrivate::QStaticSlotObject<
            Func2,
            typename QtPrivate::List_Left<typename SignalType::Arguments,
                                          SlotType::ArgumentCount>::Value,
            typename SignalType::ReturnType>(slot),
        type, types, &SignalType::Object::staticMetaObject);
  }

  template <typename Func1, typename Func2>
  static inline typename std::enable_if<
      QtPrivate::FunctionPointer<Func2>::ArgumentCount == -1,
      QMetaObject::Connection>::type
  connect(const typename QtPrivate::FunctionPointer<Func1>::Object *sender,
          Func1 signal, Func2 slot) {
    return connect(sender, signal, sender, std::move(slot),
                   Qt::DirectConnection);
  }

  template <typename Func1, typename Func2>
  static inline typename std::enable_if<
      QtPrivate::FunctionPointer<Func2>::ArgumentCount == -1,
      QMetaObject::Connection>::type
  connect(const typename QtPrivate::FunctionPointer<Func1>::Object *sender,
          Func1 signal, const QObject *context, Func2 slot,
          Qt::ConnectionType type = Qt::AutoConnection) {
    typedef QtPrivate::FunctionPointer<Func1> SignalType;
    const int FunctorArgumentCount = QtPrivate::ComputeFunctorArgumentCount<
        Func2, typename SignalType::Arguments>::Value;

    static_assert(bool((FunctorArgumentCount >= 0)),
                  "Signal and slot arguments are not compatible.");

    const int SlotArgumentCount =
        (FunctorArgumentCount >= 0) ? FunctorArgumentCount : 0;
    typedef typename QtPrivate::FunctorReturnType<
        Func2, typename QtPrivate::List_Left<typename SignalType::Arguments,
                                             SlotArgumentCount>::Value>::Value
        SlotReturnType;

    static_assert(
        bool((QtPrivate::AreArgumentsCompatible<
              SlotReturnType, typename SignalType::ReturnType>::value)),
        "Return type of the slot is not compatible with the return type of the "
        "signal.");

    static_assert(
        bool(QtPrivate::HasQ_OBJECT_Macro<typename SignalType::Object>::Value),
        "No Q_OBJECT in the class with the signal");

    const int *types = nullptr;
    if (type == Qt::QueuedConnection || type == Qt::BlockingQueuedConnection)
      types =
          QtPrivate::ConnectionTypes<typename SignalType::Arguments>::types();

    return connectImpl(
        sender, reinterpret_cast<void **>(&signal), context, nullptr,
        new QtPrivate::QFunctorSlotObject<
            Func2, SlotArgumentCount,
            typename QtPrivate::List_Left<typename SignalType::Arguments,
                                          SlotArgumentCount>::Value,
            typename SignalType::ReturnType>(std::move(slot)),
        type, types, &SignalType::Object::staticMetaObject);
  }

  static bool disconnect(const QObject *sender, const char *signal,
                         const QObject *receiver, const char *member);
  static bool disconnect(const QObject *sender, const QMetaMethod &signal,
                         const QObject *receiver, const QMetaMethod &member);
  inline bool disconnect(const char *signal = nullptr,
                         const QObject *receiver = nullptr,
                         const char *member = nullptr) const {
    return disconnect(this, signal, receiver, member);
  }
  inline bool disconnect(const QObject *receiver,
                         const char *member = nullptr) const {
    return disconnect(this, nullptr, receiver, member);
  }
  static bool disconnect(const QMetaObject::Connection &);

  template <typename Func1, typename Func2>
  static inline bool
  disconnect(const typename QtPrivate::FunctionPointer<Func1>::Object *sender,
             Func1 signal,
             const typename QtPrivate::FunctionPointer<Func2>::Object *receiver,
             Func2 slot) {
    typedef QtPrivate::FunctionPointer<Func1> SignalType;
    typedef QtPrivate::FunctionPointer<Func2> SlotType;

    static_assert(
        bool(QtPrivate::HasQ_OBJECT_Macro<typename SignalType::Object>::Value),
        "No Q_OBJECT in the class with the signal");

    static_assert(bool((QtPrivate::CheckCompatibleArguments<
                        typename SignalType::Arguments,
                        typename SlotType::Arguments>::value)),
                  "Signal and slot arguments are not compatible.");

    return disconnectImpl(sender, reinterpret_cast<void **>(&signal), receiver,
                          reinterpret_cast<void **>(&slot),
                          &SignalType::Object::staticMetaObject);
  }
  template <typename Func1>
  static inline bool
  disconnect(const typename QtPrivate::FunctionPointer<Func1>::Object *sender,
             Func1 signal, const QObject *receiver, void **zero) {

    ((!zero) ? static_cast<void>(0)
             : qt_assert("!zero", "/usr/local//include/QtCore/qobject.h", 390));
    typedef QtPrivate::FunctionPointer<Func1> SignalType;
    return disconnectImpl(sender, reinterpret_cast<void **>(&signal), receiver,
                          zero, &SignalType::Object::staticMetaObject);
  }

  void dumpObjectTree();
  void dumpObjectInfo();

  void dumpObjectTree() const;
  void dumpObjectInfo() const;

  bool setProperty(const char *name, const QVariant &value);
  QVariant property(const char *name) const;
  QList<QByteArray> dynamicPropertyNames() const;

  __attribute__((__deprecated__)) static uint registerUserData();
  __attribute__((__deprecated__("Use setProperty()"))) void
  setUserData(uint id, QObjectUserData *data);
  __attribute__((__deprecated__("Use property()"))) QObjectUserData *
  userData(uint id) const;

public:
  void destroyed(QObject * = nullptr);
  void objectNameChanged(const QString &objectName, QPrivateSignal);

public:
  inline QObject *parent() const { return d_ptr->parent; }

  inline bool inherits(const char *classname) const {
    return const_cast<QObject *>(this)->qt_metacast(classname) != nullptr;
  }

public:
  void deleteLater();

protected:
  QObject *sender() const;
  int senderSignalIndex() const;
  int receivers(const char *signal) const;
  bool isSignalConnected(const QMetaMethod &signal) const;

  virtual void timerEvent(QTimerEvent *event);
  virtual void childEvent(QChildEvent *event);
  virtual void customEvent(QEvent *event);

  virtual void connectNotify(const QMetaMethod &signal);
  virtual void disconnectNotify(const QMetaMethod &signal);

protected:
  QObject(QObjectPrivate &dd, QObject *parent = nullptr);

protected:
  QScopedPointer<QObjectData> d_ptr;

  static const QMetaObject staticQtMetaObject;
  friend inline const QMetaObject *qt_getQtMetaObject() noexcept;

  friend struct QMetaObject;
  friend struct QMetaObjectPrivate;
  friend class QMetaCallEvent;
  friend class QApplication;
  friend class QApplicationPrivate;
  friend class QCoreApplication;
  friend class QCoreApplicationPrivate;
  friend class QWidget;
  friend class QAccessibleWidget;
  friend class QThreadData;

private:
  QObject(const QObject &) = delete;
  QObject &operator=(const QObject &) = delete;

private:
  static QMetaObject::Connection
  connectImpl(const QObject *sender, void **signal, const QObject *receiver,
              void **slotPtr, QtPrivate::QSlotObjectBase *slot,
              Qt::ConnectionType type, const int *types,
              const QMetaObject *senderMetaObject);

  static bool disconnectImpl(const QObject *sender, void **signal,
                             const QObject *receiver, void **slot,
                             const QMetaObject *senderMetaObject);
};

inline QMetaObject::Connection
QObject::connect(const QObject *asender, const char *asignal,
                 const char *amember, Qt::ConnectionType atype) const {
  return connect(asender, asignal, this, amember, atype);
}

inline const QMetaObject *qt_getQtMetaObject() noexcept {
  return &QObject::staticQtMetaObject;
}

class __attribute__((visibility("default"))) QObjectUserData {
  QObjectUserData(const QObjectUserData &) = delete;
  QObjectUserData &operator=(const QObjectUserData &) = delete;

public:
  QObjectUserData() = default;
  virtual ~QObjectUserData();
};
template <class T> inline T qobject_cast(QObject *object) {
  typedef typename std::remove_cv<typename std::remove_pointer<T>::type>::type
      ObjType;
  static_assert(bool(QtPrivate::HasQ_OBJECT_Macro<ObjType>::Value),
                "qobject_cast requires the type to have a Q_OBJECT macro");

  return static_cast<T>(ObjType::staticMetaObject.cast(object));
}

template <class T> inline T qobject_cast(const QObject *object) {
  typedef typename std::remove_cv<typename std::remove_pointer<T>::type>::type
      ObjType;
  static_assert(bool(QtPrivate::HasQ_OBJECT_Macro<ObjType>::Value),
                "qobject_cast requires the type to have a Q_OBJECT macro");

  return static_cast<T>(ObjType::staticMetaObject.cast(object));
}

template <class T> inline const char *qobject_interface_iid() {
  return nullptr;
}
__attribute__((visibility("default"))) QDebug operator<<(QDebug,
                                                         const QObject *);

class QSignalBlocker {
public:
  inline explicit QSignalBlocker(QObject *o) noexcept;
  inline explicit QSignalBlocker(QObject &o) noexcept;
  inline ~QSignalBlocker();

  inline QSignalBlocker(QSignalBlocker &&other) noexcept;
  inline QSignalBlocker &operator=(QSignalBlocker &&other) noexcept;

  inline void reblock() noexcept;
  inline void unblock() noexcept;

private:
  QSignalBlocker(const QSignalBlocker &) = delete;
  QSignalBlocker &operator=(const QSignalBlocker &) = delete;
  QObject *m_o;
  bool m_blocked;
  bool m_inhibited;
};

QSignalBlocker::QSignalBlocker(QObject *o) noexcept
    : m_o(o), m_blocked(o && o->blockSignals(true)), m_inhibited(false) {}

QSignalBlocker::QSignalBlocker(QObject &o) noexcept
    : m_o(&o), m_blocked(o.blockSignals(true)), m_inhibited(false) {}

QSignalBlocker::QSignalBlocker(QSignalBlocker &&other) noexcept
    : m_o(other.m_o), m_blocked(other.m_blocked),
      m_inhibited(other.m_inhibited) {
  other.m_o = nullptr;
}

QSignalBlocker &QSignalBlocker::operator=(QSignalBlocker &&other) noexcept {
  if (this != &other) {

    if (m_o != other.m_o || (!m_inhibited && other.m_inhibited))
      unblock();
    m_o = other.m_o;
    m_blocked = other.m_blocked;
    m_inhibited = other.m_inhibited;

    other.m_o = nullptr;
  }
  return *this;
}

QSignalBlocker::~QSignalBlocker() {
  if (m_o && !m_inhibited)
    m_o->blockSignals(m_blocked);
}

void QSignalBlocker::reblock() noexcept {
  if (m_o)
    m_o->blockSignals(true);
  m_inhibited = false;
}

void QSignalBlocker::unblock() noexcept {
  if (m_o)
    m_o->blockSignals(m_blocked);
  m_inhibited = true;
}

namespace QtPrivate {
inline QObject &deref_for_methodcall(QObject &o) { return o; }
inline QObject &deref_for_methodcall(QObject *o) { return *o; }
} // namespace QtPrivate

class MyObject : public QObject {
  using W_ThisType = MyObject;
  static constexpr auto W_UnscopedName = w_internal::viewLiteral("MyObject");
  friend struct w_internal::FriendHelper;

  template <typename W_Flag> static inline constexpr int w_flagAlias(W_Flag) {
    return 0;
  }

public:
  struct W_MetaObjectCreatorHelper;

public:
  using W_BaseType = std::remove_reference_t<decltype(
      w_internal::getParentObjectHelper(&W_ThisType::qt_metacast))>;

public:
  static const QMetaObject staticMetaObject;

  virtual const QMetaObject *metaObject() const;
  virtual void *qt_metacast(const char *);
  virtual int qt_metacall(QMetaObject::Call, int, void **);

  static inline QString tr(const char *s, const char *c = nullptr, int n = -1) {
    return staticMetaObject.tr(s, c, n);
  }

  __attribute__((__deprecated__)) static inline QString
  trUtf8(const char *s, const char *c = nullptr, int n = -1) {
    return staticMetaObject.tr(s, c, n);
  }

private:
  __attribute__((visibility("hidden"))) static void
  qt_static_metacall(QObject *, QMetaObject::Call, int, void **);

  struct QPrivateSignal {};

public:
  void mySlot(const QString &name) {
    QMessageLogger(static_cast<const char *>("./example.h"), 40,
                   static_cast<const char *>(__PRETTY_FUNCTION__))
        .debug("hello %s", QtPrivate::asString(name).toLocal8Bit().constData());
  }

  friend constexpr auto w_state(
      w_internal::Index<
          w_internal::stateCount<0, w_internal::SlotStateTag, W_ThisType **>>,

      w_internal::SlotStateTag, W_ThisType **)
      -> decltype(w_internal::makeMetaSlotInfo(
          &W_ThisType::mySlot, w_internal::viewLiteral("mySlot"),
          integral_constant<decltype(&W_ThisType::mySlot),
                            &W_ThisType::mySlot>(),
          w_internal::viewParsedLiterals<w_internal::countParsedLiterals(""
                                                                         "")>(
              ""
              ""),
          w_internal::W_EmptyFlag)) {
    return w_internal::makeMetaSlotInfo(
        &W_ThisType::mySlot, w_internal::viewLiteral("mySlot"),
        std::integral_constant<decltype((&W_ThisType::mySlot)),
                               &W_ThisType::mySlot>(),
        w_internal::viewParsedLiterals<w_internal::countParsedLiterals(""
                                                                       "")>(""
                                                                            ""),
        w_internal::W_EmptyFlag);
  }

  static inline void w_GetAccessSpecifierHelper(
      std::integral_constant<decltype(&W_ThisType::mySlot),
                             &W_ThisType::mySlot>) {}

public:
  {
    using w_SignalType = decltype((&W_ThisType::mySignal));
    return w_internal::SignalImplementation<w_SignalType,
                                            w_signalIndex_mySignal_53>{this}(
        name, 0);
  }

  static constexpr int w_signalIndex_mySignal_53 =
      w_internal::stateCount<1, w_internal::SignalStateTag, W_ThisType **>;

  friend constexpr auto w_state(w_internal::Index<w_signalIndex_mySignal_53>,
                                w_internal::SignalStateTag, W_ThisType **)
      -> decltype(w_internal::makeMetaSignalInfo(
          &W_ThisType::mySignal, w_internal::viewLiteral("mySignal"),
          std::integral_constant<decltype((&W_ThisType::mySignal)),
                                 &W_ThisType::mySignal>(),
          w_internal::viewParsedLiterals<w_internal::countParsedLiterals(""
                                                                         "")>(
              ""
              ""),
          w_internal::viewParsedLiterals<
              w_internal::countParsedLiterals(""
                                              "name , 0")>(""
                                                           "name , 0"))) {
    return w_internal::makeMetaSignalInfo(
        &W_ThisType::mySignal, w_internal::viewLiteral("mySignal"),
        std::integral_constant<decltype((&W_ThisType::mySignal)),
                               &W_ThisType::mySignal>(),
        w_internal::viewParsedLiterals<w_internal::countParsedLiterals(""
                                                                       "")>(""
                                                                            ""),
        w_internal::viewParsedLiterals<w_internal::countParsedLiterals(
            ""
            "name , 0")>(""
                         "name , 0"));
  }

  static inline void w_GetAccessSpecifierHelper(
      std::integral_constant<decltype((&W_ThisType::mySignal)),
                             &W_ThisType::mySignal>) {}
};

namespace w_internal {

enum : uint {
  IsUnresolvedType = 0x80000000,
  IsUnresolvedNotifySignal = 0x70000000
};

template <class T, class Name, size_t L = 1024 * 1024 * 1024>
struct ObjectInfo {
  using Type = T;
  static constexpr auto counter = L;
  static constexpr auto name = StringView{Name::value};

  static constexpr int signalCount = stateCount<L, SignalStateTag, T **>;
  static constexpr int slotCount = stateCount<L, SlotStateTag, T **>;
  static constexpr int methodCount =
      signalCount + slotCount + stateCount<L, MethodStateTag, T **>;
  static constexpr int constructorCount =
      stateCount<L, ConstructorStateTag, T **>;
  static constexpr int propertyCount = stateCount<L, PropertyStateTag, T **>;
  static constexpr int enumCount = stateCount<L, EnumStateTag, T **>;
  static constexpr int classInfoCount = stateCount<L, ClassInfoStateTag, T **>;
  static constexpr int interfaceCount = stateCount<L, InterfaceStateTag, T **>;

  static constexpr auto methodSequence = make_index_sequence<methodCount>{};
  static constexpr auto constructorSequence =
      make_index_sequence<constructorCount>{};
  static constexpr auto propertySequence = make_index_sequence<propertyCount>{};
  static constexpr auto interfaceSequence =
      make_index_sequence<interfaceCount>{};
  template <size_t Idx>
  static constexpr auto method(Index<Idx>,
                               std::enable_if_t<(Idx < signalCount)> * = {}) {
    using TPP = T **;
    return w_state(index<Idx>, SignalStateTag{}, TPP{});
  }
  template <size_t Idx>
  static constexpr auto
  method(Index<Idx>,
         std::enable_if_t<(Idx >= signalCount && Idx - signalCount < slotCount)>
             * = {}) {
    using TPP = T **;
    return w_state(index<Idx - signalCount>, SlotStateTag{}, TPP{});
  }
  template <size_t Idx>
  static constexpr auto
  method(Index<Idx>,
         std::enable_if_t<(Idx >= signalCount + slotCount)> * = {}) {
    using TPP = T **;
    return w_state(index<Idx - signalCount - slotCount>, MethodStateTag{},
                   TPP{});
  }
};

template <class F, size_t... Is>
constexpr void fold(index_sequence<Is...>, F &&f) {
  (void)f;

  ordered((f(index<Is>), 0)...);
}

template <class F, class State, class TPP> struct FoldState {
  F &&f;
  template <class I> constexpr void operator()(I i) {
    f(w_state(i, State{}, TPP{}), i);
  }
};
template <size_t L, class State, class TPP, class F>
constexpr void foldState(F &&f) {
  auto fs = FoldState<F, State, TPP>{std::forward<F>(f)};
  fold(make_index_sequence<stateCount<L, State, TPP>>{}, fs);
}

template <size_t L, class T, class F> constexpr void foldMethods(F &&f) {
  foldState<L, SignalStateTag, T>(f);
  foldState<L, SlotStateTag, T>(f);
  foldState<L, MethodStateTag, T>(f);
}

template <class T>
constexpr auto fetchExplicitName(const StringView &defaultName, ...) {
  return defaultName;
}

template <class T>
constexpr auto fetchExplicitName(const StringView &, int)
    -> decltype(w_explicitObjectName(static_cast<T *>(nullptr))) {
  return w_explicitObjectName(static_cast<T *>(nullptr));
}

template <size_t L, size_t PropIdx, typename T, typename O>
struct ResolveNotifySignal {
private:
  using TP = T **;
  using OP = O **;
  static constexpr auto prop =
      w_state(index<PropIdx>, PropertyStateTag{}, TP{});

  template <size_t SigIdx,
            bool Eq = w_state(index<SigIdx>, SignalStateTag{}, OP{}).func ==
                      prop.notify>
  static constexpr auto match(int) {
    return Eq;
  }
  template <size_t SigIdx> static constexpr auto match(float) { return false; }

  template <size_t... Is>
  static constexpr int indexFold(index_sequence<Is...>) {
    int r = -1;

    ordered2<int>({(match<Is>(0) ? r = (int)Is : 0)...});

    return r;
  }

public:
  static constexpr int signalIndex() {
    return indexFold(
        make_index_sequence<stateCount<L, SignalStateTag, O **>>{});
  }
};
struct HasNotifySignal {
  bool r{};
  template <class P, class I> constexpr void operator()(P p, I) {
    r = r || !std::is_same<decltype(p.notify), std::nullptr_t>::value;
  }
};
template <size_t L, typename TPP> constexpr bool hasNotifySignal() {
  auto hns = HasNotifySignal{};
  foldState<L, PropertyStateTag, TPP>(hns);
  return hns.r;
}

template <class State> struct ClassInfoGenerator {
  State &s;
  constexpr ClassInfoGenerator(State &s) : s(s) {}

  template <class ClassInfo, class Index>
  constexpr void operator()(const ClassInfo &ci, Index) {
    s.addString(ci.first);
    s.addString(ci.second);
  }
};

template <class T, class M>
auto test_public(int) -> std::enable_if_t<
    std::is_same<void, decltype(T::w_GetAccessSpecifierHelper(M{}))>::value,
    std::true_type>;
template <class T, class M> auto test_public(float) -> std::false_type;
template <class T, class M> using isPublic = decltype(test_public<T, M>(0));

template <typename T, typename M, typename = void>
struct isProtected : std::false_type {};
template <typename T, typename = std::enable_if_t<!std::is_final<T>::value>>
struct Derived : T {
  template <typename M, typename X = T>
  static decltype(X::w_GetAccessSpecifierHelper(std::declval<M>())) test(M);
};
template <typename T, typename M>
struct isProtected<T, M, decltype(Derived<T>::test(std::declval<M>()))>
    : std::true_type {};

template <class State, class T> struct MethodGenerator {
  State &s;
  int parameterIndex;
  MethodGenerator(const MethodGenerator &) = delete;
  constexpr MethodGenerator(State &s, int pi) : s(s), parameterIndex(pi) {}

  template <class Method, class Index>
  constexpr void operator()(const Method &method, Index) {
    s.addString(method.name);
    s.addInts((uint)Method::argCount, parameterIndex, 1,
              adjustFlags(Method::flags, typename Method::IntegralConstant()));
    parameterIndex += 1 + Method::argCount * 2;
  }

private:
  template <typename M> static constexpr uint adjustFlags(uint f, M) {
    if (!(f & (W_Access::Protected.value | W_Access::Private.value |
               W_Access::Public.value))) {

      f |= isPublic<T, M>::value      ? W_Access::Public.value
           : isProtected<T, M>::value ? W_Access::Protected.value
                                      : W_Access::Private.value;
    }
    return f & static_cast<uint>(~W_Access::Private.value);
  }
};

template <typename T, typename = void>
struct MetaTypeIdIsBuiltIn : std::false_type {};
template <typename T>
struct MetaTypeIdIsBuiltIn<
    T, typename std::enable_if<QMetaTypeId2<T>::IsBuiltIn>::type>
    : std::true_type {};
template <typename T, typename State, typename TypeStr = int>
constexpr void
handleType(State &s, TypeStr = {},
           std::enable_if_t<MetaTypeIdIsBuiltIn<T>::value> * = {}) {
  s.addInts(QMetaTypeId2<T>::MetaType);
}
template <typename T, typename State, typename TypeStr = int>
constexpr void
handleType(State &s, TypeStr = {},
           std::enable_if_t<!MetaTypeIdIsBuiltIn<T>::value> * = {}) {
  s.addTypeString(W_TypeRegistery<T>::name);
  static_assert(W_TypeRegistery<T>::registered,
                "Please Register T with W_REGISTER_ARGTYPE");
}
template <typename T, typename State>
constexpr void
handleType(State &s, StringView v,
           std::enable_if_t<!MetaTypeIdIsBuiltIn<T>::value> * = {}) {
  s.addTypeString(v);
}

template <class State, class T> struct PropertyGenerator {
  State &s;
  constexpr PropertyGenerator(State &s) : s(s) {}

  template <class Prop, class Index>
  constexpr void operator()(const Prop &prop, Index) {
    s.addString(prop.name);
    handleType<typename Prop::PropertyType>(s, prop.typeStr);
    constexpr uint moreFlags =
        (QtPrivate::IsQEnumHelper<typename Prop::PropertyType>::Value
             ? uint(PropertyFlags::EnumOrFlag)
             : 0);
    constexpr uint finalFlag =
        std::is_final<T>::value ? 0 | PropertyFlags::Final : 0;
    constexpr uint defaultFlags = 0 | PropertyFlags::Stored |
                                  PropertyFlags::Scriptable |
                                  PropertyFlags::Designable;
    s.addInts(Prop::flags | moreFlags | finalFlag | defaultFlags);
  }
};

template <class State, size_t L, class T, bool hasNotify>
struct NotifySignalGenerator;
template <class State, size_t L, class T>
struct NotifySignalGenerator<State, L, T, false> {
  constexpr NotifySignalGenerator(State &) {}
  template <class Prop, size_t Idx>
  constexpr void operator()(const Prop &, Index<Idx>) {}
};
template <class State, size_t L, class T>
struct NotifySignalGenerator<State, L, T, true> {

  using TP = T **;
  State &s;
  constexpr NotifySignalGenerator(State &s) : s(s) {}
  template <class Prop, size_t Idx>
  constexpr void operator()(const Prop &prop, Index<Idx>) {
    process(prop.notify, index<Idx>);
  }

private:
  template <size_t Idx> constexpr void process(Empty, Index<Idx>) {
    s.addInts(0);
  }

  template <size_t Idx, typename Func>
  constexpr void
  process(Func, Index<Idx>,
          std::enable_if_t<std::is_same<T, typename QtPrivate::FunctionPointer<
                                               Func>::Object>::value,
                           int> = 0) {
    constexpr int signalIndex =
        ResolveNotifySignal<L, Idx, T, T>::signalIndex();
    static_assert(signalIndex >= 0,
                  "NOTIFY signal in parent class not registered as a W_SIGNAL");
    s.addInts(signalIndex);
  }

  template <size_t Idx, typename Func>
  constexpr void
  process(Func, Index<Idx>,
          std::enable_if_t<!std::is_same<T, typename QtPrivate::FunctionPointer<
                                                Func>::Object>::value,
                           int> = 0) {
    using O = typename QtPrivate::FunctionPointer<Func>::Object;
    using OP = O **;
    constexpr int signalIndex =
        ResolveNotifySignal<L, Idx, T, O>::signalIndex();
    static_assert(signalIndex >= 0,
                  "NOTIFY signal in parent class not registered as a W_SIGNAL");
    static_assert(signalIndex < 0 || ((5 << 16) | (15 << 8) | (0)) >=
                                         ((5 << 16) | (10 << 8) | (0)),
                  "NOTIFY signal in parent class requires Qt 5.10");
    constexpr auto sig = w_state(index<signalIndex>, SignalStateTag{}, OP{});
    s.template addTypeString<IsUnresolvedNotifySignal>(sig.name);
  }
};

template <class State> struct EnumGenerator {
  State &s;
  int dataIndex{};
  EnumGenerator(const EnumGenerator &) = delete;
  constexpr EnumGenerator(State &s, int di) : s(s), dataIndex(di) {}

  template <class Enum, class Index>
  constexpr void operator()(const Enum &e, Index) {
    auto nameIndex = s.stringCount;
    (void)nameIndex;
    s.addString(e.name);

    if (Enum::hasAlias)
      s.addString(e.alias);

    else
      s.addInts(nameIndex);

    s.addInts(Enum::flags, (uint)Enum::count, dataIndex);
    dataIndex += Enum::count * 2;
  }
};

template <class State> struct EnumValuesGenerator {
  State &s;
  constexpr EnumValuesGenerator(State &s) : s(s) {}

  template <class Enum, class Index>
  constexpr void operator()(const Enum &e, Index) {
    generateAll(typename Enum::Values{}, e.names, Enum::sequence);
  }

private:
  template <size_t... Values, typename Names, size_t... Is>
  constexpr void generateAll(index_sequence<Values...>, const Names &names,
                             index_sequence<Is...>) {

    ordered((s.addString(names[Is]), s.addInts((uint)Values), 0)...);
  }
};
template <size_t I, size_t N>
constexpr auto stringFetch(const StringViewArray<N> &s,
                           std::enable_if_t<(I < N)> * = {}) {
  return s[I];
}
template <size_t I, size_t N>
constexpr auto stringFetch(const StringViewArray<N> &s,
                           std::enable_if_t<!(I < N)> * = {}) {
  (void)s;
  struct _ {};
  return _{};
}

template <class Arg, class State, class TypeName>
constexpr void handleArgType(State &ss, const TypeName &typeName) {
  using Type = typename QtPrivate::RemoveConstRef<Arg>::Type;

  auto typeName2 = std::conditional_t<std::is_same<Arg, Type>::value, TypeName,
                                      std::tuple<TypeName>>{typeName};
  handleType<Type>(ss, typeName2);
}
template <class... Args, class State, class TypeNames, size_t... Is>
constexpr void handleArgTypes(State &ss, const TypeNames &typeNames,
                              index_sequence<Is...>) {

  ordered((handleArgType<Args>(ss, stringFetch<Is>(typeNames)), 0)...);
}

template <size_t ArgCount, class State, size_t NameCount>
constexpr void handleArgNames(State &ss,
                              const StringViewArray<NameCount> &paramNames) {
  auto i = size_t{};
  for (; i < ArgCount && i < NameCount; ++i)
    ss.addString(paramNames[i]);
  for (; i < ArgCount; ++i)
    ss.addInts(1);
}

template <class State> struct MethodParametersGenerator {
  State &s;
  constexpr MethodParametersGenerator(State &s) : s(s) {}
  template <class Method, class Index>
  constexpr void operator()(const Method &method, Index) {
    generateSingleMethodParameter(method.func, method);
  }

private:
  template <typename Method, typename Obj, typename Ret, typename... Args>
  constexpr void generateSingleMethodParameter(Ret (Obj::*)(Args...),
                                               const Method &method) {
    handleType<Ret>(s);
    handleArgTypes<Args...>(s, method.paramTypes, Method::argSequence);
    handleArgNames<Method::argCount>(s, method.paramNames);
  }
  template <typename Method, typename Obj, typename Ret, typename... Args>

  constexpr void generateSingleMethodParameter(Ret (Obj::*)(Args...) const,
                                               const Method &method) {
    handleType<Ret>(s);
    handleArgTypes<Args...>(s, method.paramTypes, Method::argSequence);
    handleArgNames<Method::argCount>(s, method.paramNames);
  }
  template <typename Method, typename Ret, typename... Args>
  constexpr void generateSingleMethodParameter(Ret (*)(Args...),
                                               const Method &method) {
    handleType<Ret>(s);
    handleArgTypes<Args...>(s, method.paramTypes, Method::argSequence);
    handleArgNames<Method::argCount>(s, method.paramNames);
  }
};

template <class State> struct ConstructorParametersGenerator {
  State &s;
  constexpr ConstructorParametersGenerator(State &s) : s(s) {}

  template <typename... Args, class Index>
  constexpr void operator()(const MetaConstructorInfo<Args...> &info, Index) {
    s.addInts(IsUnresolvedType | 1);
    handleArgTypes<Args...>(s, StringViewArray<>{}, info.argSequence);
    s.addInts(((void)sizeof(Args), 1)...);
  }
};
struct MethodParamOffset {
  int sum{};
  template <class M, class I> constexpr void operator()(M m, I) {
    sum += int(1 + m.argCount * 2);
  }
};
template <size_t L, class T> constexpr int methodsParamOffset() {
  auto mpo = MethodParamOffset{};
  foldMethods<L, T>(mpo);
  return mpo.sum;
}
struct ConstructorParamOffset {
  int sum{};
  template <class M, class I> constexpr void operator()(M m, I) {
    sum += int(1 + m.argCount * 2);
  }
};
template <size_t L, class T> constexpr int constructorParamOffset() {
  auto cpo = ConstructorParamOffset{};
  foldState<L, ConstructorStateTag, T>(cpo);
  return cpo.sum;
}

template <class T, size_t N> using RawArray = T[N];
template <class T, size_t N> struct OwnArray {
  RawArray<T, N> data{};
  constexpr OwnArray(const T (&s)[N]) {
    auto p = data;
    for (auto c : s)
      *p++ = c;
  }
};

struct LayoutBuilder {
  size_t stringSize{};
  uint stringCount{};
  uint intCount{};

  constexpr void addString(const StringView &s) {
    stringSize += s.size() + 1;
    stringCount += 1;
    intCount += 1;
  }
  constexpr void addStringUntracked(const StringView &s) {
    stringSize += s.size() + 1;
    stringCount += 1;
  }
  template <uint Flag = IsUnresolvedType>
  constexpr void addTypeString(const StringView &s) {
    stringSize += s.size() + 1;
    stringCount += 1;
    intCount += 1;
  }
  template <class... Ts> constexpr void addInts(Ts...) {
    intCount += sizeof...(Ts);
  }
};
struct DataBuilder {
  char *stringCharP{};
  qptrdiff *stringOffestP{};
  int *stringLengthP{};
  uint *intP{};
  uint stringCount{};
  uint intCount{};
  qptrdiff stringOffset{};

  constexpr DataBuilder() = default;
  DataBuilder(const DataBuilder &) = delete;
  template <class Holder>
  constexpr DataBuilder(Holder &r)
      : stringCharP(r.stringChars), stringOffestP(r.stringOffsets),
        stringLengthP(r.stringLengths), intP(r.ints),
        stringOffset(r.stringOffset) {}

  constexpr void addString(const StringView &s) {
    for (auto c : s)
      *stringCharP++ = c;
    *stringCharP++ = '\0';
    *stringOffestP++ = stringOffset;
    *stringLengthP++ = s.size();
    *intP++ = stringCount;
    stringOffset += 1 + s.size() - qptrdiff(sizeof(QByteArrayData));
    stringCount += 1;
    intCount += 1;
  }
  constexpr void addStringUntracked(const StringView &s) {
    for (auto c : s)
      *stringCharP++ = c;
    *stringCharP++ = '\0';
    *stringOffestP++ = stringOffset;
    *stringLengthP++ = s.size();
    stringOffset += 1 + s.size() - qptrdiff(sizeof(QByteArrayData));
    stringCount += 1;
  }

  template <uint Flag = IsUnresolvedType>
  constexpr void addTypeString(const StringView &s) {
    for (auto c : s)
      *stringCharP++ = c;
    *stringCharP++ = '\0';
    *stringOffestP++ = stringOffset;
    *stringLengthP++ = s.size();
    *intP++ = Flag | stringCount;
    stringOffset += 1 + s.size() - qptrdiff(sizeof(QByteArrayData));
    stringCount += 1;
    intCount += 1;
  }
  template <class... Ts> constexpr void addInts(Ts... vs) {

    ordered2<uint>({(*intP++ = vs)...});

    intCount += sizeof...(Ts);
  }
};

template <typename T, typename State>
constexpr void generateDataPass(State &state) {
  using ObjI = typename T::W_MetaObjectCreatorHelper::ObjectInfo;
  constexpr size_t L = ObjI::counter;
  constexpr bool hasNotify = hasNotifySignal<L, T **>();
  constexpr int classInfoOffset = 14;
  constexpr int methodOffset = classInfoOffset + ObjI::classInfoCount * 2;
  constexpr int propertyOffset = methodOffset + ObjI::methodCount * 5;
  constexpr int enumOffset =
      propertyOffset + ObjI::propertyCount * (hasNotify ? 4 : 3);
  constexpr int constructorOffset =
      enumOffset +
      ObjI::enumCount *
          (((5 << 16) | (15 << 8) | (0)) >= ((5 << 16) | (12 << 8) | (0)) ? 5
                                                                          : 4);
  constexpr int paramIndex = constructorOffset + ObjI::constructorCount * 5;
  constexpr int constructorParamIndex =
      paramIndex + methodsParamOffset<L, T **>();
  constexpr int enumValueOffset =
      constructorParamIndex + constructorParamOffset<L, T **>();

  state.addInts(
      ((5 << 16) | (15 << 8) | (0)) >= ((5 << 16) | (12 << 8) | (0)) ? 8 : 7);
  state.addString(ObjI::name);
  state.addStringUntracked(viewLiteral(""));
  state.addInts(ObjI::classInfoCount, classInfoOffset, ObjI::methodCount,
                methodOffset, ObjI::propertyCount, propertyOffset,
                ObjI::enumCount, enumOffset, ObjI::constructorCount,
                constructorOffset, 0x4, ObjI::signalCount);

  foldState<L, ClassInfoStateTag, T **>(ClassInfoGenerator<State>{state});

  foldMethods<L, T **>(MethodGenerator<State, T>{state, paramIndex});

  foldState<L, PropertyStateTag, T **>(PropertyGenerator<State, T>{state});
  foldState<L, PropertyStateTag, T **>(
      NotifySignalGenerator<State, L, T, hasNotify>{state});

  foldState<L, EnumStateTag, T **>(
      EnumGenerator<State>{state, enumValueOffset});

  foldState<L, ConstructorStateTag, T **>(
      MethodGenerator<State, T>{state, constructorParamIndex});

  foldMethods<L, T **>(MethodParametersGenerator<State>{state});

  foldState<L, ConstructorStateTag, T **>(
      ConstructorParametersGenerator<State>{state});

  foldState<L, EnumStateTag, T **>(EnumValuesGenerator<State>{state});
}
template <class T> constexpr auto createLayout() {
  auto r = LayoutBuilder{};
  generateDataPass<T>(r);
  return r;
}
template <class T> constexpr LayoutBuilder dataLayout = createLayout<T>();

template <std::size_t StringSize, std::size_t StringCount, std::size_t IntCount>
struct MetaDataHolder {
  RawArray<QByteArrayData, StringCount> byteArrays;
  OwnArray<char, StringSize> stringChars;

  OwnArray<uint, IntCount> ints;
};
template <class T> struct MetaDataProvider {
  static constexpr auto stringSize = dataLayout<T>.stringSize;
  static constexpr auto stringCount = dataLayout<T>.stringCount;
  static constexpr auto intCount = dataLayout<T>.intCount;
  using MetaDataType = const MetaDataHolder<stringSize, stringCount, intCount>;

  struct Arrays {

    constexpr static qptrdiff stringOffset =
        __builtin_offsetof(MetaDataType, stringChars);

    RawArray<qptrdiff, stringCount> stringOffsets{};
    RawArray<int, stringCount> stringLengths{};
    RawArray<char, stringSize> stringChars{};
    RawArray<uint, intCount> ints{};
  };
  constexpr static auto buildArrays() {
    auto r = Arrays{};
    DataBuilder b{r};
    generateDataPass<T>(b);
    return r;
  }
  constexpr static Arrays arrays = buildArrays();
};

template <class T, class IS> struct MetaDataBuilder;
template <class T, std::size_t... Is>
struct MetaDataBuilder<T, index_sequence<Is...>> {
  using P = MetaDataProvider<T>;
  using MetaDataType = typename P::MetaDataType;

  static MetaDataType meta_data;
};

template <class T, std::size_t... Is>
typename MetaDataBuilder<T, index_sequence<Is...>>::MetaDataType
    MetaDataBuilder<T, index_sequence<Is...>>::meta_data = {
        {{{{-1}},
          P::arrays.stringLengths[Is],
          0,
          0,
          P::arrays.stringOffsets[Is]}...},
        {P::arrays.stringChars},
        {P::arrays.ints}};

template <typename T>
static constexpr auto parentMetaObject(int)
    -> decltype(&T::W_BaseType::staticMetaObject) {
  return &T::W_BaseType::staticMetaObject;
}

template <typename T>
static constexpr const QMetaObject *parentMetaObject(...) {
  return nullptr;
}

template <typename F, typename O, typename T>
inline auto propSet(F f, O *o, const T &t) -> decltype(((o->*f)(t), 0)) {
  return ((o->*f)(t), 0);
}
template <typename F, typename O, typename T>
inline auto propSet(F f, O *o, const T &t) -> decltype(o->*f = t) {
  return o->*f = t;
}
template <typename O, typename T> inline void propSet(Empty, O *, const T &) {}

template <typename F, typename O, typename T>
inline auto propGet(F f, O *o, T &t) -> decltype(t = (o->*f)()) {
  return t = (o->*f)();
}
template <typename F, typename O, typename T>
inline auto propGet(F f, O *o, T &t) -> decltype(t = o->*f) {
  return t = o->*f;
}
template <typename O, typename T> inline void propGet(Empty, O *, T &) {}

template <typename F, typename M, typename O>
inline auto propNotify(F f, M m, O *o) -> decltype(((o->*f)(o->*m), 0)) {
  return ((o->*f)(o->*m), 0);
}
template <typename F, typename M, typename O>
inline auto propNotify(F f, M, O *o) -> decltype(((o->*f)(), 0)) {
  return ((o->*f)(), 0);
}
template <typename... T> inline void propNotify(T...) {}

template <typename F, typename O>
inline auto propReset(F f, O *o) -> decltype(((o->*f)(), 0)) {
  return ((o->*f)(), 0);
}
template <typename... T> inline void propReset(T...) {}

struct FriendHelper {

  template <typename T> static constexpr QMetaObject createMetaObject() {
    using MetaData =
        MetaDataBuilder<T, make_index_sequence<dataLayout<T>.stringCount>>;

    return {{parentMetaObject<T>(0),
             MetaData::meta_data.byteArrays,
             MetaData::meta_data.ints.data,
             T::qt_static_metacall,
             {},
             {}}};
  }

  template <typename T>
  static int qt_metacall_impl(T *_o, QMetaObject::Call _c, int _id, void **_a) {
    using ObjI = typename T::W_MetaObjectCreatorHelper::ObjectInfo;
    _id = _o->T::W_BaseType::qt_metacall(_c, _id, _a);
    if (_id < 0)
      return _id;
    if (_c == QMetaObject::InvokeMetaMethod ||
        _c == QMetaObject::RegisterMethodArgumentMetaType) {
      constexpr int methodCount = ObjI::methodCount;
      if (_id < methodCount)
        T::qt_static_metacall(_o, _c, _id, _a);
      _id -= methodCount;
    } else if ((_c >= QMetaObject::ReadProperty &&
                _c <= QMetaObject::QueryPropertyUser) ||
               _c == QMetaObject::RegisterPropertyMetaType) {
      constexpr int propertyCount = ObjI::propertyCount;
      if (_id < propertyCount)
        T::qt_static_metacall(_o, _c, _id, _a);
      _id -= propertyCount;
    }
    return _id;
  }

  template <typename T, int I> static int indexOfMethod(void **func) {
    using ObjI = typename T::W_MetaObjectCreatorHelper::ObjectInfo;
    constexpr auto m = ObjI::method(index<I>);
    if ((m.flags & 0xc) == W_MethodType::Signal.value &&
        m.func == *reinterpret_cast<decltype(m.func) *>(func))
      return I;
    return -1;
  }

  template <typename T, int I>
  static void invokeMethod(T *_o, int _id, void **_a) {
    if (_id == I) {
      using ObjI = typename T::W_MetaObjectCreatorHelper::ObjectInfo;
      constexpr auto f = ObjI::method(index<I>).func;
      using P = QtPrivate::FunctionPointer<std::remove_const_t<decltype(f)>>;
      P::template call<typename P::Arguments, typename P::ReturnType>(f, _o,
                                                                      _a);
    }
  }

  template <typename T, int I>
  static void registerMethodArgumentType(int _id, void **_a) {
    if (_id == I) {
      using ObjI = typename T::W_MetaObjectCreatorHelper::ObjectInfo;
      constexpr auto f = ObjI::method(index<I>).func;
      using P = QtPrivate::FunctionPointer<std::remove_const_t<decltype(f)>>;
      auto _t = QtPrivate::ConnectionTypes<typename P::Arguments>::types();
      uint arg = *reinterpret_cast<uint *>(_a[1]);
      *reinterpret_cast<int *>(_a[0]) =
          _t && arg < P::ArgumentCount ? _t[arg] : -1;
    }
  }

  template <typename T, int I>
  static void propertyOperation(T *_o, QMetaObject::Call _c, int _id,
                                void **_a) {
    if (_id != I)
      return;
    using TPP = T **;
    constexpr auto p = w_state(index<I>, PropertyStateTag{}, TPP{});
    using Type = typename decltype(p)::PropertyType;
    switch (+_c) {
    case QMetaObject::ReadProperty:
      if (p.getter) {
        propGet(p.getter, _o, *reinterpret_cast<Type *>(_a[0]));
      } else if (p.member) {
        propGet(p.member, _o, *reinterpret_cast<Type *>(_a[0]));
      }
      break;
    case QMetaObject::WriteProperty:
      if (p.setter) {
        propSet(p.setter, _o, *reinterpret_cast<Type *>(_a[0]));
      } else if (p.member) {
        propSet(p.member, _o, *reinterpret_cast<Type *>(_a[0]));
        propNotify(p.notify, p.member, _o);
      }
      break;
    case QMetaObject::ResetProperty:
      if (p.reset) {
        propReset(p.reset, _o);
      }
      break;
    case QMetaObject::RegisterPropertyMetaType:
      *reinterpret_cast<int *>(_a[0]) =
          QtPrivate::QMetaTypeIdHelper<Type>::qt_metatype_id();
    }
  }

  template <typename T, class... Args, std::size_t... I>
  static void createInstanceImpl(void **_a,
                                 const MetaConstructorInfo<Args...> &,
                                 index_sequence<I...>) {
    *reinterpret_cast<T **>(_a[0]) =
        new T(*reinterpret_cast<std::remove_reference_t<Args> *>(_a[I + 1])...);
  }
  template <typename T, int I> static void createInstance(int _id, void **_a) {
    if (_id == I) {
      using TPP = T **;
      constexpr auto m = w_state(index<I>, ConstructorStateTag{}, TPP{});
      createInstanceImpl<T>(_a, m, m.argSequence);
    }
  }

  template <typename T, size_t... MethI, size_t... ConsI, size_t... PropI>
  static void qt_static_metacall_impl2(QObject *_o, QMetaObject::Call _c,
                                       int _id, void **_a,
                                       std::index_sequence<MethI...>,
                                       std::index_sequence<ConsI...>,
                                       std::index_sequence<PropI...>) {
    (void)_id;
    (void)_o;
    (void)_a;
    if (_c == QMetaObject::InvokeMetaMethod) {
      ((T::staticMetaObject.cast(_o))
           ? static_cast<void>(0)
           : qt_assert("T::staticMetaObject.cast(_o)",
                       "./verdigris/wobjectimpl.h", 964));

      ordered(
          (invokeMethod<T, MethI>(reinterpret_cast<T *>(_o), _id, _a), 0)...);

    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {

      ordered((registerMethodArgumentType<T, MethI>(_id, _a), 0)...);

    } else if (_c == QMetaObject::IndexOfMethod) {

      auto r = int{-1};
      ordered2<int>({(r += (1 + indexOfMethod<T, MethI>(
                                    reinterpret_cast<void **>(_a[1]))))...});
      *reinterpret_cast<int *>(_a[0]) = r;

    } else if (_c == QMetaObject::CreateInstance) {

      ordered((createInstance<T, ConsI>(_id, _a), 0)...);

    } else if ((_c >= QMetaObject::ReadProperty &&
                _c <= QMetaObject::QueryPropertyUser) ||
               _c == QMetaObject::RegisterPropertyMetaType) {

      ordered((propertyOperation<T, PropI>(static_cast<T *>(_o), _c, _id, _a),
               0)...);
    }
  }

  template <typename T, size_t... MethI, size_t... ConsI, size_t... PropI>
  static void qt_static_metacall_impl2(T *_o, QMetaObject::Call _c, int _id,
                                       void **_a, std::index_sequence<MethI...>,
                                       std::index_sequence<ConsI...>,
                                       std::index_sequence<PropI...>) {
    (void)_id;
    (void)_o;
    (void)_a;
    if (_c == QMetaObject::InvokeMetaMethod) {

      ordered((invokeMethod<T, MethI>(_o, _id, _a), 0)...);

    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {

      ordered((registerMethodArgumentType<T, MethI>(_id, _a), 0)...);

    } else if (_c == QMetaObject::IndexOfMethod) {
      ((false) ? static_cast<void>(0)
               : qt_assert_x("qt_static_metacall",
                             "IndexOfMethod called on a Q_GADGET",
                             "./verdigris/wobjectimpl.h", 1018));
    } else if (_c == QMetaObject::CreateInstance) {

      ordered((createInstance<T, ConsI>(_id, _a), 0)...);

    } else if ((_c >= QMetaObject::ReadProperty &&
                _c <= QMetaObject::QueryPropertyUser) ||
               _c == QMetaObject::RegisterPropertyMetaType) {

      ordered((propertyOperation<T, PropI>(_o, _c, _id, _a), 0)...);
    }
  }

  template <typename T, typename... Ts>
  static void qt_static_metacall_impl(Ts &&...args) {
    using ObjI = typename T::W_MetaObjectCreatorHelper::ObjectInfo;
    return qt_static_metacall_impl2<T>(
        std::forward<Ts>(args)..., ObjI::methodSequence,
        ObjI::constructorSequence, ObjI::propertySequence);
  }

  template <typename T>
  static void *qt_metacast_impl(T *o, const char *_clname) {
    if (!_clname)
      return nullptr;
    const QByteArrayDataPtr sd = {
        const_cast<QByteArrayData *>(T::staticMetaObject.d.stringdata)};
    if (_clname == QByteArray(sd))
      return o;
    using ObjI = typename T::W_MetaObjectCreatorHelper::ObjectInfo;
    void *result = {};
    auto l = [&](auto i) {
      using TPP = T **;
      using Interface = decltype(w_state(i, InterfaceStateTag{}, TPP{}));
      const char *iid = qobject_interface_iid<Interface>();
      if (iid && !strcmp(_clname, iid))
        result = static_cast<Interface>(o);
    };
    fold(ObjI::interfaceSequence, l);
    if (!result)
      return o->T::W_BaseType::qt_metacast(_clname);
    return result;
  }
};

} // namespace w_internal

struct MyObject::W_MetaObjectCreatorHelper {
  struct Name {
    static constexpr auto defaultName = w_internal::viewLiteral("MyObject");
    static constexpr auto value =
        w_internal::fetchExplicitName<typename MyObject::W_ThisType>(
            defaultName, 0);
  };
  using ObjectInfo =
      w_internal::ObjectInfo<typename MyObject::W_ThisType, Name>;
};
const QMetaObject MyObject::staticMetaObject =
    w_internal::FriendHelper::createMetaObject<typename MyObject::W_ThisType>();
void MyObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id,
                                  void **_a) {
  w_internal::FriendHelper::qt_static_metacall_impl<MyObject>(_o, _c, _id, _a);
}
const QMetaObject *MyObject::metaObject() const { return &staticMetaObject; }
void *MyObject::qt_metacast(const char *_clname) {
  return w_internal::FriendHelper::qt_metacast_impl<MyObject>(this, _clname);
}
int MyObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a) {
  return w_internal::FriendHelper::qt_metacall_impl<MyObject>(this, _c, _id,
                                                              _a);
}

void aaa(MyObject *obj1) {
  bool ok = true;

  ok = ok && QObject::connect(obj1,
                              qFlagLocation("2"
                                            "mySignal(QString)"
                                            "\0"
                                            "example.cpp"
                                            ":"
                                            "18"),
                              obj1,
                              qFlagLocation("1"
                                            "mySlot(QString)"
                                            "\0"
                                            "example.cpp"
                                            ":"
                                            "18"));
  ((ok) ? static_cast<void>(0) : qt_assert("ok", "example.cpp", 19));
}

int main() {
  MyObject o;
  aaa(&o);
  o.mySlot("world");
}
