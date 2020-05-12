#include "Function.h"



void check_imput(int i)
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

void printf_money(Server& obj)
{
	system("cls");
	cout << "Me�� ������ ������� >>" << endl;
		int sum;
		cout << "������� ����� ������� ������ ����� : ";
		cin >> sum;
		check_imput(sum);
		char buf[100];
		itoa(sum, buf, 10);
		send(obj.getConnetc(), buf, sizeof(buf), 0);
		recv(obj.getConnetc(), buf, sizeof(buf), 0);
		int ch = atoi(buf);
		if(ch==1)
		{
			cout << "�� ����� ��� ����� ����� ! " << endl;
			system("pause");
			system("cls");
		}
		else 
		{
			recv(obj.getConnetc(), buf, sizeof(buf), 0);
			int balance = atoi(buf);
			cout << "�������� ������� ����������� " << endl;
			cout << "�� ����� :" << sum << "���" << endl;
			cout << "������� �� ����� : " << balance << "���" << endl;
			system("pause");
			system("cls");
		}
}

void replenish_promised_payment(Server& obj)
{
	system("cls");
	cout << "���� ������ ���������� ������� >>" << endl;
	char payment[100];
	int pay;
	recv(obj.getConnetc(), payment, sizeof(payment), 0);
	pay = atoi(payment);
	cout << "��� ���� ���������� : " << pay << endl;
	cout << "������� ����� ��� ������ : ";
	int sum;
	cin >> sum;
	check_imput(sum);
	char buf[100];
	itoa(sum, buf, 10);
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
		int ch = atoi(buf);
	if(ch==0)
	{
		cout << "������������ ������� " << endl;
	}
	else
	{
		if(ch==1)
		{
			int sum;
			recv(obj.getConnetc(), buf, sizeof(buf), 0);
			sum = atoi(buf);
			cout << "������ ������� ����� � ������� " << sum << " ��� ����� ���������� �� ��� ���� " << endl;
			system("pause");
			system("cls");
		}
		else
		{
			recv(obj.getConnetc(), buf, sizeof(buf), 0);
			sum = atoi(buf);
			cout << "������� ������� ���������� " << sum << "��� " << endl;
			system("pause");
			system("cls");
		}
	}
}

void Replenish_account(Server& obj)
{
	system("cls");
	char buf[100];
	int sum;
	cout << "������� ����� ��� ���������� : ";
	cin >> sum;
	check_imput(sum);
	itoa(sum, buf, 10);
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "���������� ������ ������� !" << endl;

}

void addReiting(Server& obj)
{
	system("cls");
	int ch;
	char buf[100], buf2[100];
	PrintfBet(obj);
	cin >> ch;
	itoa(ch, buf, 10);
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "������� ������ �� 1-10" << endl;
	int rating;
	while(true)
	{
		cin >> rating;
		check_imput(rating);
		if (rating > 10 && rating < 0)
		{
			cout << "������� ������ � ������ ��������� " << endl;
		}
		else break;
	}
	
	itoa(rating, buf2, 10);
	send(obj.getConnetc(), buf2, sizeof(buf2), 0);
	cout << "���� ������ ��������� !" << endl;
}

