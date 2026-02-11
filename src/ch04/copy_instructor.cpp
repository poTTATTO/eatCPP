#include<cstring>
#include<iostream>

class PhotonCannon
{
private:
    int hp_, shield_;
    int x_, y_;
    int damage_;
    char* name_;

public:
    PhotonCannon(int x, int y, const char* cannon_name);
    PhotonCannon(const PhotonCannon& pc);
    ~PhotonCannon();
    void showStatus();
};

PhotonCannon::~PhotonCannon(){
    if(name_) delete[] name_;
}

PhotonCannon::PhotonCannon(const PhotonCannon& pc)
{
    std::cout<< "복사 생성자 호출!"<<std::endl;
    hp_ = pc.hp_;
    shield_ = pc.shield_;
    x_ = pc.x_;
    y_ = pc.y_;
    damage_ = pc.damage_;   
    name_ = new char[strlen(pc.name_) + 1]; 
    strcpy(name_, pc.name_);
}

PhotonCannon::PhotonCannon(int x, int y, const char* cannon_name)
{
    std::cout<<"생성자 호출!"<<std::endl;
    hp_ = shield_ = 100;
    this->x_ = x;
    this->y_ = y;
    damage_ = 20;
    name_ = new char[strlen(cannon_name) + 1];
    strcpy(name_, cannon_name);
}

void PhotonCannon::showStatus()
{
    std::cout<<"Photon Cannon"<<std::endl;
    std::cout<<" Name : "<<name_<<std::endl;
    std::cout<<" Location : (" << this->x_ <<" , "<< this->y_ << " ) "<<std::endl;
    std::cout<<" HP : "<< hp_ <<std::endl;
}

int main()
{
    PhotonCannon pc1(3,3, "name");
    PhotonCannon pc2(pc1);
    PhotonCannon pc3 = pc2;

    pc1.showStatus();
    pc2.showStatus();
}