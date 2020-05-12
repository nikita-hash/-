#include "Menu.h"
void checkImput(int i);

void Menu::CheckImputSwitch(int check)
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

void Menu::displayUser(Server& obj)
{
	cout << "Пользователь : ";
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
	cout << "Ваши персональные данные: " << endl;
	cout << "Имя : " << name << endl;
	cout << "Номер телефона : " << tel << endl;
	cout << "Паспортные данные : " << pas_info << endl;
	cout << "Состояние кошелька : " << cash << endl;
	cout << "Обещенный платеж : " << contr << endl;
	cout << "Логин : " << login << endl;
	cout << "Пороль : " << password << endl;
	cout << "###########################################################" << endl;
	system("pause");
	
}

void Menu::displayExpert(Server& obj)
{
	cout << "Эксперт : ";
	char name[100], tel[100], pas_info[100], login[100], password[100];
	recv(obj.getConnetc(), name, sizeof(name), 0);
	recv(obj.getConnetc(), tel, sizeof(tel), 0);
	recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
	recv(obj.getConnetc(), login, sizeof(login), 0);
	cout << login << endl;
	recv(obj.getConnetc(), password, sizeof(password), 0);
	cout << "###########################################################" << endl;
	cout << "Ваши персональные данные: " << endl;
	cout << "Логин : " << login << endl;
	cout << "Пороль : " << password << endl;
	cout << "Имя : " << name << endl;
	cout << "Телефон :+375" << tel << endl;
	cout << "Паспортные данные : " << pas_info << endl;
	cout << "###########################################################" << endl;
	system("pause");
}

void Menu::MenuBet(Server& obj)
{
	
		char buf[100];
		int ch;
		PrintfBet(obj);
		cout << "Выберите матч " << endl;
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
			cout << "Нет доступных ставок" << endl;
			
		}
		else
		{
			char date[100], bu2[100];
			float cash;
			cout << "Введите сегодняшнюю дату : ";
			cin >> date;
			send(obj.getConnetc(), date, sizeof(date), 0);
			cout << "Введите сумму : ";
			cin >> cash;
			itoa(cash, bu2, 10);
			send(obj.getConnetc(), bu2, sizeof(bu2),0);
			recv(obj.getConnetc(), bu2, sizeof(bu2), 0);
			int cha;
			cha = atoi(bu2);
			if(cha==2)
			{
				cout << "Недостаточно денег на счете " << endl;
			}
			else
			{
				cout << "Ставка принята !" << endl;
				
			}
		}
	
	
}

void Menu::MenuChangeUser(Server& obj)
{
	while(true)
	{
		system("cls");
		cout << "Вы берите нужный параметр >>" << endl;
		cout << "1)Имя" << endl;
		cout << "2)Паспотрные данные " << endl;
		cout << "3)Номер телефона " << endl;
		cout << "4)Логин" << endl;
		cout << "5)Пороль" << endl;
		cout << "6)выход" << endl;
		int ch;
		char buf[100];
		cin >> ch;
		CheckImputSwitch(ch);
		itoa(ch, buf, 10);
		send(obj.getConnetc(), buf, sizeof(buf), 0);
		switch(ch)
		{
		case 1:cout << "Введите новое имя :";
			char name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
				cout << "Имя успешно изменено !!" << endl;
				system("pause");
				system("cls");
				break;
		case 2:cout << "Введите новые паспортные данные :";
			 name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "данные успешно изменены успешно изменено !!" << endl;
			system("pause");
			system("cls");
			break;
		case 3:cout << "Введите новые телефон :+375";
			 name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "данные успешно изменены успешно изменено !!" << endl;
			system("pause");
			system("cls");
			break;
		case 4:cout << "Введите новый Логин : ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "данные успешно изменены успешно изменено !!" << endl;
			system("pause");
			system("cls");
			break;
		case 5:cout << "Введите новый пороль : ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "данные успешно изменены успешно изменено !!" << endl;
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
		cout << "Вы берите нужный параметр >>" << endl;
		cout << "1)Имя" << endl;
		cout << "2)Паспотрные данные " << endl;
		cout << "3)Номер телефона " << endl;
		cout << "4)Логин" << endl;
		cout << "5)Пороль" << endl;
		cout << "6)выход" << endl;
		int ch;
		char buf[100];
		cin >> ch;
		CheckImputSwitch(ch);
		itoa(ch, buf, 10);
		send(obj.getConnetc(), buf, sizeof(buf), 0);
		switch (ch)
		{
		case 1:cout << "Введите новое имя :";
			char name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "Имя успешно изменено !!" << endl;
			system("pause");
			system("cls");
			break;
		case 2:cout << "Введите новые паспортные данные :";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "данные успешно изменены успешно изменено !!" << endl;
			system("pause");
			system("cls");
			break;
		case 3:cout << "Введите новые телефон :+375";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "данные успешно изменены успешно изменено !!" << endl;
			system("pause");
			system("cls");
			break;
		case 4:cout << "Введите новый Логин : ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "данные успешно изменены успешно изменено !!" << endl;
			system("pause");
			system("cls");
			break;
		case 5:cout << "Введите новый пороль : ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "данные успешно изменены успешно изменено !!" << endl;
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
		cout << "1)Регистрация " << endl;
		cout << "2)Авторизация " << endl;
		cout << "3)Войти как администратор" << endl;
		cout << "4)Войти как эксперт " << endl;
		cout << "5)выход" << endl;
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
		cout << "1)Сделать ставку " << endl;
		cout << "2)Пополнить счет " << endl;
		cout << "3)Взять обещанный платеж " << endl;
		cout << "4)Вывод средст" << endl;
		cout << "5)погасить обещанный платеж " << endl;
		cout << "6)Найти нужный матч " << endl;
		cout << "7)вывести параметры аккаунта " << endl;
		cout << "8)изменить параметры аккаунта " << endl;
		cout << "9)Мнение экспертов на лучший матч " << endl;
		cout << "10)Выход" << endl;
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
		cout << "1)Вывод информации о всех пользователях " << endl;
		cout << "2)Вывод информации о всех администраторах " << endl;
		cout << "3)Поиск пользователя " << endl;
		cout << "4)Поиск администртора " << endl;
		cout << "5)Удалить администратора " << endl;
		cout << "6)Удалить пользователя " << endl;
		cout << "7)Регистрация админа" << endl;
		cout << "8)добавить эксперта " << endl;
		cout << "9)Вывод информации о всех экспертах" << endl;
		cout << "10)Удалить эксперта " << endl;
		cout << "11)Поиск эксперта " << endl;
		cout << "12)Выход" << endl;
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
		cout << "1)Добавить прогноз" << endl;
		cout << "2)Вывод параметров аккаунта" << endl;
		cout << "3)Редактирование параметров аккаунта " << endl;
		cout << "4)Добавить оценку матчу " << endl;
		cout << "5)Выход" << endl;
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
			cout << "Ошибка выбора варианта ,повторит попытку !" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}
}
