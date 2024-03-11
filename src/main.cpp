#include <time.h>
#include <stdlib.h>
#include "../include/Game.h"
#include "/Users/arhway/Desktop/FinalI/C-Game/Games/Settings/Setting.h"


int main()
{
    srand(time(static_cast<unsigned>(0)));
    Game game;
    // Setting music;
    game.run();
    return 0;
}
