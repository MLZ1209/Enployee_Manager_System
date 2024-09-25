#pragma once
#include<iostream>
#include<string>
#include "register.h"

using namespace std;


class interface1
{
private:
	string name;
	string pwd;

public:
	interface1() {}
	bool face(short);
};

bool interface1::face(short n)
{
	system("cls");
	cout << "用户名:";
	cin >> this->name;
	cout << "\n密码:";
	cin >> this->pwd;
	User p(name, pwd);
	
	bool result;
	if (n == 2)
	{
		cout << "注册";
		result = p.regid();
	}
	else
	{
		cout << "登录" << endl;
		result = p.sign();
		if (result == false)
		{
			cout << "用户名或密码错误!!!" << endl;
			Sleep(500);
		}
	}
	return result;
}
