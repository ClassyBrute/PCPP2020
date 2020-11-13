#include "Weapon.h"

Weapon::Weapon(sf::String skin, sf::Vector2f coordinates, int damage, double cooldown, float max_speed){
    this->coordinates = coordinates;

    this->weapon_texture.loadFromFile(skin);

    this->weapon.setTexture(this->weapon_texture);
    this->weapon.setPosition(coordinates);

    this->damage = damage;
    this->cooldown = cooldown;
    this->max_speed = max_speed;
}

Weapon::~Weapon(){

}
