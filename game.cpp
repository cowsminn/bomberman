#include "game.h"

game::game()
{
    this->initWindow();

}

game::~game()
{
    delete this->window;

}

void game::run()
{
    while(this->window->isOpen()) {
        sf::Event e;
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
                    if(e.key.code == sf::Keyboard::Escape)
                        this->window->close();
                        else std::cout << "Received key " << (e.key.code == sf::Keyboard::X ? "X" : "(other)") << "\n";
                        break;

                default:
                    break;
            }
        }
        this->update();
        this->render();
    }
    this->window->clear();
    this->window->display();
}

void game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode({800, 700}), "BomberMan", sf::Style::Default);

}

void game::render()
{
    this->window->clear();

    this->window->display();


}

void game::update() {

}
