#pragma once
#include<iostream>
#include<iomanip>
using namespace std;
class Rating
{
	int rating;
	char nameExpert[100];
	int positionGaMe;
public:
	void setRating(int a)
	{
		rating = a;
	}
	void setNamExpert(char* a)
	{
		strcpy_s(nameExpert, sizeof(nameExpert),a);
	}
	void setPositionGame(int a) { positionGaMe = a; }
	int getRating() { return rating; }
	int getPosition() { return positionGaMe; }
	char* getNameExpert(){ return nameExpert; }
	friend istream& operator>>(istream&os,Rating &obj)
	{
		os >> obj.rating >> obj.nameExpert >> obj.positionGaMe;
		return os;
	}
};
