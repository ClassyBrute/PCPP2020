#ifndef WEAPON_H
#define WEAPON_H

#include "libraries.h"

class Weapon{
private:
    sf::Vector2i coordinates;

public:

    Weapon();
    ~Weapon();

    int move_with_player(sf::Vector2i coordinates);
    void shoot();
};

#endif