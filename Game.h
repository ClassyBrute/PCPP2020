#ifndef GAME_H
#define GAME_H

#include "Menu.h"

class Game{

public:

    sf::RenderWindow *window;
    sf::Event event;

    Player *player;
    Map *map;
    Enemy *enemy;

    std::vector<Enemy> enemies;

    void initWindow();
    void initMap();
    void initPlayer();
    void initEnemy(sf::Vector2f coordinates, int enemy_health, sf::String skin, int damage, float speed, int speed_attack);
    
    Game();
    ~Game();

    void drawEnemies();
    void createEnemies();

	void updateSFMLEvents();
    void updatePlayerMove();
    void updateEnemyMove();
	void update();
    
	void render();
	void run();

};

#endif
