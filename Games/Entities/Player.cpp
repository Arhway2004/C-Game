#include "Player.h"

// problem: check player out of bound / or area that can't walk
// when idle player not move
// add isCollided function

Player::Player()
{
    this->loadFile(this->testTexture, "../assets/textures/player_run.png");
    this->testSprite.setTexture(this->testTexture);
    this->testSprite.setPosition(300.f, 300.f);
    this->testSprite.setTextureRect(sf::IntRect(0, 0, 80, 80)); // x, y, w, h
    this->testSprite.setScale(2.f, 2.f);
}

Player::~Player()
{
}

void Player::setPosition(const float x, const float y)
{
    this->testSprite.setPosition(x, y);
}

void Player::loadFile(sf::Texture &texture, std::string path)
{
    if (!texture.loadFromFile(path))
    {
        std::cout << "Player::loadFile:: Error: Player texture not loaded" << std::endl;
    }
    else
    {
        std::cout << "Texture load successfully" << std::endl;
    }
}

void Player::move(const float &dt, const float x, const float y, const float movementSpeed)
{
    this->testSprite.move(x * movementSpeed * dt, y * movementSpeed * dt);
}

void Player::update(const float &dt)
{
    // this->updateInput(dt);

    this->updateMovement(dt);
    this->updateAnimation();
}

void Player::updateInput(const float &dt)
{
    int xTexture = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->move(dt, -1.f, 0.f, 200.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->loadFile(this->testTexture, "../assets/textures/player_run.png");
        xTexture = (int)this->testSprite.getPosition().x / 35 % 8; // slow down 35 frames
        xTexture = xTexture * 80;
        this->testSprite.setTextureRect(sf::IntRect(xTexture, 0, 80, 80)); // x, y, w, h>
        this->move(dt, 1.f, 0.f, 200.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->move(dt, 0.f, -1.f, 200.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->move(dt, 0.f, 1.f, 200.f);
    }
}

void Player::updateMovement(const float &dt)
{
    this->playerState = IDLE;
    // std::cout << "Player::outbound:: " << this->isOutBound() << std::endl;
    // if(!this->isOutBound()){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->playerState = MOVING_LEFT;
        this->move(dt, -1.f, 0.f, 200.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->playerState = MOVING_RIGHT;
        this->move(dt, 1.f, 0.f, 200.f);
        // std::cout << "player x: " << this->testSprite.getPosition().x << " player y: " << this->testSprite.getPosition().y << std::endl;
        // std::cout << "player out of bound: " << this->isOutBound() << std::endl;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->move(dt, 0.f, -1.f, 200.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->move(dt, 0.f, 1.f, 200.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        this->playerState = SHOOTING;
        // implement shooting
    }

    if (prevState == MOVING_LEFT && playerState == IDLE)
    {
        this->playerState = IDLE_LEFT;
    }
    else if (prevState == MOVING_RIGHT && playerState == IDLE)
    {
        this->playerState = IDLE_RIGHT;
    }
    else
    {
        prevState = playerState;
    }
    // }
}

bool Player::isOutBound() const
{
    if ((this->testSprite.getPosition().x > 0 || this->testSprite.getPosition().x < WINDOW_WIDTH) && (this->testSprite.getPosition().y > 0 || this->testSprite.getPosition().y < WINDOW_HEIGHT))
    {
        return false;
    }
    return true;
}

bool Player::isCollided(const Entity &entity) const
{
    return false;
}

void Player::updateAnimation()
{
    int xTexture = 0;
    switch (this->playerState)
    {
    case IDLE:
        if (this->prevState == MOVING_LEFT)
        {
            animation.updateAnimation(this->testSprite, this->testTexture, 240, 64, 80, 4, 35, "../assets/textures/player_idle.png");
        }
        else
        {
            animation.updateAnimation(this->testSprite, this->testTexture, 160, 64, 80, 4, 35, "../assets/textures/player_idle.png");
        }
        break;
    case MOVING_LEFT:
        animation.updateAnimation(this->testSprite, this->testTexture, 240, 80, 80, 8, 35, "../assets/textures/player_run.png");
        break;
    case MOVING_RIGHT:
        animation.updateAnimation(this->testSprite, this->testTexture, 160, 80, 80, 8, 35, "../assets/textures/player_run.png");
        break;
    case SHOOTING:
        // animation.updateAnimation(this->testSprite, this->testTexture, 0, 64, 80, 4, 35, "../assets/textures/player_idle.png");
        break;
    case IDLE_LEFT:
        animation.updateAnimation(this->testSprite, this->testTexture, 240, 64, 80, 4, 35, "../assets/textures/player_idle.png");
        break;
    case IDLE_RIGHT:
        animation.updateAnimation(this->testSprite, this->testTexture, 160, 64, 80, 4, 35, "../assets/textures/player_idle.png");
        break;
    default:
        animation.updateAnimation(this->testSprite, this->testTexture, 0, 64, 80, 4, 35, "../assets/textures/player_idle.png");
        break;
    }
}

//Add the function to get the position of the player
sf::Vector2f Player::getPosition() const
{
    return this->testSprite.getPosition();
}

void Player::render(sf::RenderTarget *target)
{
    target->draw(this->testSprite);
}
