#ifndef COIN_H
#define COIN_H

#include "libraries.h"

class Coin{
public:
    sf::Texture coin_texture;
    sf::Sprite coin;
    int value;

    Coin(sf::Vector2f coordinates, int value);
    ~Coin();

};

#endif