#include <iostream>
#include <string>

std::string rtrim (const std::string&);

int main ()
{
    std::string s;
    getline(std::cin, s);
    std::cout << rtrim(s) << "|\n";

    return 0;
}

std::string rtrim (const std::string& str)
{
    std::string n_str;
    auto it = str.end() - 1;
    while (it >= str.begin() && *it == ' ')
    {
        --it;
    }
    auto n_it = str.begin();
    while (n_it <= it)
    {
        n_str += *n_it;
        ++n_it;
    }
    return n_str;
}