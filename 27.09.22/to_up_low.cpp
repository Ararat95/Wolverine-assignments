#include <iostream>
#include <string>

std::string to_up_low(const std::string&);

int main()
{
    std::string line;
    getline(std::cin, line);
    std::cout << to_up_low(line) << std::endl;

    return 0;
}

std::string to_up_low(const std::string& str)
{
    std::string tmp;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] <= 'z' && str[i] >= 'a')
        {
            tmp.push_back(str[i] - 32);
            continue;
        }
        else if (str[i] <= 'Z' && str[i] >= 'A')
        {
            tmp.push_back(str[i] + 32);
            continue;
        }
        tmp.push_back(str[i]);
    }
    return tmp;
}