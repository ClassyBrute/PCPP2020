#include "Map.h"

Map::Map(){
    this->background_texture.loadFromFile("textures/map.png");
    this->background.setTexture(background_texture);
    
    this->wall_texture.loadFromFile("textures/tiles.png");
    this->wall.setTexture(wall_texture);
    for (int i = 0; i < 5; i++)
        this->walls.push_back(wall);
}

Map::~Map(){

}

void Map::level1(sf::RenderWindow* window){

    for (int i = 0; i < 5; i++){
        this->walls[i].setPosition(sf::Vector2f(100 * (i + 1),100 * (i + 1)));
        window->draw(this->walls[i]);
    }
        

}