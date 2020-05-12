#include "BIds.h"

void BIds::setNameExpert(char* name)
{
	strcpy_s(nameExpert, sizeof(nameExpert), name);
}

void BIds::setLoginExpert(char* login)
{
	strcpy_s(loginExpert, sizeof(loginExpert), login);
}

char* BIds::getLoginExpert()
{
	return loginExpert;
}

char* BIds::getNameExpert()
{
	return nameExpert;
}

void BIds::setFirstNamefootbalTeam(char* name)
{
	strcpy_s(firstNamefootbalTeam, sizeof(firstNamefootbalTeam), name);
}

void BIds::setSecondNamefootbalTeam(char* name)
{
	strcpy_s(secondNamefootbalTeam, sizeof(secondNamefootbalTeam), name);
}

void BIds::setFirstcoefficient(float cof)
{
	firstcoefficient = cof;
}

void BIds::setSecondcofficient(float cof)
{
	secondcofficient = cof;
}

void BIds::setfirstPrecent(int precent)
{
	percentWinfirst = precent;
}

void BIds::setSecondPrecent(int precent)
{
	precentWinsecond = precent;
}

char* BIds::getFirstNamefootbalTeam()
{
	return firstNamefootbalTeam;
}

char* BIds::getSecondNamefootbalTeam()
{
	return secondNamefootbalTeam;
}

float BIds::getFirstcofficient()
{
	return firstcoefficient;
}

float BIds::getSecondcofficient()
{
	return secondcofficient;
}

int BIds::getpercentWinfirst()
{
	return percentWinfirst;
}

int BIds::getprecentWinsecond()
{
	return precentWinsecond;
}

istream& operator>>(istream& os, BIds& obj)
{
	os >> obj.firstNamefootbalTeam >> obj.secondNamefootbalTeam >> obj.firstcoefficient >> obj.secondcofficient >> obj.percentWinfirst >> obj.precentWinsecond >> obj.nameExpert >> obj.loginExpert;
	return os;
}
