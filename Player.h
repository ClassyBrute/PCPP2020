#ifndef PLAYER_H
#define PLAYER_H

#include "libraries.h"

class Player{
private:
    sf::Vector2i coordinates;
    sf::Sprite skin;
    int player_health;
    int gold;

public:
    Player();
    ~Player();

    int move(sf::Vector2i coordinates);
    int health(int player_health);
    int bank(int gold);
    void death();
};

#endif
