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
    file >> time_end;
    file >> tables;
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
    file << time_end << "\n";
    file << tables << "\n";
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

std::string Save::TimeEnd()
{
    return time_end;
}

int Save::Tables()
{
    return tables;
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

void Save::TimeEnd(std::string value)
{
    time_end = value;
}

void Save::Tables(int value)
{
    tables = value;
}
