#pragma once
#include<iostream>
#include<string>
using namespace std;
class Exceptinon:public exception
{
public:
	void messegErrorFile(string name)
	{
		cout << "������ �������� ����� - '" << name << "'" << endl;
	}
};
