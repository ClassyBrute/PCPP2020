#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Map.h"
#include "Enemy.h"
#include "constans.h"

class Game{
private:
    sf::RenderWindow *window;
    sf::Event event;

    Player *player;
    Map *map;
    Enemy *enemy;

    std::vector<sf::Sprite> enemies;

    void initWindow();
    void initMap();
    void initPlayer();
    void initEnemy(sf::Vector2f coordinates, int enemy_health, sf::String skin);

public:
    Game();
    ~Game();

    void drawEnemies();
    void createEnemies();

	void updateSFMLEvents();
    void updatePlayerMove();
	void update();
    
	void render();
	void run();

};

#endif
