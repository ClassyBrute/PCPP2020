#include "Map.h"

Map::Map(){
    this->background_texture.loadFromFile("textures/map.png");

    this->background.setTexture(background_texture);

    gridLength = 5;
    setUpInitialState();

}

Map::~Map(){

}


void Map::setUpInitialState(){
    
    setUpTiles();
}

void Map::setUpTiles(){

    tiles.clear();

    std::vector<MapTile *> walls;
    walls.push_back(new MapTile("textures/tiles.png", 20, 50, false));
    walls.push_back(new MapTile("textures/tiles.png", 200, 100, false));
    walls.push_back(new MapTile("textures/tiles.png", 500, 400, false));
    walls.push_back(new MapTile("textures/tiles.png", 600, 600, false));
    tiles.push_back(walls);
}