#ifndef MENUHELP_H
#define MENUHELP_H

#define MAX_NUMBER_OF_ITEMS 1

#include "libraries.h"
#include "constans.h"

class MenuHelp{

public:

    MenuHelp(float width, float height);  
    ~MenuHelp();

    void drawMenuHelp (sf::RenderWindow* window);
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
    sf::Text help;

};

#endif