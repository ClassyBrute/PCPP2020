#ifndef HEART_H
#define HEART_H

#include "libraries.h"

class Heart{
public:
    sf::Texture heart_texture;
    sf::Sprite heart;

    Heart(sf::Vector2f coordinates);
    ~Heart();

};

#endif