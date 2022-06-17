#include<iostream>
#include<Windows.h>
#include"菜单.h"
#include"文件存取操作.h"
#include"全局变量存储区.h"
using namespace std;

vector<indexs>students;   //建立学生和管理者索引（相当于目录）
vector<indexsm>managers;

std::string *newinfo =new string; //新通知
int studentcount=0;
int managercount=0;
student* currstud;
manager* currmana;

bool isdebug = true;
bool willlogout = false;

void firstbootsequence()
{
	string username;
	int type;
	cout << "无管理员账户-请创建至少一个党支部或团支部账户" << endl;
	cout << "用户名：";
	cin >> username;
	
	while (true)
	{
		cout << "键入用户类型（0=党支部，1=团支部）：";
		cin >> type;
		if (!(type == PERMISSION_DZB || type == PERMISSION_TZB)) cout << "输入有误，请重试！";
		else break;
		system("cls");
	}
	manager* a = new manager(username, type);
	managercount = 1;
	save();
	system("cls");
}

int main()
{
	load();
	if (managercount == 0)
		firstbootsequence();
	while (true)
	{
		mainmenu();
		int userinp = 0;
		scanf_s("%d", &userinp);
		switch (userinp)
		{
		case 1:
			DZBmenu();
			continue;
		case 2:
			TZBmenu();
			continue;
		case 3:
			StudentMenu();
			continue;
		case 4:
			return 0;
		default:
			cout << "输入有误，请重试！";
			continue;
		}
	}
}