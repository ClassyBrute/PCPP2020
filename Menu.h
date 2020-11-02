#ifndef MENU_H
#define MENU_H

#define MAX_NUMBER_OF_ITEMS 3

#include "libraries.h"
#include "constans.h"

class Menu{

public:

    Menu(float width, float height);
    ~Menu();

    void drawMenu (sf::RenderWindow* window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return selectedItemIndex; }

    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];    

};


#endif
