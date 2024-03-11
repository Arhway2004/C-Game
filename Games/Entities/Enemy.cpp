#include "Enemy.h"
    
Enemy::Enemy() : currentDirection(0.0f, 0.0f)
{
    this->enemyTexture = std::make_shared<sf::Texture>();
    this->loadFile(*this->enemyTexture, "../assets/textures/crab.png");
    this->enemySprite.setTexture(*this->enemyTexture);
    this->enemySprite.setPosition(600.f, 600.f);
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

void Enemy::Movement(const float &dt, sf::Vector2f playerPosition)
{
    // // move back and forth
    // oscillationTimer += dt;
    // if (oscillationTimer >= 2.0f)
    // { // Change direction every 2 seconds
    //     oscillationTimer = 0.0f;
    //     oscillationDirection *= -1.0f;
    // }

    // this->move(dt, oscillationDirection, 0.0f, 100.f);
    // this->move(dt, 1.0f, 0.0f, 100.f); // move right
//     sf::Vector2f direction = playerPosition - this->enemySprite.getPosition();
//     float magnitude = sqrtf(direction.x * direction.x + direction.y * direction.y);

//     // Normalize the direction to get a unit vector
//     if (magnitude != 0)
//     {
//         direction /= magnitude;
//     }


    sf::Vector2f direction = playerPosition - this->enemySprite.getPosition();
    float distanceToPlayer = sqrtf(direction.x * direction.x + direction.y * direction.y);

    // Chase the player if within range
        if (distanceToPlayer != 0)
        {
            // Normalize direction for consistent movement speed
            sf::Vector2f normalizedDirection = direction / distanceToPlayer;

            // Smoothly update movement direction
            currentDirection = lerp(currentDirection, normalizedDirection, 0.1f);
        }
    else
    {

    }

    // Use the stored direction for movement
    this->move(dt, currentDirection.x, currentDirection.y, 100.f);

    
}



void Enemy::setState(const EnemyStates state)
{
    this->enemyState = state;
}

Enemy::EnemyStates Enemy::getState()
{
    return this->enemyState;
}

void Enemy::update(const float &dt)
{
    this->Movement(dt, player.getPosition());
    this->updateAnimation();
    // sf::Vector2f playerPosition = player.getPosition();
    this->player.update(dt);
    // std::cout << "Enemy Player Position: " << playerPosition.x << ", " << playerPosition.y << std::endl;
}

void Enemy::updateInput(const float &dt)
{
}

bool Enemy::isCollided(const Entity &entity) const
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
