/**
  This file presents Verdigris, a "fork" of CopperSpice.

  CopperSpice is a fork of Qt 4 whose specificity is to get rid of moc (Qt Meta-object compiler)
  In order to get rid of moc, they changed the Qt macros to be less optimal.
  They made a complete, incompatible fork of Qt.

  Verdigris is not a fork of CopperSpice, but rather a re-implementation of their macro in a way
  that is binary compatible with Qt. You can write your application without needing moc, and still
  use it with existing Qt 5 releases.

  CopperSpice generates the metaobjects at run-time. But moc generates them at compile time.
  Verdigris uses constexpr to generate QMetaObject at compile time.
  It is using C++14 for simplicity because it is much more easy to handle constexpr.
  The code is originally taken from my previous work
  https://woboq.com/blog/reflection-in-cpp-and-qt-moc.html
  In that experiment, I was trying to use same macros that Qt does (keeping source compatibility).
  When using more complex but uglier macros (CopperSpice style) we can do it without the moc.

 */


/** ******************************************************************************************** **/
/** INTRODUCTION **/

#include <QObject>

// Now declare your class:
class MyObject : public QObject
{
    Q_OBJECT

public slots:

    // Here we declare a slot:
    void mySlot(const QString &name) { qDebug("hello %s", qPrintable(name)); }
    /* If you're going to use the new connection syntax, no need to do anything else for slots.
       But if you want to use the other connection syntax, or QML, you need to register the slot
       just like so: */

signals:

    // Now a signal:
    void mySignal(const QString &name);

};

