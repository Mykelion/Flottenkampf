#include "game.h"


game::game()
{
    std::cout << "Player 1:" << std::endl;
    this->choosefleet(this->Fleet1);
    std::cout << "Player 2:" << std::endl;
    this->choosefleet(this->Fleet2);
    this->initgameworld();
    this->calculatecoordinates(this->Fleet1, this->gameworld);
    this->calculatecoordinates(this->Fleet2, this->gameworld);
    this->printgameworld();
    std::cout << "Fleets are ready for battle!" << std::endl;
}
void game::choosefleet(std::vector<std::unique_ptr<Ship>>& Fleet)
{
    int fleetsize = 0;
    while(fleetsize < 1 || fleetsize > 9)
    {
        std::cout << "Enter Fleetsize" << std::endl;
        std::cin >> fleetsize;
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore();
            throw std::invalid_argument("Input was not a number!");
        }
        if(fleetsize < 1 || fleetsize > 9)
        {
            std::cout << "invalid Fleetsize" << std::endl;
        }
    }

        for(int i = 0; i < fleetsize; i++)
        {
            int choice = 0;
            std::cout << "Choose a shiptype" << std::endl;
            std::cout << "press 1 for Fighter" << std::endl;
            std::cout << "press 2 for Destroyer" << std::endl;
            std::cout << "press 3 for Cruiser" << std::endl;
            std::cin >> choice;

            switch (choice)
            {
                case 1:
                Fleet.push_back(std::make_unique<Jaeger>());
                std::cout << "Fighter was added to your Fleet!" << std::endl;
                break;
                case 2:
                Fleet.push_back(std::make_unique<Zerstoerer>());
                std::cout << "Destroyer was added to your Fleet!" << std::endl;
                break;
                case 3:
                Fleet.push_back(std::make_unique<Kreuzer>());
                std::cout << "Cruiser was added to your Fleet!" << std::endl;
                break;
                default:
                std::cout << "Invalid choice!\n";// exception oder bedingung die überptüft ob buchstaben eingegeben werden fehlt
                i--;
                break;
            }
        }
}
bool game::isoccupied(int movex, int movey)
{

    for (int i = 0; i < this->Fleet1.size(); i++)
        if (this->Fleet1[i]->getx() == movex && this->Fleet1[i]->gety() == movey)// Am Ende sieht man nicht alle plätze da die schiffe auch zu den x plätzen fahren können|| this->gameworld[movey][movex] == 'x'
        {
            return true;
        }


    for (int i = 0; i < this->Fleet2.size(); i++)
        if (this->Fleet2[i]->getx() == movex && this->Fleet2[i]->gety() == movey)//|| this->gameworld[movey][movex] == 'x'
        {
            return true;
        }

    return false;
}
void game::moveship(Ship* Ship)
{
    if(Ship == nullptr)
    {
        throw std::invalid_argument("Ship pointer is null!");
    }


    int movex = std::rand()%20;
    int movey = std::rand()%20;
    while(this->isoccupied(movex, movey))
    {
        movex = std::rand()%20;
        movey = std::rand()%20;
    }
    int xbefore = Ship->getx();
    int ybefore = Ship->gety();
    this->gameworld[ybefore][xbefore] = '~';
    Ship->setx(movex);
    Ship->sety(movey);

    if(Ship->getshiptype() == "Fighter")
    {
        this->gameworld[Ship->gety()][Ship->getx()] = 'F';
    }
    else if(Ship->getshiptype() == "Cruiser")
    {
        this->gameworld[Ship->gety()][Ship->getx()] = 'C';
    }
    else if(Ship->getshiptype() == "Destroyer")
    {
        this->gameworld[Ship->gety()][Ship->getx()] = 'D';
    }
    else
    {
        throw std::runtime_error("Unknown ship type!");
    }
}


