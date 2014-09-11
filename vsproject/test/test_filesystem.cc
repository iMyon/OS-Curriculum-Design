#include "../src/func/include/filesystem.h"
#include "../src/func/include/user.h"
#include "../src/func/src/user.cc"
#include<iostream>
#include<string>
#pragma comment(lib, "tinyxml2.lib")

using namespace std;
int main()
{
    Filesystem* fs = new Filesystem();
    fs->cd(fs->getPtr_currentPath()->FirstChildElement());
    cout<<fs->getCurrentPath()<<endl;
    XMLElement* file = fs->getPtr_currentPath()->FirstChildElement();
    //cout<<fs->getPtr_currentPath()->Attribute("filename")<<endl;

    //ls
   // vector<XMLElement*> vxe;
   // fs->ls(vxe);
    //cout<<vxe.at(0)->Attribute("filename")<<endl;

    //read test
    //cout<<fs->read(fs->getPtr_currentPath()->FirstChildElement());

    //write
    //fs->write(fs->getPtr_currentPath()->FirstChildElement(), "随意");

    //rm
    //fs->rm(fs->getPtr_currentPath()->FirstChildElement());

    //rename
    fs->rename(file, "测试");

    //touch，mkdir
    //fs->touch("测试文件");
    //fs->mkdir("测试文件夹");


    std::cin.get();
    return 0;
}