#include "../headers/Player.h"

Player::Player() {
    this->initTexture();
    this->initSprite();
    this->speed = 3.f;

}

Player::Player(float startX, float startY) : position(startX, startY) {
    this->speed = 3.f;
}

std::ostream &operator<<(std::ostream &os, const Player &st) {
    os << "speed: " << st.speed << "\n";
    os << "position: (" << st.position.x << ", " << st.position.y << ")\n";
    os << "texture position: (" << st.sprite.getPosition().x << ", " << st.sprite.getPosition().y << ")\n";
    os << "position of the player on the sprite png: (" << st.sprite.getTextureRect().left << ", " << st.sprite.getTextureRect().top << ", "
       << st.sprite.getTextureRect().width << ", " << st.sprite.getTextureRect().height << ")\n";
    return os;
}

Player::~Player() {

}

sf::Vector2f Player::getPosition() const {
    return position;
}

void Player::setPosition(float x, float y) {
    this->position = sf::Vector2f(x, y);
}

void Player::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        int xTexture;
        xTexture = (int) this->sprite.getPosition().y / 20 % 4;
        xTexture = xTexture * 16;
        this->sprite.setTextureRect(sf::IntRect(xTexture, 0, 16, 16));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        int xTexture;
        xTexture = (int) this->sprite.getPosition().x / 20 % 4;
        xTexture = xTexture * 16;
        this->sprite.setTextureRect(sf::IntRect(xTexture, 16, 16, 16));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        int xTexture;
        xTexture = (int) this->sprite.getPosition().y / 20 % 4;
        xTexture = xTexture * 16;
        this->sprite.setTextureRect(sf::IntRect(xTexture + 64, 0, 16, 16));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        int xtexture;
        xtexture = (int) this->sprite.getPosition().x / 20 % 4;
        xtexture = xtexture * 16;
        this->sprite.setTextureRect(sf::IntRect(xtexture + 64, 16, 16, 16));
    }

}

void Player::render(sf::RenderTarget& target) {
    target.draw(this->sprite);
}

void Player::initSprite() {
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect(64, 0, 16, 16));
    this->sprite.scale(3.4f, 3.4f); /// nu vreau sa fie chiar 64x64

}

void Player::initTexture() {

    if (!this->texture.loadFromFile("textures/Hero.png")) {
        std::cout << "eroare : textura Player" << '\n';
    }

}

void Player::move(const float dirX, const float dirY) {
    this->sprite.move(this->speed * dirX, this->speed * dirY);
    this->position = this->sprite.getPosition();
}

Player::Player(const Player &other) : speed(other.speed){
    std::cout << " const de copiere";
}

Player &Player::operator=(const Player &other) {

    speed = other.speed;

    return *this;
}



