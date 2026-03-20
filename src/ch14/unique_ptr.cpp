#include<iostream>
#include<memory>
#include<stdexcept>
class A
{
private:
    int* data_;

public:
    A()
    {
        std::cout<<"자원을 획득함!"<<std::endl;
        data_ = new int[100];
    }

    void some() { std::cout<<  "일반 포인터와 동일하게 사용 가능!"<<std::endl;}

    ~A()
    {
        std::cout<<"자원을 해제함!"<<std::endl;
        delete[] data_;
    }
};

void do_something()
{
    std::unique_ptr<A> pa(new A());
    pa->some();
}

int main()
{
    do_something();
}