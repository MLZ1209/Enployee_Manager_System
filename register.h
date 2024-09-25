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
		cout << "���ļ�ʧ��" << endl;
	}
	ofs.close();
	}
	~User() {}
	bool regid();
	bool sign();
};
bool User::regid()
{
	//���ļ�----------------------�ȶ��ظ��û���
	ifstream ifs("E:\\register_table", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ��𻵻��쳣!!!" << endl;
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
			cout << "�û����ظ���" << endl;
			Sleep(1000);
			return false;
		}
	}
	ifs.close();
	//д�ļ�   -----------------
	ofstream ofs("E:\\register_table", ios::app);
	if (!ofs.is_open() )
	{
		cout << "�ļ��𻵻��쳣!!!" << endl;
		Sleep(3);
	}
	ofs<<this->username + ' ' + this->userpwd<<endl;
	ofs.close();
	cout << "ע��ɹ�������" << endl;
	Sleep(1000);
	return true;
}
bool User::sign()
{

	ifstream ifs("E:\\register_table", ios::in);
	if (ifs.is_open() == false)
	{
		cout << "�ļ��𻵻��쳣!" << endl;
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
