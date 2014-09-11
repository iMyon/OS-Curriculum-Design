//用于生成文件系统实例，管理文件的功能
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
    string currentPath;                     //当前路径
    myon::User* user;                       //当前用户
    XMLDocument pDoc;                //xml文档对象
    static const char* xmlFilename;   //xml文件名
    XMLElement* ptr_currentPath;    //当前路径指针
    XMLElement* ptr_parentPath;    //父级路径指针

public:
    Filesystem();
    void file2xmlElem(myon::File* file, XMLElement* xe);            //文件对象赋值XMLElement对象
    myon::User* getUser(){ return user; }
    string getCurrentPath() const{ return currentPath; }
    XMLElement* getPtr_currentPath(){ return ptr_currentPath; }
    XMLElement* getPtr_parentPath(){ return ptr_parentPath; }
    void setUser(myon::User* user)            //更改用户
    {
        this->user = user;
    } 
    void save();                    //保存xml文件
    bool cd(XMLElement* directory);     //进入目录
    bool checkPermission_r(myon::File* file);
    bool checkPermission_w(myon::File* file);
    bool checkPermission_x(myon::File* file);
    bool setPermission(XMLElement* xFile, string str);  //设置权限;
    bool rename(XMLElement* file, string filename);      //重命名
    bool touch(string filename);            //新建文件
    bool mkdir(string filename);            //新建文件夹
    bool rm(XMLElement* file);              //删除文件
    bool read(XMLElement* file, string&);          //读取文件内容
    bool write(XMLElement* file, string str);           //写入文件
    bool ls(vector<XMLElement*>&);      //列出文件列表
};