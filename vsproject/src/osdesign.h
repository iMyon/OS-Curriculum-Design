#ifndef OSDESIGN_H
#define OSDESIGN_H

#include <QtWidgets/QMainWindow>
#include "ui_osdesign.h"

class osDesign : public QMainWindow
{
    Q_OBJECT

public:
    osDesign(QWidget *parent = 0);
    ~osDesign();

private:
    Ui::osDesignClass ui;
};

#endif // OSDESIGN_H
