#ifndef MAPTILE_H
#define MAPTILE_H

#include "libraries.h"
#include "constans.h"

class MapTile{

public:

// can player/enemy move through it
    bool isPassable;
    // bool isExit;

    sf::Vector2f pos;
    sf::Texture texture;
    sf::Sprite sprite;
    
    MapTile(std::string, float, float, bool);
    ~MapTile();

    bool setUpSprite(std::string);

};

#endif
