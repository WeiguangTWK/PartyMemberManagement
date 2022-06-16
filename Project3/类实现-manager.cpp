#include"全局变量存储区.h"
#include"文件存取操作.h"
#include"功能-增.h"
#include"功能-删.h"
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

void manager::delrecord()
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

void manager::searchrecord()
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
			
			continue;
		case 2:
			
			continue;
		case 3:
			system("cls");
			return;
		default:
			break;
		}

	}
}

void manager::releaseinfo()     //发布通知
{
	while (true)
	{
		system("cls");
		cout << "键入新通知内容：";
		cin >> newinfo;
		cout << "新通知为：" << newinfo << endl;;
		cout << "您确认吗（Y/N）？";
		char userinp;
		cin >> userinp;
		if (userinp == 'Y' || userinp == 'y') continue;
	}
	save();
}
