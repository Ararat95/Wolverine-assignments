#include "class_enum.h"

void My_enum::fill_the_maps()
{
    enum_int[Color::red] = "RED";
    enum_int[Color::green] = "GREEN";
    enum_int[Color::blue] = "BLUE";
    enum_int[Color::purple] = "PURPLE";
    enum_int[Color::brown] = "BROWN";
    enum_int[Color::black] = "BLACK";
    enum_int[Color::white] = "WHITE";

    enum_str["red"] = Color::red;
    enum_str["green"] = Color::green;
    enum_str["blue"] = Color::blue;
    enum_str["purple"] = Color::purple;
    enum_str["brown"] = Color::brown;
    enum_str["black"] = Color::black;
    enum_str["white"] = Color::white;
}

Color My_enum::enum_parsing(const std::string& str)
{
    if (!enum_str.count(str))
    {
        throw std::invalid_argument("Value is not found\n");
    }
    return enum_str[str];
}

std::string My_enum::enum_parsing_int(int num)
{
    color = Color(num);
    if (!enum_int.count(color))
    {
        throw std::invalid_argument("Value is not found\n");
    }
    return enum_int[color];
}

void My_enum::print_enum(const std::string& str)
{
    std::cout << "your Enum color index is: " << enum_str[str] << std::endl;
}

void My_enum::print_enum(int num)
{
    color = Color(num);
    std::cout << "your Enum color is: " << enum_int[color] << std::endl;
}