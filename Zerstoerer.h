#ifndef ZERSTOERER_H
#define ZERSTOERER_H

#include "Ship.h"


class Zerstoerer : public Ship
{
    public:
        Zerstoerer();
        virtual ~Zerstoerer();
        void attack(Ship& enemytarget, int number, double damagemultiplier, int player) override;
        void checkifdestroyed() override;
        void sethp(int damage) override;
        bool getdestroyed() override;

    protected:

    private:
};

#endif // ZERSTOERER_H
