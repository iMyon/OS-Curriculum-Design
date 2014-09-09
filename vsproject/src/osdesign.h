#ifndef OSDESIGN_H
#define OSDESIGN_H

#include <QtWidgets/QMainWindow>
#include "ui_osdesign.h"
#include"func/include/filesystem.h"

class osDesign : public QMainWindow, public Ui::osDesignClass
{
    Q_OBJECT

private:
    
public:
    osDesign(QWidget *parent = 0);
    ~osDesign();
};

#endif // OSDESIGN_H
