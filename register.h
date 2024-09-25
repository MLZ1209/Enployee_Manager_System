#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include <windows.h>
using namespace std;
class User
{
private:
	string username;
	string userpwd;
public:
	User(string name, string pwd) :username(name), userpwd(pwd) 
	{
	ofstream ofs("E:\\register_table", ios::app);
	if (!ofs.is_open())
	{
		cout << "打开文件失败" << endl;
	}
	ofs.close();
	}
	~User() {}
	bool regid();
	bool sign();
};
bool User::regid()
{
	//读文件----------------------比对重复用户名
	ifstream ifs("E:\\register_table", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件损坏或异常!!!" << endl;
		Sleep(3);
		return false;
	}
	int position;
	string tempstring , temp;
	while (getline(ifs, tempstring))
	{
		position = tempstring.find(' ');
		temp = tempstring.substr(0, position);
		if (temp == this->username)
		{
			cout << "用户名重复！" << endl;
			Sleep(1000);
			return false;
		}
	}
	ifs.close();
	//写文件   -----------------
	ofstream ofs("E:\\register_table", ios::app);
	if (!ofs.is_open() )
	{
		cout << "文件损坏或异常!!!" << endl;
		Sleep(3);
	}
	ofs<<this->username + ' ' + this->userpwd<<endl;
	ofs.close();
	cout << "注册成功！！！" << endl;
	Sleep(1000);
	return true;
}
bool User::sign()
{

	ifstream ifs("E:\\register_table", ios::in);
	if (ifs.is_open() == false)
	{
		cout << "文件损坏或异常!" << endl;
		return false;
	}
	short flag = 0;
	string tempstring,sumstring = this->username+" "+this->userpwd;
	while (getline(ifs, tempstring))
	{
		if (tempstring == sumstring)
		{
			return true;
		}
	}
	return false;
}
