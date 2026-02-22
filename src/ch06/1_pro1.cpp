#include<iostream>

class MultiArray
{
private:
    Array* pArray_;
public:
    MultiArray(int N)
    {
        int size;
        std::cin>>size;
        pArray_ = new Array[size];

        for(int i=0; i<N; ++i)
        {
            pArray_[i];
        }
    }
};

class Array
{
private:
    Array* pArray_;
    int value_;

public:
    Array()
    {
        value_ = -1;
        pArray_ = nullptr;
    }

    Array(int N)
    {
        int pre_size;
        int size;
        std::cin>>size;
        pre_size = size;
        pArray_ = new Array[pre_size]; // 1차원 길이  예 : 3

        Array* t_pArray = pArray_;

        for(int i=0; i < size; ++i)
        {
            Array* pArray_1 = pArray_[i].pArray_;
            for(int j=0; j < N - 1; ++j);
            {
                std::cin>>size; // 
                for(int k = 0; k<size; ++k)
                {
                    t_pArray[k].pArray_ = new Array[size];
                t_pArray = t_pArray->pArray_;
                }
            }
        }
    }

    Array& operator[](int idx)
    {
        if(pArray_ == nullptr)
        {
            return *this;
        }
        else
        {
            return *pArray_;
        }
    }
};