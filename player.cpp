#include "player.h"



player::player() {
    if (!this->texture.loadFromFile("textures/yandhi.jpg")) {
        std::cout << "eroare : textura player" << '\n';
    }
}

player::~player() {


}

