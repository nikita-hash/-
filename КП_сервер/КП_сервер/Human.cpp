#include "Human.h"

Human::Human()
{
	cash = 0;
	contribution = 0;
}

Human::Human(int a)
{
}

void Human::setName(char* nam)
{
	strcpy_s(name,sizeof(name),nam);
}

void Human::setTel(char* tel)
{
	strcpy_s(this->tel, sizeof(this->tel), tel);
}

void Human::setPass_info(char* info)
{
	strcpy_s(this->pas_indo, sizeof(pas_indo), info);
}

void Human::setPassword(char* pass)
{
	strcpy_s(this->password, 100, pass);
}

void Human::setLogin(char* log)
{
	strcpy_s(this->login, 100, log);
}

void Human::setCasg(float s)
{
	cash = s;
}

void Human::setContibution(int i)
{
	contribution = i;
}

float Human::getCash()
{
	return cash;
}

int Human::getContribution()
{
	return contribution;
}

char* Human::getName()
{
	return name;
}

char* Human::getTel()
{
	return tel;
}

char* Human::getPas_info()
{
	return pas_indo;
}

char* Human::getlogin()
{
	return login;
}

char* Human::getPassword()
{
	return password;
}

ostream& operator<<(ostream& os, Human& obj)
{
	os << "\t" << obj.getName() << "\t" << obj.getTel() << "\t" << obj.getPas_info() << "\t" << obj.getlogin() << "\t" << obj.getPassword() << obj.getCash() << "\t" << obj.getContribution() << endl;
	return os;
}

istream& operator>>(istream& os, Human& obj)
{
	os >> obj.name >> obj.tel >> obj.pas_indo >> obj.login >> obj.password >> obj.cash >> obj.contribution;
	return os;
}
