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
    pDoc.LoadFile(xmlFilename); 
    user = new myon::User(0);
    currentPath = "/";
    ptr_currentPath = pDoc.RootElement();
    ptr_parentPath = pDoc.RootElement();
}

void Filesystem::save()
{
    pDoc.SaveFile(xmlFilename);
}

bool Filesystem::cd(XMLElement* directory)
{
    myon::File* file = new myon::File(directory);
    if(file->getType() != 2)            //不是文件夹的话返回false
        return false;
    if(checkPermission_r(file) == false)
        return false;
    if(directory == pDoc.RootElement())
    {
        currentPath = "/";
    }
    else
    {
        ptr_parentPath = directory->Parent()->ToElement();
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

bool Filesystem::touch(string filename)
{
    myon::File* file = new myon::File(this->ptr_currentPath);
    if(checkPermission_w(file) == false)
        return false;
    XMLElement *fileElement = pDoc.NewElement("file");
    fileElement->SetAttribute("owner", this->user->getId());
    fileElement->SetAttribute("type", 1);
    fileElement->SetAttribute("group", 0); 
    fileElement->SetAttribute("filename", filename.c_str());
    fileElement->SetAttribute("permission", "001001011");       //默认644权限
    this->ptr_currentPath->LinkEndChild(fileElement);
    this->save();
    return true;
}
bool Filesystem::mkdir(string filename)
{
    myon::File* file = new myon::File(this->ptr_currentPath);
    if(checkPermission_w(file) == false)
        return false;
    XMLElement *fileElement = pDoc.NewElement("directory");
    fileElement->SetAttribute("owner", this->user->getId());
    fileElement->SetAttribute("type", 2);
    fileElement->SetAttribute("group", 0); 
    fileElement->SetAttribute("filename", filename.c_str());
    fileElement->SetAttribute("permission", "101101111");       //默认755权限
    this->ptr_currentPath->LinkEndChild(fileElement);
    this->save();
    return true;
}

bool Filesystem::rename(XMLElement* xe, string filename)
{
    myon::File* file = new myon::File(xe);
    if(checkPermission_w(file) == false)
        return false;
    xe->SetAttribute("filename", filename.c_str());
    this->save();
}

bool Filesystem::rm(XMLElement* xe)
{
    if(xe == pDoc.RootElement())
        return false;
    myon::File* file = new myon::File(xe);
    if(this->getUser()->getId() == file->getOwner())
    {
        xe->Parent()->DeleteChild(xe);
        this->save();
        return true;
    }
    return false;
}

bool Filesystem::read(XMLElement* xe, string& str )
{
    myon::File* file = new myon::File(xe);
    if(checkPermission_r(file) == false)
    {
        return false;
    }
    if(xe->GetText())
        str = string(xe->GetText());
    else
        str = "";
    return true;
}
bool Filesystem::write(XMLElement* xe, string content)
{
    myon::File* file = new myon::File(xe);
    if(checkPermission_w(file) == false)
    {
        return false;
    }
    xe->SetText(content.c_str());
    this->save();
    return true;
}

bool Filesystem::checkPermission_r(myon::File* file)
{
    if(file->getOwner() == this->getUser()->getId())
    {
        if(file->getPermission()[0] == 1)
            return true;
        return false;
    }
    else
    {
        if(file->getPermission()[6] == 1)
            return true;
        return false;
    }
}
bool Filesystem::checkPermission_w(myon::File* file)
{
    if(file->getOwner() == this->getUser()->getId())
    {
        if(file->getPermission()[1] == 1)
            return true;
        return false;
    }
    else
    {
        if(file->getPermission()[7] == 1)
            return true;
        return false;
    }
}
bool Filesystem::checkPermission_x(myon::File* file)
{
    if(file->getOwner() == this->getUser()->getId())
    {
        if(file->getPermission()[2] == 1)
            return true;
        return false;
    }
    else
    {
        if(file->getPermission()[8] == 1)
            return true;
        return false;
    }
}

bool Filesystem::setPermission(XMLElement* xFile, string str)
{
    myon::File* file = new myon::File(xFile);
    if(file->getOwner() != this->user->getId())
        return false;
    str.assign(str.rbegin(), str.rend());
    if(str.length() !=9 ) return false;
    for(int i=0; i<9; i++) 
        if(str.at(i) == '0' || str.at(i) == '1') continue;
        else return false;
    xFile->SetAttribute("permission", str.c_str());
    save();
}

void Filesystem::file2xmlElem(myon::File* file, XMLElement* xe)          
{
    xe->SetAttribute("owner", file->getOwner());
    xe->SetAttribute("filename", file->getFilename().c_str());
    xe->SetAttribute("type", file->getType());
    xe->SetAttribute("content", file->getContent().c_str());
    xe->SetAttribute("permission",file->getPermission().to_string().c_str());
}

bool Filesystem::ls(vector<XMLElement*>& vxe)
{
    myon::File* file = new myon::File(this->ptr_currentPath);
    if(checkPermission_r(file) == false)
    {
        return false;
    };
    vxe.push_back(ptr_parentPath);
    XMLElement* elem = ptr_currentPath->FirstChildElement();
    while(elem)
    {
        XMLElement* temp = elem;
        vxe.push_back(temp);
        elem = elem->NextSiblingElement();
    }
    return true;
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
    rootElement->SetAttribute("owner", 0);
    rootElement->SetAttribute("group", 0);
    rootElement->SetAttribute("type", 2);
    rootElement->SetAttribute("filename", "/");
    rootElement->SetAttribute("permission", "111111111");
    pDoc->LinkEndChild(rootElement);
    //节点directory
    XMLElement *directoryElement = pDoc->NewElement("directory");
    directoryElement->SetAttribute("owner", 0);
    directoryElement->SetAttribute("group", 0);
    directoryElement->SetAttribute("type", 2);
    directoryElement->SetAttribute("filename", "demo_directory");
    directoryElement->SetAttribute("permission", "111111111");
    rootElement->LinkEndChild(directoryElement);
    //节点file
    XMLElement *fileElement = pDoc->NewElement("file");
    fileElement->SetAttribute("owner", 0);
    fileElement->SetAttribute("type", 1);
    fileElement->SetAttribute("group", 0); 
    fileElement->SetAttribute("filename", "demo_file");
    fileElement->SetAttribute("permission", "111111111");
    fileElement->LinkEndChild(pDoc->NewText("keyText"));//给节点设置值
    directoryElement->LinkEndChild(fileElement);
    //节点file
    XMLElement *file2Element = pDoc->NewElement("file");
    file2Element->SetAttribute("owner", 0);
    file2Element->SetAttribute("group", 0);
    file2Element->SetAttribute("type", 1);
    file2Element->SetAttribute("filename", "demo_file");
    file2Element->SetAttribute("permission", "111111111");
    file2Element->LinkEndChild(pDoc->NewText("demo"));//给节点设置值
    rootElement->LinkEndChild(file2Element);

    pDoc->SaveFile(filename);//保存文件 参数：路径
}