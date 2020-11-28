#include "Heart.h"

Heart::Heart(sf::Vector2f coordinates){
    this->heart_texture.loadFromFile("textures/heart.png");
    this->heart.setTexture(this->heart_texture);
    this->heart.setPosition(coordinates);

}

Heart::~Heart(){

}
