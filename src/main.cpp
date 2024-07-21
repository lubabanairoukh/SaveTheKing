#include "GameController.h"


int main()
{
    std::srand(static_cast<unsigned>(time(NULL)));
    GameController my_game;
    my_game.run();

    return 0;
}
