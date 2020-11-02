#include "Menu.h"

Menu::Menu(){

    this->initWindow();
    this->initGame();


    if (!font.loadFromFile("textures/font.ttf")){
    }

    menu_text[0].setFont(font);
    menu_text[0].setColor(sf::Color::Red);
    menu_text[0].setString("Play");
    menu_text[0].setPosition(sf::Vector2f(600, 200));

    menu_text[1].setFont(font);
    menu_text[1].setColor(sf::Color::White);
    menu_text[1].setString("Options");
    menu_text[1].setPosition(sf::Vector2f(600, 500));

    menu_text[2].setFont(font);
    menu_text[2].setColor(sf::Color::White);
    menu_text[2].setString("Exit");
    menu_text[2].setPosition(sf::Vector2f(600, 800));

    selectedItemIndex = 0;
}


Menu::~Menu(){
    delete this->window;
}

void Menu::initGame(){
    this->game = new Game();
}

void Menu::initWindow(){
    std::string title = "Super Fancy Magic Luke";
    sf::VideoMode window_bounds(window_size::width_window, window_size::height_window);
    int frame_limit = 60;

    this->window = new sf::RenderWindow(window_bounds, title);
    this->window->setFramerateLimit(frame_limit);
}

void Menu::drawMenu(sf::RenderWindow* window){

    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++){
        window->draw(this->menu_text[i]);
    }
}

void Menu::updateSFMLEvents(){
    while (this->window->pollEvent(this->event)){

        switch (event.type){

            case sf::Event::KeyReleased:
                switch (event.key.code){
                    case sf::Keyboard::W:
                        this->MoveUp();
                        break;

                    case sf::Keyboard::S:
                        this->MoveDown();
                        break;

                    case sf::Keyboard::Return:
                        switch (this->GetPressedItem()){
                            case 0:
                                Game->run();
                            case 1:
                                continue;
                            case 2:
                                this->window->close();
                        }
                }
        }

        if (this->event.type == sf::Event::Closed)
            this->window->close();
    }
}

void Menu::MoveUp(){

    if (selectedItemIndex - 1 >= 0){
        this->menu_text[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        this->menu_text[selectedItemIndex].setColor(sf::Color::Red);
    }
}

void Menu::MoveDown(){

    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS){
        this->menu_text[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        this->menu_text[selectedItemIndex].setColor(sf::Color::Red);
    }
}

void Menu::update(){
    this->updateSFMLEvents();        
}

void Menu::render(){
    this->window->clear();

    this->drawMenu(this->window);

    this->window->display();
}

void Menu::run(){
	while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}
