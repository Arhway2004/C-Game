#include "../include/Game.h" 
#include <iostream>

Game::Game(){
    this->initWindow();
    this->run(); 
    this->update();
    this->render(); 
}

Game::~Game(){
}

void Game::initWindow(){
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Untitled"); 
    this->window->setFramerateLimit(144); 
    this->window->setVerticalSyncEnabled(false); 
}

void Game::initVariables(){
    
}

void Game::initSystem(){

}

void Game::run(){
    while(this->window->isOpen()){
        sf::Event event; 
        while(this->window->pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window->close(); 
            }
        }
        this->update(); 
        this->render(); 
    }
}


void Game::updateGUI(){
    if(!this->font.loadFromFile("../assets/font/SEASHORE.otf")){
        std::cout << "ERROR at game/updateGUI::couldn't upload the font" <<std::endl; 
    }
}

void Game::update(){
    this->updateGUI(); 
}

void Game::render(){
    this->window->clear(); 
    this->window->display(); 
}