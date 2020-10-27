#ifndef MAP_H
#define MAP_H

#include "libraries.h"
#include "constans.h"

class Map{

public:
    Map();
    ~Map();

    sf::Texture background_texture;
    sf::Sprite background;

    sf::Texture tile_texture;
    sf::Sprite tiles;

    void updateTileMap();
    void drawTileMap(std::vector<std::vector<sf::Vector2i>> , std::vector<sf::Vector2i>);
};

#endif
