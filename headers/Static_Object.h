#ifndef OOP_STATIC_OBJECT_H
#define OOP_STATIC_OBJECT_H

#include <SFML/Graphics.hpp>

class Static_Object {
protected:
    sf::Texture texture;
    sf::Sprite sprite;

public:
    virtual ~Static_Object() {}

    virtual void setPosition(float x, float y);

    virtual void draw(sf::RenderWindow &window) const;

    virtual void move(float offsetX, float offsetY);
};

#endif //OOP_STATIC_OBJECT_H
