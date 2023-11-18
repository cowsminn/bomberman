#include "../headers/Game.h"

Game::Game() : lines(0), columns(0), window(sf::VideoMode({1280, 720}), "BomberMan", sf::Style::Default) {
    this->initWindow();
}

Game::~Game() {}

//std::ostream &operator<<(std::ostream &os, const Game &st) {
//    std::cout << "test";
//    return os;
//}

void Game::run() {
    while (this->window.isOpen()) {
        sf::Event e{};
        while (this->window.pollEvent(e)) {
            switch (e.type) {
                case sf::Event::Closed:
                    this->window.close();
                    break;
                case sf::Event::Resized:
                    std::cout << "New width: " << this->window.getSize().x << '\n'
                              << "New height: " << this->window.getSize().y << '\n';
                    break;
                case sf::Event::KeyPressed:
                    if (e.key.code == sf::Keyboard::Escape)
                        this->window.close();
                    else {
                        std::cout << "Received key " << (e.key.code == sf::Keyboard::X ? "X" : "(other)") << "\n";
                    }
                    break;
                default:
                    break;
            }
        }
        this->update();
        this->render();
    }
}

void Game::initWindow() {
    this->window.create(sf::VideoMode({1280, 720}), "BomberMan", sf::Style::Default);
    this->window.setFramerateLimit(59);
    this->window.setVerticalSyncEnabled(false);
}

void Game::render() {
    this->window.clear(sf::Color::White);
    this->player.render(this->window);
    this->display_outline(this->window, "textures/Bark.png", 14, 8);
    this->window.display();
}

void Game::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        this->player.move(-1.f, 0.f);
        this->player.update();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        this->player.move(1.f, 0.f);
        this->player.update();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        this->player.move(0.f, -1.f);
        this->player.update();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        this->player.move(0.f, 1.f);
        this->player.update();
    }
}

void
Game::display_at_position(sf::RenderWindow &window, const std::string &texture_path, float offset_x, float offset_y,
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

void Game::display_outline(sf::RenderWindow &window, const std::string &texture_path, int sizeX, int sizeY) {
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

float Game::calculate_offset_x(int size, float scale) const {
    float offset_x = (float(window.getSize().x) - 64 * scale * float(size)) / 2;
    return offset_x;
}

float Game::calculate_offset_y(int size, float scale) const {
    float offset_y = (float(window.getSize().y) - 64 * scale * float(size)) / 2;
    return offset_y;
}



