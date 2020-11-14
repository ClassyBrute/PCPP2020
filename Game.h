#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Map.h"
#include "Menu.h"
#include "Enemy.h"
#include "Weapon.h"
#include "Bullet.h"
#include "constans.h"

class Game{
private:
    sf::RenderWindow *window;
    sf::Event event;

    Menu *menu;
    Player *player;
    Map *map;
    Enemy *enemy;
    Weapon *weapon;
    Bullet *bullet;

    std::vector<Enemy> enemies;
    std::vector<Bullet> bullets;
    
    sf::Vector2f mousePosWindow;
    sf::Vector2f aimDir;
	sf::Vector2f aimDirNorm;
    sf::Vector2f mouse;
    float oldRotate;

    clock_t start;
    clock_t stop;

    void initWindow();
    void initMenu();
    void initMap();
    void initPlayer();
    void initWeapon();
    void initEnemy(sf::Vector2f coordinates, int enemy_health, sf::String skin, int damage, float speed, int speed_attack);

    void weapon_position();

public:
    Game();
    ~Game();

    void drawMenu();
    void drawEnemies();
    void drawBullets();
    void createEnemies();

	void updateSFMLEvents();
    void updateSFMLEventsInMenu();
    void updatePlayerMove();
    void updateEnemyMove();
    void updateBulletMove();
	void update();

	void render();
	void run();

    void run_menu();
    void render_menu();

};

#endif
