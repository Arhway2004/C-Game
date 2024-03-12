#include "interactable_obj.h"
#include <iostream>

InteractableObj::InteractableObj(int pos_x, int pos_y, float scale_x, float scale_y, std::string path)
{
    this->inputted = false;

    if (!this->texture.loadFromFile(path))
    {
        std::cout << "ERROR at InteractableObj::Couldn't load the texture" << std::endl;
    }
    else
    {
        std::cout << "InteracableObj::Texture loaded" << std::endl;
    }

    this->icon = new sf::Sprite(this->texture);
    this->icon->setScale(scale_x, scale_y);
    this->icon->setPosition(pos_x, pos_y);
    this->bounds = icon->getGlobalBounds();

    
    if (!font.loadFromFile("../assets/font/SEASHORE.otf"))
    {
        // Handle font loading error
    }

    
    interactText.setFont(font);
    interactText.setString("Press F to Interact");
    interactText.setCharacterSize(25);
    interactText.setFillColor(sf::Color::White);
}

InteractableObj::~InteractableObj()
{
    delete this->icon;
}

const bool InteractableObj::getInput() const
{
    return this->inputted;
}



bool InteractableObj::IsPressed(const sf::Vector2f playerPosition)
{
    float interactionDistance = 85.0f;
    // Calculate center of the object
    sf::Vector2f objectCenter = sf::Vector2f(
        bounds.left + bounds.width / 2.0f,
        bounds.top + bounds.height / 2.0f);

    // Calculate distance between player and object center
    sf::Vector2f delta = playerPosition - objectCenter;
    float distance = std::sqrt(delta.x * delta.x + delta.y * delta.y);

    // If player is near the object, check for key press
    if (distance < interactionDistance)
    {
        sf::Vector2f textPosition(475.f,2.f);
        interactText.setPosition(textPosition);
        showText = true;
        std::cout << "Player near object" << std::endl;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
        {
            this->inputted = true;
        }
        else
        {
            this->inputted = false;
        }
    }
    else
    {
        this->inputted = false;
        showText = false;
    }

    return this->inputted;
}


void InteractableObj::update(const float &dt)
{
}

void InteractableObj::render(sf::RenderTarget *target)
{
    std::cout << "Rendering interactable" << std::endl;
    target->draw(*this->icon);
    if (showText)
    {
        target->draw(interactText);
    }
}

