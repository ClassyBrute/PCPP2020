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

    menu0.setFont(font);
    menu0.setColor(sf::Color::White);
    menu0.setString("BACK");
    menu0.setScale(2, 2);
    menu0.setPosition(sf::Vector2f(width/2 - 68, 782));

    title.setFont(font_title);
    title.setColor(sf::Color::Red);
    title.setString("SUPER FANCY MAGIC LUKE");
    title.setScale(2, 2);
    title.setPosition(sf::Vector2f(200, 200));

    title1.setFont(font_title);
    title1.setColor(sf::Color::Black);
    title1.setString("SUPER FANCY MAGIC LUKE");
    title1.setScale(2, 2);
    title1.setPosition(sf::Vector2f(202, 202));

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

    help1.setFont(font_title);
    help1.setColor(sf::Color::White);
    help1.setString("Welcome to our awesome game\n"
                    "your objective is to defeat\n" 
                    "all of the enemies and not die!\n" 
                    "GOOD LUCK!\n\n"
                    "MOVEMENT: W A S D\n"
                    "SHOOTING: Left Mouse Button");
    help1.setScale(1, 1);
    help1.setPosition(sf::Vector2f(302, 402));

    selectedItemIndex = 0;
}


MenuHelp::~MenuHelp(){

}

void MenuHelp::drawMenuHelp(sf::RenderWindow* window){

    window->draw(this->title1);
    window->draw(this->title);
    window->draw(this->help1);
    window->draw(this->help);
    window->draw(this->menu0);

    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++){
        window->draw(this->menu[i]);
    }
}
