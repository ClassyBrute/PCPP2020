#ifndef MAP_H
#define MAP_H

#include "libraries.h"
#include "constans.h"
#include "mapTile.h"

class Map{

    sf::Vector2i playerPos;
    // std::vector<sf::Vector2i> enemyPositions;
    void setUpInitialState();
    // void setUpEnemyPositions();
    void setUpTiles();

public:
    Map();
    ~Map();

    std::vector< std::vector<MapTile *> > tiles;
    int gridLength;

    sf::Texture background_texture;
    sf::Sprite background;
};

#endif
