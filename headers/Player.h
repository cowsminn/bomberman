#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Player {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f position;
    float speed;
    sf::FloatRect bounds; // Define player bounds

    void initTexture();

    void initSprite();

public:
    Player();

    Player(float startX, float startY, const sf::FloatRect &bounds);

    ~Player();

    sf::Vector2f getPosition() const;
    void setPosition(float x, float y);

    void update();

    void render(sf::RenderTarget& target);

    void move(float dirX, float dirY);

    friend std::ostream &operator<<(std::ostream &os, const Player &st);

    Player(const Player &other);

    Player &operator=(const Player &other);
};

#endif // OOP_PLAYER_H
