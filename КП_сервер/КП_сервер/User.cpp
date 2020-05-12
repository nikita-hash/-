#include "User.h"

User::User()
{
	FileCreator obj;
	obj.read_vector(vecHuman, FileClient);
	obj.read_vector(vecAdmin, FileAdmin);
	obj.read_vector(vecBids, FileBids);
	obj.read_vector(vecExpert, FileExpert);
	obj.read_vector(vecReiting, FileReiting);
	//obj.read_vector_Agency(vecAgancy);
}

void User::print_Money(Server& obj, int i)
{
	int sum;
	char buf[100];
	recv(obj.GetNewConnection(), buf, sizeof(buf), 0);
	sum = atoi(buf);
	if(vecHuman[i].getCash()<sum)
	{
		int check = 1;
		char msg[100];
		itoa(check, msg, 10);
		send(obj.GetNewConnection(), msg, sizeof(msg), 0);
	}
	else
	{
		int check = 2;
		char msg[100];
		itoa(check, msg, 10);
		send(obj.GetNewConnection(), msg, sizeof(msg), 0);
		int rez = vecHuman[i].getCash() - sum;
		vecHuman[i].setCasg(vecHuman[i].getCash() - sum);
		itoa(rez, msg, 10);
		send(obj.GetNewConnection(), msg, sizeof(msg), 0);
		seve_info_Client();
		cout << "User = " << vecHuman[i].getlogin() << " Снял со счета  = " << sum << " остаток на счете = " << rez << endl;
	}
}

void User::replenish_promised_payment(Server& obj, int i)
{
	int pay;
	char payment[100];
	pay=vecHuman[i].getContribution();
	itoa(pay, payment, 10);
	send(obj.GetNewConnection(), payment, sizeof(payment), 0);
	int sum;
	char buf[100];
	recv(obj.GetNewConnection(), buf, sizeof(buf), 0);
	sum = atoi(buf);
	if(vecHuman[i].getCash()<sum)
	{
		int check = 0;
		char msg[100];
		itoa(check, msg, 10);
		send(obj.GetNewConnection(), msg, sizeof(msg), 0);
	}
	else
	{
	if(vecHuman[i].getContribution()<sum)
	{
		int check = 1;
		char msg[100];
		itoa(check, msg, 10);
		send(obj.GetNewConnection(), msg, sizeof(msg), 0);
		int rezault = sum - vecHuman[i].getContribution();
		vecHuman[i].setCasg(vecHuman[i].getCash() - sum);
		vecHuman[i].setContibution(0);
		vecHuman[i].setCasg(rezault + vecHuman[i].getCash());
		char buf2[100];
		itoa(rezault, buf2, 10);
		send(obj.GetNewConnection(), buf2, sizeof(buf2), 0);
		seve_info_Client();
		cout << "User = " << vecHuman[i].getlogin() << " Внес полату по платежу . Остаток составил = " << vecHuman[i].getContribution() << endl;
	}
	else
	{
		int check = 2;
		char msg[100];
		itoa(check, msg, 10);
		send(obj.GetNewConnection(), msg, sizeof(msg), 0);
		int rezault = vecHuman[i].getContribution() - sum;
		vecHuman[i].setCasg(vecHuman[i].getCash() - sum);
		vecHuman[i].setContibution(vecHuman[i].getContribution()-sum);
		char buf2[100];
		itoa(rezault, buf2, 10);
		send(obj.GetNewConnection(), buf2, sizeof(buf2), 0);
		seve_info_Client();
		cout << "User = " << vecHuman[i].getlogin() << " Внес полату по платежу . Остаток составил = " << vecHuman[i].getContribution() << endl;
	}
	}
}

void User::promised_payment(Server& obj, int i)
{
	int  sum;
	char buf[100];
	recv(obj.GetNewConnection(), buf, sizeof(buf), 0);
	sum = atoi(buf);
	vecHuman[i].setContibution(sum + vecHuman[i].getContribution());
	seve_info_Client();
	cout << vecHuman[i].getlogin() << "- взял обещанный платеж на сумму = " << sum << endl;
}


