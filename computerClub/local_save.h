#pragma once
#ifndef LOCALSAVE
#define LOCALSAVE
#include <iostream>
#include <string>
#include <fstream>
#include <string.h>

class Save
{
	std::fstream file;
	std::string name;
	std::string lang;
	std::string theme;
	int price;
	std::string time_start;
public:
	Save(std::string);
	~Save();
	void SaveData(std::string);

	std::string Name();
	std::string Lang();
	std::string Theme();
	int Price();
	std::string TimeStart();

	void Name(std::string);
	void Lang(std::string);
	void Theme(std::string);
	void Price(int);
	void TimeStart(std::string);
};

#endif // !LOCALSAVE
