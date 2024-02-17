#ifndef BOMB_H
#define BOMB_H

#include "Static_Object.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Exception.h"

class Bomb : public Static_Object {
private:
    bool isActive;
    sf::Clock timer;

public:
    Bomb();

    Bomb(const Bomb& other);

    Bomb& operator=(Bomb other);

    ~Bomb() override = default;

    Bomb *clone() const override;

    friend std::ostream &operator<<(std::ostream &os, const Bomb &st);

    void activate();

    void draw(sf::RenderWindow &window) const override;

    void update();

};

#endif // BOMB_H
