#include<iostream>
#include "interface.h"
#include"Employee.h"
using namespace std;

int mune2()
{
	short item;
	std::cout << "1������Ա����Ϣ;" << std::endl<<"2����ʾԱ����Ϣ;"<<
		std::endl<<"3��ɾ��Ա����Ϣ"<<std::endl<<"4���޸���Ա����Ϣ"<<std::endl<<
		"5������Ա����Ϣ"<<std::endl<<"6�����ձ������\n"<<"7������ĵ���Ϣ\n"<<"0���˳�ϵͳ"<<std::endl;
	std::cout << "��ѡ��:";
	std::cin >> item;
	return item;
}
bool mune1()
{
	string name, pwd;
	short select;
	cout << "��ӭ��¼ְ������ϵͳ��\n\n" << endl;
	cout << "1��-------��¼----------\n\n" << endl;
	cout << "2��---------ע��----------\n\n" << endl;
	cout << "��ѡ��:";
	cin >> select;
	if (select > 2 || select < 1)
	{
		cout << "�������!!!"<<endl;
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
	//	cout << "��������Ҫ���ְ�����:"; cin >> tid;
	//	cout << "\n��������Ҫ���ְ������:"; cin >> tname;
	//	cout << "\n��������Ҫ���ְ�����ű��:"; cin >> tpid;
	//	emp.AddUser(tid, tname, tpid); break;
	//case 2:emp.DisplayUser(); break;
	//case 3:cout << "��������Ҫɾ����ְ�����:"; cin >> tid;
	//	emp.DelUser(tid); break;
	//case 4:
	//	cout << "��������Ҫ�޸ĵ�ְ�����:"; cin >> tid;
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