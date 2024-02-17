#ifndef OOP_STATIC_OBJECT_H
#define OOP_STATIC_OBJECT_H

#include <SFML/Graphics.hpp>

class Static_Object {
protected:
    sf::Texture texture;
    sf::Sprite sprite;

public:
    Static_Object();

    virtual ~Static_Object() {}

    virtual Static_Object *clone() const = 0;

    Static_Object(const Static_Object &other);

    Static_Object &operator=(const Static_Object &other);

    virtual void setPosition(float x, float y);

    virtual void draw(sf::RenderWindow &window) const;

    virtual void move(float offsetX, float offsetY);

    friend void swap(Static_Object &first, Static_Object &second) noexcept;

    virtual void activate() = 0;
    virtual void explosion(sf::RenderWindow& window) = 0;
};

#endif //OOP_STATIC_OBJECT_H
