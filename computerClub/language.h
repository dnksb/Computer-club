#pragma once
#ifndef LANGUAGE
#define LANGUAGE
#include <string>

struct Menu
{
	std::string file;
	std::string imp;
	std::string exp;
	std::string save;
	std::string report;
	std::string settings;
	std::string lang;
	std::string rus;
	std::string eng;
	std::string time;
	std::string price;
	std::string change;
	std::string login;
	std::string theme;
	std::string light;
	std::string dark;
	std::string help;
};
struct Table 
{
	std::string time;
	std::string type;
	std::string client;
	std::string computer;
};
struct MainForm
{
	std::string date;
	std::string user;
	std::string time;
	std::string type;
	std::string client;
	std::string computer;
	std::string add;
	std::string finish;
};

class Language
{
private:
	Menu menu;
	Table table;
	MainForm form;
public:
	Language(const std::string);
	void set_lang(const std::string);
	void update(const std::string);
};

#endif // LANGUAGE