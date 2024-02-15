
#include "../headers/Static_Object.h"

void Static_Object::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

void Static_Object::draw(sf::RenderWindow &window) const {
    window.draw(sprite);
}

void Static_Object::move(float offsetX, float offsetY) {
    sprite.move(offsetX, offsetY);
}


