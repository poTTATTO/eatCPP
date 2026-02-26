#include<algorithm>
#include<functional>
#include<vector>
#include<string>
#include<iostream>


template<typename Iter>
void print(Iter begin, Iter end)
{
    while(begin != end)
    {
        std::cout<<"["<<*begin<<"]";
        begin++;
    }
    std::cout<<std::endl;
}

int main()
{
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    std::cout << "처음 vec 상태 ------" << std::endl;
    print(vec.begin(), vec.end());  

    int num_erased = 0;
    vec.erase(std::remove_if(vec.begin(), vec.end(), [&num_erased](int i) { 
                if(num_erased >= 2)
                    return false;
                else if (i % 2 == 1){
                    num_erased++;
                    return true;
                } 
                return false;}),
        vec.end());

    print(vec.begin(), vec.end());

    return 0;
}