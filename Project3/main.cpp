#include<iostream>
#include<Windows.h>
#include"menus.h"
#include"FileRWOpts.h"
#include"ȫ�ֱ����洢��.h"
using namespace std;

vector<indexs>students;   //����ѧ���͹������������൱��Ŀ¼��
vector<indexsm>managers;

int studentcount;
int managercount;
student* currstud;
manager* currmana;

void firstbootsequence()
{
	string username;
	int type;
	cout << "�޹���Ա�˻�-�봴������һ����֧������֧���˻�" << endl;
	cout << "�û�����" << endl;
	cin >> username;
	
	while (true)
	{
		cout << "�����û����ͣ�0=��֧����1=��֧�飩��";
		cin >> type;
		if (!(type == 0 || type == 1)) cout << "�������������ԣ�";
		else break;
		system("cls");
	}
}

int main()
{
	load();
	if (managercount == 0)
		;
	while (true)
	{
		mainmenu();
		int userinp = 0;
		scanf_s("%d", &userinp);
		switch (userinp)
		{
		case 1:
			DZBmenu();
			continue;
		case 2:
			TZBmenu();
			continue;
		case 3:
			StudentMenu();
			continue;
		case 4:
			return 0;
		default:
			cout << "�������������ԣ�";
			continue;
		}
	}
}