#include<iostream>
#include<Windows.h>
#include"menus.h"
#include"全局变量存储区.h"
using namespace std;

vector<indexs>students;   //建立学生和管理者索引（相当于目录）
vector<indexsm>managers;

int studentcount;
int managercount;
student* currstud;
manager* currmana;

int main()
{
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