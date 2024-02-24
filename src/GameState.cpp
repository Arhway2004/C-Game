#include "../include/GameState.h"

GameState::GameState(sf::RenderWindow* window){
    this->window = window;
    this->endNow = false;

    // this->option_icon = std::make_shared<ClickableIcon>(850.0, 0.0, 1.0, 1.0, "../assets/icons/setting.png");
    this->option_icon = new ClickableIcon(850.0, 0.0, 1.0, 1.0, "../assets/icons/setting.png");

    this->option_page = std::make_shared<Options>(); 
    this->guide_page = std::make_shared<Guide>(); 
}

GameState::~GameState(){

}

void GameState::update(const float& dt, sf::RenderWindow* window){
    this->updateMousePosition(); 
    this->option_page->update(this->mousePosView);
    this->guide_page->update(this->mousePosView);
    // std::cout << "enum: " << this->option_page->currentState + 1 << std::endl;

    //icon
    this->option_icon->isClicked(this->mousePosView);
    if (this->option_icon->getClicked()){
       this->showOption = true;
       this->option_page->reset_quit();
    }

    if(this->option_page->return_quit()){
        showOption = false; 
    }

    // if(this->guide_page->return_quit()){
    //     this->option_page->show_guide = false;
    // }

    //     this->showOption = true;
    //     this->option_page->currentState = BASE;
    //     this->option_page->show_guide = false;
    //     this->option_page->show_base = true;
    // }
}

// void GameState::updateInput(const float& dt, Button* btn){
    
// }

void GameState::initFont(sf::Font& font, std::string path){
    if(!font.loadFromFile(path)){
        std::cout << "ERROR at MainMenu/initFont::couldn't upload the font" << std::endl; 
    }
}

void GameState::setText(sf::Text& text, sf::Font& font, sf::Color msg_color, short size, short int pos_x, short int pos_y, std::string msg){
    text.setFont(font);
    text.setString(msg);
    text.setFillColor(msg_color);
    text.setCharacterSize(size); 
    text.setPosition(
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

void GameState::render(sf::RenderTarget* target){
    if(!target){
        target = this->window; 
    }
    this->option_icon->render(target);
    if(this->showOption){
        this->option_page->render_options(target);
    }
    // if(this->option_page->show_guide){
    //     this->guide_page->render_guide(target);
    // }
}
