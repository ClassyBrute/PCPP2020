#include "Game.h"

void Game::initWindow(){
    std::string title = "Super Fancy Magic Luke";
    sf::VideoMode window_bounds(window_size::width_window, window_size::height_window);
    int frame_limit = 60;

    this->window = new sf::RenderWindow(window_bounds, title);
    this->window->setFramerateLimit(frame_limit);
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
        this->player->move({0.f, -5.f});
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        this->player->move({-5.f, 0.f});
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        this->player->move({0.f, 5.f});
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        this->player->move({5.f, 0.f});
    }
}

void Game::update(){
    this->updateSFMLEvents();

    updatePlayerMove();
}

void Game::render(){
    this->window->clear(sf::Color::White);

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
    this->initPlayer();
}

Game::~Game(){
    delete this->window;
}
