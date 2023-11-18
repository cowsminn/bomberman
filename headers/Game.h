#ifndef OOP_GAME_H
#define OOP_GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Wall.h"

class Game {
private:
    sf::RenderWindow window;
    Player player;
    std::vector<Wall> walls;
    sf::VertexArray rectangleWithBoxes;
    void initWindow();

    float calculate_offset_x(int size, float scale) const;

    float calculate_offset_y(int size, float scale) const;

    int lines, columns;

public:
    Game();

    Game(float dir_X, float dir_Y);
    ~Game();

    void run();
    void update();
    void render();

    static void display_at_position(sf::RenderWindow &window, const std::string &texture_path, float offset_x = 0,
                                    float offset_y = 0, float scale = 1, float scale_x = 1, float scale_y = 1);

    void display_outline(sf::RenderWindow &window, const std::string &texture_path, int sizeX, int sizeY);

    friend std::ostream &operator<<(std::ostream &os, const Game &st);

};

#endif //OOP_GAME_H
