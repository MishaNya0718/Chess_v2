#include "MainWindow.h"
#include <Core.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Core *coreObject = new Core(&a);
    MainWindow w;
    w.resize(500, 500);
    w.show();
    return a.exec();
}
