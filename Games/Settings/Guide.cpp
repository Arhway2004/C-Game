
#include "Guide.h"

Guide::Guide(): Base("Guide", 280, 100, 1.0, 1.2){
    this->bg_texture.loadFromFile("/Users/yangyaohui/Desktop/Arhway/C-Game/assets/textures/GreenBoard.png");
    this->A_texture.loadFromFile("/Users/yangyaohui/Desktop/Arhway/C-Game/assets/textures/A.png");
    this->D_texture.loadFromFile("/Users/yangyaohui/Desktop/Arhway/C-Game/assets/textures/D.png");
    this->S_texture.loadFromFile("/Users/yangyaohui/Desktop/Arhway/C-Game/assets/textures/S.png");
    this->W_texture.loadFromFile("/Users/yangyaohui/Desktop/Arhway/C-Game/assets/textures/W.png");
    this->Mouse_texture.loadFromFile("/Users/yangyaohui/Desktop/Arhway/C-Game/assets/textures/Mouse.png");

    this->background.setSize(sf::Vector2f(680, 400));
    this->background.setTexture(&this->bg_texture);

    this->A.setSize(sf::Vector2f(150, 150));
    this->A.setTexture(&this->A_texture);

    this->D.setSize(sf::Vector2f(150, 150));
    this->D.setTexture(&this->D_texture);

    this->S.setSize(sf::Vector2f(150, 150));
    this->S.setTexture(&this->S_texture);

    this->W.setSize(sf::Vector2f(150, 150));
    this->W.setTexture(&this->W_texture);

    this->Mouse.setSize(sf::Vector2f(450, 450));
    this->Mouse.setTexture(&this->Mouse_texture);

    this->background.setPosition(140, 50);
    this->A.setPosition(180, 220);
    this->D.setPosition(350, 220);
    this->S.setPosition(265, 220);
    this->W.setPosition(265, 140);
    this->Mouse.setPosition(400, 40);

    this->A.setScale(1.0, 1.0);
    this->D.setScale(1.0, 1.0);
    this->S.setScale(1.0, 1.0);
    this->W.setScale(1.0, 1.0);
    this->Mouse.setScale(1.0, 1.0);
}

Guide::~Guide(){
    delete this->window;
}

void Guide::update(const sf::Vector2f mousePos){
    
}

void Guide::render_guide(sf::RenderTarget* target){
    target->draw(this->background);
    target->draw(this->A);
    target->draw(this->D);
    target->draw(this->S);
    target->draw(this->W);
    target->draw(this->Mouse);

    
}
