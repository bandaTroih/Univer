#include "DBmanager.h"


DBmanager* DBmanager::instance = nullptr;

DBmanager::DBmanager()
{
}

DBmanager* DBmanager::Get()
{
    if (instance == nullptr)
        instance = new DBmanager();
    return instance;
}

DBmanager::~DBmanager()
{
}



std::vector<Faculty> DBmanager::get_faculties()
{
    std::vector<Faculty> res;
    sqlite3_open(db_file.c_str(), &db);
    sqlite3_exec(db, "select * from faculties", [](void* ctx, int argc, char** argv, char** colName) -> int
        {
            int id = 1;
            for (int i = 0; i < argc; i++)
                if (i % 2 == 1)
                    static_cast<std::vector<Faculty>*>(ctx)->push_back(Faculty(id, argv[i]));
                else
                    id = atoi(argv[i]);
            
            return 0;
        }, &res, NULL);

    sqlite3_close(db);
    return res;
}

std::vector<Group> DBmanager::get_groups(int fid)
{
    std::vector<Group> res;
    char sql[100];
    sprintf_s(sql, 100, "select * from groups where faculty_id=%i", fid);
    
    sqlite3_open(db_file.c_str(), &db);
    sqlite3_exec(db, sql, [](void* ctx, int argc, char** argv, char** colName) -> int
        {
            int id = 1;
            int f_id = 1;
            for (int i = 0; i < argc; i++)
                if (i % 3 == 0)
                    id = atoi(argv[i]);
                else if (i % 3 == 1)
                    f_id = atoi(argv[i]);
                else
                    static_cast<std::vector<Group>*>(ctx)->push_back(Group(id, f_id, argv[i]));

            return 0;
        }, &res, NULL);

    sqlite3_close(db);
    return res;
}

std::vector<std::string> DBmanager::get_students(int gid)
{
    return std::vector<std::string>();
}

std::vector<std::string> DBmanager::get_student(int sid)
{
    return std::vector<std::string>();
}
