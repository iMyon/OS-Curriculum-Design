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
    void open(int);        //���ļ�������޷����򷵻ش�����Ϣ
    void open();       
    void open(QTreeWidgetItem*, int index);        
    void rm();          //ɾ���ļ�
    void touch();           //�����ļ�
    void mkdir();       //�����ļ���
    void rename();
    //void read();
    //void write();
    void setPermission();

    void switchUser();
    
    void refreshFileLists();        //ˢ���б�
    //�ļ��б��Ҽ��˵�
     void showFileListsContextMenu(const QPoint &point);
};

#endif // OSDESIGN_H
