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

void Game::initEnemy(sf::Vector2f coordinates, int enemy_health, sf::String skin){
    this->enemy = new Enemy(coordinates, enemy_health, skin);
    this->enemies.push_back(enemy->character);
}

void Game::drawEnemies(){
    for (unsigned i = 0; i < this->enemies.size(); i++){
        this->window->draw(this->enemies[i]);
    }
}

void Game::createEnemies(){
    this->initEnemy({10.f, 10.f}, 50, "textures/enemy.png");
    this->initEnemy({1000.f, 800.f}, 50, "textures/enemy2.png");
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
        else{
            this->player->move({0.f, -5.f});
            for (unsigned i = 0; i < this->map->walls_lvl1.size(); i++){
                if (this->map->walls_lvl1[i].getGlobalBounds().intersects(this->player->character.getGlobalBounds()))
                    this->player->move({0.f, 5.f});    
            }
        }
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        if (this->player->coordinates.x <= 0){
            this->player->coordinates.x == 0;
        }
        else{
            this->player->move({-5.f, 0.f});
            for (unsigned i = 0; i < this->map->walls_lvl1.size(); i++){
                if (this->map->walls_lvl1[i].getGlobalBounds().intersects(this->player->character.getGlobalBounds()))
                    this->player->move({5.f, 0.f});    
            }
        }
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        if (this->player->coordinates.y + this->player->player_texture.getSize().y >= window_size::height_window){
            this->player->coordinates.y == window_size::height_window - this->player->player_texture.getSize().y;
        }
        else{
            this->player->move({0.f, 5.f});
            for (unsigned i = 0; i < this->map->walls_lvl1.size(); i++){
                if (this->map->walls_lvl1[i].getGlobalBounds().intersects(this->player->character.getGlobalBounds()))
                    this->player->move({0.f, -5.f});    
            }
        }
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        if (this->player->coordinates.x + this->player->player_texture.getSize().x >= window_size::width_window){
            this->player->coordinates.x == window_size::width_window - this->player->player_texture.getSize().x;
        }
        else{
            this->player->move({5.f, 0.f});
            for (unsigned i = 0; i < this->map->walls_lvl1.size(); i++){
                if (this->map->walls_lvl1[i].getGlobalBounds().intersects(this->player->character.getGlobalBounds()))
                    this->player->move({-5.f, 0.f});    
            }
        }
    }
}

void Game::update(){
    this->updateSFMLEvents();

    this->updatePlayerMove();
}

void Game::render(){
    this->window->clear();

    this->window->draw(this->map->background);
    this->map->level1(this->window);
    this->window->draw(this->player->character);
    this->drawEnemies();

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
    this->createEnemies();
}

Game::~Game(){
    delete this->window;
}
