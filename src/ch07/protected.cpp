#include<iostream>

class Base
{
protected:
    std::string parent_string_;
public:
    Base() :  parent_string_("기반"){std::cout<<"기반 클래스"<<std::endl;}

    void what(){std::cout<<parent_string_<<std::endl;}
};

class Derived : public Base
{
private:
    std::string child_string_;

public:
    Derived() : child_string_("파생"), Base()
    {
        std::cout<<"파생 클래스"<<std::endl;
        parent_string_ = "바꾸기";
    }

    void what() { std::cout<<child_string_<<std::endl;}
};