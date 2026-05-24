#ifndef JAEGER_H
#define JAEGER_H

#include "Ship.h"


class Jaeger : public Ship
{
    public:
        Jaeger();
        virtual ~Jaeger();
        void attack(Ship& enemytarget, int number, double damagemultiplier, int player) override;
        void checkifdestroyed() override;
        void sethp(int damage) override;
        bool getdestroyed() override;

    protected:

    private:
};

#endif // JAEGER_H
