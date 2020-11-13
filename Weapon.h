#ifndef WEAPON_H
#define WEAPON_H

#include "libraries.h"

class Weapon{
private:
    sf::Texture weapon_texture;
    sf::Vector2f coordinates;

public:
    sf::Sprite weapon;

    int damage;
    double cooldown;
    float max_speed;

    Weapon(sf::String skin, sf::Vector2f coordinates, int damage, double cooldown, float max_speed);
    ~Weapon();
};

#endif