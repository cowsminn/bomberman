#include "../headers/Game.h"

Game::Game() : map(window), bomb() {
    this->initWindow();
    bombCooldownClock.restart();
    bombCooldownDuration = sf::seconds(5.0f);
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
                    else if (e.key.code == sf::Keyboard::Space && test) {
                        /// In caz ca vreau sa pun bomba instant fara cooldown
                        bomb.activate();
                        bomb.setPosition(player.getPosition().x, player.getPosition().y);
                        test = 0;
                    } else {
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
    bomb.draw(this->window);
    this->map.display_outline(14, 8);
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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && bombCooldownClock.getElapsedTime() > bombCooldownDuration) {
        bomb.activate();
        bomb.setPosition(player.getPosition().x, player.getPosition().y);

        bombCooldownClock.restart();
    }
}
