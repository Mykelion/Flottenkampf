#include "Jaeger.h"

Jaeger::Jaeger()
{
    this->shiptype = "Fighter";
    this->huelle = 75;
    this->groesse = 4;
    this->schaden = 30;
    this->destroyed = false;
}

Jaeger::~Jaeger()
{
    //dtor
}
void Jaeger::sethp(int damage)
{
    this->huelle = this->huelle - damage;
}

void Jaeger::attack(Ship& enemytarget, int number, double damagemultiplier, int player)
{
    int dmg = this->schaden * damagemultiplier;
    if(number == 9 || number == 10)
    {
        dmg = dmg*2;
        std::cout << "Critical damage incoming!" << std::endl;
    }
    enemytarget.sethp(dmg);
    if(player == 1)
    {
        std::cout << "Fighter of Player " << player << " on " << "(" << this->x+1 << "|" << this->y+1 << ")" << " attacks " << enemytarget.getshiptype() << " of Player " << player+1 <<" on " << "(" << enemytarget.getx()+1 << "|" << enemytarget.gety()+1 << ")" << std::endl;
    }
    else
    {
        std::cout << "Fighter of Player " << player << " on " << "(" << this->x+1 << "|" << this->y+1 << ")" << " attacks " << enemytarget.getshiptype() << " of Player " << player-1 <<" on " << "(" << enemytarget.getx()+1 << "|" << enemytarget.gety()+1 << ")" << std::endl;
    }
}
void Jaeger::checkifdestroyed()
{
    if(this->huelle<= 0)
    {
        this->huelle = 0;
        this->destroyed = true;
        std::cout << "Fighter has been destroyed!" << std::endl;
    }
    else
    {
        std::cout << "remaining hp of Fighter: " << this->huelle << std::endl;
    }

}
bool Jaeger::getdestroyed()
{
    return destroyed;
}
