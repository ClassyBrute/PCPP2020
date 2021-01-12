#include "Weapon.h"

void Weapon::change_damage(int damage, int difficulty){
    this->damage = damage + difficulty;
}

Weapon::Weapon(sf::Vector2f coordinates, int damage, double cooldown, float max_speed){
    this->coordinates = coordinates;
    this->weapon.setPosition(coordinates);

    this->damage = damage;
    this->cooldown = cooldown;
    this->max_speed = max_speed;
}

Weapon::~Weapon(){

}
