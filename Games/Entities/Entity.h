#ifndef ENTITY_H
#define ENTITY_H
#include "../../src/Config.h"

//class for enemy and player
class Entity {
    private: 

    protected:
        sf::RectangleShape shape; 
        float movementSpeed; 



    public:
        Entity(); 
        virtual ~Entity();

        virtual void move(const float& dt, const float x, const float y);
        virtual void update(const float& dt) = 0;
        virtual void render(sf::RenderTarget& target) = 0; 
};

#endif 