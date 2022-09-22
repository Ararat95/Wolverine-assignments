#include <iostream>

int main ()
{
    int arr[]{1,54,6,7,5,48,549,54,74,8,9,42};
    int size = sizeof(arr) / sizeof(int);
    int sum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum += arr[i];
    }
    std::cout << sum << std::endl;
    return 0;
}