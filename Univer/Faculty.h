#pragma once
#include"framework.h"
class Faculty
{
	int id;
	char name[100];
public:
	Faculty();
	Faculty(int id, const char name[]);
	~Faculty();
	const char* getName();
	TCHAR* LgetName();
	int getId();
};

