#include<iostream>
#include<string>


void* operator new(std::size_t count)
{
    std::cout<< count <<" 할당"<<std::endl;
    return malloc(count);
}

int main()
{
    std::string s = "somtimes string is very slow";
    std::cout<<"----------------------"<<std::endl;

    std::cout<< s.substr(0,20)<<std::endl<<std::endl;

    std::string_view sv = s;

    std::cout<<sv.substr(0,20)<<std::endl;

    return 0;
}