#pragma once
#include "../../GeneratedFiles/ui_osdesign.h"
#include "filesystem.h"
namespace Ui {
    class osDesignClass;
} // namespace Ui

class Ui::osDesignClass : public Ui_osDesignClass
{
    Q_OBJECT
private:
    Filesystem* fsm;
public:
    osDesignClass(QWidget* parent = 0);
};