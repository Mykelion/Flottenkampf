#include <iostream>
#include <time.h>
#include "game.h"




int main()
{
    srand(time(NULL));
    try
    {
        game game;
        game.rungame();
    }

    catch(const std::invalid_argument& except)
    {
        std::cout << except.what() << std::endl;
    }
    catch(const std::runtime_error& except)
    {
        std::cout << except.what() << std::endl;
    }


    return 0;
}
