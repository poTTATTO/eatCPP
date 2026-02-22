#include <iostream>
#include <string.h>
class MyString
{

private:
    char* string_content;
    int string_length;
    int memory_capacity;
public:
    explicit MyString(int n);
    explicit MyString(char c);
    MyString(const char* str);
    MyString(const MyString& str);
    ~MyString();
    int length() const;
    void print() const;
    void println() const;
    MyString& assign(const MyString& str);
    MyString& assign(const char* str);
    MyString& insert(int loc, const MyString& str);
    MyString& insert(int loc, const char* str);
    MyString& insert(int loc, char c);
    MyString& erase(int loc, int num);
    int find(int from, const MyString& str) const;
    int find(int from, const char* str) const;
    int find(int from, char c) const;
    int compare(const MyString& str) const;
    int capacity() const;
    void reserve(int size);

    char& operator[](const int idx);
};

char& MyString::operator[](const int idx)
{
    return string_content[idx];
}
MyString::MyString(int capacity)
{
    string_content = new char[capacity];
    string_length = 0;
    memory_capacity = capacity;
}
int MyString::compare(const MyString& str) const
{
    for(int i=0; i < std::min(string_length, str.string_length); i++)
    {
        if(string_content[i] > str.string_content[i])
            return 1;
        else if(string_content[i] < str.string_content[i])
            return -1;
    }
    if(string_length == str.string_length) return 0;
    else if(string_length > str.string_length)
        return 1;

    return -1;
}
int MyString::find(int from, const MyString& str) const
{
    int i, j;
    if(str.string_length == 0) return -1;

    for(i = from; i <= string_length - str.string_length; i++)
    {
        for(j = 0; j < str.string_length; j++){
            if(string_content[i + j] != str.string_content[j]) break;
        }

        if(j == str.string_length) return i;
    }

    return -1;
}

MyString& MyString::erase(int loc, int num)
{
    if(loc < 0 || num < 0 || loc >= string_length)
        return *this;
    if(num + loc > string_length)
       num = string_length - loc;
    
    int move_len = string_length -  (loc + num);
    
    if(move_len > 0)
        memmove(string_content + loc, string_content + loc + num, string_length - (loc + num));
    string_length -= num;

    return *this;
}

void MyString::reserve(int size)
{
    if(size > memory_capacity)
    {
        char* tmp = new char[size];
        memcpy(tmp, string_content,string_length);
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
    std::cout<<std::endl;

}

MyString& MyString::assign(const MyString& str)
{
    if(strlen(str.string_content) >  memory_capacity)
    {
        delete[] string_content;
        string_content = new char[str.string_length];
        memory_capacity = str.string_length;
    }
    
    for (int i = 0; i != str.string_length; i++) {
    string_content[i] = str.string_content[i];
}
    string_length = str.string_length;
    return *this;
}
int MyString::find(int from, const char* str) const
{
    MyString tmp(str);
    return find(from, tmp);
}

int MyString::find(int from, char c) const
{
    MyString tmp(c);
    return find(from, tmp);
}


MyString& MyString::assign(const char* str)
{
    if(strlen(str) > memory_capacity){
        delete[] string_content;
        string_content = new char[strlen(str)];
        memory_capacity = string_length;
    }

    for (int i = 0; i != strlen(str); i++) {
        string_content[i] = str[i];
    }
    string_length = strlen(str);
    return *this;
}
MyString& MyString::insert(int loc, const MyString& str)
{
    if(loc < 0 || loc > string_length) return *this;

    int new_len = string_length + str.string_length;

    if(new_len > memory_capacity)
    {
        if(memory_capacity * 2 > new_len)
           memory_capacity *= 2;
        else
            memory_capacity = new_len;
        char* tmp = new char[memory_capacity];

        memcpy(tmp, string_content, loc);
        memcpy(tmp + loc, str.string_content, str.string_length);
        memcpy(tmp + loc + str.string_length, string_content + loc, string_length - loc);

        delete[] string_content;
        string_content = tmp;
    }
    else
    {
        memmove(string_content + loc + str.string_length, string_content + loc, string_length - loc);
        memcpy(string_content + loc, str.string_content, str.string_length);
    }

    string_length = new_len;
       
    return *this;
}

MyString& MyString::insert(int loc, const char* str)
{
    MyString temp(str);
    return insert(loc, temp);
}
MyString& MyString::insert(int loc, char c)
{
    MyString temp(c);
    return insert(loc, temp);
}

void doSomethingWithString(MyString str)
{

}

int main()
{
    MyString s1("hello");
    s1.print();

    std::cout<<std::endl;
    s1[2] = 'c';
    s1.print();
    // doSomethingWithString(3);
    
    // MyString s1("this is a very very very long string");
    // MyString s2("world");

    // s1.find(0, "very");
    // std::cout<<"location of fisrt <very> in the string : "<<s1.find(s1.find(0,"very"),"very")<<std::endl;
    // s1.erase(4, 6).println();
    
    // std::cout<<s1.capacity()<<std::endl;
    // std::cout<<s1.length()<<std::endl;
    // s1.insert(4, s2).println(); 
    
    // std::cout<<std::endl;
    // std::cout<<"Capacity : "<<s1.capacity()<<std::endl;
    // std::cout<<"String length : "<<s1.length()<<std::endl;
    // // s1.println();

    // s1.insert(4,"hello").println();
    return 0;
}