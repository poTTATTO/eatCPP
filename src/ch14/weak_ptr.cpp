#include<iostream>
#include<memory>

class A
{
private:
    int* data;
    // shared_ptr 대신 weak_ptr를 사용한다.
    // weak_ptr는 객체를 가리킺만 참조 횟수(use_count)를 늘리지 않는다. 
    std::weak_ptr<A> other;
public:
    A()
    {
        data = new int[100];
        std::cout<<"자원을 획득함!"<<std::endl;
    }

    ~A()
    {
        std::cout<<"소멸자 호출 !"<<std::endl;
        delete[] data;
    }

    void set_other(std::shared_ptr<A> o)
    {
        other = o;
    }

    void accessOther()
    {
        if(std::shared_ptr<A> shared_other = other.lock())
        {
            std::cout<<"상대 객체에 접근 성공"<<std::endl;
        }
        else
        {
            std::cout<<"상대 객체가 이미 소멸됨"<<std::endl;
        }
    }
};

int main()
{
    std::shared_ptr<A> pa1 = std::make_shared<A>();
    std::shared_ptr<A> pa2 = std::make_shared<A>();

    pa1->set_other(pa2);
    pa2->set_other(pa1);

    return 0;
}