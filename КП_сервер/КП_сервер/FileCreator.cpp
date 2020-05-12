#include "FileCreator.h"


//void FileCreator::read_vector_Agency(vector<Agancy>& vec)
//{
//	ifstream file;
//	file.open(FileStatic);
//	if (file.peek() == EOF)
//	{
//	}
//	else
//	{
//		while (!file.eof())
//		{
//			Agancy obj;
//			file >> obj;
//			vec.push_back(obj);
//		}
//	}
//	file.close();
//}



void FileCreator::write_vector_User(vector<Human> &vec)
{
	int check = 0;
	ofstream file(FileClient);
	for (vector<Human>::iterator i = vec.begin(); i != vec.end(); i++)
	{
		if (check == vec.size() - 1)
		{
			file << i->getName() << "\t" << i->getTel() << "\t" << i->getPas_info() << "\t" << i->getlogin() << "\t" << i->getPassword() << "\t" << i->getCash() << "\t" << i->getContribution();
		}
		else
		{
			file << i->getName() << "\t" << i->getTel() << "\t" << i->getPas_info() << "\t" << i->getlogin() << "\t" << i->getPassword() << "\t" << i->getCash() << "\t" << i->getContribution() << endl;
		}
		check++;
	}
	file.close();
}

void FileCreator::write_vector_Admin(vector<Human>& vec)
{
	ofstream file(FileAdmin);
	int check = 0;
	for (vector<Human>::iterator i = vec.begin(); i != vec.end(); i++)
	{

		if (check == vec.size() - 1)
		{
			file << i->getName() << "\t" << i->getTel() << "\t" << i->getPas_info() << "\t" << i->getlogin() << "\t" << i->getPassword() << "\t" << i->getCash();
		}
		else
		{
			file << i->getName() << "\t" << i->getTel() << "\t" << i->getPas_info() << "\t" << i->getlogin() << "\t" << i->getPassword() << "\t" << i->getCash() << endl;
		}
		check++;
	}
	file.close();
}

void FileCreator::write_vector_Bids(vector<BIds>& vec)
{
	ofstream file(FileBids);
	int check = 0;
	for (vector<BIds>::iterator i = vec.begin(); i != vec.end(); i++)
	{

		if (check == vec.size() - 1)
		{
			file << i->getFirstNamefootbalTeam ()<< "\t" << i->getSecondNamefootbalTeam ()<< "\t" << i->getFirstcofficient()<< "\t" << i->getSecondcofficient ()<< "\t" << i->getpercentWinfirst ()<< "\t" << i->getprecentWinsecond() << "\t" << i->getNameExpert ()<< "\t" << i->getLoginExpert();
		}
		else
		{
			file << i->getFirstNamefootbalTeam ()<< "\t" << i->getSecondNamefootbalTeam() << "\t" << i->getFirstcofficient ()<< "\t" << i->getSecondcofficient() << "\t" << i->getpercentWinfirst() << "\t" << i->getprecentWinsecond() << "\t" << i->getNameExpert ()<< "\t" << i->getLoginExpert() << endl;
		}
		check++;
	}
	file.close();
}

void FileCreator::write_vector_Expert(vector<Human>& vec)
{
	ofstream file(FileExpert);
	int check = 0;
	for (vector<Human>::iterator i = vec.begin(); i != vec.end(); i++)
	{

		if (check == vec.size() - 1)
		{
			file << i->getName() << "\t" << i->getTel() << "\t" << i->getPas_info() << "\t" << i->getlogin() << "\t" << i->getPassword() << "\t" << i->getCash();
		}
		else
		{
			file << i->getName() << "\t" << i->getTel() << "\t" << i->getPas_info() << "\t" << i->getlogin() << "\t" << i->getPassword() << "\t" << i->getCash() << endl;
		}
		check++;
	}
	file.close();
}

void FileCreator::write_vector_Agancy(vector<Agancy>& vec)
{
	ofstream file(FileStatic);
	int check = 0;
	for (vector<Agancy>::iterator i = vec.begin(); i != vec.end(); i++)
	{

		if (check == vec.size() - 1)
		{
			file << i->getDate() << "\t" << i->getName() << "\t" << i->getPas_info() << i->getTel() << "\t"<< "\t" << i->getlogin() << "\t" << i->getFirstNamefootbalTeam() << "\t"<<i->getFirstcofficient()<<"\t"<<i->getpercentWinfirst()<<"\t"<<i->getSecondNamefootbalTeam()<<"\t"<<i->getSecondcofficient()<<"\t"<<i->getpercentWinfirst()<<"\t"<<i->getCahs1();
		}
		else
		{
			file << i->getDate() << "\t" << i->getName() << "\t" << i->getPas_info() << i->getTel() << "\t" << "\t" << i->getlogin() << "\t" << i->getFirstNamefootbalTeam() << "\t" << i->getFirstcofficient() << "\t" << i->getpercentWinfirst() << "\t" << i->getSecondNamefootbalTeam() << "\t" << i->getSecondcofficient() << "\t" << i->getpercentWinfirst() << "\t" << i->getCahs1() << endl;
		}
		check++;
	}
	file.close();
}

void FileCreator::write_vector_Reiting(vector<Rating>& vec)
{
	ofstream file(FileReiting);
		int check = 0;
		for (vector<Rating>::iterator i = vec.begin(); i != vec.end(); i++)
		{

			if (check == vec.size() - 1)
			{
				file << i->getRating()<<"\t"<<i->getNameExpert()<<"\t"<<i->getPosition();
			}
			else
			{
				file << i->getRating() << "\t" << i->getNameExpert() << "\t" << i->getPosition() << endl;
			}
			check++;
		}
		file.close();

}

