#pragma once
#define PERMISSION_DZB 0
#define PERMISSION_TZB 1
#include<iostream>
#include<string>
class student
{
public:
	
	//std::string passwd;
	student(std::string n);
	void applyaction();        //申请入党

	std::string name;
	std::string applydate="none";     //申请日期
	int type = 0;  //0=群众 1=共青团员 2=入党积极分子 3=预备党员
	std::string votecondition="none"; //推优情况
	int status = 0;  //0=通常 1=申请成为共产党员 2=新申请 3=申请通过 4=申请不通过
private:
	void viewfunc();
};

class manager :public student
{
public:
	manager(std::string n, int priv);
	void addrecord(); //增
	void delrecord(); //删
	void editrecord(); //改
	void searchrecord(); //查

	void getvotecond();   //获取推优情况
	void judgeapplication();  //判定转正

	void votecondrecadd();  //录入推优情况
	void releaseinfo();     //发布通知

	int privillagetype = 0;  //0=党支部 1=团支部
private:
	void viewfunc();
};

struct indexs   //索引用的数据类型
{
	std::string name;
	student* pointer;
};
struct indexsm   //索引用的数据类型
{
	std::string name;
	manager* pointer;
};

struct savedatastudent
{
	std::string name;
	std::string applydate;     //申请日期
	int type = 0;  //0=群众 1=共青团员 2=入党积极分子 3=预备党员
	std::string votecondition; //推优情况
	bool status = 0;  //0=通常 1=申请成为共产党员 2=新申请 3=申请通过 4=申请不通过
};

struct savedatamanager
{
	std::string name;
	int privillagetype = 0;  //0=党支部 1=团支部
};