#include "Options.h"

// Options::Options(int pos_x ,int pos_y ,int scale_x , int scale_y , std::string title , std::string path) : Base(pos_x, pos_y, scale_x, scale_y, title, path){

//     // set position and scale for each icon
//     // ClickableIcon(int pos_x, int pos_y, int scale_x, int scale_y, std::string path); 
//     // resume_icon = new ClickableIcon(0, 0, "res/img/icons/resume.png");
// }

//marked add text/icons to the option window
Options::Options() : Base("Options", 280, 100, 1.0, 1.2){
    this->resume_icon = new ClickableIcon(440 , 140, 0.25, 0.25, "../assets/icons/resume2.png");
    this->restart_icon = new ClickableIcon(440, 200, 0.22, 0.22, "../assets/icons/restart2.png");
    this->setting_icon = new ClickableIcon(440, 260, 0.20, 0.20, "../assets/icons/setting2.png");
    this->guide_icon = new ClickableIcon(440, 320, 0.25, 0.25, "../assets/icons/guide2.png");
    this->quit_icon = new ClickableIcon(440, 380, 0.3, 0.3, "../assets/icons/quit2.png");
}

Options::~Options(){
    delete this->resume_icon;
    delete this->restart_icon;
    delete this->setting_icon;
    delete this->guide_icon; 
    delete this->quit_icon;
}

// void Options::endState(){

// }

void Options::reset_quit(){
    this->quit = false; 
}

void Options::update(const sf::Vector2f mousePos){
    std::cout << "Options::update: Closing window" << std::endl;
    Base::update(mousePos);
    // this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
    //add action
    if (this->resume_icon->isClicked(mousePos)){
        // this->closeWindow(); 
    }
    if (this->restart_icon->isClicked(mousePos)){
        // this->closeWindow(); 
    }
    if (this->setting_icon->isClicked(mousePos)){
        // this->closeWindow(); 
    }
    if (this->guide_icon->isClicked(mousePos)){
        // this->closeWindow(); 
    }
    if (this->quit_icon->isClicked(mousePos)){
        // this->closeWindow(); 
    }
}

void Options::render_options(sf::RenderTarget* target){
    //nothing vdo18
    if(!quit){
        std::cout << "Options::render_options" << std::endl;
        target->draw(*this->frame);
        target->draw(*this->close_icon);
        target->draw(this->title);
        this->resume_icon->render(target);
        this->restart_icon->render(target);
        this->setting_icon->render(target);
        this->guide_icon->render(target);
        this->quit_icon->render(target);
    }else{
        std::cout << "Options::render_options: Closing window" << std::endl;
    }
    
}