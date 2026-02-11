#include<iostream>
#include<cstring>

class Marine{

private:
    int hp;
    int x, y;
    int damage;
    bool is_dead;
    char* name;

public:
    Marine();
    Marine(int x, int y);
    Marine(int x, int y, const char* marine_name);
    ~Marine();
    int attack();
    void be_attacked(int damage_earn);
    void move(int x, int y);

    void show_status();
};

Marine::~Marine(){
    
    if(this->name != nullptr){
        delete[] name;
    }
}
Marine::Marine(){
    this->x = 0;
    this->y = 0;
    this->damage = 5;
    this->hp = 50;
    this->is_dead = false;
    this->name = nullptr;
}

Marine::Marine(int x, int y){
    this->x = x;
    this->y = y;
    this->damage = 5;
    this->hp = 50;
    this->is_dead = false;
    this->name = nullptr;
}

Marine::Marine(int x, int y, const char* marine_name){
    this->name = new char[strlen(marine_name) + 1];
    strcpy(name, marine_name);
    this->x = x;
    this->y = y;
    this->damage = 5;
    is_dead = false;

}
int Marine::attack(){
    return this->damage;
}

void Marine::be_attacked(int damage_earn){
    this->hp -= damage_earn;
    if(this->hp <= 0){
        this->is_dead = true;
    }
}

void Marine::move(int x, int y){
    this->x = x;
    this->y = y;
}

void Marine::show_status(){
    std::cout<<"hp : "<< this->hp <<std::endl;
    std::cout<<"position( "<<this->x <<" , "<< this-> y<< " )"<<std::endl;
    std::cout<<"damage : "<<this->damage<<std::endl;
    std::cout<<"is_dead : "<<std::boolalpha<< this->is_dead<<std::endl;
}

int main(){
    Marine* array[100];

    array[0] = new Marine(1,2);
    array[1] = new Marine(2,3);

    array[0]->show_status();
    std::cout<<std::endl;
    array[1]->show_status();

    array[0]->be_attacked(array[1]->attack());

    array[0]->show_status();
    std::cout<<std::endl;
    array[1]->show_status();


    delete array[0];
    delete array[1];

    return 0;
}