#include "Menu.h"

Menu::Menu(float width, float height){

    font.loadFromFile("textures/font.ttf");
    font_title.loadFromFile("textures/font_title.ttf");

    this->background_texture.loadFromFile("textures/menu_background.png");
    this->background.setTexture(background_texture);
    

    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("PLAY");
    menu[0].setScale(2, 2);
    menu[0].setPosition(sf::Vector2f(width/2 - 70, 600));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::Black);
    menu[1].setString("OPTIONS");
    menu[1].setScale(2, 2);
    menu[1].setPosition(sf::Vector2f(width/2 - 70, 700));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::Black);
    menu[2].setString("EXIT");
    menu[2].setScale(2, 2);
    menu[2].setPosition(sf::Vector2f(width/2 - 70, 800));

    title.setFont(font_title);
    title.setColor(sf::Color::Red);
    title.setString("SUPER FANCY MAGIC LUKE");
    title.setScale(2, 2);
    title.setPosition(sf::Vector2f(200, 200));

    selectedItemIndex = 0;
}


Menu::~Menu(){

}

void Menu::drawMenu(sf::RenderWindow* window){

    window->draw(this->title);

    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++){
        window->draw(this->menu[i]);
    }
}

void Menu::MoveUp(){

    if (selectedItemIndex - 1 >= 0){
        this->menu[selectedItemIndex].setColor(sf::Color::Black);
        selectedItemIndex--;
        this->menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}

void Menu::MoveDown(){

    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS){
        this->menu[selectedItemIndex].setColor(sf::Color::Black);
        selectedItemIndex++;
        this->menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}