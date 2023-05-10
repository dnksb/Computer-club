#pragma once
#include <string>
#include <fstream>

class Lang
{
	std::ifstream file_source;

public:
	std::string file;
	std::string imp;
	std::string exp;
	std::string save;
	std::string report;
	std::string settings;
	std::string lang;
	std::string rus;
	std::string eng;
	std::string work_time;
	std::string price;
	std::string change;
	std::string login;
	std::string theme;
	std::string light;
	std::string dark;
	std::string help;
	std::string view;

	std::string data_time;
	std::string data_type;
	std::string data_client;
	std::string data_computer;

	std::string date;
	std::string user;
	std::string time;
	std::string type;
	std::string client;
	std::string computer;
	std::string add;
	std::string finish;

	std::string CAME;
	std::string WAIT;
	std::string SIT;
	std::string LEAVE;

	std::string error;

	std::string Set;
	std::string time_start;
	std::string time_end;


	Lang(std::string);
};

