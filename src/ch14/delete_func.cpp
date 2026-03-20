#include<iostream>

class A
{
public:
    A(int a){};
    A(const A& a) = delete;
};

int main()
{
    A a(3);
    // A b(a);
}