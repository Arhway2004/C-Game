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
    delete &this->icon; 
}

const bool ClickableIcon::getClicked() const{
    return this->clicked; 
}

bool ClickableIcon::isClicked(const sf::Vector2f mousePos){
    if(icon->getGlobalBounds().contains(mousePos)){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            this->clicked = true;
            std::cout << "icon cliked: "  << this->clicked << std::endl;
        }else{
            this->clicked = false;
            std::cout << "icon cliked: "  << this->clicked << std::endl;
        }
    }
    return this->clicked;
}

void ClickableIcon::update(const float& dt){
    //chnge pic of smth
}

void ClickableIcon::render(sf::RenderTarget* target){
    std::cout << "rendering icon" << std::endl;
    target->draw(*this->icon); 
}