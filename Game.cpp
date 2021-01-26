#include "Game.h"

void Game::initWindow(){
    std::string title = "Super Fancy Magic Luke";
    sf::VideoMode window_bounds(constans::width_window, constans::height_window);
    // this->icon->loadFromFile("textures/player.png");
    // this->window->setIcon(40, 40, this->icon->getPixelsPtr());
    int frame_limit = 60;

    this->window = new sf::RenderWindow(window_bounds, title);
    this->window->setFramerateLimit(frame_limit);

    this->mouse = sf::Vector2f(sf::Mouse::getPosition(*this->window));
    this->oldRotate = 0.f;
}

void Game::initMenu(){
    this->menu = new Menu(this->window->getSize().x, this->window->getSize().y);
}

void Game::initMenuHelp(){
    this->menu_help = new MenuHelp(this->window->getSize().x, this->window->getSize().y);
}

void Game::initMenuShop(){
    this->menu_shop = new MenuShop(this->window->getSize().x, this->window->getSize().y);
}

void Game::initMenuGameEnd(){
    this->menu_game_end = new MenuGameEnd();
}

void Game::initMenuDiffic(){
    this->menu_diffic = new MenuDiffic(this->window->getSize().x, this->window->getSize().y);
}

void Game::initMap(){
    this->map = new Map();
}

void Game::initPlayer(){
    this->player = new Player();
}

