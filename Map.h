#ifndef MAP_H
#define MAP_H

#include "libraries.h"
#include "constans.h"

class Map{

public:

    Map();
    ~Map();

    std::vector<sf::Sprite> walls_lvl1;

    sf::Texture background_texture;
    sf::Sprite background;

    sf::Texture wall_texture_hor;
    sf::Sprite wall_hor;
    sf::Texture wall_texture_ver;
    sf::Sprite wall_ver;

    void level1(sf::RenderWindow* window);

};

#endif
