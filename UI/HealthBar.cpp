#include "HealthBar.h"

//frame.setSize(sf::Vector2f(77, 8));
//blood.setSize(sf::Vector2f(74, 5));
HealthBar::HealthBar(float pos_x, float pos_y, float set_w, float set_h, int fullHealth, sf::Color bloodColor) {
    this->position = sf::Vector2f(pos_x, pos_y);
    this->frame.setSize(sf::Vector2f(set_w, set_h));
    this->frame.setPosition(this->position);
    this->frame.setFillColor(sf::Color::Transparent);
    this->frame.setOutlineColor(sf::Color::Black);
    this->frame.setOutlineThickness(1.0f);

    this->blood.setSize(sf::Vector2f(set_w - 3, set_h - 3));
    this->blood.setFillColor(bloodColor);
    this->blood.setOutlineColor(bloodColor);
    this->blood.setPosition(pos_x + 2, pos_y + 2);

    this->fullHealth = fullHealth;
}

HealthBar::~HealthBar(){
    
}

void HealthBar::setPosition(float x, float y){
    this->frame.setPosition(sf::Vector2f(x, y));
    this->blood.setPosition(x + 2, y + 2);
}


void HealthBar::update(const int change){ //if damage change = - / gain change = +
    //move health bar 
    float percent = ((float)change / (float)this->fullHealth) * 100;
    this->fullHealthtoPercent += percent;
    if(this->fullHealthtoPercent >= 0 && this->fullHealthtoPercent <= 100){
        //change just number
        std::cout << "HealthBar::update:: Health bar is not full" << std::endl;
        this->blood.setSize(sf::Vector2f(this->blood.getSize().x * this->fullHealthtoPercent / 100 , this->blood.getSize().y));
    }else{
        this->blood.setSize(sf::Vector2f(0.0 , this->blood.getSize().y));
    }
}


void HealthBar::render(sf::RenderTarget* target){
    target->draw(this->frame);  
    target->draw(this->blood);
}