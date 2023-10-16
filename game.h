#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

#ifndef OOP_GAME_H
#define OOP_GAME_H


class game {
private:
    sf::RenderWindow* window;

    void initWindow();

public:
    game();
    virtual ~game();

    void run();
    void update();
    void render();



};

#endif //OOP_GAME_H
