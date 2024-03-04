#include "Bullet.h"
//inherit from Entity

Bullet::Bullet(const float pos_x, const float pos_y)
{
    this->bulletSprite.setScale(0.5f, 0.5f);
    this->bulletSprite.setPosition(pos_x, pos_y);
    
    this->bulletTexture = std::make_shared<sf::Texture>(); 
    this->loadFile(*this->bulletTexture, "../assets/textures/bullet.png");
    this->bulletSprite.setTexture(*this->bulletTexture);
}

Bullet::Bullet(){
    this->bulletSprite.setScale(0.5f, 0.5f);
    this->bulletSprite.setPosition(300.f, 300.f);
    this->loadFile(*this->bulletTexture, "../assets/textures/bullet.png");
    this->bulletSprite.setTexture(*this->bulletTexture);
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

void Bullet::setRotation(const float angle){
    this->bulletSprite.setRotation(angle);
}

void Bullet::move(const float& dt, const float x, const float y, const float movementSpeed){
    //set bullet angle
    this->bulletSprite.move(x * movementSpeed * dt ,y * movementSpeed * dt);
}

void Bullet::move(const float& dt, const float x, const float y, const float movementSpeed, const float angle){
    //set bullet angle 
    velocity.x = movementSpeed * cos(angle);
    velocity.y = movementSpeed * sin(angle);

    this->bulletSprite.move(x * movementSpeed * dt ,y * movementSpeed * dt); 
    // this->bulletSprite.move(velocity.x * dt, velocity.y * dt);
}

void Bullet::update(const float& dt){

}

void Bullet::update(const float& dt, const float angle){
    //isOutBound();
    //isCollided();
    this->updateInput(dt, angle);
}

bool Bullet::isOutBound() const{
    if ((this->bulletSprite.getPosition().x > WINDOW_WIDTH || this->bulletSprite.getPosition().x < 0) && (this->bulletSprite.getPosition().y > WINDOW_HEIGHT || this->bulletSprite.getPosition().y < 0)){
        return true;
    }
    return false;
}

bool Bullet::isCollided(const Entity& entity) const{

}

void Bullet::updateInput(const float& dt){

}

void Bullet::updateInput(const float& dt, const float angle){
    float angleRad = angle * (M_PI / 180.0f);
    this->bulletSprite.move(500*std::cos(angleRad)* dt, 500*std::sin(angleRad) * dt);
}

//updateMovement

void Bullet::render(sf::RenderTarget* target){
    target->draw(this->bulletSprite);
}


