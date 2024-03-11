#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include "Player.h"

class Enemy : public Entity
{
private:
    //Initializer
    struct EnemyStats{
        int maxBullet;
        int bulletReceived; //number of bullet to kill
    }; 

    std::shared_ptr<HealthBar> enemyHealthBar;

    std::shared_ptr<sf::Texture> enemyTexture;
    std::shared_ptr<sf::Sprite> enemySprite;
    // sf::Sprite enemySprite;
    Animation animation;
    Player player;

    //Variables for movenment
    float movementSpeed = 100.f;
    float oscillationDirection = 1.0f; // Start moving right
    float oscillationTimer = 0.0f;

public:
    // Constructors / Destructors

    enum EnemyStates
    {
        ALIVE = 0,
        DAMAGED = 1,
        DEAD = 2,
    };

    EnemyStats enemy_stats;
    EnemyStates enemyState = ALIVE;
    Enemy();
    virtual ~Enemy();

    // Functions
    std::shared_ptr<sf::Sprite> getSprite() const;

    void loadFile(sf::Texture& texture, std::string path) override;
    void update(const float &dt) override;
    void update(const float &dt, sf::Vector2f mousePos); 
    void updateState(); 

    // void update(const float &dt, Player &player);
    void render(sf::RenderTarget *target) override;
    sf::FloatRect getGlobalBounds() const;
    void move(const float &dt, const float x, const float y, const float movementSpeed) override;
    bool isOutBound() const override;
    bool isCollided(const Entity& entity) const;

    //setter 
    void setPosition(const float x, const float y) override;
    void setState(const EnemyStates state); 
    //getter
    EnemyStates getState();
    sf::Vector2f getPosition() const;


    // Movement 
    void updateAnimation();
    void Movement(const float &dt, sf::Vector2f playerPosition);
    void updateInput(const float &dt) override; // not used but write to override from entity
};

#endif