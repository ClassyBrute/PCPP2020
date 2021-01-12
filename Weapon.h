#ifndef WEAPON_H
#define WEAPON_H

#include "libraries.h"

class Weapon{
private:
    sf::Vector2f coordinates;

public:
    sf::Sprite weapon;

    int damage;
    double cooldown;
    float max_speed;

    void change_damage(int damage, int difficulty);

    Weapon(sf::Vector2f coordinates, int damage, double cooldown, float max_speed);
    ~Weapon();
};

#endif