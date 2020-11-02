#include "Game.h"

void Game::initWindow(){
    std::string title = "Super Fancy Magic Luke";
    sf::VideoMode window_bounds(window_size::width_window, window_size::height_window);
    int frame_limit = 60;

    this->window = new sf::RenderWindow(window_bounds, title);
    this->window->setFramerateLimit(frame_limit);
}

void Game::initMenu(){
    this->menu = new Menu(this->window->getSize().x, this->window->getSize().y);
}

void Game::initMap(){
    this->map = new Map();
}

void Game::initPlayer(){
    this->player = new Player();
}

void Game::initEnemy(sf::Vector2f coordinates, int enemy_health, sf::String skin, int damage, float speed, int speed_attack){
    this->enemy = new Enemy(coordinates, enemy_health, skin, damage, speed, speed_attack);
    this->enemies.push_back(*enemy);
}

void Game::drawEnemies(){
    for (unsigned i = 0; i < this->enemies.size(); i++){
        this->window->draw(this->enemies[i].character);
    }
}

void Game::createEnemies(){
    this->initEnemy({10.f, 10.f}, 50, "textures/enemy.png", 10, 2.5f, 5);
    this->initEnemy({1000.f, 800.f}, 50, "textures/enemy2.png", 15, 3.f, 4);
}

void Game::updateSFMLEvents(){
    while (this->window->pollEvent(this->event)){

        switch (event.type){

            case sf::Event::KeyReleased:
                switch (event.key.code){
                    case sf::Keyboard::W:
                        menu->MoveUp();
                        break;

                    case sf::Keyboard::S:
                        menu->MoveDown();
                        break;

                    case sf::Keyboard::Return:
                        switch (menu->GetPressedItem()){
                            case 0:
                                continue;
                            case 1:
                                continue;
                            case 2:
                                this->window->close();
                        }
                }
        }

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

void Game::updateEnemyMove(){
    for (unsigned i = 0; i < this->enemies.size(); i++){
        if (!this->player->character.getGlobalBounds().intersects(this->enemies[i].character.getGlobalBounds())){
            this->enemies[i].start = 0;

            if (this->player->coordinates.x > this->enemies[i].coordinates.x){
                this->enemies[i].move({this->enemies[i].enemy_speed, 0.f});
                
                for (unsigned j = 0; j < this->map->walls_lvl1.size(); j++){
                    if (this->map->walls_lvl1[j].getGlobalBounds().intersects(this->enemies[i].character.getGlobalBounds()))
                        this->enemies[i].move({-this->enemies[i].enemy_speed, 0.f});    
                }
            }
            else if (this->player->coordinates.x < this->enemies[i].coordinates.x){
                this->enemies[i].move({-this->enemies[i].enemy_speed, 0.f});

                for (unsigned j = 0; j < this->map->walls_lvl1.size(); j++){
                    if (this->map->walls_lvl1[j].getGlobalBounds().intersects(this->enemies[i].character.getGlobalBounds()))
                        this->enemies[i].move({this->enemies[i].enemy_speed, 0.f});    
                }
            }
            
            if (this->player->coordinates.y > this->enemies[i].coordinates.y){
                this->enemies[i].move({0.f, this->enemies[i].enemy_speed});

                for (unsigned j = 0; j < this->map->walls_lvl1.size(); j++){
                    if (this->map->walls_lvl1[j].getGlobalBounds().intersects(this->enemies[i].character.getGlobalBounds()))
                        this->enemies[i].move({0.f, -this->enemies[i].enemy_speed});    
                }
            }
            else if (this->player->coordinates.y < this->enemies[i].coordinates.y){
                this->enemies[i].move({0.f, -this->enemies[i].enemy_speed});

                for (unsigned j = 0; j < this->map->walls_lvl1.size(); j++){
                    if (this->map->walls_lvl1[j].getGlobalBounds().intersects(this->enemies[i].character.getGlobalBounds()))
                        this->enemies[i].move({0.f, this->enemies[i].enemy_speed});    
                }
            }
        }
        else
            this->player->health(-this->enemies[i].attack());
    }
}

void Game::update(){
    this->updateSFMLEvents();
    this->updatePlayerMove();
    this->updateEnemyMove();
    this->window->clear();

    this->menu->drawMenu(this->window); 
    this->window->display();

}

void Game::render(){
    // this->window->clear();

    // this->menu->drawMenu(this->window);
    this->window->draw(this->map->background);
    this->map->level1(this->window);
    this->window->draw(this->player->character);
    this->drawEnemies();

    // this->window->display();
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
    this->initMenu(); 
    this->initMap();
    this->initPlayer();
    this->createEnemies();
}

Game::~Game(){
    delete this->window;
}
