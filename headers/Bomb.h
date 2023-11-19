#ifndef BOMB_H
#define BOMB_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Bomb {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    bool isActive;

public:
    Bomb();

    void setPosition(float x, float y);

    void activate();

//    void deactivate();

    [[nodiscard]] bool isActiveBomb() const;

    void draw(sf::RenderWindow &window) const;

    void move(float dirX, float dirY);
};

#endif // BOMB_H
