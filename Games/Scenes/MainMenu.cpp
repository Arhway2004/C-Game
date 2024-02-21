//base class for game to call other scene
#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow* window) : GameState(window)
{
    this->endNow = false;
    this->initFont(this->font, "../assets/font/SEASHORE.otf"); 
    this->setText(this->game_title, this->font, sf::Color::White, 100, 370, 100, "Untitled"); 
    
    this->start_btn = new Button(400.0, 250.0, 150.0, 60.0, &this->font, "Start Game");
    this->quit_btn = new Button(400.0, 330.0, 150.0, 60.0, &this->font, "Quit Game");
    //add asset

    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    this->background.setFillColor(sf::Color::Black);  

}

MainMenu::~MainMenu(){
    delete this->start_btn;
    // delete this->game_title;
}

// void MainMenu::updateInput(const float& dt, Button* btn){
//     this->endNow = false; 
//     std::cout << "button pressed: " << btn->isPressed() << "\n";
//     if(btn->isPressed()){
//         this->endNow = true;
//     }else{
//         this->endNow = false;
//     }
//     // this->checkForEnd();
// }

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
    this->start_btn->update(this->mousePosView); 
    this->quit_btn->update(this->mousePosView);
    
    if(this->quit_btn->isPressed()){
        this->window->close();
    }
    if(this->start_btn->isPressed()){
        this->endNow = true;
    }else{
        this->endNow = false;
    }
    GameState::update(dt);
}

void MainMenu::render(sf::RenderTarget* target) {
    if(!target){
        target = this->window; 
    }
    target->draw(this->background);
    target->draw(game_title);
    this->start_btn->render(target);
    this->quit_btn->render(target);
    GameState::render(target);
}
