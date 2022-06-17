#include"文件存取操作.h"
#include"全局变量存储区.h"
#include<iostream>
#include<fstream>
using namespace std;

void save()
{
	ofstream file;

	savedatamanager man;
	file.open(FILEMANA, ios::out | ios::trunc | ios::binary);
	file.seekp(0);
	file.write((char*)&managercount, sizeof(int));
	if(isdebug)cout << "managercount=" << managercount << endl;
	
	for (auto it : managers)
	{
		man.name = it.name;
		man.privillagetype = it.pointer->privillagetype;
		file.write((char*)&man, sizeof(savedatamanager));
		if (isdebug)cout << "save manager name " << man.name << " type " << man.privillagetype << endl;
	}
	file.close();


	savedatastudent stud;
	file.open(FILESTUD, ios::out | ios::trunc | ios::binary);
	file.seekp(0);
	file.write((char*)&studentcount, sizeof(int));

	for (auto it : students)
	{
		stud.applydate = it.pointer->applydate;
		stud.name = it.pointer->name;
		stud.status = it.pointer->status;
		stud.type = it.pointer->type;
		stud.votecondition = it.pointer->votecondition;
		file.write((char*)&stud, sizeof(savedatastudent));
		if (isdebug)cout << "save student name " << stud.name << " type " << stud.type << endl;
	}
	size_t strlength = newinfo->length();
	file.write((char*)&strlength, sizeof(size_t));

	if (strlength != 0)
	{
		file.write((char*)newinfo, sizeof(string));
		if (isdebug) cout << "save new info" << *newinfo << endl;
	}

	file.close();
	if (isdebug)system("pause");
}

void load()
{
	ifstream file;

	
	savedatamanager *man=new savedatamanager;
	file.open(FILEMANA, ios::in | ios::binary);
	file.seekg(0);
	file.read((char*)&managercount, sizeof(int));
	if (isdebug)cout << "managercount=" << managercount << endl;
	

	for (int i = managercount; i > 0; i--)
	{
		file.read((char*)man, sizeof(savedatamanager));
		manager* add = new manager(man->name, man->privillagetype);
		if (isdebug)cout << "read manager " << add->name << " level " << add->privillagetype << endl;
	}
	file.close();



	savedatastudent* stud = new savedatastudent;
	file.open(FILESTUD, ios::in | ios::binary);
	file.seekg(0);
	file.read((char*)&studentcount, sizeof(int));
	if (isdebug)cout << "studentcount=" << studentcount << endl;

	for (int i = studentcount; i > 0; i--)
	{
		file.read((char*)stud, sizeof(savedatastudent));
		student* adds = new student(stud->name);
		adds->applydate = stud->applydate;
		adds->name = stud->name;
		adds->status = stud->status;
		adds->type = stud->type;
		adds->votecondition = stud->votecondition;
		if (isdebug)cout << "read student name " << adds->name << " type " << adds->status << endl;
	}
	size_t strlength = 0;
	file.read((char*)&strlength, sizeof(size_t));
	if (isdebug)cout << "strlength=" << strlength << endl;
	if (strlength != 0)
	{
		file.read((char*)newinfo, sizeof(string));
		if (isdebug) cout << "read new info" << *newinfo << endl;
	}

	file.close();
	if (isdebug)system("pause");
}

void clearall()
{
	for (auto it : students)
	{
		free(it.pointer);
	}
	students.clear();
	for (auto it : managers)
	{
		free(it.pointer);
	}
	managers.clear();
}

void refreshall()
{
	save();
	clearall();
	load();
}