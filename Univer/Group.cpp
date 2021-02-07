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
