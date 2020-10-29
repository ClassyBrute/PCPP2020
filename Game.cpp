#include "Game.h"

void Game::initWindow(){
    std::string title = "Super Fancy Magic Luke";
    sf::VideoMode window_bounds(window_size::width_window, window_size::height_window);
    int frame_limit = 60;

    this->window = new sf::RenderWindow(window_bounds, title);
    this->window->setFramerateLimit(frame_limit);
}

void Game::initMap(){
    this->map = new Map();
}

void Game::initPlayer(){
    this->player = new Player();
}

void Game::updateSFMLEvents(){
    while (this->window->pollEvent(this->event)){
        if (this->event.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::updatePlayerMove(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){     
        if (this->player->coordinates.y <= 0){
            this->player->coordinates.y == 0;
        }
        else   
            this->player->move({0.f, -5.f});
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        if (this->player->coordinates.x <= 0){
            this->player->coordinates.x == 0;
        }
        else
            this->player->move({-5.f, 0.f});
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        if (this->player->coordinates.y + this->player->player_texture.getSize().y >= window_size::height_window){
            this->player->coordinates.y == window_size::height_window - this->player->player_texture.getSize().y;
        }
        else
            this->player->move({0.f, 5.f});
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        if (this->player->coordinates.x + this->player->player_texture.getSize().x >= window_size::width_window){
            this->player->coordinates.x == window_size::width_window - this->player->player_texture.getSize().x;
        }
        else
            this->player->move({5.f, 0.f});
    }
}

void Game::update(){
    this->updateSFMLEvents();

    this->updatePlayerMove();
}

void Game::render(){
    this->window->clear();

    this->window->draw(this->map->background);

    for (int i = 0; i < this->map->gridLength; i++){
        for (int j = 0; i < this->map->gridLength; j++){
            this->window->draw(this->map->tiles[i][j]->sprite);
        }
    }
    
    this->window->draw(this->player->character);

    this->window->display();
}

void Game::run(){
	while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}

Game::Game(){
    this->initWindow();
    this->initMap();
    this->initPlayer();
}

Game::~Game(){
    delete this->window;
}
