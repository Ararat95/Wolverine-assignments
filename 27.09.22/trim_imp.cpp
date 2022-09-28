#include <iostream>
#include <string>

std::string trim (const std::string&);

int main ()
{
    std::string line;
    getline(std::cin,line);
    std::cout << '|' << trim(line) << '|' << std::endl;

    return 0;
}

std::string trim (const std::string& str)
{
    std::string n_str;
    auto it_end = str.end() - 1;
    while (it_end >= str.begin() && *it_end == ' ')
    {
        --it_end;
    }
    for (auto it_beg = str.begin(); it_beg <= it_end; ++it_beg)
    {
        if (*it_beg == ' ')
        {
            continue;
        }
        while (it_beg <= it_end)
        {
            n_str += *it_beg;
            ++it_beg;
        }
    }
    return n_str;
}