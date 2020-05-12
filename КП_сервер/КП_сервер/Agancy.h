#pragma once
#include<iostream>
#include<iomanip>
#include"Human.h"
#include"Bids.h"
using namespace std;
class Agancy:public Human ,public BIds
{
	char date[100];
	double cash1;
public:
	void setDate(char* a);
	void serCash(float a);
	char* getDate();
	float getCahs1();
	friend ostream& operator<<(ostream& os, Agancy& obj);
	friend istream& operator>>(istream& os, Agancy& obj);
};