void addForecast(Server& obj)
{
	int check;
	char name1[100], name2[100], login[100], name[100], bufcof1[100], bufcof2[100], bufproc1[100], bufproc2[100], msg[100];
	float cof1, cof2;
	int procent1, procent2;
	cout << "���� ���������� �������� >>" << endl;
	cout << "������� �������� ������� : ";
	cin >> name1;
	send(obj.getConnetc(), name1, sizeof(name1), 0);
	cout << "��������� �� ������ : ";
	cin >> cof1;
	itoa(cof1, bufcof1, 10);
	send(obj.getConnetc(), bufcof1, sizeof(bufcof1), 0);
	cout << "������� ������ ������� : ";
	cin >> procent1;
	itoa(procent1, bufproc1, 10);
	send(obj.getConnetc(), bufproc1, sizeof(bufproc1), 0);
	cout << "������� �������� ������� : ";
	cin >> name2;
	send(obj.getConnetc(), name2, sizeof(name2), 0);
	cout << "��������� �� ������ : ";
	cin >> cof2;
	itoa(cof2, bufcof2, 10);
	send(obj.getConnetc(), bufcof2, sizeof(bufcof2), 0);
	cout << "������� ������ ������� : ";
	cin >> procent2;
	itoa(procent2, bufproc2, 10);
	send(obj.getConnetc(), bufproc2, sizeof(bufproc2), 0);	
		system("cls");
		cout << "������� �������� !" << endl;
		cout << name1 << setw(39) << name2 << endl;
		cout << "����������:" << cof1 << setw(38) << "����������:"<< cof2 << endl;
		system("pause");
		system("cls");
}

void addClient(Server& obj)
{
	system("cls");
	char buf[100];
	cout << "����������>>" << endl;
	cout << "���� ��� :";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "��� ����� �������� : +375";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "��� ���������� ����� : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "���������� ���� ����� : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "���������� ���� ������ : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);

	cout << "����������� ������ ������� " << endl;
	system("pause");
	system("cls");
}

void addAdmin(Server& obj)
{
	system("cls");
	char buf[100];
	cout << "����������>>" << endl;
	cout << "���� ��� :";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "��� ����� �������� : +375";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "��� ���������� ����� : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "���������� ���� ����� : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "���������� ���� ������ : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "����������� ������ ������� " << endl;
	system("pause");
	system("cls");
}

void addExpert(Server& obj)
{
	system("cls");
	char buf[100];
	cout << "����������>>" << endl;
	cout << "���� ��� :";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "��� ����� �������� : +375";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "��� ���������� ����� : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "���������� ���� ����� : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "���������� ���� ������ : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);

	cout << "����������� ������ ������� " << endl;
	system("pause");
	system("cls");
}

void AutorizationUser(Server& obj)
{
	char buf[100];
	cout << "���� ����������� >>" << endl;
	cout << "����� : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "������ : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	char buff[100];
	recv(obj.getConnetc(), buff, sizeof(buff), 0);
	int ch = atoi(buff);
	if( ch==0)
	{
		cout << "��� ������ ������������� " << endl;
		system("pause");
		Menu menu;
		menu.startMenu(obj);
	}
	else
	{
		system("cls");
		char name[100];
		recv(obj.getConnetc(), name, sizeof(name), 0);
		cout << "����� ���������� " << name <<":)"<<endl;
	}
}

void AutorizationAdmin(Server& obj)
{
	char buf[100];
	cout << "���� ����������� >>" << endl;
	cout << "����� : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "������ : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	char buff[100];
	recv(obj.getConnetc(), buff, sizeof(buff), 0);
	int ch = atoi(buff);
	if (ch == 0)
	{
		cout << "��� ������ ��������������  " << endl;
		system("pause");
		Menu menu;
		menu.startMenu(obj);
	}
	else
	{
		char name[100];
		recv(obj.getConnetc(), name, sizeof(name), 0);
		cout << "����� ���������� ������������� " << name << ":)" << endl;
	}
}

void AutorizationExpert(Server& obj)
{
	char buf[100];
	cout << "���� ����������� >>" << endl;
	cout << "����� : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "������ : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	char buff[100];
	recv(obj.getConnetc(), buff, sizeof(buff), 0);
	int ch = atoi(buff);
	if (ch == 0)
	{
		cout << "��� ������ ������������� " << endl;
		system("pause");
		Menu menu;
		menu.startMenu(obj);
	}
	else
	{
		system("cls");
		char name[100];
		recv(obj.getConnetc(), name, sizeof(name), 0);
		cout << "����� ���������� " << name << ":)" << endl;
	}
}

