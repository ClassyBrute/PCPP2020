#include "Map.h"

Map::Map(){

    action_music.openFromFile("sounds/audio_action.wav");

    buffer.loadFromFile("sounds/audio_gun.wav");
    shot.setBuffer(buffer);

    this->background_texture.loadFromFile("textures/map.png");
    this->background_texture_normal.loadFromFile("textures/map_normal.png");
    this->background_texture_hard.loadFromFile("textures/map_hard.png");
    
    // horizontal walls
    this->wall_texture_hor.loadFromFile("textures/wall_hor.png");
    this->wall_texture_hor_normal.loadFromFile("textures/wall_hor_normal.png");
    this->wall_texture_hor_hard.loadFromFile("textures/wall_hor_hard.png");
    
    // vertical walls
    this->wall_texture_ver.loadFromFile("textures/wall_ver.png");
    this->wall_texture_ver_normal.loadFromFile("textures/wall_ver_normal.png");
    this->wall_texture_ver_hard.loadFromFile("textures/wall_ver_hard.png");
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