#include"ȫ�ֱ����洢��.h"
#include"�ļ���ȡ����.h"
#include"����-��.h"
#include"����-ɾ.h"
#include"����-��.h"
#include"����-��.h"
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

void manager::editrecord()
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

void manager::releaseinfo()     //����֪ͨ
{
	while (true)
	{
		system("cls");
		cout << "������֪ͨ���ݣ�";
		cin >> newinfo;
		cout << "��֪ͨΪ��" << newinfo << endl;;
		cout << "��ȷ����Y/N����";
		char userinp;
		cin >> userinp;
		if (userinp == 'Y' || userinp == 'y') continue;
	}
	save();
}
