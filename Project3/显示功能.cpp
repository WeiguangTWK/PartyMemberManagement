#include"disp.h"
#include<iostream>
using namespace std;
void dispstudent(indexs src)
{
	cout << "姓名：" << src.name << " 身份：";
	switch (src.pointer->type)
	{
	case 0:
		cout << "群众 ";
		break;
	case 1:
		cout << "共青团员 ";
		break;
	case 2:
		cout << "入党积极分子 ";
		break;
	case 3:
		cout << "预备党员 ";
		break;
	}
	cout << "状态：";
	switch (src.pointer->status)
	{
	case 0:
		cout << "未提交申请 ";
		break;
	case 1:
		cout << "申请已收到 ";
		break;
	case 2:
		cout << "申请已提交，但未读 ";
		break;
	case 3:
		cout << "申请通过 ";
		break;
	case 4:
		cout << "申请不通过 ";
		break;
	}
	cout << "推优情况：" << src.pointer->votecondition << " 最近一次提交申请：" << src.pointer->applydate << endl;;
}

void dispstudent(student* src)
{
	cout << "姓名：" << src->name << " 身份：";
	switch (src->type)
	{
	case 0:
		cout << "群众 ";
		break;
	case 1:
		cout << "共青团员 ";
		break;
	case 2:
		cout << "入党积极分子 ";
		break;
	case 3:
		cout << "预备党员 ";
		break;
	}
	cout << "状态：";
	switch (src->status)
	{
	case 0:
		cout << "未提交申请 ";
		break;
	case 1:
		cout << "申请已收到 ";
		break;
	case 2:
		cout << "申请已提交，但未读 ";
		break;
	case 3:
		cout << "申请通过 ";
		break;
	case 4:
		cout << "申请不通过 ";
		break;
	}
	cout << "推优情况：" << src->votecondition << " 最近一次提交申请：" << src->applydate<<endl;
}

void dispmanager(indexsm src)
{
	cout << "姓名：" << src.name << " 成员类型：";
	switch (src.pointer->privillagetype)
	{
	case PERMISSION_DZB:
		cout << "党支部成员";
		break;
	case PERMISSION_TZB:
		cout << "团支部成员";
		break;
	}
	cout << endl;
}