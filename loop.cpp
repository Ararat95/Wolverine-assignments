#include <iostream>

int main ()
{
    int n;
    int i = 0;
    std::cout << "Type the number: ";
    std::cin >> n;
    label:
        std::cout << i++ << '|';
        if (i <= n)
        {
            goto label;
        }
        std::cout << std::endl;

    return 0;
}