#include<fstream>
#include"ȫ�ֱ����洢��.h"
#define FILESTUD "studdata.dat"   //ѧ�����ݴ洢·��
#define FILEMANA "manadata.dat" //���������ݴ洢·��
using namespace std;

void pointptr(string name) {};

void load()
{
	int count, * countp = &count;
	ifstream file;  //�����ļ�����

	file.read((char*)countp, sizeof(int));

	for (int i = count;i > 0; i--)
	{
		savedatastudent stud, * studp = &stud;
		file.open(FILESTUD, std::ios::in | std::ios::binary);  //FILESTUD������ĺ궨��, std::ios::in ������ļ����ڶ�ȡ��std::iso::binary�����ļ��������Ʒ�ʽ��
		file.read((char*)studp, sizeof(savedatastudent));
		student* a=new student(stud.name);
		a->applydate = stud.applydate;
		a->name = stud.name;
		a->type = stud.type;
		a->votecondition = stud.votecondition;
		a->status = stud.status;
	}

	


	ifstream mfile;
	mfile.read((char*)countp, sizeof(int));

	for (int i = count; i > 0; i--)
	{
		savedatamanager man, * manp = &man;
		mfile.open(FILEMANA, std::ios::in | std::ios::binary);
		file.read((char*)manp, sizeof(savedatamanager));
		manager a(man.name, man.privillagetype);

	}
	
}

void save()
{
	savedatastudent stud, * studp = &stud;

	ofstream file;

	int* studcp = &studentcount;
	file.write((char*)studcp, sizeof(int));

	file.open(FILESTUD, std::ios::out | std::ios::binary);
	for (auto it : students)
	{
		stud.name = it.name;
		stud.applydate = it.pointer->applydate;
		stud.type = it.pointer->type;
		stud.votecondition = it.pointer->votecondition;
		file.write((char*)studp, sizeof(savedatastudent));
	}

	savedatamanager man, * manp = &man;

	ofstream mfile;
	mfile.open(FILEMANA, std::ios::out | std::ios::binary);
	int* mancp = &managercount;
	file.write((char*)mancp, sizeof(int));

	for (auto it : managers)
	{
		man.name = it.name;
		man.privillagetype = it.pointer->privillagetype;
		file.write((char*)manp, sizeof(savedatamanager));
	}
}