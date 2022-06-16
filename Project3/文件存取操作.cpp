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
	//cout << "managercount=" << managercount << endl;
	//system("pause");
	
	for (auto it : managers)
	{
		man.name = it.name;
		man.privillagetype = it.pointer->privillagetype;
		file.write((char*)&man, sizeof(savedatamanager));
	}
}

void load()
{
	ifstream file;


	savedatamanager *man=new savedatamanager;
	file.open(FILEMANA, ios::in | ios::binary);
	file.seekg(0);
	file.read((char*)&managercount, sizeof(int));
	cout << "managercount=" << managercount << endl;
	system("pause");

	for (int i = managercount; i > 0; i--)
	{
		file.read((char*)man, sizeof(savedatamanager));
		manager* add = new manager(man->name, man->privillagetype);
		cout << "read manager " << add->name << " level " << add->privillagetype << endl;
	}
	file.close();
}