#pragma once
#include"User.h"
#include"Exception.h"
#include<iostream>
#include<fstream>
#include<string>
static string FileClient = "Info_klient.txt";
static string FileAdmin = "Admin_info.txt";
static string FileBids = "Bids_info.txt";
static string FileExpert = "Expert_info.txt";
static string FileStatistick = "Report.txt";
static string FileStatic = "Statistic.txt";
static string FileReiting = "Reiting.txt";
using namespace std;
class FileCreator
{
public:
	template<class T>
	void read_vector(vector<T>& vec,string nameFile);
	void write_vector_User(vector<Human> &vec);
	void write_vector_Admin(vector<Human>& vec);
	void write_vector_Bids(vector<BIds>& vec);
	void write_vector_Expert(vector<Human>& vec);
	void write_vector_Agancy(vector<Agancy>& vec);
	void write_vector_Reiting(vector<Rating>& vec);
};

template<class T>
inline void FileCreator::read_vector(vector<T>& vec, string nameFile)
{
	try
	{
		ifstream file;
		file.open(nameFile);
		if (file.peek() == EOF)
		{
		}
		else
		{
			while (!file.eof())
			{
				T obj;
				file >> obj;
				vec.push_back(obj);
			}
		}
		file.close();
	}
	catch (Exceptinon& ex)
	{
		ex.messegErrorFile(nameFile);
		exit(1);
	}
}
