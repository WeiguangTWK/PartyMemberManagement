#include"功能-删.h"
#include"文件存取操作.h"
#include"全局变量存储区.h"
#include<Windows.h>
#include<iostream>
using namespace std;

string name;

bool tmpfunc(indexs & task)
	{
	return task.name == name;
	}
bool tmpfuncm(indexsm& task)
{
	return task.name == name;
}
void delstudrec()
{
	
	while (true)
	{
		system("cls");
		cout << "输入要删除的学生姓名：";

		bool isdeled = false;
		cin >> name;
		for (auto it : students)
		{
			if (it.name == name)
			{
				if (isdebug) cout << "删除了" << it.name << endl;
				free(it.pointer);
				indexs tmp;
				tmp.name = name;
				tmp.pointer = it.pointer;
				vector<indexs>::iterator itr;
				itr = find_if(students.begin(), students.end(),tmpfunc);
				students.erase(itr);
				studentcount--;
				isdeled = true;
				break;
			}
		}
		if (isdeled)
		{
			save();
			cout << "删除成功！" << endl;
			cout << "是否继续删除其他记录（Y/N)？";
			char userinp;
			cin >> userinp;
			if (userinp == 'Y' || userinp == 'y') continue;
			break;
		}
		else
		{
			cout << "未找到该学生，请重试！" << endl;
			Sleep(1200);
			continue;
		}

	}
}


void delmanarec()
{
	while (true)
	{
		system("cls");
		cout << "输入要删除的党支部/团支部成员姓名：";
		bool isdeled = false;
		cin >> name;
		for (auto it : managers)
		{
			if (it.name == name)
			{
				if (name == currmana->name)
				{
					cout << "警告：将删除目前登陆的账户，删除后您将被登出" << endl;
					cout << "您确认吗（Y/N）?";
					char userinp;
					cin >> userinp;
					if (userinp == 'Y' || userinp == 'y') willlogout = true;
					else continue;
				}
				if (isdebug) cout << "删除了" << it.name << endl;
				free(it.pointer);
				indexsm tmp;
				tmp.name = name;
				tmp.pointer = it.pointer;
				vector<indexsm>::iterator itr;
				itr = find_if(managers.begin(), managers.end(), tmpfuncm);
				managers.erase(itr);
				managercount--;
				isdeled = true;
				break;
			}
		}
		if (isdeled)
		{
			save();
			cout << "删除成功！" << endl;
			
			if (willlogout)
			{
				Sleep(1000);
				system("cls");
				return;
			}

			cout << "是否继续删除其他记录（Y/N)？";
			char userinp;
			cin >> userinp;
			if (userinp == 'Y' || userinp == 'y') continue;
			break;
		}
		else
		{
			cout << "未找到该成员，请重试！" << endl;
			Sleep(1200);
			continue;
		}

	}
}