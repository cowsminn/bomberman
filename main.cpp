#include "headers/Game.h"

#ifdef __linux__
#include <X11/Xlib.h>
#endif

int main()
{
    Game game;
    std::cout << game;
    game.run();
    return 0;
}
