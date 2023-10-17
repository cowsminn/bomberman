#include "player.h"



player::player() {
    this->initTexture();
    this->initSprite();
    this->speed = 10.f;

}

player::~player() {


}

void player::update() {

}

void player::render(sf::RenderTarget& target) {
    target.draw(this->sprite);
}


void player::initSprite() {
    this->sprite.setTexture(this->texture);

    this->sprite.scale(0.2f,0.2f);

}

void player::initTexture() {

    if (!this->texture.loadFromFile("C:/Users/cosmi/Documents/Projects/bomberman/textures/yandhi.jpg")) {
        std::cout << "eroare : textura player" << '\n';
    }
}

void player::move(const float dirX, const float dirY) {
    this->sprite.move(this->speed * dirX, this->speed * dirY);


}


