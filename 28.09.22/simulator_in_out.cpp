#include <iostream>
#include <string>
#include <vector>
#include <fstream>

void start_of_prog();
std::vector<std::string> file_reader();
std::vector<std::string> parser (const std::string&);
void file_writer(const std::vector<std::string>&);

int main()
{
    start_of_prog();
}

void start_of_prog()
{
    std::vector<std::string> vec = file_reader();
    file_writer(vec);
}

std::vector<std::string> file_reader()
{
    std::fstream file;
    std::string line;
    std::vector<std::string> vec;
    std::vector<std::string> parsed;
    file.open("Fasm.txt");
    if (file.is_open())
    {
        while (!file.eof())
        {
            std::getline(file,line);
            if (line.empty())
            {
                continue;
            }
            vec = parser(line);
            parsed.insert(parsed.end(),vec.begin(),vec.end());
        }
    }
    else
    {
        std::cout << "File is not open\n";
    }
    file.close();
    return parsed;
}

void file_writer(const std::vector<std::string>& vec)
{
    std::fstream file;
    file.open("Parsed.txt",std::ios::app);
    if (file.is_open())
    {
        auto it = vec.begin();
        while (it != vec.end())
        {
            file << *it << '\n';
            ++it;
        }
    }
    else
    {
        std::cout << "file is not open: \n";
    }
    file.close();
}

std::vector<std::string> parser(const std::string& line)
{
    std::vector<std::string> vec;
    std::string tmp;
    for (int i = 0; i < line.size(); ++i)
    {
        if(line[i] == ' ' || line[i] == ',')
        {
            continue;
        }
        while (line[i] != ' ' && line[i] != ',' && i < line.size())
        {
            tmp+= line[i];
            ++i;
        }
        vec.push_back(tmp);
        tmp.clear();
    }
    
    return vec;
}