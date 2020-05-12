#pragma once
#include<iostream>
#include<iomanip>
using namespace std;
class BIds
{
protected:
	char loginExpert[100];
	char nameExpert[100];
	char firstNamefootbalTeam[100];
	char secondNamefootbalTeam[100];
	float firstcoefficient;
	float secondcofficient;
	int percentWinfirst;
	int precentWinsecond;
public:
	void setNameExpert(char* name);
	void setLoginExpert(char* login);
	char* getLoginExpert();
	char* getNameExpert();
	void setFirstNamefootbalTeam(char* name);
	void setSecondNamefootbalTeam(char* name);
	void setFirstcoefficient(float cof);
	void setSecondcofficient(float cof);
	void setfirstPrecent(int precent);
	void setSecondPrecent(int precent);
	char* getFirstNamefootbalTeam();
	char* getSecondNamefootbalTeam();
	float getFirstcofficient();
	float getSecondcofficient();
	int getpercentWinfirst();
	int getprecentWinsecond();
	friend istream& operator>>(istream& os, BIds& obj);

};