void game::shipsmoved(Ship* attacker, Ship* target)
{
    if(attacker == nullptr)
    {
        throw std::invalid_argument("attacker pointer is null!");
    }
    if(target == nullptr)
    {
        throw std::invalid_argument("target pointer is null!");
    }
    int attackerxold = attacker->getx();
    int attackeryold = attacker->gety();
    int targetxold = target->getx();
    int targetyold = target->gety();

    this->moveship(attacker);
    std::cout << attacker->getshiptype() << " of Player " << this->player << " on " <<  "(" << attackerxold+1 << "|" << attackeryold+1 << ")" << " moved to "
    << "(" << attacker->getx()+1 << "|" << attacker->gety()+1 << ")" << std::endl;
    this->moveship(target);
    if(this->player == 1)
    {
        std::cout << target->getshiptype() << " of Player " << this->player+1 << " on " <<  "(" << targetxold+1 << "|" << targetyold+1 << ")" << " moved to "
        << "(" << target->getx()+1 << "|" << target->gety()+1 << ")" << std::endl;
    }
    else
    {
        std::cout << target->getshiptype() << " of Player " << this->player-1 << " on " <<  "(" << targetxold+1 << "|" << targetyold+1 << ")" << " moved to "
        << "(" << target->getx()+1 << "|" << target->gety()+1 << ")" << std::endl;
    }
}
void game::calculatecoordinates(std::vector<std::unique_ptr<Ship>>& Fleet, char gameworld[20][20])
{
    for(int i = 0; i < Fleet.size(); i++)
    {
        int xcoord = std::rand()%20;
        int ycoord = std::rand()%20;
        do
        {
            xcoord = std::rand()%20;
            ycoord = std::rand()%20;
        }
        while(gameworld[ycoord][xcoord] == 'F' || gameworld[ycoord][xcoord] == 'C' || gameworld[ycoord][xcoord] == 'D' || this->isoccupied(xcoord, ycoord));
        Fleet[i]->setx(xcoord);
        Fleet[i]->sety(ycoord);
        if(Fleet[i]->getshiptype() == "Fighter")
        {
            gameworld[ycoord][xcoord] = 'F';
        }
        else if(Fleet[i]->getshiptype() == "Cruiser")
        {
            gameworld[ycoord][xcoord] = 'C';
        }
        else if(Fleet[i]->getshiptype() == "Destroyer")
        {
            gameworld[ycoord][xcoord] = 'D';
        }
        else
        {
            throw std::runtime_error("Unknown ship type!");
        }
    }
}
void game::printgameworld()
{
    for(int y = 0; y < 20; y++)
    {
        for(int x = 0; x < 20; x++)
        {
            std::cout << gameworld[y][x];
        }
        std::cout << '\n';
    }
}

void game::initgameworld()
{
    for(int y = 0; y < 20; y++)
    {
        for(int x = 0; x < 20; x++)
        {
            this->gameworld[y][x] = '~';
        }
    }

}

