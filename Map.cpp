#include "Map.h"

Map::Map(){
    this->background_texture.loadFromFile("textures/map.png");

    this->background.setTexture(background_texture);

    this->tile_texture.loadFromFile("textures/tiles.png");

    this->tiles.setTexture(tile_texture);
}

Map::~Map(){

}

void Map::updateTileMap(){
    std::ifstream openfile("map.txt");

    std::vector<std::vector<sf::Vector2i>> map;
    std::vector<sf::Vector2i> tempMap;

    if(openfile.is_open()){
        while(!openfile.eof()){
            std::string str;
            openfile >> str;
            char x = str[0], y = str[2];
            if(!isdigit(x) || !isdigit(y))
                tempMap.push_back(sf::Vector2i(-1, -1));
            else
                tempMap.push_back(sf::Vector2i(x - '0', y - '0'));

            if(openfile.peek() == '\n'){
                map.push_back(tempMap);
                tempMap.clear();
            }
        }
        map.push_back(tempMap);
    }
}


void Map::drawTileMap(std::vector<std::vector<sf::Vector2i>> map, std::vector<sf::Vector2i> tempMap){
    for(int i = 0; i < map.size(); i++){
        for(int j = 0; j < map[j].size(); j++){
            if(map[i][j].x != -1 && map[i][j].y != -1){
                tiles.setPosition(j * 50, i * 50);
                tiles.setTextureRect(sf::IntRect(map[i][j].x * 50, map[i][j].y * 50, 50, 50));
            }
        }
    }
}
