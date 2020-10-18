#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Enemy.h"

class Game{
private:
    sf::RenderWindow *window;
    sf::Event event;
    void initWindow();

public:
    Game();
    ~Game();

	void updateSFMLEvents();
	void update();
	void render();
	void run();

};

#endif
