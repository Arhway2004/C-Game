#pragma once
#include "Base.h"
#include "../../src/Config.h"


class Guide: public Base{
    private: 
        sf::RenderWindow* window;
        sf::RectangleShape background,A,D,S,W,Mouse;
        sf::Texture bg_texture,A_texture,D_texture,S_texture,W_texture,Mouse_texture;
        
    public: 
        Guide(); 
        virtual ~Guide();
        void update(const sf::Vector2f mousePos);
        void render_guide(sf::RenderTarget* target = nullptr);

}; 
