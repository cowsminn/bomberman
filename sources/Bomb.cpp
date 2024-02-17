#include "../headers/Bomb.h"

Bomb::Bomb() : isActive(false){
    if (!texture.loadFromFile("textures/bomb.png")) {
        throw FailedTextureLoad("textures/bomb.png");
    }

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(40, 0, 20, 26));
    sprite.scale(1.6f, 1.6f);
}

Bomb *Bomb::clone() const{
    return new Bomb(*this);
}

Bomb::Bomb(const Bomb& other) : Static_Object(other), isActive(other.isActive), timer(other.timer){}

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

void Bomb::explosion(sf::RenderWindow &window) {
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f( 51, 48));
    rect.setFillColor(sf::Color::Magenta);
    rect.setOutlineColor(sf::Color::Black);
    window.draw(rect);
}
