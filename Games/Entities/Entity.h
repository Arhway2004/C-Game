#ifndef ENTITY_H
#define ENTITY_H
#include "../../src/Config.h"

//class for enemy and player
class Entity {
    protected:
        //temp
        sf::Sprite sprite;
        sf::Texture texture; 
        float movementSpeed;

    public:
        // virtual void createSprite(std::shared_ptr<sf::Texture> texture) = 0;
        virtual void setPosition(const float x, const float y) = 0;  
        virtual void move(const float& dt, const float x, const float y) = 0;
        virtual void update(const float& dt) = 0;
        virtual void updateInput(const float& dt) = 0; 
        virtual void render(sf::RenderTarget* target) = 0; 
};

#endif 