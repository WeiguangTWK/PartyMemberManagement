#ifdef _HAS_STD_BYTE
#undef _HAS_STD_BYTE
#endif // _HAS_STD_BYTE
#define _HAS_STD_BYTE 0
#include"ȫ�ֱ����洢��.h"
#include"�ļ���ȡ����.h"
#include"disp.h"
#include"����-��.h"
#include"����-ɾ.h"
#include"����-��.h"
#include"����-��.h"
#include<Windows.h>
#include<string>
using namespace std;

//=========================================��������===========================================
manager::manager(string n, int priv) :name(n), privillagetype(priv)
{
	indexsm a;
	a.name = n;
	a.pointer = this;
	managers.push_back(a);
	if (isdebug)cout << "new manager obj create name " << a.name << " level " << a.pointer->privillagetype << endl;

}

//============================================================================================
void manager::addrecord()  //��
{
	while (true)
	{
		system("cls");
		cout << "��ѡ�������û����ͣ�" << endl;;
		cout << "1.ѧ��" << endl;
		cout << "2.��֧����Ա" << endl;
		if (this->privillagetype == PERMISSION_DZB) cout << "3.��֧����Ա" << endl;
		cout << "4.�˳�" << endl<<endl;
		cout << "�������ѡ��";
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
			cout << "�������������ԣ�";
			continue;
		}
	}
}

void manager::delrecord()  //ɾ
{
	while (true)
	{
		if (willlogout) return;
		system("cls");
		cout << "��ѡ��ɾ���û����ͣ�"<<endl;
		cout << "1.ѧ��" << endl;
		if (this->privillagetype == PERMISSION_DZB) cout << "2.��֧��/��֧����Ա" <<  endl;
		cout << "3.�˳�" << endl << endl;
		cout << "��������ѡ��";
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

void manager::searchrecord()  //��
{
	while (true)
	{
		system("cls");
		cout << "��ѡ������û����ͣ�" << endl;
		cout << "1.ѧ��" << endl;
		cout << "2.��֧��/��֧����Ա" << endl;
		cout << "3.�˳�" << endl << endl;
		cout << "��������ѡ��";
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

void manager::editrecord()  //��
{
	while (true)
	{
		system("cls");
		cout << "��ѡ���޸��û����ͣ�" << endl;
		cout << "1.ѧ��" << endl;
		cout << "2.��֧��/��֧����Ա" << endl;
		cout << "3.�˳�" << endl << endl;
		cout << "��������ѡ��";
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
			cout << "������" << it.pointer->name << " ���������" << it.pointer->applydate << endl;
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
	if (isnewexist) cout << endl << "����Ϊ���ύ�뵳�����ѧ��" << endl;
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
		cout << "�����Ա������";
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
		if (tar.pointer->status == 0 || tar.pointer->status == 4)
		{
			cout << "��ѧ��δ�ύ������" << endl;
			continue;
		}
		if (tar.pointer->status == 3)
		{
			cout << "��ѧ������Ԥ����Ա" << endl;
			continue;
		}
		tar.pointer->status = 3;
		tar.pointer->type = 3;
		save();
		cout << "�Ƿ�������ң�Y/N��?";
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
		cout << "���������������ʽ��ͬ��Ʊ��/��Ʊ������";
		cin >> tar.pointer->votecondition;
		save();
		cout << "�Ƿ�������ң�Y/N��?";
		char userinp;
		cin >> userinp;
		if (userinp == 'Y' || userinp == 'y') continue;
		else break;
	}
}

void manager::releaseinfo()     //����֪ͨ
{
	while (true)
	{
		system("cls");
		cout << "������֪ͨ���ݣ�";
		cin >> *newinfo;
		cout << "��֪ͨΪ��" << *newinfo << endl;;
		cout << "��ȷ����Y/N����";
		char userinp;
		cin >> userinp;
		if (userinp == 'Y' || userinp == 'y') break;
	}
	save();
}
