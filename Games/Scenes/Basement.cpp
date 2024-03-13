#include "Basement.h"

// change when pressed start
Basement::Basement(sf::RenderWindow *window) : GameState(window)
{
    this->endNow = false;
    this->window = window;
    this->background.setSize(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));
    this->background.setFillColor(sf::Color::White);
    this->loadTextures(this->bgTex, "../assets/textures/base_bg.png");
    this->bg.setTexture(this->bgTex);
    this->bg.setScale(2.76f, 2.9f);
    this->bg.setPosition(0.f, 0.f);
    // this->initFont(this->font, "../assets/font/SEASHORE.otf");
    // this->test_btn = new Button(400.0, 250.0, 150.0, 60.0, &this->font, "Door Test");
    this->door1 = new InteractableObj(485.0, 33.0, 2.76, 2.9, "../assets/textures/door1.png");
}

Basement::~Basement()
{
    
}

// void Basement::updateInput(const float& dt, Button* btn)
// {

// }

void Basement::endState()
{
    this->endNow = true;
}

void Basement::loadTextures(sf::Texture &texture, std::string path)
{
    if (!texture.loadFromFile(path))
    {
        std::cout << "Player::loadFile:: Error: Player texture not loaded" << std::endl;
    }
    else
    {
        std::cout << "Texture load successfully" << std::endl;
    }
}

void Basement::update(const float &dt, sf::RenderWindow* window)
{
    // Update per frame
    // Update mouse
    this->updateMousePosition();
    std::cout << "mousePosView: " << this->mousePosView.x << ", " << this->mousePosView.y << std::endl;
    this->door1->IsPressed(player.getPosition()); //need to implement how to get player position
    
    
    if (this->door1->getInput()) 
    {
        this->endNow = true;
    }

    sf::Vector2f playerPosition = player.getPosition();
    std::cout << "Player Position: " << playerPosition.x << ", " << playerPosition.y << std::endl;
    this->player.update(dt);

    GameState::update(dt, window);
}

void Basement::render(sf::RenderTarget *target)
{
    if (!target)
    {
        target = this->window;
    }
    target->draw(this->background);
    target->draw(this->bg);

    this->door1->render(target);

    this->player.render(target);
    
    GameState::render(target);
}
