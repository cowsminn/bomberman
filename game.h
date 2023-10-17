#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include "player.h"
#ifndef OOP_GAME_H
#define OOP_GAME_H


class game {
private:
    sf::RenderWindow* window;
    sf::Event e;

    player* player;

    void initWindow();
    void initPlayer();

public:
    game();
    virtual ~game();

    void run();
    void update();
    void render();



};

#endif //OOP_GAME_H
