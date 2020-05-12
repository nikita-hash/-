#include "Function.h"



void check_imput(int i)
{
	while (true)
	{
		if (!cin)
		{
			cout << "Ошибка выбора варианта ,повторит попытку !" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}
}

void printf_money(Server& obj)
{
	system("cls");
	cout << "Meню вывода средств >>" << endl;
		int sum;
		cout << "Введите сумму которую хотите снять : ";
		cin >> sum;
		check_imput(sum);
		char buf[100];
		itoa(sum, buf, 10);
		send(obj.getConnetc(), buf, sizeof(buf), 0);
		recv(obj.getConnetc(), buf, sizeof(buf), 0);
		int ch = atoi(buf);
		if(ch==1)
		{
			cout << "На счете нет такой суммы ! " << endl;
			system("pause");
			system("cls");
		}
		else 
		{
			recv(obj.getConnetc(), buf, sizeof(buf), 0);
			int balance = atoi(buf);
			cout << "Операция успешно произведена " << endl;
			cout << "Вы сняли :" << sum << "руб" << endl;
			cout << "Остаток на счете : " << balance << "руб" << endl;
			system("pause");
			system("cls");
		}
}

void replenish_promised_payment(Server& obj)
{
	system("cls");
	cout << "Меню оплаты обещанного платежа >>" << endl;
	char payment[100];
	int pay;
	recv(obj.getConnetc(), payment, sizeof(payment), 0);
	pay = atoi(payment);
	cout << "Ваш долг состовляет : " << pay << endl;
	cout << "Введите сумму для оплаты : ";
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
		cout << "Недостаточно средств " << endl;
	}
	else
	{
		if(ch==1)
		{
			int sum;
			recv(obj.getConnetc(), buf, sizeof(buf), 0);
			sum = atoi(buf);
			cout << "Платеж погашен сумма в размере " << sum << " руб будет переведена на ваш счет " << endl;
			system("pause");
			system("cls");
		}
		else
		{
			recv(obj.getConnetc(), buf, sizeof(buf), 0);
			sum = atoi(buf);
			cout << "Остаток платежа состовляет " << sum << "руб " << endl;
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
	cout << "Введите сумму для пополнения : ";
	cin >> sum;
	check_imput(sum);
	itoa(sum, buf, 10);
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Транзакция прошла успешно !" << endl;

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
	cout << "Введите оценку от 1-10" << endl;
	int rating;
	while(true)
	{
		cin >> rating;
		check_imput(rating);
		if (rating > 10 && rating < 0)
		{
			cout << "Введите оценку в нужном диапозоне " << endl;
		}
		else break;
	}
	
	itoa(rating, buf2, 10);
	send(obj.getConnetc(), buf2, sizeof(buf2), 0);
	cout << "Ваша оценка сохранена !" << endl;
}

void addForecast(Server& obj)
{
	int check;
	char name1[100], name2[100], login[100], name[100], bufcof1[100], bufcof2[100], bufproc1[100], bufproc2[100], msg[100];
	float cof1, cof2;
	int procent1, procent2;
	cout << "Меню добавления прогноза >>" << endl;
	cout << "Введите название команды : ";
	cin >> name1;
	send(obj.getConnetc(), name1, sizeof(name1), 0);
	cout << "кофициент на победу : ";
	cin >> cof1;
	itoa(cof1, bufcof1, 10);
	send(obj.getConnetc(), bufcof1, sizeof(bufcof1), 0);
	cout << "Процент победы команды : ";
	cin >> procent1;
	itoa(procent1, bufproc1, 10);
	send(obj.getConnetc(), bufproc1, sizeof(bufproc1), 0);
	cout << "Введите название команды : ";
	cin >> name2;
	send(obj.getConnetc(), name2, sizeof(name2), 0);
	cout << "кофициент на победу : ";
	cin >> cof2;
	itoa(cof2, bufcof2, 10);
	send(obj.getConnetc(), bufcof2, sizeof(bufcof2), 0);
	cout << "Процент победы команды : ";
	cin >> procent2;
	itoa(procent2, bufproc2, 10);
	send(obj.getConnetc(), bufproc2, sizeof(bufproc2), 0);	
		system("cls");
		cout << "Прогноз добавлен !" << endl;
		cout << name1 << setw(39) << name2 << endl;
		cout << "Коэфициент:" << cof1 << setw(38) << "Коэфициент:"<< cof2 << endl;
		system("pause");
		system("cls");
}

void addClient(Server& obj)
{
	system("cls");
	char buf[100];
	cout << "Регистраци>>" << endl;
	cout << "Ваша имя :";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Ваш номер телефона : +375";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Ваш паспортный номер : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Придумайте свой логин : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Придумайте свой пороль : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);

	cout << "регистрация прошла успешно " << endl;
	system("pause");
	system("cls");
}

void addAdmin(Server& obj)
{
	system("cls");
	char buf[100];
	cout << "Регистраци>>" << endl;
	cout << "Ваша имя :";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Ваш номер телефона : +375";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Ваш паспортный номер : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Придумайте свой логин : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Придумайте свой пороль : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "регистрация прошла успешно " << endl;
	system("pause");
	system("cls");
}

void addExpert(Server& obj)
{
	system("cls");
	char buf[100];
	cout << "Регистраци>>" << endl;
	cout << "Ваша имя :";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Ваш номер телефона : +375";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Ваш паспортный номер : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Придумайте свой логин : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Придумайте свой пороль : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);

	cout << "регистрация прошла успешно " << endl;
	system("pause");
	system("cls");
}

void AutorizationUser(Server& obj)
{
	char buf[100];
	cout << "Меню авторизации >>" << endl;
	cout << "Логин : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Пороль : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	char buff[100];
	recv(obj.getConnetc(), buff, sizeof(buff), 0);
	int ch = atoi(buff);
	if( ch==0)
	{
		cout << "Нет такого пользоватьеля " << endl;
		system("pause");
		Menu menu;
		menu.startMenu(obj);
	}
	else
	{
		system("cls");
		char name[100];
		recv(obj.getConnetc(), name, sizeof(name), 0);
		cout << "Добро пожаловать " << name <<":)"<<endl;
	}
}

void AutorizationAdmin(Server& obj)
{
	char buf[100];
	cout << "Меню авторизации >>" << endl;
	cout << "Логин : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Пороль : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	char buff[100];
	recv(obj.getConnetc(), buff, sizeof(buff), 0);
	int ch = atoi(buff);
	if (ch == 0)
	{
		cout << "Нет такого Администратора  " << endl;
		system("pause");
		Menu menu;
		menu.startMenu(obj);
	}
	else
	{
		char name[100];
		recv(obj.getConnetc(), name, sizeof(name), 0);
		cout << "Добро пожаловать Администратор " << name << ":)" << endl;
	}
}

void AutorizationExpert(Server& obj)
{
	char buf[100];
	cout << "Меню авторизации >>" << endl;
	cout << "Логин : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Пороль : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	char buff[100];
	recv(obj.getConnetc(), buff, sizeof(buff), 0);
	int ch = atoi(buff);
	if (ch == 0)
	{
		cout << "Нет такого пользоватьеля " << endl;
		system("pause");
		Menu menu;
		menu.startMenu(obj);
	}
	else
	{
		system("cls");
		char name[100];
		recv(obj.getConnetc(), name, sizeof(name), 0);
		cout << "Добро пожаловать " << name << ":)" << endl;
	}
}

void PrintfUserInfo(Server& obj)
{
	char buf[100];
	int size;
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	size=atoi(buf);
	system("cls");
	cout << "имя \t" << "номер телефона \t" << "паспортные д. \t" << "логин \t" << "пороль \t" << "денег на счете " << endl;
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
	cout << "имя \t" << "номер телефона \t" << "паспортные д. \t" << "логин \t" << "пороль \t" << endl;
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
	cout << "имя \t" << "номер телефона \t" << "паспортные д. \t" << "логин \t" << "пороль \t" << endl;
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
		cout << "Матч:" <<i+1<< endl;
		cout << name1 << setw(39) << name2 << endl;
		cout << "Коэфициент:" << cof1 << setw(37) << "Коэфициент:" << cof2 << endl;
	}
}

void DelClient(Server& obj)
{
	system("cls");
	int ch = 0;
	cout << "Меню удаления пользователя " << endl;
	cout << "Введите логин пользователя : ";
	char log[100];
	cin >> log;
	send(obj.getConnetc(), log, sizeof(log), 0);
	cout << "Введите паспортные данные пользователя : ";
	char pas[100];
	cin >> pas;
	send(obj.getConnetc(), pas, sizeof(pas), 0);
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	ch = atoi(buf);
	if (ch == 0)
	{
		system("cls");
		cout << "такого пользователя нет " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "Пользователь:" << endl;
		char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
		float cash;
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		recv(obj.getConnetc(), msg, sizeof(msg), 0);
		cash = atoi(msg);
		cout << "Имя : " << name << endl;
		cout << "Номер телефона : " << tel << endl;
		cout << "Паспортные данные : " << pas_info << endl;
		cout << "Состояние кошелька : " << cash << endl;
		cout << "Логин : " << login << endl;
		cout << "Пороль : " << password << endl;
		cout << "удален!" << endl;
		system("pause");
		system("cls");
	}
}

void DelAdmin(Server& obj)
{
	system("cls");
	int ch = 0;
	cout << "Меню удаления Администратора " << endl;
	cout << "Введите логин админа : ";
	char log[100];
	cin >> log;
	send(obj.getConnetc(), log, sizeof(log), 0);
	cout << "Введите паспортные данные админа : ";
	char pas[100];
	cin >> pas;
	send(obj.getConnetc(), pas, sizeof(pas), 0);
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	ch = atoi(buf);
	if (ch == 0)
	{
		system("cls");
		cout << "такого пользователя нет " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "Админ:" << endl;
		char name[100], tel[100], pas_info[100], login[100], password[100];
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		cout << "Имя : " << name << endl;
		cout << "Номер телефона : " << tel << endl;
		cout << "Паспортные данные : " << pas_info << endl;
		cout << "Логин : " << login << endl;
		cout << "Пороль : " << password << endl;
		cout << "удален!" << endl;
		system("pause");
		system("cls");
	}
}

void DelExpert(Server& obj)
{
	system("cls");
	int ch = 0;
	cout << "Меню удаления Эксперта " << endl;
	cout << "Введите логин : ";
	char log[100];
	cin >> log;
	send(obj.getConnetc(), log, sizeof(log), 0);
	cout << "Введите паспортные данные : ";
	char pas[100];
	cin >> pas;
	send(obj.getConnetc(), pas, sizeof(pas), 0);
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	ch = atoi(buf);
	if (ch == 0)
	{
		system("cls");
		cout << "такого Эксперта нет " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "Эксперт:" << endl;
		char name[100], tel[100], pas_info[100], login[100], password[100];
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		cout << "Имя : " << name << endl;
		cout << "Номер телефона : " << tel << endl;
		cout << "Паспортные данные : " << pas_info << endl;
		cout << "Логин : " << login << endl;
		cout << "Пороль : " << password << endl;
		cout << "удален!" << endl;
		system("pause");
		system("cls");
	}
}

void findBids(Server& obj)
{
	cout << "Меню поиска матча >>" << endl;
	char name1[100], name2[100];
	cout << "Введите название первой команды : ";
	cin >> name1;
	cout << "Введите название второй команлы : ";
	cin >> name2;
	send(obj.getConnetc(), name1, sizeof(name1), 0);
	send(obj.getConnetc(), name2, sizeof(name2), 0);
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	int check = atoi(buf);
	if(check==0)
	{
		cout << "Нет таких матчей " << endl;
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
		cout << "Матч:" << endl;
		cout << name1 << setw(39) << name2 << endl;
		cout << "Коэфициент:" << cof1 << setw(37) << "Коэфициент:" << cof2 << endl;
	}
}

void findClient(Server& obj)
{
	system("cls");
	cout << "Меню поиска клиента >>" << endl;
	cout << "Введите логин клиента : ";
	int check = 0;
	char log[100], tel[100];
	cin >> log;
	send(obj.getConnetc(), log, sizeof(log), 0);
	cout << "Введите номер телефона :+375";
	cin >> tel;
	send(obj.getConnetc(), tel, sizeof(tel), 0);
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	check = atoi(buf);
	if(check==0)
	{
		system("cls");
		cout << "такого пользователя нет " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "Результаты поиска:" << endl;
		char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
		float cash;
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		recv(obj.getConnetc(), msg, sizeof(msg), 0);
		cash = atoi(msg);
		cout << "Имя : " << name << endl;
		cout << "Номер телефона : " << tel << endl;
		cout << "Паспортные данные : " << pas_info << endl;
		cout << "Состояние кошелька : " << cash << endl;
		cout << "Логин : " << login << endl;
		cout << "Пороль : " << password << endl;
		system("pause");
		system("cls");
	}
}

void findAdmin(Server& obj)
{
	system("cls");
	cout << "Меню поиска админа >>" << endl;
	cout << "Введите логин админа : ";
	int check = 0;
	char log[100], tel[100];
	cin >> log;
	send(obj.getConnetc(), log, sizeof(log), 0);
	cout << "Введите номер телефона :+375";
	cin >> tel;
	send(obj.getConnetc(), tel, sizeof(tel), 0);
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	check = atoi(buf);
	if (check == 0)
	{
		system("cls");
		cout << "такого пользователя нет " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "Результаты поиска:" << endl;
		char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
		float cash;
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		cout << "Имя : " << name << endl;
		cout << "Номер телефона : " << tel << endl;
		cout << "Паспортные данные : " << pas_info << endl;
		cout << "Логин : " << login << endl;
		cout << "Пороль : " << password << endl;
		system("pause");
		system("cls");
	}
}

void findExpert(Server& obj)
{
	system("cls");
	cout << "Меню поиска Экспертов >>" << endl;
	cout << "Введите логин Эксперта : ";
	int check = 0;
	char log[100], tel[100];
	cin >> log;
	send(obj.getConnetc(), log, sizeof(log), 0);
	cout << "Введите номер телефона :+375";
	cin >> tel;
	send(obj.getConnetc(), tel, sizeof(tel), 0);
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	check = atoi(buf);
	if (check == 0)
	{
		system("cls");
		cout << "такого Эксперта нет " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "Результаты поиска:" << endl;
		char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
		float cash;
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		cout << "Имя : " << name << endl;
		cout << "Номер телефона : " << tel << endl;
		cout << "Паспортные данные : " << pas_info << endl;
		cout << "Логин : " << login << endl;
		cout << "Пороль : " << password << endl;
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
		cout << "Нет ни одной оценки или нет ни одной доступной ставки  " << endl;
	}
	if(ch==2)
	{
		cout << "Не все ставки получили оценки !" << endl;
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
		cout << "ЛУЧШИЙ МАТЧ !!!" << endl;
		cout << "##############################################" << endl;
		cout << "Матч:"<< endl;
		cout << name1 << setw(39) << name2 << endl;
		cout << "Коэфициент:" << cof1 << setw(37) << "Коэфициент:" << cof2 << endl;
	}
}
