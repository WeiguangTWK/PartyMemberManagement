#include<iostream>
#include<Windows.h>
#include"�˵�.h"
#include"�ļ���ȡ����.h"
#include"ȫ�ֱ����洢��.h"
using namespace std;

vector<indexs>students;   //����ѧ���͹������������൱��Ŀ¼��
vector<indexsm>managers;

std::string newinfo = "��֪ͨ"; //��֪ͨ
int studentcount=0;
int managercount=0;
student* currstud;
manager* currmana;

bool isdebug = false;

void firstbootsequence()
{
	string username;
	int type;
	cout << "�޹���Ա�˻�-�봴������һ����֧������֧���˻�" << endl;
	cout << "�û�����";
	cin >> username;
	
	while (true)
	{
		cout << "�����û����ͣ�0=��֧����1=��֧������";
		cin >> type;
		if (!(type == PERMISSION_DZB || type == PERMISSION_TZB)) cout << "�������������ԣ�";
		else break;
		system("cls");
	}
	manager* a = new manager(username, type);
	managercount = 1;
	save();
	system("cls");
}

int main()
{
	load();
	if (managercount == 0)
		firstbootsequence();
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