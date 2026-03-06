#include<iostream>

template <typename T>

class Vector
{
private:
    T* data_;
    std::size_t size_;

public:
    Vector(std::size_t size) : size_(size)
    {
        data_ = new T[size];

        for(int i=0; i<size_; ++i)
        {
            data_[i] = 3;
        }
    }

    const T& at(std::size_t index) const
    {
        if(index >= size_)
        {
            throw std::out_of_range("vector의 index가 범위를 초과함");
        }
        return data_[index];
    }

    ~Vector()
    {
        delete[] data_;
    }
};


int main()
{
    Vector<int> vec(3);

    int index, data = 0;
    std::cin >> index;

    try
    {
        data = vec.at(index);
    }catch (std::out_of_range& e)
    {
        std::cout<<"예외 발생 ! "<<e.what()<<std::endl;
    }

    std::cout<<"읽은 데이터 : "<< data << std::endl;

    return 0;
}