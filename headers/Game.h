#ifndef OOP_GAME_H
#define OOP_GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Wall.h"
#include "Map.h"
#include "Bomb.h"

class Game {
private:
    sf::RenderWindow window;
    Player player;
    std::vector<Wall> walls;
    sf::VertexArray rectangleWithBoxes;
    sf::Clock bombCooldownClock;
    sf::Time bombCooldownDuration;
    Map map;
    Bomb bomb;
    void initWindow();

    int test;

public:
    Game();
    ~Game();

    void run();
    void update();
    void render();

//    friend std::ostream &operator<<(std::ostream &os, const Game &st);
};

#endif //OOP_GAME_H
