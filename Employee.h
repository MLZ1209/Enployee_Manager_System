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
			cout << "���û��Ѿ�ע���������" << endl;
			return;
		}
	}
	ifs.close();
	ofs << id << " " << name << " " << Pid << endl;
	ofs.close();
	cout << "ְ����ӳɹ�!!!" << endl;
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
			cout << "ȷ��Ҫɾ����" << tempstring <<"��"<< endl;
			flag = 1;
			if (getchar() == 'y') continue;
		}
		l.push_back(tempstring);
	}
	if (!flag)
	{
		cout << "�Բ���û��ƥ����Ա������" << endl;
	
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
	cout << "�޸���ɣ�����" << endl;
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
		cout << "�ļ���ʧ��!!!11" << endl;
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
			cout << "ȷ��Ҫ�޸���"<<endl;
			if (getchar() == 'y')
			{
				cout << "�������޸ĺ��Ա����ţ�";
				cin >> tid;
				cout << "\n�������޸ĺ��Ա������:";
				cin >> tname;
				cout << "\n�������޸ĺ��Ա�����ű��:";
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
		cout << "�ļ���ʧ��!!!" << endl;
		Sleep(3000);
		return;
	}
	for (vector<string>::iterator it = ll.begin(); it != ll.end(); it++)
	{
		ofs << *it << endl;
	}
	ofs.close();
	cout << "��Ϣ�޸ĳɹ�!!!" << endl;
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
		cout << "�ļ���ʧ��!!!" << endl;
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
	cout << "   ���        ����       ���ű��     " << endl;
	for_each(ll.begin(), ll.end(), print);
	Sleep(3000);
	return;
}
void employee::ClearFile()
{
	cout << "ȷ������ĵ���?(y/n):";
	if (getchar() == 'y')
	{
		ofstream ofs("E:\\employee_info", ios::out);
		if (!ofs.is_open())
		{
			cout << "���ļ�ʧ��!!!" << endl;
			Sleep(2000);
			return;
		}
		cout << "�ĵ������!!!" << endl;
		Sleep(2000);
		return;
	}
	cout << "��ȡ��" << endl;
	Sleep(2000);
	return;
}