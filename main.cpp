#include <QtGui/QApplication>
#include "pingpong.h"
#include "testgui.h"

int main(int argc, char *argv[])
{
    #define APP_TEST
    QApplication a(argc, argv);
    PingPong w;
#if defined(Q_WS_S60)
    w.showMaximized();
#else
    w.show();
#endif

    TestGui test;

    #ifndef APP_TEST
     return a.exec();
    #else
        QTest::qExec(&test);
    #endif

}
