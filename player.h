#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H


class player {
private:
    sf::Sprite sprite;
    sf::Texture texture;
public:
    player();
    virtual ~player();
    void update();
};


#endif //OOP_PLAYER_H
