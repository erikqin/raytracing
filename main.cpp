#include <QApplication>
#include "qt_cal.h"

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    qt_cal mainwindow;
    mainwindow.showMaximized();
    return app.exec();

}
