//base class for game to call other scene
#include "../include/MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow* window) : GameState(window)
{

}

MainMenu::~MainMenu(){

}

void MainMenu::updateInput(const float& dt){
    this->checkForEnd(); 
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

void MainMenu::update(const float& dt){
    //update per frame
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

}
