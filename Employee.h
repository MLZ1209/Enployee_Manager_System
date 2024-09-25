#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<Windows.h>
#include<vector>
#include<algorithm>
using namespace std;
class employee
{
private:
	string id;
	string name;
	string Pid;
public:
	employee() {}
	employee(const string tid , const string tname , const string tpid)
	{
		id = tid;
		name = tname;
		Pid = tpid;
		//cout << Pid << " " << tpid << endl;
	}
	void AddUser(const string id, const string name, const string Pid);
	void DelUser(const string id);
	void DisplayUser();
	void AlterUser(const string id);
	//void Findinfo();
	void SortUser(int n);
	void ClearFile();
	friend void print(const employee a);
};
void employee::AddUser(const string id, const string name, const string Pid)
{

	ofstream ofs("E:\\employee_info", ios::app);
	ifstream ifs("E:\\employee_info", ios::in);
	string tempstring;
	int pos;
	while(getline(ifs, tempstring))
	{
		pos = tempstring.find(' ');
		string tid = tempstring.substr(0 , pos);
		if (id == tid)
		{
			cout << "该用户已经注册过！！！" << endl;
			return;
		}
	}
	ifs.close();
	ofs << id << " " << name << " " << Pid << endl;
	ofs.close();
	cout << "职工添加成功!!!" << endl;
	Sleep(3000);
	return;
}
void employee::DelUser(const string id)
{
	int pos ,flag=0;
	fstream file("E:\\employee_info");
	string tid , tempstring;
	vector<string> l;
	while (getline(file, tempstring))
	{
		pos = tempstring.find(' ');
		tid = tempstring.substr(0, pos);
		if (id == tid)
		{
			cout << "确定要删除：" << tempstring <<"吗？"<< endl;
			flag = 1;
			if (getchar() == 'y') continue;
		}
		l.push_back(tempstring);
	}
	if (!flag)
	{
		cout << "对不起，没有匹配人员！！！" << endl;
	
		file.close();
		Sleep(3000);
		return;
	}
	file.close();
	ofstream ofs("E:\\employee_info" , ios::out);
	for (vector<string>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << endl;
		ofs << *it << endl;
	}
	ofs.close();
	cout << "修改完成！！！" << endl;
	Sleep(3000);
	return;
}
void employee::DisplayUser()
{
	ifstream ifs("E:\\employee_info", ios::in);
	string temp;
	while (getline(ifs, temp))
	{
		cout << temp << endl;
	}
	Sleep(3000);
	return;
}
void employee::AlterUser(const string id)
{
	fstream file("E:\\employee_info");
	if (!file.is_open())
	{
		cout << "文件打开失败!!!11" << endl;
		Sleep(3000);
		return;
	}
	string tempstring;
	vector<string> ll;
	string pid , tid , tname ,tpid;

	int pos;
	while (getline(file, tempstring))
	{
		pos = tempstring.find(' ');
		pid = tempstring.substr(0, pos);
		if (pid == id)
		{
			cout << "确定要修改吗？"<<endl;
			if (getchar() == 'y')
			{
				cout << "请输入修改后的员工编号：";
				cin >> tid;
				cout << "\n请输入修改后的员工名字:";
				cin >> tname;
				cout << "\n请输入修改后的员工部门编号:";
				cin >> tpid;
				tempstring = tid + ' ' + tname + ' ' + tpid;
			}
			else
			{
				return;
			}
		}
		ll.push_back(tempstring);
	}
	file.close();
	ofstream ofs("E:\\employee_info", ios::out);
	if (!ofs.is_open())
	{
		cout << "文件打开失败!!!" << endl;
		Sleep(3000);
		return;
	}
	for (vector<string>::iterator it = ll.begin(); it != ll.end(); it++)
	{
		ofs << *it << endl;
	}
	ofs.close();
	cout << "信息修改成功!!!" << endl;
	Sleep(3000);
	return;
}
void print(const employee a)
{
	cout << a.id <<"  " << a.name <<"  " << a.Pid << endl;
}
void employee::SortUser(int n)
{
	ifstream ifs("E:\\employee_info", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败!!!" << endl;
		Sleep(2000);
		return;
	}
	string tempstring  , tid , tname , tpid;
	vector<employee> ll;
	int pos1, pos2;
	while (getline(ifs, tempstring))
	{
		pos1 = tempstring.find_first_of(' ');
		pos2 = tempstring.find_last_of(' ');
		tid = tempstring.substr(0, pos1);
		tname = tempstring.substr(pos1+1,pos2-pos1);
		tpid = tempstring.substr(pos2+1, tempstring.length()-pos2);
		employee l(tid, tname, tpid);
		cout <<tempstring.length() << endl;
		ll.push_back(l);
	}
	ifs.close();
	sort(ll.begin(), ll.end(), [](const employee a, const employee b) {return a.id < b.id; });
	cout << "   编号        姓名       部门编号     " << endl;
	for_each(ll.begin(), ll.end(), print);
	Sleep(3000);
	return;
}
void employee::ClearFile()
{
	cout << "确定清空文档吗?(y/n):";
	if (getchar() == 'y')
	{
		ofstream ofs("E:\\employee_info", ios::out);
		if (!ofs.is_open())
		{
			cout << "打开文件失败!!!" << endl;
			Sleep(2000);
			return;
		}
		cout << "文档已清空!!!" << endl;
		Sleep(2000);
		return;
	}
	cout << "已取消" << endl;
	Sleep(2000);
	return;
}