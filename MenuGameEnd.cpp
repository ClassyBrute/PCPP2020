#include "MenuGameEnd.h"

MenuGameEnd::MenuGameEnd(){

    

    
}

void MenuGameEnd::draw(float width, float height, int gold, float time){
    font.loadFromFile("textures/font.ttf");
    font_title.loadFromFile("textures/font_title.ttf");

    this->background_texture.loadFromFile("textures/menu_background.png");
    this->background.setTexture(background_texture);

    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("PLAY AGAIN");
    menu[0].setScale(2, 2);
    menu[0].setPosition(sf::Vector2f(width/2 - 120, 680));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::Black);
    menu[1].setString("EXIT");
    menu[1].setScale(2, 2);
    menu[1].setPosition(sf::Vector2f(width/2 - 120, 780));

    menu0.setFont(font);
    menu0.setColor(sf::Color::White);
    menu0.setString("PLAY AGAIN");
    menu0.setScale(2, 2);
    menu0.setPosition(sf::Vector2f(width/2 - 118, 682));

    menu1.setFont(font);
    menu1.setColor(sf::Color::White);
    menu1.setString("EXIT");
    menu1.setScale(2, 2);
    menu1.setPosition(sf::Vector2f(width/2 - 118, 782));

    title.setFont(font_title);
    title.setColor(sf::Color::Red);
    title.setString("GAME OVER");
    title.setScale(2, 2);
    title.setPosition(sf::Vector2f(width/2 - 120, 200));

    title1.setFont(font_title);
    title1.setColor(sf::Color::Black);
    title1.setString("GAME OVER");
    title1.setScale(2, 2);
    title1.setPosition(sf::Vector2f(width/2 - 118, 202));

    help.setFont(font_title);
    help.setColor(sf::Color::Black);
    help.setString("TOTAL COLLECTED COINS: " + std::to_string(gold) + "\n"
                    "KILLED ENEMIES: " + std::to_string(this->dead_enemies) + "\n" 
                    "TIME: " + std::to_string(time) + "s\n" );
    help.setScale(1, 1);
    help.setPosition(sf::Vector2f(width/2 - 120, 400));

    help1.setFont(font_title);
    help1.setColor(sf::Color::White);
    help1.setString("TOTAL COLLECTED COINS: " + std::to_string(gold) + "\n"
                    "KILLED ENEMIES: " + std::to_string(this->dead_enemies) + "\n" 
                    "TIME: " + std::to_string(time) + "s\n" );
    help1.setScale(1, 1);
    help1.setPosition(sf::Vector2f(width/2 - 118, 402));

    selectedItemIndex = 0;
}


MenuGameEnd::~MenuGameEnd(){

}

void MenuGameEnd::drawMenuGameEnd(sf::RenderWindow* window){

    window->draw(this->title1);
    window->draw(this->title);
    window->draw(this->menu0);
    window->draw(this->menu1);
    window->draw(this->help1);
    window->draw(this->help);

    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++){
        window->draw(this->menu[i]);
    }
}

void MenuGameEnd::MoveUp(){

    if (selectedItemIndex - 1 >= 0){
        this->menu[selectedItemIndex].setColor(sf::Color::Black);
        selectedItemIndex--;
        this->menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}

void MenuGameEnd::MoveDown(){

    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS){
        this->menu[selectedItemIndex].setColor(sf::Color::Black);
        selectedItemIndex++;
        this->menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}