#include"����-��.h"
#include"ȫ�ֱ����洢��.h"
#include"�ļ���ȡ����.h"
using namespace std;

void addstudacc()
{
	while (true)
	{
		system("cls");
		savedatastudent tmp;
		cout << "������ѧ��������Ϣ��" << endl;;
		cout << "������";
		cin >> tmp.name;
		while (true)
		{
			cout << "������ò��0=Ⱥ�� 1=������Ա 2=�뵳�������� 3=Ԥ����Ա����";
			cin >> tmp.type;
			if (tmp.type == 0 || tmp.type == 1 || tmp.type == 2 || tmp.type == 3) break;
			cout << "�������������ԣ�" << endl;
		}
		student* added = new student(tmp.name);
		added->type = tmp.type;
		cout << "�Ƿ�¼����ϸ��Ϣ��Y/N��?";
		char isdetailed;
		cin >> isdetailed;
		if (isdetailed == 'Y' || isdetailed == 'y')
		{
			cout << "�������������";
			cin >> tmp.votecondition;
			cout << "�������һ�������뵳���ڣ�";
			cin >> tmp.applydate;
			added->votecondition = tmp.votecondition;
			added->applydate = tmp.applydate;
		}
		studentcount++;
		save();
		cout << "¼����ɣ��Ƿ����¼�룿��Y/N��";
		cin >> isdetailed;
		if (isdetailed == 'Y' || isdetailed == 'y') continue;
		break;
	}
}

void addTZSacc()
{
	while (true)
	{
		cout << "��������֧����Ա������ݣ�"<<endl;
		cout << "����:";
		savedatamanager tmp;
		cin >> tmp.name;
		tmp.privillagetype = PERMISSION_TZB;
		manager* a = new manager(tmp.name, tmp.privillagetype);
		managercount++;
		save();
		cout << "¼����ɣ��Ƿ����¼�룿��Y/N��";
		char userinp;
		cin >> userinp;
		if (userinp == 'Y' || userinp == 'y') continue;
		break;
	}
}
void addDZBacc()
{
	if (currmana->privillagetype != PERMISSION_DZB)
	{
		cout << "�������������ԣ�" << endl;
		system("cls");
		return;
	}
	while (true)
	{
		cout << "�����뵳֧����Ա������ݣ�" << endl;
		cout << "����:";
		savedatamanager tmp;
		cin >> tmp.name;
		tmp.privillagetype = PERMISSION_DZB;
		manager* a = new manager(tmp.name, tmp.privillagetype);
		managercount++;
		save();
		cout << "¼����ɣ��Ƿ����¼�룿��Y/N��";
		char userinp;
		cin >> userinp;
		if (userinp == 'Y' || userinp == 'y') continue;
		break;
	}
}