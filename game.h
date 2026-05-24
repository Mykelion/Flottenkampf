#ifndef GAME_H
#define GAME_H
#include "Ship.h"
#include "Jaeger.h"
#include "Zerstoerer.h"
#include "Kreuzer.h"
#include <stdexcept>
#include <vector>
#include <memory>


class game
{
    public:
        game();
        virtual ~game();
        void choosefleet(std::vector<std::unique_ptr<Ship>>& Fleet);
        void deletedestroyed();
        void rungame();
        void initgameworld();
        void calculatecoordinates(std::vector<std::unique_ptr<Ship>>& Fleet, char gameworld[20][20]);
        void moveship(Ship* Ship);
        bool isoccupied(int movex, int movey);
        void shipsmoved(Ship* attacker, Ship* target);
        void printgameworld();
        double damagecalculation(Ship* attacker, Ship* target);

    protected:

    private:
    int round;
    std::vector<std::unique_ptr<Ship>> Fleet1;
    std::vector<std::unique_ptr<Ship>> Fleet2;
    int player;// nummer 1 oder 2
    char gameworld[20][20];


};

#endif // GAME_H
