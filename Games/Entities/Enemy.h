#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include "Player.h"

class Enemy : public Entity
{
private:
    // Initializer
    std::shared_ptr<sf::Texture> enemyTexture;
    sf::Sprite enemySprite;
    sf::Vector2f currentDirection;
    Animation animation;
    Player player;
    

    // Variables for movenment
    float movementSpeed = 100.f;
    float oscillationDirection = 1.0f; // Start moving right
    float oscillationTimer = 0.0f;

public:
    // Constructors / Destructors
    enum EnemyStates
    {
        ALIVE = 0,
        SHOOTED = 1,
        DAMAGED = 2,
        DEAD = 3,
    };

    EnemyStates enemyState = ALIVE;
    Enemy();
    virtual ~Enemy();

    // Functions
    void loadFile(sf::Texture &texture, std::string path) override;
    void update(const float &dt);
    void render(sf::RenderTarget *target) override;
    sf::FloatRect getGlobalBounds() const;
    void move(const float &dt, const float x, const float y, const float movementSpeed) override;
    bool isOutBound() const override;
    bool isCollided(const Entity &entity) const;
    sf::Vector2f lerp(const sf::Vector2f &a, const sf::Vector2f &b, float t)
    {
        return (1 - t) * a + t * b;
    }

    // setter
    void setPosition(const float x, const float y) override;
    void setState(const EnemyStates state);
    // getter
    EnemyStates getState();

    // Movement
    void updateAnimation();
    void Movement(const float &dt, sf::Vector2f playerPosition);
    void updateInput(const float &dt) override; // not used but write to override from entity
};

#endif