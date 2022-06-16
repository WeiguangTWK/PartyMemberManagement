#include<fstream>
#include"ȫ�ֱ����洢��.h"
#define FILESTUD "studdata.dat"   //ѧ�����ݴ洢·��
#define FILEMANA "manadata.dat" //���������ݴ洢·��
using namespace std;

void pointptr(string name) {};

void load()
{
	int * countp = &studentcount;
	ifstream file;  //�����ļ�����
	file.open(FILESTUD, std::ios::in | std::ios::binary);  //FILESTUD������ĺ궨��, std::ios::in ������ļ����ڶ�ȡ��std::iso::binary�����ļ��������Ʒ�ʽ��

	file.read((char*)countp, sizeof(int));

	for (int i = studentcount;i > 0; i--)
	{
		savedatastudent stud, * studp = &stud;
		file.read((char*)studp, sizeof(savedatastudent));
		student* a=new student(stud.name);
		a->applydate = stud.applydate;
		a->name = stud.name;
		a->type = stud.type;
		a->votecondition = stud.votecondition;
		a->status = stud.status;
	}
	file.close();
	
	countp = &managercount;

	ifstream mfile;
	mfile.open(FILEMANA, std::ios::in | std::ios::binary);

	mfile.read((char*)countp, sizeof(int));

	for (int i = managercount; i > 0; i--)
	{
		savedatamanager man, * manp = &man;
		file.read((char*)manp, sizeof(savedatamanager));
		manager* a=new manager(man.name, man.privillagetype);

	}
	mfile.close();
}

void save()
{
	savedatastudent stud, * studp = &stud;

	ofstream file;

	int* countp = &studentcount;
	file.open(FILESTUD, std::ios::out | std::ios::binary);

	file.write((char*)countp, sizeof(int));

	for (auto it : students)
	{
		stud.name = it.name;
		stud.applydate = it.pointer->applydate;
		stud.type = it.pointer->type;
		stud.votecondition = it.pointer->votecondition;
		file.write((char*)studp, sizeof(savedatastudent));
	}
	file.close();

	countp = &managercount;
	savedatamanager man, * manp = &man;

	ofstream mfile;
	mfile.open(FILEMANA, std::ios::out | std::ios::binary);
	file.write((char*)countp, sizeof(int));

	for (auto it : managers)
	{
		man.name = it.name;
		man.privillagetype = it.pointer->privillagetype;
		file.write((char*)manp, sizeof(savedatamanager));
	}
	mfile.close();
}

void clearall() //ɾ���������ڴ�ļ�¼
{
	for (auto it : students) free(it.pointer);
	for (auto it : managers) free(it.pointer);
	students.clear();
	managers.clear();
}