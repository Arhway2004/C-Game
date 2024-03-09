#include "../include/GameState.h"

GameState::GameState(sf::RenderWindow* window) : option_icon(850.0, 0.0, 1.0, 1.0, "../assets/icons/setting.png"){
    this->window = window;
    this->endNow = false;

    this->option_page = std::make_shared<Options>(); 
    this->guide_page = std::make_shared<Guide>(); 
    this->setting_page = std::make_shared<Setting>(); 
    //init setting page here
    this->showOption = false;
    this->showGuide = false;
    this->showSetting = false;

    // click for setting
    this->plus1click =false;
    this->plus2click =false;
    this->delete1click =false;
    this->delete2click = false;

    //show setting = false 
}

GameState::~GameState(){

}   

void GameState::updateOptions(){
    //current state
    //click 
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
        }
    }else if(this->showSetting){
        this->setting_page->update(this->mousePosView);

        if(this->setting_page->return_quit()){
            this->showSetting = false;
            this->showOption = false;
            this->option_page->show_setting = false;
            this->setting_page->endState();
        }
    }
    //else if(this->showQuit) do what
    
    if (this->option_icon.isClicked2()){
        this->showOption = true;
        this->showGuide = false;
        this->showSetting = false;
        this->option_page->show_guide = false;
        this->option_page->show_setting = false;
        this->option_page->reset_quit();
    }

    this->showGuide = this->option_page->show_guide;
    this->showSetting = this->option_page->show_setting;

    if(this->option_page->show_guide) {
    this->guide_page->reset_quit();
    }
    if(this->option_page->show_setting) {
    this->setting_page->reset_quit();
    }
    //else if(this->option_page->show_quit) do what
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
    if(this->showOption){ //showOption
        this->option_page->render_options(target);
        // this->plus1click->*render(target);
    }else{
        if(this->showGuide){
            this->guide_page->render_guide(target);

        }else{
            std::cout << "not render guide" << this->showGuide << std::endl;
        }

        if(this->showSetting){
            this->setting_page->render_setting(target);

        }else{
            std::cout << "not render setting" << this->showSetting << std::endl;
        }
    }
    
}
