#include<iostream>
#include<limits>
typedef struct Animal{
    char name[30];
    int age;
    int health;
    int food;
    int clean;
}Animal;

void show_stat(Animal* animal);
void pass_day(Animal* list[], int cnt);
void play(Animal* animal);
void clear_buf_line(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void create_animal(Animal* animal){
    std::cout<<"이름 : ";
    std::cin.getline(animal->name, 30);
    std::cout<<"나이 : ";
    std::cin>>animal->age;
    animal->food = 100;
    animal->health = 100;
    animal->clean  = 100;
}


int main(){
    Animal* list[30];
    int cnt=0;

    while(true){
        int select;
        std::cout<<"1 : 추가"<<std::endl;
        std::cout<<"2 : 보기"<<std::endl;
        std::cout<<"3 : 놀기"<<std::endl;
        
        std::cin>>select;
        clear_buf_line();
        switch (select){
        int play_with;
        case 1:
            list[cnt] = new Animal;
            create_animal(list[cnt]);
            break;
        case 2:
            std::cout<<"번호 입력 : ";
            std::cin>>play_with;
            show_stat(list[play_with]);
            break;

        case 3:
            std::cout<<"번호 입력 : ";
            std::cin>>play_with;
            play(list[play_with]);
            break;
            
        default:
            break;
        }
        clear_buf_line();
    }
    for(int i=0; i < cnt; i++){
        delete list[i];
    }

    return 0;

}

void show_stat(Animal* animal){
    std::cout<<"이름 : "<<animal->name<<std::endl;
    std::cout<<"나이 : "<<animal->age<<std::endl;
    std::cout<<"체력 : "<<animal->health<<std::endl;
    std::cout<<"배부름 : "<<animal->food<<std::endl;
    std::cout<<"청결 : "<<animal->clean<<std::endl;
}

void play(Animal* animal){
    animal->health += 10;
    animal->food -= 20;
    animal->clean -= 30;
}

void pass_day(Animal* list[], int cnt){
    for(int i=0; i<cnt; i++){
        list[i]->health -= 10;
        list[i]->food -= 30;
        list[i] ->clean -= 20;
    }
}