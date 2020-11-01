#ifndef ENEMY_H
#define ENEMY_H

#include "libraries.h"

class Enemy{
public:
    sf::Vector2f coordinates;
    sf::Texture enemy_texture;
    sf::Sprite character;

    clock_t start;
    clock_t stop;

    int enemy_health;
    int enemy_speed;
    int speed_attack;
    int damage;

    Enemy(sf::Vector2f coordinates, int enemy_health, sf::String skin, int damage, float speed, int speed_attack);
    ~Enemy();

    void move(sf::Vector2f coordinates);
    void death();

    int attack();

};

#endif