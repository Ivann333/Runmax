#include <SFML/Graphics.hpp>
#include "Engine.h"


using namespace sf;

int main()
{


    auto myGame = std::make_unique<Engine>();

    myGame->run();

    return 0;
    

    
}