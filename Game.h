#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Map.h"
#include "Menu.h"
#include "MenuHelp.h"
#include "MenuShop.h"
#include "MenuGameEnd.h"
#include "MenuDiffic.h"
#include "Enemy.h"
#include "Weapon.h"
#include "Bullet.h"
#include "Coin.h"
#include "Heart.h"
#include "constans.h"

class Game{
private:
    sf::RenderWindow *window;
    sf::Event event;

    Menu *menu;
    MenuHelp *menu_help;
    MenuShop *menu_shop;
    MenuGameEnd *menu_game_end;
    MenuDiffic *menu_diffic;
    Player *player;
    Map *map;
    Enemy *enemy;
    Weapon *weapon;
    Bullet *bullet;
    Coin *coin;
    Heart *heart;

    std::vector<Enemy> enemies;
    std::vector<Bullet> bullets;
    std::vector<Coin> coins;
    std::vector<Heart> hearts;

    sf::Vector2f mousePosWindow;
    sf::Vector2f aimDir;
	sf::Vector2f aimDirNorm;
    sf::Vector2f mouse;
    
    float speed_player;
    float speed_bullet;
    int damage;

    float oldRotate;

    sf::Clock clock;
    sf::Clock cooldown;

    float time;

    std::mt19937 generator;
    int drop;

    int current_level;

    sf::Font font;
    sf::Text level_information;

    int difficulty;

    void initWindow();
    void initMenu();
    void initMenuHelp();
    void initMenuShop();
    void initMenuGameEnd();
    void initMenuDiffic();
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
    void level1();
    void level2();
    void level3();
    void level4();
    void level5();
    void level6();
    void level7();
    void level8();
    void level9();
    void level10();
    void next_level();

	void updateSFMLEvents();
    void updateSFMLEventsInMenu();
    void updateSFMLEventsInMenuHelp();
    void updateSFMLEventsInMenuShop();
    void updateSFMLEventsInMenuGameEnd();
    void updateSFMLEventsInMenuDiffic();
    void updatePlayerMove();
    void updateEnemyMove();
    void updateBulletMove();
	void update();

	void render();
	void run();

    void run_menu();
    void render_menu();

    void run_menu_help();
    void render_menu_help();

    void run_menu_shop();
    void render_menu_shop();

    void run_menu_game_end();
    void render_menu_game_end();

    void run_menu_diffic();
    void render_menu_diffic();

    void player_rotate();
    void enemy_rotate();
};

#endif
