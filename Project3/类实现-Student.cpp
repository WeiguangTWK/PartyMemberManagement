#include"类声明.h"
#include"全局变量存储区.h"
#include"文件存取操作.h"
#include"disp.h"
using namespace std;


//=========================================建立索引===========================================
student::student(string n) :name(n)
{
	indexs a;
	a.name = n;
	a.pointer = this;
	students.push_back(a); 
	if (isdebug)cout << "new student obj create name " << a.name << " level " << a.pointer->type << endl;
}
//============================================================================================

void student::viewfunc() //查看
{
	dispstudent(this);
	system("pause");
}

void student::applyaction()
{
	cout << "入党须知：" << endl;
	cout << "1.争取入党是中华民族优秀儿女的自觉要求" << endl;
	cout << "2.要承认党纲和党章，了解党的基本知识" << endl;
	cout << "3.共产党员要为实现共产主义奋斗终身" << endl;
	cout << "4.共产党员要高举中国特色社会主义的伟大旗帜" << endl;
	cout << "5.认真学习马克思列宁主义、毛泽东思想" << endl;
	cout << "6.认真学习中国特色社会主义理论体系" << endl;
	cout << "7.为构建社会主义和谐社会添砖加瓦" << endl;
	cout << "8.共产党员要争做社会主义建设的模范" << endl;
	cout << "9.胸怀理想，立足现实，贯彻执行党的基本路线和各项方针政策" << endl;
	cout << "10.坚持党和人民的利益高于一切" << endl << endl;
	cout << "阅读完成后选择是否提交（Y/N）:";
	char userinp;
	cin >> userinp;
	if (userinp == 'Y' || userinp == 'y')
	{
		this->status = 2;
		string applydate;
		cout << "输入今日日期（格式：年/月/日）：";
		cin >> applydate;
		save();
		cout << "您的申请已记录在案，请在数日内前往党支部递交入党申请书，随后您可以通过此系统查询入党进度" << endl;
	}
	else
	{
		cout << "您取消了申请" << endl;
	}
}
