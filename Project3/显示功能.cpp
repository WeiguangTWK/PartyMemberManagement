#include"disp.h"
#include<iostream>
using namespace std;
void dispstudent(indexs src)
{
	cout << "������" << src.name << " ��ݣ�";
	switch (src.pointer->type)
	{
	case 0:
		cout << "Ⱥ�� ";
		break;
	case 1:
		cout << "������Ա ";
		break;
	case 2:
		cout << "�뵳�������� ";
		break;
	case 3:
		cout << "Ԥ����Ա ";
		break;
	}
	cout << "״̬��";
	switch (src.pointer->status)
	{
	case 0:
		cout << "δ�ύ���� ";
		break;
	case 1:
		cout << "�������յ� ";
		break;
	case 2:
		cout << "�������ύ����δ�� ";
		break;
	case 3:
		cout << "����ͨ�� ";
		break;
	case 4:
		cout << "���벻ͨ�� ";
		break;
	}
	cout << "���������" << src.pointer->votecondition << " ���һ���ύ���룺" << src.pointer->applydate << endl;;
}

void dispstudent(student* src)
{
	cout << "������" << src->name << " ��ݣ�";
	switch (src->type)
	{
	case 0:
		cout << "Ⱥ�� ";
		break;
	case 1:
		cout << "������Ա ";
		break;
	case 2:
		cout << "�뵳�������� ";
		break;
	case 3:
		cout << "Ԥ����Ա ";
		break;
	}
	cout << "״̬��";
	switch (src->status)
	{
	case 0:
		cout << "δ�ύ���� ";
		break;
	case 1:
		cout << "�������յ� ";
		break;
	case 2:
		cout << "�������ύ����δ�� ";
		break;
	case 3:
		cout << "����ͨ�� ";
		break;
	case 4:
		cout << "���벻ͨ�� ";
		break;
	}
	cout << "���������" << src->votecondition << " ���һ���ύ���룺" << src->applydate<<endl;
}

void dispmanager(indexsm src)
{
	cout << "������" << src.name << " ��Ա���ͣ�";
	switch (src.pointer->privillagetype)
	{
	case PERMISSION_DZB:
		cout << "��֧����Ա";
		break;
	case PERMISSION_TZB:
		cout << "��֧����Ա";
		break;
	}
}