#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H


class player {
private:
    sf::Sprite sprite;
    sf::Texture texture;

    void initTexture();
    void initSprite();
public:
    player();
    virtual ~player();

    explicit player(const sf::Sprite &sprite);

    void update();
    void render(sf::RenderTarget& target);

};


#endif //OOP_PLAYER_H
