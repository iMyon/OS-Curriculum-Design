#ifndef OSDESIGN_H
#define OSDESIGN_H

#include <QtWidgets/QMainWindow>
#include "ui_osdesign.h"
#include"func/include/filesystem.h"

class osDesign : public QMainWindow, public Ui::osDesignClass
{
    Q_OBJECT

private:
    Filesystem* fsm;
public:
    void _setupUi(QMainWindow*);
    osDesign(QWidget *parent = 0);
    ~osDesign();
    void connectToolBar();
public slots:
    void alert(QString str);
    void test();
    void open(int);        //打开文件，如果无法打开则返回错误信息
    void open();       
    void open(QTreeWidgetItem*, int index);        
    void rm();          //删除文件
    void touch();           //创建文件
    void mkdir();       //创建文件夹
    void rename();
    //void read();
    //void write();
    void setPermission();

    void switchUser();
    
    void refreshFileLists();        //刷新列表
    //文件列表右键菜单
     void showFileListsContextMenu(const QPoint &point);
};

#endif // OSDESIGN_H
