#include "../headers/Wall.h"

Wall::Wall() {
    // Load texture and set sprite properties
    if (!texture.loadFromFile("textures/wall.png")) {
        // Handle error if texture fails to load
        std::cout << "Error loading wall texture." << std::endl;
    }
    sprite.setTexture(texture);
    // Set other properties of the sprite as needed
}

Wall::Wall(float x, float y) {

    if (!texture.loadFromFile("textures/wall.png")) {
        // Handle error if texture fails to load
        std::cout << "Error loading wall texture." << std::endl;
    }
    sprite.setTexture(texture);
    // Set other properties of the sprite as needed
    sprite.setPosition(x, y);
}

Wall::~Wall() {

}

bool Wall::checkCollision(const sf::FloatRect &playerBounds) const {
    // Check collision between wall and player bounds
    return sprite.getGlobalBounds().intersects(playerBounds);
}
