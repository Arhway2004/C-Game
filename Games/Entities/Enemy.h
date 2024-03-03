#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

class Enemy : public Entity
{
private:
    // Initializer
    sf::Texture enemyTexture;
    sf::Sprite enemySprite;
    Animation animation;
    
    // Variables for movenment
    float movementSpeed = 100.f;
    float oscillationDirection = 1.0f; // Start moving right
    float oscillationTimer = 0.0f;

public:
    // Constructors / Destructors
    Enemy();
    virtual ~Enemy();

    // Functions
    void loadFile(sf::Texture& texture, std::string path) override;
    void update(const float &dt) override;
    void render(sf::RenderTarget *target) override;
    void setPosition(const float x, const float y) override;
    void move(const float &dt, const float x, const float y, const float movementSpeed) override;
    bool isOutBound() const override;
    bool isCollided(const Entity& entity) const override;

    // Movement 
    void updateAnimation();
    void Movement(const float &dt);
    void updateInput(const float &dt) override; // not used but write to override from entity
};

#endif