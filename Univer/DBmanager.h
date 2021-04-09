#pragma once
#include <iostream>
#include<sqlite3.h>
#include <vector>
#include "framework.h"
class DBmanager
{
private:
	DBmanager();
	DBmanager(const DBmanager &obj) = delete;
	DBmanager(DBmanager&& obj) = delete;
	~DBmanager();
	static DBmanager* instance;
public:
	static DBmanager* Get();

private:
	std::string db_file= "univer.db";
	sqlite3* db;

public:
	std::vector<Faculty> get_faculties();
	std::vector<Group> get_groups(int fid);
	std::vector<std::string> get_students(int gid);
	std::vector<std::string> get_student(int sid);

};

