#include"����-ɾ.h"
#include"�ļ���ȡ����.h"
#include"ȫ�ֱ����洢��.h"
#include<Windows.h>
#include<iostream>
using namespace std;

string name;

bool tmpfunc(indexs & task)
	{
	return task.name == name;
	}
bool tmpfuncm(indexsm& task)
{
	return task.name == name;
}
void delstudrec()
{
	
	while (true)
	{
		system("cls");
		cout << "����Ҫɾ����ѧ��������";

		bool isdeled = false;
		cin >> name;
		for (auto it : students)
		{
			if (it.name == name)
			{
				if (isdebug) cout << "ɾ����" << it.name << endl;
				free(it.pointer);
				indexs tmp;
				tmp.name = name;
				tmp.pointer = it.pointer;
				vector<indexs>::iterator itr;
				itr = find_if(students.begin(), students.end(),tmpfunc);
				students.erase(itr);
				studentcount--;
				isdeled = true;
				break;
			}
		}
		if (isdeled)
		{
			save();
			cout << "ɾ���ɹ���" << endl;
			cout << "�Ƿ����ɾ��������¼��Y/N)��";
			char userinp;
			cin >> userinp;
			if (userinp == 'Y' || userinp == 'y') continue;
			break;
		}
		else
		{
			cout << "δ�ҵ���ѧ���������ԣ�" << endl;
			Sleep(1200);
			continue;
		}

	}
}


void delmanarec()
{
	while (true)
	{
		system("cls");
		cout << "����Ҫɾ���ĵ�֧��/��֧����Ա������";
		bool isdeled = false;
		cin >> name;
		for (auto it : managers)
		{
			if (it.name == name)
			{
				if (name == currmana->name)
				{
					cout << "���棺��ɾ��Ŀǰ��½���˻���ɾ�����������ǳ�" << endl;
					cout << "��ȷ����Y/N��?";
					char userinp;
					cin >> userinp;
					if (userinp == 'Y' || userinp == 'y') willlogout = true;
					else continue;
				}
				if (isdebug) cout << "ɾ����" << it.name << endl;
				free(it.pointer);
				indexsm tmp;
				tmp.name = name;
				tmp.pointer = it.pointer;
				vector<indexsm>::iterator itr;
				itr = find_if(managers.begin(), managers.end(), tmpfuncm);
				managers.erase(itr);
				managercount--;
				isdeled = true;
				break;
			}
		}
		if (isdeled)
		{
			save();
			cout << "ɾ���ɹ���" << endl;
			
			if (willlogout)
			{
				Sleep(1000);
				system("cls");
				return;
			}

			cout << "�Ƿ����ɾ��������¼��Y/N)��";
			char userinp;
			cin >> userinp;
			if (userinp == 'Y' || userinp == 'y') continue;
			break;
		}
		else
		{
			cout << "δ�ҵ��ó�Ա�������ԣ�" << endl;
			Sleep(1200);
			continue;
		}

	}
}