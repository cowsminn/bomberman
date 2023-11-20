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

    ~Bomb();

    Bomb(const Bomb& other);

    friend std::ostream &operator<<(std::ostream &os, const Bomb &st);

    void setPosition(float x, float y);

    void activate();


//    void deactivate();

//    [[maybe_unused]] bool isActiveBomb() const;

    void draw(sf::RenderWindow &window) const;

    void move(float dirX, float dirY);
};

#endif // BOMB_H
