#include<string>
#include"ȫ�ֱ����洢��.h"
bool authmananame(std::string _name)
{
	for (auto it : managers)
	{
		if (it.name == _name)
		{
			currmana = it.pointer;
			return true;
		}
	}
	return false;
}

bool authstudname(std::string _name)
{
	for (auto it : students)
	{
		if (it.name == _name)
		{
			currstud = it.pointer;
			return true;
		}
	}
	return false;
}