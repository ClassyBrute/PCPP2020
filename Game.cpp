#include "Game.h"

void Game::initWindow(){
    std::string title = "Super Fancy Magic Luke";
    sf::VideoMode window_bounds(constans::width_window, constans::height_window);
    int frame_limit = 60;

    this->window = new sf::RenderWindow(window_bounds, title);
    this->window->setFramerateLimit(frame_limit);

    this->mouse = sf::Vector2f(sf::Mouse::getPosition(*this->window));
    this->oldRotate = 0.f;
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

void Game::initWeapon(){
    this->weapon = new Weapon("textures/weapon.png", sf::Vector2f(this->player->character.getPosition().x + this->player->player_texture.getSize().y / 4, this->player->character.getPosition().y + this->player->player_texture.getSize().y / 2), 100, 2.0, 10.f);
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
        if (this->event.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::updateSFMLEventsInMenu(){
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
                                this->run();
                                break;
                            case 1:
                                break;
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
        if (this->player->coordinates.y + this->player->player_texture.getSize().y >= constans::height_window){
            this->player->coordinates.y == constans::height_window - this->player->player_texture.getSize().y;
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
        if (this->player->coordinates.x + this->player->player_texture.getSize().x >= constans::width_window){
            this->player->coordinates.x == constans::width_window - this->player->player_texture.getSize().x;
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

void Game::updateBulletMove(){
    mousePosWindow = sf::Vector2f(sf::Mouse::getPosition(*this->window));
    this->aimDir = sf::Vector2f(this->mousePosWindow.x - this->player->character.getPosition().x + this->player->player_texture.getSize().x / 2, this->mousePosWindow.y - this->player->character.getPosition().y + this->player->player_texture.getSize().y / 2);
    this->aimDirNorm = sf::Vector2f(this->aimDir.x / sqrt(pow(this->aimDir.x, 2) + pow(this->aimDir.y, 2)), this->aimDir.y / sqrt(pow(this->aimDir.x, 2) + pow(this->aimDir.y, 2)));

    for (size_t i = 0; i < this->bullets.size(); i++){
        this->bullets[i].bullet.move(bullets[i].velocity);
        
        if (this->bullets[i].bullet.getPosition().x < 0 || (this->bullets[i].bullet.getPosition().x > this->window->getSize().x || this->bullets[i].bullet.getPosition().y < 0 || this->bullets[i].bullet.getPosition().y > this->window->getSize().y))
                this->bullets.erase(this->bullets.begin() + i);
        else{
            for (unsigned j = 0; j < this->map->walls_lvl1.size(); j++){
                if (this->map->walls_lvl1[j].getGlobalBounds().intersects(this->bullets[i].bullet.getGlobalBounds())){
                    this->bullets.erase(this->bullets.begin() + i);
                    break;
                }
            }
        }
    }

    for (size_t i = 0; i < this->bullets.size(); i++){
        for (unsigned j = 0; j < this->enemies.size(); j++){
            if (this->enemies[j].character.getGlobalBounds().intersects(this->bullets[i].bullet.getGlobalBounds())){
                this->bullets.erase(this->bullets.begin() + i);
                this->enemies[j].health(this->weapon->damage);
                if (this->enemies[j].enemy_health <= 0)
                    this->enemies.erase(this->enemies.begin() + j);
                break;
            }
        }
    }
}

void Game::update(){
    this->updateSFMLEvents();
    this->updatePlayerMove();
    this->updateEnemyMove();

    this->weapon_position();
    this->updateBulletMove();

    this->window->clear();

}

void Game::render(){
    this->window->clear();
    this->window->draw(this->map->background);
    this->map->level1(this->window);

    this->drawBullets();

    for (size_t i = 0; i < this->bullets.size(); i++){
        this->window->draw(bullets[i].bullet);
    }

    this->window->draw(this->weapon->weapon);
    this->window->draw(this->player->character);
    this->drawEnemies();

    this->window->display();
}

void Game::render_menu(){
    this->window->clear();

    this->window->draw(this->menu->background);

    this->menu->drawMenu(this->window); 

    this->window->display();
}

void Game::run(){
	while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}

void Game::run_menu(){
    while (this->window->isOpen()){
        this->updateSFMLEventsInMenu();
        this->render_menu();
    }
}

void Game::weapon_position(){
    this->weapon->weapon.setPosition(sf::Vector2f(this->player->character.getPosition().x + this->player->player_texture.getSize().y / 4, this->player->character.getPosition().y + this->player->player_texture.getSize().y / 2));
    
    if (!(sf::Mouse::getPosition().x == this->mouse.x && sf::Mouse::getPosition().y == this->mouse.y)){
        sf::Vector2f position = sf::Vector2f(sf::Mouse::getPosition(*this->window));

        float dx = this->weapon->weapon.getPosition().x - position.x;
        float dy = this->weapon->weapon.getPosition().y - position.y;
        
        float rotation = (atan2(dy, dx)) * 180 / constans::PI + 90;

        this->weapon->weapon.rotate(-oldRotate);
        this->weapon->weapon.rotate(rotation);
        this->oldRotate = rotation;
        mouse = sf::Vector2f(sf::Mouse::getPosition());
    }
}

void Game::drawBullets(){  
    this->stop = clock();
    double elapsed = (this->stop - this->start) / (CLOCKS_PER_SEC / 10);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (start == 0 || elapsed >= this->weapon->cooldown)){
        this->bullet = new Bullet(this->weapon->damage, this->weapon->cooldown);
        this->bullet->bullet.setPosition(this->player->character.getPosition().x + this->player->player_texture.getSize().x / 2, this->player->character.getPosition().y + this->player->player_texture.getSize().y / 2);
        this->bullet->velocity = aimDirNorm * this->weapon->max_speed;

        this->bullets.push_back(*this->bullet);

        this->start = clock();
    }
}

Game::Game(){
    this->start = 0;

    this->initWindow();
    this->initMenu(); 
    this->initMap();
    this->initPlayer();
    this->initWeapon();
    this->createEnemies();
}

Game::~Game(){
    delete this->window;
}
