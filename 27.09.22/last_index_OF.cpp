#include <iostream>
#include <string>

int last_index(const std::string&, const std::string&);

int main()
{
    std::string s;
    std::string word;
    getline(std::cin, s);
    getline (std::cin, word);
    std::cout << last_index (s,word) << std::endl;

    return 0;
}

int last_index(const std::string& str, const std::string& word)
{
    if (str.size() < word.size())
    {
        return -1;
    }
    int str_e = str.size() - 1;
    int word_e = word.size() - 1;
    for (int i = str_e; i >= 0; --i)
    {
        bool check = true;
        int j = word_e;
        if (str[i] == word[j])
        {
            while ((j >= 0 && i >= 0) && (i >= j))
            {
                if (str[i] != str[j])
                {
                    check = false;
                    break;
                }
                --i;
                --j;
            }
        if (check)
        {
            return ++i;
        }        
        }
    }
    return -1;
}