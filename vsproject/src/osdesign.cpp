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
    //alert(QStringLiteral("����"));


    //���Զ���
    treeFile->setContextMenuPolicy(Qt::CustomContextMenu);
    //�����źźͲ�
    connect(treeFile, SIGNAL(customContextMenuRequested(const QPoint)), this, SLOT(showFileListsContextMenu(const QPoint))); 
    //˫���¼�
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

   //����Ŀ¼
   myon::File* file = new myon::File(vxe.at(0));
   QStringList columnTitle;
    columnTitle.append("..");
    QTreeWidgetItem* parentDir = new QTreeWidgetItem(columnTitle);
    treeFile->addTopLevelItem(parentDir); 

    //������ǰĿ¼�ļ��б�
    for(int i=1; i<vxe.size(); i++)
    {
        file = new myon::File(vxe.at(i));
        QStringList columnTitle;
        columnTitle.append(file->getFilename().c_str());
        if(file->getType() == 1)
            columnTitle.append(QStringLiteral("�ļ�"));
        else
            columnTitle.append(QStringLiteral("�ļ���"));
        columnTitle.append("2014-9-12");
        columnTitle.append(myon::User(file->getOwner()).getName().c_str());
        string perstr = vxe.at(i)->Attribute("permission");
        //rwxȨ��
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
    QModelIndex indexSelect = treeFile->indexAt(point);                         //��õ�ǰ�һ��¼��Ľڵ�
    QModelIndex indexParent = indexSelect.parent();                             //��õ�ǰ�һ��¼��ڵ�ĸ��ڵ�
    int row = indexSelect.row();                                                                //��õ�ǰ�һ��¼������νڵ����ڵ���
    QModelIndex indexData = indexParent.child(row,1);                           //��õ�ǰ�һ��¼��ڵ㸸�ڵ�ĵ�row�еĵڶ��еĽڵ�
    QString QStr;
    QStr = indexSelect.data().toString();                                                   //��õ�ǰ�һ��¼��Ľڵ�����
    if(QStr != "")                                                                                      //�����ǰ�һ��¼��ڽڵ㷶Χ�ڣ������νڵ�������ʾ�Ҽ��Ĳ˵�
    {
        QAction* openAction = new QAction(QStringLiteral("&��"),this);
        QAction* touchAction = new QAction(QStringLiteral("&�½��ļ�"),this);
        QAction* mkdirAction = new QAction(QStringLiteral("&�½��ļ���"),this);
        QAction* deleteAction = new QAction(QStringLiteral("&ɾ��"),this);
        QAction* renameAction = new QAction(QStringLiteral("&������"),this);
        QAction* permissionAction = new QAction(QStringLiteral("&����Ȩ��"),this);
        qMenu->addAction(openAction);
        qMenu->addAction(touchAction);
        qMenu->addAction(mkdirAction);
        qMenu->addAction(renameAction);
        qMenu->addAction(deleteAction);
        qMenu->addAction(permissionAction);
        //���¼�
        connect(openAction, SIGNAL(triggered(bool)), this, SLOT(open()));    
        //ɾ��
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
     int row = index;      //��ǰѡ�е���
     vector<XMLElement*> vxe;
     fsm->ls(vxe);
     XMLElement* xFile = vxe.at(row);
     myon::File* file = new myon::File(xFile);
     if(file->getType() == 1)       //�ļ���򿪱༭
     {
         string content;
         if(fsm->read(xFile, content) == false)
             alert(QStringLiteral("��û��Ȩ�޶�ȡ���ļ�����"));
         else
         {
            bool isOK;
            QString text = QInputDialog::getText(NULL, QStringLiteral("�ļ�����"),
               QStringLiteral("�ļ�����"),
               QLineEdit::Normal,
               content.c_str(),
               &isOK);
            if(isOK) 
            {
                if(fsm->write(xFile, text.toStdString()) == false)
                    alert(QStringLiteral("��û��Ȩ���޸��ļ�"));
                else
                    refreshFileLists();
            }
         }
     }
     else   //�ļ��е���cd
     {
         bool temp = fsm->cd(xFile);
         if(temp == false)
             alert(QStringLiteral("��û��Ȩ�޴򿪸��ļ���"));
         else
         {
             labelCurrentPath->setText(tr(fsm->getCurrentPath().c_str()));
             refreshFileLists();
         }
     }
 }
 void osDesign::open()
 {
     int row = treeFile->currentIndex().row();      //��ǰѡ�е���
     open(row);
 }
 void osDesign::open(QTreeWidgetItem* ti, int index)
 {
     open(index);
 }
 
 void osDesign::rm()
 {
    QMessageBox   mb(QStringLiteral("ɾ��ȷ��"), QStringLiteral("ȷ��ɾ������?"),
    QMessageBox::Question,
    QMessageBox::Yes   |   QMessageBox::Default,
    QMessageBox::No     |   QMessageBox::Escape,
    QMessageBox::NoButton);   
    if(mb.exec() == QMessageBox::No)
       return;

     int row = treeFile->currentIndex().row();      //��ǰѡ�е���
     vector<XMLElement*> vxe;
     fsm->ls(vxe);
     XMLElement* xFile = vxe.at(row);
     if(fsm->rm(xFile))
        refreshFileLists();
     else
         alert(QStringLiteral("��û��Ȩ��ɾ������ļ�"));
 }

 void osDesign::touch()
 {
    bool isOK;
    QString text = QInputDialog::getText(NULL, QStringLiteral("�����ļ���"),
       QStringLiteral("�����ļ���"),
       QLineEdit::Normal,
       QStringLiteral("new file"),
       &isOK);
    if(isOK) 
    {
        if(fsm->touch(text.toStdString()) == false)
            alert(QStringLiteral("��û��������Ȩ�޴����ļ�"));
        else
            refreshFileLists();
    }
 }

  void osDesign::mkdir()
 {
    bool isOK;
    QString text = QInputDialog::getText(NULL, QStringLiteral("�����ļ�����"),
       QStringLiteral("�����ļ�����"),
       QLineEdit::Normal,
       QStringLiteral("new directory"),
       &isOK);
    if(isOK) 
    {
        if(fsm->mkdir(text.toStdString()) == false)
            alert(QStringLiteral("��û��������Ȩ�޴����ļ���"));
        else
            refreshFileLists();
    }
 }

  void osDesign::rename()
  {
     int row = treeFile->currentIndex().row();      //��ǰѡ�е���
     vector<XMLElement*> vxe;
     fsm->ls(vxe);
     XMLElement* xFile = vxe.at(row);

    bool isOK;
    QString text = QInputDialog::getText(NULL, QStringLiteral("�����ļ���"),
       QStringLiteral("�����ļ���"),
       QLineEdit::Normal,
       xFile->Attribute("filename"),
       &isOK);
    if(isOK) 
    {
        if(fsm->rename(xFile, text.toStdString()) == false)
            alert(QStringLiteral("��û��Ȩ�����������ļ�"));
        else
            refreshFileLists();
    }
  }

  void osDesign::setPermission()
  {
     int row = treeFile->currentIndex().row();      //��ǰѡ�е���
     vector<XMLElement*> vxe;
     fsm->ls(vxe);
     XMLElement* xFile = vxe.at(row);

    bool isOK;
    string old_permission = xFile->Attribute("permission");
    old_permission.assign(old_permission.rbegin(), old_permission.rend());
    QString text = QInputDialog::getText(NULL, QStringLiteral("����Ȩ��"),
       QStringLiteral("3��rwx���ַ������磺111101101"),
       QLineEdit::Normal,
       old_permission.c_str(),
       &isOK);
    if(isOK) 
    {
        if(fsm->setPermission(xFile, text.toStdString()) == false)
            alert(QStringLiteral("��û��Ȩ�����������ļ�"));
        else
            refreshFileLists();
    }
  }

  void osDesign::switchUser()
  {
    bool isOK;
    QString text = QInputDialog::getText(NULL, QStringLiteral("�����û���"),
       QStringLiteral("�����û���"),
       QLineEdit::Normal,
       "root",
       &isOK);
    if(isOK) 
    {
        myon::User* user = new myon::User(text.toStdString());
        if(user->getName() != text.toStdString())
            alert(QStringLiteral("ϵͳû������û�"));
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
