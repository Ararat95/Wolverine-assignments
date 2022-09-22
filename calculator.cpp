#include <iostream>
#include <map>

void summary (int first, int second) {std::cout <<first << ' ' << '+' << ' ' << second << ' ' << '=' << ' ' << first + second << std::endl;}
void substruct (int first, int second) {std::cout << first << ' ' << '-' << ' ' << second << ' ' << '=' << ' ' << first - second << std::endl;}
void multiple (int first, int second) {std::cout << first << ' ' << '*' << ' ' << second << ' ' << '=' << ' ' << first * second << std::endl;}
void divide (int first, int second) {std::cout << first << ' ' << '/' << ' ' << second << ' ' << '=' << ' ' << first / second << std::endl;}
void percent (int first, int second) {std::cout << first << ' ' << '%' << ' ' << second << ' ' << '=' << ' ' << (first * second) / 100 << std::endl;}

int main ()
{
    char arit_sym;
    int first;
    int second;
    std::map<char,void(*)(int,int)> calc;
    calc['+'] = summary;
    calc['-'] = substruct;
    calc['*'] = multiple;
    calc['/'] = divide;
    calc['%'] = percent;
    void(*f)(int,int);
    
        std::cout << "type your condition as follows: first num 'arithmetic symbol' second num" << std::endl;
        std::cin >> first;
        std::cin >> arit_sym;
        std::cin >> second;
        switch (arit_sym)
        {
            case '+': f = calc['+']; (*f)(first,second); break;
            case '-': f = calc['-']; (*f)(first,second); break;
            case '*': f = calc['*']; (*f)(first,second); break;
            case '/': f = calc['/']; (*f)(first,second); break;
            case '%': f = calc['%']; (*f)(first,second); break;
        }
    

    return 0;
}