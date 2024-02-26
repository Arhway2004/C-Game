#include "../include/GameState.h"

GameState::GameState(sf::RenderWindow* window) : option_icon(850.0, 0.0, 1.0, 1.0, "../assets/icons/setting.png"){
    this->window = window;
    this->endNow = false;

    this->option_page = std::make_shared<Options>(); 
    this->guide_page = std::make_shared<Guide>(); 
    this->showOption = false;
    this->showGuide = false;
}

GameState::~GameState(){

}   

void GameState::updateOptions(){
    //current state
    //click 
    std::cout << "option beginning: " << this->showOption << std::endl;
    std::cout << "guide beginning: " << this->showGuide << std::endl;
    this->updateMousePosition(); 

    this->option_icon.update(mousePosView);
   
    
    if(this->showOption){
        this->option_page->update(this->mousePosView);
        if(this->option_page->return_quit()){
            this->showOption = false;
            this->option_page->endState();
        }
    }else if(this->showGuide){
        this->guide_page->update(this->mousePosView);
        if(this->guide_page->return_quit()){
            this->showGuide = false;
            this->showOption = false;
            this->option_page->show_guide = false;
            this->guide_page->endState();
            std::cout << "show quit guide: " << this->option_page->show_guide << std::endl;
        }else{
            std::cout << "not enter quit" << std::endl;
        }
    }
    
    std::cout << "option icon clicked: " << option_icon.isClicked2() << std::endl;
    if (this->option_icon.isClicked2()){
        this->showOption = true;
        this->showGuide = false;
        this->option_page->show_guide = false;
        this->option_page->reset_quit();
    }

     this->showGuide = this->option_page->show_guide;
     if(this->option_page->show_guide) {
        this->guide_page->reset_quit();
     } 

    
    std::cout << "option_page->guide_icon.getClicked()" << this->option_page->guide_icon.getClicked() << std::endl;
    std::cout << "guide before render: " << this->showGuide << std::endl;
    std::cout << "show quit guide before render: " << this->option_page->show_guide << std::endl;

}
 

void GameState::update(const float& dt, sf::RenderWindow* window){
    this->updateOptions();
    
}


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
    this->option_icon.render(target);
    std::cout << "show option render: " << this->showOption << std::endl;
    std::cout << "show guide render: " << this->showGuide << std::endl;
    if(this->showOption){ //showOption
        this->option_page->render_options(target);
    }else{
        if(this->showGuide){
            this->guide_page->render_guide(target);
        }else{
            std::cout << "not render guide" << this->showGuide << std::endl;
        }
    }
    
}
