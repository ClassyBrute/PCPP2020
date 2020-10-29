#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Map.h"
#include "mapTile.h"
#include "Enemy.h"
#include "constans.h"

class Game{
private:
    sf::RenderWindow *window;
    sf::Event event;

    Player *player;
    Map *map;

    void initWindow();
    void initMap();
    void initPlayer();

public:
    Game();
    ~Game();

	void updateSFMLEvents();
    void updatePlayerMove();
	void update();
    
	void render();
	void run();

};

#endif
