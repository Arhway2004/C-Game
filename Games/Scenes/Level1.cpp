#include "Level1.h"

Level1::Level1(sf::RenderWindow* window) : GameState(window){
    this->endNow = false; 
    // this->player = Player2(300.f, 300.f);
    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    this->background.setFillColor(sf::Color::Black);
    this->loadTextures(this->bgTex, "../assets/textures/map.png");
    this->bg.setTexture(this->bgTex);
    this->bg.setScale(2.f, 2.1f);
    this->bg.setPosition(0.f, 0.f);
}

Level1::~Level1(){
    
}

void Level1::endState(){
    std::cout << "Ending Level1" << "\n";
}

void Level1::updateInput(const float& dt){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        this->endNow = true;
    }
}

void Level1::update(const float& dt, sf::RenderWindow* window) {
    this->updateInput(dt);
    // this->updateOptions();
    this->player.update(dt, this->mousePosView); 
    //last
    GameState::update(dt, window);
}

void Level1::loadTextures(sf::Texture& texture, std::string path){
    if(!texture.loadFromFile(path)){
        std::cout << "Player::loadFile:: Error: Player texture not loaded" << std::endl;
    }else{
        std::cout << "Texture load successfully" << std::endl;
    }
}

void Level1::render(sf::RenderTarget* target) {
    if(!endNow){
        target->draw(this->background); 
        target->draw(this->bg);
        this->player.render(target); 
    }
    //last
    GameState::render(target); 
}


