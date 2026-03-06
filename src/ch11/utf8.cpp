#include<iostream>
#include<string>


int main()
{
    std::string str = u8"이건 UTF-8 문자열 입니다";

    size_t i = 0;
    size_t len = 0;

    while(i < str.size())
    {
        if((str[i] & 0b11111000) == 0b11110000)
        {
            len = 4;
        }
        else if((str[i] & 0b11110000) == 0b11100000)
        {
            len = 3;
        }
        else if((str[i] & 0b11100000) == 0b11000000)
        {
            len = 2;
        }
        else if((str[i] & 0b10000000) == 0b00000000)
        {
            len = 1;
        }else
        {
            std::cout<<"이상한 문자 발견"<<std::endl;
            len = 1;
        }

        std::cout<<str.substr(i, len)<<std::endl;

        i += len;
    }


    return 0;
}