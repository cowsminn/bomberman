#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H


class Player {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f position;
    float speed;


    void initSprite();
    void initTexture();

public:
    Player();

    Player(float startX, float startY);

    sf::Vector2f getPosition() const;

    void setPosition(float x, float y);

    ~Player();

    Player(const Player& other);

    Player& operator=(const Player& other);

    friend std::ostream &operator<<(std::ostream &os, const Player &st);

    void move(float dirX, float dirY);
    void update();
    void render(sf::RenderTarget& target);
};


#endif //OOP_PLAYER_H
