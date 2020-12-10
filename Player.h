#ifndef PLAYER_H
#define PLAYER_H

#include "libraries.h"
#include "constans.h"

class Player{

public:
    Player();
    ~Player();

    sf::Texture player_texture;
    sf::Sprite character;
    sf::Vector2f coordinates;
    int player_health;
    int gold;

    void move(sf::Vector2f coordinates);
    void reset_position();
    void health(int player_health);
    void death();
    void bank(int gold);
};

#endif
