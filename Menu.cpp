#include "Menu.h"

Menu::Menu(float width, float height){

    if (!font.loadFromFile("textures/font.ttf")){
    }

    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width/2, 200));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Options");
    menu[1].setPosition(sf::Vector2f(width/2, 500));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(width/2, 800));

    selectedItemIndex = 0;
}


Menu::~Menu(){

}

void Menu::drawMenu(sf::RenderWindow* window){

    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++){
        window->draw(this->menu[i]);
    }
}

void Menu::MoveUp(){

    if (selectedItemIndex - 1 >= 0){
        this->menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        this->menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}

void Menu::MoveDown(){

    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS){
        this->menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        this->menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}