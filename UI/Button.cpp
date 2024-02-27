#include "Button.h"
#include <iostream>

Button::Button(float x, float y, float width, float height, sf::Font* font, std::string text)
{
    this->shape.setPosition(sf::Vector2f(x, y)); 
    this->shape.setSize(sf::Vector2f(width, height));

    this->buttonStates = IDLE; 

    this->font = font; 
    this->text.setFont(*this->font); 
    this->text.setString(text); 
    this->text.setFillColor(sf::Color::White); 
    this->text.setCharacterSize(25); 
    this->text.setPosition(
        //center text
        this->shape.getPosition().x + this->text.getGlobalBounds().width / 2.f - 5,
        this->shape.getPosition().y + this->text.getGlobalBounds().height / 2.f + 5
        //this->shape.getPosition().x = top left corner 
    );

    this->idleColor = sf::Color::Blue; 
    this->hoverColor = sf::Color::Red; 
    this->activeColor = sf::Color::Green; 
}

Button::~Button(){

}

//accessor
const bool Button::isPressed() const{
    if (this->buttonStates == PRESSED){
        return true; 
    }
    return false; 
}

void Button::update(const sf::Vector2f mousePos){
    this->buttonStates = IDLE; 

    //hover
    if(this->shape.getGlobalBounds().contains(mousePos)){
        this->buttonStates = HOVER;

        //pressed
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            this->buttonStates = PRESSED;
        }
    }

    switch(this->buttonStates){
        case IDLE: 
            std::cout << "idle" << std::endl; 
            this->shape.setFillColor(this->idleColor); 
            break; 
        case HOVER: 
            std::cout << "hover" << std::endl; 
            this->shape.setFillColor(this->hoverColor); 
            break;
        case PRESSED:
            std::cout << "pressed" << std::endl; 
            this->shape.setFillColor(this->activeColor);  
            break; 
        default: 
            std::cout << "defualt" << std::endl; 
            this->shape.setFillColor(sf::Color::Red); 
            break; 
    }
    std::cout << "\x1B[2J\x1B[H"; 
}

void Button::render(sf::RenderTarget* target){
    target->draw(this->shape);
    //temp
    target->draw(this->text); 
}



