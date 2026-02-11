#include<iostream>
#include<cstring>

class MyString
{

private:
    char* str_;
    int len_;

public:
    MyString(const MyString& ms);
    MyString(const char* str);
    ~MyString();

    char* getStr() const;

    int getLen() const;
    char* addString(const MyString& ms);
    bool isEqual(const MyString& ms);
    char* find(const MyString& ms);
    int compare(const MyString& ms);
};

int MyString::compare(const MyString& ms)
{
    int result = strcmp(str_, ms.getStr());

    return result;
}
char* MyString::find(const MyString& ms)
{
    char* ptr = strstr(str_, ms.getStr());
    return ptr;
}
bool MyString::isEqual(const MyString& ms)
{
    int result = strcmp(str_, ms.getStr());
    if(!result) return true;
    else return false;
}

char* MyString::addString(const MyString& ms)
{
    len_ = len_ + ms.getLen();
    char* tmp = new char[len_ + 1];
    strcpy(tmp, str_);
    strcat(tmp, ms.getStr());
    delete[] str_;
    str_ = tmp;

    return str_;
}

int MyString::getLen() const
{
    return len_;
}

char* MyString::getStr() const
{
    return str_;
}

MyString::MyString(const char* str)
{
    len_ = strlen(str);
    str_ = new char[len_ + 1];
    strcpy(str_, str);
}

MyString::MyString(const MyString& ms)
{
    len_ = strlen(ms.getStr());
    str_ = new char[len_ + 1];
    strcpy(str_, ms.getStr());
}

MyString::~MyString()
{
    if(str_) delete[] str_;
}

int main()
{
    MyString s1("hello");
    std::cout<<"s1 : "<<s1.getStr()<<std::endl;
    std::cout<<"s1 len : "<<s1.getLen()<<std::endl;

    MyString s2("world!");
    s1.addString(s2);
    std::cout<<"s1 + s2 : "<<s1.getStr()<<std::endl;

    MyString s3("world");
    for(int i=0; i<s3.getLen(); i++){
        char* find = s1.find(s3);
        if(!find)
            break;
        std::cout<<find[i];
    }
    std::cout<<std::endl;
    MyString s4("world");

    if(s3.isEqual(s4))
        std::cout<<s3.getStr()<<"와 "<<s4.getStr()<<"는 같아용"<<std::endl;
    std::cout<<std::endl;

    MyString s5("hello");

    int result = s4.compare(s5);
    if(result > 0)
        std::cout<<s4.getStr()<<"이 "<<s5.getStr()<<"보다 뒤에 있음"<<std::endl;
    else if(result < 0)
        std::cout<<s4.getStr()<<"이 "<<s5.getStr()<<"보다 앞에 있음"<<std::endl;
    return 0;
}