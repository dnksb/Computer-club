#include "local_save.h"

Save::Save(std::string value)
{
    file = std::fstream();
    file.open(value);
    if (!file.is_open()) { return; }
    
    file >> name;
    file >> theme;
    file >> lang;
    file >> price;
    file >> time_start;
}

Save::~Save()
{
}

void Save::SaveData(std::string value)
{
    file = std::fstream();
    file.open(value);
    if (!file.is_open()) { return; }

    file << name << "\n";
    file << theme << "\n";
    file << lang << "\n";
    file << price << "\n";
    file << time_start << "\n";
}

std::string Save::Name()
{
    return name;
}

std::string Save::Lang()
{
    return lang;
}

std::string Save::Theme()
{
    return theme;
}

int Save::Price()
{
    return price;
}

std::string Save::TimeStart()
{
    return time_start;
}

void Save::Name(std::string value)
{
    name = value;
}

void Save::Lang(std::string value)
{
    lang = value;
}

void Save::Theme(std::string value)
{
    theme = value;
}

void Save::Price(int value)
{
    price = value;
}

void Save::TimeStart(std::string value)
{
    time_start = value;
}
