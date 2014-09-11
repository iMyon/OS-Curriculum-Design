/*
Ŀ����Ҫ�󣺱���Ƶ�Ŀ����ͨ����ƺ͵���һ���򵥵��ļ�ϵͳ����Ҫ��ģ���ļ����������ִ�У���ģ���ļ�����ʹѧ������Ҫ�ļ����������ʵ�ʺ�ִ�й����бȽ�������˽⣬�������ǵĻ���ʵʩ������
����Ҫ�����£� 
1. ���һ��֧��n���û����ļ�ϵͳ��ÿ���û���ӵ�ж���ļ��� 
2. ���ö�����������ϵĶ༶�ļ�Ŀ¼���� 
3. ���ļ�Ӧ���ô�ȡ���Ʊ�����ʽ���硰ֻ��ִ�С��������������������д�ȡ��� 
4. ϵͳ���ⲿ����Ӧ�ӽ�����ʵϵͳ�������������ļ�������� 1. ͨ������ʹ�ø��ļ�ϵͳ��ϵͳӦ��ʾ���������ִ�н����
*/

#pragma once
#include<string>
#include<bitset>
#include "../../tinyxml2/tinyxml2.h"
using namespace tinyxml2;

using std::string;
using std::bitset;

namespace myon
{
    class File;
}
class myon::File
{
private:
    int owner;              //�ļ�ӵ���ߣ�userId
    string path;            //�ļ�����·��
    string filename;        //�ļ���
    bitset<9> permission;       //�ļ�Ȩ�ޣ�rwx*3, ÿ�����owner, group, other
    int type;                   //1���ļ��� 2:�ļ���
    string content;    //�ļ�����

public:
    File(int ow, string pt, bitset<9>* pm, int tp = 1, string content = "");
    File(XMLElement* xe);
    //get��set��������
    int getOwner()
    {
        return owner;
    }
    string getPath()
    {
        return path;
    }
    string getFilename(){ return filename; }
    bitset<9> getPermission()
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
    void setPermission(bitset<9> permission)
    {
        for(int i=0; i<9; i++)
            this->permission[i] = permission[i];
    }
    void setContent(string content)
    {
        this->content = content;
    }
};