double game::damagecalculation(Ship* attacker, Ship* target)
{
    int distancex = 0;
    int distancey = 0;
    if(attacker == nullptr)
    {
        throw std::invalid_argument("attacker pointer is null!");
    }
    if(target == nullptr)
    {
        throw std::invalid_argument("target pointer is null!");
    }

    if(attacker->getx() < target->getx())
    {
        distancex = target->getx() - attacker->getx();
    }
    else
    {
        distancex = attacker->getx() - target->getx();
    }
    if(attacker->gety() < target->gety())
    {
        distancey = target->gety() - attacker->gety();
    }
    else
    {
        distancey = attacker->gety() - target->gety();
    }
    int sum = distancex + distancey;
    if(sum > 14)
    {
        std::cout << "Distance: " << sum << " incoming damage reduced by half" << std::endl;
        return 0.5;
    }
    else if(sum > 4 && sum < 15)
    {
        std::cout << "Distance: " << sum << " incoming damage slightly reduced" << std::endl;
        return 0.75;
    }
    else
    {
        return 1;
    }
}
void game::deletedestroyed()
{
    for(int i = 0; i < Fleet1.size(); i++)
    {
        if(this->Fleet1[i]->getdestroyed())
        {
            std::cout << Fleet1[i]->getshiptype() << " deleted!" << std::endl;
            this->gameworld[Fleet1[i]->gety()][Fleet1[i]->getx()] = 'x';
            Fleet1.erase(Fleet1.begin() + i);

            i--;
        }
    }
    for(int i = 0; i < Fleet2.size(); i++)
    {
        if(this->Fleet2[i]->getdestroyed())
        {
            std::cout << Fleet2[i]->getshiptype() << " deleted!" << std::endl;
            this->gameworld[Fleet2[i]->gety()][Fleet2[i]->getx()] = 'x';
            Fleet2.erase(Fleet2.begin() + i);

            i--;
        }
    }
}
void game::rungame()
{
    this->round = 1;
    if(Fleet1.empty())
    {
        throw std::runtime_error("Fleet1 is empty!");
    }
    if(Fleet2.empty())
    {
        throw std::runtime_error("Fleet2 is empty!");
    }
    while(Fleet1.size() > 0 && Fleet2.size() > 0)
    {
        this->player = 1;
        std::cout << "Round: " << round << std::endl;
        std::cout << "Player 1 turn" << std::endl;
        int attackerindex = std::rand()%Fleet1.size();
        int targetindex = std::rand()%Fleet2.size();

        Ship* attacker = Fleet1[attackerindex].get();
        Ship* target = Fleet2[targetindex].get();
        this->shipsmoved(attacker, target);
        this->printgameworld();
        double damagemultiplier = damagecalculation(attacker, target);

        int number = std::rand()%10+1;

        if(attacker->getshiptype() == "Cruiser")
        {
            if(number < target->getgroesse())
            {
                std::cout << "The attack missed its target!" << std::endl;
            }
            else
            {
                std::cout << "The attack hit its target! Bombardement activated!" << std::endl;
                while(number >= target->getgroesse())
                {
                    attacker->attack(*target, number, damagemultiplier, player);
                    target->checkifdestroyed();
                    this->deletedestroyed();

                    if(Fleet2.size() == 0)
                    {
                        break;
                    }

                    targetindex = std::rand()%Fleet2.size();
                    target = Fleet2[targetindex].get();
                    number = std::rand()%10+1;
                }
            }

        }
        else if(attacker->getshiptype() == "Destroyer")
        {
            if(number >= target->getgroesse()||number >= target->getgroesse()-1 || number >= target->getgroesse()-2)
            {
                attacker->attack(*target, number, damagemultiplier, player);
                target->checkifdestroyed();
                this->deletedestroyed();
            }
            else
            {
                std::cout << "The attack missed its target!" << std::endl;
            }
        }
        else
        {
            if(number >= target->getgroesse())
            {
                attacker->attack(*target, number, damagemultiplier, player);
                target->checkifdestroyed();
                this->deletedestroyed();
            }
            else
            {
                std::cout << "The attack missed its target!" << std::endl;
            }
        }
        if(Fleet2.size()==0)
        {
            this->printgameworld();
            break;
        }
        this->printgameworld();
        this->player = 2;
        std::cout << "Player 2 turn" << std::endl;
        attackerindex = std::rand()%Fleet2.size();
        targetindex = std::rand()%Fleet1.size();

        attacker = Fleet2[attackerindex].get();
        target = Fleet1[targetindex].get();
        this->shipsmoved(attacker, target);
        this->printgameworld();
        damagemultiplier = damagecalculation(attacker, target);
        number = std::rand()%10+1;

        if(attacker->getshiptype() == "Cruiser")
        {
            if(number < target->getgroesse())
            {
                std::cout << "The attack missed its target!" << std::endl;
            }
            else
            {
                std::cout << "The attack hit its target! Bombardement activated!" << std::endl;
                while(number >= target->getgroesse())
                {
                    attacker->attack(*target, number, damagemultiplier, player);
                    target->checkifdestroyed();
                    this->deletedestroyed();

                    if(Fleet1.size() == 0)
                    {
                        break;
                    }

                    targetindex = std::rand()%Fleet1.size();
                    target = Fleet1[targetindex].get();
                    number = std::rand()%10+1;
                }
            }
        }
        else if(attacker->getshiptype() == "Destroyer")
        {
            if(number >= target->getgroesse()||number >= target->getgroesse()-1 || number >= target->getgroesse()-2)
            {
                attacker->attack(*target, number, damagemultiplier, player);
                target->checkifdestroyed();
                this->deletedestroyed();
            }
            else
            {
                std::cout << "The attack missed its target!" << std::endl;
            }
        }
        else
        {
            if(number >= target->getgroesse())
            {
                attacker->attack(*target, number, damagemultiplier, player);
                target->checkifdestroyed();
                this->deletedestroyed();
            }
            else
            {
                std::cout << "The attack missed its target!" << std::endl;
            }
        }
        if(Fleet1.size()==0)
        {
            this->printgameworld();

            break;
        }
        this->printgameworld();

        this->round++;
    }
    if(Fleet1.size() == 0)
    {
        std::cout << "Game over Player 2 wins" << std::endl;
    }
    else
    {
        std::cout << "Game over Player 1 wins" << std::endl;
    }
}

game::~game()
{
    //dtor
}

