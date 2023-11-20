#include "headers/Game.h"

#ifdef __linux__
#include <X11/Xlib.h>
#endif

int main()
{
    Player player;
    std::cout << player;
    Game game;
    game.run();
    return 0;
}
