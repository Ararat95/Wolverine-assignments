#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> split (const std::string&);

int main ()
{
    std::string s = "  mov r1,  2";
    std::vector<std::string> vec;
    vec = split(s);
}

std::vector <std::string> split (const std::string& s)
{
    std::vector<std::string> vec;
    std::string tmp;
    // VERSION 1
    /*int i = 0;   
    while(s[i] == ' ' && i < s.size())
    {
        ++i;
    }
    while(s[i] != ' ' && i < s.size())
    {
        tmp += s[i];
        ++i;
    }
    vec.push_back(tmp);
    tmp.clear();
    while (s[i] == ' ' && i < s.size())
    {
        ++i;
    }
    while(s[i] != ',' && i < s.size())
    {
        tmp += s[i];
        ++i;
    }
    vec.push_back(tmp);
    tmp.clear();
    while ((s[i] == ' ' || s[i] == ',') && i < s.size())
    {
        ++i;
    }
    while (s[i] != ' ' && i < s.size())
    {
        tmp += s[i];
        ++i;
    }
    vec.push_back(tmp);
   */
    // VERSION 2  RESULT IS THE SAME
    for (int i = 0; i < s.size(); ++i)
    {
        if(s[i] == ' ' || s[i] == ',')
        {
            continue;
        }
        while (s[i] != ' ' && s[i] != ',' && i < s.size())
        {
            tmp+= s[i];
            ++i;
        }
        vec.push_back(tmp);
        tmp.clear();
    }
    
    return vec;

}