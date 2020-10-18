#ifndef ENEMY_H
#define ENEMY_H

#include "Player.h"

class Enemy : public Player{
public:
    Enemy(sf::Vector2i coordinates, int enemy_health, sf::Sprite skin);
    ~Enemy();

    int move(sf::Vector2i coordinates);
    void death();

};

#endif