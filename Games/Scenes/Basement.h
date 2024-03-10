#ifndef BASEMENT_H
#define BASEMENT_H

#include "../../include/Gamestate.h"
#include "../../include/Game.h"
#include "../../UI/Button.h"
#include "../../UI/ClickableIcon.h"
#include "../Settings/Options.h"
#include "../Settings/Base.h"
#include "../../UI/interactable_obj.h"
// #include "../../UI/Music.h"



class Basement : public GameState{
    private: 
        sf::RenderWindow* window; 
        sf::RectangleShape background; 
        sf::Font font; 

        Button* test_btn;
        ClickableIcon* door1;
        ClickableIcon* door2;
        InteractableObj* obj1;
        // Music* music;
        //fn
        // void initKeybinds(); for what
        
    public: 
        Basement(sf::RenderWindow* window); 
        virtual ~Basement(); 
        
        // void updateInput(const float& dt, Button* btn) override;
        void endState() override; 
        void update(const float& dt, sf::RenderWindow* window) override; 
        void render(sf::RenderTarget* target = nullptr) override;
};

#endif 