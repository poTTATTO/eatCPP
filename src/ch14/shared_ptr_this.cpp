#include<iostream>
#include<memory>

class A
{
private:
    int* data;

public:
    A()
    {
        data = new int[100];
        std::cout<<"자원을 획득함 !"<<std::endl;
    }

    ~A()
    {
        std::cout<<"소멸자 호출 !"<<std::endl;
        delete[] data;
    }

    std::shared_ptr<A> get_shared_ptr() { return std::shared_ptr<A>(this);}
};

int main()
{
    std::shared_ptr<A> pa1 = std::make_shared<A>();
    std::shared_ptr<A> pa2 = pa1->get_shared_ptr();

    std::cout<<pa1.use_count()<<std::endl;
    std::cout<<pa2.use_count()<<std::endl;

    return 0;
}