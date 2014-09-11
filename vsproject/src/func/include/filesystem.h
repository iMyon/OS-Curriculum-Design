//���������ļ�ϵͳʵ���������ļ��Ĺ���
#pragma once
#include<string>
#include "file.h"
#include "./user.h"
#include <vector>
using std::vector;
#include "../../tinyxml2/tinyxml2.h"
using std::string;
using namespace tinyxml2;

class Filesystem
{
private:
    string currentPath;                     //��ǰ·��
    myon::User* user;                       //��ǰ�û�
    XMLDocument pDoc;                //xml�ĵ�����
    static const char* xmlFilename;   //xml�ļ���
    XMLElement* ptr_currentPath;    //��ǰ·��ָ��
    XMLElement* ptr_parentPath;    //����·��ָ��

public:
    Filesystem();
    void file2xmlElem(myon::File* file, XMLElement* xe);            //�ļ�����ֵXMLElement����
    myon::User* getUser(){ return user; }
    string getCurrentPath() const{ return currentPath; }
    XMLElement* getPtr_currentPath(){ return ptr_currentPath; }
    XMLElement* getPtr_parentPath(){ return ptr_parentPath; }
    void setUser(myon::User* user)            //�����û�
    {
        this->user = user;
    } 
    void save();                    //����xml�ļ�
    bool cd(XMLElement* directory);     //����Ŀ¼
    bool checkPermission_r(myon::File* file);
    bool checkPermission_w(myon::File* file);
    bool checkPermission_x(myon::File* file);
    bool setPermission(XMLElement* xFile, string str);  //����Ȩ��;
    bool rename(XMLElement* file, string filename);      //������
    bool touch(string filename);            //�½��ļ�
    bool mkdir(string filename);            //�½��ļ���
    bool rm(XMLElement* file);              //ɾ���ļ�
    bool read(XMLElement* file, string&);          //��ȡ�ļ�����
    bool write(XMLElement* file, string str);           //д���ļ�
    bool ls(vector<XMLElement*>&);      //�г��ļ��б�
};