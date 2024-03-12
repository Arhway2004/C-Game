#include "Enemy.h"


//enemy blood not appear

Enemy::Enemy()
{   
    this->enemyTexture = std::make_shared<sf::Texture>(); 
    this->enemySprite = std::make_shared<sf::Sprite>();
    this->loadFile(*this->enemyTexture, "../assets/textures/crab.png");
    this->enemySprite->setTexture(*this->enemyTexture);
    this->enemySprite->setPosition(400.f, 400.f);
    this->enemySprite->setTextureRect(sf::IntRect(0, 0, 72, 45)); // x, y, w, h
    this->enemySprite->setScale(2.f, 2.f);
    this->enemySprite->setOrigin(72/2.f, 45/2.f);
    this->enemyHealthBar = std::make_shared<HealthBar>(this->enemySprite->getPosition().x, this->enemySprite->getPosition().y - 60, 77, 8, 100, sf::Color::Red);
    
    std::srand(std::time(0));
    int rand = std::rand() % 3 + 1;
    this->enemy_stats.maxBullet = rand;
    this->enemy_stats.bulletReceived = 0;
}

Enemy::~Enemy()
{

}

std::shared_ptr<sf::Sprite> Enemy::getSprite() const
{
    return this->enemySprite;
}

void Enemy::setPosition(const float x, const float y)
{
    this->enemySprite->setPosition(x, y);
}

sf::Vector2f Enemy::getPosition() const
{
    return sf::Vector2f(this->enemySprite->getPosition().x, this->enemySprite->getPosition().y);
}

sf::FloatRect Enemy::getGlobalBounds() const
{
    return this->enemySprite->getGlobalBounds();
}

sf::Vector2f Enemy::getOrigin() const
{
    return sf::Vector2f(this->enemySprite->getOrigin().x, this->enemySprite->getOrigin().y);
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
    this->enemySprite->move(x * movementSpeed * dt, y * movementSpeed * dt);
}

void Enemy::Movement(const float &dt, sf::Vector2f playerPosition)
{
 
    sf::Vector2f direction = playerPosition - this->enemySprite->getPosition();
    float magnitude = sqrtf(direction.x * direction.x + direction.y * direction.y);

    // Normalize the direction to get a unit vector
    if (magnitude != 0){
        direction /= magnitude;
    }
    this->move(dt, direction.x, direction.y, 100.f); 
}

void Enemy::updateState()
{
    switch (this->enemyState)
    {
        case Enemy::EnemyStates::DAMAGED: {
            std::cout << "Enemy is damaged" << std::endl;
            int damage = 100 / this->enemy_stats.maxBullet;
            this->enemy_stats.bulletReceived++;
            this->enemyHealthBar->update(-damage);
            if(this->enemy_stats.bulletReceived == this->enemy_stats.maxBullet){
                this->enemyState = Enemy::EnemyStates::DEAD;
            }
            break;
        }
        case Enemy::EnemyStates::DEAD: {
            std::cout << "Enemy is dead" << std::endl;
            break;
        }
        default:
            break;
    }
}

void Enemy::update(const float &dt){
    
}


void Enemy::update(const float &dt, sf::Vector2f mousePos)
{
    this->Movement(dt, player.getPosition());
    this->updateAnimation();
    this->updateState();
    sf::Vector2f playerPosition = player.getPosition();
    this->player.update(dt, mousePos); 
    // this->enemyHealthBar->update(0);
    this->enemyHealthBar->setPosition(this->enemySprite->getPosition().x - 40, this->enemySprite->getPosition().y - 40);
    // if (this->enemyHealthBar->bloodRunsOut())
    // {
    //     this->enemyState = Enemy::EnemyStates::DEAD;
    // }
    std::cout << "Enemy Player Position: " << playerPosition.x << ", " << playerPosition.y << std::endl;
}

void Enemy::updateInput(const float &dt)
{
    
}

void Enemy::setState(Enemy::EnemyStates state){
    this->enemyState = state;
}

Enemy::EnemyStates Enemy::getState(){
    return this->enemyState;
}

bool Enemy::isCollided(const Entity& entity) const
{

}

bool Enemy::isOutBound() const
{
    if ((this->enemySprite->getPosition().x > 0 || this->enemySprite->getPosition().x < WINDOW_WIDTH) && (this->enemySprite->getPosition().y > 0 || this->enemySprite->getPosition().y < WINDOW_HEIGHT))
    {
        return false;
    }
    return true;
}

void Enemy::updateAnimation()
{
    animation.updateAnimation(*this->enemySprite, *this->enemyTexture, 0, 76, 45, 3, 35, "../assets/textures/crab.png");
}

void Enemy::render(sf::RenderTarget *target)
{
    if(this->enemyState != Enemy::EnemyStates::DEAD){
        target->draw(*this->enemySprite);
        // this->enemyHealthBar->render(target);
    }
}