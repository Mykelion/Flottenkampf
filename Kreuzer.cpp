#include "Kreuzer.h"

Kreuzer::Kreuzer()
{
    this->shiptype = "Cruiser";
    this->huelle = 250;
    this->groesse = 8;
    this->schaden = 50;
    this->destroyed = false;
}

Kreuzer::~Kreuzer()
{
    //dtor
}
void Kreuzer::sethp(int damage)
{
    this->huelle = this->huelle - damage;
}
void Kreuzer::attack(Ship& enemytarget, int number, double damagemultiplier, int player)
{
    int dmg = this->schaden * damagemultiplier;
    enemytarget.sethp(dmg);
    if(player == 1)
    {
        std::cout << "Cruiser of Player " << player << " on " << "(" << this->x+1 << "|" << this->y+1 << ")" << " attacks " << enemytarget.getshiptype() << " of Player " << player+1 <<" on " << "(" << enemytarget.getx()+1 << "|" << enemytarget.gety()+1 << ")" << std::endl;
    }
    else
    {
        std::cout << "Cruiser of Player " << player << " on " << "(" << this->x+1 << "|" << this->y+1 << ")" << " attacks " << enemytarget.getshiptype() << " of Player " << player-1 <<" on " << "(" << enemytarget.getx()+1 << "|" << enemytarget.gety()+1 << ")" << std::endl;
    }
}
bool Kreuzer::getdestroyed()
{
    return destroyed;
}
void Kreuzer::checkifdestroyed()
{
    if(this->huelle <= 0)
    {
        this->huelle = 0;

        this->destroyed = true;
        std::cout << "Cruiser has been destroyed!" << std::endl;
    }
    else
    {
        std::cout << "remaining hp of Cruiser: " << this->huelle << std::endl;
    }

}
