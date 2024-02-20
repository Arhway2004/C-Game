#pragma once
#include "Base.h"

class Guide: public Base{
    private:
        bool quit = true;

    public:
        Guide();
        virtual ~Guide();
        bool getQuit();
        void update(const sf::Vector2f mousePos);
        void render_guide(sf::RenderTarget* target = nullptr);
};