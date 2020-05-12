#include "Agancy.h"

ostream& operator<<(ostream& os, Agancy& obj)
{
	os << "###############################################################################" << endl;
	os<< "Дата оформления ставки :" << obj.getDate() << endl;
	os << "Имя пользователя : " << obj.getName() << endl;
	os << "Паспортный номер польщователя : " << obj.getPas_info() << endl;
	os << "Номер телефона пользователя : " << obj.getTel() << endl;
	os << obj.getFirstNamefootbalTeam() << setw(39) << obj.getSecondNamefootbalTeam() << endl;
	os << "Коэфициент:" << obj.getFirstcofficient() << setw(37) << "Коэфициент:" << obj.getSecondcofficient() << endl;
	os << "Размер ставки : " << obj.getCahs1() << endl;
	return os;
}

istream& operator>>(istream& os, Agancy& obj)
{
	os >> obj.date >> obj.name >> obj.pas_indo >> obj.tel >> obj.login >> obj.firstNamefootbalTeam >> obj.firstcoefficient >> obj.percentWinfirst >> obj.secondNamefootbalTeam >> obj.secondcofficient >> obj.precentWinsecond >> obj.cash1;
	return os;
}

void Agancy::setDate(char* a)
{
	strcpy_s(date, sizeof(date), a);
}

void Agancy::serCash(float a)
{
	cash1 = a;
}

char* Agancy::getDate()
{
	return date;
}

float Agancy::getCahs1()
{
	return cash1;
}
