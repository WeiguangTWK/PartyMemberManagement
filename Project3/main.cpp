#include<iostream>
#include<Windows.h>
#include"menus.h"
#include"ȫ�ֱ����洢��.h"
using namespace std;

vector<indexs>students;   //����ѧ���͹������������൱��Ŀ¼��
vector<indexsm>managers;

int studentcount;
int managercount;
student* currstud;
manager* currmana;

int main()
{
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