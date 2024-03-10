//base class for game to call other scene
#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow* window) : GameState(window)
{
    this->endNow = false;
    this->initFont(this->font, "../assets/font/SEASHORE.otf"); 
    this->setText(this->game_title, this->font, sf::Color::White, 100, 370, 100, "Untitled"); 
    
    this->start_btn = Button(400.0, 250.0, 150.0, 60.0, &this->font, "Start Game");
    this->quit_btn = Button(400.0, 330.0, 150.0, 60.0, &this->font, "Quit Game");
    //add asset

    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    this->background.setFillColor(sf::Color::Black);
    this->music = new(Setting);  


}

MainMenu::~MainMenu(){

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
// }

// void MainMenu::checkForEnd(){
//     GameState::checkForEnd(); 
// }


void MainMenu::update(const float& dt, sf::RenderWindow* window){
    //update per frame
    //update mouse

    this->updateMousePosition();
    this->start_btn.update(this->mousePosView); 
    this->quit_btn.update(this->mousePosView);

    if(!this->showOption && !this->showGuide && !this->showSetting){
        if(this->quit_btn.isPressed()){
            std::cout << "quit button pressed" << std::endl;
            if (window != nullptr) {
                std::cout << "MainMenu::update:: window = null ptr" << std::endl;
                window->close();
            }
        }
        if(this->start_btn.isPressed()){
            std::cout << "str button pressed" << std::endl;
            this->endNow = true;
        }else{
            this->endNow = false;
        } 
    }

    GameState::update(dt, window);
}

void MainMenu::render(sf::RenderTarget* target) {


    if(!target){
        target = this->window; 
    }
    target->draw(this->background);
    target->draw(game_title);
    this->start_btn.render(target);
    this->quit_btn.render(target);
    GameState::render(target);
}
