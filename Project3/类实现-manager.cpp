#include"全局变量存储区.h"
#include"文件存取操作.h"
using namespace std;

//=========================================建立索引===========================================
manager::manager(string n, int priv) :student(n), privillagetype(priv)
{
	indexsm a;
	a.name = n;
	a.pointer = this;
	managers.push_back(a);
}

//============================================================================================
void manager::addrecord()  //增
{
	while (true)
	{
		system("cls");
		cout << "请选择新增用户类型：";
		cout << "1.学生" << endl;
		cout << "2.团支部成员" << endl;
		if (this->privillagetype == 0) cout << "3.党支部成员" << endl << endl;
		cout << "4.退出" << endl;
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
			return;
		default:
			cout << "输入有误请重试！";
			continue;
		}
	}
}