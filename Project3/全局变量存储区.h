#pragma once
#include<vector>
#include"类声明.h"

extern std::vector<indexs>students;   //建立学生和管理者索引（相当于目录）
extern std::vector<indexsm>managers;

extern int studentcount;
extern int managercount;

extern student* currstud;   //当前登陆学生
extern manager* currmana;   //当前登陆管理者

extern std::string newinfo; //新通知

extern bool isdebug;
extern bool willlogout;