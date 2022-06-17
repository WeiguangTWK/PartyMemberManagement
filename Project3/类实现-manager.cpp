#ifdef _HAS_STD_BYTE
#undef _HAS_STD_BYTE
#endif // _HAS_STD_BYTE
#define _HAS_STD_BYTE 0
#include"全局变量存储区.h"
#include"文件存取操作.h"
#include"disp.h"
#include"功能-增.h"
#include"功能-删.h"
#include"功能-查.h"
#include"功能-改.h"
#include<Windows.h>
#include<string>
using namespace std;

//=========================================建立索引===========================================
manager::manager(string n, int priv) :name(n), privillagetype(priv)
{
	indexsm a;
	a.name = n;
	a.pointer = this;
	managers.push_back(a);
	if (isdebug)cout << "new manager obj create name " << a.name << " level " << a.pointer->privillagetype << endl;

}

//============================================================================================
void manager::addrecord()  //增
{
	while (true)
	{
		system("cls");
		cout << "请选择新增用户类型：" << endl;;
		cout << "1.学生" << endl;
		cout << "2.团支部成员" << endl;
		if (this->privillagetype == PERMISSION_DZB) cout << "3.党支部成员" << endl;
		cout << "4.退出" << endl<<endl;
		cout << "输入你的选择：";
		int userinp;
		cin >> userinp;
		switch (userinp)
		{
		case 1:
			addstudacc();
			continue;
		case 2:
			addTZSacc();
			continue;
		case 3:
			addDZBacc();
			continue;
		case 4:
			return;
		default:
			cout << "输入有误请重试！";
			continue;
		}
	}
}

void manager::delrecord()  //删
{
	while (true)
	{
		if (willlogout) return;
		system("cls");
		cout << "请选择删除用户类型："<<endl;
		cout << "1.学生" << endl;
		if (this->privillagetype == PERMISSION_DZB) cout << "2.党支部/团支部成员" <<  endl;
		cout << "3.退出" << endl << endl;
		cout << "输入您的选择：";
		int userinp;
		cin >> userinp;
		switch (userinp)
		{
		case 1:
			delstudrec();
			continue;
		case 2:
			delmanarec();
			continue;
		case 3:
			system("cls");
			return;
		default:
			break;
		}
		
	}
}

void manager::searchrecord()  //查
{
	while (true)
	{
		system("cls");
		cout << "请选择查找用户类型：" << endl;
		cout << "1.学生" << endl;
		cout << "2.党支部/团支部成员" << endl;
		cout << "3.退出" << endl << endl;
		cout << "输入您的选择：";
		int userinp;
		cin >> userinp;
		switch (userinp)
		{
		case 1:
			searchrecords();
			continue;
		case 2:
			searchmanager();
			continue;
		case 3:
			system("cls");
			return;
		default:
			break;
		}

	}
}

void manager::editrecord()  //改
{
	while (true)
	{
		system("cls");
		cout << "请选择修改用户类型：" << endl;
		cout << "1.学生" << endl;
		cout << "2.党支部/团支部成员" << endl;
		cout << "3.退出" << endl << endl;
		cout << "输入您的选择：";
		int userinp;
		cin >> userinp;
		switch (userinp)
		{
		case 1:
			editstud();
			continue;
		case 2:
			editmana();
			continue;
		case 3:
			system("cls");
			return;
		default:
			break;
		}
	}
}
void manager::getvotecond()
{
	for (auto it : students)
	{
		if (it.pointer->applydate != "none")
			cout << "姓名：" << it.pointer->name << " 推优情况：" << it.pointer->applydate << endl;
	}
}

void manager::judgeapplication()
{
	bool isnewexist = false;
	for (auto it : students)
	{
		if (it.pointer->status == 2) dispstudent(it);
		isnewexist = true;
	}
	if (isnewexist) cout << endl << "以上为新提交入党申请的学生" << endl;
	for (auto it : students)
	{
		if (it.pointer->status == 2)
		{
			it.pointer->status = 1;
			continue;
		}
		if (it.pointer->status == 1) dispstudent(it);
	}
	string target;
	indexs tar;
	while (true)
	{
		cout << "键入成员姓名：";
		cin >> target;
		bool isfound = false;
		for (auto it : students)
		{
			if (it.name == target)
			{
				dispstudent(it);
				tar = it;
				isfound = true;
				cout << endl;
				break;
			}
		}
		if (!isfound)
		{
			cout << "查无此人！" << endl;
			Sleep(1000);
			continue;
		}
		if (tar.pointer->status == 0 || tar.pointer->status == 4)
		{
			cout << "该学生未提交申请书" << endl;
			continue;
		}
		if (tar.pointer->status == 3)
		{
			cout << "该学生已是预备党员" << endl;
			continue;
		}
		tar.pointer->status = 3;
		tar.pointer->type = 3;
		save();
		cout << "是否继续查找（Y/N）?";
		char userinp;
		cin >> userinp;
		if (userinp == 'Y' || userinp == 'y') continue;
		else break;
	}
}

void manager::votecondrecadd()
{
	while (true)
	{
		system("cls");
		string target;
		indexs tar;
		cout << "键入学生姓名：";
		cin >> target;
		bool isfound = false;
		for (auto it : students)
		{
			if (it.name == target)
			{
				dispstudent(it);
				tar = it;
				isfound = true;
				cout << endl;
				break;
			}
		}
		if (!isfound)
		{
			cout << "查无此人！" << endl;
			Sleep(1000);
			continue;
		}
		cout << "输入推优情况（格式：同意票数/总票数）：";
		cin >> tar.pointer->votecondition;
		save();
		cout << "是否继续查找（Y/N）?";
		char userinp;
		cin >> userinp;
		if (userinp == 'Y' || userinp == 'y') continue;
		else break;
	}
}

void manager::releaseinfo()     //发布通知
{
	while (true)
	{
		system("cls");
		cout << "键入新通知内容：";
		cin >> *newinfo;
		cout << "新通知为：" << *newinfo << endl;;
		cout << "您确认吗（Y/N）？";
		char userinp;
		cin >> userinp;
		if (userinp == 'Y' || userinp == 'y') break;
	}
	save();
}
