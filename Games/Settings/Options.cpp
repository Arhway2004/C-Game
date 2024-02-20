#include "Options.h"

//what is the purpose of this function?

Options::Options() : Base("Options", 280, 100, 1.0, 1.2){
    this->currentState = BASE; 
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
    //add action
    if(this->resume_icon) this->resume_icon->isClicked(mousePos);
    if(this->restart_icon) this->restart_icon->isClicked(mousePos);
    if(this->setting_icon) this->setting_icon->isClicked(mousePos);
    if(this->guide_icon) this->guide_icon->isClicked(mousePos);
    if(this->quit_icon) this->quit_icon->isClicked(mousePos);

    Base::update(mousePos);
    if (this->resume_icon->getClicked()){
        // this->currentState = RESUME;
        this->show_resume = true;
        std::cout << "Click resume" << std::endl;
    }
    else if (this->restart_icon->getClicked()){
        // this->currentState = RESTART;
        this->show_restart = true;
        std::cout << "Click restart" << std::endl;
    }
    else if (this->setting_icon->getClicked()){
        // this->currentState = SETTINGS;
        this->show_setting = true;
        std::cout << "Click setting" << std::endl;
    }
    else if (this->guide_icon->getClicked()){
        // this->currentState = GUIDE;
        this->show_guide = true;
        std::cout << "Guide" << std::endl;
        // this->show_base = false;
    }
    else if (this->quit_icon->getClicked()){
        // this->quit = true; 
        // this->currentState = QUIT;
        this->show_quit = true;
        std::cout << "Click quit" << std::endl;
        // this->closeWindow(); 
    }
    
    else{
        // this->currentState = BASE;
        this->show_base = true;
    }
    std::cout << "current stage " << this->currentState << std::endl;    
}

void Options::render_options(sf::RenderTarget* target){
    //nothing vdo18
    if(!quit && this->show_base == true){
    // if(!quit){
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
    // if(!quit && this->currentState == BASE && this->show_base == true){
    //     std::cout << "Options::render_options" << std::endl;
    //     target->draw(*this->frame);
    //     target->draw(*this->close_icon);
    //     target->draw(this->title);
    //     this->resume_icon->render(target);
    //     this->restart_icon->render(target);
    //     this->setting_icon->render(target);
    //     this->guide_icon->render(target);
    //     this->quit_icon->render(target);
    // }else{
    //     std::cout << "Options::render_options: Closing window" << std::endl;
    // }

}