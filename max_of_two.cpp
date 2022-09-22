#include <iostream>

int main ()
{
    int first;
    int second;
    std::cout << "type first: ";
    std::cin >> first;
    std::cout << "type second: ";
    std::cin >> second;
    
    if (first > second)
    {
        std::cout << first << std::endl;
    }
    else
    {
        std::cout << second << std::endl;
    }
}