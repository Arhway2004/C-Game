//rotate bullet following gun direction

#include "Entity.h"
#include "Bullet.h"

#ifndef PLAYER2_H 
#define PLAYER2_H

class Player : public Entity{
    private:
        sf::Texture testTexture;
        sf::Sprite testSprite;
        sf::Texture gunTexture;
        sf::Sprite gunSprite;
        float gunAngle;
        Animation animation;
        float movementSpeed = 100.f;
        std::vector<Bullet> bullets;
        std::vector<float> bulletAngles; 

        bool canShoot = true;
        sf::Clock shootCooldown;
        const float shootCooldownTime = 0.3f;

    public: 
        enum PlayerStates{
            IDLE = 0,
            MOVING_LEFT = 1,
            MOVING_RIGHT = 2,
            SHOOTING = 3,
            IDLE_LEFT = 4,
            IDLE_RIGHT = 5,
            DAMAGED = 6, 
            DEAD = 7
        };
        PlayerStates playerState = IDLE;
        PlayerStates prevState;

        struct Playerstats{
            //might store player stats 
        };

        Playerstats player_stats;


        Player(); 
        virtual ~Player(); 
        void loadFile(sf::Texture& tex, std::string path) override;
        void setPosition(const float x, const float y) override;
        void updateOrigin();
        void move(const float& dt, const float x, const float y, const float movementSpeed) override;
        void update(const float& dt) override;
        void update(const float& dtm, sf::Vector2f mousePos);
        bool isOutBound() const override; //should be in entity class
        void updateInput(const float& dt) override;
        void updateGunMovement(sf::Vector2f mousePos); 
        void shootBullet(std::vector<Bullet>& bullets, sf::Vector2f mousePos); 
        bool isCollided(const Enemy& enemy);
        bool bulletHitEnemy(Enemy& enemy) const; 

        //movement
        void updateMovement(const float& dt, sf::Vector2f mousePos); 
        void updateAnimation();

        //combat 
        void render(sf::RenderTarget* target) override;
};

#endif


//spawn position where gun point to 
//rotate according to mousePos
//in updatemove(...., angle to rotate)
//where to update bullet 