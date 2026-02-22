#include<iostream>

class Int
{
private:
    int data_;
public:
    Int(int data) : data_(data) {}
    Int(const Int& i) : data_(i.data_) {}
    Int& operator++()
    {
        ++data_;
        return *this;
    }
    Int operator++(int i)
    {
        Int tmp(*this);
        ++data_;
        return tmp;
    }

    friend std::ostream& operator<<(std::ostream& os, const Int& i);
};

std::ostream& operator<<(std::ostream& os, const Int& i)
{
    os<<i.data_;
    return os;
}

int main()
{
    Int x = 3;
    std::cout<<(x++)<<std::endl;
}