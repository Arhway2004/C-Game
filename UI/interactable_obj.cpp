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
}

InteractableObj::~InteractableObj()
{
    delete this->icon;
}

const bool InteractableObj::getInput() const
{
    return this->inputted;
}

// bool InteractableObj::IsPressed(const sf::Vector2f mousePos)
// {   
    
    // Works now!
    // if (icon->getGlobalBounds().contains(mousePos))
    // {
    //     std::cout << "Mouse over object" << std::endl; 
    //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    //     {
    //         this->inputted = true;
    //         std::cout << "Key pressed: " << this->inputted << std::endl;
    //     }
    //     else
    //     {
    //         this->inputted = false;
    //         std::cout << "Key Pressed: " << this->inputted << std::endl;
    //     }
    // }
    // return this->inputted;

// Might use this logic in the future
// need to adjust some of logic for getting player position
bool InteractableObj::IsPressed(const sf::Vector2f playerPosition)
{
    float interactionDistance = 50.0f; // Adjust this distance as needed

    // Calculate distance between player and object
    float dx = playerPosition.x - (icon->getPosition().x + icon->getGlobalBounds().width / 2);
    float dy = playerPosition.y - (icon->getPosition().y + icon->getGlobalBounds().height / 2);
    float distance = std::sqrt(dx * dx + dy * dy);

    // If player is near the object, check for key press
    // Test player is exactly on the object
    if (playerPosition == icon->getPosition())
    {   
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
    }

    return this->inputted;
}


void InteractableObj::update(const float &dt)
{
    // Change picture or any other update logic here
}

void InteractableObj::render(sf::RenderTarget *target)
{
    std::cout << "Rendering interactable" << std::endl;
    target->draw(*this->icon);
}

