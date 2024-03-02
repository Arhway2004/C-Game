#include "FirstScenes.h"

FirstScenes::FirstScenes(sf::RenderWindow* window) : GameState(window)
{
    this->window = window;
    this->endNow = false;
    this->background.setSize(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));
    if (!this->bg_t.loadFromFile("../assets/textures/ClassRoomScenes.png")){
        std::cout << "Error loading texture" << std::endl;
    }
    this->background.setTexture(&this->bg_t);

    this->p1t.loadFromFile("../assets/textures/p1.png");
    this->p1.setTexture(p1t);
    p1.setPosition(-200, 20);
    p1.setScale(1.0, 1.2);

    this->p2t.loadFromFile("../assets/textures/p2.png");
    this->p2.setTexture(p2t);
    p2.setPosition(750, 150);
    p2.setScale(0.6, 0.6);

    this->enterPress = false;
    this->x = 0;

    this->message = new Message(200.0, 350.0, 0.6, 0.6, Textbox);

    this->textLine.push_back("Hello");
    this->textLine.push_back("hw");
    this->textLine.push_back("das");
    this->message->Text(this->textLine, this->x);
}

FirstScenes::~FirstScenes()
{
    // delete this->window;
    delete this->message;
}

void FirstScenes::endState()
{
    this->endNow = true;
}

void FirstScenes::updateInput(const float& dt)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        this->endNow = true; 
    }
}

void FirstScenes::update(const float& dt, sf::RenderWindow* window)
{
    this->updateInput(dt);
    static bool enterKeyPressedLastFrame = false; // Flag to track Enter key press

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    {
        if (!enterKeyPressedLastFrame) // Check if Enter key wasn't pressed last frame
        {
            std::cout << "Enter key pressed" << std::endl;
            ++x;
            // this->textLine.clear();
            std::cout << x << std::endl;
            if (x == 1)
            {
                this->textLine.push_back("Message 1");
            }
            else if (x == 2)
            {
                this->textLine.push_back("Message 2");
            }
            this->message->Text(this->textLine, this->x);
        }
    }
    enterKeyPressedLastFrame = sf::Keyboard::isKeyPressed(sf::Keyboard::Return); // Update flag
    GameState::update(dt, window);
}


void FirstScenes::render(sf::RenderTarget* target)
{
    target->draw(this->background);
    target->draw(this->p1);
    target->draw(this->p2);
    this->message->render(target);
    GameState::render(target);
}