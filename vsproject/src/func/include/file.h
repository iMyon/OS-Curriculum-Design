/*
目的与要求：本设计的目的是通过设计和调试一个简单的文件系统，主要是模拟文件操作命令的执行，来模拟文件管理，使学生对主要文件操作命令的实质和执行过程有比较深入的了解，掌握它们的基本实施方法。
具体要求如下： 
1. 设计一个支持n个用户的文件系统，每个用户可拥有多个文件： 
2. 采用二级或二级以上的多级文件目录管理； 
3. 对文件应设置存取控制保护方式，如“只能执行”、“允许读”、“允许写等”； 
4. 系统的外部特征应接近于真实系统，可设置下述文件操作命令： 1. 通过键盘使用该文件系统，系统应显示操作命令的执行结果。
*/

#pragma once
#include<string>
#include<bitset>

using std::string;
using std::bitset;

namespace myon
{
    class File;
}
class myon::File
{
private:
    int owner;              //文件拥有者，userId
    string path;            //文件所在路径
    string filename;        //文件名
    bitset<3> permission[3];       //文件权限，3个rwx的数组，每组代表owner, group, other
    int type;                   //1：文件， 2:文件夹
    string content;    //文件内容

public:
    File(int ow, string pt, bitset<3>* pm, int tp, string content)
        : owner(ow), path(pt), type(tp), content(content)
    {
        //初始化权限数组
        for(int i=0; i<3; i++)
        {
            permission[i] = pm[i];
        }
    }
    //get和set函数内联
    int getOwner()
    {
        return owner;
    }
    string getPath()
    {
        return path;
    }
    string getFilename(){ return filename; }
    bitset<3>* getPermission()
    {
        return permission;
    }
    int getType()
    {
        return type;
    }
    string getContent()
    {
        return content;
    }
    void setOwner(int owner) 
    {
        this->owner = owner;
    }
    void setType(int type)
    {
        this->type = type;
    }
    void setPath(string path)
    {
        this->path = path;
    }
    void setFilename(string filename)
    {
        this->filename = filename;
    }
    void setPermission(bitset<3>* permission)
    {
        //初始化权限数组
        for(int i=0; i<3; i++)
        {
            this->permission[i] = permission[i];
        }
    }
    void setContent(string content)
    {
        this->content = content;
    }
};
