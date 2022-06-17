#include"disp.h"
#include"功能-改.h"
#include"全局变量存储区.h"
#include"文件存取操作.h"
#include<Windows.h>
using namespace std;
void editstud()
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
		cout << "请输入修改后学生基本信息：" << endl;;
		cout << "姓名：";
		string name;
		cin >> name;
		cout << "name=" << name << endl;
		tar.name = name;
		tar.pointer->name = name;
		cout << "tar.name=" << tar.name << endl;
		cout << "tar.pointer->name=" << tar.pointer->name << endl;
		while (true)
		{
			cout << "政治面貌（0=群众 1=共青团员 2=入党积极分子 3=预备党员）：";
			cin >> tar.pointer->type;
			if (tar.pointer->type == 0 || tar.pointer->type == 1 || tar.pointer->type == 2 || tar.pointer->type == 3) break;
			cout << "输入有误，请重试！" << endl;
		}
		cout << "是否录入详细信息（Y/N）?";
		char isdetailed;
		cin >> isdetailed;
		if (isdetailed == 'Y' || isdetailed == 'y')
		{
			cout << "输入推优情况：";
			cin >> tar.pointer->votecondition;
			cout << "输入最近一次申请入党日期：";
			cin >> tar.pointer->applydate;
		}
		save();
		cout << "是否继续查找（Y/N）?";
		char userinp;
		cin >> userinp;
		if (userinp == 'Y' || userinp == 'y') continue;
		else break;
	}
}
void editmana()
{
	while (true)
	{
		system("cls");
		string target;
		indexsm tar;
		cout << "键入成员姓名：";
		cin >> target;
		bool isfound = false;
		for (auto it : managers)
		{
			if (it.name == target)
			{
				dispmanager(it);
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
		cout << "请输入更改后成员基本身份：" << endl;
		cout << "姓名:";
		cin >> tar.pointer->name;
		while (true)
		{
			cout << "身份(0=党支部成员 1=团支部成员)：";
			cin >> tar.pointer->privillagetype;
			if (!(tar.pointer->privillagetype == PERMISSION_DZB || tar.pointer->privillagetype))
			{
				cout << "输入有误，请重试！" << endl;
				continue;
			}
			else break;
		}
		refreshall();
		cout << "是否继续查找（Y/N）?";
		char userinp;
		cin >> userinp;
		if (userinp == 'Y' || userinp == 'y') continue;
		else break;
	}
}