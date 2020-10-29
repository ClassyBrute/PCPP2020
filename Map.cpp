#include "Map.h"

Map::Map(){
    this->background_texture.loadFromFile("textures/map.png");
    this->background.setTexture(background_texture);
    
    // horizontal walls
    this->wall_texture_hor.loadFromFile("textures/wall_hor.png");
    this->wall_hor.setTexture(wall_texture_hor);
    for (int i = 0; i < 5; i++)
        this->walls_lvl1.push_back(wall_hor);
    
    // vertical walls
    this->wall_texture_ver.loadFromFile("textures/wall_ver.png");
    this->wall_ver.setTexture(wall_texture_ver);
    for (int i = 0; i < 7; i++)
        this->walls_lvl1.push_back(wall_ver);
}

Map::~Map(){

}

void Map::level1(sf::RenderWindow* window){

    // horizontal walls first
    this->walls_lvl1[0].setPosition(sf::Vector2f(550, 350));
    this->walls_lvl1[1].setPosition(sf::Vector2f(1000, 350));
    this->walls_lvl1[2].setPosition(sf::Vector2f(200, 650));
    this->walls_lvl1[3].setPosition(sf::Vector2f(300, 650));
    this->walls_lvl1[4].setPosition(sf::Vector2f(400, 200));

    // vertical walls now
    this->walls_lvl1[5].setPosition(sf::Vector2f(150, 150));
    this->walls_lvl1[6].setPosition(sf::Vector2f(150, 250));
    this->walls_lvl1[7].setPosition(sf::Vector2f(550, 200));
    this->walls_lvl1[8].setPosition(sf::Vector2f(850, -50));
    this->walls_lvl1[9].setPosition(sf::Vector2f(400, 850));
    this->walls_lvl1[10].setPosition(sf::Vector2f(850, 650));
    this->walls_lvl1[11].setPosition(sf::Vector2f(850, 850));

    for (int i = 0; i < 12; i++){
        window->draw(this->walls_lvl1[i]);
    }
        

}