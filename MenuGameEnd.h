#ifndef MENUGAMEEND_H
#define MENUGAMEEND_H

#define MAX_NUMBER_OF_ITEMS 2

#include "libraries.h"
#include "constans.h"

class MenuGameEnd{

public:

    MenuGameEnd(float width, float height);
    ~MenuGameEnd();

    void drawMenuGameEnd(sf::RenderWindow* window);
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
    sf::Text menu0;
    sf::Text menu1;
    sf::Text help;
    sf::Text help1;

};

#endif
