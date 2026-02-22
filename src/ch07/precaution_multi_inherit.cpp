#if 0
#include<iostream>

class A
{
public:
    int a;
};

class B
{
public: 
    int a;
};

class C : public B, public A
{
public:
    int c;
};

int main()
{
    C c;
    c.a = 3;
}
#endif

class Human
{
    // ...
};

class HandsomeHuman : public virtual Human
{
    //...
};

class SmaartHuman : public  virtual Human
{
    //...
};

class Me : public HandsomeHuman, public SmaartHuman
{
    //...
};