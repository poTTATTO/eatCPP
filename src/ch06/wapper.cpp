#include<iostream>

class Int
{

private:
    int data_;

public:
    Int(int data);
    Int(const Int& i);
    operator int();
};

Int::operator int()
{
    return data_;
}
Int::Int(int data) : data_(data) {}

Int::Int(const Int& i) : data_(i.data_) {}

int main()
{
    Int x = 3;

    int y = x + 4;

    std::cout<<y<<std::endl;
    return 0;
}