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
	cout << "�û���:";
	cin >> this->name;
	cout << "\n����:";
	cin >> this->pwd;
	User p(name, pwd);
	
	bool result;
	if (n == 2)
	{
		cout << "ע��";
		result = p.regid();
	}
	else
	{
		cout << "��¼" << endl;
		result = p.sign();
		if (result == false)
		{
			cout << "�û������������!!!" << endl;
			Sleep(500);
		}
	}
	return result;
}
