#include "Map.h"

Map::Map(){
    this->background_texture.loadFromFile("textures/map.png");
    this->background.setTexture(background_texture);
    
    wall_texture.loadFromFile("textures/tiles.png");
    wall.setTexture(wall_texture);
}

Map::~Map(){

}

void Map::Level1(){


    wall.setPosition(sf::Vector2f(100,100));

}