#include "Menu.h"

Menu::Menu(float width, float height){

    menu_music.openFromFile("sounds/audio_menu.wav");
    menu_music.play();

    font.loadFromFile("textures/font.ttf");
    font_title.loadFromFile("textures/font_title.ttf");

    this->background_texture.loadFromFile("textures/menu_background.png");
    this->background.setTexture(background_texture);
    

    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("PLAY");
    menu[0].setScale(2, 2);
    menu[0].setPosition(sf::Vector2f(width/2 - 70, 580));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::Black);
    menu[1].setString("HELP");
    menu[1].setScale(2, 2);
    menu[1].setPosition(sf::Vector2f(width/2 - 70, 680));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::Black);
    menu[2].setString("EXIT");
    menu[2].setScale(2, 2);
    menu[2].setPosition(sf::Vector2f(width/2 - 70, 780));

    menu0.setFont(font);
    menu0.setColor(sf::Color::White);
    menu0.setString("PLAY");
    menu0.setScale(2, 2);
    menu0.setPosition(sf::Vector2f(width/2 - 68, 582));

    menu1.setFont(font);
    menu1.setColor(sf::Color::White);
    menu1.setString("HELP");
    menu1.setScale(2, 2);
    menu1.setPosition(sf::Vector2f(width/2 - 68, 682));

    menu2.setFont(font);
    menu2.setColor(sf::Color::White);
    menu2.setString("EXIT");
    menu2.setScale(2, 2);
    menu2.setPosition(sf::Vector2f(width/2 - 68, 782));

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

    selectedItemIndex = 0;
}


Menu::~Menu(){

}

void Menu::drawMenu(sf::RenderWindow* window){

    window->draw(this->title1);
    window->draw(this->title);
    window->draw(this->menu0);
    window->draw(this->menu1);
    window->draw(this->menu2);

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