#pragma once
#include "Base.h"

class Guide: public Base{
    private: 

    public: 
        Guide(); 
        virtual ~Guide();
        void update(const sf::Vector2f mousePos);
        void render_guide(sf::RenderTarget* target = nullptr);

}; 