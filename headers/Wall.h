#ifndef OOP_WALL_H
#define OOP_WALL_H

#include <SFML/Graphics.hpp>
#include "Static_Object.h"
#include <iostream>

class Wall : public Static_Object {
public:
    Wall();

    Wall(float x, float y);

    ~Wall() override;

};

#endif //OOP_WALL_H
