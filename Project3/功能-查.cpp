#include"ȫ�ֱ����洢��.h"
#include"����-��.h"

indexs searchrecord(std::string target)
{
	for (auto it : students)
	{
		if (it.name == target) return it;
	}
	indexs tmp;
	tmp.name = "NULL";
	return tmp;
}

indexsm searchmanager(std::string target)
{
	for (auto it : managers)
	{
		if (it.name == target) return it;
	}
	indexsm tmp;
	tmp.name = "NULL";
	return tmp;
}