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

const char* Faculty::getName()
{
    return name;
}

TCHAR* Faculty::LgetName()
{
    size_t size1 = strlen(name) + 1;
    TCHAR* buff = new TCHAR[size1];
    size_t size2;
    mbstowcs_s(&size2, buff, size1, name, _TRUNCATE);
    return buff;
}

int Faculty::getId()
{
    return id;
}
