#include "../headers/Wall.h"

Wall::Wall() {
    if (!texture.loadFromFile("textures/wall.png")) {
        throw FailedTextureLoad("wall.png");
    }
    sprite.setTexture(texture);

}

Wall::Wall(float x, float y) {
    try {
        if (!texture.loadFromFile("textures/wall.png")) {
            throw FailedTextureLoad("wall.png");
        }
        sprite.setTexture(texture);
        sprite.setPosition(x, y);
    } catch(const CustomException& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}


Wall::~Wall() {

}

