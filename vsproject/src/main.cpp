#include "osdesign.h"
#include <QtWidgets/QApplication>
#pragma comment(lib, "tinyxml2.lib")

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    osDesign w;
    w.show();
    return a.exec();
}
