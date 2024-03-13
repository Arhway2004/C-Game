#include "ClickableIcon.h"

ClickableIcon::ClickableIcon(int pos_x, int pos_y, float scale_x, float scale_y, std::string path){
    this->clicked = false; 
    if(!this->texture.loadFromFile(path)){
        std::cout << "ERROR at ClickableIcon::Couldn't load the texture" << std::endl;
    }else{
        std::cout << "ClickableIcon::Texture loaded" << std::endl;
    }

    this->icon = new sf::Sprite(this->texture);
    this->icon->setScale(scale_x, scale_y);
    this->icon->setPosition(pos_x, pos_y);
}

ClickableIcon::~ClickableIcon(){
    delete this->icon; 
}

const bool ClickableIcon::getClicked() const{
    return this->clicked; 
}

bool ClickableIcon::isClicked(const sf::Vector2f mousePos){
    bool isInBound = icon->getGlobalBounds().contains(mousePos);
    bool mousePressed =sf::Mouse::isButtonPressed(sf::Mouse::Left);

    this->clicked = isInBound && mousePressed;

    return this->clicked;
}


bool ClickableIcon::resetClick(){
    this->clicked = false; 
    return false; 
}

const bool ClickableIcon::isClicked2() const{
    if(this->clickableState == PRESSED_C){
        return true;
    }
    return false;
}

void ClickableIcon::update(const sf::Vector2f mousePos){
    this->clickableState = RELEASED_C;
    if(this->icon->getGlobalBounds().contains(mousePos)){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            this->clickableState = PRESSED_C;
        }
    }
}



void ClickableIcon::render(sf::RenderTarget* target){
    std::cout << "rendering icon" << std::endl;
    target->draw(*this->icon); 
}