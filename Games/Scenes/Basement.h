#ifndef BASEMENT_H
#define BASEMENT_H

#include "../../include/Gamestate.h"
#include "../../include/Game.h"
#include "../../UI/Button.h"
#include "../../UI/ClickableIcon.h"
#include "../Settings/Options.h"
#include "../Settings/Base.h"
#include "../../UI/interactable_obj.h"
#include "../Entities/Player_w.h"

class Basement : public GameState{
    private: 
        sf::RenderWindow* window; 
        sf::RectangleShape background; 
        sf::Font font; 
        sf::Texture bgTex;
        sf::Sprite bg;

        Button* test_btn;
        InteractableObj* door1;
        PlayerW player;
        
        //fn
        // void initKeybinds(); for what
        
    public: 
        Basement(sf::RenderWindow* window); 
        virtual ~Basement(); 
        
        // void updateInput(const float& dt, Button* btn) override;
        void loadTextures(sf::Texture &tex, std::string path);
        void endState() override; 
        void update(const float& dt, sf::RenderWindow* window) override; 
        void render(sf::RenderTarget* target = nullptr) override;
};

#endif 