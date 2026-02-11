#include <iostream>
// string.h 는 strlen 때문에 include 했는데, 사실 여러분이 직접 strlen
// 과 같은 함수를 만들어서 써도 됩니다.
#include <string.h>
class MyString
{

private:
    char* string_content;
    int string_length;
    int memory_capacity;
    public:
    MyString(char c);
    MyString(const char* str);
    MyString(const MyString& str);
    ~MyString();
    int length() const;
    void print() const;
    void println() const;
    MyString& assign(const MyString& str);
    MyString& assign(const char* str);

    int capacity() const;
    void reserve(int size);
};

void MyString::reserve(int size)
{
    if(size > memory_capacity)
    {
        char* tmp = new char[size];
        strcpy(tmp, string_content);
        delete[] string_content;
        string_content = tmp;
        memory_capacity = size;
    }
}
int MyString::capacity() const
{
    return memory_capacity;
}
MyString::MyString(char c) 
{
    string_content = new char[1];
    string_content[0] = c;
    memory_capacity = 1;
}
MyString::MyString(const char* str) 
{
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];
    for (int i = 0; i != string_length; i++) {
        string_content[i] = str[i];
    }
}
MyString::MyString(const MyString& str) 
{
    string_length = str.string_length;
    memory_capacity = string_length;
    string_content = new char[string_length];
    for (int i = 0; i != string_length; i++)
        string_content[i] = str.string_content[i];
}

MyString::~MyString() { delete[] string_content; }

int MyString::length() const { return string_length; }

void MyString::print() const
{
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }
}

void MyString::println() const 
{
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];

    }

}

MyString& MyString::assign(const MyString& str)
{
    if(strlen(str.string_content) >  memory_capacity)
    {
        delete[] string_content;
        string_content = new char[str.string_length];
        memory_capacity = str.string_length;
    }
    strcpy(string_content, str.string_content);
    
    string_length = str.string_length;
    return *this;
}

MyString& MyString::assign(const char* str)
{
    if(strlen(str) > memory_capacity){
        delete[] string_content;
        string_content = new char[strlen(str)];
        memory_capacity = string_length;
    }
    strcpy(string_content, str);

    string_length = strlen(str);
    return *this;
}


int main()
{
    MyString s1("very very very long string");
    s1.reserve(30);

    std::cout<<"Capacity : "<<s1.capacity()<<std::endl;
    std::cout<<"String length : "<<s1.length()<<std::endl;
    s1.println();

    return 0;
}