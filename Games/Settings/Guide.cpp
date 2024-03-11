
#include "Guide.h"

Guide::Guide(): Base("Guide", 280, 100, 1.0, 1.2){
    std::cout << "Guide::Guide: Guide constructor" << std::endl;
    // this->bg_texture.loadFromFile("/Users/arhway/Desktop/Arhway/C-Game/assets/textures/GreenBoard.png");
    this->A_texture.loadFromFile("../../assets/textures/A.png");
    this->D_texture.loadFromFile("../../assets/textures/D.png");
    this->S_texture.loadFromFile("../../assets/textures/S.png");
    this->W_texture.loadFromFile("../../assets/textures/W.png");
    this->Mouse_texture.loadFromFile("../../assets/textures/Mouse.png");

    // this->background.setSize(sf::Vector2f(680, 400));
    // this->background.setTexture(&this->bg_texture);

    this->A.setSize(sf::Vector2f(125, 125));
    this->A.setTexture(&this->A_texture);

    this->D.setSize(sf::Vector2f(125, 125));
    this->D.setTexture(&this->D_texture);

    this->S.setSize(sf::Vector2f(125, 125));
    this->S.setTexture(&this->S_texture);

    this->W.setSize(sf::Vector2f(125, 125));
    this->W.setTexture(&this->W_texture);

    this->Mouse.setSize(sf::Vector2f(400, 400));
    this->Mouse.setTexture(&this->Mouse_texture);

    // this->background.setPosition(140, 50);
    this->A.setPosition(300, 240);
    this->D.setPosition(440, 240);
    this->S.setPosition(370, 240);
    this->W.setPosition(370, 175);
    this->Mouse.setPosition(500, 70);

    this->A.setScale(1.0, 1.0);
    this->D.setScale(1.0, 1.0);
    this->S.setScale(1.0, 1.0);
    this->W.setScale(1.0, 1.0);
    this->Mouse.setScale(1.0, 1.0);
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
        target->draw(this->A);
        target->draw(this->D);
        target->draw(this->S);
        target->draw(this->W);
        target->draw(this->Mouse);
        //render other ui elements here 
    }else{
        std::cout << "Options::render_options: Closing window" << std::endl;
    }
}
