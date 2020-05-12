#pragma once
#include<iostream>
#include<iomanip>
#include"Server.h"
#include"Menu.h"
using namespace std;
void check_imput(int i);
void printf_money(Server& obj);
void replenish_promised_payment(Server& obj);
void Replenish_account(Server& obj);
void addReiting(Server& obj);
void addForecast(Server& obj);
void addClient(Server& obj);
void addAdmin(Server& obj);
void addExpert(Server& obj);
void AutorizationUser(Server& obj);
void AutorizationAdmin(Server& obj);
void AutorizationExpert(Server& obj);
void PrintfUserInfo(Server& obj);
void PrintfAdminInfo(Server& obj);
void PrintfExpertInfo(Server& obj);
void Printf_debtor(Server& obj);
void PrintfBet(Server& obj);
void DelClient(Server& obj);
void DelAdmin(Server& obj);
void DelExpert(Server& obj);
void findBids(Server& obj);
void findClient(Server& obj);
void findAdmin(Server& obj);
void findExpert(Server& obj);//
void ExpertOpinion(Server& obj);