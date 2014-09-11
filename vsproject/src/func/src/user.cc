#include "../include/user.h"
const string myon::User::saveFile = "user.txt";
myon::User::User(const int& id)
{
    if(_access(saveFile.c_str(), 0) == -1)      //文件不存在则创建默认文件
    {
        ofstream of(saveFile);
        //用户标识号 组标识号 用户名
        of<<"0 0 root"<<std::endl;
        of<<"100 1 myon"<<std::endl;
        of.close();
    }
    this->id = 0;
    this->group = 0;
    this->name = "root";
    ifstream ifs(saveFile);
    if(ifs.good())
    {
        while (!ifs.eof())
        {
            int cid;
            ifs>>cid;
            if(cid == id)
            {
                this->id = cid;
                ifs>>this->group;
                ifs>>this->name;
                ifs.close();
                break;
            }
            else
            {
                char buff[256];
                ifs.getline(buff, 256);
            }
        }
    }
    else
    {
        this->id = 0;
        this->group = 0;
        this->name = "root";
    }
}

myon::User::User(const string& username)
{
    if(_access(saveFile.c_str(), 0) == -1)      //文件不存在则创建默认文件
    {
        ofstream of(saveFile);
        //用户标识号 组标识号 用户名
        of<<"0 0 root"<<std::endl;
        of<<"100 1 myon"<<std::endl;
        of.close();
    }
    this->id = 0;
    this->group = 0;
    this->name = "root";
    ifstream ifs(saveFile);
    if(ifs.good())
    {
        while (!ifs.eof())
        {
            int cid;
            ifs>>cid;
            int cgroup;
            ifs>>cgroup;
            string cname;
            ifs>>cname;
            if(username == cname)
            {
                this->id = cid;
                this->group = cgroup;
                this->name = cname;
                ifs.close();
                break;
            }
            else
            {
                char buff[256];
                ifs.getline(buff, 256);
            }
        }
    }
    else
    {
        this->id = 0;
        this->group = 0;
        this->name = "root";
    }
}