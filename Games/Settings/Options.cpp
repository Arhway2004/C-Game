#include "Options.h"

//what is the purpose of this function?

Options::Options() : Base("Options", 280, 100, 1.0, 1.2), resume_icon(440, 140, 0.25, 0.25, "../assets/icons/resume2.png"), restart_icon(440, 200, 0.22, 0.22, "../assets/icons/restart2.png"), setting_icon(440, 260, 0.20, 0.20, "../assets/icons/setting2.png"), guide_icon(440, 320, 0.25, 0.25, "../assets/icons/guide2.png"), quit_icon(440, 380, 0.3, 0.3, "../assets/icons/quit2.png") {
    this->music = new(Setting);
}

Options::~Options(){

}

void Options::reset_quit(){
    this->quit = false; 
}

bool Options::return_quit(){
    return this->quit;
}

void Options::update(const sf::Vector2f mousePos){
    //add action
    this->resume_icon.isClicked(mousePos);
    this->restart_icon.isClicked(mousePos);
    this->setting_icon.isClicked(mousePos);
    this->guide_icon.isClicked(mousePos);
    this->quit_icon.isClicked(mousePos);
    
    Base::update(mousePos);
    this->show_base = true;
    std::cout << "show guide: " << this->show_guide << std::endl;
    std::cout << "show setting: " << this->show_setting << std::endl;       
    if (this->resume_icon.getClicked()){
        music->playSFX();
        std::cout << "Click resume" << std::endl;
        //add functionalities
    }
    else if (this->restart_icon.getClicked()){
        music->playSFX();


        std::cout << "Click restart" << std::endl;
        this->quit = true;
        this->show_guide = false;
        this->show_resume = false;
        this->show_setting = false;
        this->show_restart = true;
        this->show_quit = false;

    }else if (this->setting_icon.getClicked()){
        music->playSFX();
        std::cout << "Click setting" << std::endl;
        this->quit = true;
        this->show_guide = false;
        this->show_resume = false;
        this->show_setting = true;
        this->show_restart = false;
        this->show_quit = false;
    }
    else if (this->guide_icon.getClicked()){
        music->playSFX();
        this->quit = true;
        this->show_guide = true;
        this->show_resume = false;
        this->show_setting = false;
        this->show_restart = false;
        this->show_quit = false;
    }
    else if (this->quit_icon.getClicked()){
        std::cout << "Click quit" << std::endl;
        // this->closeWindow(); 
    }
    else{
        this->show_guide = false;
        std::cout << "return base" << std::endl;
    }
    
}

void Options::render_options(sf::RenderTarget* target){
    if(!quit && this->show_base == true){
        target->draw(this->frame);
        target->draw(this->close_icon);
        target->draw(this->title);
        this->resume_icon.render(target);
        this->restart_icon.render(target);
        this->setting_icon.render(target);
        this->guide_icon.render(target);
        this->quit_icon.render(target);
    }else{
        std::cout << "Options::render_options: Closing window" << std::endl;
    }

}