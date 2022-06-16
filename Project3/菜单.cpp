//这里用来写菜单项
#pragma once
#include"菜单.h"
#include"验证.h"
#include"全局变量存储区.h"
#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;

void mainmenu()
{
	cout << "选择你的身份：" << endl 
		 << "1.党支部人员" << endl 
		 << "2.团支部人员" << endl 
		 << "3.学生" << endl 
		 << "4.退出系统" << endl 
		 << "键入选项：";
}

void DZBmenu()
{
	while (true)
	{
		system("cls");
		cout << "请验证党支部身份！" << endl;;
		cout << "输入用户名，或者键入“exit”以退出：";
		string userinp;
		cin >> userinp;
		if (userinp == "exit")
		{
			system("cls");
			return;
		}
		if (authmananame(userinp))
		{
			if (!(currmana->privillagetype==PERMISSION_DZB))
			{
				cout << "您登陆的身份不是党支部成员！" << endl;
				continue;
			}
			cout << "登陆成功！";
			system("cls");   //清屏
			break;
		}
		else
		{
			cout << "登陆失败，请重试！";
			continue;
		}
	}
	while (true)
	{
		system("cls");
		cout << "欢迎！党支部成员，请选择您的操作：" << endl;
		cout << "1.新增人员"<<endl;
		cout << "2.删除人员" << endl;
		cout << "3.更改人员信息" << endl;
		cout << "4.查询人员信息" << endl;
		cout << "5.获取推优情况" << endl;
		cout << "6.判定人员转正" << endl;
		cout << "7.登出账号" << endl;
		cout << "键入需要进行的操作：";
		int userinp;
		cin >> userinp;
		switch (userinp)
		{
		case 1:
			currmana->addrecord();
			continue;
		case 2:
			continue;
		case 3:
			continue;
		case 4:
			continue;
		case 5:
			continue;
		case 6:
			continue;
		case 7:
			system("cls");
			return;
		default:
			cout << "选项有误，请重试！";
			continue;
		}
	}
}


void TZBmenu()
{
	while (true)
	{
		system("cls");
		cout << "请验证团支部身份！" << endl;;
		cout << "输入用户名，或者键入“exit”以退出：";
		string userinp;
		cin >> userinp;
		if (userinp == "exit")
		{
			system("cls");
			return;
		}
		if (authmananame(userinp))
		{
			if (!(currmana->privillagetype == PERMISSION_TZB))
			{
				cout << "您登陆的身份不是团支部成员！" << endl;
				continue;
			}
			cout << "登陆成功！";
			system("cls");   //清屏
			break;
		}
		else
		{
			cout << "登陆失败，请重试！";
			continue;
		}
	}
	while (true)
	{
		system("cls");
		cout << "欢迎！团支部成员，请选择您的操作：" << endl;
		cout << "1.新增人员" << endl;
		cout << "2.删除人员" << endl;
		cout << "3.更改人员信息" << endl;
		cout << "4.查询人员信息" << endl;
		cout << "5.录入推优情况" << endl;
		cout << "6.发布通知" << endl;
		cout << "7.登出账号" << endl;
		cout << "键入需要进行的操作：";
		int userinp;
		cin >> userinp;
		switch (userinp)
		{
		case 1:
			continue;
		case 2:
			continue;
		case 3:
			continue;
		case 4:
			continue;
		case 5:
			continue;
		case 6:
			continue;
		case 7:
			system("cls");
			return;
		default:
			cout << "选项有误，请重试！";
			continue;
		}
	}
}

void StudentMenu()
{
	while (true)
	{
		system("cls");
		cout << "请验证学生身份！" << endl;;
		cout << "输入用户名，或者键入“exit”以退出：";
		string userinp;
		cin >> userinp;
		if (userinp == "exit")
		{
			system("cls");
			return;
		}
		if (authstudname(userinp))
		{
			cout << "登陆成功！";
			system("cls");   //清屏
			break;
		}
		else
		{
			cout << "登陆失败，请重试！";
			continue;
		}
	}
	while (true)
	{
		system("cls");
		cout << "欢迎同学登陆管理系统，请选择操作:" << endl;;
		cout << "1.查询本人信息" << endl;
		cout << "2.递交入党申请" << endl;
		cout << "3.登出账号" << endl;
		cout << "键入需要进行的操作：";
		int userinp;
		cin >> userinp;
		switch (userinp)
		{
		case 1:
			continue;
		case 2:
			currstud->applyaction();
			continue;
		case 3:
			system("cls");
			return;
		default:
			cout << "选项有误，请重试！";
			continue;
		}
	}
}