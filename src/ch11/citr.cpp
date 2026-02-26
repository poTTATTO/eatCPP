#include<iostream>
#include<vector>

template <typename T>
void print_vector(std::vector<T>& vec)
{
    for(typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
    {
        std::cout<< *itr << std::endl;
    }

}

int main()
{
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    std::vector<int>::const_iterator citr = vec.cbegin();

    // *citr = 40;

    return 0;

}