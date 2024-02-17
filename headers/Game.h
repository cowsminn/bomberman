#ifndef OOP_GAME_H
#define OOP_GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System/Sleep.hpp>
#include <iostream>
#include "Static_Object.h"
#include <vector>
#include <memory>
#include <chrono>
#include <thread>
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
    std::vector<std::unique_ptr<Static_Object>> objects;

public:
    Game();
    ~Game();

    void run();
    void update();
    void render();

    friend std::ostream &operator<<(std::ostream &os, const Game &st);

};

#endif //OOP_GAME_H
