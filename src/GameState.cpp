#include "../include/GameState.h"

GameState::GameState(sf::RenderWindow* window){
    this->window = window; 
    this->endNow = false; 
}

GameState::~GameState(){

}

void GameState::update(const float& dt){
    this->updateMousePosition(); 
}

void GameState::updateInput(const float& dt){
    
}

//temp
void GameState::updateMouseTemp(){

}

void GameState::setText(sf::Text* text, sf::Font font, sf::Color msg_color, short size, short int pos_x, short int pos_y, std::string msg){
    text->setFont(font);
    text->setString(msg); 
    text->setFillColor(msg_color); 
    text->setCharacterSize(size); 
    text->setPosition(
        pos_x, pos_y
    );
}

bool GameState::getQuit() const{
    return this->endNow; 
}

void GameState::endState(){
    std::cout << "Ending GameState!" << "\n"; 
}

void GameState::checkForEnd(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        this->endNow = true; 
    }
}

void GameState::updateMousePosition(){
    this->mousePosScreen = sf::Mouse::getPosition(); 
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}




