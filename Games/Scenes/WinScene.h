#ifndef WINSCENE_H
#define WINSCENE_H

#include "../../include/Gamestate.h"
#include "../../src/config.h"

class WinScene : public GameState{
    private:
        sf::RenderWindow* window;
        sf::RectangleShape background;
        sf::Texture bgTex;
        sf::Sprite bg;
        
        
    public: 
        WinScene(sf::RenderWindow* window); 
        virtual ~WinScene(); 
        
        void loadfile(sf::Texture &tex, std::string path);
        void endState() override;
        void update(const float& dt, sf::RenderWindow* window) override;
        void render(sf::RenderTarget* target = nullptr) override;
};

#endif