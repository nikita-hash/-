#include "Menu.h"
void checkImput(int i);

void Menu::CheckImputSwitch(int check)
{
	while (true)
	{
		if (!cin)
		{
			cout << "������ ������ �������� ,�������� ������� !" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}
}

void Menu::displayUser(Server& obj)
{
	cout << "������������ : ";
	char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
	float cash;
	int contr;
	recv(obj.getConnetc(), name, sizeof(name), 0);
	recv(obj.getConnetc(), tel, sizeof(tel), 0);
	recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
	recv(obj.getConnetc(), login, sizeof(login), 0);
	cout << login << endl;
	recv(obj.getConnetc(), password, sizeof(password), 0);
	recv(obj.getConnetc(), msg, sizeof(msg), 0);
	cash = atoi(msg);
	recv(obj.getConnetc(), msg, sizeof(msg), 0);
	contr = atoi(msg);
	cout << "###########################################################" << endl;
	cout << "���� ������������ ������: " << endl;
	cout << "��� : " << name << endl;
	cout << "����� �������� : " << tel << endl;
	cout << "���������� ������ : " << pas_info << endl;
	cout << "��������� �������� : " << cash << endl;
	cout << "��������� ������ : " << contr << endl;
	cout << "����� : " << login << endl;
	cout << "������ : " << password << endl;
	cout << "###########################################################" << endl;
	system("pause");
	
}

void Menu::displayExpert(Server& obj)
{
	cout << "������� : ";
	char name[100], tel[100], pas_info[100], login[100], password[100];
	recv(obj.getConnetc(), name, sizeof(name), 0);
	recv(obj.getConnetc(), tel, sizeof(tel), 0);
	recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
	recv(obj.getConnetc(), login, sizeof(login), 0);
	cout << login << endl;
	recv(obj.getConnetc(), password, sizeof(password), 0);
	cout << "###########################################################" << endl;
	cout << "���� ������������ ������: " << endl;
	cout << "����� : " << login << endl;
	cout << "������ : " << password << endl;
	cout << "��� : " << name << endl;
	cout << "������� :+375" << tel << endl;
	cout << "���������� ������ : " << pas_info << endl;
	cout << "###########################################################" << endl;
	system("pause");
}

void Menu::MenuBet(Server& obj)
{
	
		char buf[100];
		int ch;
		PrintfBet(obj);
		cout << "�������� ���� " << endl;
		cin >> ch;
		CheckImputSwitch(ch);
		_itoa(ch, buf, 10);
		send(obj.getConnetc(), buf, sizeof(buf), 0);
		char msg[100];
		int check;
		recv(obj.getConnetc(), msg, sizeof(msg), 0);
		check = atoi(msg);
		if(check==0)
		{
			cout << "��� ��������� ������" << endl;
			
		}
		else
		{
			char date[100], bu2[100];
			float cash;
			cout << "������� ����������� ���� : ";
			cin >> date;
			send(obj.getConnetc(), date, sizeof(date), 0);
			cout << "������� ����� : ";
			cin >> cash;
			itoa(cash, bu2, 10);
			send(obj.getConnetc(), bu2, sizeof(bu2),0);
			recv(obj.getConnetc(), bu2, sizeof(bu2), 0);
			int cha;
			cha = atoi(bu2);
			if(cha==2)
			{
				cout << "������������ ����� �� ����� " << endl;
			}
			else
			{
				cout << "������ ������� !" << endl;
				
			}
		}
	
	
}

void Menu::MenuChangeUser(Server& obj)
{
	while(true)
	{
		system("cls");
		cout << "�� ������ ������ �������� >>" << endl;
		cout << "1)���" << endl;
		cout << "2)���������� ������ " << endl;
		cout << "3)����� �������� " << endl;
		cout << "4)�����" << endl;
		cout << "5)������" << endl;
		cout << "6)�����" << endl;
		int ch;
		char buf[100];
		cin >> ch;
		CheckImputSwitch(ch);
		itoa(ch, buf, 10);
		send(obj.getConnetc(), buf, sizeof(buf), 0);
		switch(ch)
		{
		case 1:cout << "������� ����� ��� :";
			char name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
				cout << "��� ������� �������� !!" << endl;
				system("pause");
				system("cls");
				break;
		case 2:cout << "������� ����� ���������� ������ :";
			 name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "������ ������� �������� ������� �������� !!" << endl;
			system("pause");
			system("cls");
			break;
		case 3:cout << "������� ����� ������� :+375";
			 name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "������ ������� �������� ������� �������� !!" << endl;
			system("pause");
			system("cls");
			break;
		case 4:cout << "������� ����� ����� : ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "������ ������� �������� ������� �������� !!" << endl;
			system("pause");
			system("cls");
			break;
		case 5:cout << "������� ����� ������ : ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "������ ������� �������� ������� �������� !!" << endl;
			system("pause");
			system("cls");
			break;
		case 6:MenuUser(obj);
		}
	}
}

void Menu::MenuChangeExpert(Server& obj)
{
	while (true)
	{
		system("cls");
		cout << "�� ������ ������ �������� >>" << endl;
		cout << "1)���" << endl;
		cout << "2)���������� ������ " << endl;
		cout << "3)����� �������� " << endl;
		cout << "4)�����" << endl;
		cout << "5)������" << endl;
		cout << "6)�����" << endl;
		int ch;
		char buf[100];
		cin >> ch;
		CheckImputSwitch(ch);
		itoa(ch, buf, 10);
		send(obj.getConnetc(), buf, sizeof(buf), 0);
		switch (ch)
		{
		case 1:cout << "������� ����� ��� :";
			char name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "��� ������� �������� !!" << endl;
			system("pause");
			system("cls");
			break;
		case 2:cout << "������� ����� ���������� ������ :";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "������ ������� �������� ������� �������� !!" << endl;
			system("pause");
			system("cls");
			break;
		case 3:cout << "������� ����� ������� :+375";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "������ ������� �������� ������� �������� !!" << endl;
			system("pause");
			system("cls");
			break;
		case 4:cout << "������� ����� ����� : ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "������ ������� �������� ������� �������� !!" << endl;
			system("pause");
			system("cls");
			break;
		case 5:cout << "������� ����� ������ : ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "������ ������� �������� ������� �������� !!" << endl;
			system("pause");
			system("cls");
			break;
		case 6:MenuExpert(obj);
		}
	}
}

void Menu::startMenu(Server& Connection)
{
	
	while(1)
	{
		system("cls");
		char buf[100];
		int ch;
		cout << "1)����������� " << endl;
		cout << "2)����������� " << endl;
		cout << "3)����� ��� �������������" << endl;
		cout << "4)����� ��� ������� " << endl;
		cout << "5)�����" << endl;
		cin >> ch;
		CheckImputSwitch(ch);
		_itoa(ch, buf, 10);
		send(Connection.getConnetc(), buf, sizeof(buf), 0);
		switch (ch)
		{
		case 1:addClient(Connection); break;
		case 2:AutorizationUser(Connection); MenuUser(Connection); break;
		case 3:AutorizationAdmin(Connection); 	MenuAdmin(Connection); break;
		case 4:AutorizationExpert(Connection); MenuExpert(Connection); break;
		case 5:exit(1);
		case 6:break;
		}
	}
}

void Menu::MenuUser(Server& Connection)
{
	while(true)
	{
		char buf[100];
		int ch;
		//displayUser(Connection);
		cout << endl;
		cout << "1)������� ������ " << endl;
		cout << "2)��������� ���� " << endl;
		cout << "3)����� ��������� ������ " << endl;
		cout << "4)����� ������" << endl;
		cout << "5)�������� ��������� ������ " << endl;
		cout << "6)����� ������ ���� " << endl;
		cout << "7)������� ��������� �������� " << endl;
		cout << "8)�������� ��������� �������� " << endl;
		cout << "9)������ ��������� �� ������ ���� " << endl;
		cout << "10)�����" << endl;
		cin >> ch;
		CheckImputSwitch(ch);
		_itoa(ch, buf, 10);
		send(Connection.getConnetc(), buf, sizeof(buf), 0);
		switch(ch)
		{
		case 1:MenuBet(Connection); break;
		case 2:Replenish_account(Connection); break;
		case 3:Replenish_account(Connection); break;
		case 4:printf_money(Connection); break;
		case 5:replenish_promised_payment(Connection); break;
		case 6:findBids(Connection); break;
		case 7:displayUser(Connection); break;
		case 8:MenuChangeUser(Connection); break;
		case 9:ExpertOpinion(Connection); break;
		case 10:startMenu(Connection); break;
		}
	}
}

void Menu::MenuAdmin(Server& Connection)
{
	while (1)
	{
		cout << "1)����� ���������� � ���� ������������� " << endl;
		cout << "2)����� ���������� � ���� ��������������� " << endl;
		cout << "3)����� ������������ " << endl;
		cout << "4)����� ������������� " << endl;
		cout << "5)������� �������������� " << endl;
		cout << "6)������� ������������ " << endl;
		cout << "7)����������� ������" << endl;
		cout << "8)�������� �������� " << endl;
		cout << "9)����� ���������� � ���� ���������" << endl;
		cout << "10)������� �������� " << endl;
		cout << "11)����� �������� " << endl;
		cout << "12)�����" << endl;
		int ch;
		char buf[100];
		cin >> ch;
		CheckImputSwitch(ch);
		itoa(ch, buf, 10);
		send(Connection.getConnetc(), buf, sizeof(buf), 0);
		switch(ch)
		{
		case 1:PrintfUserInfo(Connection); break;
		case 2:PrintfAdminInfo(Connection); break;
		case 3:findClient(Connection); break;
		case 4:findAdmin(Connection); break;
		case 5:DelAdmin(Connection); break;
		case 6:DelClient(Connection); break;
		case 7:addAdmin(Connection); break;
		case 8:addExpert(Connection); break;
		case 9:PrintfExpertInfo(Connection); break;
		case 10:DelExpert(Connection); break;
		case 11:findExpert(Connection); break;
		case 12:startMenu(Connection); break;
		}
	}
}

void Menu::MenuExpert(Server& Connection)
{
	while (true)
	{

		char buf[100];
		int ch;
		cout << endl;
		cout << "1)�������� �������" << endl;
		cout << "2)����� ���������� ��������" << endl;
		cout << "3)�������������� ���������� �������� " << endl;
		cout << "4)�������� ������ ����� " << endl;
		cout << "5)�����" << endl;
		cin >> ch;
		CheckImputSwitch(ch);
		_itoa(ch, buf, 10);
		send(Connection.getConnetc(), buf, sizeof(buf), 0);
		switch (ch)
		{
		case 1: addForecast(Connection); break;
		case 2:displayExpert(Connection); break;
		case 3:MenuChangeExpert(Connection); break;
		case 4:addReiting(Connection); break;
		case 5:startMenu(Connection);
		}
	}
}

void checkImput(int i)
{
	while (true)
	{
		if (!cin)
		{
			cout << "������ ������ �������� ,�������� ������� !" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}
}
