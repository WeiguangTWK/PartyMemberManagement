#include"ȫ�ֱ����洢��.h"
#include"����-��.h"
#include"disp.h"
using namespace std;
void searchrecords()
{
	while (true)
	{
		cout << "������ҵ�ѧ��������";
		string target;
		cin >> target;
		bool isfound = false;
		int count = 0;
		for (auto it : students)
		{
			if (it.name == target)
			{
				dispstudent(it);
				count++;
				isfound = true;
			}
			
		}
		if (isfound) cout << "���ҵ�" << count << "����¼" << endl;
		else cout << "���޴���" << endl;
		cout << "�Ƿ�������ң�Y/N��?";
		char userinp;
		cin >> userinp;
		if (userinp == 'Y' || userinp == 'y') continue;
		else break;
	}
}

void searchmanager()
{
	while (true)
	{
		cout << "������ҵĳ�Ա������";
		string target;
		cin >> target;
		bool isfound = false;
		int count = 0;
		for (auto it : managers)
		{
			if (it.name == target)
			{
				dispmanager(it);
				count++;
				isfound = true;
			}
			
		}
		if (isfound) cout << "���ҵ�" << count << "����¼" << endl;
		else cout << "���޴���" << endl;
		cout << "�Ƿ�������ң�Y/N��?";
		char userinp;
		cin >> userinp;
		if (userinp == 'Y' || userinp == 'y') continue;
		else break;
	}
}