void PrintfUserInfo(Server& obj)
{
	char buf[100];
	int size;
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	size=atoi(buf);
	system("cls");
	cout << "��� \t" << "����� �������� \t" << "���������� �. \t" << "����� \t" << "������ \t" << "����� �� ����� " << endl;
	for(int i=0;i<size;i++)
	{
		char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
		float cash;
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		recv(obj.getConnetc(), msg, sizeof(msg), 0);
		cash = atoi(msg);
		cout << name << "\t" << tel << "\t" << pas_info << "\t"<<setw(13) << login << "\t" << password << "\t" << cash << endl;
	}
	system("pause");
	system("cls");
}

void PrintfAdminInfo(Server& obj)
{
	char buf[100];
	int size;
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	size = atoi(buf);
	system("cls");
	cout << "��� \t" << "����� �������� \t" << "���������� �. \t" << "����� \t" << "������ \t" << endl;
	for (int i = 0; i < size; i++)
	{
		char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
		float cash;
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		cout << name << "\t" << tel << "\t" << pas_info << "\t" << setw(13) << login << "\t" << password << "\t" << endl;
	}
	system("pause");
	system("cls");
}

void PrintfExpertInfo(Server& obj)
{
	char buf[100];
	int size;
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	size = atoi(buf);
	system("cls");
	cout << "��� \t" << "����� �������� \t" << "���������� �. \t" << "����� \t" << "������ \t" << endl;
	for (int i = 0; i < size; i++)
	{
		char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
		float cash;
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		cout << name << "\t" << tel << "\t" << pas_info << "\t" << setw(13) << login << "\t" << password << "\t" << endl;
	}
	system("pause");
	system("cls");
}

void PrintfBet(Server& obj)
{
	system("cls");
	char name1[100], name2[100], login[100], name[100], bufcof1[100], bufcof2[100], bufproc1[100], bufproc2[100], msg[100];
	float cof1, cof2;
	int procent1, procent2, check;
	recv(obj.getConnetc(), msg, sizeof(msg), 0);
	check = atoi(msg);
	for (int i = 0; i < check; i++)
	{
		recv(obj.getConnetc(), name1, sizeof(name1), 0);
		recv(obj.getConnetc(), bufcof1, sizeof(bufcof1), 0);
		cof1 = atoi(bufcof1);
		recv(obj.getConnetc(), bufproc1, sizeof(bufproc1), 0);
		procent1 = atoi(bufproc1);
		recv(obj.getConnetc(), name2, sizeof(name2), 0);
		recv(obj.getConnetc(), bufcof2, sizeof(bufcof2), 0);
		cof2 = atoi(bufcof2);
		recv(obj.getConnetc(), bufproc2, sizeof(bufproc2), 0);
		procent2 = atoi(bufproc2);
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		cout << "##############################################" << endl;
		cout << "����:" <<i+1<< endl;
		cout << name1 << setw(39) << name2 << endl;
		cout << "����������:" << cof1 << setw(37) << "����������:" << cof2 << endl;
	}
}

void DelClient(Server& obj)
{
	system("cls");
	int ch = 0;
	cout << "���� �������� ������������ " << endl;
	cout << "������� ����� ������������ : ";
	char log[100];
	cin >> log;
	send(obj.getConnetc(), log, sizeof(log), 0);
	cout << "������� ���������� ������ ������������ : ";
	char pas[100];
	cin >> pas;
	send(obj.getConnetc(), pas, sizeof(pas), 0);
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	ch = atoi(buf);
	if (ch == 0)
	{
		system("cls");
		cout << "������ ������������ ��� " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "������������:" << endl;
		char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
		float cash;
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		recv(obj.getConnetc(), msg, sizeof(msg), 0);
		cash = atoi(msg);
		cout << "��� : " << name << endl;
		cout << "����� �������� : " << tel << endl;
		cout << "���������� ������ : " << pas_info << endl;
		cout << "��������� �������� : " << cash << endl;
		cout << "����� : " << login << endl;
		cout << "������ : " << password << endl;
		cout << "������!" << endl;
		system("pause");
		system("cls");
	}
}

