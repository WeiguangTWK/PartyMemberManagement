#include"����-��.h"
#include"ȫ�ֱ����洢��.h"
#include"�ļ���ȡ����.h"
using namespace std;

void addstudacc()
{
	savedatastudent tmp;
	cout << "������ѧ��������Ϣ��";
	cout << "������";
	cin >> tmp.name;
	while (true)
	{
		cout << "������ò��0=Ⱥ�� 1=������Ա 2=�뵳�������� 3=Ԥ����Ա����";
		cin >> tmp.type;
		if (tmp.type == 0 || tmp.type == 1 || tmp.type == 2 || tmp.type == 3) break;
		cout << "�������������ԣ�" << endl;
	}
	student* added = new student(tmp.name);
	added->type = tmp.type;
	cout << "�Ƿ�¼����ϸ��Ϣ��Y/N��?";
	char isdetailed;
	cin >> isdetailed;
	if (isdetailed == 'Y' || isdetailed == 'y')
	{
		cout << "�������������";
		cin >> tmp.votecondition;
		cout << "�������һ�������뵳���ڣ�";
		cin >> tmp.applydate;
		added->votecondition = tmp.votecondition;
		added->applydate = tmp.applydate;
	}
	studentcount++;
	save();
}
void addTZSacc();
void addDZBacc();