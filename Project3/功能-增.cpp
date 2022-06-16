#include"功能-增.h"
#include"全局变量存储区.h"
#include"文件存取操作.h"
using namespace std;

void addstudacc()
{
	while (true)
	{
		system("cls");
		savedatastudent tmp;
		cout << "请输入学生基本信息：";
		cout << "姓名：";
		cin >> tmp.name;
		while (true)
		{
			cout << "政治面貌（0=群众 1=共青团员 2=入党积极分子 3=预备党员）：";
			cin >> tmp.type;
			if (tmp.type == 0 || tmp.type == 1 || tmp.type == 2 || tmp.type == 3) break;
			cout << "输入有误，请重试！" << endl;
		}
		student* added = new student(tmp.name);
		added->type = tmp.type;
		cout << "是否录入详细信息（Y/N）?";
		char isdetailed;
		cin >> isdetailed;
		if (isdetailed == 'Y' || isdetailed == 'y')
		{
			cout << "输入推优情况：";
			cin >> tmp.votecondition;
			cout << "输入最近一次申请入党日期：";
			cin >> tmp.applydate;
			added->votecondition = tmp.votecondition;
			added->applydate = tmp.applydate;
		}
		studentcount++;
		save();
		cout << "录入完成，是否继续录入？（Y/N）";
		cin >> isdetailed;
		if (isdetailed == 'Y' || isdetailed == 'y') continue;
		break;
	}
}

void addTZSacc()
{
	while (true)
	{
		cout << "请输入团支部成员基本身份：";
		cout << "姓名:" << endl;
		savedatamanager tmp;
		cin >> tmp.name;
		tmp.privillagetype = PERMISSION_TZB;
		manager* a = new manager(tmp.name, tmp.privillagetype);
		managercount++;
		save();
		cout << "录入完成，是否继续录入？（Y/N）";
		char userinp;
		cin >> userinp;
		if (userinp == 'Y' || userinp == 'y') continue;
		break;
	}
}
void addDZBacc()
{
	while (true)
	{
		cout << "请输入党支部成员基本身份：";
		cout << "姓名:" << endl;
		savedatamanager tmp;
		cin >> tmp.name;
		tmp.privillagetype = PERMISSION_DZB;
		manager* a = new manager(tmp.name, tmp.privillagetype);
		managercount++;
		save();
		cout << "录入完成，是否继续录入？（Y/N）";
		char userinp;
		cin >> userinp;
		if (userinp == 'Y' || userinp == 'y') continue;
		break;
	}
}