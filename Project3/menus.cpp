//��������д�˵���
#pragma once
#include"menus.h"
#include"auth.h"
#include"ȫ�ֱ����洢��.h"
#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;

void mainmenu()
{
	cout << "ѡ�������ݣ�" << endl << "1.��֧����Ա" << endl << "2.��֧����Ա" << endl << "3.ѧ��" << endl << "4.�˳�ϵͳ" << endl << "����ѡ�";
}

void DZBmenu()
{
	while (true)
	{
		system("cls");
		cout << "����֤��֧����ݣ�" << endl;;
		cout << "�����û��������߼��롰exit�����˳���";
		string userinp;
		cin >> userinp;
		if (userinp == "exit")
		{
			system("cls");
			return;
		}
		if (authmananame(userinp))
		{
			if (!(currmana->privillagetype==0))
			{
				cout << "����½����ݲ��ǵ�֧����Ա��" << endl;
				continue;
			}
			cout << "��½�ɹ���";
			system("cls");   //����
			break;
		}
		else
		{
			cout << "��½ʧ�ܣ������ԣ�";
			continue;
		}
	}
	while (true)
	{
		system("cls");
		cout << "��ӭ����֧����Ա����ѡ�����Ĳ�����" << endl;
		cout << "1.������Ա"<<endl;
		cout << "2.ɾ����Ա" << endl;
		cout << "3.������Ա��Ϣ" << endl;
		cout << "4.��ѯ��Ա��Ϣ" << endl;
		cout << "5.��ȡ�������" << endl;
		cout << "6.�ж���Աת��" << endl;
		cout << "7.�ǳ��˺�" << endl;
		cout << "������Ҫ���еĲ�����";
		int userinp;
		cin >> userinp;
		switch (userinp)
		{
		case 1:
			continue;
		case 2:
			continue;
		case 3:
			continue;
		case 4:
			continue;
		case 5:
			continue;
		case 6:
			continue;
		case 7:
			return;
		default:
			cout << "ѡ�����������ԣ�";
			continue;
		}
	}
}


void TZBmenu()
{
	while (true)
	{
		system("cls");
		cout << "����֤��֧����ݣ�" << endl;;
		cout << "�����û��������߼��롰exit�����˳���";
		string userinp;
		cin >> userinp;
		if (userinp == "exit")
		{
			system("cls");
			return;
		}
		if (authmananame(userinp))
		{
			if (!(currmana->privillagetype == 1))
			{
				cout << "����½����ݲ�����֧���Ա��" << endl;
				continue;
			}
			cout << "��½�ɹ���";
			system("cls");   //����
			break;
		}
		else
		{
			cout << "��½ʧ�ܣ������ԣ�";
			continue;
		}
	}
	while (true)
	{
		system("cls");
		cout << "��ӭ����֧���Ա����ѡ�����Ĳ�����" << endl;
		cout << "1.������Ա" << endl;
		cout << "2.ɾ����Ա" << endl;
		cout << "3.������Ա��Ϣ" << endl;
		cout << "4.��ѯ��Ա��Ϣ" << endl;
		cout << "5.¼���������" << endl;
		cout << "6.�ǳ��˺�" << endl;
		cout << "������Ҫ���еĲ�����";
		int userinp;
		cin >> userinp;
		switch (userinp)
		{
		case 1:
			continue;
		case 2:
			continue;
		case 3:
			continue;
		case 4:
			continue;
		case 5:
			continue;
		case 6:
			return;
		default:
			cout << "ѡ�����������ԣ�";
			continue;
		}
	}
}

void StudentMenu()
{
	while (true)
	{
		system("cls");
		cout << "����֤ѧ����ݣ�" << endl;;
		cout << "�����û��������߼��롰exit�����˳���";
		string userinp;
		cin >> userinp;
		if (userinp == "exit")
		{
			system("cls");
			return;
		}
		if (authstudname(userinp))
		{
			cout << "��½�ɹ���";
			system("cls");   //����
			break;
		}
		else
		{
			cout << "��½ʧ�ܣ������ԣ�";
			continue;
		}
	}
	while (true)
	{
		system("cls");
		cout << "��ӭͬѧ��½����ϵͳ����ѡ�����:" << endl;;
		cout << "1.��ѯ������Ϣ" << endl;
		cout << "2.�ݽ��뵳����" << endl;
		cout << "3.�ǳ��˺�" << endl;
		cout << "������Ҫ���еĲ�����";
		int userinp;
		cin >> userinp;
		switch (userinp)
		{
		case 1:
			continue;
		case 2:
			currstud->applyaction();
			continue;
		case 3:
			return;
		default:
			cout << "ѡ�����������ԣ�";
			continue;
		}
	}
}