#include "Player.h"

Player::Player(){
    this->player_texture.loadFromFile("textures/player.png");

    float player_width = (constans::width_window / 2) - (player_texture.getSize().x / 2);
    float player_height = (constans::height_window / 2) - (player_texture.getSize().y / 2);
    this->coordinates = {player_width, player_height};

    this->character.setTexture(player_texture);
    this->character.setPosition(coordinates);

    this->player_health = 100;

    this->gold = 100;
}

Player::~Player(){

}

void Player::move(sf::Vector2f coordinates){
    this->coordinates.x += coordinates.x;
    this->coordinates.y += coordinates.y;

    this->character.setPosition(this->coordinates);
}

void Player::health(int player_health){
    this->player_health += player_health;

    if (this->player_health <= 0)
        this->death();
    else if (this->player_health > 100)
        this->player_health = 100;
        

    std::cout << this->player_health << '\n';
}

void Player::death(){
    this->player_health = 100;
}

void Player::bank(int gold){
    this->gold += gold;
    std::cout << this->gold << '\n';
}
