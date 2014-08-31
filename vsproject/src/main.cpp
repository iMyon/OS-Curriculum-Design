#include "osdesign.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    osDesign w;
    w.show();
    return a.exec();
}
