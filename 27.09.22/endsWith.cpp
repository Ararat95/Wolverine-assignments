#include <iostream>
#include <string>

bool endsW (const std::string&, const std::string&);

int main ()
{
    std::string s;
    std::string word;
    getline (std::cin, word);
    getline (std::cin, s);
    std::cout << std::boolalpha << endsW (s,word) << std::endl;

    return 0;
}
bool endsW (const std::string& str, const std::string& word)
{
    if (str.size() < word.size())
    {
        return false;
    }
    auto it = str.end() - word.size();
    for (int i = 0; i < word.size(); ++i)
    {
        if (*it != word[i])
        {
            return false;
        }
        ++it;
    }
    return true;
}