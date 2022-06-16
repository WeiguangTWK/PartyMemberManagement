#include<iostream>
#include<Windows.h>
#include"menus.h"
#include"FileRWOpts.h"
#include"全局变量存储区.h"
using namespace std;

vector<indexs>students;   //建立学生和管理者索引（相当于目录）
vector<indexsm>managers;

int studentcount;
int managercount;
student* currstud;
manager* currmana;

void firstbootsequence()
{
	string username;
	int type;
	cout << "无管理员账户-请创建至少一个党支部或团支书账户" << endl;
	cout << "用户名：" << endl;
	cin >> username;
	
	while (true)
	{
		cout << "键入用户类型（0=党支部，1=团支书）：";
		cin >> type;
		if (!(type == 0 || type == 1)) cout << "输入有误，请重试！";
		else break;
		system("cls");
	}
}

int main()
{
	load();
	if (managercount == 0)
		;
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