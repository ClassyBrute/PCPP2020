#ifndef MAP_H
#define MAP_H

#include "libraries.h"
#include "constans.h"

class Map{

public:

    Map();
    ~Map();

    std::vector<sf::Sprite> walls;

    sf::Texture background_texture;
    sf::Sprite background;

    sf::Texture wall_texture;
    sf::Sprite wall;

    void level1(sf::RenderWindow* window);

};

#endif
