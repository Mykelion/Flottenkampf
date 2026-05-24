#ifndef KREUZER_H
#define KREUZER_H

#include "Ship.h"


class Kreuzer : public Ship
{
    public:
        Kreuzer();
        virtual ~Kreuzer();
        void attack(Ship& enemytarget, int number, double damagemultiplier, int player) override;
        void checkifdestroyed() override;
        void sethp(int damage) override;
        bool getdestroyed() override;

    protected:

    private:
};

#endif // KREUZER_H
