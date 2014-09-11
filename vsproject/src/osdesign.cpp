#include "osdesign.h"
#include <vector>
#include <QMessageBox>
#include <QInputDialog>
#include <QLineEdit>

using std::vector;

osDesign::osDesign(QWidget *parent)
    : QMainWindow(parent)
{
    fsm = new Filesystem();
    _setupUi(this);
    //alert(QStringLiteral("中文"));


    //打开自定义
    treeFile->setContextMenuPolicy(Qt::CustomContextMenu);
    //连接信号和槽
    connect(treeFile, SIGNAL(customContextMenuRequested(const QPoint)), this, SLOT(showFileListsContextMenu(const QPoint))); 
    //双击事件
    connect(treeFile, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),this,SLOT(open(QTreeWidgetItem*,int)));
    connectToolBar();
}
void osDesign::_setupUi(QMainWindow* p)
{
    setupUi(this);
    refreshFileLists();
}
void osDesign::refreshFileLists()
{
    treeFile->clear();
    vector<XMLElement*> vxe;
   fsm->ls(vxe);

   //父级目录
   myon::File* file = new myon::File(vxe.at(0));
   QStringList columnTitle;
    columnTitle.append("..");
    QTreeWidgetItem* parentDir = new QTreeWidgetItem(columnTitle);
    treeFile->addTopLevelItem(parentDir); 

    //构建当前目录文件列表
    for(int i=1; i<vxe.size(); i++)
    {
        file = new myon::File(vxe.at(i));
        QStringList columnTitle;
        columnTitle.append(file->getFilename().c_str());
        if(file->getType() == 1)
            columnTitle.append(QStringLiteral("文件"));
        else
            columnTitle.append(QStringLiteral("文件夹"));
        columnTitle.append("2014-9-12");
        columnTitle.append(myon::User(file->getOwner()).getName().c_str());
        string perstr = vxe.at(i)->Attribute("permission");
        //rwx权限
        string rwx_str = "";
        for(int i=9; i>0; i--)
        {
            if(i % 3 ==0 && perstr[i - 1] == '1')  rwx_str += "r";
            else if(i % 3 ==0 && perstr[i - 1] == '0')  rwx_str += "-";
            else if(i % 3 ==2 && perstr[i - 1] == '1')  rwx_str += "w";
            else if(i % 3 ==2 && perstr[i - 1] == '0')  rwx_str += "-";
            else if(i % 3 ==1 && perstr[i - 1] == '1')  rwx_str += "x";
            else if(i % 3 ==1 && perstr[i - 1] == '0')  rwx_str += "-";
        }
        columnTitle.append(rwx_str.c_str());
        QTreeWidgetItem *dir = new QTreeWidgetItem(columnTitle);
        treeFile->addTopLevelItem(dir); 
    }
}

 void osDesign::showFileListsContextMenu(const QPoint &point)
 {
    QMenu *qMenu = new QMenu(treeFile);
    QModelIndex indexSelect = treeFile->indexAt(point);                         //获得当前右击事件的节点
    QModelIndex indexParent = indexSelect.parent();                             //获得当前右击事件节点的父节点
    int row = indexSelect.row();                                                                //获得当前右击事件的树形节点所在的行
    QModelIndex indexData = indexParent.child(row,1);                           //获得当前右击事件节点父节点的第row行的第二列的节点
    QString QStr;
    QStr = indexSelect.data().toString();                                                   //获得当前右击事件的节点数据
    if(QStr != "")                                                                                      //如果当前右击事件在节点范围内，即树形节点上则显示右键的菜单
    {
        QAction* openAction = new QAction(QStringLiteral("&打开"),this);
        QAction* touchAction = new QAction(QStringLiteral("&新建文件"),this);
        QAction* mkdirAction = new QAction(QStringLiteral("&新建文件夹"),this);
        QAction* deleteAction = new QAction(QStringLiteral("&删除"),this);
        QAction* renameAction = new QAction(QStringLiteral("&重命名"),this);
        QAction* permissionAction = new QAction(QStringLiteral("&设置权限"),this);
        qMenu->addAction(openAction);
        qMenu->addAction(touchAction);
        qMenu->addAction(mkdirAction);
        qMenu->addAction(renameAction);
        qMenu->addAction(deleteAction);
        qMenu->addAction(permissionAction);
        //打开事件
        connect(openAction, SIGNAL(triggered(bool)), this, SLOT(open()));    
        //删除
        connect(deleteAction, SIGNAL(triggered(bool)), this, SLOT(rm()));    
        connect(touchAction, SIGNAL(triggered(bool)), this, SLOT(touch()));    
        connect(mkdirAction, SIGNAL(triggered(bool)), this, SLOT(mkdir()));    
        connect(renameAction, SIGNAL(triggered(bool)), this, SLOT(rename()));    
        connect(permissionAction, SIGNAL(triggered(bool)), this, SLOT(setPermission()));    
        qMenu->exec(QCursor::pos());
     }
 }

 void osDesign::open(int index)
 {
     int row = index;      //当前选中的行
     vector<XMLElement*> vxe;
     fsm->ls(vxe);
     XMLElement* xFile = vxe.at(row);
     myon::File* file = new myon::File(xFile);
     if(file->getType() == 1)       //文件则打开编辑
     {
         string content;
         if(fsm->read(xFile, content) == false)
             alert(QStringLiteral("你没有权限读取该文件内容"));
         else
         {
            bool isOK;
            QString text = QInputDialog::getText(NULL, QStringLiteral("文件内容"),
               QStringLiteral("文件内容"),
               QLineEdit::Normal,
               content.c_str(),
               &isOK);
            if(isOK) 
            {
                if(fsm->write(xFile, text.toStdString()) == false)
                    alert(QStringLiteral("你没有权限修改文件"));
                else
                    refreshFileLists();
            }
         }
     }
     else   //文件夹调用cd
     {
         bool temp = fsm->cd(xFile);
         if(temp == false)
             alert(QStringLiteral("你没有权限打开该文件夹"));
         else
         {
             labelCurrentPath->setText(tr(fsm->getCurrentPath().c_str()));
             refreshFileLists();
         }
     }
 }
 void osDesign::open()
 {
     int row = treeFile->currentIndex().row();      //当前选中的行
     open(row);
 }
 void osDesign::open(QTreeWidgetItem* ti, int index)
 {
     open(index);
 }
 
 void osDesign::rm()
 {
    QMessageBox   mb(QStringLiteral("删除确认"), QStringLiteral("确认删除此项?"),
    QMessageBox::Question,
    QMessageBox::Yes   |   QMessageBox::Default,
    QMessageBox::No     |   QMessageBox::Escape,
    QMessageBox::NoButton);   
    if(mb.exec() == QMessageBox::No)
       return;

     int row = treeFile->currentIndex().row();      //当前选中的行
     vector<XMLElement*> vxe;
     fsm->ls(vxe);
     XMLElement* xFile = vxe.at(row);
     if(fsm->rm(xFile))
        refreshFileLists();
     else
         alert(QStringLiteral("你没有权限删除这个文件"));
 }

 void osDesign::touch()
 {
    bool isOK;
    QString text = QInputDialog::getText(NULL, QStringLiteral("输入文件名"),
       QStringLiteral("输入文件名"),
       QLineEdit::Normal,
       QStringLiteral("new file"),
       &isOK);
    if(isOK) 
    {
        if(fsm->touch(text.toStdString()) == false)
            alert(QStringLiteral("你没有在这里权限创建文件"));
        else
            refreshFileLists();
    }
 }

  void osDesign::mkdir()
 {
    bool isOK;
    QString text = QInputDialog::getText(NULL, QStringLiteral("输入文件夹名"),
       QStringLiteral("输入文件夹名"),
       QLineEdit::Normal,
       QStringLiteral("new directory"),
       &isOK);
    if(isOK) 
    {
        if(fsm->mkdir(text.toStdString()) == false)
            alert(QStringLiteral("你没有在这里权限创建文件夹"));
        else
            refreshFileLists();
    }
 }

  void osDesign::rename()
  {
     int row = treeFile->currentIndex().row();      //当前选中的行
     vector<XMLElement*> vxe;
     fsm->ls(vxe);
     XMLElement* xFile = vxe.at(row);

    bool isOK;
    QString text = QInputDialog::getText(NULL, QStringLiteral("输入文件名"),
       QStringLiteral("输入文件名"),
       QLineEdit::Normal,
       xFile->Attribute("filename"),
       &isOK);
    if(isOK) 
    {
        if(fsm->rename(xFile, text.toStdString()) == false)
            alert(QStringLiteral("你没有权限重命名该文件"));
        else
            refreshFileLists();
    }
  }

  void osDesign::setPermission()
  {
     int row = treeFile->currentIndex().row();      //当前选中的行
     vector<XMLElement*> vxe;
     fsm->ls(vxe);
     XMLElement* xFile = vxe.at(row);

    bool isOK;
    string old_permission = xFile->Attribute("permission");
    old_permission.assign(old_permission.rbegin(), old_permission.rend());
    QString text = QInputDialog::getText(NULL, QStringLiteral("设置权限"),
       QStringLiteral("3组rwx的字符串，如：111101101"),
       QLineEdit::Normal,
       old_permission.c_str(),
       &isOK);
    if(isOK) 
    {
        if(fsm->setPermission(xFile, text.toStdString()) == false)
            alert(QStringLiteral("你没有权限重命名该文件"));
        else
            refreshFileLists();
    }
  }

  void osDesign::switchUser()
  {
    bool isOK;
    QString text = QInputDialog::getText(NULL, QStringLiteral("输入用户名"),
       QStringLiteral("输入用户名"),
       QLineEdit::Normal,
       "root",
       &isOK);
    if(isOK) 
    {
        myon::User* user = new myon::User(text.toStdString());
        if(user->getName() != text.toStdString())
            alert(QStringLiteral("系统没有这个用户"));
        else
            fsm->setUser(user);
    }
  }


 void osDesign::alert(QString str)
 {
    QMessageBox msg;
    msg.setText(str);
    msg.exec();
 }
  void osDesign::test()
 {
    QMessageBox msg;
    msg.setText("dfdsf");
    msg.exec();
 }


  void osDesign::connectToolBar()
  {
    connect(actionSwitchUser, SIGNAL(triggered(bool)), this, SLOT(switchUser()));    
  }

osDesign::~osDesign()
{
}
