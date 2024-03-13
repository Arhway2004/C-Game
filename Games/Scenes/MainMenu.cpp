// base class for game to call other scene
#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow *window) : GameState(window) ,gif("../assets/textures/classroom_bg.gif")

{
    this->endNow = false;
    this->initFont(this->font, "../assets/font/SEASHORE.otf");

    //game logo
    this->loadfile(this->logo_tex, "../assets/icons/game_logo.png");
    this->game_logo.setTexture(this->logo_tex);
    this->game_logo.setScale(1.5f, 1.5f);
    this->game_logo.setPosition(400.f, 50.f);

    this->start_btn = Button(450.0, 350.0, 150.0, 60.0, &this->font, "Start Game");
    this->quit_btn = Button(450.0, 430.0, 150.0, 60.0, &this->font, "Quit Game");

    // this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    // this->background.setFillColor(sf::Color::Black);
}

MainMenu::~MainMenu()
{
}

void MainMenu::loadfile(sf::Texture &texture, std::string path)
{
    if (!texture.loadFromFile(path))
    {
        std::cout << "MainMenu::loadFile:: Error: MainMenu texture not loaded" << std::endl;
    }
    else
    {
        std::cout << "logo Texture load successfully" << std::endl;
    }
}


void MainMenu::endState()
{
    // transfer to another scene
    std::cout << "Ending Main Menu"
              << "\n";
}

void MainMenu::update(const float &dt, sf::RenderWindow *window)
{
    // update per frame
    // update mouse
    this->updateMousePosition();
    this->start_btn.update(this->mousePosView);
    this->quit_btn.update(this->mousePosView);

    this->gif.update(bg_gif);

    if (!this->showOption && !this->showGuide && !this->showSetting)
    {
        if (this->quit_btn.isPressed())
        {
            std::cout << "quit button pressed" << std::endl;
            if (window != nullptr)
            {
                std::cout << "MainMenu::update:: window = null ptr" << std::endl;
                window->close();
            }
        }
        if (this->start_btn.isPressed())
        {
            std::cout << "str button pressed" << std::endl;
            this->endNow = true;
        }
        else
        {
            this->endNow = false;
        }
    }

    GameState::update(dt, window);
}

void MainMenu::render(sf::RenderTarget *target)
{
    if (!target)
    {
        target = this->window;
    }

    target->draw(this->bg_gif);
    // target->draw(this->background);

    this->start_btn.render(target);
    this->quit_btn.render(target);
    target->draw(this->game_logo);

    GameState::render(target);
}