void Game::initWeapon(){
    this->weapon = new Weapon(sf::Vector2f(this->player->character.getPosition().x + this->player->player_texture.getSize().y / 4, this->player->character.getPosition().y + this->player->player_texture.getSize().y / 2), 100, 0.5, 5.f);
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

void Game::level1(){
    this->initEnemy({10.f, 10.f}, 100, "textures/enemy.png", 10, 2.5f, 5);
    this->initEnemy({1000.f, 800.f}, 100, "textures/enemy2.png", 15, 3.f, 4);
    this->initEnemy({10.f, 800.f}, 110, "textures/enemy.png", 10, 2.f, 5);
}

void Game::level2(){
    this->initEnemy({30.f, 20.f}, 100, "textures/enemy.png", 20, 2.5f, 6);
    this->initEnemy({900.f, 800.f}, 100, "textures/enemy2.png", 15, 2.5f, 4);
    this->initEnemy({10.f, 900.f}, 110, "textures/enemy.png", 15, 2.f, 5);
    this->initEnemy({1000.f, 20.f}, 100, "textures/enemy2.png", 20, 3.f, 3);
}

void Game::level3(){
    this->initEnemy({10.f, 10.f}, 130, "textures/enemy.png", 30, 3.f, 5);
    this->initEnemy({900.f, 800.f}, 150, "textures/enemy2.png", 15, 2.f, 4);
    this->initEnemy({1000.f, 800.f}, 110, "textures/enemy.png", 20, 2.f, 3);
    this->initEnemy({900.f, 25.f}, 120, "textures/enemy2.png", 20, 3.5f, 3);
    this->initEnemy({150.f, 500.f}, 150, "textures/enemy2.png", 20, 2.f, 5);
}

void Game::level4(){
    this->initEnemy({10.f, 10.f}, 130, "textures/enemy.png", 30, 3.f, 5);
    this->initEnemy({30.f, 500.f}, 100, "textures/enemy.png", 20, 2.5f, 6);
    this->initEnemy({900.f, 800.f}, 150, "textures/enemy2.png", 15, 2.f, 4);
    this->initEnemy({1000.f, 800.f}, 110, "textures/enemy.png", 20, 2.f, 3);
    this->initEnemy({25.f, 900.f}, 120, "textures/enemy2.png", 20, 3.5f, 3);
    this->initEnemy({300.f, 50.f}, 150, "textures/enemy2.png", 20, 2.f, 5);
    this->initEnemy({1000.f, 20.f}, 100, "textures/enemy.png", 20, 3.f, 3);
}

void Game::level5(){
    this->initEnemy({10.f, 10.f}, 150, "textures/enemy.png", 35, 3.f, 4);
    this->initEnemy({30.f, 500.f}, 140, "textures/enemy.png", 25, 2.5f, 4);
    this->initEnemy({900.f, 800.f}, 200, "textures/enemy2.png", 20, 2.5f, 4);
    this->initEnemy({100.f, 800.f}, 160, "textures/enemy.png", 40, 2.5f, 3);
    this->initEnemy({25.f, 900.f}, 150, "textures/enemy2.png", 30, 3.5f, 3);
    this->initEnemy({300.f, 50.f}, 150, "textures/enemy2.png", 35, 2.5f, 4);
    this->initEnemy({1000.f, 20.f}, 130, "textures/enemy.png", 45, 3.f, 2);
}

void Game::level6(){
    this->initEnemy({10.f, 500.f}, 170, "textures/enemy.png", 35, 4.f, 3);
    this->initEnemy({30.f, 500.f}, 170, "textures/enemy.png", 35, 2.5f, 2);
    this->initEnemy({1000.f, 800.f}, 250, "textures/enemy2.png", 25, 4.f, 4);
    this->initEnemy({100.f, 800.f}, 210, "textures/enemy.png", 40, 2.5f, 3);
    this->initEnemy({25.f, 900.f}, 200, "textures/enemy2.png", 35, 4.f, 3);
    this->initEnemy({300.f, 50.f}, 200, "textures/enemy2.png", 40, 2.5f, 3);
    this->initEnemy({1000.f, 70.f}, 160, "textures/enemy.png", 50, 3.5f, 2);
}

void Game::level7(){
    this->initEnemy({10.f, 500.f}, 210, "textures/enemy.png", 60, 4.f, 2);
    this->initEnemy({30.f, 500.f}, 210, "textures/enemy.png", 40, 3.f, 2);
    this->initEnemy({1000.f, 800.f}, 260, "textures/enemy2.png", 35, 5.f, 3);
    this->initEnemy({100.f, 800.f}, 210, "textures/enemy.png", 40, 3.f, 3);
    this->initEnemy({25.f, 900.f}, 230, "textures/enemy2.png", 45, 4.f, 3);
    this->initEnemy({25.f, 700.f}, 210, "textures/enemy2.png", 40, 4.f, 2);
    this->initEnemy({300.f, 50.f}, 220, "textures/enemy2.png", 40, 4.f, 2);
    this->initEnemy({1000.f, 70.f}, 220, "textures/enemy.png", 60, 4.f, 2);
}

void Game::level8(){
    this->initEnemy({10.f, 500.f}, 240, "textures/enemy.png", 70, 4.f, 2);
    this->initEnemy({30.f, 500.f}, 240, "textures/enemy.png", 70, 4.f, 2);
    this->initEnemy({1000.f, 800.f}, 300, "textures/enemy2.png", 45, 4.f, 1);
    this->initEnemy({100.f, 800.f}, 250, "textures/enemy.png", 55, 4.f, 2);
    this->initEnemy({25.f, 900.f}, 260, "textures/enemy2.png", 50, 4.f, 2);
    this->initEnemy({25.f, 700.f}, 250, "textures/enemy2.png", 60, 4.f, 2);
    this->initEnemy({300.f, 50.f}, 250, "textures/enemy2.png", 50, 4.f, 2);
    this->initEnemy({1000.f, 70.f}, 250, "textures/enemy.png", 65, 4.f, 2);
}

void Game::level9(){
    this->initEnemy({10.f, 500.f}, 260, "textures/enemy.png", 70, 4.f, 2);
    this->initEnemy({30.f, 500.f}, 270, "textures/enemy.png", 70, 4.f, 2);
    this->initEnemy({1000.f, 800.f}, 310, "textures/enemy2.png", 55, 4.f, 1);
    this->initEnemy({100.f, 800.f}, 280, "textures/enemy.png", 60, 4.f, 2);
    this->initEnemy({25.f, 900.f}, 260, "textures/enemy2.png", 60, 4.f, 2);
    this->initEnemy({25.f, 700.f}, 290, "textures/enemy2.png", 65, 4.f, 2);
    this->initEnemy({300.f, 50.f}, 290, "textures/enemy2.png", 60, 4.f, 2);
    this->initEnemy({1000.f, 70.f}, 280, "textures/enemy.png", 70, 4.f, 2);
}

void Game::level10(){
    this->initEnemy({10.f, 500.f}, 300, "textures/enemy.png", 70, 4.f, 2);
    this->initEnemy({30.f, 500.f}, 310, "textures/enemy.png", 70, 4.f, 2);
    this->initEnemy({1000.f, 800.f}, 360, "textures/enemy2.png", 50, 4.f, 1);
    this->initEnemy({100.f, 800.f}, 300, "textures/enemy.png", 55, 4.f, 2);
    this->initEnemy({25.f, 900.f}, 300, "textures/enemy2.png", 60, 4.f, 2);
    this->initEnemy({25.f, 700.f}, 280, "textures/enemy2.png", 60, 4.f, 2);
    this->initEnemy({300.f, 50.f}, 280, "textures/enemy2.png", 60, 4.f, 2);
    this->initEnemy({1000.f, 70.f}, 270, "textures/enemy.png", 65, 4.f, 2);
}

void Game::next_level(){
    this->player->reset_position();
    this->bullets.clear();
    this->menu->menu_music.pause();
    this->map->action_music.play();

    switch(this->current_level){
        case 1:
            this->level1();
            break;
        case 2:
            this->level2();
            break;
        case 3:
            this->level3();
            break;
        case 4:
            this->level4();
            break;
        case 5:
            this->level5();
            break;
        case 6:
            this->level6();
            break;
        case 7:
            this->level7();
            break;
        case 8:
            this->level8();
            break;
        case 9:
            this->level9();
            break;
        case 10:
            this->level10();
            break;

        default:
            this->menu_game_end->draw(this->window->getSize().x, this->window->getSize().y,  this->player->total_gold, this->time);
            this->render_menu_game_end();
            this->run_menu_game_end();

            break;

    }
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
                                this->render_menu_diffic();
                                this->run_menu_diffic();
                                break;
                            case 1:
                                this->render_menu_help();
                                this->run_menu_help();
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

void Game::updateSFMLEventsInMenuDiffic(){
    while (this->window->pollEvent(this->event)){

        switch (event.type){

            case sf::Event::KeyReleased:
                switch (event.key.code){
                    case sf::Keyboard::W:
                        menu_diffic->MoveUp();
                        break;

                    case sf::Keyboard::S:
                        menu_diffic->MoveDown();
                        break;

                    case sf::Keyboard::Return:
                        switch (menu_diffic->GetPressedItem()){
                            case 0:

                                this->map->walls_lvl1.clear();
                                this->map->background.setTexture(this->map->background_texture);                                
                                this->map->wall_hor.setTexture(this->map->wall_texture_hor);
                                for (int i = 0; i < 5; i++)
                                    this->map->walls_lvl1.push_back(this->map->wall_hor);
                                
                                this->map->wall_ver.setTexture(this->map->wall_texture_ver);
                                for (int i = 0; i < 7; i++)
                                    this->map->walls_lvl1.push_back(this->map->wall_ver);

                                this->weapon->change_damage(this->weapon->damage, -this->difficulty);
                                this->difficulty = 50;
                                this->weapon->change_damage(this->weapon->damage, this->difficulty);
                                clock.restart();
                                this->next_level();
                                this->run();
                                break;
                            case 1:

                                this->map->walls_lvl1.clear();
                                this->map->background.setTexture(this->map->background_texture_normal);
                                this->map->wall_hor.setTexture(this->map->wall_texture_hor_normal);
                                for (int i = 0; i < 5; i++)
                                    this->map->walls_lvl1.push_back(this->map->wall_hor);
                                
                                this->map->wall_ver.setTexture(this->map->wall_texture_ver_normal);
                                for (int i = 0; i < 7; i++)
                                    this->map->walls_lvl1.push_back(this->map->wall_ver);

                                this->weapon->change_damage(this->weapon->damage, -this->difficulty);
                                this->difficulty = 0;
                                this->weapon->change_damage(this->weapon->damage, this->difficulty);
                                clock.restart();
                                this->next_level();
                                this->run();
                                break;
                            case 2:

                                this->map->walls_lvl1.clear();
                                this->map->background.setTexture(this->map->background_texture_hard);
                                this->map->wall_hor.setTexture(this->map->wall_texture_hor_hard);
                                for (int i = 0; i < 5; i++)
                                    this->map->walls_lvl1.push_back(this->map->wall_hor);
                                
                                this->map->wall_ver.setTexture(this->map->wall_texture_ver_hard);
                                for (int i = 0; i < 7; i++)
                                    this->map->walls_lvl1.push_back(this->map->wall_ver);

                                this->weapon->change_damage(this->weapon->damage, -this->difficulty);
                                this->difficulty = -50;
                                this->weapon->change_damage(this->weapon->damage, this->difficulty);
                                clock.restart();
                                this->next_level();
                                this->run();
                                break;
                        }
                }
        }

        if (this->event.type == sf::Event::Closed)
            this->window->close();
    }
}


void Game::updateSFMLEventsInMenuHelp(){
    while (this->window->pollEvent(this->event)){

        switch (event.type){

            case sf::Event::KeyReleased:
                switch (event.key.code){
   
                    case sf::Keyboard::Return:

                        switch (menu_help->GetPressedItem()){
                            case 0:
                                this->render_menu();
                                this->run_menu();
                                break;
                        }
                }
        }

        if (this->event.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::updateSFMLEventsInMenuShop(){
    while (this->window->pollEvent(this->event)){

        switch (event.type){

            case sf::Event::KeyReleased:
                switch (event.key.code){
                    case sf::Keyboard::W:
                        menu_shop->MoveUp();
                        break;

                    case sf::Keyboard::S:
                        menu_shop->MoveDown();
                        break;

                    case sf::Keyboard::Return:
                        if (this->player->gold >= 50){
                            switch (menu_shop->GetPressedItem()){
                                case 0:
                                    this->player->gold -= 50;
                                    this->speed_player  += 1;
                                    this->next_level();
                                    this->run();
                                    break;
                                case 1:
                                    this->player->gold -= 50;
                                    this->speed_bullet  -= 0.05;
                                    this->next_level();
                                    this->run();
                                    break;
                                case 2:
                                    this->player->gold -= 50;
                                    this->damage += 20;
                                    this->next_level();
                                    this->run();
                                    break;
                                case 3:
                                    this->next_level();
                                    this->run();
                                    break;
                            }  
                        }
                        else{
                            switch (menu_shop->GetPressedItem()){
                                case 0:
                                    this->menu_shop->money.setString("YOU DON'T HAVE \nENOUGH MONEY");
                                    this->menu_shop->money1.setString("YOU DON'T HAVE \nENOUGH MONEY");

                                    break;
                                case 1:
                                    this->menu_shop->money.setString("YOU DON'T HAVE \nENOUGH MONEY");
                                    this->menu_shop->money1.setString("YOU DON'T HAVE \nENOUGH MONEY");
                                    break;
                                case 2:
                                    this->menu_shop->money.setString("YOU DON'T HAVE \nENOUGH MONEY");
                                    this->menu_shop->money1.setString("YOU DON'T HAVE \nENOUGH MONEY");
                                    break;
                                case 3:
                                    this->next_level();
                                    this->run();
                                    break;
                            }
                        }
                }
        }

        if (this->event.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::updateSFMLEventsInMenuGameEnd(){
    while (this->window->pollEvent(this->event)){

        switch (event.type){

            case sf::Event::KeyReleased:
                switch (event.key.code){
                    case sf::Keyboard::W:
                        menu_game_end->MoveUp();
                        break;

                    case sf::Keyboard::S:
                        menu_game_end->MoveDown();
                        break;

                    case sf::Keyboard::Return:
                        switch (menu_game_end->GetPressedItem()){
                            case 0:
                                clock.restart();
                                this->player->player_health = 100;
                                this->current_level = 1;
                                this->coins.clear();
                                this->hearts.clear();
                                this->player->gold = 100;
                                this->player->total_gold = 100;
                                this->enemies.clear();
                                this->menu_game_end->dead_enemies = 0;
                                this->speed_player = 0;
                                this->speed_bullet = 0;
                                this->damage = 0;
                                
                                this->run_menu_diffic();
                                break;
                            case 1:
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
        if (this->player->coordinates.y - this->player->player_texture.getSize().y / 2 <= 0){
            this->player->coordinates.y - this->player->player_texture.getSize().y / 2 == 0;
        }
        else{
            this->player->move({0.f, -(5.f + this->speed_player)});
            for (unsigned i = 0; i < this->map->walls_lvl1.size(); i++){
                if (this->map->walls_lvl1[i].getGlobalBounds().intersects(this->player->character.getGlobalBounds()))
                    this->player->move({0.f, 5.f + this->speed_player});    
            }
        }
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        if (this->player->coordinates.x - this->player->player_texture.getSize().x / 2 <= 0){
            this->player->coordinates.x - this->player->player_texture.getSize().x / 2 == 0;
        }
        else{
            this->player->move({-(5.f + this->speed_player), 0.f});
            for (unsigned i = 0; i < this->map->walls_lvl1.size(); i++){
                if (this->map->walls_lvl1[i].getGlobalBounds().intersects(this->player->character.getGlobalBounds()))
                    this->player->move({5.f + this->speed_player, 0.f});    
            }
        }
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        if (this->player->coordinates.y + this->player->player_texture.getSize().y / 2 >= constans::height_window){
            this->player->coordinates.y == constans::height_window - this->player->player_texture.getSize().y;
        }
        else{
            this->player->move({0.f, 5.f + this->speed_player});
            for (unsigned i = 0; i < this->map->walls_lvl1.size(); i++){
                if (this->map->walls_lvl1[i].getGlobalBounds().intersects(this->player->character.getGlobalBounds()))
                    this->player->move({0.f, -(5.f + this->speed_player)});    
            }
        }
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        if (this->player->coordinates.x + this->player->player_texture.getSize().x / 2 >= constans::width_window){
            this->player->coordinates.x == constans::width_window - this->player->player_texture.getSize().x;
        }
        else{
            this->player->move({5.f + this->speed_player, 0.f});
            for (unsigned i = 0; i < this->map->walls_lvl1.size(); i++){
                if (this->map->walls_lvl1[i].getGlobalBounds().intersects(this->player->character.getGlobalBounds()))
                    this->player->move({-(5.f + this->speed_player), 0.f});    
            }
        }
    }

    for (int i = 0; i < this->coins.size(); i++){
        if (this->coins[i].coin.getGlobalBounds().intersects(this->player->character.getGlobalBounds())){
            this->player->bank(this->coins[i].value);
            this->coins.erase(this->coins.begin() + i);
        }
    }

    for (int i = 0; i < this->hearts.size(); i++){
        if (this->hearts[i].heart.getGlobalBounds().intersects(this->player->character.getGlobalBounds())){
            this->player->health(10);
            this->hearts.erase(this->hearts.begin() + i);
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
                        this->enemies[i].move({-this->enemies[i].enemy_speed * 2, 0.f});    
                }
            }
            else if (this->player->coordinates.x < this->enemies[i].coordinates.x){
                this->enemies[i].move({-this->enemies[i].enemy_speed, 0.f});

                for (unsigned j = 0; j < this->map->walls_lvl1.size(); j++){
                    if (this->map->walls_lvl1[j].getGlobalBounds().intersects(this->enemies[i].character.getGlobalBounds()))
                        this->enemies[i].move({this->enemies[i].enemy_speed * 2, 0.f});    
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
        else{
            this->player->health(-this->enemies[i].attack());
            if (this->player->player_health <= 0){
                this->map->action_music.pause();
                this->menu->menu_music.play();
                this->menu_game_end->draw(this->window->getSize().x, this->window->getSize().y,  this->player->total_gold, this->time);
                this->render_menu_game_end();
                this->run_menu_game_end();
            }
        }
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

    std::uniform_int_distribution<uint32_t> random(1, 10);

    for (size_t i = 0; i < this->bullets.size(); i++){
        for (unsigned j = 0; j < this->enemies.size(); j++){
            if (this->enemies[j].character.getGlobalBounds().intersects(this->bullets[i].bullet.getGlobalBounds())){
                this->bullets.erase(this->bullets.begin() + i);
                this->enemies[j].health(this->weapon->damage + this->damage);
            
                if (this->enemies[j].enemy_health <= 0){
                    this->drop = random(this->generator);
                    this->menu_game_end->dead_enemies++;

                    if (this->drop < 5){
                        this->coin = new Coin(this->enemies[j].character.getPosition(), 20);
                        this->coins.push_back(*this->coin);
                    } else if (this->drop == 5){
                        this->heart = new Heart(this->enemies[j].character.getPosition());
                        this->hearts.push_back(*this->heart);
                    }
                    
                    this->enemies.erase(this->enemies.begin() + j);

                    if (this->enemies.size() == 0){
                        this->current_level++;

                        if (this->player->gold >= 50){
                            this->menu_shop->money.setString("");
                            this->menu_shop->money1.setString("");
                        }

                        this->render_menu_shop();
                        this->run_menu_shop();
                    }
                }
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

    this->player_rotate();
    this->enemy_rotate();

    this->window->clear();

    this->time = clock.getElapsedTime().asSeconds();
}

void Game::render(){
    this->window->clear();
    this->window->draw(this->map->background);
    this->map->level1(this->window);

    this->drawBullets();

    for (size_t i = 0; i < this->bullets.size(); i++){
        this->window->draw(bullets[i].bullet);
    }

    for (size_t i = 0; i < this->coins.size(); i++){
        this->window->draw(coins[i].coin);
    }

    for (size_t i = 0; i < this->hearts.size(); i++){
        this->window->draw(hearts[i].heart);
    }

    this->window->draw(this->weapon->weapon);
    this->window->draw(this->player->character);
    this->drawEnemies();

    std::string text = "Level: " + std::to_string(this->current_level) + "\nCoins: " + std::to_string(this->player->gold) + "\nHealth: " + std::to_string(this->player->player_health);
    this->level_information.setString(text);
    this->window->draw(level_information);

    this->window->display();
}

void Game::render_menu(){
    this->window->clear();
    this->window->draw(this->menu->background);
    this->menu->drawMenu(this->window); 
    this->window->display();
}

void Game::render_menu_help(){
    this->window->clear();
    this->window->draw(this->menu_help->background);
    this->menu_help->drawMenuHelp(this->window); 
    this->window->display();
}

void Game::render_menu_diffic(){
    this->window->clear();
    this->window->draw(this->menu_diffic->background);
    this->menu_diffic->drawMenuDiffic(this->window); 
    this->window->display();
}

void Game::render_menu_shop(){
    this->window->clear();
    this->window->draw(this->menu_shop->background);
    this->menu_shop->drawMenuShop(this->window); 
    this->window->display();
}

void Game::render_menu_game_end(){
    this->window->clear();
    this->window->draw(this->menu_game_end->background);
    this->menu_game_end->drawMenuGameEnd(this->window); 
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

void Game::run_menu_help(){
    while (this->window->isOpen()){
        this->updateSFMLEventsInMenuHelp();
        this->render_menu_help();
    }
}

void Game::run_menu_diffic(){
    while (this->window->isOpen()){
        this->updateSFMLEventsInMenuDiffic();
        this->render_menu_diffic();
    }
}

void Game::run_menu_shop(){
    while (this->window->isOpen()){
        this->updateSFMLEventsInMenuShop();
        this->render_menu_shop();
    }
}

void Game::run_menu_game_end(){
    while (this->window->isOpen()){
        this->updateSFMLEventsInMenuGameEnd();
        this->render_menu_game_end();
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

void Game::player_rotate(){
    sf::Vector2f curPos;
    curPos.x = this->player->character.getGlobalBounds().left;
    curPos.y = this->player->character.getGlobalBounds().top;
    sf::Vector2f position = sf::Vector2f(sf::Mouse::getPosition(*this->window));

    float dx = curPos.x - position.x;
    float dy = curPos.y - position.y;

    float rotation = (atan2(dy, dx)) * 180 / constans::PI;

    this->player->character.setOrigin(this->player->player_texture.getSize().x / 2, this->player->player_texture.getSize().y / 2);
    this->player->character.setRotation(rotation - 90);
}

void Game::enemy_rotate(){
    for (int i = 0; i < this->enemies.size(); i++){
        sf::Vector2f curPos;
        curPos.x = this->enemies[i].character.getGlobalBounds().left;
        curPos.y = this->enemies[i].character.getGlobalBounds().top;
        sf::Vector2f position = this->player->character.getPosition();

        float dx = curPos.x - position.x;
        float dy = curPos.y - position.y;

        float rotation = (atan2(dy, dx)) * 180 / constans::PI;

        this->enemies[i].character.setOrigin(enemies[i].enemy_texture.getSize().x / 2, enemies[i].enemy_texture.getSize().y / 2);
        this->enemies[i].character.setRotation(rotation - 90);
    }
    
}

void Game::drawBullets(){
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (this->cooldown.getElapsedTime().asSeconds() > this->weapon->cooldown + this->speed_bullet)){

        this->map->shot.play();

        this->bullet = new Bullet(this->weapon->damage, this->weapon->cooldown);
        this->bullet->bullet.setPosition(this->player->character.getPosition().x + this->player->player_texture.getSize().x / 2, this->player->character.getPosition().y + this->player->player_texture.getSize().y / 2);
        this->bullet->velocity = aimDirNorm * this->weapon->max_speed;

        this->bullets.push_back(*this->bullet);
        this->cooldown.restart();
    }
}

Game::Game(){
    this->current_level = 1;

    this->speed_bullet = 0;
    this->damage = 0;

    this->font.loadFromFile("textures/font.ttf");

    this->level_information.setFont(font);
    this->level_information.setCharacterSize(32);
    this->level_information.setPosition(20.f, 20.f);

    this->speed_player = 0;

    this->difficulty = 0;

    generator.seed(std::time(0));

    this->initWindow();
    this->initMenu(); 
    this->initMenuHelp();
    this->initMenuShop();
    this->initMenuGameEnd();
    this->initMenuDiffic();
    this->initMap();
    this->initPlayer();
    this->initWeapon();
}

Game::~Game(){
    delete this->window;
    delete this->player;
    delete this->map;
    delete this->menu;
    delete this->weapon;
}
