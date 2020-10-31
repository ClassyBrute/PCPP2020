#include "Enemy.h"

Enemy::Enemy(sf::Vector2f coordinates, int enemy_health, sf::String skin){
    this->enemy_texture.loadFromFile(skin);

    this->character.setTexture(enemy_texture);
    this->character.setPosition(coordinates);

    this->enemy_health = enemy_health;

}

Enemy::~Enemy(){

}

int Enemy::move(sf::Vector2i coordinates){
    return 0;
}

void Enemy::death(){

}
