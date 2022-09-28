#include <iostream>
#include <string>

std::string to_upper (const std::string&);

int main ()
{
    std::string s = "SJGNSLDG";
    std::cout << to_upper(s) << std::endl;

    return 0;
}

std::string to_upper (const std::string& str)
{
    std::string r_str;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            r_str.push_back(str[i] + 32);
            continue;
        }
        r_str.push_back(str[i]);
    }
    return r_str;
}