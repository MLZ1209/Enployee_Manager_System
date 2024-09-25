#include<iostream>
#include "interface.h"
#include"Employee.h"
using namespace std;

int mune2()
{
	short item;
	std::cout << "1、增加员工信息;" << std::endl<<"2、显示员工信息;"<<
		std::endl<<"3、删除员工信息"<<std::endl<<"4、修改与员工信息"<<std::endl<<
		"5、查找员工信息"<<std::endl<<"6、按照编号排序\n"<<"7、清空文档信息\n"<<"0、退出系统"<<std::endl;
	std::cout << "请选择:";
	std::cin >> item;
	return item;
}
bool mune1()
{
	string name, pwd;
	short select;
	cout << "欢迎登录职工管理系统！\n\n" << endl;
	cout << "1、-------登录----------\n\n" << endl;
	cout << "2、---------注册----------\n\n" << endl;
	cout << "请选择:";
	cin >> select;
	if (select > 2 || select < 1)
	{
		cout << "输入错误!!!"<<endl;
		return false;
	}
	interface1 itr;
	bool result = itr.face(select);
	if (result)
	{
		return true;
	}
	return false;
}
int  main()
{
	//bool result;
	//do
	//{
	//	result = mune1();
	//	system("cls");
	//} while (!result);
	//employee emp;
	//string tname, tid, tpid;
	//bool flag = true;
	//while(flag)
	//{ 
	//system("cls");
	//short select = mune2();
	//system("cls");
	//switch (select)
	//{
	//case 1:
	//	cout << "请输入你要添加职工编号:"; cin >> tid;
	//	cout << "\n请输入你要添加职工姓名:"; cin >> tname;
	//	cout << "\n请输入你要添加职工部门编号:"; cin >> tpid;
	//	emp.AddUser(tid, tname, tpid); break;
	//case 2:emp.DisplayUser(); break;
	//case 3:cout << "请输入你要删除的职工编号:"; cin >> tid;
	//	emp.DelUser(tid); break;
	//case 4:
	//	cout << "请输入你要修改的职工编号:"; cin >> tid;
	//	emp.AlterUser(tid); break;
	//case 5://emp.Findinfo(); 
	//	break;
	//case 6:
	//	emp.SortUser(1); break;
	//case 7:emp.ClearFile(); break;
	//default:flag = false;
	//	break;
	//}
	//}
	employee emp;
	emp.SortUser(1);
	return 0;
}