#include"全局变量存储区.h"
#include"功能-查.h"
#include"disp.h"
using namespace std;
void searchrecords()
{
	while (true)
	{
		cout << "输入查找的学生姓名：";
		string target;
		cin >> target;
		bool isfound = false;
		int count = 0;
		for (auto it : students)
		{
			if (it.name == target)
			{
				dispstudent(it);
				count++;
				isfound = true;
			}
			
		}
		if (isfound) cout << "共找到" << count << "条记录" << endl;
		else cout << "查无此人" << endl;
		cout << "是否继续查找（Y/N）?";
		char userinp;
		cin >> userinp;
		if (userinp == 'Y' || userinp == 'y') continue;
		else break;
	}
}

void searchmanager()
{
	while (true)
	{
		cout << "输入查找的成员姓名：";
		string target;
		cin >> target;
		bool isfound = false;
		int count = 0;
		for (auto it : managers)
		{
			if (it.name == target)
			{
				dispmanager(it);
				count++;
				isfound = true;
			}
			
		}
		if (isfound) cout << "共找到" << count << "条记录" << endl;
		else cout << "查无此人" << endl;
		cout << "是否继续查找（Y/N）?";
		char userinp;
		cin >> userinp;
		if (userinp == 'Y' || userinp == 'y') continue;
		else break;
	}
}