//base class for game to call other scene
#include "../include/MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow* window) : GameState(window)
{
    this->initFont(); 
    this->game_title = new sf::Text; 
    this->setText(game_title, this->font, sf::Color::White, 60, 350, 150, "Untitled"); 
    // this->initKeyBinds(); for what
    
    this->main_menu_btn = new Button(350.0, 300.0, 150.0, 60.0, &this->font, "Start Game");
    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    this->background.setFillColor(sf::Color::Black);  
}

MainMenu::~MainMenu(){
    delete this->main_menu_btn; 
    delete this->game_title; 
}

void MainMenu::updateInput(const float& dt){
    this->checkForEnd();

}

void MainMenu::initFont(){
    if(!this->font.loadFromFile("../assets/font/SEASHORE.otf")){
        std::cout << "ERROR at MainMenu/initFont::couldn't upload the font" << std::endl; 
    }
}

void MainMenu::endState(){
    std::cout << "Ending Main Menu" << "\n"; 
}

// bool MainMenu::getQuit() const {
//     GameState::getQuit(); 
// }

// void MainMenu::checkForEnd(){
//     GameState::checkForEnd(); 
// }

//temp
void MainMenu::updateMouseTemp(){
    // sf::Vector2f temp = sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y); 
    // this->mousePos = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window)); 
    // this->mousePos = sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y); 
}


void MainMenu::update(const float& dt){
    //update per frame
    //temp
    // this->updateMouseTemp(); 
    // this->main_menu_btn->update(this->mousePos); 
    // this->main_menu_btn->update(this->mousePosView); 

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
    this->window->draw(*game_title);
    this->main_menu_btn->render(target);
}
