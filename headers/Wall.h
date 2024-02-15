#ifndef OOP_WALL_H
#define OOP_WALL_H

#include <SFML/Graphics.hpp>
#include "Static_Object.h"
#include <iostream>

class Wall : public Static_Object {
public:
    Wall();

    // Constructor to set position
    Wall(float x, float y);

    ~Wall() override;

    // Function to check collision with player
    bool checkCollision(const sf::FloatRect &playerBounds) const;
};

#endif //OOP_WALL_H
