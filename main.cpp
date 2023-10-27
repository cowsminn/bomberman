#include "Game.h"

#ifdef __linux__
#include <X11/Xlib.h>
#endif

int main()
{
    Game game;
    game.run();

    return 0;
}
