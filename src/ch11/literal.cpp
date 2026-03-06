#include<iostream>
#include<string>

using namespace std::literals;

int main()
{
    auto str1 = "hello";

    auto str2 = "hello"s;

    std::cout<<str2;

    return 0;
}