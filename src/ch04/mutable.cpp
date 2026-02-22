#include<iostream>

class A
{

private:
    mutable int x_;
    int y_;
public:
    A(){}
    A(int x) : x_(x){}
    void doSome(int x) const{
        this->x_ = x;
    }
    void print() const{
        std::cout<<this->x_<<std::endl;
    }
};

int main()
{
    A a();
    a.doSome(3);
    a.print();

    return 0;
}