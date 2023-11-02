#include "Player.h"



Player::Player() {
    this->initTexture();
    this->initSprite();
    this->speed = 10.f;

}

Player::~Player() {


}

void Player::update() {

}

void Player::render(sf::RenderTarget& target) {
    target.draw(this->sprite);
}


void Player::initSprite() {
    this->sprite.setTexture(this->texture);

    this->sprite.scale(0.2f,0.2f);

}

void Player::initTexture() {

    if (!this->texture.loadFromFile("textures/yandhi.jpg")) {
        std::cout << "eroare : textura Player" << '\n';
    }
}

void Player::move(const float dirX, const float dirY) {
    this->sprite.move(this->speed * dirX, this->speed * dirY);


}