void DelAdmin(Server& obj)
{
	system("cls");
	int ch = 0;
	cout << "���� �������� �������������� " << endl;
	cout << "������� ����� ������ : ";
	char log[100];
	cin >> log;
	send(obj.getConnetc(), log, sizeof(log), 0);
	cout << "������� ���������� ������ ������ : ";
	char pas[100];
	cin >> pas;
	send(obj.getConnetc(), pas, sizeof(pas), 0);
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	ch = atoi(buf);
	if (ch == 0)
	{
		system("cls");
		cout << "������ ������������ ��� " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "�����:" << endl;
		char name[100], tel[100], pas_info[100], login[100], password[100];
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		cout << "��� : " << name << endl;
		cout << "����� �������� : " << tel << endl;
		cout << "���������� ������ : " << pas_info << endl;
		cout << "����� : " << login << endl;
		cout << "������ : " << password << endl;
		cout << "������!" << endl;
		system("pause");
		system("cls");
	}
}

void DelExpert(Server& obj)
{
	system("cls");
	int ch = 0;
	cout << "���� �������� �������� " << endl;
	cout << "������� ����� : ";
	char log[100];
	cin >> log;
	send(obj.getConnetc(), log, sizeof(log), 0);
	cout << "������� ���������� ������ : ";
	char pas[100];
	cin >> pas;
	send(obj.getConnetc(), pas, sizeof(pas), 0);
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	ch = atoi(buf);
	if (ch == 0)
	{
		system("cls");
		cout << "������ �������� ��� " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "�������:" << endl;
		char name[100], tel[100], pas_info[100], login[100], password[100];
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		cout << "��� : " << name << endl;
		cout << "����� �������� : " << tel << endl;
		cout << "���������� ������ : " << pas_info << endl;
		cout << "����� : " << login << endl;
		cout << "������ : " << password << endl;
		cout << "������!" << endl;
		system("pause");
		system("cls");
	}
}

void findBids(Server& obj)
{
	cout << "���� ������ ����� >>" << endl;
	char name1[100], name2[100];
	cout << "������� �������� ������ ������� : ";
	cin >> name1;
	cout << "������� �������� ������ ������� : ";
	cin >> name2;
	send(obj.getConnetc(), name1, sizeof(name1), 0);
	send(obj.getConnetc(), name2, sizeof(name2), 0);
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	int check = atoi(buf);
	if(check==0)
	{
		cout << "��� ����� ������ " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		char name1[100], name2[100], login[100], name[100], bufcof1[100], bufcof2[100], bufproc1[100], bufproc2[100], msg[100];
		float cof1, cof2;
		int procent1, procent2;
		recv(obj.getConnetc(), name1, sizeof(name1), 0);
		recv(obj.getConnetc(), bufcof1, sizeof(bufcof1), 0);
		cof1 = atoi(bufcof1);
		recv(obj.getConnetc(), bufproc1, sizeof(bufproc1), 0);
		procent1 = atoi(bufproc1);
		recv(obj.getConnetc(), name2, sizeof(name2), 0);
		recv(obj.getConnetc(), bufcof2, sizeof(bufcof2), 0);
		cof2 = atoi(bufcof2);
		recv(obj.getConnetc(), bufproc2, sizeof(bufproc2), 0);
		procent2 = atoi(bufproc2);
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		cout << "##############################################" << endl;
		cout << "����:" << endl;
		cout << name1 << setw(39) << name2 << endl;
		cout << "����������:" << cof1 << setw(37) << "����������:" << cof2 << endl;
	}
}

