#include"������.h"
#include"ȫ�ֱ����洢��.h"
#include"�ļ���ȡ����.h"
using namespace std;


//=========================================��������===========================================
student::student(string n) :name(n)
{
	indexs a;
	a.name = n;
	a.pointer = this;
	students.push_back(a); 
	if (isdebug)cout << "new student obj create name " << a.name << " level " << a.pointer->type << endl;
}
//============================================================================================

void student::viewfunc()
{
	system("cls");
	cout << "����  " << "������ò  " << "�뵳���״̬  " << "���һ������ʱ��" << endl;
	cout << this->name << "  ";
	switch (this->type)
	{
	case 0:
		cout << "Ⱥ��  ";
		break;
	case 1:
		cout << "������Ա  ";
		break;
	case 2:
		cout << "�뵳��������  ";
		break;
	case 3:
		cout << "Ԥ����Ա  ";
		break;
	default:
		break;
	}
	switch (this->status)
	{
	case 0:
		cout << "δ����  ";
		break;
	case 1:
		cout << "���ύ����  ";
		break;
	case 2:
		cout << "���ύ���룬��δ��  ";
		break;
	case 3:
		cout << "����ͨ����  ";
		break;
	case 4:
		cout << "���벻ͨ��  ";
		break;
	default:
		break;
	}
	cout << this->applydate << endl;
	system("pause");
}

void student::applyaction()
{
	cout << "�뵳��֪��" << endl;
	cout << "1.��ȡ�뵳���л����������Ů���Ծ�Ҫ��" << endl;
	cout << "2.Ҫ���ϵ��ٺ͵��£��˽⵳�Ļ���֪ʶ" << endl;
	cout << "3.������ԱҪΪʵ�ֹ�������ܶ�����" << endl;
	cout << "4.������ԱҪ�߾��й���ɫ��������ΰ������" << endl;
	cout << "5.����ѧϰ���˼�������塢ë��˼��" << endl;
	cout << "6.����ѧϰ�й���ɫ�������������ϵ" << endl;
	cout << "7.Ϊ������������г�����ש����" << endl;
	cout << "8.������ԱҪ����������彨���ģ��" << endl;
	cout << "9.�ػ����룬������ʵ���ִ᳹�е��Ļ���·�ߺ͸��������" << endl;
	cout << "10.��ֵ���������������һ��" << endl << endl;
	cout << "�Ķ���ɺ�ѡ���Ƿ��ύ��Y/N��:";
	char userinp;
	cin >> userinp;
	if (userinp == 'Y' || userinp == 'y')
	{
		this->status = 2;
		save();
		cout << "���������Ѽ�¼�ڰ�������������ǰ����֧���ݽ��뵳�����飬���������ͨ����ϵͳ��ѯ�뵳����" << endl;
	}
	else
	{
		cout << "��ȡ��������" << endl;
	}
}
