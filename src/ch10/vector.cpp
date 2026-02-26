#include<iostream>

class Vector
{
private:
    std::string* data_;
    int capacity_;
    int length_;

public:
    Vector(int n = 1) : data_(new std::string[n]), capacity_(n), length_(0) {}

    void push_back(std::string s)
    {
        if(capacity_ <= length_)
        {
            std::string* tmp = new std::string[ 2 * capacity_ ];
            for(int i=0; i<capacity_; i++)
            {
                tmp[i] = data_[i];
            }
            delete[] data_;
            data_ = tmp;
            capacity_ *= 2;
        }

        data_[length_] = s;
        length_++;
    }

    std::string operator[](int i) { return data_[i];}

    void remove(int x)
    {
        for(int i = x + 1; i < length_; i ++)
        {
            data_[i - 1] = data_[i];
        }
        length_--;
    }
    
    int size() { return length_;}

    ~Vector()
    {
        if(data_)
        {
            delete[] data_;
        }
    }
};