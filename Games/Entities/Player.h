#include "Entity.h"

#ifndef PLAYER2_H
#define PLAYER2_H

class Player : public Entity{
    private: 
        struct Playerstats{
            //might store player stats 
        };
        Playerstats player_stats;
        sf::Texture testTexture;
        sf::Sprite testSprite;
        Animation animation; 
        float movementSpeed = 100.f;


    public: 
        // Test(); 
        // virtual ~Test(); 
        // void loadFile(sf::Texture& tex, std::string path);
        // void move(const float& dt, const float x, const float y);
        // void update(const float& dt);
        // void updateInput(const float& dt);
        // void render(sf::RenderTarget* target);
        enum PlayerStates{
            IDLE = 0,
            MOVING_LEFT = 1,
            MOVING_RIGHT = 2,
            SHOOTING = 3,
            IDLE_LEFT = 4,
            IDLE_RIGHT = 5,
        };
        PlayerStates playerState = IDLE;
        PlayerStates prevState;

        Player(); 
        virtual ~Player(); 
        void loadFile(sf::Texture& tex, std::string path) override;
        void setPosition(const float x, const float y) override;  
        void move(const float& dt, const float x, const float y, const float movementSpeed) override;
        void update(const float& dt) override;
        bool isOutBound() const override; //should be in entity class
        void updateInput(const float& dt) override;
        bool isCollided(const Entity& entity) const override;  

        //movement
        void updateMovement(const float& dt); 
        void updateAnimation();

        //combat 
        void render(sf::RenderTarget* target) override;
};

#endif