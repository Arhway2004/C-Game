#pragma once
#include "Base.h"

class Guide: public Base{
    private:
        // bool quit_base = true;

    public:
        Guide();
        virtual ~Guide();
        bool return_quit();
        void reset_quit();
        void update(const sf::Vector2f mousePos);
        void render_guide(sf::RenderTarget* target = nullptr);
};