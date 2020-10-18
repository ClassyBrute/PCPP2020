#include "Game.h"

void Game::initWindow(){
    unsigned width_window = 1200;
    unsigned height_window = 1000;
    std::string title = "Super Fancy Magic Luke";
    sf::VideoMode window_bounds(width_window, height_window);
    int frame_limit = 60;

    this->window = new sf::RenderWindow(window_bounds, title);
    this->window->setFramerateLimit(frame_limit);
}

void Game::updateSFMLEvents(){
    while (this->window->pollEvent(this->event)){
        if (this->event.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::update(){
    this->updateSFMLEvents();
}

void Game::render(){
    this->window->clear();

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
}

Game::~Game(){
    delete this->window;
}
