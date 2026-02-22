#include<iostream>

class Parent
{

public:
    Parent() { std::cout<<"Parent 생성자 호출"<<std::endl;}
    ~Parent() { std::cout<<"Parent 소멸자 호출"<<std::endl;}

};

class Child : public Parent
{
public:
    Child() : Parent() { std::cout<< "Child 생성자 호출"<<std::endl;}
    ~Child() { std::cout<<"Child 소멸자 호출"<<std::endl;}
};

int main()
{
    std::cout<<"--- 평범한 Child 만들었을 때 ---"<<std::endl;
    {
        Child c;
        //Parent 생성자 호출
        //Child 생성자 호출
        //Child 소멸자 호출
        //Parent 소멸자 호출
    }

    std::cout<<"--- Parent 포인터로 Child 가리켰을 때 ---"<<std::endl;
    {
        Parent* p = new Child();
        delete p;
        //Parent 생성자 호출
        //Child생성자 호출
        //Child소멸자 호출
        //Parent 소멸자 호출
    }

    return 0;

}