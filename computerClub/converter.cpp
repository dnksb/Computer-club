#include "converter.h"

System::String^ Conv::ToSystemString(std::string str)
{
	System::String^ tmp_str = "";
	for (int i = 0; i < str.length(); i++)
		tmp_str += System::Convert::ToChar(str[i]);
	return tmp_str;
}

std::string Conv::ToStdString(System::String^ str)
{
	std::string tmp_str = "";
	for each (char ch in str) tmp_str += ch;
	return tmp_str;
}

System::Drawing::Color^ Conv::ToColor(System::Drawing::Color color)
{
	return % color;
}
