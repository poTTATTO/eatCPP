#include<iostream>
#include<cstring>
#include<cctype>
#include<cmath>
#include<stdexcept>

double getNumber(const char* number, int from, int to)
{
    if(!number)
        throw std::runtime_error("string error");
    if(from > to)
        throw std::runtime_error("range errror");
    
    bool minus(false);
    if(number[from] == '-')
    {
        minus = true;
        from++;
    }
    else if(number[from] == '+')
        from++;
    
    double num(0.0);
    double decimal(1.0);
    int div_cnt(0);
    bool is_integer(true);

    for(int i=from; i <= to; i++)
    {
        if(isdigit(number[i]))
        {
            num *= 10.0;
            num += (number[i] - '0');

            if(!is_integer)
                div_cnt++;
        }else if(number[i] == '.')
        {
            if(!is_integer)
                throw std::runtime_error(". 두개 찍힘");
            is_integer = false;
        }
        else
            break;
    }
    
    num /= pow(10, div_cnt);

    return !minus ? num : -num;
}

int main()
{
    try
    {
        const char* number = "-2.23421";
        std::cout<<getNumber(number, 0, strlen(number) -1 );
    }
    catch(const std::exception& e)
    {
        std::cerr<<"Error : "<<e.what()<<std::endl;
    }
    
    return 0;
}