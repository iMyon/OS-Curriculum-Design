#include "../include/file.h"
myon::File::File(int ow, string pt, bitset<9>* pm, int tp, string content)
    : owner(ow), path(pt), type(tp), content(content)
{
    for(int i=0; i<9; i++)
        this->permission[i] = permission[i];
}
myon::File::File(XMLElement* xe)
{
    this->owner = xe->IntAttribute("owner");
    this->filename = xe->Attribute("filename");
    this->type = xe->IntAttribute("type");
    string perstr = xe->Attribute("permission");
    bitset<9> b(perstr);
    for(int i=0; i<9; i++)
        this->permission[i] = b[i];
}
