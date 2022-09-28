#include <iostream>
#include <string>

std::string replace_all(const std::string&, const std::string&, const std::string&);

int main()
{
    std::string src = "temp";
    std::string dest = "atmpth of tmp is tmproarry";
    std::cout << dest << std::endl;
    std::cout << replace_all(dest,"tmp",src) << std::endl;

    return 0;
}

std::string replace_all(const std::string& dest, const std::string& sym, const std::string& src)
{
    int dest_size = dest.size();
    int sym_size = sym.size();
    bool check = true;
    std::string tmp;
    for (int i = 0; i <= dest_size; ++i)
    {
        check = true;
        for (int j = 0; j < sym_size; ++j)
        {
            if (dest[i + j] != sym[j])
            {
                check = false;
                break;
            }
        }
        if (check)
        {
            tmp += src;
            i += sym.size() - 1;
        }
        else
        {
            tmp += dest[i];
        }
    }
    return tmp;
}