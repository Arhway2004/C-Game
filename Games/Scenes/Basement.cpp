#include "Basement.h"

// change when pressed start
Basement::Basement(sf::RenderWindow *window) : GameState(window)
{
    this->endNow = false;
    this->window = window;
    this->background.setSize(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));
    this->background.setFillColor(sf::Color::White);
    // this->initFont(this->font, "../assets/font/SEASHORE.otf");
    // this->test_btn = new Button(400.0, 250.0, 150.0, 60.0, &this->font, "Door Test");
    this->door1 = new ClickableIcon(400.0, 400.0, 1.0, 1.0, "../assets/textures/door_test.png");
    this->door2 = new ClickableIcon(600.0, 400.0, 1.0, 1.0, "../assets/textures/door_test.png");
    this->obj1 = new InteractableObj(800.0, 400.0, 1.0, 1.0, "../assets/textures/door_test.png");
}

Basement::~Basement()
{
    
}

void Basement::updateInput(const float& dt)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        this->endNow = true;
    }
}

void Basement::endState()
{
    this->endNow = true;
}

void Basement::update(const float &dt, sf::RenderWindow* window)
{
    // Update per frame
    // Update mouse
    this->updateInput(dt);
    this->updateMousePosition();
    std::cout << "mousePosView: " << this->mousePosView.x << ", " << this->mousePosView.y << std::endl;
    this->door1->isClicked(this->mousePosView);
    this->obj1->IsPressed(sf::Vector2<float>(800.0, 400.0)); //need to implement how to get player position
    if (this->door1->getClicked())
    {
        this->endNow = true;
    }
    
    if (this->obj1->getInput()) 
    {
        this->endNow = true;
    }

    GameState::update(dt, window);
}

void Basement::render(sf::RenderTarget *target)
{
    if (!target)
    {
        target = this->window;
    }
    target->draw(this->background);

    this->door1->render(target);
    this->door2->render(target);
    this->obj1->render(target);
    
    GameState::render(target);
}
