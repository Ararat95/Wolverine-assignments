#ifndef CLASS_ENUM_H
#define CLASS_ENUM_H

#include <iostream>
#include <map>
#include <string>

enum Color:int {red, green, blue, purple, brown, black, white};

class My_enum
{
public:
    My_enum() {fill_the_maps();};
public:
    Color enum_parsing(const std::string&); 
    std::string enum_parsing_int(int);
    void print_enum(int);
    void print_enum(const std::string&);
private:
    void fill_the_maps();
private:
    Color color;
    std::map<std::string,enum::Color> enum_str;
    std::map<enum::Color,std::string> enum_int;
};
#endif // CLASS_ENUM_H