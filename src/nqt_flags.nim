type

  QTypeExtensionFlag* = enum
    NoExtensionFlags = 0x0,
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

  QTypeFlags* = enum
    Bool = 1,
    Int = 2,
    UInt = 3,
    LongLong = 4,
    ULongLong = 5,
    Double = 6,

    QChar = 7,
    QVariantMap = 8,
    QVariantList = 9,

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
    QVariantHash = 28,
    QEasingCurve = 29,
    QUuid = 30,

    VoidStar = 31,
    Long = 32,
    Short = 33,
    Char = 34,
    ULong = 35,
    UShort = 36,
    UChar = 37,
    Float = 38,
    QObjectStar = 39,
    SChar = 40,


    QVariant = 41,
    QModelIndex = 42,
    Void = 43,
    QRegularExpression = 44,
    QJsonValue = 45,
    QJsonObject = 46,
    QJsonArray = 47,
    QJsonDocument = 48,
    QByteArrayList = 49,
    QPersistentModelIndex = 50,
    Nullptr = 51,
    QCborSimpleType = 52,

    QCborValue = 53,
    QCborArray = 54,
    QCborMap = 55,


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


let
  FirstCoreType* = Bool
  LastCoreType* = QCborMap
  FirstGuiType* = QFont
  LastGuiType* = QColorSpace
  FirstWidgetsType* = QSizePolicy
  LastWidgetsType* = QSizePolicy
  HighestInternalId* = LastWidgetsType
  QReal* = Double
  UnknownType* = 0
  User* = 1024

type
  TypeFlag* = enum
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

