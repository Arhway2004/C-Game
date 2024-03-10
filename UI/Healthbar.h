#pragma once 

#include "../src/Config.h"

class HealthBar{
    private:
        sf::Vector2f position;
        int damage; //(%)damage per hit
        int fullHealth; //(%)total damage can accept 
        sf::RectangleShape frame;
        sf::RectangleShape blood;
        sf::Color bloodColor; 
        int fullHealthtoPercent = 100;

    public:
        HealthBar(float pos_x, float pos_y, float set_w, float set_h, int health, sf::Color bloodColor); 
        ~HealthBar();
        void update(const int change); 
        void setPosition(float x, float y);
        // void decreaseHealth(int damage);
        void render(sf::RenderTarget* target);

}; 