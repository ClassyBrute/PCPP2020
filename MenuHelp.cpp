#include "MenuHelp.h"

MenuHelp::MenuHelp(float width, float height){

    font.loadFromFile("textures/font.ttf");
    font_title.loadFromFile("textures/font_title.ttf");

    this->background_texture.loadFromFile("textures/menu_background.png");
    this->background.setTexture(background_texture);
    

    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("BACK");
    menu[0].setScale(2, 2);
    menu[0].setPosition(sf::Vector2f(width/2 - 70, 780));

    title.setFont(font_title);
    title.setColor(sf::Color::Red);
    title.setString("SUPER FANCY MAGIC LUKE");
    title.setScale(2, 2);
    title.setPosition(sf::Vector2f(200, 200));

    help.setFont(font_title);
    help.setColor(sf::Color::Black);
    help.setString("Welcome to our awesome game\n"
                    "your objective is to defeat\n" 
                    "all of the enemies and not die!\n" 
                    "GOOD LUCK!\n\n"
                    "MOVEMENT: W A S D\n"
                    "SHOOTING: Left Mouse Button");
    help.setScale(1, 1);
    help.setPosition(sf::Vector2f(300, 400));

    selectedItemIndex = 0;
}


MenuHelp::~MenuHelp(){

}

void MenuHelp::drawMenuHelp(sf::RenderWindow* window){

    window->draw(this->title);
    window->draw(this->help);

    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++){
        window->draw(this->menu[i]);
    }
}
