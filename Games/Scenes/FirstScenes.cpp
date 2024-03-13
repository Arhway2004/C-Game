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

    this->textLine.push_back("You: \nehhhhh,Hello, do you know where I am ?\n");
    this->textLine.push_back("                                              :Thun \nNow, you are in the game 'SE Life'. To pass this\ngame and return to your world, you need to \neliminate every rust.");
    this->textLine.push_back("You: \nOkay, thank you for the direction.\n");
    this->textLine.push_back("                                              :Teemy \nHope you enjoy with this game Thun.\n");
    this->textLine.push_back("<End of conversation.>");
    this->textLine.push_back("Press F to continue.");
    this->message->Text(this->textLine, this->x);
    //music
    // this->music = new Music();  
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

void FirstScenes::update(const float& dt, sf::RenderWindow* window)
{
    static bool enterKeyPressedLastFrame = false; // Flag to track Enter key press
    int y = textLine.size();
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    {
        std::cout << y << std::endl;
        if (!enterKeyPressedLastFrame) // Check if Enter key wasn't pressed last frame
        {
            std::cout << "Enter key pressed" << std::endl;
            ++x;
            std::cout << x << std::endl;
            if (x == y)
            {
                std::cout << y << x <<"End of first scense" << std::endl;

                this->message->Text(this->textLine, this->x);
                //waiting for connect with next slide
                // this->textLine.push_back("Message 1");
            }
            this->message->Text(this->textLine, this->x);
        }
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::F)){
        this->endNow = true; 
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