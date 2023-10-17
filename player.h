#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H


class player {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    float speed;

    void initSprite();
    void initTexture();
public:
    player();
    virtual ~player();

    void move(const float dirX, const float dirY);
    void update();
    void render(sf::RenderTarget& target);
};


#endif //OOP_PLAYER_H
