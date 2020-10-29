#include "mapTile.h"

MapTile::MapTile(std::string textureName, float x, float y, bool passable){

    if (!setUpSprite(textureName)){
        return;
    }

    pos = sf::Vector2f(x,y);
    sprite.setPosition(pos);
    isPassable = passable;
}

MapTile::~MapTile(){

}

bool MapTile::setUpSprite(std::string textureName){

    if (!texture.loadFromFile(textureName)){
        return false;
    }

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,50,50));
    
    return true;
}