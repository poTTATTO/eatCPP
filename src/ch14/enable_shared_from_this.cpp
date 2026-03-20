#include<iostream>
#include<memory>

class A : public std::enable_shared_from_this<A>
{
private:
    int* data;
    std::shared_ptr<A> other;
public:
    A()
    {
        data = new int[100];
        std::cout<<"자원을 획득함!"<<std::endl;
    }

    ~A()
    {
        std::cout<<"소멸자 호출!"<<std::endl;
        delete[] data;
    }

    std::shared_ptr<A> get_shared_ptr() { return shared_from_this();}
    void set_other(std::shared_ptr<A> o) { other = o;}
};

int main()
{
    std::shared_ptr<A> pa1 = std::make_shared<A>();
    std::shared_ptr<A> pa2 =  std::make_shared<A>();

    pa1->set_other(pa2);
    pa2->set_other(pa1);

    return 0;   
}