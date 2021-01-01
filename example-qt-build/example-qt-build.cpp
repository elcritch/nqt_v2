
#include "example-qt-build.h"

/* Here is what would go in the C++ .cpp file: */

// That's it! MyObject is a QObject that can be used in QML or connected.
void aaa(MyObject *obj1) {
    bool ok = true;
    // new syntax
    // ok = ok && QObject::connect(obj1, &MyObject::mySignal, obj1, &MyObject::mySlot);

    // old syntax
    ok = ok && QObject::connect(obj1, SIGNAL(mySignal(QString)), obj1, SLOT(mySlot(QString)));
    Q_ASSERT(ok);
}


/** ******************************************************************************************** **/

int main() {
    MyObject o;
    aaa(&o);
    emit o.mySlot("world"); // Will show the qDebug twice
}
