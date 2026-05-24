#ifndef SHIP_H
#define SHIP_H
#include <iostream>


class Ship
{
    public:
        Ship();
        virtual ~Ship();
        virtual void attack(Ship& enemytarget, int number, double damagemultiplier, int player) = 0;
        virtual void checkifdestroyed() = 0;
        virtual bool getdestroyed() = 0;
        virtual void sethp(int damage) = 0;
        int getgroesse();
        std::string getshiptype();
        int getx();
        int gety();
        void setx(int x);
        void sety(int y);




    protected:
    std::string shiptype;
    int huelle;
    int groesse;
    int schaden;
    bool destroyed;
    int x;
    int y;
    private:

};

#endif // SHIP_H
