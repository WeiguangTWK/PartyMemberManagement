#include<fstream>
#include"全局变量存储区.h"
#define FILESTUD "studdata.dat"   //学生数据存储路径
#define FILEMANA "manadata.dat" //管理者数据存储路径
using namespace std;

void pointptr(string name) {};

void load()
{
	int * countp = &studentcount;
	ifstream file;  //创建文件对象
	file.open(FILESTUD, std::ios::in | std::ios::binary);  //FILESTUD见上面的宏定义, std::ios::in 代表打开文件用于读取，std::iso::binary代表文件按二进制方式打开

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