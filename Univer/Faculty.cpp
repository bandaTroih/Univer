#include "Faculty.h"
#include <string.h>

Faculty::Faculty()
{
}

Faculty::Faculty(int id, const char name[])
{
    this->id = id;

    strcpy_s(this->name, name);
}

Faculty::~Faculty()
{
}

int Faculty::getId()
{
    return id;
}
