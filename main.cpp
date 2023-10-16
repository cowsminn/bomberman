#include "game.h"

#ifdef __linux__
#include <X11/Xlib.h>
#endif

int main()
{
    game game;
    game.run();

    return 0;
}
