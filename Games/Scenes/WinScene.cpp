#include "WinScene.h"

WinScene::WinScene(sf::RenderWindow* window)
    : GameState(window)
{
    this->window = window; 
    this->loadfile(this->bgTex, "../assets/Textures/win_cert.png");
    this->bg.setTexture(this->bgTex);
    this->bg.setScale(1.f, 1.f);
}

WinScene::~WinScene()
{
}

void WinScene::loadfile(sf::Texture &tex, std::string path)
{
    if (!tex.loadFromFile(path))
    {
        std::cout << "WinScene::loadFile:: Error: WinScene texture not loaded" << std::endl;
    }
    else
    {
        std::cout << "WinScene Texture load successfully" << std::endl;
    }
}

void WinScene::endState()
{
    std::cout << "Ending Win Scene"
              << "\n";
}

void WinScene::update(const float &dt, sf::RenderWindow *window)
{

    this->endState();
    GameState::update(dt, window);
}


void WinScene::render(sf::RenderTarget *target)
{
    if (!target)
    {
        target = this->window;
    }
    target->draw(this->bg);
}