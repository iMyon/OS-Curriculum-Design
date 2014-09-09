#include "../src/func/include/filesystem.h"
#include<iostream>
#include<string>
#pragma comment(lib, "tinyxml2.lib")

int main()
{
    Filesystem* fs = new Filesystem();
    //User* u = new User(101);
    //std::cout<<u->getName()<<std::endl;
    std::cout<<std::string("aaaab").substr(0, 2);
    std::cin.get();
    return 0;
}