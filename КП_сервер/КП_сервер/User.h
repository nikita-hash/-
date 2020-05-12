#pragma once
#include"Human.h"
#include"Bids.h"
#include"Server.h"
#include"Agancy.h"
#include"Rating.h"
#include<vector>
#include"FileCreator.h"
class User
{
protected:
	vector<Rating>vecReiting;
	vector<Agancy>vecAgancy;
	vector<Human>vecHuman;
	vector<Human>vecAdmin;
	vector<Human>vecExpert;
	vector<BIds>vecBids;
public:
	User();
	void print_Money(Server& obj, int i);
	void replenish_promised_payment(Server& obj, int i);
	void promised_payment(Server& obj, int i);
	void assessmentExpert(Server& obj, int i);
	void replenish(Server& obj,int i);
	void receptionExpert(int i, Server& obj);
	void reception(int i,Server &obj);
	void Make_bet(Server& obj,int checkHuman);
	int AutorizationAdmin(Server& obj);
	int AutorizationClient(Server& obj);
	int AutorizationExpert(Server& obj);
	void addRating(Server& obj, int checkExpert);
	void addBids(Server& obj,int i);
	void addClient(Server& obj);
	void addAdmin(Server& obj);
	void addExpert(Server& obj);
	void delClient(Server& obj);
	void delAdmin(Server& obj);
	void delExpert(Server& obj);
	void findBids(Server& obj);
	void findUser(Server& obj);
	void findAdmin(Server& obj);
	void findExpert(Server& obj);
	void printf_infoBet(Server& obj);
	void printf_infoClient(Server& obj);
	void printf_infoAdmin(Server& obj);
	void printf_infoExpert(Server& obj);
	void save_info_bids();
	void seve_info_Client();
	void save_info_Admin();
	void save_info_Expert();
	void save_info_rating();
	
	//void save_info_Agancy();
	~User();
};
