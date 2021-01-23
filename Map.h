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
    sf::Texture background_texture_normal;
    sf::Texture background_texture_hard;
    sf::Sprite background;

    sf::Texture wall_texture_hor;
    sf::Texture wall_texture_hor_normal;
    sf::Texture wall_texture_hor_hard;
    sf::Sprite wall_hor;
    
    sf::Texture wall_texture_ver;
    sf::Texture wall_texture_ver_normal;
    sf::Texture wall_texture_ver_hard;
    sf::Sprite wall_ver;

    void level1(sf::RenderWindow* window);

};

#endif
