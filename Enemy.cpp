#include "Enemy.h"

Enemy::Enemy(sf::Vector2f coordinates, int enemy_health, sf::String skin, int damage, float speed, int speed_attack){
    this->coordinates = coordinates;

    this->enemy_texture.loadFromFile(skin);

    this->character.setTexture(enemy_texture);
    this->character.setPosition(this->coordinates);

    this->enemy_health = enemy_health;

    this->enemy_speed = speed;

    this->speed_attack = speed_attack;

    this->damage = damage;

    this->start = 0;
}

Enemy::~Enemy(){

}

void Enemy::move(sf::Vector2f coordinates){
    this->coordinates.x += coordinates.x;
    this->coordinates.y += coordinates.y;
    
    this->character.setPosition(this->coordinates);
}

void Enemy::death(){

}

int Enemy::attack(){
    if (start == 0){
        this->start = clock();
        return this->damage;
    }
    
    this->stop = clock();

    double elapsed = (this->stop - this->start) / (CLOCKS_PER_SEC / 10);

    if (elapsed >= this->speed_attack){
        this->start = clock();
        return this->damage;
    }
    else
        return 0;   
}
