#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Map {
private:
    sf::RenderWindow &window;
    sf::Sprite sprite;
    sf::Texture texture;
    std::string texture_path;
    int columns, lines;

    void initSprite();

    void initTexture();

public:

    explicit Map(sf::RenderWindow &window);

    Map();

    ~Map();

    Map(const Map &other);

    static void display_at_position(sf::RenderWindow &window, const std::string &texture_path, float offset_x = 0,
                                    float offset_y = 0, float scale = 1, float scale_x = 1, float scale_y = 1);

    void display_outline(int sizeX, int sizeY) const;

    friend std::ostream &operator<<(std::ostream &os, const Map &st);

    float calculate_offset_x(int size, float scale) const;

    float calculate_offset_y(int size, float scale) const;

};

#endif