#ifndef BULLET_H
#define BULLET_H

#include "libraries.h"

class Bullet{
public:
    sf::CircleShape bullet;
    sf::Vector2f velocity;

    int damage;
    double cooldown;

    Bullet(int damage, double cooldown);
    ~Bullet();

    void shoot();
};

#endif