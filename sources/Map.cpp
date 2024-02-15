#include "../headers/Map.h"

Map::Map(sf::RenderWindow &window) : window(window), columns(), lines() {
    this->initTexture();
    this->initSprite();
    this->texture_path = "textures/wall.png";
}

Map::~Map() {

}

void Map::initSprite() {
    this->sprite.setTexture(this->texture);
    this->sprite.scale(1.f, 1.f);

}

void Map::initTexture() {

    if (!this->texture.loadFromFile("textures/wall.png")) {
        std::cout << "eroare : textura Outline" << '\n';
    }

}

void Map::display_at_position(sf::RenderWindow &window, const std::string &texture_path, float offset_x, float offset_y,
                              float scale, float scale_x, float scale_y) {
    sf::Sprite sprite;
    sf::Texture texture;
    if (!texture.loadFromFile(texture_path)) {
        std::cerr << "err " << texture_path << '\n';
        return;
    }
    sprite.setTexture(texture);
    sprite.setPosition(offset_x, offset_y);
    sprite.setScale(scale_x * scale, scale_y * scale);
    window.draw(sprite);
}

void Map::display_outline(int sizeX, int sizeY) const {
    float scale = 1.0f;

    float offset_x = calculate_offset_x(sizeX, scale);
    float offset_y = calculate_offset_y(sizeY, scale);

    for (int i = 0; i < sizeX; ++i) {
        display_at_position(window, texture_path, offset_x + i * 64 * scale, offset_y, scale, 0.8f, 0.8f);
        display_at_position(window, texture_path, offset_x + i * 64 * scale, offset_y + (sizeY - 1) * 64 * scale, scale,
                            0.8f, 0.8f);
    }
    for (int j = 1; j < sizeY - 1; ++j) {
        display_at_position(window, texture_path, offset_x, offset_y + j * 64 * scale, scale, 0.8f, 0.8f);
        display_at_position(window, texture_path, offset_x + (sizeX - 1) * 64 * scale, offset_y + j * 64 * scale, scale,
                            0.8f, 0.8f);
    }
}

float Map::calculate_offset_x(int size, float scale) const {
    float offset_x = (float(window.getSize().x) - 64 * scale * float(size)) / 2;
    return offset_x;
}

float Map::calculate_offset_y(int size, float scale) const {
    float offset_y = (float(window.getSize().y) - 64 * scale * float(size)) / 2;
    return offset_y;
}

Map::Map(const Map &other) : window(other.window),
                             sprite(other.sprite),
                             texture(other.texture),
                             texture_path(other.texture_path),
                             columns(other.columns),
                             lines(other.lines) {
}

std::ostream &operator<<(std::ostream &os, const Map &map) {
    os << "texture path: " << map.texture_path << "\n";
    os << "columns: " << map.columns << "\n";
    os << "lines: " << map.lines << "\n";
    return os;
}
