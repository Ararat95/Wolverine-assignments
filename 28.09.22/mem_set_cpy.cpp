#include <iostream>

char* memset(void*, char, size_t);
char* memcpy(void*, void*,size_t);

int main()
{

    char arr[] = "abcdefg";
    char arr2[] = "hijklmnop";
    std::cout << arr << '|' << arr2 << '\n';
    std::cout << *memset(arr, 'a', 3) << '|' << *memcpy(arr,arr2,6) << '\n';
    std::cout << arr << '|' << arr2 << '\n';

    return 0;
}

char* memset(void* dest, char sym, size_t size)
{
    char* ptr = (char*)dest;
    for (int i = 0; i < size; ++i)
    {
        if (*ptr == '\0')
        {
            break;
        }
        *ptr = sym;
        ++ptr;
    }
    return ptr;
}
char* memcpy(void* src, void* dest, size_t size)
{
    char* src_ptr = (char*)src;
    char* dest_ptr = (char*)dest;

    for (int i = 0; i < size; ++i)
    {
        if (*src_ptr == '\0' || *dest_ptr == '\0')
        {
            break;
        }
        *dest_ptr = *src_ptr;
        ++dest_ptr;
        ++src_ptr;
    }
    return dest_ptr;
}