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

// In a header file you would include the wobjectdefs.h header
// This is equivalent to the qobjectdefs.h header
#include <verdigris/wobjectdefs.h>
// And because you will inherit from QObject you also need to QObject header
#include <QObject>

// Now declare your class:
class MyObject : public QObject
{
    /** The W_OBJECT macro is equivalent to the Q_OBJECT macro. The difference is that it must
       contains the class name as a parameter and need to be put before any other W_ macro in the
       class. So it's the same as the CS_OBJECT macro from CopperSpice. */
    W_OBJECT(MyObject)

public /* slots */:

    // Here we declare a slot:
    void mySlot(const QString &name) { qDebug("hello %s", qPrintable(name)); }
    /* If you're going to use the new connection syntax, no need to do anything else for slots.
       But if you want to use the other connection syntax, or QML, you need to register the slot
       just like so: */
    W_SLOT(mySlot)
    /* The W_SLOT has optional arguments that we will see later. It is already much simpler than
       the two CopperSpice macros: CS_SLOT_1 and CS_SLOT_2. Also, CopperSpice slots cannot be
       declared inline in the class definition. */

public /* signals */:

    // Now a signal:
    void mySignal(const QString &name)
    W_SIGNAL(mySignal, name)
    /* Note the absence of semi colon after the signal declaration */
};

