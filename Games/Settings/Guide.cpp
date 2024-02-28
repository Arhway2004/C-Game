
#include "Guide.h"

Guide::Guide(): Base("Guide", 280, 100, 1.0, 1.2){
    std::cout << "Guide::Guide: Guide constructor" << std::endl;
    //add other ui here
}



Guide::~Guide(){
    
}

void Guide::reset_quit(){
    this->quit = false; 
}

bool Guide::return_quit(){
    return this->quit;
}

void Guide::update(const sf::Vector2f mousePos){
    Base::update(mousePos); //track if user click red cross to quit 
}

void Guide::render_guide(sf::RenderTarget* target){
    if(!quit){
        std::cout << "Guide::render_guide" << std::endl;
        target->draw(this->frame);
        target->draw(this->close_icon);
        target->draw(this->title);
        //render other ui elements here 
    }else{
        std::cout << "Options::render_options: Closing window" << std::endl;
    }
}
