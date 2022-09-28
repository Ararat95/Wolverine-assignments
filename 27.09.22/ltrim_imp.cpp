#include <iostream>
#include <string>

std::string ltrim (const std::string&);

int main ()
{
    std::string s;
    getline(std::cin, s);
    std::cout <<  '|' << ltrim(s) << std::endl;

    return 0;
}

std::string ltrim (const std::string& str)
{
    std::string n_str;
    for (auto it = str.begin(); it < str.end(); ++it)
    {
        if (*it == ' ')
        {
            continue;
        }
        while (it < str.end())
        {
            n_str += *it;
            ++it;
        }
    }
    return n_str;
}