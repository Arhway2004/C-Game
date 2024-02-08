//nothing vdo18
#pragma once 
#include "../../include/Game.h"
#include "../../include/GameState.h"
#include "../../UI/Button.h"

class MainMenu : public GameState{
    private:
        sf::RenderWindow* window; 
        bool isPressed; 

        sf::RectangleShape background; 
        sf::Font font; 

        
        // void initKeybinds(); for what 

        Button* main_menu_btn; 

    public:
        MainMenu(sf::RenderWindow* window); 
        virtual ~MainMenu(); 

        void updateInput(const float& dt) override;
        void endState() override; 
        void update(const float& dt) override; 
        void render(sf::RenderTarget* target = nullptr) override; 

}; 