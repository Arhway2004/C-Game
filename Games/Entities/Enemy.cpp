#include "Enemy.h"


Enemy::Enemy()
{   
    this->enemyTexture = std::make_shared<sf::Texture>(); 
    this->loadFile(*this->enemyTexture, "../assets/textures/crab.png");
    this->enemySprite.setTexture(*this->enemyTexture);
    this->enemySprite.setPosition(400.f, 400.f);
    this->enemySprite.setTextureRect(sf::IntRect(0, 0, 72, 45)); // x, y, w, h
    this->enemySprite.setScale(2.f, 2.f);
}

Enemy::~Enemy()
{

}

void Enemy::setPosition(const float x, const float y)
{
    this->enemySprite.setPosition(x, y);
}

sf::FloatRect Enemy::getGlobalBounds() const
{
    return this->enemySprite.getGlobalBounds();
}

void Enemy::loadFile(sf::Texture &texture, std::string path)
{
    if (!texture.loadFromFile(path))
    {
        std::cout << "Enemy::loadFile:: Error: Enemy texture not loaded" << std::endl;
    }
    else
    {
        std::cout << "Texture load successfully" << std::endl;
    }
}

void Enemy::move(const float &dt, const float x, const float y, const float movementSpeed)
{
    this->enemySprite.move(x * movementSpeed * dt, y * movementSpeed * dt);
}

void Enemy::Movement(const float &dt)
{
    //move back and forth
    oscillationTimer += dt;
    if (oscillationTimer >= 2.0f)
    { // Change direction every 2 seconds
        oscillationTimer = 0.0f;
        oscillationDirection *= -1.0f;
    }

    this->move(dt, oscillationDirection, 0.0f, 100.f);
}

void Enemy::setState(const EnemyStates state){
    this->enemyState = state;
}

Enemy::EnemyStates Enemy::getState(){
    return this->enemyState;
}

void Enemy::update(const float &dt)
{
    this->Movement(dt);
    this->updateAnimation();
}

void Enemy::updateInput(const float &dt)
{

}

bool Enemy::isCollided(const Entity& entity) const
{

}


bool Enemy::isOutBound() const
{
    if ((this->enemySprite.getPosition().x > 0 || this->enemySprite.getPosition().x < WINDOW_WIDTH) && (this->enemySprite.getPosition().y > 0 || this->enemySprite.getPosition().y < WINDOW_HEIGHT))
    {
        return false;
    }
    return true;
}

void Enemy::updateAnimation()
{
    animation.updateAnimation(this->enemySprite, *this->enemyTexture, 0, 76, 45, 3, 35, "../assets/textures/crab.png");
}

void Enemy::render(sf::RenderTarget *target)
{
    target->draw(this->enemySprite);
    
}