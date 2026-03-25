#include<iostream>
#include<cstring>
#include<cctype>
#include<cmath>
#include<stdexcept>
#include<bitset>

int main()
{
    char a = 0xFF;
    char b = 0b11110000;
    char c = a >> 1;
    std::cout<< std::bitset<8>(c);

    return 0;
}