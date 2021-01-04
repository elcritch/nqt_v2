

#define QT_MOC_LITERAL(idx, ofs, len)                          \
  Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
  qptrdiff(offsetof(qt_meta_stringdata_MyObject_t, stringdata0) + ofs - idx * sizeof(QByteArrayData))
