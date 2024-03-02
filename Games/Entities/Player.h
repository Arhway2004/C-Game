#include "../../src/Config.h"
#include "Entity.h"
#ifndef PLAYER2_H
#define PLAYER2_H

class Player : public Entity{
    private: 
        enum PlayerStates{
                IDLE = 0, 
                MOVING_LEFT = 1, 
                MOVING_RIGHT = 2, 
                SHOOTING = 3, 
            };

        struct Playerstats{
            //might store player stats 
        };

        PlayerStates playerState;

        sf::Texture testTexture;
        sf::Sprite testSprite;
        float movementSpeed = 100.f;

    public: 
        // Test(); 
        // virtual ~Test(); 
        // void loadFile(sf::Texture& tex, std::string path);
        // void move(const float& dt, const float x, const float y);
        // void update(const float& dt);
        // void updateInput(const float& dt);
        // void render(sf::RenderTarget* target);

        Player(); 
        virtual ~Player(); 
        void loadFile(sf::Texture& tex, std::string path);
        void setPosition(const float x, const float y) override;  
        void move(const float& dt, const float x, const float y) override;
        void update(const float& dt) override;
        void updateInput(const float& dt) override;
        void updateAnimation();

        //combat 
        void render(sf::RenderTarget* target) override;
};

#endif