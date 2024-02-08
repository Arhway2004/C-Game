//base class for game to call other scene
#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow* window) : GameState(window)
{
    this->endNow = false;
    this->initFont(this->font, "../assets/font/SEASHORE.otf"); 
    // this->game_title = new sf::Text; 
    this->setText(this->game_title, this->font, sf::Color::White, 100, 270, 150, "Untitled"); 
    // this->initKeyBinds(); for what
    
    this->main_menu_btn = new Button(300.0, 300.0, 150.0, 60.0, &this->font, "Start Game");
    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    this->background.setFillColor(sf::Color::Black);  
}

MainMenu::~MainMenu(){
    delete this->main_menu_btn;
    // delete this->game_title;
}


//how to change scene 
void MainMenu::updateInput(const float& dt){
    std::cout << "button pressed: " << this->main_menu_btn->isPressed() << "\n";
    if(this->main_menu_btn->isPressed()){
        this->endNow = true;
    }else{
        this->endNow = false;
    }
    // this->checkForEnd();
}

void MainMenu::endState(){
    //transfer to another scene
    std::cout << "Ending Main Menu" << "\n";
}

// bool MainMenu::getQuit() const {
//     GameState::getQuit(); 
// }

// void MainMenu::checkForEnd(){
//     GameState::checkForEnd(); 
// }


void MainMenu::update(const float& dt){
    //update per frame
    //update mouse
    this->updateMousePosition();
    std::cout << "mousePosView: " << this->mousePosView.x << ", " << this->mousePosView.y << std::endl; 
    this->main_menu_btn->update(this->mousePosView); 

    this->updateInput(dt);
    
    // std::cout << "Hello form main menu" << "\n"; 
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !isPressed){
        std::cout << "A" << "\n"; 
        isPressed = true; 
    }else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        isPressed = false; 
    }
}

void MainMenu::render(sf::RenderTarget* target) {
    if(!target){
        target = this->window; 
    }
    target->draw(this->background);
    target->draw(game_title);
    this->main_menu_btn->render(target);
}
