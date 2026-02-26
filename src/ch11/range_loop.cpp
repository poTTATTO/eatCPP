#include<iostream>
#include<vector>

int main()
{ 
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    for(int elem : vec)
    {
        std::cout<<"원소 :"<<elem<<std::endl;
    }

    return 0;
}