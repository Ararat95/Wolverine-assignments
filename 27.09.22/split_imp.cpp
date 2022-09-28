#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split (const std::string&, const std::string&);

int main ()
{
    std::vector < std::string> vec;
    std::string line;
    std::string symbol;
    std::cout << "please type symbols: ";
    getline (std::cin,symbol);
    std::cout << "please input text: ";
    getline(std::cin,line);
    vec = split (line,symbol);
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << std::endl;
    }
}

std::vector <std::string> split (const std::string& str, const std::string& symbol)
{
    std::string tmp;
    std::vector <std::string> v;
    for (auto it = str.begin(); it <= str.end(); ++it)
    {
         bool check = true;
        for (auto it1 = symbol.begin(); it1 < symbol.end(); ++it1)
        {
            if (*it == *it1 || it == str.end())
            {
                check = false;
                // if (!tmp.empty())
                // {
                    v.push_back(tmp);
                    tmp.clear();
                //}

                break;
            }
        }
        if(check)
        {
            tmp += *it;
        }
    }
    return v;
}