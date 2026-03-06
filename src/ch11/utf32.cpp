#include<iostream>
#include<string>

int main()
{
    std::u32string u32_str = U"이건 UTF-32 문자열 입니다";
    std::string str = "이건 UTF-32 문자열 입니다";
    // std::wstring w_str = "이건 UTF-32 문자열 입니다";

    std::cout<<u32_str.size()<<std::endl;
    std::cout<<str.size()<<std::endl;
    return 0;
}