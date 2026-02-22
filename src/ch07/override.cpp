#include<iostream>

class Base
{
private:
    std::string s_;
public:
    
    Base() : s_("기반")
    {
        std::cout<<"Base"<<std::endl;
    }

    virtual void what()
    {
        std::cout<<s_<<std::endl;
    }

    virtual ~Base(){}
};

class Derived : public Base
{
private:
    std::string s_;
public:
    Derived() : s_("파생"), Base()
    {
        std::cout<<"Derived"<<std::endl;
    }

    void what() override
    {
        std::cout<<s_<<std::endl;
    }

    ~Derived() override{}
};

int main()
{
    Base p;
    Derived c;
    Base* p_p = &p;
    Base* p_c = &c;

    p_c->what();

    return 0;


}