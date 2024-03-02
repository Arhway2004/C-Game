#include "Player.h"


Player::Player(){
    this->loadFile(this->testTexture, "../assets/textures/player_run.png");
    this->testSprite.setTexture(this->testTexture);
    this->testSprite.setPosition(300.f, 300.f);
    this->testSprite.setTextureRect(sf::IntRect(0, 0, 80, 80));  //x, y, w, h
    this->testSprite.setScale(2.f, 2.f);
}

Player::~Player(){
    
}

void Player::setPosition(const float x, const float y){
    this->testSprite.setPosition(x, y);
}

void Player::loadFile(sf::Texture& texture, std::string path){
    if(!texture.loadFromFile(path)){
        std::cout << "Player::loadFile:: Error: Player texture not loaded" << std::endl;
    }else{
        std::cout << "Texture load successfully" << std::endl;
    }
}


void Player::move(const float& dt, const float x, const float y){
    this->testSprite.move(x * this->movementSpeed * dt ,y * this->movementSpeed * dt); 
}


void Player::update(const float& dt){
    this->updateInput(dt);
    
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
    //     this->move(dt, -1.f, 0.f);
    // }
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){        
    //     int xTexture = 0; 
    //     xTexture = (int)this->testSprite.getPosition().x / 35 % 8; //slow down 35 frames
    //     xTexture = xTexture * 80;
    //     this->testSprite.setTextureRect(sf::IntRect(xTexture, 0, 80, 80));  //x, y, w, h>
    //     this->move(dt, 1.f, 0.f);
    // }
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
    //     this->move(dt, 0.f, -1.f);
    // }
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
    //     this->move(dt, 0.f, 1.f);
    // }
}

void Player::updateInput(const float& dt){
    int xTexture = 0; 

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        this->move(dt, -1.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){ 
        this->loadFile(this->testTexture, "../assets/textures/player_run.png");
        xTexture = (int)this->testSprite.getPosition().x / 35 % 8; //slow down 35 frames
        xTexture = xTexture * 80;
        this->testSprite.setTextureRect(sf::IntRect(xTexture, 0, 80, 80));  //x, y, w, h>
        this->move(dt, 1.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        this->move(dt, 0.f, -1.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        this->move(dt, 0.f, 1.f);
    }

    


}   


void Player::render(sf::RenderTarget* target){
    target->draw(this->testSprite);
}

//void Player::updateAnimation(){
    // int xTexture = 0;
    // switch(this->playerState){
    //     case PlayerStates::IDLE:
    //         this->sprite.setTextureRect(sf::IntRect(0, 0, 112.5, 113));
    //         break;
    //     case PlayerStates::MOVING_LEFT:
    //         // this->sprite.setTextureRect(sf::IntRect(0, 0, 112.5, 113));
    //         break;
    //     case PlayerStates::MOVING_RIGHT:
    //         // this->loadFile("../assets/textures/player_run.png");
    //         xTexture = (int)this->sprite.getPosition().x / 35 % 8; //slow down 35 frames
    //         xTexture = xTexture * 112.5;
    //         break;
    //     case PlayerStates::SHOOTING:
    //         // this->sprite.setTextureRect(sf::IntRect(0, 0, 112.5, 113));
    //         break;
    //     default:
    //         this->sprite.setTextureRect(sf::IntRect(0, 0, 112.5, 113));
    //         break;
    // }            
    // this->sprite.setTextureRect(sf::IntRect(xTexture, 0, 112.5, 113));
