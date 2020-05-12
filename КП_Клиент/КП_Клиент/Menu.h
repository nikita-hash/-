#pragma once
#include"Server.h"
#include"Function.h"
class Menu
{
	void CheckImputSwitch(int check);
	void displayUser(Server&obj);
	void displayExpert(Server& obj);
	void MenuBet(Server& obj);
	void MenuChangeUser(Server& obj);
	void MenuChangeExpert(Server& obj);
public:
	void startMenu(Server& Connection);
	void MenuUser(Server& Connection);
	void MenuAdmin(Server& Connection);
	void MenuExpert(Server& Connection);
};
