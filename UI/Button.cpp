#include "Button.h"


Button::Button(float x, float y, float width, float height, sf::Font* font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
    this->shape.setPosition(sf::Vector2(x, y)); 
    this->shape.setSize(sf::Vector2f(width, height));

    this->buttonStates = IDLE; 

    this->font = font; 
    this->text.setFont(*this->font); 
    this->text.setString(text); 
    this->text.setFillColor(sf::Color::White); 
    this->text.setCharacterSize(12); 
    this->text.setPosition(
        //center text
        this->shape.getPosition().x / 2.f - this->text.getGlobalBounds().width / 2.f,
        this->shape.getPosition().y / 2.f - this->text.getGlobalBounds().height / 2.f
        //this->shape.getPosition().x = top left corner 
    );

    this->idleColor = idleColor; 
    this->hoverColor = hoverColor; 
    this->activeColor = activeColor; 
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
            this->shape.setFillColor(this->idleColor); 
            break; 
        case HOVER: 
            this->shape.setFillColor(this->hoverColor); 
            break;
        case PRESSED:
            this->shape.setFillColor(this->activeColor);  
            break; 
        default: 
            this->shape.setFillColor(sf::Color::Red); 
            break; 
    }
}

void Button::render(sf::RenderTarget* target){
    target->draw(this->shape); 
}



