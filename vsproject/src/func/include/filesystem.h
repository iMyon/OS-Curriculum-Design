//���������ļ�ϵͳʵ���������ļ��Ĺ���
#pragma once
#include<string>
#include "file.h"
#include "./user.h"
#include "../../tinyxml2/tinyxml2.h"
using std::string;
using namespace tinyxml2;

class Filesystem
{
private:
    string currentPath;                     //��ǰ·��
    myon::User* user;                       //��ǰ�û�
    XMLDocument* pDoc;                //xml�ĵ�����
    static const char* xmlFilename;   //xml�ļ���
    XMLElement* ptr_currentPath;    //��ǰ·��ָ��
    XMLElement* ptr_parentPath;    //����·��ָ��

public:
    Filesystem();
    void file2xmlElem(myon::File* file, XMLElement* xe);            //�ļ�����ֵXMLElement����
    void xmlElem2file( XMLElement* xe, myon::File* file);           //��֮
    myon::User* getUser(){ return user; }
    string getCurrentPath() const{ return currentPath; }
    void setUser(myon::User* user)            //�����û�
    {
        this->user = user;
    } 
    void save();                    //����xml�ļ�
    bool cd(XMLElement* directory);     //����Ŀ¼
    bool checkPermission_r(myon::File* file);
    bool checkPermission_w(myon::File* file);
    bool checkPermission_x(myon::File* file);
    bool rename(XMLElement* file, string filename);      //������
    bool rm(XMLElement* file);              //ɾ���ļ�
    string read(XMLElement* file);          //��ȡ�ļ�����
    bool write(XMLElement* file, string str);           //д���ļ�
};