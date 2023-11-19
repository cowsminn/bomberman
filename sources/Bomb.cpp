#include "../headers/Bomb.h"

Bomb::Bomb() : isActive(false) {
    if (!texture.loadFromFile("textures/Bark.png")) {
        std::cout << "err textura bomba\n";
    }
    sprite.setTexture(texture);
}

void Bomb::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

void Bomb::activate() {
    isActive = true;
}

void Bomb::move(float dirX, float dirY) {
    sprite.move(dirX, dirY);
}

void Bomb::deactivate() {
    isActive = false;
}

bool Bomb::isActiveBomb() const {
    return isActive;
}

void Bomb::draw(sf::RenderWindow &window) const {
    if (isActive) {
        window.draw(sprite);
    }
}