void User::assessmentExpert(Server& obj, int i)
{
	int cof = 0;
	char nameExpert[100];
	float rang[100][100];
	if(vecReiting.size()==0 && vecBids.size()==0)
	{
		int ch = 1;
		char buf[100];
		itoa(ch, buf, 10);
		send(obj.GetNewConnection(), buf, sizeof(buf), 0);

	}
	/*if(vecReiting.size()%10==0)
	{
		int ch = 2;
		char buf[100];
		itoa(ch, buf, 10);
		send(obj.GetNewConnection(), buf, sizeof(buf), 0);

	}*/
	else
	{

		int ch = 0;
		char buf[100];
		send(obj.GetNewConnection(), buf, sizeof(buf), 0);
		Rating temp;
		for (int i = 0; i < vecReiting.size() - 1; i++)
		{
			for (int j = 0; j < vecReiting.size() - i - 1; j++)
			{
				if (vecReiting[j].getPosition() > vecReiting[j + 1].getPosition())
				{
					temp = vecReiting[j];
					vecReiting[j] = vecReiting[j + 1];
					vecReiting[j + 1] = temp;
				}
			}
		}

		float rang[100][100];
		int pet = 0;
		for (int i = 0; i < vecReiting.size()/2 ; i++)
		{
			for (int j = 0; j < vecBids.size(); j++)
			{
				if(pet==vecReiting.size())
				{
					break;
				}
				rang[i][j] = vecReiting[pet].getRating();
				pet++;
			}
		}

		for (int i = 0; i < vecReiting.size() / 2; i++)
		{
			cout << endl;
			for (int j = 0; j < vecBids.size(); j++)
			{
				cout << rang[i][j];
			}
		}
		cout << endl;

		int masCof[100];
		for (int i = 0; i < vecReiting.size() / 2; i++)
		{
			int cof = 0;
			for (int j = 0; j < vecBids.size(); j++)
			{
				cof = rang[i][j] + cof;
			}
			cout << "kof - " << cof << endl;
			masCof[i] = cof;
		}
		float masAge[100];

		for (int i = 0; i < vecReiting.size() / 2; i++)
		{
			float age = 0;
			for (int j = 0; j < vecBids.size(); j++)
			{
				float ag = rang[i][j] / masCof[j];
				age = age + ag;
			}
			age = age / (vecReiting.size() / 2);
			cout << "age - " << age << endl;
			masAge[i] = age;
		}
		int check=0;
		float iterator;
		iterator = masAge[0];
		for (int i = 0; i < vecReiting.size() / 2; i++)
		{
			if (iterator < masAge[i])
			{
				iterator = masAge[i];
				check = i;
			}
		}
		char name1[100], name2[100], login[100], name[100], bufcof1[100], bufcof2[100], bufproc1[100], bufproc2[100];
			float cof1, cof2;
			int procent1, procent2;
			strcpy_s(name1, sizeof(name1), vecBids[check].getFirstNamefootbalTeam());
			send(obj.GetNewConnection(), name1, sizeof(name1), 0);
			cof1 = vecBids[check].getFirstcofficient();
			itoa(cof1, bufcof1, 10);
			send(obj.GetNewConnection(), bufcof1, sizeof(bufcof1), 0);
			procent1 = vecBids[check].getpercentWinfirst();
			itoa(procent1, bufproc1, 10);
			send(obj.GetNewConnection(), bufproc1, sizeof(bufproc1), 0);
			strcpy_s(name2, sizeof(name2), vecBids[check].getSecondNamefootbalTeam());
			send(obj.GetNewConnection(), name2, sizeof(name2), 0);
			cof2 = vecBids[check].getSecondcofficient();
			itoa(cof2, bufcof2, 10);
			send(obj.GetNewConnection(), bufcof2, sizeof(bufcof2), 0);
			procent2 = vecBids[check].getprecentWinsecond();
			itoa(procent2, bufproc2, 10);
			send(obj.GetNewConnection(), bufproc2, sizeof(bufproc2), 0);

		

	}
}

void User::replenish(Server& obj,int i)
{
	float sum;
	char buf[100];
	recv(obj.GetNewConnection(), buf, sizeof(buf), 0);
	sum = atoi(buf);
	vecHuman[i].setCasg(sum+vecHuman[i].getCash());
	seve_info_Client();
	cout << vecHuman[i].getlogin() << "- пополнил счет на счет на сумму = " << sum << endl;

}

