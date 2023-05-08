#include "language.h"

Language::Language(const std::string lang)
{
	set_lang(lang);
}

void Language::set_lang(const std::string lang)
{
	if (lang == "rus")
	{
		//TODO
		//тут открывается файл и передается в update
	}
	if (lang == "eng")
	{
		
	}
	else
	{

	}
}

void Language::update(const std::string lang)
{
}
