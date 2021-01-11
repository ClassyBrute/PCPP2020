#include "MenuShop.h"

MenuShop::MenuShop(float width, float height){

    font.loadFromFile("textures/font.ttf");
    font_title.loadFromFile("textures/font_title.ttf");

    this->background_texture.loadFromFile("textures/shop_background.png");
    this->background.setTexture(background_texture);
    

    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("MOVEMENT SPEED - 50 COIN");
    menu[0].setScale(2, 2);
    menu[0].setPosition(sf::Vector2f(width/5 - 100, 400));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("FIRE RATE - 50 COIN");
    menu[1].setScale(2, 2);
    menu[1].setPosition(sf::Vector2f(width/5 - 100, 500));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("DAMAGE - 50 COIN");
    menu[2].setScale(2, 2);
    menu[2].setPosition(sf::Vector2f(width/5 - 100, 600));

    menu[3].setFont(font);
    menu[3].setColor(sf::Color::White);
    menu[3].setString("CONTINUE");
    menu[3].setScale(2, 2);
    menu[3].setPosition(sf::Vector2f(width/2 - 100, 780));

    menu0.setFont(font);
    menu0.setColor(sf::Color::Black);
    menu0.setString("MOVEMENT SPEED - 50 COIN");
    menu0.setScale(2, 2);
    menu0.setPosition(sf::Vector2f(width/5 - 98, 402));

    menu1.setFont(font);
    menu1.setColor(sf::Color::Black);
    menu1.setString("FIRE RATE - 50 COIN");
    menu1.setScale(2, 2);
    menu1.setPosition(sf::Vector2f(width/5 - 98, 502));

    menu2.setFont(font);
    menu2.setColor(sf::Color::Black);
    menu2.setString("DAMAGE - 50 COIN");
    menu2.setScale(2, 2);
    menu2.setPosition(sf::Vector2f(width/5 - 98, 602));

    menu3.setFont(font);
    menu3.setColor(sf::Color::Black);
    menu3.setString("CONTINUE");
    menu3.setScale(2, 2);
    menu3.setPosition(sf::Vector2f(width/2 - 98, 782));


    help.setFont(font_title);
    help.setColor(sf::Color::White);
    help.setString("BUY YOURSELF SOME UPGRADES");
    help.setScale(1, 1);
    help.setPosition(sf::Vector2f(370, 300));

    help1.setFont(font_title);
    help1.setColor(sf::Color::Black);
    help1.setString("BUY YOURSELF SOME UPGRADES");
    help1.setScale(1, 1);
    help1.setPosition(sf::Vector2f(372, 302));

    title.setFont(font_title);
    title.setColor(sf::Color::White);
    title.setString("SHOP");
    title.setScale(2, 2);
    title.setPosition(sf::Vector2f(550, 200));

    title1.setFont(font_title);
    title1.setColor(sf::Color::Black);
    title1.setString("SHOP");
    title1.setScale(2, 2);
    title1.setPosition(sf::Vector2f(552, 202));

    money.setFont(font_title);
    money.setColor(sf::Color::Red);
    // money.setString("YOU DON'T HAVE \nENOUGH MONEY");
    money.setScale(1, 1);
    money.setPosition(sf::Vector2f(850, 50));

    money1.setFont(font_title);
    money1.setColor(sf::Color::Black);
    // money1.setString("YOU DON'T HAVE \nENOUGH MONEY");
    money1.setScale(1, 1);
    money1.setPosition(sf::Vector2f(852, 52));


    selectedItemIndex = 0;
}


MenuShop::~MenuShop(){

}

void MenuShop::drawMenuShop(sf::RenderWindow* window){

    window->draw(this->title);
    window->draw(this->title1);
    window->draw(this->help);
    window->draw(this->help1);
    window->draw(this->menu0);
    window->draw(this->menu1);
    window->draw(this->menu2);
    window->draw(this->menu3);
    window->draw(this->money);
    window->draw(this->money1);


    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++){
        window->draw(this->menu[i]);
    }
}

void MenuShop::MoveUp(){

    if (selectedItemIndex - 1 >= 0){
        this->menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        this->menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}

void MenuShop::MoveDown(){

    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS){
        this->menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        this->menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}