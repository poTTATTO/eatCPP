#include<cstring>
#include<iostream>

class String
{
private:
    char* str_;
    int len_;

public:
    String(char c, int n);
    String(const char* s);
    String(const String& s);
    ~String();

    void addString(const String& s);
    void copyString(const String& s);
    int strlen() const;
    char* getStr() const;

};

char* String::getStr() const
{
    return str_;
}

String::String(char c, int n)
{
    len_ = n;
    str_ = new char[len_ + 1];
    for(int i=0; i<n; i++){
        str_[i] = c;
    }
    str_[n] = '\0';
}

String::String(const char* s)
{
    len_ = std::strlen(s);
    str_ = new char[len_ + 1];
    strcpy(str_, s);
}

String::String(const String& s){
    str_ = new char[s.len_ + 1];
    strcpy(str_, s.getStr());
}

void String::addString(const String& s)
{
    len_ = len_ + s.strlen();
    char* tmp = new char[len_ + 1];
    strcpy(tmp, str_);
    strcat(tmp, s.getStr());
    delete[] str_;
    str_ = tmp;
}

void String::copyString(const String& s)
{
    delete[] str_;
    len_ = s.strlen();

    str_ = new char[len_ + 1];
    strcpy(str_, s.getStr());   

}

String::~String(){
    if(str_) delete[] str_;
}

int String::strlen() const
{
    return len_;
}

int main()
{
    String s1('c', 10);
    String s2("hello");
    String s3(s1);

    std::cout<<"s1 : "<< s1.getStr()<<std::endl;
    s1.addString(s2);
    s1.addString(s1);

    s3.copyString(s2);
    std::cout<<"s1 : "<< s1.getStr()<<std::endl;
    std::cout<<"s2 : " << s2.getStr()<<std::endl;
    std::cout<<"s3 : "<<s3.getStr()<<std::endl;

    return 0;
}