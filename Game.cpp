#include "Game.h"

Game::Game()
{
    this->window = nullptr;
    this->initWindow();
    this->initPlayer();

}

Game::~Game()
{
    delete this->window;
    delete this->player;

}

void Game::run()
{
    while(this->window->isOpen()) {
        while (this->window->pollEvent(e)) {
            switch (e.type) {
                case sf::Event::Closed:
                    this->window->close();
                    break;
                case sf::Event::Resized:
                    std::cout << "New width: " << this->window->getSize().x << '\n'
                              << "New height: " << this->window->getSize().y << '\n';
                    break;
                case sf::Event::KeyPressed:
                    if (e.key.code == sf::Keyboard::Escape)
                        this->window->close();
                    else { std::cout << "Received key " << (e.key.code == sf::Keyboard::X ? "X" : "(other)") << "\n"; }
                        break;

                default:
                    break;
            }
        }
        this->update();
        this->render();
    }

}

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode({800, 700}), "BomberMan", sf::Style::Default);
    this->window->setFramerateLimit(59);
    this->window->setVerticalSyncEnabled(false);
}

void Game::render()
{
    this->window->clear(sf::Color::White);
    this->player->render(*this->window);
    this->window->display();



}

void Game::update() {

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->player->move(-1.f,0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->player->move(1.f,0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->player->move(0.f,-1.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->player->move(0.f,1.f);


}

void Game::initPlayer() {

    this->player = new class Player();

}

