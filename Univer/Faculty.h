#pragma once
class Faculty
{
	int id;
	char name[100];
public:
	Faculty();
	Faculty(int id, const char name[]);
	~Faculty();

	int getId();
};

