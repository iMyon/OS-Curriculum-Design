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
       const  static string saveFile;    //�����û���Ϣ���ļ�
    public:
        User(const int& id);
        User(const string& username);
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

  
}

#endif