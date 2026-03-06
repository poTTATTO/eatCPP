#include<iostream>
#include<cstring>
#include<vector>
class Rvalue
{
private:
    int length_;
    char* content_;

public:

    Rvalue() : length_(0), content_(nullptr)
    {
        std::cout<<"생성자 호출 ! "<<std::endl;
    }

    Rvalue(const char* str) : length_(strlen(str)), content_(new char[length_])
    {
        std::cout<<"생성자 호출 !"<<std::endl;
        memcpy(content_, str, length_);
    }

    Rvalue(const Rvalue& r) : length_(r.length_), content_(new char[length_])
    {
        std::cout<<"복사 생성자 호출 !"<<std::endl;
        memcpy(content_, r.content_, length_);
    }

    Rvalue(Rvalue&& r) noexcept : length_(r.length_), content_(r.content_)
    {
        std::cout<<"이동 생성자 호출 !"<<std::endl;
        r.content_ = nullptr;
    }

    Rvalue& operator=(Rvalue&& r) noexcept
    {
        std::cout<<"이동 대입 연산자"<<std::endl;
        if(this != &r)
        {
            delete[] content_;
            length_ = r.length_;
            content_ = r.content_;

            r.content_ = nullptr;
            r.length_ = 0;
        }

        return *this;
    }

    ~Rvalue()
    {
        if(content_) delete[] content_;
    }

    Rvalue& operator=(const Rvalue& r)
    {
        std::cout<<"대입 연산자"<<std::endl;
        if(content_) 
        {
            delete[] content_;
            length_ = r.length_;
            content_ = new char[length_];
            memcpy(content_, r.content_, length_);
        }

        return *this;
    }

    Rvalue operator+(const Rvalue& r)
    {
        Rvalue tmp;
        tmp.length_ = length_ + r.length_;
        tmp.content_ = new char[tmp.length_];
        memcpy(tmp.content_, content_, length_);
        memcpy(tmp.content_ + length_, r.content_, r.length_);

        return tmp;
    }

    void print() const
    {
        std::cout<<content_<<std::endl;
    }
};

template <typename T>
void swap(T& a, T& b)
{
    T tmp(std::move(a));
    a = std::move(b);
    b = std::move(tmp); 
}

int main()
{
    Rvalue r1("hello");
    Rvalue r2("world");
    std::cout<<"Swap 전---"<<std::endl;
    r1.print(); r2.print();

    std::cout<<"Swap 후---"<<std::endl;
    swap(r1, r2);
    r1.print(); r2.print();
    return 0;
}