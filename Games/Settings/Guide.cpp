#include "Guide.h"

Guide::Guide(): Base("Guide", 280, 100, 1.0, 1.2){
    std::cout << "Guide::Guide: Guide constructor" << std::endl;
}

Guide::~Guide(){

}

bool Guide::getQuit(){
    return this->quit;
}

void Guide::update(const sf::Vector2f mousePos){
    Base::update(mousePos);
}

void Guide::render_guide(sf::RenderTarget* target){
    std::cout << "Guide::render_guide: Rendering guide" << std::endl;
    // target->draw(*this->frame);
    // target->draw(*this->close_icon);
    // target->draw(this->title);
    if(!quit && this->currentState == GUIDE ){
        std::cout << "Options::render_options" << std::endl;
        target->draw(*this->frame);
        target->draw(*this->close_icon);
        target->draw(this->title);
        // this->resume_icon->render(target);
        // this->restart_icon->render(target);
        // this->setting_icon->render(target);
        // this->guide_icon->render(target);
        // this->quit_icon->render(target);
    }else{
        std::cout << "Options::render_options: Closing window" << std::endl;
    }
    //render arrow to go back to options
}
