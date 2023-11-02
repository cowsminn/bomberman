#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#ifndef OOP_GAME_H
#define OOP_GAME_H


class Game {
private:
    sf::RenderWindow window;

    Player player;

    void initWindow();
    void initPlayer();

public:
    Game();

    ~Game();

    void run();
    void update();
    void render();



};

#endif //OOP_GAME_H
