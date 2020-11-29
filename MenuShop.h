#ifndef MENUSHOP_H
#define MENUSHOP_H

#define MAX_NUMBER_OF_ITEMS 4

#include "libraries.h"
#include "constans.h"

class MenuShop{

public:

    MenuShop(float width, float height);  
    ~MenuShop();

    void drawMenuShop (sf::RenderWindow* window);
    void MoveUp();
    void MoveDown();
    
    int GetPressedItem() { return selectedItemIndex; }
    int selectedItemIndex;

    sf::Texture background_texture;
    sf::Sprite background;

    sf::Font font;
    sf::Font font_title;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];    
    sf::Text title;
    sf::Text title1;
    sf::Text help;
    sf::Text help1;
    sf::Text menu0;
    sf::Text menu1;
    sf::Text menu2;
    sf::Text menu3;

};

#endif