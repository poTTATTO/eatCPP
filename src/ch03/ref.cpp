#include<iostream>

int main(){
    int a = 10;
    int& another_a = a;

    int b =  3;
    another_a = b; // another_a가 b를 가리키는 게 아니라 그냥 a에 b를 대입하는거다.

    return 0;
}