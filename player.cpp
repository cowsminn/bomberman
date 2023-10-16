#include "player.h"



player::player() {
    if (!this->texture.loadFromFile("textures/yandhi.jpg")) {
        std::cout << "eroare : textura player" << '\n';
    }
}

player::player(const sf::Sprite &sprite) : sprite(sprite) {

    this->sprite.setTexture(this->texture);

}

player::~player() {

}

