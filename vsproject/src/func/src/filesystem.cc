#pragma once
#include "../include/filesystem.h"

void genFile(const char* filename);     //生成默认xml文件
const char* Filesystem::xmlFilename = "fileTree.xml";
Filesystem::Filesystem()
{
    if(_access(xmlFilename,0) == -1)            //文件不存在则创建默认文件
    {
        genFile(xmlFilename);
    }
    pDoc->LoadFile(xmlFilename); 
    user = new myon::User(0);
    currentPath = "/";
    ptr_currentPath = pDoc->RootElement();
    ptr_parentPath = pDoc->RootElement();
}

void Filesystem::save()
{
    pDoc->SaveFile(xmlFilename);
}

bool Filesystem::cd(XMLElement* directory)
{
    myon::File* file;
    this->xmlElem2file(directory, file);
    if(checkPermission_r(file) == false)
        return false;
    if(directory == pDoc->RootElement())
    {
        currentPath = "/";
        ptr_currentPath = directory;
    }
    else
    {
        ptr_parentPath = ptr_currentPath;
        if(directory == ptr_parentPath)
        {
            string filename = directory->Attribute("filename");
            int pos = filename.rfind(filename);
            currentPath = currentPath.substr(0,pos);
        }
        else
        {
            currentPath = currentPath + directory->Attribute("filename") + "/";
        }
    }
    ptr_currentPath = directory;
    return true;
}

bool Filesystem::rename(XMLElement* xe, string filename)
{
    myon::File* file;
    xmlElem2file(xe, file);
    if(checkPermission_w(file) == false)
        return false;
    xe->SetAttribute("filename", filename.c_str());
    this->save();
}

bool Filesystem::rm(XMLElement* xe)
{
    myon::File* file;
    xmlElem2file(xe, file);
    if(this->getUser()->getId() == file->getOwner())
    {
        pDoc->DeleteChild(xe);
        this->save();
        return true;
    }
    return false;
}

string Filesystem::read(XMLElement* xe)
{
    myon::File* file;
    xmlElem2file(xe, file);
    if(checkPermission_r(file) == false)
    {
        return NULL;
    }
    return xe->GetText();
}
bool Filesystem::write(XMLElement* xe, string content)
{
    myon::File* file;
    xmlElem2file(xe, file);
    if(checkPermission_w(file) == false)
    {
        return false;
    }
    xe->LinkEndChild(pDoc->NewText(content.c_str()));
    this->save();
    return true;
}

bool Filesystem::checkPermission_r(myon::File* file)
{
    if(file->getOwner() == this->getUser()->getId())
    {
        if(file->getPermission()[0][0] == 1)
            return true;
        return false;
    }
    else
    {
        if(file->getPermission()[2][0] == 1)
            return true;
        return false;
    }
}
bool Filesystem::checkPermission_w(myon::File* file)
{
    if(file->getOwner() == this->getUser()->getId())
    {
        if(file->getPermission()[0][1] == 1)
            return true;
        return false;
    }
    else
    {
        if(file->getPermission()[2][1] == 1)
            return true;
        return false;
    }
}
bool Filesystem::checkPermission_x(myon::File* file)
{
    if(file->getOwner() == this->getUser()->getId())
    {
        if(file->getPermission()[0][2] == 1)
            return true;
        return false;
    }
    else
    {
        if(file->getPermission()[2][2] == 1)
            return true;
        return false;
    }
}

void Filesystem::file2xmlElem(myon::File* file, XMLElement* xe)          
{
    xe->SetAttribute("owner", file->getOwner());
    xe->SetAttribute("filename", file->getFilename().c_str());
    xe->SetAttribute("type", file->getType());
    xe->SetAttribute("content", file->getContent().c_str());
    string  perstr = "";
    bitset<3>* b = file->getPermission();
    for(int i=0; i<3; i++)
    {
        perstr += b[i].to_string();
    }
    xe->SetAttribute("permission", perstr.c_str());
}
void Filesystem::xmlElem2file( XMLElement* xe, myon::File* file)
{
    file->setOwner(xe->IntAttribute("owner"));
    file->setFilename(xe->Attribute("filename"));
    file->setType(xe->IntAttribute("type"));
    string perstr = xe->Attribute("permission");
    bitset<3> b[3];
    b[0] = bitset<3>(perstr.substr(0, 3));
    b[1] = bitset<3>(perstr.substr(3, 3));
    b[2] = bitset<3>(perstr.substr(6, 3));
    file->setPermission(b);
}

void genFile(const char* filename)
{
    //xml声明
    XMLDocument *pDoc = new XMLDocument();
    if (NULL==pDoc) {
        return ;
    }
    XMLDeclaration *pDel = pDoc->NewDeclaration("xml version=\"1.0\" encoding=\"UTF-8\"");
    if (NULL==pDel) {
        return ;
    }
    pDoc->LinkEndChild(pDel);
    //节点root
    XMLElement *rootElement = pDoc->NewElement("root");
    pDoc->LinkEndChild(rootElement);
    //节点directory
    XMLElement *directoryElement = pDoc->NewElement("directory");
    directoryElement->SetAttribute("owner", 0);
    directoryElement->SetAttribute("group", 0);
    directoryElement->SetAttribute("type", 2);
    directoryElement->SetAttribute("filename", "demo_directory");
    directoryElement->SetAttribute("permission", "777");
    rootElement->LinkEndChild(directoryElement);
    //节点file
    XMLElement *fileElement = pDoc->NewElement("file");
    directoryElement->SetAttribute("owner", 0);
    directoryElement->SetAttribute("type", 1);
    directoryElement->SetAttribute("group", 0); 
    directoryElement->SetAttribute("filename", "demo_file");
    directoryElement->SetAttribute("permission", "777");
    fileElement->LinkEndChild(pDoc->NewText("keyText"));//给节点设置值
    directoryElement->LinkEndChild(fileElement);
    //节点file
    XMLElement *file2Element = pDoc->NewElement("file");
    directoryElement->SetAttribute("owner", 0);
    directoryElement->SetAttribute("group", 0);
    directoryElement->SetAttribute("type", 1);
    directoryElement->SetAttribute("filename", "demo_file");
    directoryElement->SetAttribute("permission", "777");
    file2Element->LinkEndChild(pDoc->NewText("demo"));//给节点设置值
    rootElement->LinkEndChild(file2Element);

    pDoc->SaveFile(filename);//保存文件 参数：路径
}