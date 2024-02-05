#include "../include/GameState.h"

GameState::GameState(sf::RenderWindow* window){
    this->window = window; 
    this->endNow = false; 
}

GameState::~GameState(){

}

void GameState::update(const float& dt){

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

void GameState::render(sf::RenderTarget* target){

}




