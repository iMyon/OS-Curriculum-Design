#ifndef USER_H
#define USER_H
#include<string>
#include<io.h>
#include<fstream>
using std::string;
using std::ofstream;
using std::ifstream;

namespace myon
{
    class User
    {
    private:
        int id;
        int group;
        string name;
       const  static string saveFile;    //保存用户信息的文件
    public:
        User(const int& id);
        int getId(){ return id; }
        int getGroup(){ return group; }
        string getName(){ return name; }

        int setGroup(int id)
        {
            this->group = group;
        }
        int setName(string name)
        {
            this->name = name;
        }
    };

    const string User::saveFile = "user.txt";

    User::User(const int& id)
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
}

#endif