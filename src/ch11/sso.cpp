#include<iostream>
#include<string>

//new를 전역 함수로 정의하면 모든 new 연산자를 오버로딩함
void* operator new(std::size_t count)
{
    std::cout<< count << "byte 할당"<<std::endl;
    return malloc(count);
}