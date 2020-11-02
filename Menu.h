#ifndef MENU_H
#define MENU_H

#define MAX_NUMBER_OF_ITEMS 3

#include "libraries.h"
#include "constans.h"
#include "Player.h"
#include "Map.h"
#include "Enemy.h"
#include "Game.h"

class Menu{

public:

    Game *game;

    sf::RenderWindow *window;
    sf::Event event;

    Menu();
    ~Menu();

    void drawMenu (sf::RenderWindow* window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return selectedItemIndex; }

    void initWindow();
    void initGame();
	void updateSFMLEvents();
	void update();
    
	void render();
	void run();

    int selectedItemIndex;
    sf::Font font;
    sf::Text menu_text[MAX_NUMBER_OF_ITEMS];    

};


#endif
