#include "../headers/Bomb.h"

Bomb::Bomb() :Static_Object(), isActive(false), basePtr(nullptr) {
    if (!texture.loadFromFile("textures/bomb.png")) {
        std::cout << "Error loading bomb texture.\n";
    }

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(40, 0, 20, 26));
    sprite.scale(1.6f, 1.6f);
}

Bomb *Bomb::clone() const{
    return new Bomb(*this);
}

Bomb::Bomb(const Bomb& other) : Static_Object(other), isActive(other.isActive), timer(other.timer), basePtr(nullptr) {}

void Bomb::activate() {
    isActive = true;
    timer.restart();
}

void Bomb::update() {
    if (isActive && timer.getElapsedTime().asSeconds() >= 3.0f) {
        isActive = false;
    }
}

void Bomb::draw(sf::RenderWindow &window) const {
    if (isActive) {
        window.draw(sprite);
    }
}

std::ostream &operator<<(std::ostream &os, const Bomb &st) {
    os << st.isActive << " op << bomb";
    return os;
}
