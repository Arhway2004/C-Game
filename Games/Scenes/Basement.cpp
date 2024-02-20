#include "Basement.h"


//change when pressed start
Basement::Basement(sf::RenderWindow* window) : GameState(window)
{
    this->endNow = false;
    this->window = window;
    this->background.setSize(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));
    this->background.setFillColor(sf::Color::Black);
}

Basement::~Basement()
{
    delete this->window; 
}

// void Basement::updateInput(const float& dt, Button* btn)
// {

// }

void Basement::endState()
{
    this->endNow = true;
}


void Basement::update(const float& dt){
    GameState::update(dt);
}

void Basement::render(sf::RenderTarget* target)
{
    target->draw(this->background);
    GameState::render(target);
}