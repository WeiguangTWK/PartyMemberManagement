#include"������.h"
#include"ȫ�ֱ����洢��.h"
#include"�ļ���ȡ����.h"
#include"disp.h"
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

void student::viewfunc() //�鿴
{
	dispstudent(this);
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
