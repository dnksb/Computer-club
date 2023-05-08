#pragma once
#ifndef THEME_H
#define THEME_H
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>


class Theme
{
	std::string form_back_ground;
	std::string button_back_ground;
	std::string menu_back_ground;
	std::string text_back_ground;
	std::string text_color;
	std::string border;
public:
	Theme(std::string);
	std::string FormBackGround();
	std::string ButtonBackGround();
	std::string MenuBackGround();
	std::string TextBackGround();
	std::string TextColor();
	std::string Border();

	void FormBackGround(std::string);
	void ButtonBackGround(std::string);
	void MenuBackGround(std::string);
	void TextBackGround(std::string);
	void TextColor(std::string);
	void Border(std::string);
};

#endif
