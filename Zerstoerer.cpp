#include "Zerstoerer.h"

Zerstoerer::Zerstoerer()
{
    this->shiptype = "Destroyer";
    this->huelle = 150;
    this->groesse = 6;
    this->schaden = 60;
    this->destroyed = false;
}

Zerstoerer::~Zerstoerer()
{
    //dtor
}
void Zerstoerer::attack(Ship& enemytarget, int number, double damagemultiplier, int player)
{
    int dmg = this->schaden * damagemultiplier;
    enemytarget.sethp(dmg);
    if(player == 1)
    {
        std::cout << "Destroyer of Player " << player << " on " << "(" << this->x+1 << "|" << this->y+1 << ")" << " attacks " << enemytarget.getshiptype() << " of Player " << player+1 <<" on " << "(" << enemytarget.getx()+1 << "|" << enemytarget.gety()+1 << ")" << std::endl;
    }
    else
    {
        std::cout << "Destroyer of Player " << player << " on " << "(" << this->x+1 << "|" << this->y+1 << ")" << " attacks " << enemytarget.getshiptype() << " of Player " << player-1 <<" on " << "(" << enemytarget.getx()+1 << "|" << enemytarget.gety()+1 << ")" << std::endl;
    }
}
void Zerstoerer::sethp(int damage)
{
    this->huelle = this->huelle - damage;
}

bool Zerstoerer::getdestroyed()
{
    return destroyed;
}
void Zerstoerer::checkifdestroyed()
{
    if(this->huelle <= 0)
    {
        this->huelle = 0;
        this->destroyed = true;
        std::cout << "Destroyer has been destroyed!" << std::endl;
    }
    else
    {
        std::cout << "remaining hp of Destroyer: " << this->huelle << std::endl;
    }

}