void findClient(Server& obj)
{
	system("cls");
	cout << "���� ������ ������� >>" << endl;
	cout << "������� ����� ������� : ";
	int check = 0;
	char log[100], tel[100];
	cin >> log;
	send(obj.getConnetc(), log, sizeof(log), 0);
	cout << "������� ����� �������� :+375";
	cin >> tel;
	send(obj.getConnetc(), tel, sizeof(tel), 0);
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	check = atoi(buf);
	if(check==0)
	{
		system("cls");
		cout << "������ ������������ ��� " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "���������� ������:" << endl;
		char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
		float cash;
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		recv(obj.getConnetc(), msg, sizeof(msg), 0);
		cash = atoi(msg);
		cout << "��� : " << name << endl;
		cout << "����� �������� : " << tel << endl;
		cout << "���������� ������ : " << pas_info << endl;
		cout << "��������� �������� : " << cash << endl;
		cout << "����� : " << login << endl;
		cout << "������ : " << password << endl;
		system("pause");
		system("cls");
	}
}

void findAdmin(Server& obj)
{
	system("cls");
	cout << "���� ������ ������ >>" << endl;
	cout << "������� ����� ������ : ";
	int check = 0;
	char log[100], tel[100];
	cin >> log;
	send(obj.getConnetc(), log, sizeof(log), 0);
	cout << "������� ����� �������� :+375";
	cin >> tel;
	send(obj.getConnetc(), tel, sizeof(tel), 0);
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	check = atoi(buf);
	if (check == 0)
	{
		system("cls");
		cout << "������ ������������ ��� " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "���������� ������:" << endl;
		char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
		float cash;
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		cout << "��� : " << name << endl;
		cout << "����� �������� : " << tel << endl;
		cout << "���������� ������ : " << pas_info << endl;
		cout << "����� : " << login << endl;
		cout << "������ : " << password << endl;
		system("pause");
		system("cls");
	}
}

void findExpert(Server& obj)
{
	system("cls");
	cout << "���� ������ ��������� >>" << endl;
	cout << "������� ����� �������� : ";
	int check = 0;
	char log[100], tel[100];
	cin >> log;
	send(obj.getConnetc(), log, sizeof(log), 0);
	cout << "������� ����� �������� :+375";
	cin >> tel;
	send(obj.getConnetc(), tel, sizeof(tel), 0);
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	check = atoi(buf);
	if (check == 0)
	{
		system("cls");
		cout << "������ �������� ��� " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "���������� ������:" << endl;
		char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
		float cash;
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		cout << "��� : " << name << endl;
		cout << "����� �������� : " << tel << endl;
		cout << "���������� ������ : " << pas_info << endl;
		cout << "����� : " << login << endl;
		cout << "������ : " << password << endl;
		system("pause");
		system("cls");
	}
}

void ExpertOpinion(Server& obj)
{
	int ch;
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	ch = atoi(buf);
	if (ch == 1)
	{
		cout << "��� �� ����� ������ ��� ��� �� ����� ��������� ������  " << endl;
	}
	if(ch==2)
	{
		cout << "�� ��� ������ �������� ������ !" << endl;
	}
	if(ch==0)
	{
		char name1[100], name2[100], login[100], name[100], bufcof1[100], bufcof2[100], bufproc1[100], bufproc2[100], msg[100];
		float cof1, cof2;
		int procent1, procent2;
		recv(obj.getConnetc(), name1, sizeof(name1), 0);
		recv(obj.getConnetc(), bufcof1, sizeof(bufcof1), 0);
		cof1 = atoi(bufcof1);
		recv(obj.getConnetc(), bufproc1, sizeof(bufproc1), 0);
		procent1 = atoi(bufproc1);
		recv(obj.getConnetc(), name2, sizeof(name2), 0);
		recv(obj.getConnetc(), bufcof2, sizeof(bufcof2), 0);
		cof2 = atoi(bufcof2);
		recv(obj.getConnetc(), bufproc2, sizeof(bufproc2), 0);
		cout << "������ ���� !!!" << endl;
		cout << "##############################################" << endl;
		cout << "����:"<< endl;
		cout << name1 << setw(39) << name2 << endl;
		cout << "����������:" << cof1 << setw(37) << "����������:" << cof2 << endl;
	}
}
