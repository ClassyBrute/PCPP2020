#ifndef ENEMY_H
#define ENEMY_H

#include "libraries.h"

class Enemy{
public:
    sf::Texture enemy_texture;
    sf::Sprite character;
    sf::Vector2f coordinates;
    int enemy_health;

    Enemy(sf::Vector2f coordinates, int enemy_health, sf::String skin);
    ~Enemy();

    int move(sf::Vector2i coordinates);
    void death();

};

#endif