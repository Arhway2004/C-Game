#include "../include/Game.h" 
#include <iostream>

Game::Game(){
    this->initWindow();
    this->initStates(); 
    this->run(); 
    this->update();
    this->render(); 
}

Game::~Game(){
    delete this->window; 
    while(!this->states.empty()){
        delete this->states.top(); 
        this->states.pop(); 
    }
}

void Game::endApplication(){
    std::cout << "Ending Application"; 
}

void Game::initWindow(){
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Untitled"); 
    this->window->setFramerateLimit(144); 
    this->window->setVerticalSyncEnabled(false); 
}

void Game::initVariables(){
    
}

void Game::initStates(){
    this->states.push(new MainMenu(this->window)); 
}

void Game::run(){
    while(this->window->isOpen()){
        sf::Event event; 
        while(this->window->pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window->close(); 
            }
        }
        this->updateDt(); //set new dt every framerate
        this->update(); 
        this->render();
    }
}

void Game::updateDt(){
    //update dt with time taken to update and render 1 frame
    this->dt = this->dtClock.restart().asSeconds(); 
    //debug
    // std::cout << "\x1B[2J\x1B[H"; 
    // std::cout << this->dt << "\n"; 
}

void Game::updateGUI(){
    if(!this->font.loadFromFile("../assets/font/SEASHORE.otf")){
        std::cout << "ERROR at game/updateGUI::couldn't upload the font" <<std::endl; 
    }
}

void Game::update(){
    this->updateGUI(); 
    if(!this->states.empty()){
        this->states.top()->checkForEnd(); 

        this->states.top()->update(this->dt); //if met some condition = ask to quit

        if(this->states.top()->getQuit()){
            this->states.top()->endState(); 
            delete this->states.top(); 
            this -> states.pop(); 
        }
    }//App ends
    else{
        this->endApplication(); 
        this->window->close(); 
    }
}

void Game::render(){
    this->window->clear(); 

    //render item
    if(!this->states.empty()){
        // this->states.top()->endState(); 
        this->states.top()->render(this->window);   
    }
    this->window->display(); 
}