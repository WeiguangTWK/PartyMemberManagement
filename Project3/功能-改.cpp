#include"disp.h"
#include"����-��.h"
#include"ȫ�ֱ����洢��.h"
#include"�ļ���ȡ����.h"
#include<Windows.h>
using namespace std;
void editstud()
{
	while (true)
	{
		system("cls");
		string target;
		indexs tar;
		cout << "����ѧ��������";
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
			cout << "���޴��ˣ�" << endl;
			Sleep(1000);
			continue;
		}
		cout << "�������޸ĺ�ѧ��������Ϣ��" << endl;;
		cout << "������";
		string name;
		cin >> name;
		cout << "name=" << name << endl;
		tar.name = name;
		tar.pointer->name = name;
		cout << "tar.name=" << tar.name << endl;
		cout << "tar.pointer->name=" << tar.pointer->name << endl;
		while (true)
		{
			cout << "������ò��0=Ⱥ�� 1=������Ա 2=�뵳�������� 3=Ԥ����Ա����";
			cin >> tar.pointer->type;
			if (tar.pointer->type == 0 || tar.pointer->type == 1 || tar.pointer->type == 2 || tar.pointer->type == 3) break;
			cout << "�������������ԣ�" << endl;
		}
		cout << "�Ƿ�¼����ϸ��Ϣ��Y/N��?";
		char isdetailed;
		cin >> isdetailed;
		if (isdetailed == 'Y' || isdetailed == 'y')
		{
			cout << "�������������";
			cin >> tar.pointer->votecondition;
			cout << "�������һ�������뵳���ڣ�";
			cin >> tar.pointer->applydate;
		}
		save();
		cout << "�Ƿ�������ң�Y/N��?";
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
		cout << "�����Ա������";
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
			cout << "���޴��ˣ�" << endl;
			Sleep(1000);
			continue;
		}
		cout << "��������ĺ��Ա������ݣ�" << endl;
		cout << "����:";
		cin >> tar.pointer->name;
		while (true)
		{
			cout << "���(0=��֧����Ա 1=��֧����Ա)��";
			cin >> tar.pointer->privillagetype;
			if (!(tar.pointer->privillagetype == PERMISSION_DZB || tar.pointer->privillagetype))
			{
				cout << "�������������ԣ�" << endl;
				continue;
			}
			else break;
		}
		save();
		cout << "�Ƿ�������ң�Y/N��?";
		char userinp;
		cin >> userinp;
		if (userinp == 'Y' || userinp == 'y') continue;
		else break;
	}
}