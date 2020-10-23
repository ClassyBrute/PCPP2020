#ifndef PLAYER_H
#define PLAYER_H

#include "libraries.h"
#include "constans.h"

class Player{
private:
    sf::Texture player_texture;
    sf::Vector2f coordinates;

public:
    Player();
    ~Player();

    sf::Sprite character;
    int player_health;
    int gold;

    void move(sf::Vector2f coordinates);
    void health(int player_health);
    void death();
    void bank(int gold);
};

#endif
