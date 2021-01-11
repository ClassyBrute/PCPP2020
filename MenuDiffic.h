#ifndef MENUDIFFIC_H
#define MENUDIFFIC_H

#define MAX_NUMBER_OF_ITEMS 3

#include "libraries.h"
#include "constans.h"

class MenuDiffic{

public:

    MenuDiffic(float width, float height);  
    ~MenuDiffic();

    void drawMenuDiffic (sf::RenderWindow* window);
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
    sf::Text menu2;
    sf::Text menu1;
    sf::Text menu0;

};

#endif