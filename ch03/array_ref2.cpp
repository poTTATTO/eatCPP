#include<iostream>

int main(){
    
    int arr[3] = {1,2,3};
    int (&ref)[3] = arr;

    ref[0] = 3;
    ref[1] = 2;
    ref[2] = 1;

    for(int i = 0; i<3; i++){
        std::cout<<arr[i]<<std::endl;
    }

    return 0;
}