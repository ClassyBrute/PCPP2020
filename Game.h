#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Map.h"
#include "Menu.h"
#include "Enemy.h"
#include "constans.h"

class Game{
private:
    sf::RenderWindow *window;
    sf::Event event;

    Menu *menu;
    Player *player;
    Map *map;
    Enemy *enemy;

    std::vector<Enemy> enemies;

    void initWindow();
    void initMenu();
    void initMap();
    void initPlayer();
    void initEnemy(sf::Vector2f coordinates, int enemy_health, sf::String skin, int damage, float speed, int speed_attack);

public:
    Game();
    ~Game();

    void drawMenu();
    void drawEnemies();
    void createEnemies();

	void updateSFMLEvents();
    void updateSFMLEventsInMenu();
    void updatePlayerMove();
    void updateEnemyMove();
	void update();

	void render();
	void run();

    void run_menu();
    void render_menu();

};

#endif
