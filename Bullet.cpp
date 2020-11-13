#include "Bullet.h"

Bullet::Bullet(int damage, double cooldown){
    this->damage = damage;
    this->cooldown = cooldown;

    this->velocity = sf::Vector2f(0.f, 0.f);

    this->bullet.setRadius(5.f);
    this->bullet.setFillColor(sf::Color::Red);

}

Bullet::~Bullet(){

}
