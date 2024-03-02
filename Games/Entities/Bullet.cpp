#include "Bullet.h"
//inherit from Entity

Bullet::Bullet(){
    
}

Bullet::~Bullet(){
    
}

void Bullet::loadFile(sf::Texture& tex, std::string path){
    if(!tex.loadFromFile(path)){
        std::cout << "Bullet::loadFile:: Error: Bullet texture not loaded" << std::endl;
    }else{
        std::cout << "Bullet Texture load successfully" << std::endl;
    }
}

void Bullet::setPosition(const float x, const float y){
    this->bulletSprite.setPosition(x, y);
}

void Bullet::move(const float& dt, const float x, const float y, const float movementSpeed){
    this->bulletSprite.move(x * movementSpeed * dt ,y * movementSpeed * dt); 
}

void Bullet::update(const float& dt){
    //isOutBound();
    //isCollided();
    //updateInput();

}

bool Bullet::isOutBound() const{
    
}

bool Bullet::isCollided(const Entity& entity) const{
    
}

void Bullet::updateInput(const float& dt){
    
}

//updateMovemetn

void Bullet::render(sf::RenderTarget* target){
    target->draw(this->bulletSprite);
}


