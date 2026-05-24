#include "Ship.h"

Ship::Ship()
{
    //ctor
}

Ship::~Ship()
{
    //dtor
}

int Ship::getgroesse()
{
    return this->groesse;
}
std::string Ship::getshiptype()
{
    return this->shiptype;
}
int Ship::getx()
{
    return this->x;
}
int Ship::gety()
{
    return this->y;
}
void Ship::setx(int x)
{
    this->x = x;
}
void Ship::sety(int y)
{
    this->y = y;
}
