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
	void applyaction();        //�����뵳

	std::string name;
	std::string applydate="none";     //��������
	int type = 0;  //0=Ⱥ�� 1=������Ա 2=�뵳�������� 3=Ԥ����Ա
	std::string votecondition="none"; //�������
	int status = 0;  //0=ͨ�� 1=�����Ϊ������Ա 2=������ 3=����ͨ�� 4=���벻ͨ��
	void viewfunc();
};

class manager
{
public:
	manager(std::string n, int priv);
	std::string name;
	void addrecord(); //��
	void delrecord(); //ɾ
	void editrecord(); //��
	void searchrecord(); //��

	void getvotecond();   //��ȡ�������
	void judgeapplication();  //�ж�ת��

	void votecondrecadd();  //¼���������
	void releaseinfo();     //����֪ͨ

	int privillagetype = 0;  //0=��֧�� 1=��֧��
private:
	void viewfunc();
};

struct indexs   //�����õ���������
{
	std::string name;
	student* pointer;
};
struct indexsm   //�����õ���������
{
	std::string name;
	manager* pointer;
};

struct savedatastudent
{
	std::string name;
	std::string applydate;     //��������
	int type = 0;  //0=Ⱥ�� 1=������Ա 2=�뵳�������� 3=Ԥ����Ա
	std::string votecondition; //�������
	bool status = 0;  //0=ͨ�� 1=�����Ϊ������Ա 2=������ 3=����ͨ�� 4=���벻ͨ��
};

struct savedatamanager
{
	std::string name;
	int privillagetype = 0;  //0=��֧�� 1=��֧��
};