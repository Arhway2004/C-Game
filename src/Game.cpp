#include "../include/Game.h" 
#include <iostream>

Game::Game(){
    this->initWindow();
    this->initStates(); 
    this->run(); 
    this->update();
    this->render(); 
    // this->music = new(Setting);
}
// : music(new Setting)
Game::~Game(){
    delete this->window; 
    while(!this->states.empty()){
        delete this->states.top(); 
        this->states.pop(); 
    }
}

void Game::endApplication(){
    std::cout << "Ending Application\n"; 
}

void Game::initWindow(){
    this->window = new sf::RenderWindow(sf::VideoMode(960, 540), "Untitled"); 
    this->window->setFramerateLimit(144);
    this->window->setVerticalSyncEnabled(false);
}

void Game::initVariables(){
}

void Game::initStates(){
    this->states.push(new Basement(this->window)); 
    this->states.push(new FirstScenes(this->window));
    this->states.push(new MainMenu(this->window));
}

void Game::run(){
    // this->music->playMusic(); 
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

void Game::add_scene(GameState* scene){
    this->states.push(scene); 
}

void Game::updateDt(){
    this->dt = this->dtClock.restart().asSeconds(); 
}

void Game::updateGUI(){
    if(!this->font.loadFromFile("../assets/font/SEASHORE.otf")){
        std::cout << "ERROR at game/updateGUI::couldn't upload the font" <<std::endl; 
    }
}

void Game::update(){
    if(!this->states.empty()){
        // this->states.top()->checkForEnd(); 
        this->states.top()->update(this->dt, this->window); //if met some condition = ask to quit
        // music->playMusic();
        std::cout << "states quit : " << this->states.top()->getQuit() << "\n";
        if(this->states.top()->getQuit()){
            this->states.top()->endState(); 
            delete this->states.top(); 
            this -> states.pop(); 

            std::cout << "states len : " << this->states.size() << "\n";
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
        this->states.top()->render(this->window);   
    }
    this->window->display();
    
}