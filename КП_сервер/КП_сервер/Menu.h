#pragma once
#include"Server.h"
#include"User.h"
#include"FileCreator.h"
class Menu:public User
{
	void Menucheck(int i,Server &obj);
	void AdminMenu(Server& obj);
	void UserMenu(Server& obj, int i, User& user);
	void ExpertMenu(Server& obj, int i, User& user);
	void MenuBet(Server& obj, User& user);
	void MenuChangeUser(Server& obj, int i, User& user);
	void MenuChangeExpert(Server& obj, int i, User& user);
public:
	Menu();
	void startMenu(Server &obj);
	
};
