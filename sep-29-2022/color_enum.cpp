#include "class_enum.h"

int main()
{
    // there is a unique object named enum_class that you should use in your future actions
    // and given an enum with type Color
    My_enum enum_class;
    std::string s = "brown";
    enum_class.print_enum(s);
    enum_class.print_enum(2);
    My_enum* Enum = new My_enum;
    Enum->print_enum("black");
    Enum->print_enum(4);   
    delete Enum;
    return 0;
}