void User::receptionExpert(int i, Server& obj)
{
	char name[100], tel[100], pas_info[100], login[100], password[100];
	strcpy_s(name, sizeof(name), vecExpert[i].getName());
	send(obj.GetNewConnection(), name, sizeof(name), 0);
	strcpy_s(tel, sizeof(tel), vecExpert[i].getTel());
	send(obj.GetNewConnection(), tel, sizeof(tel), 0);
	strcpy_s(pas_info, sizeof(pas_info), vecExpert[i].getPas_info());
	send(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
	strcpy_s(login, sizeof(login), vecExpert[i].getlogin());
	send(obj.GetNewConnection(), login, sizeof(login), 0);
	strcpy_s(password, sizeof(password), vecExpert[i].getPassword());
	send(obj.GetNewConnection(), password, sizeof(password), 0);
	
}

void User::reception(int i,Server&obj)
{
	char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
	float cash;
	strcpy_s(name, sizeof(name), vecHuman[i].getName());
	send(obj.GetNewConnection(), name, sizeof(name), 0);
	strcpy_s(tel, sizeof(tel), vecHuman[i].getTel());
	send(obj.GetNewConnection(), tel, sizeof(tel), 0);
	strcpy_s(pas_info, sizeof(pas_info), vecHuman[i].getPas_info());
	send(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
	strcpy_s(login, sizeof(login), vecHuman[i].getlogin());
	send(obj.GetNewConnection(), login, sizeof(login), 0);
	strcpy_s(password, sizeof(password), vecHuman[i].getPassword());
	send(obj.GetNewConnection(), password, sizeof(password), 0);
	cash = vecHuman[i].getCash();
	itoa(cash, msg, 10);
	send(obj.GetNewConnection(), msg, sizeof(msg), 0);
	int contr = vecHuman[i].getContribution();
	itoa(contr, msg, 10);
	send(obj.GetNewConnection(), msg, sizeof(msg), 0);
}

void User::Make_bet(Server& obj,int checkHuman)
{
	int checkBids;
	float cash;
	char date[100], buf[100], msg[100];
	char firstNamefootbalTeam[100];
	char secondNamefootbalTeam[100];
	float firstcoefficient;
	float secondcofficient;
	int percentWinfirst;
	int precentWinsecond;
	char name[100];
	char tel[100];
	char pas_indo[100];
	char password[100];
	char login[100];
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	checkBids = atoi(msg);
	checkBids = checkBids - 1;
	if(vecBids.size()==0)
	{
		int ch = 0;
		char msg2[100];
		itoa(ch, msg2, 10);
		send(obj.GetNewConnection(), msg2, sizeof(msg2), 0);
	}
	else
	{
		int ch=1;
		char msg2[100];
		itoa(ch, msg2, 10);
		send(obj.GetNewConnection(), msg2, sizeof(msg2), 0);
		Agancy stat;
		recv(obj.GetNewConnection(), date, sizeof(date), 0);
		stat.setDate(date);
		recv(obj.GetNewConnection(), buf, sizeof(buf), 0);
		cash = atoi(buf);
		if (cash > vecHuman[checkHuman].getCash())
		{
				int ck = 2;
				char bus;
				itoa(ck, buf, 10);
				send(obj.GetNewConnection(), buf, sizeof(buf), 0);
		}
		else
		{
			int ck = 5;
			char bus;
			itoa(ck, buf, 10);
			send(obj.GetNewConnection(), buf, sizeof(buf), 0);
			stat.serCash(cash);
			strcpy_s(name, sizeof(name), vecHuman[checkHuman].getName());
			strcpy_s(pas_indo, sizeof(pas_indo), vecHuman[checkHuman].getPas_info());
			strcpy_s(tel, sizeof(tel), vecHuman[checkHuman].getTel());
			strcpy_s(login, sizeof(login), vecHuman[checkHuman].getlogin());
			strcpy_s(firstNamefootbalTeam, sizeof(firstNamefootbalTeam), vecBids[checkBids].getFirstNamefootbalTeam());
			strcpy_s(secondNamefootbalTeam, sizeof(secondNamefootbalTeam), vecBids[checkBids].getSecondNamefootbalTeam());
			firstcoefficient = vecBids[checkBids].getFirstcofficient();
			secondcofficient = vecBids[checkBids].getSecondcofficient();
			percentWinfirst = vecBids[checkBids].getpercentWinfirst();
			precentWinsecond = vecBids[checkBids].getprecentWinsecond();
			vecHuman[checkHuman].setCasg(vecHuman[checkHuman].getCash() - cash);
			stat.setName(name);
			stat.setPass_info(pas_indo);
			stat.setTel(tel);
			stat.setLogin(login);
			stat.setFirstNamefootbalTeam(firstNamefootbalTeam);
			stat.setFirstcoefficient(firstcoefficient);
			stat.setfirstPrecent(percentWinfirst);
			stat.setSecondNamefootbalTeam(secondNamefootbalTeam);
			stat.setSecondcofficient(secondcofficient);
			stat.setSecondPrecent(precentWinsecond);
			ofstream file(FileStatistick, ios::app);
			file << stat;
			seve_info_Client();
			save_info_rating();
			//save_info_Agancy();
			cout << "Была сделана ставка пользователем " << name << endl;
			cout << "На сумму :" << cash << endl;
			cout << "Подробности в файле Report" << endl;
		}
	}
}


int User::AutorizationAdmin(Server& obj)
{
	int check = 0;
	char log[100], pas[100];
	recv(obj.GetNewConnection(), log, sizeof(log), 0);
	recv(obj.GetNewConnection(), pas, sizeof(pas), 0);
	for (int i = 0; i < vecAdmin.size(); i++)
	{
		if (strcmp(vecAdmin[i].getlogin(), log) == 0 && strcmp(vecAdmin[i].getPassword(), pas) == 0)
		{
			char buf[100];
			char name[100];
			check++;
			itoa(check, buf, 10);
			strcpy_s(name, sizeof(name), vecAdmin[i].getName());
			send(obj.GetNewConnection(), buf, sizeof(buf), 0);
			send(obj.GetNewConnection(), name, sizeof(name), 0);
			return i;
		}

	}
	if (check == 0)
	{
		char error[100];
		itoa(check, error, 10);
		send(obj.GetNewConnection(), error, sizeof(error), 0);
		return -1;
	}
}

void User::addClient(Server &obj)
{
	int check = 0;
	char msg[100];
	Human obj1;
			recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
			obj1.setName(msg);
			recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
			obj1.setTel(msg);
			recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
			obj1.setPass_info(msg);
			recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
			obj1.setLogin(msg);
			recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
			obj1.setPassword(msg);
			vecHuman.push_back(obj1);
			cout << "Новый пользователь был зарегестрирован!" << endl;
}

void User::addAdmin(Server& obj)
{
	int check = 0;
	char msg[100];
	Human obj1;
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setName(msg);
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setTel(msg);
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setPass_info(msg);
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setLogin(msg);
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setPassword(msg);
	vecAdmin.push_back(obj1);
	cout << "Новый пользователь был зарегестрирован!" << endl;
}

void User::addExpert(Server& obj)
{
	int check = 0;
	char msg[100];
	Human obj1;
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setName(msg);
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setTel(msg);
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setPass_info(msg);
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setLogin(msg);
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setPassword(msg);
	vecExpert.push_back(obj1);
	cout << "Новый Эксперт был зарегестрирован!" << endl;
}

int User::AutorizationClient(Server& obj)
{
	int check = 0;
	char log[100], pas[100];
	recv(obj.GetNewConnection(), log, sizeof(log), 0);
	recv(obj.GetNewConnection(), pas, sizeof(pas), 0);
	for(int i=0;i<vecHuman.size();i++)
	{
	if(strcmp(vecHuman[i].getlogin(),log)==0 && strcmp(vecHuman[i].getPassword(),pas)==0)
		{
		char buf[100];
		char name[100];
		check++;
		itoa(check, buf, 10);
		strcpy_s(name, sizeof(name), vecHuman[i].getName());
		send(obj.GetNewConnection(), buf, sizeof(buf), 0);
		send(obj.GetNewConnection(), name,sizeof(name), 0);
		return i;
		}
	
	}
	if(check==0)
	{
		char error[100];
		itoa(check, error, 10);
		send(obj.GetNewConnection(), error, sizeof(error), 0);
		return -1;
	}
}

int User::AutorizationExpert(Server& obj)
{
	int check = 0;
	char log[100], pas[100];
	recv(obj.GetNewConnection(), log, sizeof(log), 0);
	recv(obj.GetNewConnection(), pas, sizeof(pas), 0);
	for (int i = 0; i < vecExpert.size(); i++)
	{
		if (strcmp(vecExpert[i].getlogin(), log) == 0 && strcmp(vecExpert[i].getPassword(), pas) == 0)
		{
			char buf[100];
			char name[100];
			check++;
			itoa(check, buf, 10);
			strcpy_s(name, sizeof(name), vecExpert[i].getName());
			send(obj.GetNewConnection(), buf, sizeof(buf), 0);
			send(obj.GetNewConnection(), name, sizeof(name), 0);
			return i;
		}

	}
	if (check == 0)
	{
		char error[100];
		itoa(check, error, 10);
		send(obj.GetNewConnection(), error, sizeof(error), 0);
		return -1;
	}
}

void User::addRating(Server& obj, int checkExpert)
{
	char buf[100], buf2[100], name[100];
	int i, rating;
	printf_infoBet(obj);
	recv(obj.GetNewConnection(), buf, sizeof(buf), 0);
	i = atoi(buf);
	recv(obj.GetNewConnection(), buf2, sizeof(buf2), 0);
	Rating rat;
	rating = atoi(buf2);
	rat.setRating(rating);
	strcpy_s(name, sizeof(name), vecExpert[checkExpert].getName());
	rat.setNamExpert(name);
	rat.setPositionGame(i);
	vecReiting.push_back(rat);
	save_info_rating();
}

void User::addBids(Server& obj,int i)
{
	int check;
	char name1[100], name2[100], login[100], name[100], bufcof1[100], bufcof2[100], bufproc1[100], bufproc2[100], msg[100];
	float cof1, cof2;
	int procent1, procent2;
	BIds bids;
	recv(obj.GetNewConnection(), name1, sizeof(name1), 0);
	bids.setFirstNamefootbalTeam(name1);
	recv(obj.GetNewConnection(), bufcof1, sizeof(bufcof1), 0);
	cof1 = atoi(bufcof1);
	bids.setFirstcoefficient(cof1);
	recv(obj.GetNewConnection(), bufproc1, sizeof(bufproc1), 0);
	procent1 = atoi(bufproc1);
	bids.setfirstPrecent(procent1);
	recv(obj.GetNewConnection(), name2, sizeof(name2), 0);
	bids.setSecondNamefootbalTeam(name2);
	recv(obj.GetNewConnection(), bufcof2, sizeof(bufcof2), 0);
	cof2 = atoi(bufcof2);
	bids.setSecondcofficient(cof2);
	recv(obj.GetNewConnection(), bufproc2, sizeof(bufproc2), 0);
	procent2 = atoi(bufproc2);
	bids.setSecondPrecent(procent2);
	strcpy_s(login, sizeof(login), vecExpert[i].getlogin());
	bids.setLoginExpert(login);
	strcpy_s(name, sizeof(name), vecExpert[i].getName());
	bids.setNameExpert(name);
	vecBids.push_back(bids);
	cout << "Был добавлен прогноз Специалистом : " << name << endl;
	save_info_bids();
}

void User::delClient(Server& obj)
{
	int check = 0;
	char log[100], pas[100];
	recv(obj.GetNewConnection(), log, sizeof(log), 0);
	recv(obj.GetNewConnection(), pas, sizeof(pas), 0);
	for(int i=0;i<vecHuman.size();i++)
	{
		if(strcmp(vecHuman[i].getlogin(),log)==0 && strcmp(vecHuman[i].getPas_info(),pas)==0)
		
		{
		char buf[100];
		check++;
		itoa(check, buf, 10);
		send(obj.GetNewConnection(), buf, sizeof(buf), 0);
		char name[100], tel[100], pas_info[100], login[100], password[100];
		strcpy_s(name, sizeof(name), vecHuman[i].getName());
		send(obj.GetNewConnection(), name, sizeof(name), 0);
		strcpy_s(tel, sizeof(tel), vecHuman[i].getTel());
		send(obj.GetNewConnection(), tel, sizeof(tel), 0);
		strcpy_s(pas_info, sizeof(pas_info), vecHuman[i].getPas_info());
		send(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
		strcpy_s(login, sizeof(login), vecHuman[i].getlogin());
		send(obj.GetNewConnection(), login, sizeof(login), 0);
		strcpy_s(password, sizeof(password), vecHuman[i].getPassword());
		send(obj.GetNewConnection(), password, sizeof(password), 0);
		char msg[100];
		float cash = vecHuman[i].getCash();
		itoa(cash, msg, 10);
		send(obj.GetNewConnection(), msg, sizeof(msg), 0);
		auto res = vecHuman.begin();
		vecHuman.erase(res + i);
		seve_info_Client();
		}
	}
	if (check == 0)
	{
		char error[100];
		itoa(check, error, 10);
		send(obj.GetNewConnection(), error, sizeof(error), 0);
	}
	
}

void User::delAdmin(Server& obj)
{
	int check = 0;
	char log[100], pas[100];
	recv(obj.GetNewConnection(), log, sizeof(log), 0);
	recv(obj.GetNewConnection(), pas, sizeof(pas), 0);
	for (int i = 0; i < vecAdmin.size(); i++)
	{
		if (strcmp(vecAdmin[i].getlogin(), log) == 0 && strcmp(vecAdmin[i].getPas_info(), pas) == 0)

		{
			char buf[100];
			check++;
			itoa(check, buf, 10);
			send(obj.GetNewConnection(), buf, sizeof(buf), 0);
			char name[100], tel[100], pas_info[100], login[100], password[100];
			strcpy_s(name, sizeof(name), vecAdmin[i].getName());
			send(obj.GetNewConnection(), name, sizeof(name), 0);
			strcpy_s(tel, sizeof(tel), vecAdmin[i].getTel());
			send(obj.GetNewConnection(), tel, sizeof(tel), 0);
			strcpy_s(pas_info, sizeof(pas_info), vecAdmin[i].getPas_info());
			send(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
			strcpy_s(login, sizeof(login), vecAdmin[i].getlogin());
			send(obj.GetNewConnection(), login, sizeof(login), 0);
			strcpy_s(password, sizeof(password), vecAdmin[i].getPassword());
			send(obj.GetNewConnection(), password, sizeof(password), 0);
			auto res = vecAdmin.begin();
			vecAdmin.erase(res + i);
			save_info_Admin();
		}
	}
	if (check == 0)
	{
		char error[100];
		itoa(check, error, 10);
		send(obj.GetNewConnection(), error, sizeof(error), 0);
	}
}

void User::delExpert(Server& obj)
{
	int check = 0;
	char log[100], pas[100];
	recv(obj.GetNewConnection(), log, sizeof(log), 0);
	recv(obj.GetNewConnection(), pas, sizeof(pas), 0);
	for (int i = 0; i < vecExpert.size(); i++)
	{
		if (strcmp(vecExpert[i].getlogin(), log) == 0 && strcmp(vecExpert[i].getPas_info(), pas) == 0)

		{
			char buf[100];
			check++;
			itoa(check, buf, 10);
			send(obj.GetNewConnection(), buf, sizeof(buf), 0);
			char name[100], tel[100], pas_info[100], login[100], password[100];
			strcpy_s(name, sizeof(name), vecExpert[i].getName());
			send(obj.GetNewConnection(), name, sizeof(name), 0);
			strcpy_s(tel, sizeof(tel), vecExpert[i].getTel());
			send(obj.GetNewConnection(), tel, sizeof(tel), 0);
			strcpy_s(pas_info, sizeof(pas_info), vecExpert[i].getPas_info());
			send(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
			strcpy_s(login, sizeof(login), vecExpert[i].getlogin());
			send(obj.GetNewConnection(), login, sizeof(login), 0);
			strcpy_s(password, sizeof(password), vecExpert[i].getPassword());
			send(obj.GetNewConnection(), password, sizeof(password), 0);
			auto res = vecExpert.begin();
			vecExpert.erase(res + i);
			save_info_Expert();
		}
	}
	if (check == 0)
	{
		char error[100];
		itoa(check, error, 10);
		send(obj.GetNewConnection(), error, sizeof(error), 0);
	}
}

void User::findBids(Server& obj)
{
	char name1[100], name2[100];
	recv(obj.GetNewConnection(), name1, sizeof(name1), 0);
	recv(obj.GetNewConnection(), name2, sizeof(name2), 0);
	int check = 0;
	for(int i=0;i<vecBids.size();i++)
	{
	if(strcmp(name1,vecBids[i].getFirstNamefootbalTeam())==0 && strcmp(name2,vecBids[i].getSecondNamefootbalTeam())==0)
	{
		
		char name1[100], name2[100], login[100], name[100], bufcof1[100], bufcof2[100], bufproc1[100], bufproc2[100], buf[100];
		float cof1, cof2;
		int procent1, procent2;
		strcpy_s(name1, sizeof(name1), vecBids[i].getFirstNamefootbalTeam());
		send(obj.GetNewConnection(), name1, sizeof(name1), 0);
		cof1 = vecBids[i].getFirstcofficient();
		itoa(cof1, bufcof1, 10);
		send(obj.GetNewConnection(), bufcof1, sizeof(bufcof1), 0);
		procent1 = vecBids[i].getpercentWinfirst();
		itoa(procent1, bufproc1, 10);
		send(obj.GetNewConnection(), bufproc1, sizeof(bufproc1), 0);
		strcpy_s(name2, sizeof(name2), vecBids[i].getSecondNamefootbalTeam());
		send(obj.GetNewConnection(), name2, sizeof(name2), 0);
		cof2 = vecBids[i].getSecondcofficient();
		itoa(cof2, bufcof2, 10);
		send(obj.GetNewConnection(), bufcof2, sizeof(bufcof2), 0);
		procent2 = vecBids[i].getprecentWinsecond();
		itoa(procent2, bufproc2, 10);
		send(obj.GetNewConnection(), bufproc2, sizeof(bufproc2), 0);
		strcpy_s(name, sizeof(name), vecBids[i].getNameExpert());
		send(obj.GetNewConnection(), name, sizeof(name), 0);
		strcpy_s(login, sizeof(login), vecBids[i].getLoginExpert());
		send(obj.GetNewConnection(), login, sizeof(login), 0);
		check++;
	}
	
	}
	if (check == 0)
	{
		char msg[100];
		int ch = 1;
		itoa(ch, msg, 10);
		send(obj.GetNewConnection(), msg, sizeof(msg), 0);
	}
}

void User::findUser(Server& obj)
{
	int check = 0;
	char log[100], tel[100];
	recv(obj.GetNewConnection(), log, sizeof(log), 0);
	recv(obj.GetNewConnection(), tel, sizeof(tel), 0);
	for(int i=0;i<vecHuman.size();i++)
	{
		if(strcmp(vecHuman[i].getlogin(), log) == 0 && strcmp(vecHuman[i].getTel(), tel) == 0)
			{
				
			char buf[100];
			check++;
			itoa(check, buf, 10);
			send(obj.GetNewConnection(), buf, sizeof(buf), 0);
			char name[100], tel[100], pas_info[100], login[100], password[100];
			strcpy_s(name, sizeof(name), vecHuman[i].getName());
			send(obj.GetNewConnection(), name, sizeof(name), 0);
			strcpy_s(tel, sizeof(tel), vecHuman[i].getTel());
			send(obj.GetNewConnection(), tel, sizeof(tel), 0);
			strcpy_s(pas_info, sizeof(pas_info), vecHuman[i].getPas_info());
			send(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
			strcpy_s(login, sizeof(login), vecHuman[i].getlogin());
			send(obj.GetNewConnection(), login, sizeof(login), 0);
			strcpy_s(password, sizeof(password), vecHuman[i].getPassword());
			send(obj.GetNewConnection(), password, sizeof(password), 0);
			char msg[100];
			float cash = vecHuman[i].getCash();
			itoa(cash, msg, 10);
			send(obj.GetNewConnection(), msg, sizeof(msg), 0);
			seve_info_Client();
			}
	}
	if (check == 0)
	{
		char error[100];
		itoa(check, error, 10);
		send(obj.GetNewConnection(), error, sizeof(error), 0);
	}
}

void User::findAdmin(Server& obj)
{
	int check = 0;
	char log[100], tel[100];
	recv(obj.GetNewConnection(), log, sizeof(log), 0);
	recv(obj.GetNewConnection(), tel, sizeof(tel), 0);
	for (int i = 0; i < vecAdmin.size(); i++)
	{
		if (strcmp(vecAdmin[i].getlogin(), log) == 0 && strcmp(vecAdmin[i].getTel(), tel) == 0)
		{

			char buf[100];
			check++;
			itoa(check, buf, 10);
			send(obj.GetNewConnection(), buf, sizeof(buf), 0);
			char name[100], tel[100], pas_info[100], login[100], password[100];
			strcpy_s(name, sizeof(name), vecAdmin[i].getName());
			send(obj.GetNewConnection(), name, sizeof(name), 0);
			strcpy_s(tel, sizeof(tel), vecAdmin[i].getTel());
			send(obj.GetNewConnection(), tel, sizeof(tel), 0);
			strcpy_s(pas_info, sizeof(pas_info), vecAdmin[i].getPas_info());
			send(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
			strcpy_s(login, sizeof(login), vecAdmin[i].getlogin());
			send(obj.GetNewConnection(), login, sizeof(login), 0);
			strcpy_s(password, sizeof(password), vecAdmin[i].getPassword());
			send(obj.GetNewConnection(), password, sizeof(password), 0);
			save_info_Admin();
		}
	}
	if (check == 0)
	{
		char error[100];
		itoa(check, error, 10);
		send(obj.GetNewConnection(), error, sizeof(error), 0);
	}
}

void User::findExpert(Server& obj)
{
	int check = 0;
	char log[100], tel[100];
	recv(obj.GetNewConnection(), log, sizeof(log), 0);
	recv(obj.GetNewConnection(), tel, sizeof(tel), 0);
	for (int i = 0; i < vecExpert.size(); i++)
	{
		if (strcmp(vecExpert[i].getlogin(), log) == 0 && strcmp(vecExpert[i].getTel(), tel) == 0)
		{

			char buf[100];
			check++;
			itoa(check, buf, 10);
			send(obj.GetNewConnection(), buf, sizeof(buf), 0);
			char name[100], tel[100], pas_info[100], login[100], password[100];
			strcpy_s(name, sizeof(name), vecExpert[i].getName());
			send(obj.GetNewConnection(), name, sizeof(name), 0);
			strcpy_s(tel, sizeof(tel), vecExpert[i].getTel());
			send(obj.GetNewConnection(), tel, sizeof(tel), 0);
			strcpy_s(pas_info, sizeof(pas_info), vecExpert[i].getPas_info());
			send(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
			strcpy_s(login, sizeof(login), vecExpert[i].getlogin());
			send(obj.GetNewConnection(), login, sizeof(login), 0);
			strcpy_s(password, sizeof(password), vecExpert[i].getPassword());
			send(obj.GetNewConnection(), password, sizeof(password), 0);
			save_info_Expert();
		}
	}
	if (check == 0)
	{
		char error[100];
		itoa(check, error, 10);
		send(obj.GetNewConnection(), error, sizeof(error), 0);
	}
}

void User::printf_infoBet(Server& obj)
{
	char name1[100], name2[100], login[100], name[100], bufcof1[100], bufcof2[100], bufproc1[100], bufproc2[100], buf[100];
	float cof1, cof2;
	int procent1, procent2;
	int size = vecBids.size();
	size = vecBids.size();
	itoa(size, buf, 10);
	send(obj.GetNewConnection(), buf, sizeof(buf), 0);
	for (int i = 0; i < vecBids.size(); i++)
	{
		char name1[100], name2[100], login[100], name[100], bufcof1[100], bufcof2[100], bufproc1[100], bufproc2[100], buf[100];
		float cof1, cof2;
		int procent1, procent2;
		strcpy_s(name1, sizeof(name1), vecBids[i].getFirstNamefootbalTeam());
		send(obj.GetNewConnection(), name1, sizeof(name1), 0);
		cof1=vecBids[i].getFirstcofficient();
		itoa(cof1, bufcof1, 10);
		send(obj.GetNewConnection(), bufcof1, sizeof(bufcof1), 0);
		procent1 = vecBids[i].getpercentWinfirst();
		itoa(procent1, bufproc1, 10);
		send(obj.GetNewConnection(), bufproc1, sizeof(bufproc1), 0);
		strcpy_s(name2, sizeof(name2), vecBids[i].getSecondNamefootbalTeam());
		send(obj.GetNewConnection(), name2, sizeof(name2), 0);
		cof2= vecBids[i].getSecondcofficient();
		itoa(cof2, bufcof2, 10);
		send(obj.GetNewConnection(), bufcof2, sizeof(bufcof2), 0);
		procent2 = vecBids[i].getprecentWinsecond();
		itoa(procent2, bufproc2, 10);
		send(obj.GetNewConnection(), bufproc2, sizeof(bufproc2), 0);
		strcpy_s(name, sizeof(name), vecBids[i].getNameExpert());
		send(obj.GetNewConnection(), name, sizeof(name), 0);
		strcpy_s(login, sizeof(login), vecBids[i].getLoginExpert());
		send(obj.GetNewConnection(), login, sizeof(login), 0);

	}
}

void User::printf_infoClient(Server& obj)
{
	char buf[100];
	int size;
	size = vecHuman.size();
	itoa(size, buf, 10);
	send(obj.GetNewConnection(), buf, sizeof(buf), 0);
	for(int i=0;i<vecHuman.size();i++)
	{
		char name[100], tel[100], pas_info[100], login[100], password[100];
		float cash;
		strcpy_s(name, sizeof(name), vecHuman[i].getName());
		send(obj.GetNewConnection(), name, sizeof(name), 0);
		strcpy_s(tel, sizeof(tel), vecHuman[i].getTel());
		send(obj.GetNewConnection(), tel, sizeof(tel), 0);
		strcpy_s(pas_info, sizeof(pas_info), vecHuman[i].getPas_info());
		send(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
		strcpy_s(login, sizeof(login), vecHuman[i].getlogin());
		send(obj.GetNewConnection(), login, sizeof(login), 0);
		strcpy_s(password, sizeof(password), vecHuman[i].getPassword());
		send(obj.GetNewConnection(), password, sizeof(password), 0);
		char msg[100];
		cash = vecHuman[i].getCash();
		itoa(cash, msg, 10);
		send(obj.GetNewConnection(), msg, sizeof(msg), 0);
	}
}

void User::printf_infoAdmin(Server& obj)
{
	char buf[100];
	int size;
	size = vecAdmin.size();
	itoa(size, buf, 10);
	send(obj.GetNewConnection(), buf, sizeof(buf), 0);
	for (int i = 0; i < vecAdmin.size(); i++)
	{
		char name[100], tel[100], pas_info[100], login[100], password[100];
		float cash;
		strcpy_s(name, sizeof(name), vecAdmin[i].getName());
		send(obj.GetNewConnection(), name, sizeof(name), 0);
		strcpy_s(tel, sizeof(tel), vecAdmin[i].getTel());
		send(obj.GetNewConnection(), tel, sizeof(tel), 0);
		strcpy_s(pas_info, sizeof(pas_info), vecAdmin[i].getPas_info());
		send(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
		strcpy_s(login, sizeof(login), vecAdmin[i].getlogin());
		send(obj.GetNewConnection(), login, sizeof(login), 0);
		strcpy_s(password, sizeof(password), vecAdmin[i].getPassword());
		send(obj.GetNewConnection(), password, sizeof(password), 0);
	}
}

void User::printf_infoExpert(Server& obj)
{
	char buf[100];
	int size;
	size = vecExpert.size();
	itoa(size, buf, 10);
	send(obj.GetNewConnection(), buf, sizeof(buf), 0);
	for (int i = 0; i < vecExpert.size(); i++)
	{
		char name[100], tel[100], pas_info[100], login[100], password[100];
		float cash;
		strcpy_s(name, sizeof(name), vecExpert[i].getName());
		send(obj.GetNewConnection(), name, sizeof(name), 0);
		strcpy_s(tel, sizeof(tel), vecExpert[i].getTel());
		send(obj.GetNewConnection(), tel, sizeof(tel), 0);
		strcpy_s(pas_info, sizeof(pas_info), vecExpert[i].getPas_info());
		send(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
		strcpy_s(login, sizeof(login), vecExpert[i].getlogin());
		send(obj.GetNewConnection(), login, sizeof(login), 0);
		strcpy_s(password, sizeof(password), vecExpert[i].getPassword());
		send(obj.GetNewConnection(), password, sizeof(password), 0);
	}
}

void User::save_info_bids()
{
	FileCreator obj;
	obj.write_vector_Bids(vecBids);
}


void User::seve_info_Client()
{
	FileCreator obj;
	obj.write_vector_User(vecHuman);
}

void User::save_info_Admin()
{
	FileCreator obj;
	obj.write_vector_Admin(vecAdmin);
}

void User::save_info_Expert()
{
	FileCreator obj;
	obj.write_vector_Expert(vecExpert);
}

void User::save_info_rating()
{
	FileCreator obj;
	obj.write_vector_Reiting(vecReiting);
}



//void User::save_info_Agancy()
//{
//	FileCreator obj;
//	obj.write_vector_Agancy(vecAgancy);
//}

User::~User()
{

}

