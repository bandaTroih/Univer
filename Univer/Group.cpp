#include "Group.h"
#include <string.h>

Group::Group()
{
}

Group::Group(int id, int faculty_id, const char name[])
{
    this->id = id;
    this->faculty_id = faculty_id;

    strcpy_s(this->name, name);
}

Group::~Group()
{
}

int Group::getId()
{
    return id;
}

int Group::getFId()
{
    return faculty_id;
}

const char* Group::getName()
{
    return name;
}

TCHAR* Group::LgetName()
{
    size_t size1 = strlen(name) + 1;
    TCHAR* buff = new TCHAR[size1];
    size_t size2;
    mbstowcs_s(&size2, buff, size1, name, _TRUNCATE);
    return buff;
}
