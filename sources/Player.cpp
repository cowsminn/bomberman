#include "../headers/Player.h"

Player::Player() {
    this->initTexture();
    this->initSprite();
    this->speed = 3.f;
    this->bounds = sf::FloatRect(0.f, 0.f, 1220.f, 660.f); /// kinda rez de la screen - rez de la player

}

Player::Player(float startX, float startY, const sf::FloatRect &bounds)
        : position(startX, startY), bounds(bounds) {
    this->initTexture();
    this->initSprite();
    this->speed = 3.f;
}

std::ostream &operator<<(std::ostream &os, const Player &st) {
    os << "speed: " << st.speed << "\n";
    os << "position: (" << st.position.x << ", " << st.position.y << ")\n";
    os << "texture position: (" << st.sprite.getPosition().x << ", " << st.sprite.getPosition().y << ")\n";
    os << "position of the player on the sprite png: (" << st.sprite.getTextureRect().left << ", "
       << st.sprite.getTextureRect().top << ", " << st.sprite.getTextureRect().width << ", "
       << st.sprite.getTextureRect().height << ")\n";
    return os;
}

Player::~Player() {}

sf::Vector2f Player::getPosition() const {
    return position;
}

void Player::setPosition(float x, float y) {
    // Ensure the position stays within bounds
    position.x = std::max(bounds.left, std::min(x, bounds.left + bounds.width));
    position.y = std::max(bounds.top, std::min(y, bounds.top + bounds.height));
    sprite.setPosition(position);
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
    this->sprite.scale(3.4f, 3.4f);
}

void Player::initTexture() {
    if (!this->texture.loadFromFile("textures/Hero.png")) {
        std::cout << "Error loading player texture.\n";
    }
}

void Player::move(const float dirX, const float dirY) {
    float moveX = speed * dirX;
    float moveY = speed * dirY;

    // Check if the move will keep the player within bounds
    if (position.x + moveX >= bounds.left && position.x + moveX <= bounds.left + bounds.width) {
        position.x += moveX;
    }
    if (position.y + moveY >= bounds.top && position.y + moveY <= bounds.top + bounds.height) {
        position.y += moveY;
    }

    sprite.setPosition(position);
}

void Player::setBounds(const sf::FloatRect &bounds) {
    this->bounds = bounds;
}

Player::Player(const Player &other) : speed(other.speed), bounds(other.bounds) {
    std::cout << "Copy constructor called.\n";
}

Player &Player::operator=(const Player &other) {
    if (this != &other) {
        speed = other.speed;
        bounds = other.bounds;
    }
    return *this;
}
