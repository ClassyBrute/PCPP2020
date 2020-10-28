#ifndef MAP_H
#define MAP_H

#include "libraries.h"
#include "constans.h"

class Map{

public:
    std::vector<std::vector<sf::Vector2i>> map;
    std::vector<sf::Vector2i> tempMap;

    Map();
    ~Map();

    sf::Texture background_texture;
    sf::Sprite background;

    sf::Texture tile_texture;
    sf::Sprite tiles;

    void updateTileMap();
    void drawTileMap();
};

#endif
