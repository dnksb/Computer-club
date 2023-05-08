#include "theme.h"

Theme::Theme(std::string value)
{
    auto file = std::ifstream(value);
    if (!file.is_open()) return;

    file >> form_back_ground;
    file >> button_back_ground;
    file >> menu_back_ground;
    file >> text_back_ground;
    file >> text_color;
    file >> border;
    file.close();
}

std::string Theme::FormBackGround()
{
    return form_back_ground;
}

std::string Theme::ButtonBackGround()
{
    return button_back_ground;
}

std::string Theme::MenuBackGround()
{
    return menu_back_ground;
}

std::string Theme::TextBackGround()
{
    return text_back_ground;
}

std::string Theme::TextColor()
{
    return text_color;
}

std::string Theme::Border()
{
    return border;
}

void Theme::FormBackGround(std::string value)
{
    form_back_ground = value;
}

void Theme::ButtonBackGround(std::string value)
{
    button_back_ground = value;
}

void Theme::MenuBackGround(std::string value)
{
    menu_back_ground = value;
}

void Theme::TextBackGround(std::string value)
{
    text_back_ground = value;
}

void Theme::TextColor(std::string value)
{
    text_color = value;
}

void Theme::Border(std::string value)
{
    border = value;
}
