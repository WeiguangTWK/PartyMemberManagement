#include"ȫ�ֱ����洢��.h"
#include"�ļ���ȡ����.h"
#include"����-��.h"
using namespace std;

//=========================================��������===========================================
manager::manager(string n, int priv) :student(n), privillagetype(priv)
{
	indexsm a;
	a.name = n;
	a.pointer = this;
	managers.push_back(a);
}

//============================================================================================
void manager::addrecord()  //��
{
	while (true)
	{
		system("cls");
		cout << "��ѡ�������û����ͣ�";
		cout << "1.ѧ��" << endl;
		cout << "2.��֧����Ա" << endl;
		if (this->privillagetype == PERMISSION_DZB) cout << "3.��֧����Ա" << endl << endl;
		cout << "4.�˳�" << endl;
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
