#pragma once
class Group
{
	int id;
	int faculty_id;
	char name[100];
public:
	Group();
	Group(int id, int faculty_id, const char name[]);
	~Group();

	int getId();
};

