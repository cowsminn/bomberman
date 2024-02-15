#include "../headers/Wall.h"

Wall::Wall() {
    if (!texture.loadFromFile("textures/wall.png")) {
        std::cout << "Error loading wall texture." << std::endl;
    }
    sprite.setTexture(texture);

}

Wall::Wall(float x, float y) {

    if (!texture.loadFromFile("textures/wall.png")) {

        std::cout << "Error loading wall texture." << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
}

Wall::~Wall() {

}

