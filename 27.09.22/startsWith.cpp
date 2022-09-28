#include <iostream>
#include <string>

bool startsW (const std::string&, const std::string&);

int main ()
{
    std::string s;
    std::string word;
    getline (std::cin, word);
    getline (std::cin, s);
    std::cout << std::boolalpha << startsW (s,word) << std::endl;

    return 0;
}
bool startsW (const std::string& str, const std::string& word)
{
    if (str.size() < word.size())
    {
        return false;
    }
    for (int i = 0; i < word.size(); ++i)
    {
        if (str[i] != word[i])
        {
            return false;
        }
    }
    return true;
}