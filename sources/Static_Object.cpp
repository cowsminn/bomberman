#include "../headers/Static_Object.h"

Static_Object::Static_Object() = default;

void Static_Object::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

Static_Object::Static_Object(const Static_Object &other) : texture(other.texture), sprite(other.sprite) {}

void Static_Object::draw(sf::RenderWindow &window) const {
    window.draw(sprite);
}

void Static_Object::move(float offsetX, float offsetY) {
    sprite.move(offsetX, offsetY);
}

void swap(Static_Object &first, Static_Object &second) noexcept {
    using std::swap;
    swap(first.sprite, second.sprite);
    swap(first.texture, second.texture);

}

Static_Object &Static_Object::operator=(const Static_Object &other) {
    if (this != &other) {
        Static_Object *temp = other.clone();
        swap(*this, *temp);
        delete temp;
    }
    return *this;
}


