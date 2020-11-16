#include "Coin.h"

Coin::Coin(sf::Vector2f coordinates, int value){
    this->coin_texture.loadFromFile("textures/coin.png");
    this->coin.setTexture(this->coin_texture);
    this->coin.setPosition(coordinates);

    this->value = value;
}

Coin::~Coin(){

}
