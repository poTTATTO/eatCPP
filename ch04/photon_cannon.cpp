#include<cstring>
#include<iostream>

class PhotonCannon
{
private:
    int hp_, shield_;
    int x_, y_;
    int damage_;

public:
    PhotonCannon(int x, int y);
    PhotonCannon(const PhotonCannon& pc);

    void showStatus();
};

PhotonCannon::PhotonCannon(const PhotonCannon& pc)
{
    std::cout<< "복사 생성자 호출!"<<std::endl;
    hp_ = pc.hp_;
    shield_ = pc.shield_;
    x_ = pc.x_;
    y_ = pc.y_;
    damage_ = pc.damage_;    
}

PhotonCannon::PhotonCannon(int x, int y)
{
    std::cout<<"생성자 호출!"<<std::endl;
    hp_ = shield_ = 100;
    this->x_ = x;
    this->y_ = y;
    damage_ = 20;
}

void PhotonCannon::showStatus()
{
    std::cout<<"Photon Cannon"<<std::endl;
    std::cout<<" Location : (" << this->x_ <<" , "<< this->y_ << " ) "<<std::endl;
    std::cout<<" HP : "<< hp_ <<std::endl;
}

int main()
{
    PhotonCannon pc1(3,3);
    PhotonCannon pc2(pc1);
    PhotonCannon pc3 = pc2;

    pc1.showStatus();
    pc2.showStatus();
}